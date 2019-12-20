#pragma once
#include <iostream>

#define SAFE_DELETE(a) if(a) delete a;

struct SNode
{
	SNode() {};
	SNode(int _data) : data(_data) {};
	~SNode() {};

	SNode* insertNode(char data)
	{
		if (child_count == 4) return nullptr;

		children[child_count] = new SNode(data);

		children[child_count]->parent = this;

		++child_count;

		return children[child_count - 1];
	}


	char data{};

	//부모 노드에 대한 포인터
	SNode* parent{};

	//자식 노드에 대한 포인터
	SNode* children[4]{};

	int child_count{};
};


class CquadTree
{
public:
	CquadTree() {};
	~CquadTree() { clear(); };

public:
	SNode* createRootNode(char data);

	SNode* getRootNode();

	//void printNode();

	void deleteNode(SNode* m_current_node);

	void clear();

private:
	SNode* m_root_node{};

	SNode* m_current_node{};
};