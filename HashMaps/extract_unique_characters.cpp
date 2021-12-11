#include <bits/stdc++.h>

#define fo(i,n) for(int  i = 0;i<n;i++)
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ull unsigned long long


using namespace std;

vector<int> removeDuplicates(int * a , int size) {
    vector<int> output;
    unordered_map<int, bool> seen;

    for (int i = 0; i < size; i++) {
        if (seen[a[i]] != true) {
            output.push_back(a[i]);
        }
        seen[a[i]] = true;
    }

    return output;
}


int ZeroPairSum(int n, vector<int> arr) {
    // Write your code here
    int count = 0;

    unordered_map<long long, long long> mp;

    for (int i = 0; i < n ; i++) {
        mp[arr[i]]++;
    }

    for (int i = 0; i < n; i++) {
        int compliment = -1 * arr[i];

        if (compliment == arr[i]) {
            //zero
            count += mp[arr[i]] / 2;
        }
        if (mp.count(compliment) > 0) {
            count += mp[arr[i]] * mp[compliment];
            mp[arr[i]] = 0;
            mp[arr[compliment]] = 0;
        }

    }

    return count;
}

void printVector(vector<int> a) {
    for (auto value : a) {
        cout << value << " ";
    }
    cout << endl;
}
string extractuniquechars(string s) {

    string ans;
    unordered_map<char, bool> mpp;
    for (int i = 0; i < s.size(); i++) {
        mpp[s[i]] = true;
    }

    for (int i = 0; i < s.size(); i++) {
        if (mpp[s[i]] == true) {
            ans += s[i];
            mpp[s[i]] = false;
        }
    }


    return ans;

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    cout << extractuniquechars(s) << endl;
    return 0;

}
