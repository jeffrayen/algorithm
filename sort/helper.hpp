#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <cmath>
#ifndef MAX
#define MAX 1000000
#endif

using std::vector;
using std::cout;

inline void swap(vector<int> &vec, int idx_1, int idx_2){
  if(idx_1==idx_2) return;
  if(vec[idx_1]!=vec[idx_2]){
    vec[idx_1] = vec[idx_1]^vec[idx_2];
    vec[idx_2] = vec[idx_1]^vec[idx_2];
    vec[idx_1] = vec[idx_1]^vec[idx_2];
  }
}

void print(const vector<int> vec){
  for(int i=0; i<vec.size(); ++i)
    cout << vec[i] << " ";
  cout << "\n";
}

// Make sure for each consecutive elements, if the later is greater then or equal to the former 
bool check_sort(const vector<int> vec){
  bool res = true;
  for(int i=0; i<vec.size()-1; ++i){
    if(vec.at(i+1)<vec.at(i)) {
      cout << "vec[" << i << "]: " << vec.at(i) << " is greater than vec[" << i+1 << "]: " << vec.at(i+1) << "\n";
      res = false;
    }
  } return res;
}

vector<int> generate_random_vector(const int size){
  srand(time(NULL));
  vector<int> res;
  res.reserve(size);
  for(int i=0; i<size; ++i){
    res.push_back(rand()%MAX);
  }
  return res;
}
