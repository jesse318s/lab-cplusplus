#include "Heap.h"
#include <algorithm>

void Heap::heapify(int index) {
	int leftChild = left(index);
	int rightChild = right(index);
	int extremeIndex = index;

	if (isMaxHeap) {
		if (leftChild < size() && data[leftChild] > data[extremeIndex])
			extremeIndex = leftChild;

		if (rightChild < size() && data[rightChild] > data[extremeIndex])
			extremeIndex = rightChild;
	}
	else {
		if (leftChild < size() && data[leftChild] < data[extremeIndex])
			extremeIndex = leftChild;

		if (rightChild < size() && data[rightChild] < data[extremeIndex])
			extremeIndex = rightChild;
	}

	if (extremeIndex != index) {
		swap(index, extremeIndex);
		heapify(extremeIndex);
	}
}

void Heap::swap(int i, int j) { std::swap(data[i], data[j]); }

int Heap::parent(int index) { return (index - 1) / 2; }

int Heap::left(int index) { return (2 * index + 1); }

int Heap::right(int index) { return (2 * index + 2); }

Heap::Heap(bool isMax) : isMaxHeap(isMax), data() {}

void Heap::insert(int value) {
	data.push_back(value);

	int current = data.size() - 1;

	while (current != 0 && (isMaxHeap ? data[current] > data[parent(current)] : data[current] < data[parent(current)])) {
		swap(current, parent(current));
		current = parent(current);
	}
}

int Heap::extract() {
	if (data.empty()) throw std::out_of_range("Heap is empty");

	int top = data.front();

	data[0] = data.back();
	data.pop_back();

	if (!data.empty()) heapify(0);

	return top;
}

int Heap::peek() const {
	if (data.empty()) throw std::out_of_range("Heap is empty");

	return data.front();
}

int Heap::size() const { return data.size(); }

bool Heap::is_empty() const { return data.empty(); }
