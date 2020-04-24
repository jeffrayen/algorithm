#ifndef _SWAP_HPP_
#define _SWAP_HPP_

#include <vector>

using std::vector;

inline void swap(vector<int> &vec, int idx_1, int idx_2){
  if(vec[idx_1]!=vec[idx_2]){
    vec[idx_1] = vec[idx_1]^vec[idx_2];
    vec[idx_2] = vec[idx_1]^vec[idx_2];
    vec[idx_1] = vec[idx_1]^vec[idx_2];
  }
}

#endif
