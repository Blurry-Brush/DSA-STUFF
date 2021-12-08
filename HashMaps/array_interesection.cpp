#include <unordered_map>
void intersection(int *input1, int *input2, int size1, int size2)
{
    if(size1 == 0 or size2 == 0){
        return;
    }
    //Write your code here
    unordered_map<int,int> st;
    
    for(int i =0; i < size2; i++){
        st[input2[i]]++;
    }
    
    for(int i = 0; i < size1; i++){
	
        
        if(st[input1[i]] > 0){
            cout << input1[i] <<" ";
            st[input1[i]]--;
        }
		        
    }
    
   
}
