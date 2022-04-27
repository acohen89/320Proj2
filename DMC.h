#ifndef DMC_H
#define DMC_H

using namespace std;
#include <vector>
#include <iostream>
#include <math.h>   

#include "cacheBlock.h"


class DMC{
    public: 
        DMC(int); 
        short process(long long);
        int getTotalHits(){return totalHits;}
    private:
        vector<CacheBlock> table; 
        int totalHits; 
        int cacheSize; 

};

#endif
