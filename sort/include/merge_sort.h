#ifndef _MERGE_SORT_H_
#define _MERGE_SORT_H_
#include <vector>

using std::vector;

void merge_sort(vector<int> &vec, const int left, const int right);
void _merge(vector<int> &vec, const int left_1, const int right_1, const int left_2, const int right_2);

#endif
