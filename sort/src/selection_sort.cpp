#include "selection_sort.h"
#ifndef _SWAP_HPP_
#include "swap.hpp"
#endif

void selection_sort(vector<int> &vec){
  int i, j, temp;
  for(i=0; i<vec.size()-1; ++i){ // Find minimum
    int min = i;
    for(j=i+1; j<vec.size(); ++j){
      if(vec[j]<vec[min]){
        min = j;
      }
    }
    if(min!=i)
      swap(vec, i, min);
  }
}
