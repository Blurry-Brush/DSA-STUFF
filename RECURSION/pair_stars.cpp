// Change in the given string itself. So no need to return or print the changed string.
int len(char a[]){
    int ans = 0;
    for(int i = 0; a[i] != '\0'; i++){
		ans++;
    }
    return ans;
}
void help(char a[], int size){
	if(size == 0){
        return;
    }
    
    help(a+1,size-1);
    if(a[0] == a[1]){
        for(int i = len(a); i >= 1;i--){ //including the null character.
            a[i+1] = a[i];
        }
        
        a[1] = '*';
    }
}
void pairStar(char input[]) {
    // Write your code here
	int n = len(input);
    help(input,n);
}
