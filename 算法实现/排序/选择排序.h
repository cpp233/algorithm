/*
    选择排序
    ·每趟遍历选择最小的数放到序列开头
    ·剩余元素构成的序列重复这个过程
    ·继续选择最小的数放到剩下序列的开头
*/
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