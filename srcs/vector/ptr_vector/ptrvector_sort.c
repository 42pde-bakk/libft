//
// Created by Peer de Bakker on 7/27/22.
//

#include "vector.h"

typedef int idx_t;

static t_ptrvector_sort_function g_compare_function;

static void swap(void** array, const idx_t i, const idx_t j) {
	void* tmp = array[i];

	array[i] = array[j];
	array[j] = tmp;
}

static bool shouldSwap(const void* dataObject, const void* pivot) {
	return (g_compare_function(dataObject, pivot) < 0);
}

static idx_t partition(void** dataObjects, const idx_t low, const idx_t high) {
	void* pivot = dataObjects[high];
	idx_t i = low - 1; // Index of smaller element and indicates the right position of pivot found so far

	for (idx_t j = low; j <= high - 1; j++) {
		// if current element is smaller than the pivot
		if (shouldSwap(dataObjects[j], pivot)) {
			++i;
			swap(dataObjects, i, j);
		}
	}
	swap(dataObjects, i + 1, high);
	return (i + 1);
}

void quickSort(void** dataObjects, idx_t low, idx_t high) {
	if (low < high) {
		idx_t partitionIndex = partition(dataObjects, low, high);

		quickSort(dataObjects, low, partitionIndex - 1);
		quickSort(dataObjects, partitionIndex + 1, high);
	}
}

void	ptrvector_sort(t_ptrvector *vec, const t_ptrvector_sort_function compare_func) {
	g_compare_function = compare_func;
	quickSort(vec->arr, 0, (idx_t)(vec->size - 1));
}
