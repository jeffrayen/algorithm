#ifndef _HEAP_SORT_H_
#define _HEAP_SORT_H_
#include <vector>
#include <algorithm> // std::make_heap
#include "swap.hpp"

using std::vector;
using std::make_heap;

void heap_sort(vector<int> &vec);
void _make_heap(vector<int> &vec, const int idx, const int sorted);

#endif
