#pragma once

#include <vector>
#include <iostream>

using namespace std;

struct SNode
{
	SNode() {};
	SNode(int data) : m_data(data) {};
	~SNode() {};

	int m_data{};
	size_t m_index{};

	size_t m_parent{};

	size_t m_frist_child{};
	size_t m_second_child{};
	size_t m_third_child{};
	size_t m_fourth_child{};
};



class CquadTree
{
public:
	CquadTree() {};
	~CquadTree() {};

public:
	void resizeToDepth(int size)
	{
		m_size = pow(4, size - 1) + 4 + 1;

		m_v_node_vector.resize(m_size);
	}

	void createRootNode(int data)
	{
		m_v_node_vector[0] = data;
		m_v_node_vector[0].m_parent = 0;
		m_v_node_vector[0].m_frist_child = 1;
		m_v_node_vector[0].m_second_child = 2;
		m_v_node_vector[0].m_third_child = 3;
		m_v_node_vector[0].m_fourth_child = 4;
	}

	void insertChildNode(size_t parent_index, int data)
	{
		if (m_is_left)
		{
			if(m_is_left_in_left)
			{
				m_index = m_v_node_vector[parent_index].m_frist_child;
				m_v_node_vector[m_index] = data;
				m_v_node_vector[m_index].m_index = m_index;

				m_is_left_in_left = false;
			}
			else if (!m_is_left_in_left)
			{
				m_index = m_v_node_vector[parent_index].m_second_child;
				m_v_node_vector[m_index] = data;
				m_v_node_vector[m_index].m_index = m_index;

				m_is_left_in_left = true;

				m_is_left = false;
			}

			if (m_index == 0) m_index = 1;

			m_v_node_vector[m_index].m_frist_child = m_index * 4 + 1;
			m_v_node_vector[m_index].m_second_child = m_index * 4 + 2;
			m_v_node_vector[m_index].m_third_child = m_index * 4 + 3;
			m_v_node_vector[m_index].m_fourth_child = m_index * 4 + 4;

		}
		else if (!m_is_left)
		{
			if (m_is_left_in_left)
			{
				m_index = m_v_node_vector[parent_index].m_third_child;
				m_v_node_vector[m_index] = data;
				m_v_node_vector[m_index].m_index = m_index;

				m_is_left_in_left = false;
			}
			else if (!m_is_left_in_left)
			{
				m_index = m_v_node_vector[parent_index].m_fourth_child;
				m_v_node_vector[m_index] = data;
				m_v_node_vector[m_index].m_index = m_index;

				m_is_left_in_left = true;
				m_is_left = true;
			}

			if (m_index == 0) m_index = 1;

			m_v_node_vector[m_index].m_frist_child = m_index * 4 + 1;
			m_v_node_vector[m_index].m_second_child = m_index * 4 + 2;
			m_v_node_vector[m_index].m_third_child = m_index * 4 + 3;
			m_v_node_vector[m_index].m_fourth_child = m_index * 4 + 4;

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

				enter_counter += pow(4, j);
			}

		}


	}


private:
	vector<SNode> m_v_node_vector{};
	bool m_is_left{ true };
	bool m_is_left_in_left{ true };
	size_t m_index{};

	size_t m_size{};
};