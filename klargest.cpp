#ifndef KLARGEST_H
#define KLARGEST_H

#include <vector>
#include <cmath>

int kth_largest(std::vector<int> values, int k)
{
  // validate parameters
  if ((values.size() == 0) || (k <= 0) or (k > values.size())) return -888;

  // establish MaxHeap
  std::vector<int> heapValues;
  int curr_index = 0;
  int parent_index = 0;
  int temp_value;

  for (int i = 0; i < values.size(); i++)
  {
    heapValues.push_back(values.at(i));

    // when heap has two or more members, compare with parent value
    // swap if parent value is larger
    if (heapValues.size() > 1)
    {
      curr_index = heapValues.size() - 1;
      parent_index = floor((curr_index - 1) / 2);

      while (parent_index >= 0)
      {
        if (heapValues.at(curr_index) > heapValues.at(parent_index))
        {
          temp_value = heapValues.at(parent_index);
          heapValues.at(parent_index) = heapValues.at(curr_index);
          heapValues.at(curr_index) = temp_value;

          curr_index = parent_index;
          if (curr_index == 0)
            break;
          else
            parent_index = floor((curr_index - 1) / 2);
        }
        else
          break;
      }
    }
  }

  // if k > 1, then pop k - 1 times, adjust k - 1 times
  if (k > 1)
  {
    int last_member_value;
    int left_child_index;
    int right_child_index;
    int largest_index;

    for (int i = 0; i < k - 1; i++)
    {
      // replace the deleted node with the last node
      last_member_value = heapValues.back();
      heapValues[0] = last_member_value;
      heapValues.pop_back();

      // no need to compare parent given the current node is the front node
      // only compare children until both children are smaller or no children
      curr_index = 0;
      left_child_index = 2 * curr_index + 1;
      right_child_index = 2 * curr_index + 2;

      while ((left_child_index < heapValues.size()) || (right_child_index < heapValues.size()))
      {
        // if parent is smaller than child, swap with larger child
        largest_index = curr_index;

        // check if left child exists and if exists, is larger value there
        if (left_child_index < heapValues.size() &&
          heapValues.at(left_child_index) > heapValues.at(largest_index)) {
          // make this index the current largest
          largest_index = left_child_index;
        }

        // check if left child exists and if exists, is larger value there
        if (right_child_index < heapValues.size() &&
          heapValues.at(right_child_index) > heapValues.at(largest_index)) {
          // make this index the current largest
          largest_index = right_child_index;
        }

        // if parent is not larger, swap with larger child
        if (largest_index != curr_index) {
          temp_value = heapValues.at(curr_index);
          heapValues.at(curr_index) = heapValues.at(largest_index);
          heapValues.at(largest_index) = temp_value;

          // adjust parent and its child indexes
          curr_index = largest_index;
          left_child_index = 2 * curr_index + 1;
          right_child_index = 2 * curr_index + 2;
        }
        else
          break;
      }
    }
  }

  return heapValues.front();
}

#endif

