#include <string.h>
#include <string>
using namespace std;

int getCodes(string input, string output[10000]) {
    /*
    You are given the input text and output string array. Find all possible codes and store in the output string array. Don’t print the codes.
    Also, return the number of codes return to the output string. You do not need to print anything.
    */
    //no of rows in the output
    if(input.empty()){
    	output[0] = "";
        return 1;
    }
    
    int first,second;
    char firstchar,secondchar;
    int ans1,ans2;
    string result1[500];
    string result2[500];
    
    
    first = input[0] - 48;
    firstchar = first + 'a' - 1;
    
    ans1 = getCodes(input.substr(1), result1);
    ans2 = 0;
    secondchar = '\0';
    
    if(input[1] != '\0'){
        int second = first*10 + input[1] - 48;
        if(second >= 10 and second <= 26){
            secondchar = second + 'a' - 1;
            ans2 = getCodes(input.substr(2), result2);
        }
            
    }
    
    int row = 0;
     for(int i = 0; i < ans1; i++){
        output[row] = firstchar + result1[i];
         row++;
    }
 	  
    for(int i =0 ; i < ans2; i++){
            output[row] = secondchar + result2[i];
        row++;
        }
    
    return ans1+ans2;
    
}

