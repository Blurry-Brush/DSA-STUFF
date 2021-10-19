void mergeandreplace(int arr[] , int i, int j, int ei1, int ei2) {
	int aux[ei2 - i + 1];
	int p1 = i;
	int p2 = j;
	int tar = 0;

	while (p1 <= ei1 and p2 <= ei2) {
		if (arr[p1] < arr[p2]) {
			aux[tar] = arr[p1];
			p1++;
			tar++;
		}
		else {
			aux[tar] = arr[p2];
			p2++;
			tar++;
		}
	}

	while (p1 <= ei1) {
		aux[tar] = arr[p1];
		tar++;
		p1++;
	}

	while (p2 <= ei2) {
		aux[tar] = arr[p2];
		p2++;
		tar++;
	}

	int re = 0;
	for (int u = i; u <= ei2; u++) {
		arr[u] = aux[re];
		re++;
	}

}


void realmergesort(int a[], int si,int ei){
    if(si >= ei){
        return;
    }
    int mid = (si+ei)/2;
    
    realmergesort(a,si,mid);
    realmergesort(a,mid+1,ei);
    
    mergeandreplace(a,si,mid+1,mid,ei);
    
	
}
void mergeSort(int input[], int size){
	// Write your code here
    int si = 0;
    int ei = size - 1;
    realmergesort(input,si,ei);
}
