#include "stdio.h"
#include "iostream"


int mediana(int *arr, int lh, int size) {
	int pivot;
	
	if (arr[lh] < arr[size]) {
		if (arr[lh] > arr[(size + lh)/2]) 
			pivot = lh;
		else 
			if (arr[size] < arr[(size + lh)/2])
			pivot = size;
		else {
			pivot = (size + lh)/2;
		}
	} else 
		if (arr[size] > arr[(size + lh)/2])
			pivot = size;
	else 
		if (arr[lh] < arr[(size + lh)/2])
			pivot = lh;	
	else 
		pivot = (size + lh)/2;
	
	return pivot;
}

void bin_search(int *arr, int left, int right) {
	int mid, pivot;
	int i, j;
	
	std::swap(arr[mid], arr[right]);
	i = j = left;
	mid = mediana(arr, left, right);
	pivot = arr[mid];
	
	if (left < right) {
		while (j < right) {
			if (arr[j] < pivot) {
				if (arr[i] != arr[j])
					std::swap(arr[i], arr[j]);
				++i;
				++j;
			} else {
				++j;
			}
		}
		std::swap(arr[i], arr[j]);
	bin_search(arr, left, i);
	}
}

int main() {
	int size;
	std::cin >> size;
	int *array = new int[size];

	for (int i = 0; i < size; ++i) {
		std::cin >> array[i];
	}

	bin_search(array, 0, size - 1);

	for (int j = 0; j < size; ++j) {
		std::cout << array[j] << "";
	}

	return 0;
}