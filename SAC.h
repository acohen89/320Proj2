#ifndef SAC_H
#define SAC_H

using namespace std;
#include <vector>
#include <iostream>
#include <math.h>  

#include "cacheBlockCollection.h"

class SAC{
    private:
        int totalHits;
        int cacheSize;
        short assoc; 
    public:     
        vector<cacheBlockCollection> table; 
        SAC(int, short); 
        short process(long long, int);
        void processAWM(long long, int);
        void processNP(long long, int*, int);
        void processNPM(long long, int*, int);
        int getTotalHits(){return totalHits;}

};

#endif