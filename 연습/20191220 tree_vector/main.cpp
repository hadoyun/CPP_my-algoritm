#include <iostream>
#include <vector>
#include "CbinaryTree.h"

int main()
{
	CbinaryTree CBT{};

	CBT.resizeToDepth(4);

	CBT.createRootNode(111);

	CBT.insertChildNode(0, 222);
	CBT.insertChildNode(0, 222);
	CBT.insertChildNode(1, 333);
	CBT.insertChildNode(1, 333);
	CBT.insertChildNode(2, 333);
	CBT.insertChildNode(2, 333);

	CBT.insertChildNode(3, 777);
	CBT.insertChildNode(3, 888);
	CBT.insertChildNode(4, 999);
	CBT.insertChildNode(4, 1111);
	CBT.insertChildNode(4, 2222);
	CBT.insertChildNode(5, 3333);
	CBT.insertChildNode(5, 4444);
	CBT.insertChildNode(6, 5555);
	CBT.insertChildNode(6, 6666);

	CBT.printTree(4);

	//CBT.printTreeindex();

	return 0;
}