#include "DMC.h"



DMC::DMC(int cSize){
    cacheSize = cSize; 
    totalHits = 0;
    table.resize(cacheSize);
}

short DMC::process(long long address){
    int cacheSizeBits = (int) log2(cacheSize);
    int mask = pow(2, cacheSizeBits - 5) - 1;
    int index = (address >> 5) & mask;
    long long tag = address >> cacheSizeBits; 
    if(table.at(index).getValid() == 0){
        table.at(index).setTag(tag); 
        table.at(index).setValid(1); 
    } else if(table.at(index).getTag() == tag){
        return 1;
    } else {
         table.at(index).setTag(tag);
    }
    return 0; 
}