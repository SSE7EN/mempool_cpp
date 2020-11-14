#pragma once

/**
 **************************
 * @file    mempoolImpl.hpp
 * @author  SE7EN
 * @date    2020-11-13
 * @brief   simple mempool implementation
 **************************
 */

/* Includes ---------------------------------------------------------------- */



#include <stdlib.h> 
#include "mempool.hpp"

using namespace std;

template <typename T>
MempoolManager<T>::MempoolManager(){
	this->blockSize = sizeof(mempoolBlockS<T>);
	this->mempool.blockSize = this->blockSize;
};

template <typename T>
MempoolManager<T>::~MempoolManager(){
	free(this->mempool.memory);
};


template <typename T>
int MempoolManager<T>::init(size_t blockCount){
	if(blockCount <= 0) return -1;


	this->mempool.memory = (uint8_t*)malloc(sizeof(mempoolBlockS<T>)*blockCount);
	this->mempool.blockSize = sizeof(mempoolBlockS<T>);
	this->mempool.blockCount = blockCount;

	uint8_t* iter = this->mempool.memory;
	uint8_t* end = iter + blockCount*this->mempool.blockSize;

	while(iter < end){
		mempoolBlockS<T>* const currentBlock = (mempoolBlockS<T>*)iter;
		currentBlock->prev = nullptr;

		if(this->mempool.freeBlocks != nullptr){
			this->mempool.freeBlocks->prev = currentBlock;
			currentBlock->next = this->mempool.freeBlocks;
		};
		this->mempool.freeBlocks = currentBlock;

		iter += this->blockSize;
	}

	return blockCount;

};

template <typename T>
void MempoolManager<T>::freeBlock(mempoolBlockS<T> *block){
	if(this->mempool.blockCount > 0){
		if(block->prev != nullptr){
			block->prev->next = block->next;
		}
		else{
			this->mempool.allocatedBlocks = block->next;
		}

		if(block->next != nullptr){
			block->next->prev = block->prev;
		}

		block->next = this->mempool.freeBlocks;
		block->preev = nullptr;

		if(this->mempool.freeBlocks != nullptr){
			this->mempool.freeblocks->prev = block;
		}

		this->mempool.freeblocks = block;	
	}
	
};

template <typename T>
mempoolBlockS<T>* MempoolManager<T>::allocateBlock(T data){
	mempoolBlockS<T> *block = nullptr;
	
	if(this->mempool.freeBlock != nullptr){
		block = this->mempool.freeBlocks;
		this->mempool.freeBlocks = block->next;
		this->mempool.freeBlocks->prev = nullptr;

		block->next = this->mempool.alocatedBlocks;
		this->mempool.allocatedBlocks->prev = block;
	}


	return block;
}
