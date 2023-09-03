#include <iostream>
#include <string>
#include <vector>
#include "BubbleSort.h"
#include "QuickSort.h"
#include "RecursiveBinarySearch.h"

//void test_sort_search(int sortType, int searchValue);

int main(int argc, char *argv[])
{
  const int SEARCH_VALUE = 1;

  try
  {
    // test sort and function
    // searchType: 0 for bubble sort, 1 or others for quick sort
    // searchValue: value to be searched
    //test_sort_search(1, 3);
    //return 0;

    // obtain integer list
    if (argc <= 1)
    {
      std::cout << "no integer is provided." << std::endl;
      return 0;
    }

    std::vector<int> list;
    for (int i = 1; i < argc; i++)
      list.push_back(std::stoi(argv[i]));

    // perform quick sort
    QuickSort quickSort;
    std::vector<int> sortedList = quickSort.sort(list);

    // perform binary search
    RecursiveBinarySearch recursiveBinarySearch;
    bool found = recursiveBinarySearch.search(sortedList, SEARCH_VALUE);

    // generate output
    if (found)
      std::cout << "true ";
    else
      std::cout << "false ";

    std::vector<int>::iterator itr;
    for (itr = sortedList.begin(); itr != sortedList.end(); itr++)
      std::cout << *itr << " ";
    std::cout << std::endl;
  }
  catch (std::exception& exc)
  {
    std::cout << exc.what() << std::endl;
  }

  return 0;
}
/*
void test_sort_search(int sortType, int searchValue)
{
  const int SEARCH_VALUE_NO_SEARCH = 888;

  std::vector<int> lists[] =
  {
    {10, 9, 2, 3},
    {5, 2, 3, 1, 0},
    {9, 10, 3},
    {10, -2, 2, 3, 2, 8, 2, 2, 2, 2, -2, -10, 9, 8, 7, 6, 5, 4, 3, 10},
    {0},
    {0, 0},
    {0, 0, 0},
    {0, 0, 0, 0},
    {1, 2},
    {1, 2, 3},
    {1, 2, 3, 3},
    {2, 1},
    {3, 2, 1},
    {3, 3, 3, 3},
    {1, 1, 2, 3, 4, 4, 5, 6, 7, 7, 8, 8, 8, 9, 10, 10, 0, 0},
    {3, 3, 2, 1},
    {4, 5, 6, 7},
    {5, 4, 3, 1, 2},
    {1, 3, 5, 4, -5, 100, 7777, 2014},
    {0, 3, 5, 4, -5, 100, 7777, 2014}
  };

  BubbleSort bubbleSort;
  QuickSort quickSort;
  RecursiveBinarySearch recursiveBinarySearch;
  
  std::vector<int>::iterator itr;

  int numberTestCases = sizeof(lists) / sizeof(lists[0]);
  bool found = false;
  std::cout << "Total " << numberTestCases << " testing cases...";
  if (searchValue == SEARCH_VALUE_NO_SEARCH)
    std::cout << "no search" << std::endl;
  else
    std::cout << "searching " << searchValue << std::endl;

  for (int i = 0; i < sizeof(lists) / sizeof(lists[0]); i++)
  {
    std::cout << "test case " << i + 1 << std::endl;
    for (itr = lists[i].begin(); itr != lists[i].end(); itr++)
      std::cout << *itr << "  ";
    std::cout << " -> ";

    std::vector<int> sortedList;
    if (sortType == 0)
      sortedList = bubbleSort.sort(lists[i]);
    else
      sortedList = quickSort.sort(lists[i]);

    for (itr = sortedList.begin(); itr != sortedList.end(); itr++)
      std::cout << *itr << "  ";

    if (searchValue != SEARCH_VALUE_NO_SEARCH)
    {
      found = recursiveBinarySearch.search(sortedList, searchValue);
      if (found)
        std::cout << "found" << std::endl;
      else
        std::cout << "not found" << std::endl;
    }
    else
      std::cout << std::endl;
  }
}
*/
