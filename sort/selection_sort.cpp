#include <iostream>
#include <vector>
#include "helper.hpp"
#include "timer.hpp"

using std::vector;
using std::cout;

void selection_sort(vector<int> &vec);

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
  selection_sort(in_vec);
  t.set_tock();
  cout << "Selection sort spend " << t.get_ms() << " ms\n";
  #ifdef DEBUG
  cout << "Sorted vector: \n"; print(in_vec);
  #endif
  check_sort(in_vec);
  return 0;
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
