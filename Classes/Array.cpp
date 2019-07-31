#ifndef Array_CPP
#define Array_CPP

#define DEFAULT_ARRAYSIZE 64

//Array implements ExtensibleArray, where array is allocated and allows for
//further Page indexing without constant reallocation for each 'Append'/'Add'
//Operation.template <class T,typename L>

template <class T,typename L>
class Array
{
  T* array; // Pointer to Array of given class type.

  L _Size; // Number of elements the array is extendable to without reallocation.
public:
  L Size; // Number of elements added to the array.



  Array(int DeclaredSize)
  {
    //Minimum Size = 20
    DeclaredSize = ((DeclaredSize > 4) ? DeclaredSize : 4);
    Size =  DeclaredSize;

    _Size = Size << 2;
    array = new T[_Size];

  }



  ~Array()
  {
    delete [] array;
  }

//Hidden Function that Extends the array when it gets larger than the (hidden array size '_Size'), or the index being modified.
  void _Extend(L By)
  {
    By = By <<2;
    if(By > _Size)
    {
      T* New_array = new T[By];

      for(int x=0;x<=Size;x++)
      {
        New_array[x] = array[x];
      }
      delete array;
      array = New_array;
      _Size = By;
    }
  }

//Print Itterates Over the list and prints the contents of each index.
 void Print()
 {
   for(int x=0; x<=Size;x++)
   {
     std::cout <<x<< " :" << array[x] << "\n";
   }
 }

 //int Get(int Index)
 //Returns index of GivenElement
 // [0-MaxInteger] : index in Array
 // -1             : Something went wrong
 // -2             :
  int Add(T GivenElement)
  {
    Size++;
    Set(Size,GivenElement);
    return Size;
  }

//  void Set(int Index,T*GivenStructure)
//Short:
//Takes index, and GivenStruct, and adds GivenStruct to the array's index
  void Set(L Index,T GivenElement)
  {
    if (Index >= Size)
    {
      Size = Index;
    }
    if(Size == _Size)
  	{
      int IncreaseBy = ((Size > Index) ? Size : Index);
  		//Extend Array
      _Extend(IncreaseBy);
  	}

    array[Index] = GivenElement;
  }

  //int Get(int Index)
  //Returns:
  // T*    : Success, Returns a pointer to the Element
  // NULL  : Something went wrong
  T* Get(L Index)
  {
  	if(Index > Size)
  	{
  		//attempting to access element outside array
  		return NULL;
  	}
  	return array[Index];
  }
};

#endif // Array_CPP
