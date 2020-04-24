#include "quick_sort.h"
#ifndef _SWAP_HPP_
#include "swap.hpp"
#endif

void quick_sort(vector<int> &vec, int left, int right);
void quick_insertion(vector<int> &vec, int first, int last);
void _medianLeft(vector<int> &vec, int left, int right);

void _medianLeft(vector<int> &vec, const int left, const int right){
  int mid = (left+right)/2;
  if(vec[left]>vec[mid])   swap(vec, left, mid);
  if(vec[left]>vec[right]) swap(vec, left, right);
  if(vec[mid]>vec[right])  swap(vec, mid, right);
  // Swap middle to left
  swap(vec, left, mid);
}

void quick_sort(vector<int> &vec, int left, int right){
  if((right-left)>MIN_SIZE){
    // Quick sort
    _medianLeft(vec, left, right);
    int sortLeft = left+1, sortRight = right;
    while(sortLeft<=sortRight){
      // Find key on left that belongs on right
      while(vec[sortLeft]<vec[left])
        ++sortLeft;
      // Find key on right that belongs on left
      while(vec[sortRight]>=vec[left]){
        --sortRight;
        if(sortRight==left) break; // Break if minimum pivot
      }
      if(sortLeft<=sortRight){
        swap(vec, sortLeft, sortRight);
        ++sortLeft; --sortRight;
      }
    } // end while(sortLeft<=sortRight)
    // Prepare for next pass
    if(sortRight==left){
      quick_sort(vec, sortLeft, right); // Empty left array, sort right one
    }else{
      swap(vec, left, sortLeft-1);
      if(left<sortRight) quick_sort(vec, left, sortRight-1); // Sort left subarray
      if(sortLeft<right) quick_sort(vec, sortLeft, right);   // Sort right subarray
    }
  } // end if((right-left)>MIN_SIZE)
  else
    quick_insertion(vec, left, right);
}

void quick_insertion(vector<int> &vec, int first, int last){
  int current = first + 1;
  while(current<=last){
    int hold = vec[current], walker = current -1;
    while(walker>=first and hold<vec[walker]){
      vec[walker+1] = vec[walker];
      --walker;
    }
    vec[walker+1] = hold;
    ++current;
  }
}
