#include <iostream>
#include <fstream>
#include <string>
#include <vector>
// Sort
#include "bubble_sort.h"
#include "cocktail_sort.h"
#include "heap_sort.h"
#include "insertion_sort.h"
#include "merge_sort.h"
#include "quick_sort.h"
#include "selection_sort.h"
#include "shell_sort.h"
// Others
#include "helper.hpp"
#include "timer.hpp"

#define SORT_NUM 8

/*
 TODO:
  1. Multi-threading
  2. Catch keyboard interrupt
*/


using std::string;
using std::vector;
using std::cout;
using std::ofstream;

string test(int size){
  string str; 
  vector<int> rng_vec_0, rng_vec_1, rng_vec_2, rng_vec_3, rng_vec_4, rng_vec_5, rng_vec_6, rng_vec_7;
  for(int i=0; i<size; ++i){
    rng_vec_0.push_back(rand()%MAX);
  }
  rng_vec_1 = rng_vec_0;
  rng_vec_2 = rng_vec_0;
  rng_vec_3 = rng_vec_0;
  rng_vec_4 = rng_vec_0;
  rng_vec_5 = rng_vec_0;
  rng_vec_6 = rng_vec_0;
  rng_vec_7 = rng_vec_0;
  str += std::to_string(size) + ",";
  Timer t;
  bubble_sort(rng_vec_0);
  t.set_tock(); str += std::to_string(t.get_ms()) + ",";
  t.reset();
  //
  cocktail_sort(rng_vec_1);
  t.set_tock(); str += std::to_string(t.get_ms()) + ",";
  t.reset();
  //
  heap_sort(rng_vec_2);
  t.set_tock(); str += std::to_string(t.get_ms()) + ",";
  t.reset();
  //
  insertion_sort(rng_vec_3);
  t.set_tock(); str += std::to_string(t.get_ms()) + ",";
  t.reset();
  //
  selection_sort(rng_vec_4);
  t.set_tock(); str += std::to_string(t.get_ms()) + ",";
  t.reset();
  shell_sort(rng_vec_5);
  t.set_tock(); str += std::to_string(t.get_ms()) + ",";
  cout << str;
  //
  merge_sort(rng_vec_6, 0, rng_vec_6.size()-1);
  t.set_tock(); str += std::to_string(t.get_ms()) + ",";
  t.reset();
  //
  quick_sort(rng_vec_7, 0, rng_vec_7.size()-1);
  t.set_tock(); str += std::to_string(t.get_ms()) + "\n";
  t.reset();
  //
  
  return str;
}

int main(int argc, char** argv)
{
  srand(time(NULL));
  if(argc<2){
    std::cerr << "\033[1;33mNot enough arguments, abort...\n\033[0m";
    exit(EXIT_FAILURE);
  }
  ofstream file;
  file.open("result.csv", ofstream::out);
  file << ",Bubble,Cocktail,Heap,Insertion,Selection,Shell,Merge,Quick\n";
  int size = 10;
  while(size<=atoi(argv[1])){
    auto str = test(size);
    cout << str;
    file << str;
    cout << "Size: " << size << " complete\n";
    size += 10;
  }
  file.close();
  
  return 0;
}
