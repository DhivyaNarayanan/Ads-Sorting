#include<iostream>
#include<vector>
#include<string>

class queue
{
private:
	std::vector<std::string>vec_queue;
	int rear;
	int front;
public:
	queue()
	{
		rear = -1;
		front = 0;
	}
	~queue();
	void push(std::string data);
	void pop();
	std::string ret_front();
	bool empty();
	int size();

};
