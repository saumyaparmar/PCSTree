#pragma once
namespace PCS
{
	class PCSNode
	{
		static const unsigned int NAME_SIZE = 32;

	public:
		PCSNode();
		PCSNode(const PCSNode& in);
		PCSNode(PCSNode* const pInParent,
			    PCSNode* const pInChild,
				PCSNode* const pInNextSibling,
				PCSNode* const pInPrevSibling,
				const char* const pInName);

		PCSNode(const char* const pInName);
		virtual ~PCSNode();

		//ASSIGNMENT OPERATOR
		PCSNode& operator = (const PCSNode& in);

		//ACCESSORS
		void SetParent(PCSNode* const pIn);
		void SetChild(PCSNode* const pIn);
		void SetNextSibling(PCSNode* const pIn);
		void SetPrevSibling(PCSNode* const pIn);

		PCSNode* GetParent(void) const;
		PCSNode* GetChild(void) const;
		PCSNode* GetNextSibling(void) const;
		PCSNode* GetPrevSibling(void) const;

		//NAME
		void SetName(const char* const pInName);
		void GetName(char* const pOutBuffer, unsigned int sizeOutBuffer) const;

		//PRINT
		void PrintNode() const;
		void PrintChildren() const;
		void PrintSiblings() const;

		//NUM OF CHILDREN AND SIBLINGS
		int GetNumSiblings() const;
		int GetNumChildren() const;
	private:
		//DATA
		PCSNode* pParent;
		PCSNode* pChild;
		PCSNode* pNextSibling;
		PCSNode* pPrevSibling;
		char     pName[PCSNode::NAME_SIZE];
	};
}