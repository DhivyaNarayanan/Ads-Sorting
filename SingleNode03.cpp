#include"SingleNode03.h"

int SingleNode03::getValue()
{
	return this->value;
}
void SingleNode03::setValue(int value)
{
	this->value = value;
}
ISingleNode03 * SingleNode03::getNext()
{
	return this->next;
}
void SingleNode03::setNext(ISingleNode03 * next)
{
	this->next = next;
}