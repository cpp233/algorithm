#ifndef _BUBBLESORT_H_
#define _BUBBLESORT_H_

#include <vector>

std::vector<int> bubbleSorting(const std::vector<int>& v){

    if(v.size() < 2){
        return v;
    }

    auto tempV = v;
    for(int i = v.size(); i > 0; --i){
        for(int j = 0; j+1 < i; ++j){
            if( tempV[j] > tempV[j+1] ){
                auto temp = tempV[j+1];
                tempV[j+1] = tempV[j];
                tempV[j] = temp;
            }
        }
    }

    return tempV;
}

#endif