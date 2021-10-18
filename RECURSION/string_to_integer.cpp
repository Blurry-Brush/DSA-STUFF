int len(char a[]){
    int ans = 0;
    for(int i = 0; a[i] != '\0'; i++){
        ans++;
    }
    
    return ans;
}

int help(char s[], int size){
    if(size == 1){
        return s[0] - '0';
    }
    
    int smallans = help(s+1, size - 1);
    int b = s[0] - '0';
    
    int k = 1; //pow function
    for(int i = 1; i <= len(s) - 1;i++){
        k *= 10;
    }
    int ourwork = b*k; 
    return ourwork + smallans;
}


int stringToNumber(char input[]) {
    // Write your code here
	int n = len(input);
    help(input,n);
    
}


