#include <bits/stdc++.h>
#include <bits/extc++.h>
std::ifstream fin("money.in");
std::ofstream fout("money.out");
int n, m, *a;
int MinR(int *s, int l)
{
	int k = 0, i = 0, j = 1;
	while (k < n && i < n && j < n)
	{
		if (s[(i + k) % n] == s[(j + k) % n])
			++k;
		else
		{
			if (s[(i + k) % n] > s[(j + k) % n])
				i = i + k + 1;
			else
				j = j + k + 1;
			if (i == j)
				++i;
			k = 0;
		}
	}
	i = std::min(i, j);
	return i;
}
void hash(unsigned long long &x, int *f, int *t)
{
	for (; f < t; ++f)
		x = x * 19260817 + *f;
	return;
}
__gnu_pbds::gp_hash_table<unsigned long long, bool> st;
int main()
{
	fin >> m >> n;
	a = new int[n];
	for (int i = 1; i <= m; i++)
	{
		for (int j = 0; j < n; j++)
			fin >> a[j];
		int p = MinR(a, n);
		std::cout << p << ' ' << a[p] << std::endl;
		unsigned long long h = 0;
		hash(h, a + p + 1, a + n);
		hash(h, a, a + p + 1);
		std::cout << h << std::endl;
		bool &f = st[h];
		if (f)
		{
			fout << "All the currency in circulation will be destroyed by Luke." << std::endl;
			return 0;
		}
		f = 1;
	}
	fout << "Soldier Xu is sleeping." << std::endl;
	delete[] a;
	return 0;
}