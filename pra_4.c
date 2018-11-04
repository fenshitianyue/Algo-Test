///////////////////////////////////////////////////////
// 字符串转换
///////////////////////////////////////////////////////

#include <stdio.h>
#include <string.h>


int main(){
	char arr[256];
	while (scanf("%s", arr) && (strcmp(arr, "END") != 0)){
		int size = strlen(arr);
		for (int i = 0; i < size; ++i){
			switch (arr[i]){
			case 'A':
			case 'W':
			case 'F':
				arr[i] = 'I';
				break;
			case 'D':
			case 'P':
			case 'G':
			case 'B':
				arr[i] = 'e';
				break;
			case 'C':
				arr[i] = 'L';
				break;
			case 'M':
				arr[i] = 'o';
				break;
			case 'S':
				arr[i] = 'v';
				break;
			case 'L':
				arr[i] = 'Y';
				break;
			case 'X':
				arr[i] = 'u';
				break;
			default:
				break;
			}
		}
		printf("%s\n", arr);
    scanf("%*[^\n]");scanf("%*c");//clear input cache
	}
	return 0;
}




