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
		//child_count == 각 노드가 갖는 최대의 자식 노드의 갯수(count!)
		if (child_count == 4) return nullptr;

		//자식 노드의 child_count번 항목에 새로운 노드를 만든다.
		children[child_count] = new SNode(data);
		//child_count 항목의 노드의 부모는 이 함수를 호출한 부모 노드가 된다.
		children[child_count]->parent = this;

		//child_count 숫자를 늘려 다음 children 노드를 입력한다.
		++child_count;

		//이 함수가 리턴하는 SNode == 자식 노드는 ++되기 전에 child_count 번째 항목의 children이다.
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