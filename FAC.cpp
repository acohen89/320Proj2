#include "FAC.h"

FAC::FAC(int s){
    size = s;
    table.setSize(FAC_SIZE); 
    treeTable.resize(FAC_SIZE); 
    totalHits = 0; 
    for(int i = 0; i < NUM_TREE_LEVELS; i++){
        int levelSize = pow(2, i); 
        tree[i].resize(levelSize);
        for(int k = 0; k < levelSize; k++){
            tree[i].at(k) = 0; 
        }
    }
}

void FAC::processLRU(long long address, int accessTime){
    int tag = address >> 5; 
    totalHits += table.insert(tag, accessTime); 
}


void printTree(vector<int> tree[]){
     for(int i = 0; i < NUM_TREE_LEVELS; i++){
        int levelSize = pow(2, i);
        for(int k = 0; k < levelSize; k++){
            cout << tree[i].at(k); 
        }
        cout << endl; 
     }
}

void FAC::processHC(long long address){
    int tag = address >> 5; 
    for(int i = 0; i < treeTable.size(); i++){
        if(treeTable.at(i).getTag() == tag){
            totalHits++; 
            //* update tree 
            int end = FAC_SIZE; 
            int start = 0; 
            int curIndex = 0; 
            int targetIndex = i;
            for(int j = 0; j < NUM_TREE_LEVELS; j++){
                int updateIndex = curIndex;
                if(targetIndex - start >= (end - start) / 2){ //right side
                    start = ((end - start) / 2) + start;
                    curIndex = (curIndex  * 2) + 1;
                }else { //left side 
                    end = ((end - start) / 2) - end;
                    curIndex *=2; 
                }
                tree[j].at(updateIndex) = tree[j].at(updateIndex) == 0 ? 1 : 0; 
            }
            return;
        }
    }
    int curIndex = 0;  
    for(int i = 0; i < NUM_TREE_LEVELS; i++){
        int updateIndex = curIndex;
        if(curIndex == 0){
            curIndex = tree[i].at(curIndex) == 0 ? 0 : 1; 
        } else {
            curIndex = (curIndex * 2) + (tree[i].at(curIndex) == 1 ? 1 : 0); 
        }
        tree[i].at(updateIndex) = tree[i].at(updateIndex) == 0 ? 1 : 0; 
    }
    treeTable.at(curIndex).setTag(tag); 
    treeTable.at(curIndex).setValid(1); 
}