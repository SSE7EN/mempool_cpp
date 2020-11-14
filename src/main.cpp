
#include "mempool.hpp"




int main(){
    MempoolManager<Test>* mempool = new MempoolManager<Test>();
    mempool->init(10000);

    delete mempool;


    return 0;
}