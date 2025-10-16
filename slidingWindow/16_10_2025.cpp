#include <bits/stdc++.h>

using namespace std;

void bai1(){
    vector<int> arr{2,3};
    int k = 1;
    
    
    int n = arr.size();
    int maxSum = INT_MIN;
    int curSum = 0;
    for(int i  =0; i < k; ++i){
        curSum += arr[i];
    }
    for(int i = k; i < n; ++i){
        curSum += arr[i] - arr[i-k];
        maxSum = max(maxSum,curSum);
    }
    cout<<"maxSum: "<<maxSum<<"\n";
}
void bai2(){
    string S = "12121";
    
    int freq[3] = {0};
    int cnt = 0;
    int i = 0; int j = 0;
    int res = INT_MAX;
    int n = S.size();
    while(j < n){
        freq[S[j]-'0'] += 1;
        if (freq[S[j]-'0'] == 1) cnt += 1;
        if (cnt == 3){
            while(freq[S[i]-'0'] > 1) {
                freq[S[i]-'0'] -= 1;
                i += 1;
            }
            res = min(res,j-i+1);
            freq[S[i]-'0'] -= 1;
            i += 1;
            cnt -= 1;
        }
        j += 1;
    }
    cout<<"min substring: "<<res<<"\n";
        
    
}
void bai3(){
    string txt = "geeks";
    string pat = "eke";
    
    vector<int> freq(26,0);
    for(int i = 0; i < pat.size(); ++i){
        freq[txt[i]-'a'] += 1;
        freq[pat[i]-'a'] -= 1;
    }
    // checking if we found the substring is permutation
    // for(int i =0; i < 26; ++i){
    //     if (freq[i] != 0) {
    //         cout<<""
    //     }
    // }
    for(int i = pat.size(); i < txt.size(); ++i){
        freq[txt[i]-'a'] += 1;
        freq[txt[i-pat.size()]-'a'] -= 1;
        
    }
}




