#include <bits/stdc++.h>

using namespace std;

void reverseArray(int arr[], int n)
{
	int s = 0;
	int e = n - 1;

	while (s < e)
	{
		swap(arr[s], arr[e]);
		s++;
		e--;
	}
}

void printArray(int arr[], int n)
{

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void printallPairs(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		int x = arr[i];

		for (int j = i + 1; j < n; j++)
		{
			int y = arr[j];

			cout << x << " " << y << endl;
		}
		cout << endl;
	}
}

void printSumSubarrays(int arr[], int n)
{
	//Brute Force//

	int maxcnt = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			int cnt = 0;
			for (int k = i; k <= j; k++)
			{
				cnt += arr[k];
			}
			if (cnt > maxcnt)
			{
				maxcnt = cnt;
			}
		}
	}
	cout << maxcnt << endl;
}

void printSubarrays(int arr[], int n)
{

	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			for (int k = i; k <= j; k++)
			{
				cout << arr[k] << ",";
			}
			cout << endl;
		}
	}
}

int subarraysumprefix(int arr[], int n)
{

	int prefix[100] = {0}; // make constant size array or vector,
	prefix[0] = arr[0];

	for (int i = 1; i < n; i++)
	{
		prefix[i] = prefix[i - 1] + arr[i];
	}

	int largest_sum = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			int subarraysum = 0;

			subarraysum = i > 0 ? prefix[j] - prefix[i - 1] : prefix[j];

			largest_sum = max(largest_sum, subarraysum);
		}
	}
	return largest_sum;
}

int kadane(int arr[], int n)
{
	int cs = 0;
	int ms = 0;

	for (int i = 0; i < n; i++)
	{
		cs += arr[i];

		if (cs < 0)
		{
			cs = 0;
		}

		ms = max(ms, cs);
	}

	return ms;
}

int maxSumSubarray(vector<int> A)
{
	int cs = 0;
	int ms = 0;
	int n = A.size();
	for (int i = 0; i < n; i++)
	{
		cs += A[i];

		if (cs < 0)
		{
			cs = 0;
		}
		ms = max(ms, cs);
	}
	return ms;
}

void bubbleSort(int arr[], int n)
{
	//repeated swapping
	for (int times = 0; times <= n - 1; times++)
	{
		//swap
		for (int j = 0; j <= n - 1 - times; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}
void insertionSort(int arr[], int n)
{

	//sorted and unsorted area
	for (int i = 1; i < n; i++)
	{
		int current = arr[i];
		int prev = i - 1;

		while (prev >= 0 and arr[prev] >= current)
		{
			arr[prev + 1] = arr[prev];
			prev--;
		}
		arr[prev + 1] = current;
	}
}

void selectionSort(int arr[], int n)
{

	//finding minimum in unsorted

	for (int pos = 0; pos < n - 1; pos++)
	{

		int current = arr[pos];
		int min_pos = pos;

		for (int j = pos; j < n; j++)
		{
			if (arr[j] < arr[min_pos])
				min_pos = j;
		}

		swap(arr[pos], arr[min_pos]);
	}
}

void countingSort(int arr[], int n)
{
	//elements must be non negative.
	//range
	int largest = 0;
	for (int i = 0; i < n; i++)
	{
		largest = max(largest, arr[i]);
	}

	//frequencyarray
	//dynamic array
	//int *freq = new int[largest + 1];
	vector<int> freq(largest + 1, 0);
	for (int i = 0; i < n; i++)
	{
		freq[arr[i]]++;
	}

	int j = 0;

	for (int i = 0; i < freq.size(); i++)
	{
		while (freq[i] > 0)
		{
			arr[j] = i;

			freq[i]--;
			j++;
		}
	}
	return;
}

int main()
{

	int yashage;
	int currentage = 13;
	yashage = 500 + currentage;

	cout << yashage << endl;
	return 0;
}