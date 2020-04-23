#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <cmath>
#ifndef MAX
#define MAX 10000
#endif

using std::vector;
using std::cout;

void print(const vector<int> vec);
void shell_sort(vector<int> &vec);
vector<int> generate_random_vector(const int size);

int main(int argc, char** argv)
{
  srand(time(NULL));
  vector<int> in_vec = generate_random_vector(atoi(argv[1]));
  #ifdef DEBUG
  cout << "Input vector: \n"; print(in_vec);
  #endif
  auto start = std::chrono::high_resolution_clock::now();
  shell_sort(in_vec);
  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count();
  cout << "Shell sort spend " << duration*1e-6 << " ms\n";
  #ifdef DEBUG
  cout << "Sored vector: \n"; print(in_vec);
  #endif
  return 0;
}

void print(const vector<int> vec){
  for(int i=0; i<vec.size(); ++i)
    cout << vec[i] << " ";
  cout << "\n";
}

void shell_sort(vector<int> &vec){
  int gap = vec.size()/2;
  while(gap>=1){
    // Insertion sort to sort sub-array
    for(int i=gap; i<vec.size(); ++i){
      int tmp = vec[i], idx = i;
      while(idx>=gap and vec[idx-gap]>tmp){
        vec[idx] = vec[idx-gap];
        idx -= gap;
      }
      vec[idx] = tmp;
    }
    gap >>= 1; // gap /= 2
  }
}

vector<int> generate_random_vector(const int size){
  vector<int> res;
  for(int i=0; i<size; ++i){
    res.push_back(rand()%MAX);
  }
  return res;
}
