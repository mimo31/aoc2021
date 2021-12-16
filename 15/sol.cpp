#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

struct rch
{
	int i;
	int j;
	ll cost;

	bool operator<(const rch& other) const
	{
		return cost > other.cost;
	}
};

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	constexpr int n = 100;

	vector<ll> costs(25 * n * n);

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int ii = 0; ii < 5; ii++)
		{
			for (int j = 0; j < n; j++)
			{
				for (int jj = 0; jj < 5; jj++)
				{
					costs[(ii * n + i) * 5 * n + jj * n + j] = (s[j] - '0' + ii + jj - 1) % 9 + 1;
				}
			}
		}
	}
	constexpr ll inf = numeric_limits<ll>::max();

	vector<ll> shorts(25 * n * n, inf);
	shorts[0] = 0;
	priority_queue<rch> qq;
	qq.push({ 0, 0, 0 });
	vector<bool> visited(25 * n * n, false);
	while (!qq.empty())
	{
		const rch cur = qq.top();
		qq.pop();
		if (visited[cur.i * 5 * n + cur.j])
			continue;
		visited[cur.i * 5 * n + cur.j] = true;
		for (int i = max(cur.i - 1, 0); i <= min(cur.i + 1, 5 * n - 1); i++)
		{
			for (int j = max(cur.j - 1, 0); j <= min(cur.j + 1, 5 * n - 1); j++)
			{
				if (!(i == cur.i || j == cur.j))
					continue;
				if (i == cur.i && j == cur.j)
					continue;
				shorts[i * 5 * n + j] = min(shorts[i * 5 * n + j], shorts[cur.i * 5 * n + cur.j] + costs[i * 5 * n + j]);
				qq.push({ i, j, shorts[i * 5 * n + j] });
			}
		}
	}
	cout << shorts[25 * n * n - 1] << endl;
	return 0;
	//shorts[0] = inf;
	

	/*
	shorts[0] = 0;
	for (int j = 1; j < 5 * n; j++)
		shorts[j] = costs[j] + shorts[j - 1];
	for (int i = 1; i < 5 * n; i++)
	{
		shorts[i * 5 * n] = costs[i * 5 * n] + shorts[(i - 1) * 5 * n];
		for (int j = 1; j < 5 * n; j++)
		{
			shorts[i * 5 * n + j] = costs[i * 5 * n + j] + min(shorts[(i - 1) * 5 * n + j], shorts[i * 5 * n + j - 1]);
		}
	}
	cout << shorts[25 * n * n - 1] << endl;
	*/

	/*

	constexpr int mm = 10;

	vector<ll> costs2p(mm * mm);
	for (int i = 0; i < mm; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < mm; j++)
			costs2p[i * mm + j] = s[j] - '0';
	}

	constexpr int m = mm * 5;

	vector<ll> costs2(m * m);

	for (int ii = 0; ii < 5; ii++)
	{
		for (int jj = 0; jj < 5; jj++)
		{
			for (int i = 0; i < mm; i++)
			{
				for (int j = 0; j < mm; j++)
				{
					ll val = costs2p[i * mm + j] + ii + jj;
					while (val > 9)
						val -= 9;
					costs2[(ii * mm + i) * m + jj * mm + j] = val;
				}
			}
		}
	}

	assert(costs == costs2);
	*/


	/*
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			ll val = costsp[(i % nn) * nn + j % nn] + i / nn + j / nn;
			while (val > 9)
				val -= 9;
			costs[i * n + j] = val;// > 9 ? val - 9 : val;
		}
	}
	*/

	/*
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << costs[i * n + j];
		cout << endl;
	}

	cout << n << endl;

	vector<ll> shorts(n * n);
	shorts[0] = 0;
	for (int j = 1; j < n; j++)
		shorts[j] = shorts[j - 1] + costs[j];
	for (int i = 1; i < n; i++)
	{
		shorts[i * n] = shorts[(i - 1) * n] + costs[i * n];
		for (int j = 1; j < n; j++)
			shorts[i * n + j] = costs[i * n + j] + min(shorts[(i - 1) * n + j], shorts[i * n + j - 1]);
	}
	cout << shorts[n * n - 1] << endl;
	*/

	return EXIT_SUCCESS;
}
