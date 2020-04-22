#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#ifndef MAX
#define MAX 10000
#endif
#ifndef COMPARE
  #ifndef VERSION
    #define VERSION 2
  #endif
#endif
using std::vector;
using std::cout;

void print(const vector<int> vec);
void insertion_sort_V1(vector<int> &vec);
void insertion_sort_V2(vector<int> &vec);
vector<int> generate_random_vector(const int size);

int main(int argc, char** argv)
{
  srand(time(NULL));
  vector<int> in_vec = generate_random_vector(atoi(argv[1]));
  #ifdef DEBUG
  cout << "Input vector: \n"; print(in_vec);
  #endif
  #ifdef COMPARE
  vector<int> in_vec1 = in_vec;
  auto start = std::chrono::high_resolution_clock::now();
  insertion_sort_V1(in_vec);
  auto end = std::chrono::high_resolution_clock::now();
  auto duration_1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count();
  start = std::chrono::high_resolution_clock::now();
  insertion_sort_V2(in_vec1);
  end = std::chrono::high_resolution_clock::now();
  auto duration_2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count();
  cout << "V1: " << duration_1*1e-6 << " ms\n";
  cout << "V2: " << duration_2*1e-6 << " ms\n";
  #endif
  #ifndef COMPARE
  auto start = std::chrono::high_resolution_clock::now();
  if(VERSION==1)
    insertion_sort_V1(in_vec);
  else
    insertion_sort_V2(in_vec);
  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count();
  cout << "Insertion sort spend " << duration*1e-6 << " ms\n";
  #ifdef DEBUG
  cout << "Sorted vector: \n"; print(in_vec);
  #endif
  #endif
  return 0;
}

void print(const vector<int> vec){
  for(int i=0; i<vec.size(); ++i)
    cout << vec[i] << " ";
  cout << "\n";
}

// Lower
void insertion_sort_V1(vector<int> &vec){
  vector<int> res;
  res.push_back(vec[0]);
  for(int i=1; i<vec.size(); ++i){
    int idx = 0;
    for(int j=0; j<res.size(); ++j){
      if(vec[i]>res[j]) idx+=1;
    }
    res.insert(res.begin()+idx, vec[i]);
  }
  vec = res;
}

// Faster, from Wiki
void insertion_sort_V2(vector<int> &vec){
  for(int i=1; i<vec.size(); ++i){
    int key = vec[i];
    int j = i-1;
    while(j>=0 and vec[j]>key){
      vec[j+1] = vec[j];
      --j;
    }
    vec[j+1] = key;
  }
}

vector<int> generate_random_vector(const int size){
  vector<int> res;
  for(int i=0; i<size; ++i){
    res.push_back(rand()%MAX);
  }
  return res;
}
