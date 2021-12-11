#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	constexpr int d = 100;
	constexpr int b = 100;

	vector<int> draws(d);
	for (int i = 0; i < d; i++)
		cin >> draws[i];

	vector<vector<int>> boards(b);
	vector<vector<bool>> marked(b);
	for (int i = 0; i < b; i++)
	{
		boards[i] = vector<int>(5 * 5);
		marked[i] = vector<bool>(5 * 5, false);
		for (int j = 0; j < 5 * 5; j++)
			cin >> boards[i][j];
	}
	vector<bool> won = vector<bool>(b, false);
	int wonc = 0;
	int lastd = -1;
	int lastwin = -1;
	for (int i = 0; i < d; i++)
	{
		lastd = draws[i];
		for (int j = 0; j < b; j++)
		{
			if (won[j])
				continue;
			for (int k = 0; k < 5 * 5; k++)
			{
				if (boards[j][k] == draws[i])
					marked[j][k] = true;
			}
			for (int k = 0; k < 5; k++)
			{
				bool fail = false;
				for (int l = 0; l < 5; l++)
					if (!marked[j][5 * k + l])
					{
						fail = true;
						break;
					}
				if (!fail)
				{
					lastwin = j;
					wonc++;
					won[j] = true;
					break;
				}
			}
			if (wonc == b)
				break;
			if (won[j])
				continue;
			for (int k = 0; k < 5; k++)
			{
				bool fail = false;
				for (int l = 0; l < 5; l++)
					if (!marked[j][5 * l + k])
					{
						fail = true;
						break;
					}
				if (!fail)
				{
					lastwin = j;
					wonc++;
					won[j] = true;
					break;
				}
			}
			if (wonc == b)
				break;
		}
		if (wonc == b)
			break;
	}
	int sm = 0;
	for (int i = 0; i < 5 * 5; i++)
		if (!marked[lastwin][i])
			sm += boards[lastwin][i];
	cout << sm * lastd << endl;
	return EXIT_SUCCESS;
}
