#include <iostream>
#include <vector>
#include "helper.hpp"
#include "timer.hpp"

using std::vector;
using std::cout;

void bubble_sort(vector<int> &vec);

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
  bubble_sort(in_vec);
  t.set_tock();
  cout << "Bubble sort spend " << t.get_ms() << " ms\n";
  #ifdef DEBUG
  cout << "Sorted vector: \n"; print(in_vec);
  #endif
  check_sort(in_vec);
  return 0;
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
