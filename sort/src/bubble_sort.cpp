#include "bubble_sort.h"

void bubble_sort(vector<int> &vec){
  bool best_case = true; // If no swap in first pass, then the given list is already sorted
  for(int i=0; i<vec.size()-1; ++i){
    for(int j=0; j<vec.size()-i-1; ++j){
      if(vec[j]>=vec[j+1]){
        swap(vec, j, j+1);
        best_case = false;
      }
    }
    if(best_case) break;
  }
}
