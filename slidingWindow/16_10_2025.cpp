void bai2(){
    /*
    Given a string S of size N consisting of the characters 
    0, 1 and 2, the task is to find 
    the length of the smallest substring of string S that 
    contains all the three characters 0, 1 and 2. 
    If no such substring exists, then return -1.

    Examples:
    
    Input: S = "01212"
    Output: 3
    Explanation: The substring 012 
    is the smallest substring that contains the characters 0, 1 and 2.
    
    Input:  S = "12121"
    Output: -1
    Explanation:  As the character 0 
    is not present in the string S, 
    therefore no substring containing 
    all the three characters 0, 1 and 2 exists. 
    Hence, the answer is -1 in this case.
    */
    string S = "12121";
    int n = S.size();
    int freq[3] = {0};
    int cnt = 0; // dem du co 0 1 2 khong
    int res = INT_MAX;
    int i = 0, j = 0;
    while(j < n){
        freq[S[j]-'0'] += 1;
        if (freq[S[j]-'0'] == 1) cnt += 1;
        if (cnt == 3){
            while(i < j && freq[S[i]-'0'] > 1) {
                freq[S[i]-'0'] -= 1;
                i += 1;
            }
            
            res = min(res,j-i+1);
            // de co the tiep tuc move window
            freq[S[i]-'0'] -= 1;
            i += 1;
            cnt -= 1;
        }
        j += 1;
    }
    cout<<"Smallest window is: "<<res<<"\n";
}




