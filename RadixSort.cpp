#include"RadixSort.h"
//#include<queue>
#include"queue.h"
#include<string>
#include<iostream>

void RadixSort::sort(std::vector<std::string> & data)
{
	const int radix = 26;
	//const int letters = 20;
	//std::queue<std::string>queues[radix+1];
	//std::vector<std::string> queue_vec[radix + 1];
	/*for (int i = 0; i < radix + 1; i++)
	{
		queue_vec[i] = new std::vector<std::string>[];

	}*/
	queue queue_vec[radix + 1];
	//queue[radix + 1] = new queue();
	int max = 0;
	for (int j = 0; j < data.size(); j++)
	{
		int i = data[j].size();
		if (i>max)
			max = i;
	}

	std::cout << "max no_of characters in string: " << max << "\n";

	for (int i = 0; i <=max-1; i++)
	{
		for (int j = 0; j < data.size(); ++j)
		{
			//if (data[j][i] == '\0')
				//queue_vec[radix].push(data[j]);
		//	else
				queue_vec[data[j][i] % 97].push(data[j]);
			

		}
						
       	int k = 0;

		if (!queue_vec[radix].empty())
		{

			for (int t = 0; t < queue_vec[radix].size(); t++)
			{

				data[k] = queue_vec[radix].ret_front();
				++k;
			}
			while (!queue_vec[radix].empty())
				queue_vec[radix].pop();

		}
		for (int j = 0; j < radix; ++j)
		{

			for (int t = 0; t < queue_vec[j].size(); t++)
			{

				data[k] = queue_vec[j].ret_front();

				++k;
			}
			while (!queue_vec[j].empty())
				queue_vec[j].pop();

		}
	}

}
//










































































