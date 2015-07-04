#include"Interfaces03.h"

class LinkedListSort : public ILinkedListSort
{
public:
	LinkedListSort() { }
	~LinkedListSort() { }
	 LinkedListNode * sort(LinkedListNode * list);
	 LinkedListNode * merge(LinkedListNode * a, LinkedListNode *b);
	 void SplitList(LinkedListNode * head, LinkedListNode ** front_ref, LinkedListNode **back_ref);
};