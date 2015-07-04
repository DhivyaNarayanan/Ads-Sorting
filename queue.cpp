#include"queue.h"
#include<string>

void queue::push(std::string data)
{
	vec_queue.push_back(data);
	rear++;
}
void queue::pop()
{
	
	front++;

}
std::string queue::ret_front()
{
	return vec_queue[front];
}

bool queue::empty()
{
	if (front > rear)
		return true;
	else
		return false;
}
int queue::size()
{
	return rear - front;
}