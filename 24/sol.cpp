// AAR: this code was not useful for solving the problem and is probably not even correct

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

struct instr
{
	int code;

	int target;
	int argval;
	int argsrc;

	instr(const int code, const int target)
		: code(code), target(target)
	{
	}

	instr(const int code, const int target, const int argval, const int argsrc)
		: code(code), target(target), argval(argval), argsrc(argsrc)
	{
	}
};

void gettarget(int& tar)
{
	string tr;
	cin >> tr;
	tar = tr[0] - 'w';
}

void getarg(int& argval, int& argsrc)
{
	string arg;
	cin >> arg;
	if (arg[0] >= 'w' && arg[0] <= 'z')
	{
		argsrc = arg[0] - 'w';
	}
	else
	{
		argsrc = -1;
		stringstream ss(arg);
		ss >> argval;
	}
}

bool perform(const vector<instr>& instrs, const vector<int>& digs)
{
	ll regs[4] = { 0, 0, 0, 0 };
	int ndig = 0;
	for (const instr& inst : instrs)
	{
		const int cd = inst.code;
		if (cd == 0)
		{
			assert(ndig < 14);
			regs[inst.target] = digs[ndig];
			ndig++;
		}
		else if (cd == 1)
		{
			const int val = inst.argsrc == -1 ? inst.argval : regs[inst.argsrc];
			regs[inst.target] += val;
		}
		else if (cd == 2)
		{
			const int val = inst.argsrc == -1 ? inst.argval : regs[inst.argsrc];
			regs[inst.target] *= val;
		}
		else if (cd == 3)
		{
			const int val = inst.argsrc == -1 ? inst.argval : regs[inst.argsrc];
			if (val == 0)
			{
				cout << "div ha" << endl;
				return false;
			}
			regs[inst.target] /= val;
		}
		else if (cd == 4)
		{
			const int val = inst.argsrc == -1 ? inst.argval : regs[inst.argsrc];
			if (regs[inst.target] < 0 || val <= 0)
			{
				cout << "mod ha" << endl;
				return false;
			}
			regs[inst.target] %= val;
		}
		else if (cd == 5)
		{
			const int val = inst.argsrc == -1 ? inst.argval : regs[inst.argsrc];
			regs[inst.target] = regs[inst.target] == val;
		}
	}
	return !regs[3];
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<instr> instrs;

	for (int i = 0; i < n; i++)
	{
		string name;
		cin >> name;
		if (name == "inp")
		{
			int tr;
			gettarget(tr);
			instrs.push_back(instr(0, tr));
		}
		else if (name == "add")
		{
			int tr, aval, asrc;
			gettarget(tr);
			getarg(aval, asrc);
			instrs.push_back(instr(1, tr, aval, asrc));
		}
		else if (name == "mul")
		{
			int tr, aval, asrc;
			gettarget(tr);
			getarg(aval, asrc);
			instrs.push_back(instr(2, tr, aval, asrc));
		}
		else if (name == "div")
		{
			int tr, aval, asrc;
			gettarget(tr);
			getarg(aval, asrc);
			instrs.push_back(instr(3, tr, aval, asrc));
		}
		else if (name == "mod")
		{
			int tr, aval, asrc;
			gettarget(tr);
			getarg(aval, asrc);
			instrs.push_back(instr(4, tr, aval, asrc));
		}
		else if (name == "eql")
		{
			int tr, aval, asrc;
			gettarget(tr);
			getarg(aval, asrc);
			instrs.push_back(instr(5, tr, aval, asrc));
		}
		else
			assert(false);
	}

	vector<int> digs(14);
	for (int i = 0; 1; i++)
	{
		for (int j = 0; j < 14; j++)
			digs[j] = rand() % 9 + 1;
		const bool r = perform(instrs, digs);
		if (r)
		{
			for (const ll dg : digs)
				cout << dg;
			cout << ": " << r;
			cout << endl;
		}
	}
	/*
	fill(digs.begin(), digs.end(), 9);
	for (int i = 0; i < 100000; i++)
	{
		const bool r = perform(instrs, digs);
		if (r)
		{
			for (const ll dg : digs)
				cout << dg;
			cout << ": " << r;
			cout << endl;
		}
		digs[13]--;
		for (int j = 13; j >= 0; j--)
		{
			if (digs[j] == 0)
			{
				if (j != 0)
				{
					digs[j] = 9;
					digs[j - 1]--;
				}
			}
			else
				break;
		}
	}
	*/

	return EXIT_SUCCESS;
}
