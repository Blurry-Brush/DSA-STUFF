/*
	To apply the method explained in the hint video, we have to add two more parameters in the function call. This can be done by calling a helper function from given function. The helper function can have three parameters: array, start index, end index.  
	
	Skeleton code to achieve this:
	#include <iostream>
	using namespace std;
	
	void quickSort(int input[], int start, int end)
	{
    		// your code goes here 
	}
	void quickSort(int input[], int size)
	{
    		quickSort(input, 0, size - 1);
	}
		
*/
void swap(int &a,int &b){
    int c = a;
    a = b;
    b = c;
}

int partition(int arr[], int si, int ei) {
	int countlessthan = 0;
	for (int k = si + 1; k <= ei; k++) {
		if (arr[k] <= arr[si]) { //equal walo ke liye space.
			countlessthan++;
		}
	}

	int ans = si + countlessthan;
	//cout << ans << endl;
	swap(arr[ans], arr[si]);
	int i = si;
	int j = ei;

	while (i <= (ans - 1) and j >= (ans + 1)) {
		if (arr[i] > arr[ans]) {
			if (arr[j] <= arr[ans]) { //equal wale left mein.
				swap(arr[i], arr[j]);
				i++;
				j--;
			}
			else {
				j--;
			}
		}
		else {
			i++;
		}
	}

	
	return ans;
}
void realquicksort(int arr[],int si,int ei){
    if(si >= ei){
        return;
    }
    int ans = partition(arr,si,ei);
    
    realquicksort(arr,si,ans-1);
    realquicksort(arr,ans+1,ei);
}

void quickSort(int input[], int size) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Change in the given array itself.
     Taking input and printing output is handled automatically.
  */
    
	realquicksort(input,0,size - 1);

}
