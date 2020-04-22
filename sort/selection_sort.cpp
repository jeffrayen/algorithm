#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#define MAX 10000

using std::vector;
using std::cout;

void print(const vector<int> vec);
void selection_sort(vector<int> &vec);
vector<int> generate_random_vector(const int size);

int main(int argc, char** argv)
{
  srand(time(NULL));
  vector<int> in_vec = generate_random_vector(atoi(argv[1]));
  //cout << "Input vector: \n"; print(in_vec);
  auto start = std::chrono::high_resolution_clock::now();
  selection_sort(in_vec);
  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count();
  //cout << "Sorted vector: \n";
  cout << "Selection sort Spend " << duration*1e-6 << " ms\n";
  //print(in_vec);
  return 0;
}

void print(const vector<int> vec){
  for(int i=0; i<vec.size(); ++i)
    cout << vec[i] << " ";
  cout << "\n";
}

void selection_sort(vector<int> &vec){
  int i, j, temp;
  for(i=0; i<vec.size()-1; ++i){ // Find minimum
    int min = i;
    for(j=i+1; j<vec.size(); ++j){
      if(vec[j]<vec[min]){
        min = j;
      }
    }
    if(min!=i){ // swap
      temp = vec[i];
      vec[i] = vec[min];
      vec[min] = temp;
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
