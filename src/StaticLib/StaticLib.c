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
	if (begin==NULL||end==NULL||begin>end||radix<1)
	return false;

	else
	{
		int n;
		n = end - begin;
		int *rad;// 基数を取り出した後保存
		rad = malloc(sizeof(int)*n);
		if (rad == NULL)exit(0);

		item* y = (item*)malloc(sizeof(item) * n);
		if (y == NULL)exit(0);

		int k;
		int m = 1;// 基数を取り出す桁

		while (m <= radix)
		{
			for (int i = 0; i < n; i++)
			{
				rad[i] = ((begin + i)->key / m) % 10;
			}

			k = 0;
			for (int i = 0; i <= 9; i++)
			{
				for (int j = 0; j < n; j++)
					if (rad[j] == i)
					{
						y[k++] = *(begin + j);
						
					}
			}

			for (int i = 0; i < n; i++)
			{
				*(begin + i) = y[i];
			}
			m *= 10;
		}

		free(rad);
		free(y);

		return true;
	}
}
