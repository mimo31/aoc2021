#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	vector<bool> bits;
	for (const char c : s)
	{
		const int val = (c >= '0' && c <= '9') ? c - '0' : c - 'A' + 10;
		bits.push_back(val / 8);
		bits.push_back(val / 4 % 2);
		bits.push_back(val / 2 % 2);
		bits.push_back(val % 2);
	}

	int sm = 0;

	int nxt = 0;

	const auto readpck = [&](const auto& readpck_fun) -> ll
	{
		const int vers = bits[nxt] * 4 + bits[nxt + 1] * 2 + bits[nxt + 2];
		nxt += 3;
		const int typ = bits[nxt] * 4 + bits[nxt + 1] * 2 + bits[nxt + 2];
		nxt += 3;
		sm += vers;
		if (typ == 4)
		{
			ll val = 0;
			while (bits[nxt])
			{
				for (int i = 0; i < 4; i++)
					val = val * 2 + bits[nxt + 1 + i];
				nxt += 5;
			}
			for (int i = 0; i < 4; i++)
				val = val * 2 + bits[nxt + 1 + i];
			nxt += 5;
			return val;
		}
		else
		{
			const bool lid = bits[nxt];
			nxt++;
			vector<ll> args;
			if (lid)
			{
				int num = 0;
				for (int i = 0; i < 11; i++)
					num = 2 * num + bits[nxt++];
				for (int i = 0; i < num; i++)
					args.push_back(readpck_fun(readpck_fun));
			}
			else
			{
				int num = 0;
				for (int i = 0; i < 15; i++)
					num = 2 * num + bits[nxt++];
				int stopind = nxt + num;
				while (nxt != stopind)
					args.push_back(readpck_fun(readpck_fun));
			}
			assert(!args.empty());
			if (typ == 0)
			{
				ll sm = 0;
				for (const ll a : args)
					sm += a;
				return sm;
			}
			else if (typ == 1)
			{
				ll prod = 1;
				for (const ll a : args)
					prod *= a;
				return prod;
			}
			else if (typ == 2)
			{
				ll mn = numeric_limits<ll>::max();
				for (const ll a : args)
					mn = min(mn, a);
				return mn;
			}
			else if (typ == 3)
			{
				ll mx = numeric_limits<ll>::min();
				for (const ll a : args)
					mx = max(mx, a);
				return mx;
			}
			else if (typ == 5)
			{
				assert(args.size() == 2);
				return args[0] > args[1];
			}
			else if (typ == 6)
			{
				assert(args.size() == 2);
				return args[0] < args[1];
			}
			else if (typ == 7)
			{
				assert(args.size() == 2);
				return args[0] == args[1];
			}
			assert(false);
		}
	};

	cout << readpck(readpck) << endl;

	//cout << sm << endl;

	return EXIT_SUCCESS;
}
