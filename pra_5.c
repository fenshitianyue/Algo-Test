////////////////////////////////////////////////////////
// 字符串压缩
// eg：
// 先输入一个整数，表示这次压缩几个字符串，然后依次输入
// 每行字符串,输出输入的所有字符串的压缩结果
// input:
// 2
// aaaabbc
// abc
// 
// output:
// a5b3c2
///////////////////////////////////////////////////////


#include <stdio.h>
#include <string.h>


int table[128] = { 0 };

void dst(char* arr){
	unsigned int len = strlen(arr);
	for (unsigned int i = 0; i < len; ++i){
		table[(int)arr[i]]++;
	}
}

int main()
{
	int n = 0;
	char  arr[1024] = { 0 };
	while (scanf("%d", &n) != EOF){
		for (int i = 0; i < n; ++i){
			scanf("%s", arr);
			dst(arr);
			memset(arr, 0, strlen(arr));
		}
		for (int i = 0; i < 128; ++i){
			if (table[i] != 0){
				printf("%c%d", i, table[i]);
			}
		}
		printf("\n");
		memset(table, 0, sizeof(table));
	}

	return 0;
}



