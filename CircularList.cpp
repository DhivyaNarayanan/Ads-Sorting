#include"CircularList.h"
#include"SingleNode03.h"

void CircularList::addHead(int number)
{
	ISingleNode03 *nn = new SingleNode03();
	nn->setValue(number);
	if (head == NULL)
	{
		nn->setNext(nn);
		head = nn;
		tail = nn;
		l_size++;
	}
	else
	{
		nn->setNext(head);
		head = nn;
		tail->setNext(head);
		/*tail->setNext(nn);
		tail = nn;
		nn->setNext(head);*/
		l_size++;
	}
}

ISingleNode03 * CircularList::getHead()
{
	return this->head;
}
void CircularList::setHead(ISingleNode03 * head)
{
	this->head = head;
}

ISingleNode03 * CircularList::getTail()
{
	return this->tail;
}
void CircularList::setTail(ISingleNode03 * tail)
{
	this->tail = tail;
}
int CircularList::size()
{
	return l_size;
}
