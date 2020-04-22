#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#define MAX 10000

using std::vector;
using std::cout;

void print(const vector<int> vec);
void merge_sort(vector<int> &vec);
vector<int> _merge(vector<int> vec_1, vector<int> vec_2);
vector<int> generate_random_vector(const int size);

int main(int argc, char** argv)
{
  srand(time(NULL));
  vector<int> in_vec = generate_random_vector(atoi(argv[1]));
  //cout << "Input vector: \n"; print(in_vec);
  auto start = std::chrono::high_resolution_clock::now();
  merge_sort(in_vec);
  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count();
  cout << "Merge sort Spend " << duration*1e-6 << " ms\n";
  //cout << "Sorted vector: \n"; print(in_vec);
  return 0;
}

void merge_sort(vector<int> &vec){
  vector<int> left, right;
  // Split until size one or zero
  left = vector<int>(vec.begin(), vec.begin()+vec.size()/2);
  right = vector<int>(vec.begin()+vec.size()/2, vec.end());
  if(left.size()>1) merge_sort(left);
  if(right.size()>1) merge_sort(right);
  vec = _merge(left, right);
  
}

vector<int> _merge(vector<int> vec_1, vector<int> vec_2){
  vector<int> res;
  int i= 0, j = 0;
  while(1){
    if(i==vec_1.size()){
      for(;j<vec_2.size(); ++j) res.push_back(vec_2[j]);
      break;
    }
    if(j==vec_2.size()){
      for(;i<vec_2.size(); ++i) res.push_back(vec_1[i]);
      break;
    }
    if(vec_1[i]>=vec_2[j]){
      res.push_back(vec_2[j]);
      ++j;
    }else{
      res.push_back(vec_1[i]);
      ++i;
    }
  }
  return res;
}

vector<int> generate_random_vector(const int size){
  vector<int> res;
  for(int i=0; i<size; ++i){
    res.push_back(rand()%MAX);
  }
  return res;
}

void print(const vector<int> vec){
  for(int i=0; i<vec.size(); ++i)
    cout << vec[i] << " ";
  cout << "\n";
}
