#include <iostream>
#include <fstream>
#include <random>
#include <filesystem>
#define frog 19260817
std::ifstream fin("pro.dat");
std::string name = "frog";
char tmp[256];
void sv(std::string id, int n, int m)
{
	std::ofstream fout("frog.in");
	std::cout << "ID=" << id << std::endl;
	std::default_random_engine e(clock());
	std::uniform_int_distribution<char> u('a', 'z');
	for (int i = 0; i < frog; i++)
		fout.put(u(e));
	fout << '\n'
		 << n << ' ' << m << std::endl;
	fout.close();
	system("./sol");
	std::rename((name + ".in").c_str(), (name + id + ".in").c_str());
	std::rename((name + ".out").c_str(), (name + id + ".out").c_str());
	return;
}
int main()
{
	int n, m;
	for (int i = 0; fin >> n >> m; i++)
		sv(std::to_string(i), n, m);
	system("mv *.in *.out data");
	return 0;
}