#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#define MAX 10000

using std::vector;
using std::cout;

void print(const vector<int> vec);
void quick_sort(vector<int> &vec);
vector<int> generate_random_vector(const int size);

int main(int argc, char** argv)
{
  srand(time(NULL));
  vector<int> in_vec = generate_random_vector(atoi(argv[1]));
  vector<int> cp_vec = in_vec;
  //cout << "Input vector: \n"; print(in_vec);
  auto start = std::chrono::high_resolution_clock::now();
  quick_sort(in_vec);
  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count();
  cout << "Quick sort Spend " << duration*1e-6 << " ms\n";
  //cout << "Sorted vector: \n"; print(in_vec);
  return 0;
}

void print(const vector<int> vec){
  for(int i=0; i<vec.size(); ++i)
    cout << vec[i] << " ";
  cout << "\n";
}

void quick_sort(vector<int> &vec){
  // Select pivot
  int pivot = vec[rand()%vec.size()]; // Random select
  vector<int> less, greater;
  // Partition into two sub-lists: less and greater
  for(int i=0; i<vec.size()-1; ++i){
    if(pivot<vec[i])
      greater.push_back(vec[i]);
    else
      less.push_back(vec[i]);
  }
  if(less.size()>1) quick_sort(less); // Sort less sub-list
  if(greater.size()>1) quick_sort(greater); // Sort greater sub-list
  // Sorted list = [less sub-list] [pivot] [greater sub-list]
  for(int i=0; i<less.size(); ++i)
    vec[i] = less[i];
  vec[less.size()] = pivot;
  for(int i=0; i<greater.size(); ++i)
    vec[less.size()+1+i] = greater[i];
}

vector<int> generate_random_vector(const int size){
  vector<int> res;
  for(int i=0; i<size; ++i){
    res.push_back(rand()%MAX);
  }
  return res;
}

