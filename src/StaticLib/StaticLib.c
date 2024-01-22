#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"


// 基数ソート(引数が不適切であればfalseを返す)
// begin: ソートする配列の先頭要素へのポインタ
// end: ソートする配列の末尾要素の次の要素へのポインタ
// radix: 基数
int digitNum(const item* item,const int radix,const int num)
{
	int radix_ = 1;
	if (num != 1)
	{
		for (int i = 0; i < num - 1; i++) radix_ *= radix;
	}
	return (item->key / radix_) % radix;
}
void radix_sort_(const item* backBucket, item* bucket, const int radix, const int num, const int size)
{
	int k = 0;
	for (int i = 0; i < radix; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (digitNum(&backBucket[j], radix, num) == i)
			{
				bucket[k] = backBucket[j];
				k++;
			}
		}
	}
}
bool radix_sort(item* begin, const item* end, int radix)
{
	if (begin == NULL || end == NULL || radix < 1 || end - begin < 1) return false;
	const int size = end - begin;

	int max = 0;
	for (int i = 0; i < size; i++)
	{
		if (begin[i].key > max) max = begin[i].key;
	}

	int Max = radix, num = 1;
	while (max > Max)
	{
		Max *= radix;
		num++;
	}

	item** bucket;
	bucket = (item**)malloc(num * sizeof(item*));
	for (int i = 0; i < num; i++) {
		bucket[i] = (item*)malloc(sizeof(item));
	}

	for (int i = 0; i < size; i++)
	{
		bucket[0][i] = begin[i];
	}
	for (int i = 0; i < num; i++)
	{
		if(i == 0)
			radix_sort_(begin,bucket[i], radix, num, size);
		else
			radix_sort_(bucket[i - 1],bucket[i], radix, num, size);
	}

	for (int i = 0; i < size; i++)
	{
		begin[i] = bucket[num - 1][i];
	}
	for (int i = 0; i < num; i++) {
		free(bucket[i]);
	}
	free(bucket);
	return true;
}
