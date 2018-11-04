///////////////////////////////////////////////////////
// 输入n个学生的学号和成绩（一一对应）
// 将其排序后输出
// 排序规则：按照成绩排序，成绩相同的按照学号排序
///////////////////////////////////////////////////////

#include <stdio.h>
#include <string.h>

typedef struct {
	int _no;
	int _sc;
} Stu;

void swap(Stu *x, Stu *y)
{
	(*x)._no ^= (*y)._no;
	(*y)._no ^= (*x)._no;
	(*x)._no ^= (*y)._no;

	(*x)._sc ^= (*y)._sc;
	(*y)._sc ^= (*x)._sc;
	(*x)._sc ^= (*y)._sc;
}

void Sort(Stu array[], int size){
	for (int i = 0; i < size; ++i){
		for (int j = i + 1; j < size; ++j){
			if (array[j]._sc < array[i]._sc){
				swap(&array[i], &array[j]);
			}
			else if ((array[j]._sc == array[i]._sc) && (array[j]._no < array[i]._no)){
				swap(&array[i], &array[j]);
			}
		}//end for(j)
	}//end for(i)
}//end func

int main(){
	Stu stu[128];
  memset(stu, 0, sizeof(stu));
	int n = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i){
		scanf("%d%d", &stu[i]._no, &stu[i]._sc);
	}
	Sort(stu, n);
	for (int i = 0; i < n; ++i){
		printf("%d %d\n", stu[i]._no, stu[i]._sc);
	}
	return 0;
}

