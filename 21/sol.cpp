#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

struct state
{
	int p0, p1;
	int s0, s1;

	/*
	bool operator==(const state& other)
	{
		return p0 == other.p0 && p1 == other.p1 && s0 == s0.other && s1 == s1.other;
	}
	*/

	bool operator<(const state& other) const
	{
		if (p0 < other.p0)
			return true;
		if (p0 > other.p0)
			return false;
		if (p1 < other.p1)
			return true;
		if (p1 > other.p1)
			return false;
		if (s0 < other.s0)
			return true;
		if (s0 > other.s0)
			return false;
		return s1 < other.s1;
	}
};

map<state, pair<ll, ll>> cache;

void cou(const state& st)
{
	if (cache.find(st) != cache.end())
		return;
	pair<ll, ll> res = { 0, 0 };
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++)
			for (int k = 1; k <= 3; k++)
			{
				const int np0 = (st.p0 + i + j + k - 1) % 10 + 1;
				const int ns0 = st.s0 + np0;
				if (ns0 >= 21)
					res.first++;
				else
				{
					const state nst = { st.p1, np0, st.s1, ns0 };
					cou(nst);
					const pair<ll, ll> rs = cache[nst];
					res.first += rs.second;
					res.second += rs.first;
				}
			}
	cache[st] = res;
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int p0, p1;

	cin >> p0 >> p1;

	const state ist = { p0, p1, 0, 0 };

	cou(ist);
	const pair<ll, ll> rs = cache[ist];
	cout << rs.first << endl;
	cout << rs.second << endl;

	
	/*
	int s0 = 0, s1 = 0;

	for (int m = 0; ; m++)
	{
		p0 += (6 * m + 1 + 6 * m + 2 + 6 * m + 3);
		p0 = (p0 - 1) % 10 + 1;
		s0 += p0;
		if (s0 >= 1000)
		{
			cout << (6 * m + 3) * s1 << endl;
			break;
		}
		p1 += (6 * m + 4 + 6 * m + 5 + 6 * m + 6);
		p1 = (p1 - 1) % 10 + 1;
		s1 += p1;
		if (s1 >= 1000)
		{
			cout << (6 * m + 6) * s0 << endl;
			break;
		}
	}
	*/

	return EXIT_SUCCESS;
}
