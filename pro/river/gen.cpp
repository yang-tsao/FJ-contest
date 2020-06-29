#include <bits/stdc++.h>
int main()
{
	std::ifstream fin("pro.dat");
	int n, m;
	for (int i = 1; fin >> n >> m; ++i)
	{
		std::ofstream fout("river.in");
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_real_distribution<long double> dis(0.L, sqrt(2.L) / 2.L);
		fout << n << '\n'
			 << m << '\n';
		long double v;
		do
		{
			v = dis(gen);
			fout << v << '\n';
		} while (--n);
		fout.close();
		std::cout << "Generating Out " << i << std::endl;
		system("./sol");
		std::rename("river.out", ("river" + std::to_string(i) + ".out").c_str());
		std::rename("river.in", ("river" + std::to_string(i) + ".in").c_str());
	}
	system("mv *.in *.out data/");
	return 0;
}