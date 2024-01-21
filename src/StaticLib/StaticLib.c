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
    if (begin == NULL || end == NULL)return false;
    if (end - begin < 1)return false;
    if (radix < 1)return false;
    if (end - begin <= 1)return true;
    item* p = begin;
    item* q = end;
    int rad[10];
    int i, j, k;
    int m = 1;
    item* back = begin + (end - begin) - 1;
   
    while (m <= back->key) {
        for (i = 0; i < back->key; i++)
            rad[i] = (p[i].key / m) % radix;

        k = 0;
        for (i = 0; i <= 9; i++)
            for (j = 0; j < back->key; j++)
                if (rad[j] == i)
                    q[k++] = p[j];

        for (i = 0; i < back; i++)
            p[i] = q[i];

        m *= 10;
        radix_sort(begin,end,radix);
    }
}