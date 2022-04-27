#ifndef CACHEBLOCKCOLLECTION_H
#define CACHEBLOCKCOLLECTION_H

using namespace std; 
#include <vector>
#include <iostream> 
#include <list>
#include <bits/stdc++.h>

#include "cacheBlock.h"

#define MAX_ASOC 512

class cacheBlockCollection{
    private:
        int size;
        CacheBlock lruArr[MAX_ASOC]; 
    public: 
        cacheBlockCollection(int);
        cacheBlockCollection();
        friend ostream& operator<<(ostream&, const cacheBlockCollection&);
        short insert(int, int);
        void setSize(int s){size = s;}
};

#endif 