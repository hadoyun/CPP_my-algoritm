#pragma once
#include <vector>
#include <iostream>

using namespace std;

#define SAFE_DELETE(a) if(a) delete a;



struct SNode
{
	SNode() {};
	SNode(int data) : m_data(data) {};
	~SNode() {};

	int m_data{};
	size_t m_index{};

	size_t m_parent{};
	size_t m_left{};
	size_t m_right{};
};



class CbinaryTree
{
public:
	CbinaryTree() {};
	~CbinaryTree() {};

public:
	void resizeToDepth(int size)
	{
		m_size = pow(2, size) - 1;

		m_v_node_vector.resize(m_size);
	}

	void createRootNode(int data)
	{
		m_v_node_vector[0] = data;
		m_v_node_vector[0].m_parent = 0;
		m_v_node_vector[0].m_left = 1;
		m_v_node_vector[0].m_right = 2;
	}

	void insertChildNode(size_t parent_index, int data)
	{
		if (m_is_left)
		{
			m_index = m_v_node_vector[parent_index].m_left;
			m_v_node_vector[m_index] = data;
			m_v_node_vector[m_index].m_index = m_index;

			if (m_index == 0) m_index = 1;

			m_v_node_vector[m_index].m_left = m_index * 2 + 1;
			m_v_node_vector[m_index].m_right = m_index * 2 + 2;

			m_is_left = false;
		}
		else if (!m_is_left)
		{
			m_index = m_v_node_vector[parent_index].m_right;
			m_v_node_vector[m_index] = data;
			m_v_node_vector[m_index].m_index = m_index;

			if (m_index == 0) m_index = 1;

			m_v_node_vector[m_index].m_left = m_index * 2 + 1;
			m_v_node_vector[m_index].m_right = m_index * 2 + 2;

			m_is_left = true;
		}
	}

	void printTree(int depth)
	{
		double enter_counter{};

		vector<double> v_enter_counter{};

		for (auto& i : m_v_node_vector)
		{
			cout << " [" << i.m_data << ']';


			for (int j = 1; j < depth + 1; ++j)
			{
				v_enter_counter.emplace_back(enter_counter);

				for (auto& v : v_enter_counter)
				{
					if (i.m_index == v)
					{
						cout << '\n';
					}
				}

				enter_counter += pow(2, j);
			}

		}


	}


private:
	vector<SNode> m_v_node_vector{};
	bool m_is_left{ true };
	size_t m_index{};

	size_t m_size{};
};