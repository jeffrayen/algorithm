#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <cmath>
#include "timer.hpp"
#include "helper.hpp"

using std::vector;
using std::cout;

void shell_sort(vector<int> &vec);

int main(int argc, char** argv)
{
  srand(time(NULL));
  vector<int> in_vec = generate_random_vector(atoi(argv[1]));
  #ifdef DEBUG
  cout << "Input vector: \n"; print(in_vec);
  #endif
  Timer t;
  shell_sort(in_vec);
  t.set_tock();
  cout << "Shell sort spend " << t.get_ms() << " ms\n";
  #ifdef DEBUG
  cout << "Sored vector: \n"; print(in_vec);
  #endif
  return 0;
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
