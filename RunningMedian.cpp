#include"RunningMedian.h"
#include<iostream>

std::vector<int> RunningMedian::compute(std::vector<int> vec, int window_size)
{
	std::vector<int>output_vec;
	int k = 1;
	int j = 0;
	int t = 0;
	int tmpwindow = 1;
	while (j < vec.size())
	{
		
		std::vector<int>sub_vec;
		t = 0;
		if (tmpwindow <= window_size)
		{
			for (int i = 0; i < tmpwindow; i++)
			{

				sub_vec.push_back(vec[t]);
				t++;
			}
			j++;
		}
		else
		{
			j = k;
			int ind = 0;
			while (ind < window_size)
			{
				sub_vec.push_back(vec[j]);
				j++;
				ind++;
			}
			/*j = k;
			for (int i = k; i <= window_size; i++, j++)
			{
				
			}*/
			k++;
			
		}
		for (int l = 1; l < sub_vec.size(); l++)
		{
			int key = sub_vec[l];
			int i = l - 1;
			while (i >= 0 && sub_vec[i]>key)
			{
				sub_vec[i + 1] = sub_vec[i];
				--i;
			}
			sub_vec[i + 1] = key;
		}
		int ksize = sub_vec.size();
		int median =0;
		if (ksize > 1)
		{

			if (ksize % 2 != 0)
			{
				int mid ;

				mid = (ksize - 1) / 2;
				median = sub_vec[mid];
			}
			else
			{
				median = 0;
				int mid2 = ksize / 2;
				int mid1 = mid2 - 1;
				int sum = sub_vec[mid1] + sub_vec[mid2];
				median = sum / 2;
			}
		}
		else
			median = sub_vec[ksize - 1];
		/*int median = 0;
		int sum = 0;
		for (int p = 0; p < sub_vec.size(); p++)
		{
			sum = sum + sub_vec[p];
		}
		median = sum / ksize;*/
		output_vec.push_back(median);
		
		//k++;
		tmpwindow++;
	}
	
	return output_vec;
}
//	for (int i = 1; i <= window_size; i++)
//	{
//		int tmp_window = i;
//		int t = 0;
//		int inc = 0;
//		int nxt_index = 0;
//		while (nxt_index != vec.size())
//		{
//
//			std::vector<int>sub_vector;
//			
//			for (int j = 0; j < i; j++)
//			{
//				
//				sub_vector.push_back(vec[t]);
//				t++;
//			}
//			nxt_index = t ;
//			t = inc + 1;
//			inc++;
//			
//			//Sorting the sub_vector-insertion sort
//			for (int l = 1; l < sub_vector.size(); l++)
//			{
//				int key = sub_vector[l];
//				int i = l - 1;
//				while (i >= 0 && sub_vector[i]> key)
//				{
//					sub_vector[i + 1] = sub_vector[i];
//					--i;
//				}
//				sub_vector[i + 1] = key;
//			}
//			int ksize = sub_vector.size();
//			int mid = 1;
//			if (ksize > 1)
//			{
//				int mid = ksize / 2;
//			}
//			int median = sub_vector[mid-1];
//			if (output_vec.size() == 0)
//			{
//				output_vec.push_back(median);
//				std::cout << "\nMedian : " << median;
//			}
//			//int opsize = output_vec.size();
//			else if (output_vec[output_vec.size() - 1] != median)
//			{
//				output_vec.push_back(median);
//				std::cout << "\nMedian : " << median;
//			}
//				
//		}
//			
//		std::cout << "size of output vector : " << output_vec.size() << "\n";
//	}
//	return output_vec;
//}