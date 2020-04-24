#include "insertion_sort.h"

void insertion_sort(vector<int> &vec){
  for(int i=1; i<vec.size(); ++i){
    int key = vec[i], j = i-1;
    while(j>=0 and vec[j]>key){
      vec[j+1] = vec[j];
      --j;
    }
    vec[j+1] = key;
  }
}
