///////////////////////////////////////////////////////
// 字符串压缩
// eg：
// 先输入一个整数，表示这次压缩几个字符串，然后依次输入
// 每行字符串;输出每行字符串压缩后的结果
// input:
// 2
// aaaabbc
// abc
// output:
// a4b2c1
// a1b1c1 
///////////////////////////////////////////////////////


#include <stdio.h>
#include <string.h>


int table[100][128];

void dst(int n, char* arr){
	unsigned int len = strlen(arr);
	for (unsigned int i = 0; i < len; ++i){
		table[n][(int)arr[i]]++;
	}
}

int main()
{
	int n = 0;
	char  arr[1024] = { 0 };
	while (scanf("%d", &n) != EOF){
		for (int i = 0; i < n; ++i){
			scanf("%s", arr);
			dst(i, arr);
			memset(arr, 0, strlen(arr));
		}
		for (int j = 0; j < n; ++j){
			for (int i = 0; i < 128; ++i){
				if (table[j][i] != 0){
					printf("%c%d", i, table[j][i]);
				}
			}
			printf("\n");
		}
		memset(table, 0, sizeof(table));
	}

	return 0;
}



