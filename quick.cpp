#include "stdio.h"
#include "iostream"

int mediana(int *arr, int lh, int size) {
	int pivot;
	
	if (arr[lh] < arr[size]) {
		if (arr[lh] > arr[(size + lh) / 2]) 
			pivot = lh;
		else 
			if (arr[size] < arr[(size + lh) / 2])
			pivot = size;
		else {
			pivot = (size + lh) / 2;
		}
	} else 
		if (arr[size] > arr[(size + lh) / 2])
			pivot = size;
	else 
		if (arr[lh] < arr[(size + lh) / 2])
			pivot = lh;	
	else 
		pivot = (size + lh) / 2;
	
	return pivot;
}

void quick_sort(int *arr, int lh, int rh) {
	int pivot = mediana(arr, lh, rh);
	int value_pivot = arr[pivot];
	int r = rh;
	int l = lh;

	while (l < r) {
		while (arr[l] < value_pivot) {
			++l;
		}
		while (arr[r] > value_pivot) {
			--r;
		}
		 if (l < r)
			std::swap(arr[l], arr[r]);
		
	}
	if (r > lh) 
		quick_sort(arr, lh, r);
	if (l < rh)
		quick_sort(arr, r + 1, rh);
	
}

int main() {
	int size = 0;
	int index_pivot;
	int lh = 0, rh;
	int pivot;
	int *array = NULL;

	std::cin >> size;
	
	rh = size - 1;
	array = new int[size];
	
	for (int i = 0; i < size; ++i) {
		std::cin >> array[i];
	}

	quick_sort(array, lh, rh);


	for(int i = 0; i < size; ++i) {
		std::cout << array[i] << " ";
	}

	delete[] array;
	
	return 0;
}