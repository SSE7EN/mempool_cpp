#pragma once

/**
 **************************
 * @file    mempool.hpp
 * @author  SE7EN
 * @date    2020-11-13
 * @brief   simple mempool implementation
 **************************
 */

/* Includes ---------------------------------------------------------------- */
#include <cstddef>
#include <stdint.h>


class Test{

    public:
        int test;
        Test(){this->test =0;}
};

template <typename T>
struct mempoolBlockS{
	mempoolBlockS* next; /** ptr to next block */
	mempoolBlockS* prev; /** ptr to previous block */

	T data; /** data */

};



template <typename T>
struct mempoolS{
	uint8_t* memory = nullptr; /** pointer to memory */
	mempoolBlockS<T>* freeBlocks = nullptr; /** ptr to first free block */
	mempoolBlockS<T>* allocatedBlocks = nullptr; /** ptr to first alocated block */
	size_t blockSize = 0; /** size of single block  */
	size_t blockCount = 0; /** block count */


};

template <typename T>
class MempoolManager{
	public:
		MempoolManager();
		~MempoolManager();

		/*
		 * @brief initialize memory pool
		 *
		 * @param blockCount count of block to create
		 *
		 * @return count of block avalible or -1 if sth went wrong
		 *
		 */
		int init(size_t blockCount);
		void freeBlock(mempoolBlockS<T> *block);
		mempoolBlockS<T>* allocateBlock(T data);
			


	private:
		mempoolS<T> mempool;
		size_t blockSize;	
};

#include "mempoolImpl.hpp"
