#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<char> state(n * m);
	for (int i = 0; i < n; i++)
	{
		string li;
		cin >> li;
		for (int j = 0; j < m; j++)
			state[i * m + j] = li[j];
	}
	for (int step = 1; ; step++)
	{
		vector<bool> mov(n * m, false);
		bool moved = false;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				mov[i * m + j] = state[i * m + j] == '>' && state[i * m + (j + 1) % m] == '.';
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				if (mov[i * m + j])
				{
					moved = true;
					state[i * m + j] = '.';
					state[i * m + (j + 1) % m] = '>';
				}
			}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				mov[i * m + j] = state[i * m + j] == 'v' && state[(i + 1) % n * m + j] == '.';
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				if (mov[i * m + j])
				{
					moved = true;
					state[i * m + j] = '.';
					state[(i + 1) % n * m + j] = 'v';
				}
			}
		if (!moved)
		{
			cout << step << endl;
			break;
		}
	}


	return EXIT_SUCCESS;
}
