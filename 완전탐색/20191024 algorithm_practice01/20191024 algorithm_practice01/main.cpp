#include <vector>
#include <iostream>

using namespace std;


void pairCombination(int left_student_count, int total_student_count, const vector<pair<int, int>>& v_friend_pair,
	vector<pair<int, int>>& v_matched_pair, int& result, int offset)
{
	if (left_student_count == 0) return;

	for (int i = offset; i < (int)v_friend_pair.size(); ++i)
	{
		bool collision{ false };

		//�񱳸� �ݺ��ϱ� ���� for��
		for (const auto& matched_pair : v_matched_pair)
		{
			// v_matched_pair �� �ϳ��� ��ġ�� v_matched_pair�� emplace_back�� ���� �ʴ´�.
			if (matched_pair.first == v_friend_pair[i].first ||
				matched_pair.first == v_friend_pair[i].second ||
				matched_pair.second == v_friend_pair[i].first ||
				matched_pair.second == v_friend_pair[i].second)
			{
				collision = true;
				// '�ϳ���'
				break;
			}
		}

		// �浹���� ������ v_matched_pair�� emlplace_back�� ���ش�!
		if (collision == false)
		{
			v_matched_pair.emplace_back(v_friend_pair[i]);

			pairCombination(left_student_count - 2, total_student_count, v_friend_pair, v_matched_pair, result, i + 1);

			if ((int)v_matched_pair.size() == total_student_count / 2) ++result;

			if (v_matched_pair.size()) v_matched_pair.pop_back();
		}
	}
}


int main()
{
	int student_count{};

	cin >> student_count;

	int pair_count{};

	cin >> pair_count;

	int input[2]{};

	vector<pair<int, int>> v_friend_pair{};

	vector<pair<int, int>> v_matched_pair{};

	int result{};

	for (int i = 0; i < pair_count; ++i)
	{
		cin >> input[0];
		cin >> input[1];

		if (input[0] > input[1])
		{
			swap(input[0], input[1]);
		}

		v_friend_pair.emplace_back(make_pair(input[0], input[1]));
	}

	pairCombination(student_count, student_count, v_friend_pair, v_matched_pair, result, 0);

	cout << result;

	return 0;
}