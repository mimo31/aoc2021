#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int l = 12;//5;//12;
	int n = 1000;//12;//1000;
	vector<string> strs(n);
	for (int i = 0; i < n; i++)
		cin >> strs[i];
	vector<string> oxs = strs;
	for (int j = 0; j < l; j++)
	{
		assert(!oxs.empty());
		if (oxs.size() == 1)
			break;
		int cou = 0;
		for (const string& s : oxs)
			if (s[j] == '1')
				cou++;
		vector<string> nw;
		if (cou >= (oxs.size() - cou))
		{
			for (const string& s : oxs)
				if (s[j] == '1')
					nw.push_back(s);
		}
		else
		{
			for (const string& s : oxs)
				if (s[j] != '1')
					nw.push_back(s);
		}
		oxs = nw;
	}
	vector<string> cos = strs;
	for (int j = 0; j < l; j++)
	{
		assert(!cos.empty());
		if (cos.size() == 1)
			break;
		int cou = 0;
		for (const string& s : cos)
			if (s[j] == '1')
				cou++;
		vector<string> nw;
		if (cou >= (cos.size() - cou))
		{
			for (const string& s : cos)
				if (s[j] != '1')
					nw.push_back(s);
		}
		else
		{
			for (const string& s : cos)
				if (s[j] == '1')
					nw.push_back(s);
		}
		cos = nw;
	}
	assert(oxs.size() == 1);
	assert(cos.size() == 1);
	int val = 0;
	int val2 = 0;
	//cout << oxs[0] << endl;
	//cout << cos[0] << endl;
	for (int j = 0; j < l; j++)
	{
		val *= 2;
		val2 *= 2;
		if (oxs[0][j] == '1')
			val++;
		if (cos[0][j] == '1')
			val2++;
	}
	cout << val * val2 << endl;
	//cout << val2 << endl;
	/*
	vec
	vector<int> cous(l, 0);
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < l; j++)
			if (s[j] == '1')
				cous[j]++;
	}
	int val = 0;
	int val2 = 0;
	for (int j = 0; j < l; j++)
	{
		val *= 2;
		val2 *= 2;
		if (cous[j] <= n / 2)
			val++;
		else
			val2++;
	}
	//cout << val << endl;
	//cout << val2 << endl;
	cout << val * val2 << endl;
	*/
	return EXIT_SUCCESS;
}
