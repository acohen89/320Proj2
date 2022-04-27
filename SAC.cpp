#include "SAC.h"

SAC::SAC(int cSize, short as){
    cacheSize = cSize; 
    totalHits = 0;
    assoc = as; 
    table.resize(cacheSize);
    for(int i = 0; i < table.size(); i++){
        table.at(i) = cacheBlockCollection(as);
    }
}


long long calculateTag(long long address, int lineSize, int cacheSize, int assoc){
    int cacheSizeBits = (int) log2(cacheSize);
    int assocBits = (int) log2(assoc);
    int mask = pow(2, cacheSizeBits - lineSize - assocBits) - 1;   
    int index = (address >> lineSize) & mask;
    return address >> cacheSizeBits - assocBits;
}

int calculateIndex(long long address, int lineSize, int cacheSize, int assoc){
    int cacheSizeBits = (int) log2(cacheSize);
    int assocBits = (int) log2(assoc);
    int mask = pow(2, cacheSizeBits - 5 - assocBits) - 1;   
    return (address >> 5) & mask;
}

short SAC::process(long long address, int accessTime){
    long long tag = calculateTag(address, 5, cacheSize, assoc);
    int index = calculateIndex(address, 5, cacheSize, assoc);
    return table.at(index).insert(tag, accessTime); 
}

void SAC::processAWM(long long address, int accessTime){
    // long long tag = calculateTag(address, 5, cacheSize, assoc);
    // int index = calculateIndex(address, 5, cacheSize, assoc);
    // totalHits += table.at(index).insert(tag, accessTime); 
}

void SAC::processNP(long long address, int *accessTime, int lineSize){
    long long tag = calculateTag(address, lineSize, cacheSize, assoc);
    int index = calculateIndex(address, lineSize, cacheSize, assoc);
    totalHits += table.at(index).insert(tag, *accessTime); 
    address += lineSize; 
    tag = calculateTag(address, lineSize, cacheSize, assoc);
    index = calculateIndex(address, lineSize, cacheSize, assoc);
    *accessTime = *accessTime + 1;
    table.at(index).insert(tag, *accessTime); 
}

void SAC::processNPM(long long address, int *accessTime, int lineSize){
    long long tag = calculateTag(address, lineSize, cacheSize, assoc);
    int index = calculateIndex(address, lineSize, cacheSize, assoc);
    totalHits += table.at(index).insert(tag, *accessTime); 
    address += lineSize; 
    tag = calculateTag(address, lineSize, cacheSize, assoc);
    index = calculateIndex(address, lineSize, cacheSize, assoc);
    *accessTime = *accessTime + 1;
    table.at(index).insert(tag, *accessTime); 
}