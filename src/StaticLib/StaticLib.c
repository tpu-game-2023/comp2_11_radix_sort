#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"
#include <malloc.h>

typedef struct {
	item* items;
	item* stacks;
}bucket;

// 基数ソート(引数が不適切であればfalseを返す)
// begin: ソートする配列の先頭要素へのポインタ
// end: ソートする配列の末尾要素の次の要素へのポインタ
// radix: 基数
bool radix_sort(item* begin, const item* end, int radix)
{
	// ToDo: 基数ソートを実装する
	if (!begin || !end || radix <= 0)return false;

	int length = (int)(end - begin);
	if (length <= 0)return false;

	unsigned int maxkey = 0;
	for (item* i = begin; i < end; i++) {
		if (maxkey < i->key)
			maxkey = i->key;
	}

	bucket* buckets = (bucket*)malloc(sizeof(bucket) * radix);
	if (!buckets)return false;
	//buckets[0].items = (item*)malloc(sizeof(item) * length);
	//buckets[0].num = 0;
	for (int i = 0; i < radix; i++) {
		buckets[i].items = (item*)malloc(sizeof(item) * length);//(maxkey / radix + 1)
		buckets[i].stacks = buckets[i].items;
	}

	//sort start
	for (unsigned int base = 1; base <= maxkey; base *= radix) {

		for (item* i = begin; i < end; i++) {
			int bnum = i->key / base % radix;
			//buckets[bnum].items[buckets[bnum].num] = *i;
			*(buckets[bnum].stacks) = *i;
			buckets[bnum].stacks++;
		}

		item* tmp = begin;
		for (int i = 0; i < radix; i++) {
			for (item* j = buckets[i].items; j < buckets[i].stacks; j++) {
				*tmp = *j;
				tmp++;
			}
			buckets[i].stacks = buckets[i].items;
		}
	}

	for (int i = 0; i < radix; i++) {
		free(buckets[i].items);
	}
	free(buckets);

	return true;
}
