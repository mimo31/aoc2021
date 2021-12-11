#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	constexpr int n = 1000;

	vector<int> poss(n);
	int su = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> poss[i];
		su += poss[i];
	}
	int mn = poss[0];
	int mx = poss[n - 1];
	for (int i = 0; i < n; i++)
	{
		mn = min(mn, poss[i]);
		mx = max(mx, poss[i]);
	}
	int best = numeric_limits<int>::max();
	for (int p = mn; p <= mx; p++)
	{
		int cur = 0;
		for (int i = 0; i < n; i++)
		{
			int d;
			if (poss[i] < p)
				d = p - poss[i];
			else
				d = poss[i] - p;
			cur += d * (d + 1) / 2;
			//cur += (poss[i] - p) * (poss[i] - p - );
		}
		best = min(best, cur);
	}
	cout << best << endl;
	/*
	const int c0 = su / n;
	const int c1 = (su - 1) / n + 1;
	int co0 = 0;
	int co1 = 0;
	for (int i = 0; i < n; i++)
	{
		co0 += (poss[i] - c0) * (poss[i] - c0);
		co1 += (poss[i] - c1) * (poss[i] - c1);
	}
	*/
	/*
	sort(poss.begin(), poss.end());
	const int med = poss[n / 2];
	int sm = 0;
	for (int i = 0; i < n; i++)
		if (med < poss[i])
			sm += poss[i] - med;
		else
			sm += med - poss[i];
	*/
	//cout << min(co0, co1) << endl;

	return EXIT_SUCCESS;
}
