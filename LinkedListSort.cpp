#include "LinkedListSort.h"

LinkedListNode * LinkedListSort::sort(LinkedListNode * list)
{
	LinkedListNode *SList;
	LinkedListNode *head = list;
	LinkedListNode * a=NULL;
	LinkedListNode *b=NULL;
	if (head->next == NULL)
		return head;
	SplitList(head, &a, &b);
	LinkedListNode *head1 = sort(a);
	LinkedListNode *head2 = sort(b);
	SList = merge(head1, head2);
	return SList;
	
}
LinkedListNode * LinkedListSort::merge(LinkedListNode * a, LinkedListNode *b)
{
	LinkedListNode *Sortedlist = NULL;
	if (a == NULL)
		return b;
	if (b == NULL)
		return a;

	if (a->key <= b->key)
	{
		Sortedlist = a;
		Sortedlist->next = merge(a->next, b);
	}
	else
	{
		Sortedlist = b;
		Sortedlist->next = merge(a, b->next);
	}
	return Sortedlist;
}
void LinkedListSort::SplitList(LinkedListNode * head, LinkedListNode ** front_ref, LinkedListNode **back_ref)
{
	LinkedListNode * prev, *post;
	if (head == NULL || head->next == NULL)
	{
		*front_ref = head;
		*back_ref = NULL;
	}
	else
	{
		prev = head;
		post = head->next;

		while (post != NULL)
		{
			post = post->next;
			if (post != NULL)
			{
				prev = prev->next;
				post = post->next;
			}
		}
		*front_ref = head;
		*back_ref = prev->next;
		prev->next = NULL;
	}
}