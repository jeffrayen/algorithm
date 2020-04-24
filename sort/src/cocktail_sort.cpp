#include "cocktail_sort.h"
#ifndef _SWAP_HPP_
#include "swap.hpp"
#endif

void cocktail_sort(vector<int> &vec){
  int left = 0, right = vec.size()-1;
  while(left<right){
    bool best_case = true;
    for(int j=0; j<right; ++j){
      if(vec[j]>vec[j+1]){
        swap(vec, j, j+1); // Move maximum to right
        best_case = false;
      }
    }
    --right;
    for(int j=right; j>left; --j){
      if(vec[j]<vec[j-1]){
        swap(vec, j, j-1); // Move minimum to left
        best_case = false;
      }
    }
    ++left;
    if(best_case){
      break; // After single pass no swap is maded, which means that the list is already sorted
    }
  }
}
