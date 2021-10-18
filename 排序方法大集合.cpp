#include<iostream>
using namespace std;
void swap(int &a,int &b)
{
	int t = a;
	a = b;
	b = t;
}
void print(int arr[],int len)
{
	for(int i = 0;i < len;i++)
		cout << arr[i] << " ";
		cout << "\n";
}
void bubbleSort(int arr[],int len)
{
	for(int i = 0;i < len - 2;i++)
		for(int j = i;j < len - 1;j++)
		{
			if(arr[j + 1] < arr[j])
				swap(arr[j + 1],arr[j]);	
		}
}
void selectionSort(int a[], int len) 
{
	for (int i = 0 ; i < len - 1 ; i++) 
    {
		int min = i;
		for (int j = i + 1; j < len; j++)     //走訪未排序的元素
		{
			if (a[j] < a[min])    //找到目前最小值
			{
				min = j;    //紀錄最小值
			}
		}
		if(min != i)
			swap(a[min],a[i]); 
	}
}
void insertionSort(int arr[],int len)
{
     int i,j,key;
        for (i=1;i!=len;++i){
                key = arr[i];
                j=i-1;
                while((j>=0) && (arr[j]>key)) {
                        arr[j+1] = arr[j];
                        j--;
                }
                arr[j+1] = key;
        }
}
void merge_sort_recursive(int arr[], int reg[], int start, int end) {
    if (start >= end)
        return;
    int len = end - start, mid = (len >> 1) + start;
    int start1 = start, end1 = mid;
    int start2 = mid + 1, end2 = end;
    merge_sort_recursive(arr, reg, start1, end1);
    merge_sort_recursive(arr, reg, start2, end2);
    int k = start;
    while (start1 <= end1 && start2 <= end2)
        reg[k++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];
    while (start1 <= end1)
        reg[k++] = arr[start1++];
    while (start2 <= end2)
        reg[k++] = arr[start2++];
    for (k = start; k <= end; k++)
        arr[k] = reg[k];
}

void mergeSort(int arr[], const int len) {
    int reg[len];
    merge_sort_recursive(arr, reg, 0, len - 1);
}
int Paritition1(int A[], int low, int high) {
   int pivot = A[low];
   while (low < high) {
     while (low < high && A[high] >= pivot) {
       --high;
     }
     A[low] = A[high];
     while (low < high && A[low] <= pivot) {
       ++low;
     }
     A[high] = A[low];
   }
   A[low] = pivot;
   return low;
 }
void QuickSort(int A[], int low, int high) //快排母函数
 {
   if (low < high) {
     int pivot = Paritition1(A, low, high);
     QuickSort(A, low, pivot - 1);
     QuickSort(A, pivot + 1, high);
   }
 }


int main(){
	int nums[10];
	int k;
	char c = 'y';
	cout << "请输入待排序的数列（10个数）：\n"; 
	for(k = 0;k < 10;k++)
	cin >> nums[k];
	while(c == 'y' || c == 'Y')
	{
		cout << "请选择排序方法：\n" << "1 选择排序\n" << "2 冒泡排序\n" << "3 插入排序\n" << "4 归并排序\n" << "5 快速排序\n";
		cin >> k;
		switch (k)
		{
			case 1:
				selectionSort(nums,10);
				break;
			case 2:
				bubbleSort(nums,10);
				break;
			case 3:
				insertionSort(nums,10);
				break;
			case 4:
				mergeSort(nums,10);
				break;
			case 5:
				QuickSort(nums,0,9);
				break;
		}
		print(nums,10);
		cout <<"继续吗？（Y/y   N/n）\n";
		cin >> c;	
	}
}
