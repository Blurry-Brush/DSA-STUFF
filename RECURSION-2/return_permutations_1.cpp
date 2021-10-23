#include <string>
#include <valarray>

using namespace std;

int returnPermutations(string input, string output[]){
   	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
    if(input.empty()){
        output[0] = "";
        return 1;
    }
    int row = 0;
    for(int i = 0; i < input.length(); i++){
        char cur = input[i];
        string smalloutput[1000];
        string small = input.substr(0,i) + input.substr(i+1);
        
        int smallans = returnPermutations(small,smalloutput);
        for(int i = 0; i < smallans; i++){
            output[row] = cur + smalloutput[i];
            row++;
        }
    }
    return row;
}
