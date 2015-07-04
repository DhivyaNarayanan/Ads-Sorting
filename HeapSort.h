#include"Interfaces03.h"

class HeapSort : public IHeapSort
{
public:
	HeapSort() {}
    ~HeapSort() {}
	void sort(std::vector<int>& vector);
	void Heapify(std::vector<int>& vector);
	void fixDown(std::vector<int>& vector, int k, int size);
};