#include <iostream>
#include "PCSTree.h"
#include "PCSNode.h"

using namespace PCS;

int main()
{

	PCSTree::Info info;
	PCSTree tree;
	PCSNode* root;

	PCSNode nodeRoot("Root");
	PCSNode nodeA("Node_A");
	PCSNode nodeB("Node_B");
	PCSNode nodeC("Node_C");
	PCSNode nodeD("Node_D");
	PCSNode nodeE("Node_E");
	PCSNode nodeI("Node_I");
	PCSNode nodeK("Node_K");
	PCSNode nodeL("Node_L");
	PCSNode nodeR("Node_R");
	PCSNode nodeF("Node_F");
	PCSNode nodeM("Node_M");
	PCSNode nodeN("Node_N");
	PCSNode nodeO("Node_O");
	PCSNode nodeP("Node_P");
	PCSNode nodeS("Node_S");
	PCSNode nodeT("Node_T");
	PCSNode nodeU("Node_U");
	PCSNode nodeV("Node_V");
	PCSNode nodeW("Node_W");

	root = tree.GetRoot();


	//INSERTION OF RANDOM TREE
	tree.Insert(&nodeRoot, root);
	tree.Insert(&nodeC, &nodeRoot);
	tree.Insert(&nodeB, &nodeRoot);
	tree.Insert(&nodeA, &nodeRoot);
	tree.Insert(&nodeI, &nodeA);
	tree.Insert(&nodeE, &nodeA);
	tree.Insert(&nodeD, &nodeA);
	tree.Insert(&nodeL, &nodeB);
	tree.Insert(&nodeK, &nodeB);
	tree.Insert(&nodeR, &nodeC);
	tree.Insert(&nodeF, &nodeD);
	tree.Insert(&nodeN, &nodeL);
	tree.Insert(&nodeM, &nodeL);
	tree.Insert(&nodeP, &nodeR);
	tree.Insert(&nodeO, &nodeR);
	tree.Insert(&nodeS, &nodeP);
	tree.Insert(&nodeW, &nodeS);
	tree.Insert(&nodeV, &nodeS);
	tree.Insert(&nodeU, &nodeS);
	tree.Insert(&nodeT, &nodeS);

	tree.GetInfo(info);

	tree.Print();
	return 0;
}


