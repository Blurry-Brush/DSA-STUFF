#include <unordered_set>

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
            
            if(nums.size() == 0){
                    return 0;
            }
            int cur = 0;
            int ans = 0;
            unordered_set<int> st;
            
            for(int i = 0; i < nums.size() ; i++){
                st.insert(nums[i]);
            }
            
            for(int i = 0; i < nums.size() ; i++){
                if(st.count(nums[i] - 1) > 0){
                        //this is not the minimal
                }
                    else{
                            //++
                            while(st.count((nums[i] + 1)) > 0){
                                    cur++;
                                    nums[i]++;
                            }
                            ans = max(ans,cur);
                            cur = 0;
                    }
            }
            return ans + 1;
    }
};
