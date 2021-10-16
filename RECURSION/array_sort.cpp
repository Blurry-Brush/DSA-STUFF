#include <iostream>

using namespace std;


int is_sorted(int a[] , int size) {
	if (size == 0 or size == 1) { //base case
		return true;
	}


	if (a[0] > a[1]) {
		return false; //our work
	}
	bool smalleroutput = is_sorted(a + 1, size - 1); //a+1 is the pointer technique
	return smalleroutput;
}

int is_sorted2(int a[], int size) {
	if (size == 0 or size == 1) { //base case
		return true;
	}

	bool smallersorted = is_sorted2(a + 1, size - 1);

	if (!smallersorted) {
		return false;
	}


	if (a[0] > a[1]) {
		return false;
	}
	else {
		return true;
	}
}
int main(){

  return 0;
}
