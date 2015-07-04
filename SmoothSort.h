#include"Interfaces03.h"

class SmoothSort : public ISmoothSort
{
	struct heap
	{
		double data;
		heap*lc;
		heap*rc;
		int treesize;
		
	};
	//heap*root;
	int num_trees;
	int heapsize;
	std::vector<heap*>vec_tree;
	std::vector<long>leo_vec;
	std::vector<double>heap_vec;

public:
	
	SmoothSort() 
	{
		for (int i = 0; i < 46; i++)
		{
			if (i == 0 || i == 1)
				leo_vec.push_back(1);
			else
				leo_vec.push_back(leo_vec[i - 2] + leo_vec[i - 1] + 1);
		}
		//root->visit = false;
	}
	~SmoothSort() { }
	void buildHeap(std::vector<double>& vec);
	void sort(std::vector<double>& vec);
	void fixDown(heap*root);
	void insertintovec();
	
};