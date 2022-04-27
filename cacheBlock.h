#ifndef CACHBLOCK_H
#define CACHEBLOCK_H
#include <climits>
#pragma once

class CacheBlock{
    public:
        cacheBlock();
        void setTag(long long t){tag = t;}
        void setValid(short v){valid = v;}
        void setAccessTime(int at){accessTime = at;}
        short getValid(){return valid;}
        int getAccessTime(){return accessTime;}
        long long getTag(){return tag;}
    private:
        long long tag; 
        int accessTime; 
        short valid;  
};

#endif