#include "PCSTree.h"
#include "PCSNode.h"
#include <iostream>


using namespace PCS;

PCSTree::PCSTree() :pRoot(nullptr)
{
	mInfo.currNumLevels = 0;
	mInfo.maxNumLevels = 0;
	mInfo.currNumNodes = 0;
	mInfo.maxNumNodes = 0;
};
PCSTree::~PCSTree()
{
};

//GET ROOT
PCSNode* PCSTree::GetRoot() const
{
	return this->pRoot;
}


//INSERT NODE AT THE FRONT
void PCSTree::Insert(PCSNode* const pInNode, PCSNode* const pParent)
{
	if (pParent == nullptr)
	{
		pInNode->SetParent(pParent);
		pRoot = pInNode;
		mInfo.currNumLevels++;
		mInfo.currNumNodes++;
		mInfo.maxNumLevels++;
		mInfo.maxNumNodes++;
	}
	else
	{
		//Set the parent of the inserted node
		pInNode->SetParent(pParent);

		//Add to front so first get the child of the parent if its not null
		if (pParent->GetChild() == nullptr)
		{
			pParent->SetChild(pInNode);
			mInfo.currNumNodes++;
			mInfo.maxNumNodes++;

			if (calculateDepth(pInNode) > mInfo.maxNumLevels)
			{
				mInfo.currNumLevels++;
				mInfo.maxNumLevels++;
			}
		}
		else
		{
			pInNode->SetNextSibling(pParent->GetChild()); //Update the next sibling of the newly added node
			pParent->GetChild()->SetPrevSibling(pInNode); //Update the prev sibling of the previously added node
			pParent->SetChild(pInNode); //Set the newly added node as the child of the parent
			mInfo.currNumNodes++;
			mInfo.maxNumNodes++;
		}


	}
}


//REMOVE NODES
void PCSTree::Remove(PCSNode* const pInNode)
{
	if (pInNode == nullptr)
	{
		return;
	}

	//Remove all the children of the node
	while (pInNode->GetChild() != nullptr)
	{
		Remove(pInNode->GetChild());
	}

	//Update the siblings
	if (pInNode->GetPrevSibling() != nullptr)
	{
		pInNode->GetPrevSibling()->SetNextSibling(pInNode->GetNextSibling());
	}
	if (pInNode->GetNextSibling() != nullptr)
	{
		pInNode->GetNextSibling()->SetPrevSibling(pInNode->GetPrevSibling());
	}

	//If the node is the child of the parent then update the pointer
	if (pInNode->GetParent() != nullptr && pInNode->GetParent()->GetChild() == pInNode) {
		pInNode->GetParent()->SetChild(pInNode->GetNextSibling());
	}

	//Recalculating trees numlevel
	if (calculateDepth(pInNode) == mInfo.currNumLevels)
	{
		int newDepth = calculateMaxDepth(pRoot, 1);
		if (newDepth < mInfo.currNumLevels)
		{
			mInfo.currNumLevels = newDepth;
		}
	}

	if (pInNode == pRoot)
	{
		mInfo.currNumLevels = 0;
	}
	//Clear everything
	pInNode->SetParent(nullptr);
	pInNode->SetNextSibling(nullptr);
	pInNode->SetPrevSibling(nullptr);
	mInfo.currNumNodes--;
}



//GET TREE INFO
void PCSTree::GetInfo(Info& info)
{
	info.currNumLevels = mInfo.currNumLevels;
	info.currNumNodes = mInfo.currNumNodes;
	info.maxNumLevels = mInfo.maxNumLevels;
	info.maxNumNodes = mInfo.maxNumNodes;
}

void PCSTree::Print() const
{
	printNodes(pRoot);
}

void PCSTree::printNodes(PCSNode* inNode) const
{
	if (inNode == nullptr)
	{
		return;
	}

	inNode->PrintNode();

	//Recursively print the children
	if (inNode->GetChild() != nullptr)
	{
		printNodes(inNode->GetChild());
	}

	//Recursively print the children
	if (inNode->GetNextSibling() != nullptr)
	{
		printNodes(inNode->GetNextSibling());
	}

}


int PCSTree::calculateDepth(PCSNode* node)
{
	PCSNode* pCurr = node;
	int depth = 0;
	while (pCurr != nullptr)
	{
		depth++;
		pCurr = pCurr->GetParent();
	}
	return depth;
}

int PCSTree::calculateMaxDepth(const PCSNode* node, int depth = 1)
{
	if (node == nullptr)
	{
		return depth - 1;
	}

	int maxDepth = depth;
	PCSNode* child = node->GetChild();
	while (child != nullptr)
	{
		maxDepth = std::max(maxDepth, calculateMaxDepth(child, depth + 1));
		child = child->GetNextSibling();
	}
	return maxDepth;
}
