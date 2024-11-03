
#ifndef _SORTED_LIST_PROXY__
#define _SORTED_LIST_PROXY__

#include <cstddef>

class SortedListProxy{
private:
  friend class SortedList;
  SortedList& owner;
  size_t index;

  operator const DataType&() const{
    return owner.array[index];
  }
    
public:

  const SortedListProxy& operator=(const DataType& data){
    if(owner.array[index] < data){
      owner.array[index] = data;
      MoveUp(index);
    }
    else if(data < owner.array[index]){
      owner.array[index] = data;
      MoveDown(index);
    }
    else{
      owner.array[index] = data;
    }
    return *this;
  }
  const SortedListProxy& operator=(const SortedListProxy& data){
    return operator=((DataType)data);
  }

  SortedListProxy(SortedList& owner, size_t index) 
    : owner(owner),
    index(index) 
  {}
};

#endif //_SORTED_LIST_PROXY__