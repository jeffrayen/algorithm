#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <chrono>
#include <algorithm>
#include "tree.hpp"
#include "timer.hpp"
#include "helper.hpp"

using std::cout;
using std::vector;
using std::queue;
using std::stack;

void heap_sort(vector<int> &vec);
void heap_sort(vector<int> &vec);

int main(int argc, char** argv)
{
  srand(time(NULL));
  vector<int> in_vec = generate_random_vector(atoi(argv[1]));
  vector<int> cp_vec = in_vec;
  #ifdef DEBUG
  cout << "Input vector: \n"; print(in_vec);
  #endif
  Timer t;
  heap_sort(in_vec);
  t.set_tock();
  cout << "Heap sort (STL) spend " << t.get_ms() << " ms\n";
  #ifdef DEBUG
  cout << "Sort result: "; print(in_vec);
  #endif
  cout << "Is sort? " << check_sort(in_vec) << "\n";
  return 0;
}

void heap_sort(vector<int> &vec){
  Timer t1;
  TreeNode *tree = vec2tree(vec); // Convert to binary tree
  t1.set_tock();
  //cout << "Build tree " << t1.get_ms() << " ms\n";
  for(int i=vec.size()-1; i>2; --i){
    t1.reset();
    heapify(tree); // Convert to heap tree
    t1.set_tock();
    //cout << "Heapify tree " << t1.get_ms() << " ms\n";
    vec[i] = getNode(tree, 0)->val;
    getNode(tree, 0)->val = getNode(tree, i)->val;
    auto last_parent = getParent(tree, i);
    if(i%2==1) last_parent->left = NULL;
    else last_parent->right = NULL;
  }
  heapify(tree);
  vec[2] = tree->val;
  vec[1] = (tree->right->val>tree->left->val?tree->right->val:tree->left->val);
  vec[0] = (tree->right->val>tree->left->val?tree->left->val:tree->right->val);
}

void heap_sort_STL(vector<int> &vec){
  for(int i=0; i<vec.size(); ++i){
    std::make_heap(vec.begin(), vec.begin()+i);
    swap(vec, 0, vec.size()-i);
  }
}
