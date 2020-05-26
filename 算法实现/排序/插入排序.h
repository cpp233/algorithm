#ifndef _INSERTSORT_H_
#define _INSERTSORT_H_

#include <vector>

std::vector<int> insertSort(const std::vector<int>& v){

    if(v.size() < 2){
        return v;
    }

    auto tempV = v;

    for(int i = 1; i < tempV.size(); ++i){

        if(tempV[i] < tempV[i-1]){
            for(int j = 0; j < i;++j){
                if(tempV[i]<tempV[j]){
                    auto temp = tempV[i];
                    for(int k = i; k > j;--k){
                        tempV[k] = tempV[k-1];
                    }
                    tempV[j] = temp;
                }
            }
        }
    }

    return tempV;
}

#endif