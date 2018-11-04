#include <stdio.h>
#include <string.h>
//问题描述：模拟实现库函数atoi

//首先去掉字符串前面的空格
//然后判断字符串前面是否有正负号
//12345
//123 45
//123-45

int StrToInt(char *str)
{
	int size = strlen(str);
	if(str == NULL)
		return 0;
	int i = 0;
	while(str[i] == ' ')//处理字符串前面的空格
		i++;
	int flag = (str[i] == '-') ? -1 : 1;//处理正负号
	if(str[i] == '-' || str[i] == '+')
		++i;
	int result = 0;
	while(i < size)
	{
		if(isdigit(str[i]))
			result = result * 10 + (str[i] - '0'); 
		else if(str[i] != ' ')
			return 0;
		i++;
	}
	return flag * result;
}

//test
int main()
{
	char *arr = " -123@45";
	printf("%d\n", StrToInt(arr));
	return 0;
}
