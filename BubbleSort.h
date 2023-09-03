#pragma once
#include <vector>
#include "Sort.h"

class BubbleSort : public Sort
{
private:
  void display(std::vector<int> list);

public:
  std::vector<int> sort(std::vector<int> list);
  std::vector<int> sort_optimized_1(std::vector<int> list);
  std::vector<int> sort_optimized_2(std::vector<int> list);
};
