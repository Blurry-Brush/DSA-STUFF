int length(char a[]){
    int ans = 0;
    for(int i = 0; a[i] != '\0'; i++){
        ans++;
    }
    return ans;
}
bool helper(char str[], int start,int end){
    
    
    if(start >= end){
		return true;
    }
    if(str[start] != str[end]){
        return false;
    }
   	if(start < end+1){
        return helper(str,start+1,end-1);
    }
    return true;
    
}

bool checkPalindrome(char input[]) {
    // Write your code here
    int n = length(input);
  
    /*if(n == 0){
        return true;
    }*/
    
	return helper(input,0 , n - 1);    
}


