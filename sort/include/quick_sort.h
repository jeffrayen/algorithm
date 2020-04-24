#ifndef _QUICK_SORT_H_
#define _QUICK_SORT_H_
#define MIN_SIZE 16
#include <vector>

using std::vector;

void quick_sort(vector<int> &vec, int left, int right);
void quick_insertion(vector<int> &vec, int first, int last);
void _medianLeft(vector<int> &vec, int left, int right);

#endif
