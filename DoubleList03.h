#include"Interfaces03.h"

class DoubleList03 :public IDoubleList03
{
	IDoubleNode03 * head;
	IDoubleNode03* tail;
	int lsize;
public:
	DoubleList03() 
	{
		head = NULL;
		tail = NULL;
		lsize = 0;
	}
	~DoubleList03() {}
	IDoubleNode03 * getHead();
	IDoubleNode03 * getTail();
	void setHead(IDoubleNode03 * head);
	void setTail(IDoubleNode03 * tail);
	void addBack(int value);
	int size();
};
