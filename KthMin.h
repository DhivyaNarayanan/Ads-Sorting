#include"Interfaces03.h"

class KthMin : public IKthMin
{
public:
	KthMin() {}
	~KthMin() {}
	int findKthMin(IDoubleList03 * data, int k);
	void exchange(IDoubleNode03 * p1, IDoubleNode03 * p2);
};