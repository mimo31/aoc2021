#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	constexpr int h = 100, w = 100;

	vector<int> heis(h * w);

	for (int i = 0; i < h; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < w; j++)
			heis[i * w + j] = s[j] - '0';
	}

	vector<int> szs;
	vector<bool> visited(w * h, false);

	const auto& visit = [&](const int x, const int y, const auto& visit_fun) -> void
	{
		if (x < 0 || x >= w || y < 0 || y >= h)
			return;
		if (heis[y * w + x] == 9)
			return;
		if (visited[y * w + x])
			return;
		visited[y * w + x] = true;
		szs.back()++;
		visit_fun(x - 1, y, visit_fun);
		visit_fun(x, y - 1, visit_fun);
		visit_fun(x + 1, y, visit_fun);
		visit_fun(x, y + 1, visit_fun);
	};

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (!visited[i * w + j])
			{
				szs.push_back(0);
				visit(j, i, visit);
			}

			/*
			const int ch = heis[i * w + j];
			if (i != 0 && heis[(i - 1) * w + j] <= ch)
				continue;
			if (i != h - 1 && heis[(i + 1) * w + j] <= ch)
				continue;
			if (j != 0 && heis[i * w + j - 1] <= ch)
				continue;
			if (j != w - 1 && heis[i * w + j + 1] <= ch)
				continue;
			sm += ch + 1;
			*/
		}
	}
	sort(szs.begin(), szs.end());
	cout << szs[szs.size() - 1] * szs[szs.size() - 2] * szs[szs.size() - 3] << endl;
	//cout << sm << endl;

	return EXIT_SUCCESS;
}
