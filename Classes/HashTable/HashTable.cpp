#ifndef Hash_CPP
#define Hash_CPP


/*
*@file: HashTable.cpp
*@short:
*extended
*details
*@version
*@note
*@name: Anthony Schroeder
*@email: as3379@nau.edu
*@info
*@date
*@dependencies

*/

#include <iostream>
#include <chrono>
#include <mutex>
#include <thread>
#include <array>


/*
* HashTable
*
* @short: Generic hash table that allows for constant access time.
*
* @tparam Type
* @tparam HashType
* @Long: Implements an ExtensibleArray, where array is allocated and allows for
* further Page indexing without constant reallocation for each 'Append'/'Add'
*/
template <class Type, typename HashType>
class HashTable{


/*
* @fName: --
* @short: --
* @long: --
* @retrun:
*/
  struct Hash_t{
    Type     Item;
    HashType HashValue;
  }Hash_t;


  std::mutex Mutex;
  int* PageTable;
  int  UniqueHashes;
  int  ExpectedEntries;
  int  Entries;
  int  _ArraySize;

  int  UsedCells;

public:

  /*
  * @name: RunTimeHashFunction
  * @short:
  * @note: make sure types match HashTable types!
  */
  typedef HashType (*RunTimeHashFunction)(HashType*);
  RunTimeHashFunction HashFunction;



/*
* @fName: --
* @short: --
* @long: --
* @retrun:
*/
  HashTable(){
    HashTable(100);
  }

/*
* @fName: --
* @short: --
* @long: --
* @retrun:
*/
  HashTable(int _ExpectedEntries){
    ExpectedEntries = ExpectedEntries;
  }


/*
* @fName: _Extend
* @param:
*    - Void
* @short: Internal function for extending the HashTable to include more Elements
*         when 2/3rd's of the Table has been Used.
* @long: --
* @retrun:(void)
*/
  void _Extend(){

  }


/*
* @fName: _ScanAdd
* @short: Returns the index in table where the new item 'UniqueHash' can be
*         added.
* @long: --
* @retrun:(int)
*    [0-MaxInteger] : Index in HashTable->Table[Index]
*    -1             : Entry Exists
*    -2             : Array Full/Unexpected Error
*/
    int _ScanAdd(HashType UniqueHash)
    {
      return -2;
    }


/*
* @fName: Exists
* @short: Checks if 'UniqueHash' exists.
* @long: --
* @retrun:(int)
*    [0-MaxInteger] : Index in HashTable->Table[Index]
*    -1             : No Entry Exists
*    -2             : Array Full/Unexpected Error
*/
  int Exists(HashType UniqueHash)
  {
/*  	int Index = UniqueHash % HashTable->ArraySize;
  	int OverlapedStartIndex = Index;
  	while(true)
  	{
  		printf("\tIndex:%d\n",Index);
  		printf("\t  Accessed:%d\n",HashTable->Table[Index].Accessed);
  		printf("\t  UniqueHash:%d\n",HashTable->Table[Index].UniqueHash);
  		if(!HashTable->Table[Index].Accessed)
  		{
  			return -1;
  		}
  		else if(HashTable->Table[Index].UniqueHash == UniqueHash)
  		{
  			return Index;
  		}
  		printf("\t  OverlapedStartIndex:%d,%d\n",OverlapedStartIndex,Index);

  		Index++;
  		printf("\t  HashTable->ArraySize:%d\n",HashTable->ArraySize);

  		if(HashTable->ArraySize <= Index)
  		{
  			Index = 0;
  		}
  		if(Index == OverlapedStartIndex)
  		{
  			return -2;
  		}

  	}*/
  }

/*
* @fName: Add
* @short: Adds given Pointer to structure with the Given UniqueHash integer
*         value.
* @param:
*    - HashType UniqueHash
*    - Type* GivenStruct
*
* @long: --
*
* @retrun:(int)
*    [0-MaxInteger] : Index in HashTable->Table[Index]
*    -1             : UniqueTag Already Exists
*    -2             : Array Full/Unexpected Error
*/
  int Add(HashType UniqueHash,Type* GivenStruct)
  {
/*  	int Index = _ScanAdd(HashTable,UniqueHash);
  	if (Index<0)
  	{
  		return Index;
  	}

  	if(!HashTable->Table[Index].Accessed)
  	{
  		HashTable->UsedCells++;
  	}
  	//Add to Hash Array and DLL
  	HashTable->Table[Index].Accessed    = true;
  	HashTable->Table[Index].InUse       = true;
  	HashTable->Table[Index].UniqueHash  = UniqueHash;
  	HashTable->Table[Index].GivenStruct = GivenStruct;
  	HashTable->Entries++;

  	HashTable->Table[Index].DLL_Node
  	 						= Add(HashTable->Elements,(void*)&HashTable->Table[Index]);

  	HashTable->Entries++;
  	_Extend(HashTable);
  	printf("(%p)\n",HashTable->Table);
  	return Index;*/
  }

/*
* @fName: Add
* @short: Adds given Pointer to structure with the Given UniqueHash integer
*         value.
* @param:
*    - HashType UniqueHash
*    - Type* GivenStruct
*
* @long: --
*
* @retrun:(int)
*    [0-MaxInteger] : Index in HashTable->Table[Index]
*    -1             : UniqueTag Already Exists
*    -2             : Array Full/Unexpected Error
*/
  int Add(char* String,Type* GivenStruct)
  {
  	//String
  	//int hash = (int) ElfHash(String);
  	//return Add(HashTable,hash,GivenStruct);
  }

/*
* @fName: Add
* @short: Adds given Pointer to structure with the Given UniqueHash integer
*         value.
* @param:
*    - HashType UniqueHash
*    - Type* GivenStruct
*
* @long: --
*
* @retrun:(int)
*    [0-MaxInteger] : Index in HashTable->Table[Index]
*    -1             : UniqueTag Already Exists
*    -2             : Array Full/Unexpected Error
*/
  HashType FindHash(Type GivenStruct)
  {
    return NULL;
  }

  //Get(HashTable_t* HashTable,int Hash)
  //Gets the pointer to the unique Hash value
  //Retruns:
  // T* : Success
  // NULL  : Either entry doest exist, or something went wrong!
  Type* Get(HashType Hash)
  {
/*  	int Index = Exists(HashTable,Hash);
  	if (Index>=0)
  	{
  		return (&HashTable->Table[Index])->GivenStruct;
  	}
  	return NULL;*/
  }


  //Get(HashTable_t* HashTable, char* String)
  //Gets the pointer to the unique Hash value for the given string.
  //Retruns:
  // Void* : Success
  // NULL  : Something went wrong
  Type* Get(char* String)
  {
/*  	//String
  	int hash = (int) ElfHash(String);
  	return Get(HashTable,hash);*/
  }

/*
* @fName: --
* @short: --
* @long: --
* @retrun:
*/
  //Remove(HashTable_t* HashTable,int UniqueHash)
  //Returns Index
  // [0-MaxInteger] : Index in HashTable->Table[Index]
  // -1             : No UniqueHash
  // -2             : Unexpected Error
  int Remove(int UniqueHash)
  {
/*  	int Index = Exists(HashTable,UniqueHash);
  	if(Index>=0)
  	{
  		//Hash_t* Hash      = &;
  		HashTable->Table[Index].UniqueHash  = 0;
  		HashTable->Table[Index].GivenStruct = NULL;
  		HashTable->Table[Index].InUse       = false;
  		HashTable->Entries--;
  		Pop(HashTable->Elements,HashTable->Table[Index].DLL_Node);
  	}
  	return Index;*/
  }


/*
* @fName: Pop(HashType String)
* @short: (Remove/Get) removes item from HashTable and returns
* @long: --
* @retrun:
*   Type : Success
*   NULL : Something went wrong
*/
  Type* Pop(HashType Hash){
  /*  	int Index = Exists(HashTable,Hash);
    printf("Exists:%d\n",Index);
    if (Index>=0)
    {
      void* GivenStruct = (&HashTable->Table[Index])->GivenStruct;
      Remove(HashTable,Hash);
      return GivenStruct;
    }
    printf("Hash :%d Not found!\n",Hash);
    return NULL;*/
  }

/*
* @fName: --
* @short: --
* @long: --
* @retrun:
*/
  ~HashTable(){
    //Free_DirectStructure(HashTable->Elements);

    //free(Table);
  }




/*
* @fName: --
* @short: --
* @long: --
* @retrun:
*/
  //Print(HashTable_t* HashTable)
  void Print()
  {
/*  	printf("\n\n");
  	printf("HashTable: %p\n",HashTable);
  	for(int x=0;x<HashTable->ArraySize;x++)
  	{
  		printf("\tIndex:%d, Accessed: %d, UniqueTag: %d, UniqueTag: %p\n",x, HashTable->Table[x].Accessed, HashTable->Table[x].UniqueHash,HashTable->Table[x].GivenStruct);
  	}
  	Print(HashTable->Elements);
  	printf("\n\n");*/
  }
};






#endif // Hash_CPP
