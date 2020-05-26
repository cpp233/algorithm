#ifndef _SELECTIONSORT_H_
#define _SELECTIONSORT_H_

#include <vector>

std::vector<int> selectionSort(const std::vector<int>& v){
    
    if(v.size() < 2){
        return v;
    }
    
    auto tempV = v;

    for(int i=0; i < tempV.size(); ++i){
        int k = i;
        for(int j = i+1; j < tempV.size(); ++j){
            if(tempV[j] < tempV[k]){
                k = j;
            }
        }
        int temp = tempV[i];
        tempV[i] = tempV[k];
        tempV[k] = temp;
    }

    return tempV;
}

#endif