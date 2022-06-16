#include"sort.h"

void swap(int a, int b) {
	int temp = a;
	a = b;
	b = a;
}

//选择排序
void selectSort(int* a) {
	for (int i = 0; i < N - 1; i++)
	{
		//最小元素的位置
		int min = i;
		for (int j = i + 1; j < N; j++)
		{
			if (a[min] > a[j]) {
				min = j;
			}
		}
		if (min != i) {
			swap(a[min], a[i]);
		}
	}
}

//插入排序
//插入排序的左边总是有序的，右边是无序的
void insertSort(int* a) {
	//0号已经默认排序，从1号开始循环
	for (int i = 1; i < N; i++)
	{
		//将a的值保留下来，以免被覆盖，如果后面一个数比前面一个小就要依次向前比
		int insertVal = a[i];
		//待插位置
		int j;
		//把比这个默认元素大的之前的元素依次右移
		for (j = i - 1; j >= 0 && a[j] > insertVal; j--)
		{
			//先把元素后移，再覆盖掉元素的位置
			a[j + 1] = a[j];
		}//如果来的牌是最小的牌j=-1退出循环
		a[j + 1] = insertVal;
	}
}

//希尔排序
//希尔排序是快速版的插入排序
void shellSort(int* a) {
	//gap是下标差值-->N>>1是N右移一位-->N/2
	for (int gap = N >> 1; gap > 0; gap >>= 1) {
		//直接插入排序
		for (int i = gap; i < N; i++)
		{
			//将a的值保留下来，以免被覆盖
			int insertVal = a[i];
			//待插入位置
			int j;
			for (j = i - gap; j >= 0 && a[j] > insertVal; j-=gap)
			{
				a[j + gap] = a[j];
			}
			a[j + gap] = insertVal;
		}
	}
}

//快速排序
void quickSort(int* a, int left, int right) {
	if (right > left) {
		int pivot = partition(a, left, right);
		quickSort(a, left, pivot - 1);
		quickSort(a, pivot + 1, right);
	}
}
//窗口
int partition(int* a, int left, int right) {
	int i, j;
	for (i = left, j = left; i < right; i++) {
		if (a[i] < a[right]) {
			swap(a[i], a[j]);
			j++;
		}
	}
	swap(a[j], a[right]);
	return j;
}

void qsort(int* a, int low, int high) {
	int temp;
	int i = low;
	int j = high;
	if (low < high) {
		temp = a[low];
		while (i < j) {
			while (i < j && a[j] >= temp)
				--j;
			if (i < j) {
				a[i] = a[j];
				++i;
			}
			while (i < j && a[i] < temp)
				++i;
			if (i < j) {
				a[j] = a[i];
				--j;
			}
		}
		a[i] = temp;
		//依次排序上半部分
		qsort(a, low, i - 1);
		//依次排序下半部分
		qsort(a, i + 1, high);
	}
}

//打印
void print(int* a) {
	for (int i = 0; i < N; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}


int main() {
	int a[N];
	//以时间作为随机数种子
	srand(time(NULL));
	for (int i = 0; i < N; i++)
	{
		//创建随机数
		a[i] = rand() % M;
	}
	cout << "原数组是" << endl;
	print(a);
	//insertSort(a);
	//shellSort(a);
	//quickSort(a, 0, N - 1);
	qsort(a, 0, N - 1);
	cout << "排序后的数组是" << endl;
	print(a);
}