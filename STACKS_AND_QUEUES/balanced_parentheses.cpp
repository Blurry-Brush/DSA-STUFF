#include <stack>
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
            
        if(s.size() == 1){
                return false;
        }
            
        for(int i = 0; s[i] != '\0'; i++){
                if(s[i] == '{' or s[i] == '(' or s[i] == '['){
                        st.push(s[i]);
                }
                else{
                        if(s[i] == ')'){
                                if(st.empty()){
                                        return false;
                                }
                                if(st.top() == '(' ){
                                        st.pop();
                                        
                                }
                                else{
                                        return false;
                                }
                        }
                        else if(s[i] == '}'){
                                  if(st.empty()){
                                        return false;
                                }
                                if(st.top() == '{'){
                                        st.pop();
                                }
                                else{
                                        return false;
                                }
                        }
                        else if(s[i] == ']'){
                                  if(st.empty()){
                                        return false;
                                }
                                 if(st.top() == '['){
                                        st.pop();
                                }
                                else{
                                        return false;
                                }
                        }
                }
        }
            
            if(!(st.empty()) ){
                    return false;
            }
            return true;
    }
};
