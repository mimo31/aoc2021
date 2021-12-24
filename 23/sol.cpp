#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

struct state
{
	int hall[7];
	int rooms[16];

	state()
	{
		fill(hall, hall + 7, 0);
		fill(rooms, rooms + 16, 0);
	}

	state(uint64_t num)
	{
		for (int i = 16; i >= 0; i--)
		{
			rooms[i] = num % 5;
			num /= 5;
		}
		for (int i = 7; i >= 0; i--)
		{
			hall[i] = num % 5;
			num /= 5;
		}
	}

	uint64_t num() const
	{
		uint64_t val = 0;
		for (int i = 0; i < 7; i++)
			val = val * 5 + hall[i];
		for (int i = 0; i < 16; i++)
			val = val * 5 + rooms[i];
		return val;
	}
};

struct rch
{
	state st;
	ll rin;

	bool operator<(const rch& other) const
	{
		return rin > other.rin;
	}
};

priority_queue<rch> qq;

ll best = numeric_limits<ll>::max();

unordered_map<uint64_t, ll> reached;

void submit(const state& st, const ll rin)
{
	const uint64_t num = st.num();
	if (reached.find(num) == reached.end() || reached[num] > rin)
	{
		reached[num] = rin;
		qq.push({ st, rin });
	}
}

const ll costs[] = {
	0,
	1,
	10,
	100,
	1000
};

void visit(const rch& cur)
{
	const state st = cur.st;
	bool done = true;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			if (st.rooms[4 * i + j] != i + 1)
			{
				done = false;
				break;
			}
	}
	if (done)
	{
		best = min(best, cur.rin);
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		bool stranger = false;
		for (int j = 0; j < 4; j++)
		{
			if (st.rooms[4 * i + j] != 0 && st.rooms[4 * i + j] != i + 1)
			{
				stranger = true;
				break;
			}
		}
		if (!stranger)
			continue;
		int mi = 3;
		while (st.rooms[4 * i + mi] == 0)
			mi--;
		const int rr = st.rooms[4 * i + mi];
		{
			int le = i + 1;
			ll stp = 2 + (3 - mi);
			while (le >= 0 && st.hall[le] == 0)
			{
				state nwst = st;
				nwst.rooms[4 * i + mi] = 0;
				nwst.hall[le] = rr;
				submit(nwst, stp * costs[rr] + cur.rin);
				le--;
				stp++;
				if (le != 0)
					stp++;
			}
		}
		{
			int ri = i + 2;
			ll stp = 2 + (3 - mi);
			while (ri <= 6 && st.hall[ri] == 0)
			{
				state nwst = st;
				nwst.rooms[4 * i + mi] = 0;
				nwst.hall[ri] = rr;
				submit(nwst, stp * costs[rr] + cur.rin);
				ri++;
				stp++;
				if (ri != 6)
					stp++;
			}
		}
	}
	for (int i = 0; i < 7; i++)
	{
		if (st.hall[i] == 0)
			continue;
		const int n = st.hall[i];
		bool stranger = false;
		for (int j = 0; j < 4; j++)
		{
			if (st.rooms[4 * (n - 1) + j] != 0 && st.rooms[4 * (n - 1) + j] != n)
			{
				stranger = true;
				break;
			}
		}
		if (stranger)
			continue;
		int mt = 3;
		while (mt > 0 && st.rooms[4 * (n - 1) + mt - 1] == 0)
			mt--;
		ll stp = 2 + (3 - mt);
		bool fail = false;
		if (i <= n)
		{
			for (int j = i + 1; j <= n; j++)
			{
				if (st.hall[j] != 0)
				{
					fail = true;
					break;
				}
				stp++;
				if (j != 1)
					stp++;
			}
		}
		else
		{
			for (int j = i - 1; j >= n + 1; j--)
			{
				if (st.hall[j] != 0)
				{
					fail = true;
					break;
				}
				stp++;
				if (j != 5)
					stp++;
			}
		}
		if (fail)
			continue;
		state nwst = st;
		nwst.hall[i] = 0;
		nwst.rooms[4 * (n - 1) + mt] = n;
		submit(nwst, stp * costs[n] + cur.rin);
	}
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	assert(s.length() == 16);
	state init;
	for (int i = 0; i < 16; i++)
		init.rooms[i] = s[i] - 'A' + 1;

	qq.push({ init, 0 });
	reached[init.num()] = 0;

	while (!qq.empty())
	{
		const rch cur = qq.top();
		qq.pop();
		if (cur.rin == reached[cur.st.num()])
			visit(cur);
	}
	cout << best << endl;


	return EXIT_SUCCESS;
}
