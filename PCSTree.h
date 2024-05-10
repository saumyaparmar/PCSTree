#pragma once
namespace PCS
{

	//FORWARD DECLARE
	class PCSNode;

	class PCSTree
	{
	public:
		struct Info
		{
			int currNumNodes;
			int maxNumNodes;
			int currNumLevels;
			int maxNumLevels;
		};

	public:

		PCSTree();
		PCSTree(const PCSTree& in) = delete;
		PCSTree& operator = (const PCSTree& in) = delete;
		~PCSTree();

	public:

		PCSNode* GetRoot() const;
		void Insert(PCSNode* const pInNode, PCSNode* const pParent);
		void Remove(PCSNode* const pInNode);
		void GetInfo(Info& info);
		void Print() const;


	private:
		void printNodes(PCSNode* inNode) const;
		int calculateDepth(PCSNode* node);
		int calculateMaxDepth(const PCSNode*, int);


	private:
		Info	mInfo;
		PCSNode* pRoot;

	};

}