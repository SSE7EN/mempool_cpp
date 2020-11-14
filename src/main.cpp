
#include "mempool.hpp"




int main(){
    MempoolManager<int>* mempool = new MempoolManager<int>();
    mempool->init(10000);
    mempoolBlockS<int> *m = mempool->allocateBlock(1);
    mempoolBlockS<int> *m2 = mempool->allocateBlock(2);

    mempool->freeBlock(m2);
    mempool->allocateBlock(3);
    delete mempool;


    return 0;
}