int maximumFrequency(vector<int> &arr, int n)
{
    
    //Write your code here
    unordered_map<int,int> mp;
   	
    for(int i = 0; i < n; i++){
        mp[arr[i]]++;
    }
    
    int element;
    int maxFreq = 0;
    for(int i = 0; i < n; i++){
        if(mp[arr[i]] > maxFreq){
            element = arr[i];
            maxFreq = mp[arr[i]];
        }
    }
    
    return element;
}
