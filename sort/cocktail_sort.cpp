#include <iostream>
#include <vector>
#include "helper.hpp"
#include "timer.hpp"

using std::vector;
using std::cout;

void cocktail_sort(vector<int> &vec);

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
  cocktail_sort(in_vec);
  t.set_tock();
  cout << "Cocktail sort spend " << t.get_ms() << " ms\n";
  #ifdef DEBUG
  cout << "Sorted vector: \n"; print(in_vec);
  #endif
  check_sort(in_vec);
  return 0;
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
