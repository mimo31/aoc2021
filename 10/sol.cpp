#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int isopen(const char c)
{
	return c == '(' || c == '[' || c == '{' || c == '<';
}

int toint(const char c)
{
	if (c == '(' || c == ')')
		return 0;
	if (c == '[' || c == ']')
		return 1;
	if (c == '{' || c == '}')
		return 2;
	if (c == '<' || c == '>')
		return 3;
	assert(false);
	return 0;
}

int toscore(const char c)
{
	if (c == ')')
		return 3;
	if (c == ']')
		return 57;
	if (c == '}')
		return 1197;
	if (c == '>')
		return 25137;
	assert(false);
	return 0;
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	constexpr int n = 106;

	//ll score = 0;
	vector<ll> scores;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		stack<int> cuop;
		bool fail = false;
		for (const char c : s)
		{
			if (isopen(c))
				cuop.push(toint(c));
			else
			{
				assert(!cuop.empty());
				if (cuop.empty())
					break;
				const char tp = cuop.top();
				cuop.pop();
				if (tp != toint(c))
				{
					fail = true;
					break;
				}
			}
		}
		if (fail)
			continue;
		ll score = 0;
		while (!cuop.empty())
		{
			const int tp = cuop.top();
			cuop.pop();
			score = 5 * score + tp + 1;
		}
		if (score != 0)
			scores.push_back(score);
	}
	sort(scores.begin(), scores.end());
	cout << scores[scores.size() / 2] << endl;
	//cout << score << endl;

	return EXIT_SUCCESS;
}
