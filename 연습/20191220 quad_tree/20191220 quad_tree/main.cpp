#include "CquadTree.h"


int main()
{
	CquadTree CQT{};

	SNode* root_node{ CQT.createRootNode('w') };

	SNode* a{ root_node->insertNode('a') };
	root_node->insertNode('b');
	root_node->insertNode('c');
	root_node->insertNode('d');
	a->insertNode('e');
	a->insertNode('f');
	a->insertNode('g');
	a->insertNode('h');


	int v{ 11111 };

	return 0;
}