#include <iostream>
#include <vector>
#include "BubbleSort.h"

std::vector<int> BubbleSort::sort(std::vector<int> list)
{
  if (list.size() <= 1)
    return list;

  int compareSize = int(list.size());
  bool swapped = false;

  while (true)
  {
    swapped = false;

    for (int i = 0; i <= compareSize - 2; i++)
    {
      if (list.at(i) > list.at(i + 1))
      {
        std::swap(list[i], list[i + 1]);
        swapped = true;
      }
    }

    if (!swapped)
      break;
  }

  return list;
}

std::vector<int> BubbleSort::sort_optimized_1(std::vector<int> list)
{
  if (list.size() <= 1)
    return list;

  int compareSize = (int)list.size();
  bool swapped = false;
  int tempValue = 0;

  while (true)
  {
    swapped = false;

    for (int i = 0; i <= compareSize - 2; i++)
    {
      if (list.at(i) > list.at(i + 1))
      {
        tempValue = list.at(i);
        list.at(i) = list.at(i + 1);
        list.at(i + 1) = tempValue;

        swapped = true;
      }
    }

    compareSize--; // optimize

    if (!swapped)
      break;
  }

  return list;
}

std::vector<int> BubbleSort::sort_optimized_2(std::vector<int> list)
{
  if (list.size() <= 1)
    return list;

  int compareSize = (int)list.size();
  bool swapped = false;
  int lastSwapPos = 0;
  int tempValue = 0;

  while (true)
  {
    lastSwapPos = 0;
    swapped = false;

    for (int i = 0; i <= compareSize - 2; i++)
    {
      if (list.at(i) > list.at(i + 1))
      {
        tempValue = list.at(i);
        list.at(i) = list.at(i + 1);
        list.at(i + 1) = tempValue;

        lastSwapPos = i + 1;
      }
    }

    compareSize = lastSwapPos; // further optimize

    if (lastSwapPos <= 1)
      break;
  }

  return list;
}

void BubbleSort::display(std::vector<int> list)
{
  if (list.size() == 0)
  {
    std::cout << "list is empty" << std::endl;
    return;
  }

  std::vector<int>::iterator itr;
  for (itr = list.begin(); itr != list.end(); itr++)
    std::cout << *itr << "  ";

  std::cout << std::endl;
}

