#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include "helper.hpp"
#include "timer.hpp"

using std::vector;
using std::cout;

void insertion_sort(vector<int> &vec);

int main(int argc, char** argv)
{
  srand(time(NULL));
  vector<int> in_vec = generate_random_vector(atoi(argv[1]));
  #ifdef DEBUG
  cout << "Input vector: \n"; print(in_vec);
  #endif
  Timer t;
  insertion_sort(in_vec);
  t.set_tock();
  cout << "Insertion sort spend " << t.get_ms() << " ms\n";
  #ifdef DEBUG
  cout << "Sorted vector: \n"; print(in_vec);
  #endif
  return 0;
}

void insertion_sort(vector<int> &vec){
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
