#include "cacheBlockCollection.h"

cacheBlockCollection::cacheBlockCollection(int assocSize){
    size = assocSize; 
}


short cacheBlockCollection::insert(int tag, int accessTime){
    // checks for hit  
    for(int i = 0; i < size; i++){
        if(lruArr[i].getTag() == tag){
            lruArr[i].setAccessTime(accessTime);
            return 1;
        }
    }
    // checks for place to insert
    for(int i = 0; i < size; i++){
        if(lruArr[i].getValid() != 1){
            lruArr[i].setValid(1); 
            lruArr[i].setTag(tag); 
            lruArr[i].setAccessTime(accessTime);
            return 0; 
        }
    }
    //cache is full, so looks for replacement 
    int lruAT = INT_MAX; 
    int lruI = -1;
     for(int i = 0; i < size; i++){
        if(lruArr[i].getAccessTime() < lruAT){
            lruI = i;
            lruAT = lruArr[i].getAccessTime();
        }
    }
    lruArr[lruI].setTag(tag); 
    lruArr[lruI].setAccessTime(accessTime); 
    return 0; 
}





cacheBlockCollection::cacheBlockCollection(){
}

ostream& operator<<(ostream& os, const cacheBlockCollection& cbc)
{   
    os << "Size: " << cbc.size << endl; 
    return os;
}