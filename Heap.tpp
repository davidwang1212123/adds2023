#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <cmath>  // for floor

template <typename T>
class Heap {
 private:
  std::vector<T> values;
  void heapify(int);

 public:
  Heap();  // constructs an empty heap

  // constructs a heap with the values from the given vector
  // the type T MUST provide comparison operators <, >, ==
  Heap(std::vector<T>);

  void insert(T);
  void remove(T);
  T getMin();
  //std::vector<T> getHeapifiedValues() {
  //  return values;
  //}
};

/*******************************/
// default constructor
/*******************************/

template <typename T>
Heap<T>::Heap() {}

/*******************************/
// constructs a heap with the values in the given vector
// the type T MUST provide comparison operators <, >, ==
/*******************************/

template <typename T>
Heap<T>::Heap(std::vector<T> start_values) {
  // copy the values into our heap vector
  for (int i = 0; i < start_values.size(); i++) {
    values.push_back(start_values.at(i));
  }

  // starting from last non-leaf node (last parent), heapify each
  // of the parents
  int initial_parent_index = floor(values.size() / 2) - 1;
  for (int parent_index = initial_parent_index; parent_index >= 0;
       parent_index--) {
    heapify(parent_index);
  }
}

/*******************************/
// add values to the heap
/*******************************/

template <typename T>
void Heap<T>::insert(T value) {
  // TODO: TO BE IMPLEMENTED

  // insert at the bottom of the vector
  values.push_back(value);

  // when heap has two or more members, compare with parent value
  // swap if parent value is larger
  if(values.size() > 1)
  {
    int curr_index = values.size() - 1;
    int parent_index = floor((curr_index - 1) / 2);
    T temp_value;

    while(parent_index >= 0)
    {
      if (values.at(curr_index) < values.at(parent_index))
      {
        temp_value = values.at(parent_index);
        values.at(parent_index) = values.at(curr_index);
        values.at(curr_index) = temp_value;

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

/*******************************/
/* delete values from the heap */
/*******************************/

template <typename T>
void Heap<T>::remove(T value) {
  // TODO: TO BE IMPLEMENTED

  // vector is empty
  if (values.size() == 0) return;

  int value_index = -1;

  for(int i = 0; i < values.size(); i++)
  {
    if (values.at(i) == value)
    {
      value_index = i;
      break;
    }
  }

  // value is not found in the vector
  if (value_index == -1) return;

  // value is found, but it is the last element
  if (value_index == values.size() - 1)
  {
    values.pop_back();
    return;
  }

  // replace the deleted node with the last node
  T last_member_value = values.at(values.size() - 1);
  values[value_index] = last_member_value;
  values.pop_back();

  int curr_index = value_index;
  T temp_value;

  // check immediate parent
  int parent_index = floor((curr_index - 1) / 2);
  if ((parent_index >= 0) && values.at(curr_index) < values.at(parent_index))
  {
    // compare parent until parent value is smaller
    while(parent_index >= 0)
    {
      if (values.at(curr_index) < values.at(parent_index))
      {
        temp_value = values.at(parent_index);
        values.at(parent_index) = values.at(curr_index);
        values.at(curr_index) = temp_value;

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
  else
  {
    // compare children until both children are larger or no children
    int left_child_index = 2 * curr_index + 1;
    int right_child_index = 2 * curr_index + 2;

    while((left_child_index < values.size()) || (right_child_index < values.size()))
    {
      // if parent is larger than child, swap with smallest child
      int smallest_index = curr_index;

      // check if left child exists and if exists, is smallest value there
      if (left_child_index < values.size() &&
          values.at(left_child_index) < values.at(smallest_index)) {
        // make this index the current smallest
        smallest_index = left_child_index;
      }

      // check if left child exists and if exists, is smallest value there
      if (right_child_index < values.size() &&
          values.at(right_child_index) < values.at(smallest_index)) {
        // make this index the current smallest
        smallest_index = right_child_index;
      }

      // if parent is not smallest, swap with smallest child
      if (smallest_index != curr_index) {
        temp_value = values.at(curr_index);
        values.at(curr_index) = values.at(smallest_index);
        values.at(smallest_index) = temp_value;

        // adjust parent and its child indexes
        curr_index = smallest_index;
        left_child_index = 2 * curr_index + 1;
        right_child_index = 2 * curr_index + 2;
      }
      else
        break;
    }
  }
}

/*******************************/
// find the smallest value in the heap
/*******************************/

template <typename T>
T Heap<T>::getMin() {
  // TODO: TO BE IMPLEMENTED
  return values.at(0);
}

/*******************************/
// private function to heapify a given 'node'
/*******************************/

template <typename T>
void Heap<T>::heapify(int parent_index) {
  // if we're outside the index range, return
  if (parent_index < 0 || parent_index >= values.size()) return;

  // find children indexes
  int left_child_index = parent_index * 2 + 1;
  int right_child_index = parent_index * 2 + 2;

  // if parent is larger than child, swap with smallest child
  int index_of_smallest = parent_index;

  // check if left child exists and if exists, is smallest value there
  if (left_child_index < values.size() &&
      values.at(left_child_index) < values.at(index_of_smallest)) {
    // make this index the current smallest
    index_of_smallest = left_child_index;
  }

  // check if left child exists and if exists, is smallest value there
  if (right_child_index < values.size() &&
      values.at(right_child_index) < values.at(index_of_smallest)) {
    // make this index the current smallest
    index_of_smallest = right_child_index;
  }

  // if parent is not smallest, swap with smallest child
  if (index_of_smallest != parent_index) {
    T temp = values.at(parent_index);
    values.at(parent_index) = values.at(index_of_smallest);
    values.at(index_of_smallest) = temp;
  }

  // move up the 'tree' to grandparent
  heapify(floor(parent_index / 2) - 1);
}

#endif