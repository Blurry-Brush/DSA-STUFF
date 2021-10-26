int check(int arr[], int start, int end) {
	if (end < start) {
		return 0;
	}
	if (start == end) {
		return start;
	}
	int mid = (start + end) / 2;

	//check if mid element is the min element.
	if (start < end and arr[mid - 1] > arr[mid]) {
		return mid;
	}
	//check if mid+1 element is the min element.

	if (start < end and arr[mid] > arr[mid + 1]) {
		return mid + 1;
	}

	//binary search
	if (arr[mid] > arr[end]) {
		//right side.
		return check(arr, mid + 1, end);
	}
	return check(arr, start, mid - 1);
}
