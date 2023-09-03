#pragma once

#include <vector>
#include "Sort.h"

class QuickSort : public Sort
{
private:
  void do_quick_sort(std::vector<int>& v, int lo, int hi);
  int partition(std::vector<int>& v, int lo, int hi);
  void do_quick_sort_lomuto(std::vector<int>& v, int lo, int hi);
  int partition_lomuto(std::vector<int>& v, int lo, int hi);
  void do_quick_sort_hoare(std::vector<int>& v, int lo, int hi);
  int partition_hoare(std::vector<int>& v, int lo, int hi);

public:
  std::vector<int> sort(std::vector<int> list);
};

