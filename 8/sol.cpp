#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

vector<vector<bool>> digits = {
	{ 1, 1, 1, 0, 1, 1, 1 },
	{ 0, 0, 1, 0, 0, 1, 0 },
	{ 1, 0, 1, 1, 1, 0, 1 },
	{ 1, 0, 1, 1, 0, 1, 1 },
	{ 0, 1, 1, 1, 0, 1, 0 },
	{ 1, 1, 0, 1, 0, 1, 1 },
	{ 1, 1, 0, 1, 1, 1, 1 },
	{ 1, 0, 1, 0, 0, 1, 0 },
	{ 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 1, 1, 1, 0, 1, 1 }
};

int decode(const vector<string>& inst, const vector<string>& resenc)
{
	vector<int> assgn(7);
	iota(assgn.begin(), assgn.end(), 0);
	do
	{
		bool fail = false;
		for (int i = 0; i < 10; i++)
		{
			vector<bool> on(7, false);
			for (const char c : inst[i])
				on[assgn[c - 'a']] = true;
			int found = false;
			for (int j = 0; j < 10; j++)
				if (on == digits[j])
					found = true;
			if (!found)
			{
				fail = true;
				break;
			}
		}
		if (fail)
			continue;
		int val = 0;
		for (int i = 0; i < 4; i++)
		{
			vector<bool> on(7, false);
			for (const char c : resenc[i])
				on[assgn[c - 'a']] = true;
			for (int j = 0; j < 10; j++)
				if (on == digits[j])
				{
					val *= 10;
					val += j;
					break;
				}
		}
		//cout << "hey" << endl;
		return val;
	} while (next_permutation(assgn.begin(), assgn.end()));
	assert(false);
	//for (int i = 0; i < 5040; i++, a
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	for (int i = 0; i < 10; i++)
	{
		cout << " " << digits[i][0] << endl;
		cout << digits[i][1] << ' ' << digits[i][2] << endl;
		cout << ' ' << digits[i][3] << endl;
		cout << digits[i][4] << ' ' << digits[i][5] << endl;
		cout << ' ' << digits[i][6] << endl;
		cout << endl;
	}

	constexpr int n = 200;
	int sm = 0;
	for (int t = 0; t < n; t++)
	{
		vector<string> inst(10);
		for (int i = 0; i < 10; i++)
			cin >> inst[i];
		string trash;
		cin >> trash;
		vector<string> resenc(4);
		for (int i = 0; i < 4; i++)
		{
			cin >> resenc[i];
			//const int len = resenc[i].size();
			//if (len == 2 || len == 3 || len == 7 || len == 4)
			//	cou++;
		}
		sm += decode(inst, resenc);
	}
	cout << sm << endl;


	return EXIT_SUCCESS;
}
