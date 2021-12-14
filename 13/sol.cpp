#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll merge(const int a0, const int a1)
{
	return (((ll)a0) << 32) | a1;
}

pair<int, int> split(const ll a)
{
	const ll msk = ((1ll << 32) - 1);
	return { (a >> 32) & msk, a & msk };
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	/*
	constexpr int n = 18;
	constexpr int k = 2;
	*/

	constexpr int n = 887;
	constexpr int k = 12;

	unordered_set<ll> vals;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		vals.insert(merge(x, y));
	}

	for (int i = 0; i < k; i++)
	{
		string s;
		int coor;
		cin >> s >> coor;
		assert(s == "x" || s == "y");
		unordered_set<ll> nwset;
		if (s == "x")
		{
			for (const ll val : vals)
			{
				const pair<int, int> coors = split(val);
				if (coors.first < coor)
					nwset.insert(val);
				else
					nwset.insert(merge(coor - (coors.first - coor), coors.second));
			}
		}
		else
		{
			for (const ll val : vals)
			{
				const pair<int, int> coors = split(val);
				if (coors.second < coor)
					nwset.insert(val);
				else
					nwset.insert(merge(coors.first, coor - (coors.second - coor)));
			}
		}
		vals = nwset;
	}
	//cout << vals.size() << endl;

	int xmx = 0, ymx = 0;
	for (const ll val : vals)
	{
		const pair<int, int> coors = split(val);
		xmx = max(xmx, coors.first);
		ymx = max(ymx, coors.second);
	}

	vector<bool> field((xmx + 1) * (ymx + 1));
	for (const ll val : vals)
	{
		const pair<int, int> coors = split(val);
		field[coors.second * (xmx + 1) + coors.first] = true;
	}

	for (int i = 0; i <= ymx; i++)
	{
		for (int j = 0; j <= xmx; j++)
		{
			cout << field[i * (xmx + 1) + j];
		}
		cout << endl;
	}



	return EXIT_SUCCESS;
}
