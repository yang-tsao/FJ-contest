#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
#define lowbit(x) (x & -x)

template <typename T> inline void wt(T x, char c = '\n')
{
    if (x < 0)
    {
        x = -x;
        putchar('-');
    }
    static char sta[sizeof(T) * 8];
    T top = 0;
    do
    {
        sta[top++] = x % 10;
        x /= 10;
    } while (x);
    while (top)
        putchar(sta[--top] + '0');
    putchar(c);
}
template <typename T> inline T rd()
{
    T sum = 0, fl = 1;
    char ch = getchar();
    for (; ch < '0' || ch > '9'; ch = getchar())
        if (ch == '-')
            fl = -1;
        else if (ch == EOF)
            exit(0);
    for (; '0' <= ch && ch <= '9'; ch = getchar())
        sum = sum * 10 + ch - '0';
    return sum * fl;
}

char s[1024] = "フリージア"; //不要停下来啊！
int n, m;
std::vector<std::vector<int>> G, lp, rp, anc;
std::vector<int> deep, dpstv, bfs, ubfs;
std::vector<long long> ft;
void Dfs(int x)
{
    int sz = log2(deep[x] - 1);
    for (int i = 1; i <= sz; i++)
        anc[x][i] = anc[anc[x][i - 1]][i - 1];
    for (int &son : G[x])
    {
        deep[son] = deep[x] + 1;
        dpstv[son] = deep[son];
        anc[son].resize(log2(deep[son] - 1) + 1);
        anc[son][0] = x;
        Dfs(son);
        if (dpstv[son] > dpstv[x])
            dpstv[x] = dpstv[son];
    }
    std::sort(G[x].begin(), G[x].end(), [](int a, int b) { return dpstv[a] < dpstv[b]; });
    return;
}
int lpprsz(int x)
{
    return std::max(log2(dpstv[x] - deep[x]), 0.0);
}
int lprlsz(int x)
{
    return std::max(log2(dpstv[1] - deep[x]), 0.0);
}
void Dfs1(int x)
{
    for (int i = 0, ti = log2(deep[x] - 1); i <= ti; i++)
        if (lp[anc[x][i]][i] == 0)
            lp[anc[x][i]][i] = x;
     else
       break;
    int sz = lprlsz(x);
    lp[x].resize(sz + 1);
    rp[x].resize(sz + 1);
    if (G[x].empty())
        return;
    rp[x][0] = G[x].back();
    for (int &son : G[x])
        Dfs1(son);
    sz = lpprsz(x);
    for (int i = 1; i <= sz; i++)
        rp[x][i] = rp[rp[x][i - 1]][i - 1];
    return;
}
void Dfs2(int x)
{
    if (G[x].empty())
        return;
    Dfs2(G[x].back());
    for (int i = bfs[x] - 1, sz = lprlsz(x); deep[ubfs[i]] == deep[x]; --i)
        for (int j = lpprsz(ubfs[i]); j <= sz; j++)
            if (!lp[ubfs[i]][j])
                lp[ubfs[i]][j] = lp[ubfs[i + 1]][j];
    return;
}
int get_lp(int x, int d)
{
    for (int i = log2(d); i >= 0; i--)
        if (d & 1 << i)
            x = lp[x][i];
    return x;
}
int get_rp(int x, int d)
{
    for (int i = log2(d); i >= 0; i--)
        if (d & 1 << i)
            x = rp[x][i];
    return x;
}
void f_add(int x, long long v)
{
    do
    {
        ft[x] += v;
        x += lowbit(x);
    } while (x <= n);
    return;
}
long long f_sum(int x)
{
    long long res = 0;
    do
    {
        res += ft[x];
        x -= lowbit(x);
    } while (x);
    return res;
}
int main()
{
    n = rd<int>();
    { // Init vector size
        anc.resize(n + 1);
        lp.resize(n + 1);
        rp.resize(n + 1);
        G.resize(n + 1);
        deep.resize(n + 1);
        dpstv.resize(n + 1);
        bfs.resize(n + 1);
        ubfs.resize(n + 1);
        ft.resize(n + 2);
    }
    for (int i = 1, a; i < n; i++) // Build Tree
    {
        a = rd<int>();
        G[a].push_back(rd<int>());
    }
    { // Dfs
        deep[1] = 1;
        Dfs(1);
    }
    { // Bfs
        std::queue<int> q;
        q.push(1);
        for (int cnt = 1; !q.empty(); ++cnt)
        {
            int x = q.front();
            q.pop();
            bfs[x] = cnt;
            ubfs[cnt] = x;
            for (int son : G[x])
                q.push(son);
        }
    }
    Dfs1(1);
    Dfs2(1);
    m = rd<int>();
    for (int i = 1, a, b, c; i <= m; i++)
        if (rd<int>() == 1)
        {
            a = rd<int>();
            b = rd<int>();
            c = rd<int>();
            int l = get_lp(a, b);
            int r = get_rp(a, b);
            f_add(bfs[l], c);
            f_add(bfs[r] + 1, -c);
        }
        else
            wt(f_sum(bfs[rd<int>()]));
    return 0;
}
