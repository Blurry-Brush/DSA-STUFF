#include <queue>
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
//         priority_queue<int> pq;
        
//             for(int i = 0; i < nums.size();i++){
//                     pq.push(nums[i]);
//             }
//             // TC : O(nlogn)
               //SC  : O(n)            
//             int t = k-1;
//             while(t--){
//                     pq.pop();
//             }
//             return pq.top();
            
            
            priority_queue<int, vector<int> , greater<int> > pq;
            //min heap
            //tc : O(nlogk)
            //sc : O(k)
            
            for(int i = 0; i < k;i++){
                pq.push(nums[i]);
        }
            
            for(int i = k; i < nums.size();i++){
                    if(nums[i] > pq.top()){
                            pq.pop();
                            pq.push(nums[i]);
                    }
            }
            
            return pq.top();
    }
};
