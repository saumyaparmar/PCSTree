#include "PCSTree.h"
#include "PCSNode.h"
#include <string.h>
#include <cstdint>
#include <iostream>

using namespace PCS;

//CONSTRUCTOR
PCSNode::PCSNode() :pParent(nullptr), pChild(nullptr), pNextSibling(nullptr), pPrevSibling(nullptr), pName("0")
{
}

//COPY CONSTRUCTOR
PCSNode::PCSNode(const PCSNode& in) :pParent(in.GetParent()), pChild(in.GetChild()),
pNextSibling(in.GetNextSibling()), pPrevSibling(in.GetPrevSibling())
{
	for (uint32_t i = 0; i < PCSNode::NAME_SIZE; i++)
	{
		pName[i] = in.pName[i];
	}
}

//SPECIALIZE CONSTRUCTOR
PCSNode::PCSNode(PCSNode* const pInParent, PCSNode* const pInChild, PCSNode* const pInNextSibling,
	PCSNode* const pInPrevSibling, const char* const pInName)
{
	this->pParent = pInParent;
	this->pChild = pInChild;
	this->pNextSibling = pInNextSibling;
	this->pPrevSibling = pInPrevSibling;
	for (uint32_t i = 0; i < PCSNode::NAME_SIZE; i++)
	{
		pName[i] = pInName[i];
	}
}

PCSNode::PCSNode(const char* const pInName) :pParent(nullptr), pChild(nullptr), pNextSibling(nullptr), pPrevSibling(nullptr), pName("")
{
	for (uint32_t i = 0; i < strlen(pInName) + 1; i++)
	{
		pName[i] = pInName[i];
	}
}

//DESTRUCTOR
PCSNode::~PCSNode()
{
}

//ASSIGNMENT OPERATOR
PCSNode& PCSNode::operator = (const PCSNode& in)
{
	this->pParent = in.pParent;
	this->pChild = in.pChild;
	this->pNextSibling = in.pNextSibling;
	this->pPrevSibling = in.pPrevSibling;
	for (uint32_t i = 0; i < PCSNode::NAME_SIZE; i++)
	{
		pName[i] = in.pName[i];
	}
	return *this;
}

void PCSNode::SetParent(PCSNode* const pIn)
{
	this->pParent = pIn;
}

void PCSNode::SetChild(PCSNode* const pIn)
{
	this->pChild = pIn;
}

void PCSNode::SetNextSibling(PCSNode* const pIn)
{
	this->pNextSibling = pIn;
}

void PCSNode::SetPrevSibling(PCSNode* const pIn)
{
	this->pPrevSibling = pIn;
}

PCSNode* PCSNode::GetParent(void) const
{
	return this->pParent;
}

PCSNode* PCSNode::GetChild(void) const
{
	return this->pChild;
}

PCSNode* PCSNode::GetNextSibling(void) const
{
	return this->pNextSibling;
}

PCSNode* PCSNode::GetPrevSibling(void) const
{
	return this->pPrevSibling;
}

void PCSNode::SetName(const char* const pInName)
{
	if (pInName == nullptr)
	{
		std::cout << "NOT VALID NAME";
		return;
	}

	for (uint32_t i = 0; i < PCSNode::NAME_SIZE; i++)
	{
		pName[i] = pInName[i];
	}
	pName[strlen(pInName)] = '\0';
}

void PCSNode::GetName(char* const pOutBuffer, unsigned int sizeOutBuffer) const
{
	//Name is not initialized
	if (pName == nullptr)
	{
		std::cout << "NAME NOT INITIALIZED";;
		return;
	}

	//if pOutBuffer and sizeOutBuffer is not initialized
	if (pOutBuffer == nullptr || sizeOutBuffer == 0)
	{
		std::cout << "BUFFERS ARE NOT INITIALIZED";
		return;
	}

	for (uint32_t i = 0; i < sizeOutBuffer - 1; i++)
	{
		pOutBuffer[i] = pName[i];
	}
	pOutBuffer[sizeOutBuffer - 1] = '\0';

}

void PCSNode::PrintNode() const
{
	printf("\n");
	printf("\n");
	printf("\n");
	printf("Node Name: %s", pName);
	printf("\n");
	if (pParent == nullptr)
	{
		printf("ParentNode: nullptr, (%p)", pParent);
	}
	else
	{
		printf("ParentNode: %s , (%p)", pParent->pName, pParent);
	}
	printf("\n");
	if (pChild == nullptr)
	{
		printf("ChildNode: nullptr, (%p)", pChild);
	}
	else
	{
		printf("ChildNode: %s, (%p)", pChild->pName, pChild);
	}
	printf("\n");
	if (pNextSibling == nullptr)
	{
		printf("NextSiblingNode: nullptr, (%p)", pNextSibling);
	}
	else
	{
		printf("NextSiblingNode: %s, (%p)", pNextSibling->pName, pNextSibling);
	}
	printf("\n");
	if (pPrevSibling == nullptr)
	{
		printf("PrevSiblingNode: nullptr, (%p)", pPrevSibling);
	}
	else
	{
		printf("PrevSiblingNode: %s, (%p)", pPrevSibling->pName, pPrevSibling);
	}
	printf("\n");
	printf("\n");
	printf("\n");
}

void PCSNode::PrintChildren() const
{
	PCSNode* pCurrChild = pChild;
	int cnt = 0;
	while (pCurrChild != nullptr)
	{
		cnt++;
		printf("\n");
		printf("ChildNode %d: %s, (%p)", cnt, pCurrChild->pName, pCurrChild);
		printf("\n");
		pCurrChild = pCurrChild->pNextSibling;
	}
}


void PCSNode::PrintSiblings() const
{
	printf("\n");
	if (pNextSibling == nullptr)
	{
		printf("NextSiblingNode: nullptr, (%p)", pNextSibling);
	}
	else
	{
		printf("NextSiblingNode: %s, (%p)", pNextSibling->pName, pNextSibling);
	}
	printf("\n");
	if (pPrevSibling == nullptr)
	{
		printf("PrevSiblingNode: nullptr, (%p)", pPrevSibling);
	}
	else
	{
		printf("PrevSiblingNode: %s, (%p)", pPrevSibling->pName, pPrevSibling);
	}
	printf("\n");
}

int PCSNode::GetNumSiblings() const
{
	PCSNode* pCurrNextSibling = pNextSibling;
	PCSNode* pCurrPrevSibling = pPrevSibling;
	int cnt = 1;

	while (pCurrPrevSibling != nullptr)
	{
		cnt++;
		pCurrPrevSibling = pCurrPrevSibling->pPrevSibling;
	}
	while (pCurrNextSibling != nullptr)
	{
		cnt++;
		pCurrNextSibling = pCurrNextSibling->pNextSibling;
	}
	return cnt;
}

int PCSNode::GetNumChildren() const
{
	PCSNode* pCurrChild = pChild;
	int cnt = 0;
	if (pCurrChild != nullptr)
	{
		PCSNode* pCurrSibling = pCurrChild;
		while (pCurrSibling != nullptr)
		{
			cnt++;
			pCurrSibling = pCurrSibling->pNextSibling;
		}
	}
	return cnt;
}