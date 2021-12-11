#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	constexpr int n = 1000;

	ll hor = 0, depth = 0;
	ll aim = 0;

	for (int i = 0; i < n; i++)
	{
		string s;
		ll x;
		cin >> s >> x;
		if (s == "forward")
		{
			hor += x;
			depth += aim * x;
		}
		else if (s == "down")
			aim += x;
		else if (s == "up")
			aim -= x;
		else
			assert(false);
	}

	cout << hor * depth << endl;


	return EXIT_SUCCESS;
}
