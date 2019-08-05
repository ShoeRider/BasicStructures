#include <iostream>
#include <list>

//NEAT: Nueral Evolution Tapologies

//Random Mutations:
// + New Node
// + Remove Node
// + Change hyper parameter
// + Change Network Size
// +


//Conserns:
// Residual Networks/Units ?
// Network To :
// + Forward Propigation
// + Back Propigation

//Chance of Adding Methods:
//+ Dropout
//+ Batch Norm
//+ Folding: Cross Validation


template <typename Input, typename Output>
class NEATNetwork()
{

	struct NodeGene_t{
		int NodeNumber;
		int InnovationNumber;
	}NodeGene_t;

	struct EdgeGene_t{
		int From;
		int To;
		float Weight;
		int InnovationNumber;
	}EdgeGene_t;

	std::list<NodeGene_t> NodeGenes;
	std::list<EdgeGene_t> EdgeGenes;

public:
  /*
  * @name: RunTimeHashFunction
  * @short:
  * @note: make sure types match HashTable types!

  typedef HashType (*RunTimeHashFunction)(HashType*);
  RunTimeHashFunction HashFunction;

  */



	NEATNetwork(){
	//Chance at adding layer
	//Chance at Removing layer
	//Chance at Adding existing Genetics
	//Fitness

	}

	NEATNetwork(){

	}

	void ADD_Block(Block){
	Blocks.push_back(Block);
	}

	Output Activate(Input){

	}

	NEATNetwork Copy(){

	}

}
