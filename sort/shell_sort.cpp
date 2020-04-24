#include <iostream>
#include <vector>
#include "helper.hpp"
#include "timer.hpp"

using std::vector;
using std::cout;

void shell_sort(vector<int> &vec);

int main(int argc, char** argv)
{
  if(argc<2){
    std::cerr << "\033[1;31mNo enough input arguments, abort...\n\033[0m";
    exit(EXIT_FAILURE);
  }
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
  check_sort(in_vec);
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
