#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <stdexcept>

class Heap {
private:
    std::vector<int> data;
    bool isMaxHeap;

    void heapify(int index);
    void swap(int i, int j);
    int parent(int index);
    int left(int index);
    int right(int index);

public:
    Heap(bool isMax = true);

    void insert(int value);
    int extract();
    int peek() const;
    int size() const;
    bool is_empty() const;
};

#endif
