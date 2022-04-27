#ifndef FAC_H
#define FAC_H

using namespace std; 
#include <vector>
#include <iostream> 
#include <list>
#include <bits/stdc++.h>
#include <math.h> 

#include "cacheBlock.h"
#include "cacheBlockCollection.h"

#define FAC_SIZE 512
#define NUM_TREE_LEVELS 9

class FAC{
    private:
        int totalHits;
        cacheBlockCollection table;
        vector<int> tree[NUM_TREE_LEVELS]; 
        vector<CacheBlock> treeTable; 
        int size; 
    public: 
        FAC(int); 
        void processLRU(long long, int);
        void processHC(long long);
        int getTotalHits(){return totalHits;}
   
};

#endif 