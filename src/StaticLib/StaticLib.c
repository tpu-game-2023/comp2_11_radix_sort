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
	if (begin == NULL || end == NULL || radix <= 0)
	{
		return false;
	}

    if (end - begin <= 1)
    {
        return true;
    }

    int index;
    int m = 1;
    int n = (int)(end - begin);

    int* rad = malloc(sizeof(int) * n);
    if (rad == NULL)
    {
        exit(0);
    }

    item* work = (item*)malloc(sizeof(item) * n);
    if (work == NULL)
    {
        exit(0);
    }

    while (m <= radix)
    {
        index = 0;

        for (int i = 0; i < n; i++)
        {
            rad[i] = ((begin + i)->key / m) % 10;
        }

        for (int i = 0; i <= 9; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (rad[j] == i)
                {
                    work[index++] = *(begin + j);
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            *(begin + i) = work[i];
        }

        m *= 10;
    }

    free(rad);
    free(work);

	return true;
}
