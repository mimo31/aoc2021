#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

uint64_t merge(const int a0, const int a1)
{
	return (((uint64_t)a0) << 32) | a1;
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int x0, x1, y0, y1;
	cin >> x0 >> x1 >> y0 >> y1;
	//int best = 0;
	//unordered_set<uint64_t> vels;
	int cou = 0;
	for (int i = -2048; i < 2048; i++)
	{
		int yv = i;
		int yp = 0;
		int fst = numeric_limits<int>::max();
		int lst = numeric_limits<int>::min();
		int ymx = 0;
		for (int st = 0; ; st++)
		{
			yp += yv;
			yv--;
			ymx = max(ymx, yp);
			if (yp <= y1 && yp >= y0)
			{
				fst = min(fst, st);
				lst = max(lst, st);
			}
			if (yp < y0)
				break;
		}
		if (fst == numeric_limits<int>::max())
			continue;
		for (int i = 0; i < 512; i++)
		{
			int xp = 0;
			int xv = i;
			bool poss = false;
			for (int st = 0; st <= lst; st++)
			{
				xp += xv;
				if (xv != 0)
					xv--;
				if (st >= fst && st <= lst && xp >= x0 && xp <= x1)
				{
					cou ++;
					break;
					//best = max(best, ymx);
					//vels.push_back(merge(
				}
				if (xv == 0)
				{
					if (xp >= x0 && xp <= x1)
					{
						//best = max(best, ymx);
						cou++;
					}
					break;
				}
			}
			if (poss)
				break;
		}
	}
	cout << cou << endl;
	//cout << best << endl;

	return EXIT_SUCCESS;
}
