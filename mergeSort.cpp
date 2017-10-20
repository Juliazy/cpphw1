#include <iostream>
#include <ctime>
#include "testTools.h"

using namespace std;

void __merge(int arr[], int l, int mid, int r){
	int aux[r-l+1];
	for (int i = l; i <= r; ++i)
	{
		aux[i-l] = arr[i];
	}

	int i=l, j=mid+1;
	for (int k = l; k <= r; ++k)
	{
		if ( i > mid )
		{
			arr[k] = aux[j-l];
			j++;
		}else if ( j > r )
		{
			arr[k] = aux[i-l];
			i++;
		}else if (aux[i-l] < aux[j-l])
		{
			arr[k] = aux[i-l];
			i++;
		}else{
			arr[k] = aux[j-l];
			j++;
		}
	}
}
void __mergeSort(int arr[], int l, int r){
	// l is the left
	if (l>=r)
	{
		return;
	}
	int mid = (l+r)/2;

	__mergeSort(arr,l,mid);
	__mergeSort(arr,mid+1,r);
	if (arr[mid] > arr[mid+1])
	{
		__merge(arr,l,mid,r);	
	}
}

int mergeSort(int arr[], int len){
	int l = 0,  r = len-1;

	__mergeSort(arr, l, r);

	return 0;
}

int main(int argc, char const *argv[])
{
	int len = 10000;
	int *arr = ttools::generateTestArray(len,1,10000);

	clock_t start_stamp = clock();
	mergeSort(arr,len);
	clock_t end_stamp = clock();

	ttools::output(arr, len, start_stamp, end_stamp);
	cout << (ttools::checkSort(arr, len) ? "Sorted" : "Error") << endl;

	return 0;
}