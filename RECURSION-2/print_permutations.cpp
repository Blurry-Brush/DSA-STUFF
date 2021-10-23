#include <iostream>
#include <string>
using namespace std;

void help_onichan(string input,string output){
    if(input.empty()){
        for(int i = 0; i < output.length(); i++){
            cout << output[i];
        }
        cout << endl;
    }
    
    for(int i = 0; i < input.length(); i++){
        char cur = input[i];
     string small = input.substr(0,i) + input.substr(i+1);
        help_onichan(small, cur + output);
    }
}
void printPermutations(string input){

    	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
    string output;
    help_onichan(input,output);
}
