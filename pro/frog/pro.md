时间：1s
内存：5MB
鲁克一直对背诵课文很苦恼。每次Soldier Xu让他默写时，他都只记得句子的位置，但是不记得句子内容。
于是他决定让你写个程序帮助他。
Soldier Xu的课文很长，多达19260817个字母。现在她让鲁克默写第n到第m个字符(从0开始编号，包括第n个字符但不包括第m个字符)。
输入
第一行，19260817个字符。
第二行，两个数字，n和m
样例：
输入：
由以下程序运行产生
```cpp
#include<fstream>
std::ofstream fout("frog.in");
int main()
{
	for (int i = 0; i < 19260817;i++)
		fout.put(i % 26 + 'a');
	fout << '\n';
	fout << 26 << ' ' << 28 << '\n';
	return 0;
}
```
输出：
ab