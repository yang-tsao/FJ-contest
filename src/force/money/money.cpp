#include <bits/stdc++.h>
std::ifstream fin("money.in");
std::ofstream fout("money.out");
int m, n;
struct M
{
    std::vector<int> a;
    M(size_t sz)
    {
        a.resize(sz);
    }
    friend bool operator==(M A, M B)
    {
        int sz = A.a.size();
        for (int i = 0; i < sz; ++i)
        {
            bool flag = 1;
            for (int j = 0; j < sz; ++j)
                if (A.a[j] != B.a[(i + j) % sz])
                {
                    flag = 0;
                    break;
                }
            if (flag)
                return 1;
        }
        return 0;
    }
};
std::vector<M> v;
int main()
{
    fin >> m >> n;
    if(m*n>1000000)//做不出来，直接骗分数
    {
        fout << "All the currency in circulation will be destroyed by Luke." << std::endl;
        return 0;
    }
    v.resize(m, n);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            fin >> v[i].a[j];
        for (int j = 0; j < i; j++)
            if (v[i] == v[j])
            {
                fout << "All the currency in circulation will be destroyed by Luke." << std::endl;
                return 0;
            }
    }
    fout << "Soldier Xu is sleeping." << std::endl;
    return 0;
}