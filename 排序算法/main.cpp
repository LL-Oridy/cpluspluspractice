#include"sort.h"

void swap(int a, int b) {
	int temp = a;
	a = b;
	b = a;
}

//ѡ������
void selectSort(int* a) {
	for (int i = 0; i < N - 1; i++)
	{
		//��СԪ�ص�λ��
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

//��������
//��������������������ģ��ұ��������
void insertSort(int* a) {
	//0���Ѿ�Ĭ�����򣬴�1�ſ�ʼѭ��
	for (int i = 1; i < N; i++)
	{
		//��a��ֵ�������������ⱻ���ǣ��������һ������ǰ��һ��С��Ҫ������ǰ��
		int insertVal = a[i];
		//����λ��
		int j;
		//�ѱ����Ĭ��Ԫ�ش��֮ǰ��Ԫ����������
		for (j = i - 1; j >= 0 && a[j] > insertVal; j--)
		{
			//�Ȱ�Ԫ�غ��ƣ��ٸ��ǵ�Ԫ�ص�λ��
			a[j + 1] = a[j];
		}//�������������С����j=-1�˳�ѭ��
		a[j + 1] = insertVal;
	}
}

//ϣ������
//ϣ�������ǿ��ٰ�Ĳ�������
void shellSort(int* a) {
	//gap���±��ֵ-->N>>1��N����һλ-->N/2
	for (int gap = N >> 1; gap > 0; gap >>= 1) {
		//ֱ�Ӳ�������
		for (int i = gap; i < N; i++)
		{
			//��a��ֵ�������������ⱻ����
			int insertVal = a[i];
			//������λ��
			int j;
			for (j = i - gap; j >= 0 && a[j] > insertVal; j-=gap)
			{
				a[j + gap] = a[j];
			}
			a[j + gap] = insertVal;
		}
	}
}

//��������
void quickSort(int* a, int left, int right) {
	if (right > left) {
		int pivot = partition(a, left, right);
		quickSort(a, left, pivot - 1);
		quickSort(a, pivot + 1, right);
	}
}
//����
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
		//���������ϰ벿��
		qsort(a, low, i - 1);
		//���������°벿��
		qsort(a, i + 1, high);
	}
}

//��ӡ
void print(int* a) {
	for (int i = 0; i < N; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}


int main() {
	int a[N];
	//��ʱ����Ϊ���������
	srand(time(NULL));
	for (int i = 0; i < N; i++)
	{
		//���������
		a[i] = rand() % M;
	}
	cout << "ԭ������" << endl;
	print(a);
	//insertSort(a);
	//shellSort(a);
	//quickSort(a, 0, N - 1);
	qsort(a, 0, N - 1);
	cout << "������������" << endl;
	print(a);
}