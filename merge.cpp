#include "stdio.h"
#include "iostream"



void merge(int *arr, int first, int last) {
	int lb, ub, mid;
	int i = 0;
	int *rez = NULL;

	mid = (last + first) / 2;
	lb = first;
	ub = mid + 1;
	rez = new int[ub - lb + 1];
	
	for (int j = first; j < last + 1; j++) {
		if ((lb <= mid) && ((ub > last) || (arr[lb] < arr[ub]))) {
			rez[i] = arr[lb];
			++lb;
		} else {
			rez[i] = arr[ub];
			++ub;
		}
		++i;
	}
	for (int n = 0; n < last - first + 1; ++n) {
		arr[first + n] = rez[n];
	}
}

void split(int *arr, int first, int last) {
	int mid = (last + first) / 2;
	
	if (first < last) {
		split(arr, first, mid);
		split(arr, mid + 1, last);
		merge(arr, first, last);
	}

}

int main() {
	unsigned int size = 0;
	int *array = NULL;

	std::cin >> size;
	array = new int[size];
	
	for(int i = 0; i < size; ++i) {
		std::cin >> array[i];
	}

	split(array, 0, size-1);

	 for (int i = 0; i < size; ++i) {
	 	std::cout << array[i] << " ";
	 }

	delete[] array;

	return 0;
}