#include"VectorDoubleSort.h"



void VectorDoubleSort::sort(std::vector<double>& vec)
{
	std::vector<double>tmp_vec;
	tmp_vec = mergeSort(vec);
	for (int i = 0; i < vec.size(); i++)
	{
		vec[i] = tmp_vec[i];
	}
	/*for (int j = 1; j < vec.size(); j++)
	{
		int key = vec[j];
		int i = j - 1;
		while (i >= 0 && vec[i]> key)
		{
			vec[i + 1] = vec[i];
			--i;
		}
		vec[i + 1] = key;
	}*/
	
	//quicksort(vec, 0, vec.size() - 1);
}

std::vector<double> VectorDoubleSort:: mergeSort(std::vector<double> m)
{
	if (m.size() <= 1)
		return m;

	std::vector<double> left, right, result;
	int middle = ((int)m.size() + 1) / 2;

	for (int i = 0; i < middle; i++) {
		left.push_back(m[i]);
	}

	for (int i = middle; i < (int)m.size(); i++) {
		right.push_back(m[i]);
	}

	left = mergeSort(left);
	right = mergeSort(right);
	result = merge(left, right);

	return result;
}

std::vector<double> VectorDoubleSort::merge(std::vector<double> left,std::vector<double> right)
{
	std::vector<double> result;
	while ((int)left.size() > 0 || (int)right.size() > 0) {
		if ((int)left.size() > 0 && (int)right.size() > 0) {
			if ((double)left.front() <= (double)right.front()) {
				result.push_back((double)left.front());
				left.erase(left.begin());
			}
			else {
				result.push_back((double)right.front());
				right.erase(right.begin());
			}
		}
		else if ((int)left.size() > 0) {
			for (int i = 0; i < (int)left.size(); i++)
				result.push_back(left[i]);
			break;
		}
		else if ((int)right.size() > 0) {
			for (int i = 0; i < (int)right.size(); i++)
				result.push_back(right[i]);
			break;
		}
	}
	return result;
}
//void VectorDoubleSort::quicksort(std::vector<double>&vec, int low, int high)
//{
//	/*if (begin < end)
//	{
//		int p = split(vec, begin, end);
//		quicksort(vec, begin, p - 1);
//		quicksort(vec, p + 1, end);
//	}*/
//	double key;
//	int i, j, flag = 1;
//	if (low < high)
//	{
//		key = vec[low];
//		i = low + 1;
//		j = high;
//		while (flag)
//		{
//			while ((vec[i] <= key) && (i < j))
//				i++;
//			while (vec[j]>key)
//				j--;
//			if (i < j)
//			{
//				double temp = vec[i];
//				vec[i] = vec[j];
//				vec[j] = temp;
//			}
//			else
//				flag = 0;
//		}
//		double temp1 = vec[low];
//		vec[low] = vec[j];
//		vec[j] = temp1;
//		quicksort(vec, low, j - 1);
//		quicksort(vec, j + 1, high);
//	}
//}
//
///*void VectorDoubleSort::swap(int a, int b)
//{
//	int tmp = *a;
//	*a = *b;
//	*b = tmp;
//}*/
//int VectorDoubleSort::split(std::vector<double>&vec, int begin, int end)
//{
//	int i, p, q, t;
//	p = begin + 1;
//	q = end;
//	i = vec[begin];
//	while (q >= p)
//	{
//		while (vec[p]<  i)
//			p++;
//		while (vec[q]>i)
//			q--;
//		if (q > p)
//		{
//			t = vec[p];
//			vec[p] = vec[q];
//			vec[q] = t;
//		}
//	}
//	t = vec[begin];
//	vec[begin] = vec[q];
//	vec[q] = t;
//	return q;
//	/*int pivot = vec[end];
//	int i = begin - 1;
//	for (int j = begin; j <= end - 1; j++)
//	{
//		if (vec[j] <= pivot)
//		{
//			i++;
//			//swap(&vec[i], &vec[j]);
//			double tmp = vec[i];
//			vec[i] = vec[j];
//			vec[j] = tmp;
//		}
//	}
//	double tmp1 = vec[i + 1];
//	vec[i + 1] = vec[end];
//	vec[end] = tmp1;
//	return (i + 1);*/
