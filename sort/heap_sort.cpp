#include <iostream>
#include <vector>
#include <algorithm> // std::make_heap
#include "timer.hpp"
#include "helper.hpp"

using std::cout;
using std::vector;

void heap_sort(vector<int> &vec);

int main(int argc, char** argv)
{
  if(argc<2){
    std::cerr << "\033[1;31mNo enough input arguments, abort...\n\033[0m";
    exit(EXIT_FAILURE);
  }
  vector<int> in_vec = generate_random_vector(atoi(argv[1]));
  #ifdef DEBUG
  cout << "Input vector: \n"; print(in_vec);
  #endif
  Timer t;
  heap_sort(in_vec);
  t.set_tock();
  cout << "Heap sort spend " << t.get_ms() << " ms\n";
  #ifdef DEBUG
  cout << "Sort result: "; print(in_vec);
  #endif
  check_sort(in_vec);
  return 0;
}

void heap_sort(vector<int> &vec){
  for(int i=0; i<vec.size(); ++i){
    std::make_heap(vec.begin(), vec.end()-i);
    swap(vec, 0, vec.size()-i-1);
  }
}
