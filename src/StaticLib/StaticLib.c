#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"
#include <malloc.h>

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

	item* bucket = (item*)malloc(sizeof(item) * length);
	if (!bucket)return false;
	unsigned* count = (unsigned*)calloc(radix,sizeof(unsigned));
	if (!count) { free(bucket); return false; }

	//sort start
	for (unsigned int base = 1; base <= maxkey; base *= radix) {

		//count set
		for (item* i = begin; i < end; i++) {
			count[i->key / base % radix]++;
		}

		for (int i = 1; i < radix; i++) {
			count[i] += count[i - 1];
		}

		//bucket set
		for (item* i = begin + length -1; i >= begin; i--) {
			int radixnum = i->key / base % radix;
			count[radixnum]--;
			int now = count[radixnum];
			bucket[count[radixnum]] = *i;
		}

		for (int i = 0; i < length; i++) {
			begin[i] = bucket[i];
		}

		for (int i = 0; i < radix; i++) {
			count[i] = 0;
		}
	}

	free(bucket);
	free(count);

	return true;
}