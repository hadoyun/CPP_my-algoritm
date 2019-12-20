#include "CquadTree.h"

int main()
{
	CquadTree CQT{};

	CQT.resizeToDepth(3);

	CQT.createRootNode(0);

	CQT.insertChildNode(0, 1);
	CQT.insertChildNode(0, 2);
	CQT.insertChildNode(0, 3);
	CQT.insertChildNode(0, 4);

	CQT.insertChildNode(1, 1);
	CQT.insertChildNode(1, 2);
	CQT.insertChildNode(1, 3);
	CQT.insertChildNode(1, 4);

	CQT.insertChildNode(2, 1);
	CQT.insertChildNode(2, 2);
	CQT.insertChildNode(2, 3);
	CQT.insertChildNode(2, 4);

	CQT.insertChildNode(3, 1);
	CQT.insertChildNode(3, 2);
	CQT.insertChildNode(3, 3);
	CQT.insertChildNode(3, 4);

	CQT.insertChildNode(4, 1);
	CQT.insertChildNode(4, 2);
	CQT.insertChildNode(4, 3);
	CQT.insertChildNode(4, 4);

	CQT.printTree(3);


	return 0;
}