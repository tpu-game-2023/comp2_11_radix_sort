#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"


// 基数ソート(引数が不適切であればfalseを返す)
// begin: ソートする配列の先頭要素へのポインタ
// end: ソートする配列の末尾要素の次の要素へのポインタ
// radix: 基数
bool radix_sort(item* begin, const item* end, int radix)
{
	// ToDo: 基数ソートを実装する
	if(begin==NULL||end==NULL)return false;
}
int getMax(int begin[], int end)
{
	int max = begin[0];
	for (int i = 1; i < end; i++)
		if (begin[i] > max)
			max = begin[i];
	return max;
}
void CountingSort(int begin[], int end, int radix)
{
	int output[1];
	int count[10] = { 0 };

	for (int i = 0; i < end; i++)
		count[(begin[i] / radix) % 10]++;

	for (int i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (int i = end - 1; i >= 0; i--)
	{
		output[count[(begin[i] / radix) % 10] - 1] = begin[i];
		count[(begin[i] / radix) % 10]--;
	}

	for (int i = 0; i < end; i++)
		begin[i] = output[i];
}
void RadixSort(int begin[], int end)
{
	int m = getMax(begin, end);
	for (int radix = 1; m / radix > 0; radix *= 10)
		CountingSort(begin, end, radix);
}