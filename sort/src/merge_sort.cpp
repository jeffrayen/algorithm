#include "merge_sort.h"

void merge_sort(vector<int> &vec, const int left, const int right){
  int mid = (left+right)/2;
  if(right!=left){
    merge_sort(vec, left, mid);
    merge_sort(vec, mid+1, right);
    _merge(vec, left, mid, mid+1, right);
  }
}

void _merge(vector<int> &vec, const int left_1, const int right_1, const int left_2, const int right_2){
  vector<int> left(vec.begin()+left_1, vec.begin()+right_1+1),
              right(vec.begin()+left_2, vec.begin()+right_2+1);
  int walker = left_1, w_l = 0, w_r = 0;
  while(w_l<left.size() && w_r<right.size()){
    if(left[w_l]<=right[w_r]){
      vec[walker] = left[w_l];
      ++w_l;
    }else{
      vec[walker] = right[w_r];
      ++w_r;
    } ++walker;
  }
  if(w_l==left.size()){ // Fill in the rest right sub list
    for(; w_r<right.size(); ++w_r){
      vec[walker] = right[w_r]; ++walker;
    }
  }else{ // Fill in the rest left sub list
    for(; w_l<left.size(); ++w_l){
      vec[walker] = left[w_l]; ++walker;
    }
  }
}
