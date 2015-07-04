#include "Factory03.h"
#include"VectorDoubleSort.h"
#include"LinkedListSort.h"
#include"HeapSort.h"
#include"CircularList.h"
#include"MergeSort.h"
#include"SingleNode03.h"
#include"RadixSort.h"
#include"RecordsSearch.h"
#include"RunningMedian.h"
#include"DoubleList03.h"
#include"DoubleNode03.h"
#include"KthMin.h"
#include"SmoothSort.h"
Factory03::Factory03()
{
}

Factory03::~Factory03()
{
}
 
void * Factory03::create(std::string name)
{
  if(name == "IVectorDoubleSort1"){
    return new VectorDoubleSort();
  } else if(name == "IVectorDoubleSort2"){
    return new VectorDoubleSort();
  } else if(name == "ISmoothSort"){
    return new SmoothSort();
  } else if(name == "ILinkedListSort"){
    return new LinkedListSort();
  } else if(name == "IRunningMedian"){
    return new RunningMedian();
  } else if(name == "IRecordsSearch"){
    return new RecordsSearch();
  } else if(name == "IHeapSort"){
    return new HeapSort();
  } else if(name == "ISingleNode03"){
    return new SingleNode03();
  } else if(name == "ICircularList"){
    return new CircularList();
  } else if(name == "IMergeSort"){
    return new MergeSort();
  } else if(name == "IRadixSort"){
    return new RadixSort();
  } else if(name == "IKthMin"){
    return new KthMin();
  }else if (name == "IDoubleList03"){
	  return new DoubleList03();
  }else {
    return NULL;
  }
}

extern "C" {

ObjectFactory * createObjectFactory(){
  return new Factory03();  
}

}
