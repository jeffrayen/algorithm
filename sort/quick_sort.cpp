#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include "timer.hpp"
#include "write_file.hpp"
#include "helper.hpp"
#define MIN_SIZE 16

using std::vector;
using std::cout;

void quick_sort(vector<int> &vec, int left, int right);
void quick_insertion(vector<int> &vec, int first, int last);
void _medianLeft(vector<int> &vec, int left, int right);

int main(int argc, char** argv)
{
  if(argc<2){
    std::cerr << "\033[1;31mNo enough input arguments, abort...\n\033[0m";
    exit(EXIT_FAILURE);
  }
  vector<int> in_vec = generate_random_vector(atoi(argv[1]));
  #ifdef DEBUG
  write_file(in_vec, "unsort_vec.csv");
  #endif
  Timer t;
  quick_sort(in_vec, 0, in_vec.size()-1);
  t.set_tock();
  cout << "Quick sort spend " << t.get_ms() << " ms\n";
  #ifdef DEBUG
  write_file(in_vec, "sort_vec.csv");
  #endif
  check_sort(in_vec);
  return 0;
}

void _medianLeft(vector<int> &vec, const int left, const int right){
  assert(vec.size()>=3);
  int mid = (left+right)/2;
  if(vec[left]>vec[mid])   swap(vec, left, mid);
  if(vec[left]>vec[right]) swap(vec, left, right);
  if(vec[mid]>vec[right])  swap(vec, mid, right);
  // Swap middle to left
  swap(vec, left, mid);
}

void quick_sort(vector<int> &vec, int left, int right){
  #ifdef DEBUG
  cout << "quick sort with left " << left << " and right " << right << " and vector\n"; print(vec); 
  #endif
  if((right-left)>MIN_SIZE){
    // Quick sort
    _medianLeft(vec, left, right);
    #ifdef DEBUG
    cout << "Pivot: " << vec[left] << "\n";
    #endif
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
