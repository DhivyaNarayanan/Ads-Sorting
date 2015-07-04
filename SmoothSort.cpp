#include"SmoothSort.h"
#include<iostream>
void SmoothSort::buildHeap(std::vector<double>& vec)
{
	std::cout << "Before build heap: \n";
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << "\t";
	}
	
	heapsize = 0;
	int i = 0;
	while (i < vec.size())
	{
		if (vec_tree.size() == 0)
		{
			heap * root = new heap();
			root->data = vec[i];
			root->lc = NULL;
			root->rc = NULL;
			
			root->treesize = 1;
			heapsize = 1;
			vec_tree.push_back(root);
			std::cout << "first insertion::\n" << vec_tree[vec_tree.size() - 1]->data;
		}
		else
		{
			heap*prevtree = vec_tree[vec_tree.size() - 1];
			double prevrootdata = prevtree->data;
			std::cout << "\nprevtree->data...." << prevtree->data;
			if (vec_tree.size() ==1)
			{
				int prevtreesize = prevtree->treesize;
				heap * root = new heap();
				root->data = vec[i];
				root->lc = NULL;
				root->rc = NULL;
				
				root->treesize = 1;
				vec_tree.push_back(root);
				std::cout << "\nInsertion 1:: before fixdown...\n";
				for (int i = 0; i<vec_tree.size(); i++)
					std::cout << vec_tree[i]->data << "\t";
				std::cout << "\n Before swapping..";
				std::cout << "\ntmpdata..." << root->data;
				std::cout << "\nprevtreedata..." << prevtree->data;
			
				
				if (prevrootdata>vec[i])
				{
					double tmpdata = root->data;
					root->data = prevrootdata;
					prevtree->data = tmpdata;
					std::cout << "\n after swapping..";
					std::cout << "\ntmpdata..." << root->data;
					std::cout << "\nprevtreedata..." << prevtree->data;
					fixDown(prevtree);
					std::cout << "\nInsertion1 :: after fixdown...\n";
					for (int i = 0; i<vec_tree.size(); i++)
						std::cout << vec_tree[i]->data << "\t";
	
				}
			}
			else
			{
				heap*lasttree = vec_tree[vec_tree.size() - 1];
				heap*prevlasttree = vec_tree[vec_tree.size() - 2];
				int lasttreesize = lasttree->treesize;
				int prevtreesize = prevlasttree->treesize;
				if ((prevtreesize - lasttreesize) % 2 == 0) //consecutive leonardo size
				{
					heap * root = new heap();
					root->data = vec[i];
					root->lc = prevlasttree;
					root->rc = lasttree;
					
					root->treesize = prevtreesize + lasttreesize + 1;
					vec_tree.pop_back();
					vec_tree.pop_back();
					vec_tree.push_back(root);
					std::cout << "\nInsertion 2 :: before fixdown...\n";
					for (int i = 0; i<vec_tree.size(); i++)
						std::cout << vec_tree[i]->data << "\t";
					fixDown(root);
					for (int j = vec_tree.size() - 2; j >= 0; j--)
					{
						int prevrootdata = vec_tree[j]->data;
						int currootdata = vec_tree[j + 1]->data;
						if (prevrootdata > currootdata)
						{
							heap*prevroot = vec_tree[j];
							heap*curroot = vec_tree[j + 1];
							double tmpdata = vec_tree[j + 1]->data;
							curroot->data = prevroot->data;
							prevroot->data = tmpdata;
							std::cout << "\nInsertion 3:: before fixdown...\n";
							for (int i = 0; i<vec_tree.size(); i++)
								std::cout << vec_tree[i]->data << "\t";
							//fixDown(curroot);
							//fixDown(prevroot);
							std::cout << "\nInsertion 3:: after fixdown...\n";
							for (int i = 0; i<vec_tree.size(); i++)
								std::cout << vec_tree[i]->data << "\t";
						}
						
					}
					for (int j = vec_tree.size() - 1; j >= 0; j--)
					{
						heap * cur = vec_tree[j];
						fixDown(cur);
					}
					
					std::cout << "\nInsertion 2:: after fixdown...\n";
					for (int i = 0; i<vec_tree.size(); i++)
						std::cout << vec_tree[i]->data << "\t";
					heapsize++;
				}
				else
				{
					heap * root = new heap();
					root->data = vec[i];
					root->lc = NULL;
					root->rc = NULL;
					
					root->treesize = 1;
					vec_tree.push_back(root);
					int currootdata;
					for (int j = vec_tree.size() - 2; j >= 0; j--)
					{
						int prevrootdata = vec_tree[j]->data;
						currootdata = vec_tree[j + 1]->data;
						if (prevrootdata > currootdata)
						{
							heap*prevroot = vec_tree[j];
							heap*curroot = vec_tree[j + 1];
							double tmpdata = vec_tree[j + 1]->data;
							curroot->data = prevroot->data;
							prevroot->data = tmpdata;
							std::cout << "\nInsertion 3:: before fixdown...\n";
							for (int i = 0; i<vec_tree.size(); i++)
								std::cout << vec_tree[i]->data << "\t";
							//fixDown(curroot);
							//fixDown(prevroot);
							std::cout << "\nInsertion 3:: after fixdown...\n";
							for (int i = 0; i<vec_tree.size(); i++)
								std::cout << vec_tree[i]->data << "\t";
						}
					}
					for (int j = vec_tree.size() - 1; j >= 0; j--)
					{
						heap * cur = vec_tree[j];
						fixDown(cur);
					}
					heapsize++;
				}
			}
		}
		i++;
	}
	/*int j = 0;
	while (j < vec_tree.size())
	{
		heap*node = vec_tree[j];*/
	std::cout << "heap_vec  -- size :: " << heap_vec.size() << "\t";
		insertintovec();
	/*}*/
	for (int l = 0,m=heap_vec.size()-1; l < vec.size(),m>=0; l++,m--)
	{
		vec[l] = heap_vec[m];
	}
	std::cout << "\nAfter build heap : \n";
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << "\t";
	}
	/*heap * tmpnode = vec_tree[vec_tree.size() - 1];
	int k = vec.size() - 1;
	int j = vec_tree.size() - 1;
	while (j >= 0)
	{
		double tdata = tmpnode->data;
		vec[k] = tdata;
		k--;
		if (tmpnode->rc != NULL)
		{
			tmpnode = tmpnode->rc;
		}
	}*/
}
void SmoothSort::insertintovec()
{
	//if (node->lc == NULL&&node->rc == NULL)
	//{
	//	heap_vec.push_back(node->data);
	//	return;
	//}
	//insertintovec(node->lc);
	//insertintovec(node->rc);
	////heap_vec.push_back(node->data);
	std::cout << "vec_tree -> root ->data :: ";
	for (int i = 0; i < vec_tree.size(); i++)
	{
		std::cout << vec_tree[i]->data << "\t";
	}
	int j = vec_tree.size()-1;
	while (j >= 0)
	{
		heap * rnode = vec_tree[j];
		heap_vec.push_back(rnode->data);
		if (rnode->lc == NULL && rnode->rc == NULL)
		{
			//heap_vec.push_back(rnode->data);
			vec_tree.pop_back();
		}
		else
		{
			heap*rightnode = rnode->rc;
			heap*leftnode = rnode->lc;
			//heap_vec.push_back(rnode->data);
			vec_tree.pop_back();
			vec_tree.push_back(leftnode);
			vec_tree.push_back(rightnode);
			//vec_tree.push_back(leftnode);
		}

		j = vec_tree.size() - 1;
	}

}
	
	/*int k = vec.size() - 1;
	int j = vec_tree.size() - 1;
	while (j >= 0)
	{
		heap*rootnode = vec_tree[j];
		heap*rightnode = rootnode->rc;
		heap*leftnode = rootnode->lc;
		node = rootnode;
		if (node->visit == false)
		{
			double nodedata = node->data;
			vec[k] = nodedata;
			k--;
			node->visit = true;
		}
		while (node->rc != NULL)
		{
			rightnode = node->rc;
			if (rightnode->visit == false)
			{
				double nodedata = rightnode->data;
				vec[k] = nodedata;
				k--;
				rightnode->visit = true;

			}
			
		    node = rightnode;
		}
		node = node->pt;
		while (node->lc != NULL)
		{
			leftnode = node->lc;
			if (leftnode->visit == false)
			{
				double nodedata = leftnode->data;
				vec[k] = nodedata;
				k--;
				leftnode->visit = true;
			}
			node = leftnode;
		}
		node = node->pt;
		j--;
	}*/

void SmoothSort::fixDown(heap*root)
{
	if (root->rc == NULL || root->lc == NULL)
		return;
	heap*left = root->lc;
	heap*right = root->rc;
	double rootdata = root->data;
	double leftdata = left->data;
	double rightdata = right->data;
	if (leftdata > rightdata)
	{
		if (leftdata > rootdata)
		{
			double tmp = rootdata;
			root->data = leftdata;
			left->data = tmp;
			fixDown(left);
		}
	}
	else if (rightdata > rootdata)
	{
		double tmp = rootdata;
		root->data = rightdata;
		right->data = tmp;
		fixDown(right);
	}
	//int lc = (2 * k) + 1;
	////int rc = (2 * k) + 2;
	//while (lc < size)
	//{
	//	int j = lc;
	//	if (lc + 1 < size && vector[lc + 1] > vector[lc])
	//		j = lc + 1;
	//	if (vector[k] < vector[j])
	//	{
	//		int tmp;
	//		tmp = vector[k];
	//		vector[k] = vector[j];
	//		vector[j] = tmp;
	//	}
	//	k = j;
	//	lc = (2 * k) + 1;
	//	//rc = (2 * k) + 2;
	//}
}
void SmoothSort::sort(std::vector<double>& vec)
{
	int back = vec.size() - 1;
	int heapsize = vec.size();
	while (heapsize > 0)
	{
		int max = back;
		for (int i = heapsize - 1; i >= 0; i--)
		{
			if (vec[max] < vec[i])
				max = i;
		}
		double tmp = vec[back];
		vec[back] = vec[max];
		vec[max] = tmp;
		back = back - 1;
		heapsize--;
	}
	
}

