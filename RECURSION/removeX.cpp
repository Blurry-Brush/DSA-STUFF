// Change in the given string itself. So no need to return or print anything
int len(char a[]){
    int ans = 0;
    for(int i = 0; a[i] != '\0'; i++){
        ans++;
    }
    return ans;
}

void help(char ar [] , int size,int count){
	
    if(size == 0){
        return;
    }
    
    help(ar+1 ,size - 1,count);
    if(ar[count] == 'x'){
		for(int i = count; i < size; i++){
			ar[i] = ar[i+1]; //including null character.
        }        
    }
}

void removeX(char input[]) {
    // Write your code here
   	int n = len(input);
    int count = 0;
    help(input,n,count);
}
