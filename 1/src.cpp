#include <bits/stdc++.h>

using namespace std;

int main()
{
	constexpr int n = 2000;
	vector<int> vals(n);
	for (int i = 0; i < n; i++)
	{
		cin >> vals[i];
	}
	vector<int> wins(n - 2);
	for (int i = 0; i + 2 < n; i++)
		wins[i] = vals[i] + vals[i + 1] + vals[i + 2];
	int inc = 0;
	for (int i = 1; i + 2 < n; i++)
		if (wins[i] > wins[i - 1])
			inc++;
	cout << inc << endl;;
	return EXIT_SUCCESS;
}
