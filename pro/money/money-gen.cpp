#include <bits/stdc++.h>
std::ifstream fin("money.dat");
std::ofstream fout;
std::string name = "money";
void sv(std::string id, int m, int n)
{
	std::cout << "ID=" << id << std::endl;
	std::default_random_engine random(clock());
	fout.open("money.in");
	std::ofstream fans("money" + id + ".out");
	fout << m << '\n'
		 << n << '\n';
	int *a = new int[n];
	for (int j = 0; j < n; j++)
		a[j] = random();
	if (id.back() % 2)
	{
		std::cout << "Dandan Active" << std::endl;
		for (int i = 1, _n = sqrt(n); i < m; i++)
		{
			if(random()%100==0)
			{
				std::random_shuffle(a, a + n);
				for (int i = 0; i < n;++i)
					fout << a[i] << ' ';
				fout << '\n';
				continue;
			}
			if (i * 2 < m || random() % 1000)
			{
				if (random() % 2)
				{
					int bs = _n;
					for (int j = 0; j < bs; j++)
						fout << (a[j] = random())
							 << ' ';
					for (int j = bs; j < n; j++)
						fout << (a[j] = a[j - bs])
							 << ' ';
					fout << '\n';
				}
				else
				{
					a[random() % n] = random();
					int p = random() % n;
					for (int j = p; j < n; j++)
						fout << a[j] << ' ';
					for (int j = 0; j < p; j++)
						fout << a[j] << ' ';
					fout << '\n';
				}
			}
			else
			{
				std::cout << "Dandan Pos:" << i << std::endl;
				int p = random() % n;
				for (int j = p; j < n; j++)
					fout << a[j] << ' ';
				for (int j = 0; j < p; j++)
					fout << a[j] << ' ';
				fout << '\n';
			}
		}
		std::cout << "Dandan Pos:" << m << std::endl;
		int p = random() % n;
		for (int j = p; j < n; j++)
			fout << a[j] << ' ';
		for (int j = 0; j < p; j++)
			fout << a[j] << ' ';
		fout << '\n';
		fans << "All the currency in circulation will be destroyed by Luke.\n";
	}
	else
	{
		std::cout << "Dandan Sleeps" << std::endl;
		for (int i = 1; i <= m; i++)
		{
			for (int j = 0; j < n; j++)
				fout << random()
					 << ' ';
			fout << '\n';
		}
		fans << "Soldier Xu is sleeping." << std::endl;
	}
	fout.close();
	fans.close();
	std::rename((name + ".in").c_str(), (name + id + ".in").c_str());
	std::rename((name + ".out").c_str(), (name + id + ".out").c_str());
	return;
}
int main()
{
	int x, y;
	for (int i = 1; fin >> x >> y; i++)
		sv(std::to_string(i), x, y);
	system("mv *.in *.out data");
	return 0;
}
