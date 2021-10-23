#include <string.h>
#include <string>

using namespace std;

void realprint(string input, string ans){
    if(input.empty()){
        for(int i =0 ; i < ans.length(); i++){
            cout << ans[i];
        }
        cout << endl;
        return;
    }
    int first,second;
    char firstchar,secondchar;
	first = input[0] - 48;
    firstchar = first + 'a' - 1;
    
    realprint(input.substr(1), ans + firstchar);
    
    if(input[1] != '\0'){
        second = 10*first + input[1] - 48;
        if(second >= 10 and second <= 26){
        	secondchar = second + 'a' - 1;
            
            realprint(input.substr(2), ans + secondchar);
        }
    }
 //in print we do our work first and also pass output so far in the recursive call.   
}
void printAllPossibleCodes(string input) {
    /*
    Given the input as a string, print all its possible combinations. You do not need to return anything.
    */
    string output;
    realprint(input, output);
}

