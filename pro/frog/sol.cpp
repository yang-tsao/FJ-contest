#include<fstream>
std::ifstream fin("frog.in");
std::ofstream fout("frog.out");
int n,m;
int main()
{
    fin.seekg(19260817);
    fin >> n>>m;
    fin.seekg(n);
    do{
        fout.put(fin.get());
    } while (++n < m);
    return 0;
}