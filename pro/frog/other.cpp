#include <fstream>
int n, m;
int main()
{
    freopen("frog.in", "r", stdin);
    scanf("%*s", NULL);
    scanf("%d%d", &n, &m);
    fclose(stdin);
    freopen("frog.in", "r", stdin);
    freopen("frog.out", "w", stdout);
    for (int i = 0; i < n; ++i)
        getchar();
    for (int i = n; i < m; ++i)
        putchar(getchar());
    fclose(stdin);
    fclose(stdout);
    return 0;
}
