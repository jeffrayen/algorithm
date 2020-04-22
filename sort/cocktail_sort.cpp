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
void cocktail_sort(vector<int> &vec);
vector<int> generate_random_vector(const int size);

int main(int argc, char** argv)
{
  srand(time(NULL));
  vector<int> in_vec = generate_random_vector(atoi(argv[1]));
  //cout << "Input vector: \n"; print(in_vec);
  auto start = std::chrono::high_resolution_clock::now();
  cocktail_sort(in_vec);
  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count();
  cout << "Cocktail sort spend " << duration*1e-6 << " ms\n";
  //cout << "Sorted vector: \n"; print(in_vec);
  return 0;
}

void print(const vector<int> vec){
  for(int i=0; i<vec.size(); ++i)
    cout << vec[i] << " ";
  cout << "\n";
}

void cocktail_sort(vector<int> &vec){
  int left = 0, right = vec.size()-1;
  while(left<right){
    bool best_case = true;
    for(int j=0; j<right; ++j){
      if(vec[j]>vec[j+1]){
        swap(vec, j, j+1); // Move maximum to right
        best_case = false;
      }
    }
    --right;
    for(int j=right; j>left; --j){
      if(vec[j]<vec[j-1]){
        swap(vec, j, j-1); // Move minimum to left
        best_case = false;
      }
    }
    ++left;
    if(best_case){
      break; // After single pass no swap is maded, which means that the list is already sorted
    }
  }
}

vector<int> generate_random_vector(const int size){
  vector<int> res;
  for(int i=0; i<size; ++i){
    res.push_back(rand()%MAX);
  }
  return res;
}
