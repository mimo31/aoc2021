#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	constexpr ll sn = 300;

	vector<ll> cous(9, 0);
	for (int i = 0; i < sn; i++)
	{
		int v;
		cin >> v;
		cous[v]++;
	}
	for (int i = 0; i < 256; i++)
	{
		vector<ll> newcous(9);
		newcous[8] = cous[0];
		newcous[7] = cous[8];
		newcous[6] = cous[7] + cous[0];
		for (int j = 0; j < 6; j++)
		{
			newcous[j] = cous[j + 1];
		}
		cous = newcous;
	}
	ll tot = 0;
	for (int i = 0; i < 9; i++)
		tot += cous[i];
	cout << tot << endl;

	return EXIT_SUCCESS;
}
