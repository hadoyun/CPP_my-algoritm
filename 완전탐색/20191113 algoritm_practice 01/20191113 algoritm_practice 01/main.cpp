#include <vector>
#include <iostream>

using namespace std;

//TODO 시계 맞추기 (CLOCKSYNC...)

static constexpr int KClockCount{ 16 };
static constexpr int KSwitchCount{ 10 };

vector<int> vClocksPerSwitch[]
{
	{ 0, 1, 2 },			//	0
	{ 3, 7, 9, 11 },		//	1
	{ 4, 10, 14, 15 },		//	2
	{ 0, 4, 5, 6, 7 },		//	3
	{ 6, 7, 8, 10, 12 },	//	4
	{ 0, 2, 14, 15 },		//	5
	{ 3, 14, 15 },			//	6
	{ 4, 5, 7, 14, 15 },	//	7	
	{ 1, 2, 3, 4, 5 },		//	8
	{ 3, 4, 5, 9, 13 },		//	9
};

void LimitClockTimeForSwitch(vector<int>& vClocks, int iSwitch)
{
	for (const auto& iClock : vClocksPerSwitch[iSwitch])
	{
		if (vClocks[iClock] == 0) vClocks[iClock] = 12;
		if (vClocks[iClock] == -3) vClocks[iClock] = 9;
		if (vClocks[iClock] == 15) vClocks[iClock] = 3;
	}
}

void ElapseTime(vector<int>& vClocks, int iSwitch, bool bGoForth)
{
	for (auto& iClock : vClocksPerSwitch[iSwitch])
	{
		if (bGoForth)
		{
			vClocks[iClock] += 3;
		}
		else
		{
			vClocks[iClock] -= 3;
		}
	}
}

//pressSwitch clock_switch의 종류에 따라 각 배열에 3을 추가하고 15시가 되면 다시 3시로 맞춘다.
void PressSwitch(vector<int>& vClocks, vector<int>& vPressedCountPerSwitch, int iSwitch)
{
	ElapseTime(vClocks, iSwitch, true);

	++vPressedCountPerSwitch[iSwitch];

	LimitClockTimeForSwitch(vClocks, iSwitch);
}

void UnPressSwitch(vector<int>& vClocks, vector<int>& vPressedCountPerSwitch, int iSwitch)
{
	ElapseTime(vClocks, iSwitch, false);

	--vPressedCountPerSwitch[iSwitch];

	LimitClockTimeForSwitch(vClocks, iSwitch);
}

//기저 사례
bool AreAllClocksMatched(vector<int>& vClocks)
{
	for (const auto& Clock : vClocks)
	{
		if (Clock != 12)
		{
			return false;
		}
	}
	return true;
}

int CalculateTotalPressedCount(const vector<int>& vPressedCountPerSwitch)
{
	int Sum{};

	for (const auto& PressedCountPerSwitch : vPressedCountPerSwitch)
	{
		Sum += PressedCountPerSwitch;
	}

	return Sum;
}

void SynchronizeClocks(vector<int>& vClocks, vector<int>& vPressedCountPerSwitch,
	int Offset, int& TotalPressedCount)
{
	if (Offset == 10) return;

	int PressedCount{};

	// 0 안 누름 1 1번 누름 2, 3
	for (int i = 0; i < 4; ++i)
	{
		if (i > 0)
		{
			PressSwitch(vClocks, vPressedCountPerSwitch, Offset);
			++PressedCount;
		}

		SynchronizeClocks(vClocks, vPressedCountPerSwitch, Offset + 1, TotalPressedCount);

		if (AreAllClocksMatched(vClocks))
		{
			int Cmp{ CalculateTotalPressedCount(vPressedCountPerSwitch) };

			if (Cmp < TotalPressedCount) TotalPressedCount = Cmp;

			return;
		}
	}

	for (int i = 0; i < PressedCount; ++i)
	{
		UnPressSwitch(vClocks, vPressedCountPerSwitch, Offset);
	}
}

int main()
{
	vector<int> vClocks{};

	int Time{};
	for (int iClock = 0; iClock < KClockCount; ++iClock)
	{
		cin >> Time;
		vClocks.emplace_back(Time);
	}

	vector<int> vPressedCountPerSwitch{};
	vPressedCountPerSwitch.resize(KSwitchCount);

	int Result{ 99999 };

	SynchronizeClocks(vClocks, vPressedCountPerSwitch, 0, Result);
	
	cout << Result;

	return 0;
}