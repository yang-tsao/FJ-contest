#include <bits/stdc++.h>
int n, m;
std::ifstream fin("tips.in");
std::ofstream fout("tips.out");
std::vector<int> fa;
std::vector<std::map<int, int>> GT;
int main()
{
	fin >> n;
	fa.resize(n + 1);
	GT.assign(n + 1, std::map<int, int>());
	fa[0] = 0;
	fa[1] = 0;
	for (int i = 2, a, b; i <= n; ++i)
	{
		fin >> a >> b;
		fa[b] = a;
	}

	fin >> m;
	for (int i = 1, op, a, b, c; i <= m; ++i)
	{
		fin >> op;
		if (op == 1)
		{
			fin >> a >> b >> c;
			GT[a][b] += c;
		}
		else
		{
			fin >> a;
			int ans = 0;
			for (int j = 0; a; a = fa[a], ++j)
			{
				auto it = GT[a].find(j);
				if (it == GT[a].end())
					continue;
				else
					ans += it->second;
			}
			fout << ans << '\n';
		}
	}
	return 0;
}