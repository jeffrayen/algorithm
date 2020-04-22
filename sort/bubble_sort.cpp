#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#define MAX 10000

using std::vector;
using std::cout;

inline void swap(vector<int> &vec, int i, int j){
  if(vec[i]!=vec[j]){
    vec[i] = vec[i]^vec[j];
    vec[j] = vec[i]^vec[j];
    vec[i] = vec[i]^vec[j];
  }
}
void print(const vector<int> vec);
void bubble_sort(vector<int> &vec);
vector<int> generate_random_vector(const int size);

int main(int argc, char** argv)
{
  srand(time(NULL));
  vector<int> in_vec = generate_random_vector(atoi(argv[1]));
  //cout << "Input vector: \n"; print(in_vec);
  auto start = std::chrono::high_resolution_clock::now();
  bubble_sort(in_vec);
  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count();
  cout << "Bubble sort spend " << duration*1e-6 << " ms\n";
  //cout << "Sorted vector: \n"; print(in_vec);
  return 0;
}

void print(const vector<int> vec){
  for(int i=0; i<vec.size(); ++i)
    cout << vec[i] << " ";
  cout << "\n";
}

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

vector<int> generate_random_vector(const int size){
  vector<int> res;
  for(int i=0; i<size; ++i){
    res.push_back(rand()%MAX);
  }
  return res;
}
