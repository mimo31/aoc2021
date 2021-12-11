#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	constexpr int l = 500;

	constexpr int sz = 1000;
	vector<int> cou(sz * sz, 0);
	for (int i = 0; i < l; i++)
	{
		int x0, y0, x1, y1;
		cin >> x0 >> y0 >> x1 >> y1;
		assert(x0 >= 0 && x1 >= 0 && y0 >= 0 && y1 >= 0);
		assert(x0 < sz && x1 < sz && y0 < sz && y1 < sz);
		const int dx = x1 - x0;
		const int dy = y1 - y0;
		const int g = gcd(dx, dy);
		const int dxx = dx / g;
		const int dyy = dy / g;
		for (int j = 0; j <= g; j++)
			cou[x0 + dxx * j + (y0 + dyy * j) * sz]++;
		/*
		if (x0 == x1)
			for (int y = min(y0, y1); y <= max(y0, y1); y++)
				cou[x0 + y * sz]++;
		else if (y0 == y1)
			for (int x = min(x0, x1); x <= max(x0, x1); x++)
				cou[x + y0 * sz]++;
				*/

	}
	int mults = 0;
	for (int i = 0; i < sz * sz; i++)
		if (cou[i] >= 2)
			mults++;
	cout << mults << endl;

	return EXIT_SUCCESS;
}
