#include <bits/stdc++.h>
std::ifstream fin("river.in");
std::ofstream fout("river.out");
int main()
{
    int n, m;
    fin >> n >> m;
    fout << std::setprecision(m)<<std::fixed;
    do
    {
        long double v;
        fin >> v;
        fout 
             << sqrtl((v * v) / (1.L - v * v))
             << '\n';
    } while (--n);
    return 0;
}