#include <vector>
#include "RecursiveBinarySearch.h"

bool RecursiveBinarySearch::search(std::vector<int> list, int value)
{
  if (list.size() == 0)
    return false;

  int p = do_search(list, value, 0, int(list.size()) - 1);
  return (p >= 0);
}

int RecursiveBinarySearch::do_search(
  std:: vector<int> v, int value, int lo, int hi)
{
  if (hi >= lo)
  {
    int mid = int((hi - lo) / 2) + lo;

    // If the element is present at the middle point
    if (v.at(mid) == value)
      return mid;

    // If the element is smaller than mid element, then
    // it can only be present in left section
    if (v.at(mid) > value)
      return do_search(v, value, lo, mid - 1);

    // Else the element can only be present
    // in right section
    return do_search(v, value, mid + 1, hi);
  }

  // when element is not found
  return -1;
}
