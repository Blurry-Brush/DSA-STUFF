#include <bits/stdc++.h>
#define ll long long
#define ld long double

using namespace std;


inline int max(int a, int b) { //copies the entire body of the function wherever is called
	return (a > b) ? a : b;
}

int main() {

	//pointers and const

	int i = 10;
	int j = 20;

	const int * p = &i;
	p = &j;  //yes
	(*p)++; //no


	int * const p2 = &i;
	p2 = &j; //no
	(*p2)++; //yes


	const int * const p3 = &i;
	p3 = &j; //no
	(*p3)++; //no




	return 0;
}
