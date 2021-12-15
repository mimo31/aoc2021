#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	constexpr int r = 100;

	string pol;
	cin >> pol;
	unordered_map<string, char> rules;
	for (int i = 0; i < r; i++)
	{
		string s0, s1, s2;
		cin >> s0 >> s1 >> s2;
		assert(s1 == "->");
		assert(s2.size() == 1);
		rules[s0] = s2[0];
	}
	unordered_map<string, ll> pcous;
	for (int i = 1; i < pol.size(); i++)
	{
		const char chstr[3] = { pol[i - 1], pol[i], '\0' };
		const string str(chstr);
		pcous[str]++;
	}
	for (int i = 0; i < 40; i++)
	{
		unordered_map<string, ll> nwpcous;
		for (const auto& entry : pcous)
		{
			const char intr = rules[entry.first];
			const char chstr0[3] = { entry.first[0], intr, '\0' };
			const char chstr1[3] = { intr, entry.first[1], '\0' };
			const string str0(chstr0);
			const string str1(chstr1);
			nwpcous[str0] += entry.second;
			nwpcous[str1] += entry.second;
		}
		pcous = nwpcous;
	}
	/*
	vector<char> chr;
	for (const char c : pol)
		chr.push_back(c);
	for (int i = 0; i < 10; i++)
	{
		vector<char> nchr;
		nchr.push_back(chr.front());
		for (int j = 1; j < chr.size(); j++)
		{
			char chstr[3] = { chr[j - 1], chr[j], '\0' };
			string str(chstr);
			nchr.push_back(rules[str]);
			nchr.push_back(chr[j]);
		}
		chr = nchr;
	}
	*/
	unordered_map<char, ll> counts;
	for (const auto& entry : pcous)
	{
		counts[entry.first[0]] += entry.second;
		counts[entry.first[1]] += entry.second;
	}
	counts[pol[0]]++;
	counts[pol.back()]++;
	/*
	for (const char c : chr)
		counts[c]++;
		*/
	ll mx = 0, mn = numeric_limits<ll>::max();
	for (const auto& entry : counts)
	{
		mx = max(mx, entry.second);
		mn = min(mn, entry.second);
	}
	cout << (mx - mn) / 2 << endl;

	return EXIT_SUCCESS;
}
