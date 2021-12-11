#include <unordered_map>
int lengthOfLongestSubarray(int arr[],int n)
{
    unordered_map<int,int> mpp;
    int i = -1;
    int sum = 0;
    int maxlen = 0;
    mpp[sum] = i;
    
    while(i < n - 1){
        i++;
        sum += arr[i];
        
        if(!mpp.count(sum)){
            mpp[sum] = i;
        }
        else{
			int len = i - mpp[sum];
            maxlen = max(maxlen, len);
        }
    }
    return maxlen;
    
}
