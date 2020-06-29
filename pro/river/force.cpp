#include <bits/stdc++.h>
std::ifstream fin("river.in");
std::ofstream fout("river.out");
int main()
{
	int n, m;
	fin >> n >> m;
	fout << std::setprecision(m) << std::fixed;
	long double v, l, r;
	const long double eps = powl(10.L, -(m + 3));
	long double lm, rm, lf, rf;
	if (n <= 100000) //比较慢的较高精度来得及
		do
		{
			l = 0.L;
			r = 1.L;
			fin >> v;
			while (r - l > eps)
			{
				lm = fmal(r - l, 0.25L, l);
				rm = fmal(r - l, -0.25L, r);
				lf = fmal(-lm, v, sqrtl(fmal(lm, lm, 1.L)));
				rf = fmal(-rm, v, sqrtl(fmal(rm, rm, 1.L)));
				if (lf > rf)
					l = lm;
				else
					r = rm;
			}
			fout << l << '\n';
		} while (--n);
	else//直接放弃
		return 0;
	return 0;
}