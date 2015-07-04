#include"MergeSort.h"
#include"CircularList.h"
#include<iostream>

void MergeSort::mergeSort(ICircularList * input)
{
	std::cout << "Entering main sort...\n";
	ISingleNode03 * head = input->getTail()->getNext();
	ISingleNode03 *tail = input->getTail();
	tail->setNext(NULL);
	ISingleNode03* sortedhead = sort(head);
	ISingleNode03*temp = sortedhead;
	while (temp->getNext() != NULL)
	{
		temp = temp->getNext();
	}
	temp->setNext(sortedhead);

	input->setTail(temp);

	
}
ISingleNode03 * MergeSort::sort(ISingleNode03 * thead1)
{
	std::cout << "Enters sub-sort..\n";
	ISingleNode03 * slist;
	ISingleNode03 * head = thead1;
	//ISingleNode03 *tail = ttail;
	//tail->setNext(NULL);
	ISingleNode03* a = NULL;
	ISingleNode03 *b = NULL;
	if (head == NULL||head->getNext()==NULL)
	{
		std::cout << head->getValue();
		return head;
	}
	SplitList(head, &a, &b);
	ISingleNode03 *head1 = sort(a);
	ISingleNode03 *head2 = sort(b);
	slist = merge(head1, head2);
	return slist;

}
ISingleNode03 * MergeSort::merge(ISingleNode03 *a, ISingleNode03 *b)
{
	std::cout << "Enters merge...\n";
	ISingleNode03 *sorted = NULL;
	if (a == NULL)
		return b;
	if (b == NULL)
		return a;
	if (a->getValue() <= b->getValue())
	{
		sorted = a;
		sorted->setNext(merge(a->getNext(), b));
	}
	else
	{
		sorted = b;
		sorted->setNext(merge(a, b->getNext()));
	}
	return sorted;
}
void MergeSort::SplitList(ISingleNode03 * head, ISingleNode03 **front_ref, ISingleNode03 **back_ref)
{
	std::cout << "Enters Split list...\n";
	ISingleNode03 *prev;
	ISingleNode03 *post;
	if (head == NULL || head->getNext() == NULL)
	{
		*front_ref = head;
		*back_ref = NULL;
	}
	else
	{
		prev = head;
		post = head->getNext();

		while (post != NULL)
		{
			post = post->getNext();
			if (post != NULL)
			{
				prev = prev->getNext();
				post = post->getNext();
			}
		}
		*front_ref = head;
		*back_ref = prev->getNext();
		prev->setNext(NULL);
	}

}

