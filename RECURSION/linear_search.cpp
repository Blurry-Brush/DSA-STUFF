bool checkNumber(int input[], int size, int x) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */
    if(size == 0){
        return false;
    }
    
	bool findinrest = checkNumber(input+1,size-1,x);
    if(findinrest){
        return true;
    }
    else if(input[0] == x){
        return true;
        
    }
    else{
        return false;
    }
}