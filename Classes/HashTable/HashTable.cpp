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
  int* Table;
  int  UniqueHashes;
  int  ExpectedEntries;
  int  Entries;

  int  _ArraySize;
  int  UsedCells;

public:
  int  ArraySize;

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

    DeclaredSize = ((_ExpectedEntries > 4) ? _ExpectedEntries : 4);
    Entries      = 0;
    UsedCells    = 0;

    _ArraySize   = ExpectedEntries << 2;
    Table        = new Type[_Size];
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
	float Filled = (UsedCells / ArraySize);
	if (Filled >= ((float)2/(float)3))
	{
		//Create New
		int NewArraySize = UsedCells*4;
    HashTable<Type, HashType> Temp_HashTable = HashTable<Type, HashType>(NewArraySize);

		//printf("Migrating Elements\n");
		//int NewArraySize = HashTable->ArraySize*4;
		//Hash_t* NewTable = (Hash_t*) malloc(NewArraySize*sizeof(Hash_t));
		DLL_Transverse(HashTable->Elements,
			Hash_t* Hash_Element = (Hash_t*)(Node->GivenStruct);
			if (Hash_Element->InUse)
			{
				printf("Adding/Moving <%d,%p>",Hash_Element->UniqueHash,Hash_Element->GivenStruct);
				Add(Temp_HashTable,Hash_Element->UniqueHash,Hash_Element->GivenStruct);
			}

		)
		free(HashTable->Table);
		printf("Migrating Table\n");

		printf("(%p,%p)\n",HashTable->Table,Temp_HashTable->Table);
		//free(HashTable->Table);
		HashTable->Table     = Temp_HashTable->Table;
		Free_DirectStructure(HashTable->Elements);
		HashTable->Elements  = Temp_HashTable->Elements;
		HashTable->Entries   = Temp_HashTable->Entries;
		HashTable->ArraySize = Temp_HashTable->ArraySize;
		HashTable->UsedCells = Temp_HashTable->UsedCells;
		printf("(%p,%p)\n",HashTable->Table,Temp_HashTable->Table);
		free(Temp_HashTable);

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
  inline HashType FindHash(Type GivenStruct)
  {
    return HashFunction(GivenStruct);
  }

  //Get(HashTable_t* HashTable,int Hash)
  //Gets the pointer to the unique Hash value
  //Retruns:
  // Type* : Success
  // NULL  : Either entry doest exist, or something went wrong!
  Type* Get(HashType Hash)
  {
    int Index = Exists(Hash);
  	if (Index>=0)
  	{
  		return (&Table[Index])->GivenStruct;
  	}
  	return NULL;
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
