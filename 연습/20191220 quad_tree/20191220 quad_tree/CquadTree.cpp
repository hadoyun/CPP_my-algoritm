#include "CquadTree.h"

using namespace std;

SNode* CquadTree::createRootNode(char data)
{
	if (!m_root_node) m_root_node = new SNode(data);

	return m_root_node;
}

SNode* CquadTree::getRootNode()
{
	return m_root_node;
}

void CquadTree::deleteNode(SNode* current_node)
{
	if (current_node == nullptr) return;

	for (int i = 0; i < 4; ++i)
	{
		deleteNode(current_node->children[i]);
	}

	SAFE_DELETE(current_node);
}

void CquadTree::clear()
{
	deleteNode(m_current_node);
}
