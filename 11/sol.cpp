#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	constexpr int n = 10;
	constexpr int steps = 100;

	vector<int> ene(n * n);

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < n; j++)
			ene[i * n + j] = s[j] - '0';
	}

	//int cou = 0;
	for (int i = 0; true; i++)
	{
		for (int j = 0; j < n * n; j++)
			ene[j]++;
		vector<bool> flashed(n * n, false);
		int fcou  = 0;
		bool change = false;
		do
		{
			change = false;
			for (int j = 0; j < n; j++)
			{
				for (int k = 0; k < n; k++)
				{
					if (ene[j * n + k] > 9 && !flashed[j * n + k])
					{
						//cou++;
						fcou++;
						flashed[j * n + k] = true;
						for (int jj = max(j - 1, 0); jj <= j + 1 && jj < n; jj++)
						{
							for (int kk = max(k - 1, 0); kk <= k + 1 && kk < n; kk++)
							{
								ene[jj * n + kk]++;
							}
						}
						change = true;
					}
				}
			}
		} while (change);
		if (fcou == n * n)
		{
			cout << i + 1 << endl;
			break;
		}
		for (int j = 0; j < n * n; j++)
			if (flashed[j])
				ene[j] = 0;
	}


	return EXIT_SUCCESS;
}
