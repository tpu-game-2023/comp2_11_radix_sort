#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"



static void swap(item* i1, item* i2)
{
	item tmp = *i1;
	*i1 = *i2;
	*i2 = tmp;
}

static void max_n(item* j1, item* j2)
{
	item Max;
	if (j1 < j2)
		Max = *j2;
	else
		Max = *j1;
}
// 基数ソート(引数が不適切であればfalseを返す)
// begin: ソートする配列の先頭要素へのポインタ
// end: ソートする配列の末尾要素の次の要素へのポインタ
// radix: 基数
bool radix_sort(item* begin, const item* end, int radix)
{
	// ToDo: 基数ソートを実装する
	if (begin == NULL || end == NULL)return false;
	if (radix == NULL) return false;
	max_n(begin, begin + 1);
	int r = end;
	int m = 1;
	int p;
	while (m <= r)
	{
		radix = (begin / m) % 10;
		for (int i = 0; i <= 9; i++)
			for (int j = 0; j <= 9; j++)
				if (radix == i)
					p = begin;
		begin = p;
		m *= 10;
	}
	return true;
}
