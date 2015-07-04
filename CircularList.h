#include "Interfaces03.h"

class CircularList :public ICircularList
{
	ISingleNode03 *head = NULL;
	ISingleNode03 * tail = NULL;
	int l_size;
public:
	CircularList() 
	{
		l_size = 0;
	}
	~CircularList() {}
	void addHead(int number);
	ISingleNode03 *getHead();
	void setHead(ISingleNode03 * head);
	ISingleNode03 * getTail();
	void setTail(ISingleNode03 * tail);
	int size();
};