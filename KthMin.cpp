#include"KthMin.h"
#include"DoubleList03.h"
#include"DoubleNode03.h"
#include<iostream>

int KthMin::findKthMin(IDoubleList03 * data, int k)
{
	int cur_val;
	IDoubleNode03 * t_head = data->getHead();
	IDoubleNode03 * t_tail = data->getTail();
	int index = 0;
	IDoubleNode03 * ptr1 = t_head;
	IDoubleNode03 *ptr2;
	
	while (index <= k)
	{
		ptr2 = ptr1->getNext();
		while (ptr2 != NULL)
		{
			//IDoubleNode03 * min_ptr = NULL;
			//int min_val;
			int pval_1 = ptr1->getValue();
			int pval_2 = ptr2->getValue();
			if (pval_1 < pval_2)
			{
				//min_val = pval_1;
				//min_ptr = ptr1;
			}
			else if (pval_2 < pval_1)
			{
				//min_val = pval_2;
				//min_ptr = ptr2;
				/*exchange(ptr1, ptr2);
				IDoubleNode03 * tmp = ptr1;
				ptr1 = ptr2;
				ptr2 = tmp;*/
				if (ptr1->getNext() == ptr2)
				{

					IDoubleNode03 * tnext2 = ptr2->getNext();
					IDoubleNode03 * tprev1 = ptr1->getPrev();
					ptr1->setNext(tnext2);
					if (tnext2 != NULL)
						tnext2->setPrev(ptr1);
					ptr2->setPrev(tprev1);
					if (tprev1 != NULL)
						tprev1->setNext(ptr2);
					ptr1->setPrev(ptr2);
					ptr2->setNext(ptr1);
					ptr1 = ptr2;
					ptr2 = ptr1->getNext();
					if (t_head == ptr2)
					{

						data->setHead(ptr1);
						t_head = ptr1;
					}
				}
				else
				{
					IDoubleNode03 * tnext1 = ptr1->getNext();
					IDoubleNode03 * tnext2 = ptr2->getNext();
					IDoubleNode03 * tprev1 = ptr1->getPrev();
					IDoubleNode03 * tprev2 = ptr2->getPrev();

					ptr1->setNext(tnext2);
					ptr1->setPrev(tprev2);
					if (tnext2!= NULL)
						tnext2->setPrev(ptr1);
					tprev2->setNext(ptr1);

					ptr2->setNext(tnext1);
					ptr2->setPrev(tprev1);
					if (tnext1 != NULL)
						tnext1->setPrev(ptr2);
					if (tprev1 != NULL)
						tprev1->setNext(ptr2);
					IDoubleNode03 * tmp = ptr1;
					ptr1 = ptr2;
					ptr2 = tmp;
				}
			}
			ptr2 = ptr2->getNext();
		}
		 cur_val = ptr1->getValue();
		ptr1 = ptr1->getNext();
		index++;
	}
	return cur_val;
}



	

	/*int pval_1 = p1->getValue();
	int pval_2 = p2->getValue();
	p1->setValue(pval_2);
	p2->setValue(pval_1);*/
	
