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
		//child_count == �� ��尡 ���� �ִ��� �ڽ� ����� ����(count!)
		if (child_count == 4) return nullptr;

		//�ڽ� ����� child_count�� �׸� ���ο� ��带 �����.
		children[child_count] = new SNode(data);
		//child_count �׸��� ����� �θ�� �� �Լ��� ȣ���� �θ� ��尡 �ȴ�.
		children[child_count]->parent = this;

		//child_count ���ڸ� �÷� ���� children ��带 �Է��Ѵ�.
		++child_count;

		//�� �Լ��� �����ϴ� SNode == �ڽ� ���� ++�Ǳ� ���� child_count ��° �׸��� children�̴�.
		return children[child_count - 1];
	}


	char data{};

	//�θ� ��忡 ���� ������
	SNode* parent{};

	//�ڽ� ��忡 ���� ������
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