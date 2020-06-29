# 鲁克的钱。
---
### 文件名：money.cpp
### 输入：money.in
### 输出：money.out
---
鲁克王国的每一枚钱都是鲁克亲手雕刻的。每一枚钱上依次有环形的n个数字，钱可以旋转。
由于鲁克技术高超，没有钱是一样的。但是令他苦恼的是，徐大兵妄图通过造假币取代他的地位。
所幸，徐大兵技术不高明，每次造的一批假币中，必有一样的。
现在给出一批货币，请判断是否有假币。
### 是，请输出
## "All the currency in circulation will be destroyed by Luke."
### 否则，请输出
## "Soldier Xu is sleeping."
---
## 输入：
第一行，一个整数m，表示钱的数量。
第二行，一个整数n，表示每枚钱上数字的数量。
保证n*m<=1e6。
接下来m行，每行n个数，依次代表钱上的各个数字。
## 输出：
共一行，
### "All the currency in circulation will be destroyed by Luke."
或
### "Soldier Dandan is sleeping."
---
## 数据范围：
#### 对于50%的数据，输出
### "All the currency in circulation will be destroyed by Luke."，
即可骗分。
#### 对于另外50%的数据，输出
### "Soldier Dandan is sleeping."，
即可骗分。
