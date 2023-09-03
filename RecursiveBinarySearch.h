#pragma once
#include <vector>

class RecursiveBinarySearch
{
private:
  int do_search(std::vector<int> v, int value, int lo, int hi);

public:
  bool search(std::vector<int> list, int value);
};

