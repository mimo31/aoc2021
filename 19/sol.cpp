#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

struct vec3
{
	int c[3];

	vec3 operator+(const vec3& a) const
	{
		return { c[0] + a.c[0], c[1] + a.c[1], c[2] + a.c[2] };
	}

	vec3 operator-(const vec3& a) const
	{
		return { c[0] - a.c[0], c[1] - a.c[1], c[2] - a.c[2] };
	}

	int& operator[](const int i)
	{
		return c[i];
	}

	const int& operator[](const int i) const
	{
		return c[i];
	}

	bool operator<(const vec3& other) const
	{
		if (c[0] < other[0])
			return true;
		if (c[0] > other[0])
			return false;
		if (c[1] < other[1])
			return true;
		if (c[1] > other[1])
			return false;
		return c[2] < other[2];
	}
};

const vec3 V0 = { { 0, 0, 0 } };

struct trans
{
	int mat[3][3];
	vec3 trl;

	vec3 operator*(const vec3& a) const
	{
		vec3 mu = V0;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				mu[i] += mat[i][j] * a[j];
		return mu + trl;
	}

	trans operator*(const trans& t) const
	{
		trans nw;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
			{
				nw.mat[i][j] = 0;
				for (int k = 0; k < 3; k++)
					nw.mat[i][j] += mat[i][k] * t.mat[k][j];
			}
		nw.trl = *this * t.trl;
		return nw;
	}

	bool operator==(const trans& t) const
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
				if (mat[i][j] != t.mat[i][j])
					return false;
			if (trl[i] != t.trl[i])
				return false;
		}
		return true;
	}
};

const trans T0 = {
	{ { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } },
	V0
};

/*
void zeroout(trans& t)
{
	t.mat[0][0] = 0;
	t.mat[0][1] = 0;
	t.mat[0][2] = 0;
	t.mat[1][0] = 0;
	t.mat[1][1] = 0;
	t.mat[1][2] = 0;
	t.mat[2][0] = 0;
	t.mat[2][1] = 0;
	t.mat[2][2] = 0;
}
*/

trans purerot(const int i)
{
	trans t = T0;
	const int rt = i % 3;
	const int fl = i % 4;
	for (int j = 0; j < 3; j++)
		t.mat[j][(j + rt) % 3] = (fl == 3 || fl == j) ? 1 : -1;
	if (i > 12)
	{
		for (int k = 0; k < 3; k++)
		{
			swap(t.mat[0][k], t.mat[1][k]);
			t.mat[2][k] *= -1;
		}
	}
	return t;
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	vector<vector<vec3>> scnd;

	string ln;
	while (getline(cin, ln))
	{
		if (ln.size() <= 1)
			continue;
		if (ln[0] == '-' && ln[1] == '-')
		{
			scnd.push_back({});
			continue;
		}
		stringstream ss(ln);
		int x, y, z;
		ss >> x >> y >> z;
		scnd.back().push_back({ { x, y, z } });
	}

	const int n = scnd.size();

	vector<vector<pair<int, trans>>> neis(n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				continue;
			for (const vec3 b0 : scnd[i])
			{
				for (const vec3 b1 : scnd[j])
				{
					for (int k = 0; k < 24; k++)
					{
						trans tra = purerot(k);
						const vec3 b0im = tra * b0;
						tra.trl = b1 - b0im;
						set<vec3> im0;
						for (const vec3 b : scnd[i])
							im0.insert(tra * b);
						int intersz = 0;
						for (const vec3 b : scnd[j])
							if (im0.find(b) != im0.end())
								intersz++;
						//cout << intersz << endl;
						if (intersz >= 12)
						{
							neis[j].push_back({ i, tra });
							cout << i << " visited from " << j << endl;
						}
					}
				}
			}
		}
	}

	vector<trans> trs(n);
	vector<bool> visited(n, false);

	const auto dfs = [&](const int i, const trans tra, const auto& dfs_fun) -> void
	{
		if (i != 0)
			assert(tra.trl[0] != 0 || tra.trl[1] != 0 || tra.trl[2] != 0);
		if (visited[i])
		{
			assert(tra == trs[i]);
			return;
		}
		visited[i] = true;
		trs[i] = tra;
		for (const pair<int, trans>& nei : neis[i])
			dfs_fun(nei.first, tra * nei.second, dfs_fun);
	};

	dfs(0, purerot(3), dfs);

	for (int i = 0; i < n; i++)
	{
		cout << i << ": " << trs[i].trl[0] << " " << trs[i].trl[1] << " " << trs[i].trl[2] << endl;
	}

	int mxd = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			const vec3 diff = trs[i].trl - trs[j].trl;
			mxd = max(mxd, abs(diff[0]) + abs(diff[1]) + abs(diff[2]));
		}
	}
	cout << mxd << endl;

	for (int i = 0; i < n; i++)
		assert(visited[i]);

	set<vec3> alb;
	for (int i = 0; i < n; i++)
	{
		for (const vec3 b : scnd[i])
			alb.insert(trs[i] * b);
	}

	cout << alb.size() << endl;

	return EXIT_SUCCESS;
}
