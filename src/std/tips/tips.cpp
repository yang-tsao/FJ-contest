#pragma GCC optimze(3)
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cassert>
#include <queue>
#include <cmath>
#define lowbit(x) (x & -x)
char s[1024] = "フリージア";
std::ifstream fin("tips.in");
std::ofstream fout("tips.out");
int n, m;
std::vector<std::vector<int>> G, lp, rp, anc;
std::vector<int> deep, dpstp, dpstv, bfs,ubfs;
std::vector<long long> ft;
void Dfs(int x)
{
	int sz = log2(deep[x] - 1);
	for (int i = 1; i <= sz; i++)
		anc[x][i] = anc[anc[x][i - 1]][i - 1];
	for (int son : G[x])
	{
		deep[son] = deep[x] + 1;
		dpstv[son] = deep[son];
		anc[son].resize(log2(deep[son] - 1) + 1);
		anc[son][0] = x;
		Dfs(son);
		if (dpstv[son] > dpstv[x])
		{
			dpstv[x] = dpstv[son];
			dpstp[x] = son;
		}
	}
	std::sort(G[x].begin(), G[x].end(),
			  [](int a, int b) { return dpstv[a] < dpstv[b]; });
	return;
}
int lpprsz(int x)
{
	return std::max(log2(dpstv[x] - deep[x]), 0.0);
}
int lprlsz(int x)
{
	return std::max(log2(dpstv[1] - deep[x]), 0.0);
}
void Dfs1(int x)
{
	for (int i = 0, ti = log2(deep[x] - 1); i <= ti; i++)
		if (lp[anc[x][i]][i] == 0)
			lp[anc[x][i]][i] = x;
	int sz = lpprsz(x);
	lp[x].resize(lprlsz(x) + 1);
	rp[x].resize(sz + 1);
	if (G[x].empty())
		return;
	lp[x][0] = G[x].front();
	rp[x][0] = G[x].back();
	for (int son : G[x])
		Dfs1(son);
	for (int i = 1; i <= sz; i++)
		rp[x][i] = rp[rp[x][i - 1]][i - 1];
	return;
}
void Dfs2(int x)
{
	if (G[x].empty())
		return;
	Dfs2(G[x].back());
	for (int i = bfs[x] - 1,sz=lprlsz(x); deep[ubfs[i]] == deep[x];--i)
		for (int j = 0; j <= sz;j++)
			if(!lp[ubfs[i]][j])
				lp[ubfs[i]][j] = lp[ubfs[i + 1]][j];
	return;
}
int get_lp(int x, int d)
{
	for (int i = log2(d); i >= 0; i--)
		if (d & 1 << i)
			x = lp[x][i];
	return x;
}
int get_rp(int x, int d)
{
	for (int i = log2(d); i >= 0; i--)
		if (d & 1 << i)
			x = rp[x][i];
	return x;
}
void f_add(int x, long long v)
{
	do
	{
		ft[x] += v;
		x += lowbit(x);
	} while (x <= n);
	return;
}
long long f_sum(int x)
{
	long long res = 0;
	do
	{
		res += ft[x];
		x -= lowbit(x);
	} while (x);
	return res;
}
int main()
{
	fin >> n;
	{ //Init vector size
		anc.resize(n + 1);
		lp.resize(n + 1);
		rp.resize(n + 1);
		G.resize(n + 1);
		deep.resize(n + 1);
		dpstv.resize(n + 1);
		dpstp.resize(n + 1);
		bfs.resize(n + 1);
		ubfs.resize(n + 1);
		ft.resize(n + 2);
	}
	for (int i = 1, a, b; i < n; i++) //Build Tree
	{
		fin >> a >> b;
		G[a].push_back(b);
	}
	{ //Dfs
		dpstp[1] = 1;
		deep[1] = 1;
		Dfs(1);
	}
	{ //Bfs
		std::queue<int> q;
		q.push(1);
		for (int cnt = 1; !q.empty(); ++cnt)
		{
			int x = q.front();
			q.pop();
			bfs[x] = cnt;
			ubfs[cnt] = x;
			for (int son : G[x])
				q.push(son);
		}
	}
	Dfs1(1);
	/*for (int i = 1; i <= n; i++)
	{
		fout << "i=" << i << std::endl;
		for (int j = 0, tj = lprlsz(i);
			 j <= tj; j++)
			fout << lp[i][j] << '\t';
		fout << std::endl;
	}
	fout << "After  2" << std::endl;*/
	Dfs2(1);
	/*for (int i = 1; i <= n; i++)
	{
		fout << "i=" << i << std::endl;
		for (int j = 0, tj = lprlsz(i);
			 j <= tj; j++)
			fout << lp[i][j] << '\t';
		fout << std::endl;
	}*/
	fin >> m;
	for (int op, i = 1, a, b, c; i <= m; i++)
	{
		//fout << "i=" << i << std::endl;
		fin >> op;
		if (op == 1)
		{
			fin >> a >> b >> c;
			int l = get_lp(a, b);
			int r = get_rp(a, b);
		//	fout << "l=" << l << " r=" << r << std::endl;
		//	fout << "bfs l" << bfs[l] << " bfs r" << bfs[r] << std::endl;
			f_add(bfs[l], c);
			f_add(bfs[r] + 1, -c);
		}
		else
		{
			fin >> a;

			fout << f_sum(bfs[a]) << std::endl;
		}
	}
	fin.close();
	fout.close();
	return 0;
}