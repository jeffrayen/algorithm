#include "heap_sort.h"
#include "swap.hpp"

void heap_sort(vector<int> &vec){
  std::make_heap(vec.begin(), vec.end());
  for(int i=0; i<vec.size(); ++i){
    swap(vec, 0, vec.size()-i-1);
    _make_heap(vec, 0, i+1);
  }
}

/* Subprocess for heap sort
  Pre  vec: vector that `partially` in heap structure
       idx: index to start heapify
       sorted: length in the given list that already sorted
  Post vec: vector in heap structure
*/ 
void _make_heap(vector<int> &vec, const int idx, const int sorted){
  if(2*idx+1>=vec.size()-sorted) return; // Leaf node
  // Set max leaf to left one
  int max_leaf_idx = 2*idx+1;
  // If have right leaf and right leaf value greater than left one
  if((max_leaf_idx+1<vec.size()-sorted) and \
    vec[max_leaf_idx]<vec[max_leaf_idx+1]){
    ++max_leaf_idx;
  }
  if(vec[max_leaf_idx]>=vec[idx]){
    swap(vec, idx, max_leaf_idx);
    _make_heap(vec, max_leaf_idx, sorted);
  }
}
