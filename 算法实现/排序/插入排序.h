/*
    插入排序
    · 序列分有序序列和无序序列
    · 每次遍历无序序列
    · 按需要将无序序列中 大于或小于 有序序列末尾的数
    · 按顺序插入有序序列
*/
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