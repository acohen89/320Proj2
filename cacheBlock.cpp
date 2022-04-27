#include "cacheBlock.h"

CacheBlock::cacheBlock(){
    valid = 0; 
    tag = -1; 
    accessTime = INT_MAX; 
}