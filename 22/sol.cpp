#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

struct cub
{
	bool posi;
	ll x0, x1, y0, y1, z0, z1;
};

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	//vector<bool> state(101 * 101 * 101, false);

	int n;
	cin >> n;
	vector<cub> cubs;
	ll lit = 0;
	for (int i = 0; i < n; i++)
	{
		string s;
		ll x0, x1, y0, y1, z0, z1;
		cin >> s >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
		assert(s == "on" || s == "off");
		if (s == "on")
		{
			const size_t sz = cubs.size();
			for (size_t j = 0; j < sz; j++)
			{
				const cub cc = cubs[j];
				const ll xx0 = max(x0, cc.x0);
				const ll xx1 = min(x1, cc.x1);
				const ll yy0 = max(y0, cc.y0);
				const ll yy1 = min(y1, cc.y1);
				const ll zz0 = max(z0, cc.z0);
				const ll zz1 = min(z1, cc.z1);
				if (xx0 > xx1 || yy0 > yy1 || zz0 > zz1)
					continue;
				if (cc.posi)
					lit -= (xx1 - xx0 + 1) * (yy1 - yy0 + 1) * (zz1 - zz0 + 1);
				else
					lit += (xx1 - xx0 + 1) * (yy1 - yy0 + 1) * (zz1 - zz0 + 1);
				cubs.push_back({ !cc.posi, xx0, xx1, yy0, yy1, zz0, zz1 });
			}
			cubs.push_back({ true, x0, x1, y0, y1, z0, z1 });
			lit += (x1 - x0 + 1) * (y1 - y0 + 1) * (z1 - z0 + 1);
		}
		else
		{
			const size_t sz = cubs.size();
			for (size_t j = 0; j < sz; j++)
			{
				const cub cc = cubs[j];
				const ll xx0 = max(x0, cc.x0);
				const ll xx1 = min(x1, cc.x1);
				const ll yy0 = max(y0, cc.y0);
				const ll yy1 = min(y1, cc.y1);
				const ll zz0 = max(z0, cc.z0);
				const ll zz1 = min(z1, cc.z1);
				if (xx0 > xx1 || yy0 > yy1 || zz0 > zz1)
					continue;
				if (cc.posi)
					lit -= (xx1 - xx0 + 1) * (yy1 - yy0 + 1) * (zz1 - zz0 + 1);
				else
					lit += (xx1 - xx0 + 1) * (yy1 - yy0 + 1) * (zz1 - zz0 + 1);
				cubs.push_back({ !cc.posi, xx0, xx1, yy0, yy1, zz0, zz1 });
			}
		}
		/*
		const bool v = s == "on";
		for (int x = max(x0, -50); x <= min(x1, 50); x++)
			for (int y = max(y0, -50); y <= min(y1, 50); y++)
				for (int z = max(z0, -50); z <= min(z1, 50); z++)
					state[(x + 50) * 101 * 101 + (y + 50) * 101 + z + 50] = v;
					*/
	}
	/*
	int cou = 0;
	for (const bool b : state)
		cou += b;
	*/
	cout << lit << endl;

	return EXIT_SUCCESS;
}
