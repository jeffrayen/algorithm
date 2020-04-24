#include "shell_sort.h"

void shell_sort(vector<int> &vec){
  int gap = vec.size()/2;
  while(gap>=1){
    // Insertion sort to sort sub-array
    for(int i=gap; i<vec.size(); ++i){
      int tmp = vec[i], idx = i;
      while(idx>=gap and vec[idx-gap]>tmp){
        vec[idx] = vec[idx-gap];
        idx -= gap;
      }
      vec[idx] = tmp;
    }
    gap >>= 1; // gap /= 2
  }
}
