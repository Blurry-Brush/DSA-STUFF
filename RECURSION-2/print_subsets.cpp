void help(int input[], int size, int output[], int m){
    if(size == 0){
        for(int i = 0; i < m; i++){
            cout << output[i] << " ";
        }
        cout << endl;
        return;
    }
    //in print things do our work first.
    
    help(input+1,size-1,output,m); //not include
    int newoutput[m+1];
    for(int i = 0; i <m;i++){
        newoutput[i] = output[i];
    }
    newoutput[m] = input[0];
    help(input+1,size-1,newoutput,m+1); //include
}
int pow1(int x) {
	if (x == 0) {
		return 1;
	}

	int small = pow1(x - 1);
	return 2 * small;
}
void printSubsetsOfArray(int input[], int size) {
	// Write your code here
	int x = pow1(size);
    int output[x];
    int m = 0;
    help(input,size,output,m);
    
}
