#include"Interfaces03.h"

class RadixSort : public IRadixSort
{
public:
	RadixSort() {}
	~RadixSort() {}
	void sort(std::vector<std::string> & data);
};