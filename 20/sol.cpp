#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	constexpr int n = 100;
	vector<bool> code(512);
	string cds;
	cin >> cds;
	for (int i = 0; i < 512; i++)
		code[i] = cds[i] == '#';
	vector<bool> grid((n + 4) * (n + 4), false);
	for (int i = 0; i < n; i++)
	{
		string ln;
		cin >> ln;
		for (int j = 0; j < n; j++)
		{
			grid[(i + 2) * (n + 4) + j + 2] = ln[j] == '#';
		}
	}
	for (int s = 0; s < 50; s++)
	{
		vector<bool> nwg((n + 6 + s * 2) * (n + 6 + s * 2), grid[0] ? code[511] : code[0]);
		for (int i = 0; i < n + 2 * s + 2; i++)
		{
			for (int j = 0; j < n + 2 * s + 2; j++)
			{
				int ind = 0;
				for (int ii = -1; ii <= 1; ii++)
				{
					for (int jj = -1; jj <= 1; jj++)
					{
						ind = 2 * ind;
						if (grid[(n + 4 + s * 2) * (i + 1 + ii) + j + 1 + jj])
							ind++;
					}
				}
				nwg[(i + 2) * (n + 6 + s * 2) + j + 2] = code[ind];
			}
		}
		grid = nwg;
		/*
		for (int i = 0; i < n + 6 + s * 2; i++)
		{
			for (int j = 0; j < n + 6 + s * 2; j++)
			{
				cout << (nwg[i * (n + 6 + s * 2) + j] ? "#" : ".");
			}
			cout << endl;
		}
		cout << endl;
		*/
	}
	int cou = 0;
	for (const bool b : grid)
		if (b)
			cou++;
	cout << cou << endl;

	return EXIT_SUCCESS;
}
