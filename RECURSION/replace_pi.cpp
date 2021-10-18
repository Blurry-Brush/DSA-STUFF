// Change in the given string itself. So no need to return or print anything
int len(char a[]){
	int ans = 0;
    for(int i = 0; a[i] != '\0'; i++){
        ans++;
    }
    return ans;
}
void replacePi(char input[]) {
	// Write your code here
    if(len(input) <= 1){
        return;
    }
    
    replacePi(input+1);
    
    if(input[0] == 'p' and input[1] == 'i'){
        for(int i = len(input) ; i >=2 ;i--){
			input[i+2] = input[i];
        }
        
        input[0] = '3';
        input[1] = '.';
        input[2] = '1';
        input[3] = '4';
    }

}


