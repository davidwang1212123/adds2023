#include <iostream>
#include <vector>
#include "QuickSort.h"

std::vector<int> QuickSort::sort(std::vector<int> list)
{
	if (list.size() > 1)
		do_quick_sort(list, 0, int(list.size() - 1));

  return list;
}

void QuickSort::do_quick_sort(std::vector<int>& v, int lo, int hi)
{
	if ((lo >= 0) && (hi >= 0) && (lo < hi))
	{
		if ((hi - lo) == 1) // only two elements
		{
			if (v.at(lo) > v.at(hi))
				std::swap(v[lo], v[hi]);

			return;
		}

		// more than two elements
		int p = partition(v, lo, hi);
		do_quick_sort(v, lo, p - 1);
		do_quick_sort(v, p, hi);
	}
}

int QuickSort::partition(std::vector<int>& v, int lo, int hi)
{
	int pivot = v[lo + 2]; // element three is the pivot
	int i = lo - 1; // left index
	int j = hi + 1; // right index

	while (true)
	{
		// Move the left index to the right at least once and while the element at
		// the left index is less than the pivot
		do
		{
			i++;
		} while (v[i] < pivot);

		// Move the right index to the left at least once and while the element at
		// the right index is greater than the pivot
		do
		{
			j--;
		} while (v[j] > pivot);

		// if the indices crossed, return
		if (i >= j)
			return i;

		// swap the elements at the left and right indices
		std::swap(v[i], v[j]);
	}
}

void QuickSort::do_quick_sort_lomuto(std::vector<int>& v, int lo, int hi)
{
	if ((lo >= 0) && (lo < hi))
	{
		int p = partition_lomuto(v, lo, hi);
		do_quick_sort_lomuto(v, lo, p - 1);
		do_quick_sort_lomuto(v, p + 1, hi);
	}
}

// last element is taken as pivot
int QuickSort::partition_lomuto(std::vector<int>& v, int lo, int hi)
{
	int pivot = v[hi];
	int p = lo - 1;

	for (int i = lo; i < hi; i++)
	{
		if (v[i] < pivot)
		{
			p++;
			std::swap(v[i], v[p]);
		}
	}

	p++;
	std::swap(v[p], v[hi]);

	return p;
}

void QuickSort::do_quick_sort_hoare(std::vector<int>& v, int lo, int hi)
{
	if ((lo >= 0) && (hi >= 0) && (lo < hi))
	{
		int p = partition_hoare(v, lo, hi);
		do_quick_sort_hoare(v, lo, p); // the pivot is included
		do_quick_sort_hoare(v, p + 1, hi);
	}
}

// middle of the vector is taken as pivot
int QuickSort::partition_hoare(std::vector<int>& v, int lo, int hi)  
{
	int pivot = v[int(floor((hi - lo) / 2)) + lo]; // middle of the vector
	int i = lo - 1; // left index
	int j = hi + 1; // right index

	while (true)
	{
		// Move the left index to the right at least once and while the element at
		// the left index is less than the pivot
		do
		{
			i++;
		} while (v[i] < pivot);

		// Move the right index to the left at least once and while the element at
		// the right index is greater than the pivot
		do
		{
			j--;
		} while (v[j] > pivot);

		// if the indices crossed, return
		if (i >= j)
			return j;

		// swap the elements at the left and right indices
		std::swap(v[i], v[j]);
	}
}
