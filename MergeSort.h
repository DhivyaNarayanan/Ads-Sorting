#include"Interfaces03.h"

class MergeSort : public IMergeSort
{
public:
	MergeSort() {}
	~MergeSort() {}
	void mergeSort(ICircularList * input);

	ISingleNode03 * sort(ISingleNode03 * tt);
	ISingleNode03 * merge(ISingleNode03 *a, ISingleNode03 *b);
	void SplitList(ISingleNode03 * head, ISingleNode03 **front_ref, ISingleNode03 **back_ref);
	
};
