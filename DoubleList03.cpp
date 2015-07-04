#include"DoubleList03.h"
#include"DoubleNode03.h"

IDoubleNode03 * DoubleList03::getHead()
{
	return this->head;
}
IDoubleNode03 * DoubleList03::getTail()
{
	return this->tail;
}
void DoubleList03::setHead(IDoubleNode03 * head)
{
	this->head = head;
}
void DoubleList03::setTail(IDoubleNode03 * tail)
{
	this->tail = tail;
}
void DoubleList03::addBack(int value)
{
	IDoubleNode03 *nn = new DoubleNode03();
	nn->setValue(value);
	if (head == NULL)
	{
		nn->setPrev(NULL);
		nn->setNext(NULL);
		head = nn;
		tail = nn;
		lsize++;
	}
	else
	{
		nn->setPrev(tail);
		tail->setNext(nn);
		nn->setNext(NULL);
		tail = nn;
		lsize++;
	}
}
int DoubleList03::size()
{
	return this->lsize;
}