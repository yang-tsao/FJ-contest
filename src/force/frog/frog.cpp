#include <cstdio>
int n, m;
char s[4000000];
int main()
{
	freopen("frog.in", "r", stdin);
	freopen("frog.out", "w", stdout);
	for (int i = 0; i < sizeof(s);++i)
		s[i] = getchar();
	for (int i = sizeof(s); i < 19260817;++i)
		getchar();
	scanf("%d%d", &n, &m);
	if(m>sizeof(s))
		return 0;
	for (int i = n; i < m;++i)
		putchar(s[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
