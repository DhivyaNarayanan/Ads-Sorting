#include"DoubleNode03.h"

void DoubleNode03::setValue(int value)
{
	this->value = value;
}
int DoubleNode03::getValue()
{
	return this->value;
}
IDoubleNode03 * DoubleNode03::getPrev()
{
	return this->prev;
}
IDoubleNode03 * DoubleNode03::getNext()
{
	return this->next;
}
void DoubleNode03::setPrev(IDoubleNode03 * prev)
{
	this->prev = prev;
}
void DoubleNode03::setNext(IDoubleNode03 * next)
{
	this->next = next;
}