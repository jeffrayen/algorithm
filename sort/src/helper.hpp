#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#ifndef MAX
#define MAX 1000000
#endif

using std::vector;
using std::cout;

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
  vector<int> res;
  //res.reserve(size);
  cout << "gen\n";
  for(int i=0; i<size; ++i){
    res.push_back(rand()%MAX);
  }
  cout << "return\n";
  return res;
}
