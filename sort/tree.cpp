#include <iostream>
#include <cmath>
#include <queue>
#include <stack>

using std::cout;
using std::vector;
using std::stack;
using std::queue;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

inline void swap(int &a, int &b){
  if(a!=b){
    a = a^b;
    b = a^b;
    a = a^b;
  }
}
void print_tree(TreeNode *in_tree);
TreeNode* vec2tree(const vector<int> vec);
TreeNode* getNode(TreeNode* tree, int idx);
TreeNode* getParent(TreeNode* tree, int idx);
void heapify(TreeNode* tree);
void _max_heap(TreeNode* tree);
void tree2vec(TreeNode* tree, vector<int> &vec);

void print_tree(TreeNode *in_tree){
  if(!in_tree) return; // Empty
  TreeNode *node = in_tree;
  queue<TreeNode*> queue;
  cout << "[" << node->val;
  if(node->right)
    queue.push(node->right);
  node = node->left;
  while(1){
    cout << ", " << node->val;
    if(node->left)
      queue.push(node->left);
    if(node->right)
      queue.push(node->right);
    node = queue.front();
    queue.pop();
    if(queue.empty()){
      cout << ", " << node->val;
      break;
    }
  }
  cout << "]\n";
}

TreeNode* vec2tree(const vector<int> vec){
  TreeNode* tree;
  if(vec.size()==0) return tree;
  tree = new TreeNode(vec[0]);
  for(int i=1; i<vec.size(); ++i){
    TreeNode *parent_node = getParent(tree, i);
    TreeNode *tmp = new TreeNode(vec[i]); 
    if(i%2==1)
      parent_node->left = tmp;
    else
      parent_node->right = tmp;
  }
  return tree;
}

void tree2vec(TreeNode* tree, vector<int> &vec){
  int idx = 0;
  TreeNode *node = tree;
  queue<TreeNode*> queue;
  if(node->right)
    queue.push(node->right);
  vec[idx] = node->val; ++idx;
  node = node->left;
  while(1){
    vec[idx] = node->val; ++idx;
    if(node->left)
      queue.push(node->left);
    if(node->right)
      queue.push(node->right);
    node = queue.front();
    queue.pop();
    if(queue.empty()){
      vec[idx] = node->val;
      break;
    }
  }
}

TreeNode* getNode(TreeNode* tree, int idx){
  if(idx==0) return tree;
  TreeNode *tmp = tree;
  stack<int> idx_stack;
  int i = idx;
  while(i!=0){
    idx_stack.push(i);
    i = floor((i-1)/2);
  }
  while(!idx_stack.empty()){
    if(idx_stack.top()%2==1)
      tmp = tmp->left;
    else
      tmp = tmp->right;
    idx_stack.pop();
  }
  return tmp;
}

TreeNode* getParent(TreeNode* tree, int idx){
  TreeNode *tmp = tree;
  stack<int> idx_stack;
  int i = floor((idx-1)/2);
  while(i!=0){
    idx_stack.push(i);
    i = floor((i-1)/2);
  }
  if(idx_stack.empty()) return tree;
  while(!idx_stack.empty()){
    if(idx_stack.top()%2==1)
      tmp = tmp->left;
    else
      tmp = tmp->right;
    idx_stack.pop();
  }
  return tmp;
}

void heapify(TreeNode* tree){
  // Counting tree level
  TreeNode *tmp = tree;
  int level = 0;
  while(tmp){
    tmp = tmp->left;
    ++level;
  }
  for(int l=level-2; l>=0; --l){
    int idx = pow(2, l)-1;
    for(int inner=idx; inner<=idx*2; ++inner){
      TreeNode *node = getNode(tree, inner);
      _max_heap(node);
    }
  }
}

void _max_heap(TreeNode* tree){
  if(!tree->left and !tree->right) return;
  int max_leaf = tree->left->val;
  bool left_max = true;
  if(tree->right){
    if(tree->right->val>=max_leaf){
      max_leaf = tree->right->val;
      left_max = false;
    }
  }
  if(max_leaf>=tree->val){
    (left_max?swap(tree->val, tree->left->val):swap(tree->val, tree->right->val));
    (left_max?_max_heap(tree->left):_max_heap(tree->right));
  }
}
