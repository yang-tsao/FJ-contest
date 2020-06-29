#include <fstream>
#include <cstdio>
#include <vector>
#include <list>
#include <algorithm>
#include <filesystem>
#include <iostream>
#include <random>
std::string name = "tips";
char tmp[256];
std::ifstream fin("tips.dat");
std::vector<std::list<int>> G;
std::vector<int> deep, mxdp, deep_p;
void Dfs(int x)
{
	mxdp[x] = deep[x];
	for (int son : G[x])
	{
		Dfs(son);
		mxdp[x] = std::max(mxdp[x], mxdp[son]);
	}
	return;
}
void sv(std::string id, int n, int m)
{
	std::default_random_engine random(clock());
	std::ofstream fout("tips.in");
	std::cout << "id=" << id << " n=" << n << " m=" << m << std::endl;
	fout << n << '\n';
	G.assign(n + 1, std::list<int>());
	mxdp.assign(n + 1, 0);
	deep.assign(n + 1, 0);
	deep_p.resize(n + 1);
	for (int i = 0; i <= n; ++i)
		deep_p[i] = i;
	deep[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		int fa;
		if (random() % 300 == 0)
			fa = random() % (i - 1) + 1;
		else
			fa = i - 1;
		fout << fa << ' ' << i << '\n';
		G[fa].push_back(i);
		deep[i] = deep[fa] + 1;
	}
	Dfs(1);
	std::cout << "Deep=" << mxdp[1] << std::endl;
	fout << m << '\n';
	std::sort(deep_p.begin(), deep_p.end(), [](int a, int b) { return deep[a] > deep[b]; });
	for (int i = 1, _n = n / 3,__n=std::min(n/5,100); i <= m; i++)
	{
		if (random() % 2)
			fout << "2 " << deep_p[random() % __n] << '\n';
		else
		{
		bg:
			int p = random() % _n + 1;
			int d = mxdp[p] - deep[p];
			if (d > 10)
				d -= random() % 10;
			else if (d < 5)
				goto bg;
			int va = random() % 1024;
			fout << "1 ";
			fout << p << ' ' << d << ' ' << va << '\n';
		}
	}
	fout.close();
	std::cout << "Generating out" << std::endl;
	system("./tips");
	std::rename((name + ".in").c_str(), (name + id + ".in").c_str());
	std::rename((name + ".out").c_str(), (name + id + ".out").c_str());
	return;
}
int main()
{
	for (int i = 1, a, b; fin >> a >> b; i++)
		sv(std::to_string(i), a, b);
	system("mv *.in *.out data");
	return 0;
}