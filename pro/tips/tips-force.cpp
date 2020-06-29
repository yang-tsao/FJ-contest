#include <fstream>
#include <vector>
#include <list>
std::ifstream fin("tips.in");
std::ofstream fout("tips.out");
int n, m;
std::vector<std::list<int>> G;
std::vector<int> v;
void add(int x, int d, int va)
{
	if (d == 0)
	{
		v[x] += va;
		return;
	}
	for (int son : G[x])
		add(son, d - 1, va);
	return;
}
int main()
{
	fin >> n;
	G.resize(n + 1);
	v.resize(n + 1);
	for (int i = 1, a, b; i < n; i++)
	{
		fin >> a >> b;
		G[a].push_back(b);
	}
	fin >> m;
	for (int i = 1, op, a, b, c; i <= m; i++)
	{
		fin >> op;
		if (op == 1)
		{
			fin >> a >> b >> c;
			add(a, b, c);
		}
		else
		{
			fin >> a;
			fout << v[a] << std::endl;
		}
	}
	return 0;
}