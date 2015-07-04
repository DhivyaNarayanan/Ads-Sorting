#include"HeapSort.h"

void HeapSort::sort(std::vector<int>& vector)
{
	Heapify(vector);
	for (int i = vector.size()-1; i >= 0; --i)
	{
		int tmp;
		tmp = vector[i];
		vector[i] = vector[0];
		vector[0] = tmp;
		fixDown(vector, 0, i);
	}
}
void HeapSort::Heapify(std::vector<int>& vector)
{
	for (int i = vector.size()-1; i >= 0; --i)
	{
		fixDown(vector, i, vector.size());
	}
}
void HeapSort::fixDown(std::vector<int>& vector, int k, int size)
{
	int lc = (2 * k) + 1;
	//int rc = (2 * k) + 2;
	while (lc < size)
	{
		int j = lc;
		if (lc+1 < size && vector[lc+1] > vector[lc])
			j = lc+1;
		if (vector[k] < vector[j])
		{
			int tmp;
			tmp = vector[k];
			vector[k] = vector[j];
			vector[j] = tmp;
		}
		k = j;
		lc = (2 * k) + 1;
		//rc = (2 * k) + 2;
	}
}