#include"Interfaces03.h"

class VectorDoubleSort : public IVectorDoubleSort
{
public: 
	VectorDoubleSort() { }
	~VectorDoubleSort() { }
	void sort(std::vector<double>& vec);
	//void mergeSort(std::vector<double>&vec, int len);
	//void merge(std::vector<double>&left, std::vector<double>&right);
	//void quicksort(std::vector<double>&vec, int begin, int end);
	//void swap(int *a, int*b);
	//int split(std::vector<double>&vec, int begin, int end);
	std::vector<double> mergeSort(std::vector<double> m);
	std::vector<double> merge(std::vector<double> left, std::vector<double> right);
};