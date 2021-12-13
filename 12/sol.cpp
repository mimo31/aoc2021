#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

bool islnode(const string& s)
{
	return s[0] >= 'a' && s[0] <= 'z';
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	constexpr int m = 24;

	vector<string> lnodes;
	unordered_map<string, int> lnodemp;
	vector<vector<int>> lneis;

	vector<string> unodes;
	unordered_map<string, int> unodemp;
	vector<vector<int>> uneis;

	for (int i = 0; i < m; i++)
	{
		string from, to;
		cin >> from >> to;
		bool fl = islnode(from);
		bool tl = islnode(to);
		if (fl && !tl)
		{
			swap(fl, tl);
			swap(from, to);
		}
		if (!fl && !tl)
			continue;
		int ti;
		if (lnodemp.find(to) != lnodemp.end())
			ti = lnodemp[to];
		else
		{
			ti = lnodes.size();
			lnodes.push_back(to);
			lneis.push_back({});
			lnodemp[to] = ti;
		}
		if (fl)
		{
			int fi;
			if (lnodemp.find(from) != lnodemp.end())
				fi = lnodemp[from];
			else
			{
				fi = lnodes.size();
				lnodes.push_back(from);
				lneis.push_back({});
				lnodemp[from] = fi;
			}
			lneis[fi].push_back(ti);
			lneis[ti].push_back(fi);
		}
		else
		{
			int fi;
			if (unodemp.find(from) != unodemp.end())
				fi = unodemp[from];
			else
			{
				fi = unodes.size();
				unodes.push_back(from);
				uneis.push_back({});
				unodemp[from] = fi;
			}
			uneis[fi].push_back(ti);
		}
	}
	for (const vector<int>& neis : uneis)
	{
		for (int i = 0; i < neis.size(); i++)
		{
			for (int j = i; j < neis.size(); j++)
			{
				lneis[neis[i]].push_back(neis[j]);
				if (i != j)
					lneis[neis[j]].push_back(neis[i]);
			}
		}
	}
	vector<bool> visited(lnodes.size(), false);
	bool twice = false;
	const int starti = lnodemp["start"];
	const int endi = lnodemp["end"];
	int paths = 0;
	//vector<string> cpath;
	const auto visit = [&](const int v, const auto& visit_fun) -> void
	{
		if (v == endi)
		{
			/*
			for (const string& s : cpath)
				cout << s << ' ';
			cout << endl;
			*/
			paths++;
			return;
		}
		bool cleartwice = false;
		if (visited[v])
		{
			if (twice || v == starti)
				return;
			twice = true;
			cleartwice = true;
		}
		/*
		if (v == endi)
		{
			paths++;
			return;
		}
		*/
		visited[v] = true;
		//cpath.push_back(lnodes[v]);
		for (const int nei : lneis[v])
			visit_fun(nei, visit_fun);
		//cpath.pop_back();
		if (cleartwice)
			twice = false;
		else
			visited[v] = false;
	};
	visit(starti, visit);
	cout << paths << endl;
	return EXIT_SUCCESS;
}
