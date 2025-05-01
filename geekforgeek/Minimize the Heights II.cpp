Given an array arr[] denoting heights of N towers and a positive integer K.

For each tower, you must perform exactly one of the following operations exactly once.

Increase the height of the tower by K
Decrease the height of the tower by K
Find out the minimum possible difference between the height of the shortest and tallest towers after you have modified each tower.

You can find a slight modification of the problem here.
Note: It is compulsory to increase or decrease the height by K for each tower. After the operation, the resultant array should not contain any negative integers.

Examples :

Input: k = 2, arr[] = {1, 5, 8, 10}
Output: 5
Explanation: The array can be modified as {1+k, 5-k, 8-k, 10-k} = {3, 3, 6, 8}.The difference between the largest and the smallest is 8-3 = 5.
Input: k = 3, arr[] = {3, 9, 12, 16, 20}
Output: 11
Explanation: The array can be modified as {3+k, 9+k, 12-k, 16-k, 20-k} -> {6, 12, 9, 13, 17}.The difference between the largest and the smallest is 17-6 = 11. 
Constraints
1 ≤ k ≤ 107
1 ≤ n ≤ 105
1 ≤ arr[i] ≤ 107


// idea:
  // greedy algorithm. Thang lon se LUON LUON DECREASE K, thang be LUON LUON INCREASE K
  // b1: sort
  // b2: init res = arr[n-1] - arr[0]
  // b3: largest = arr[n-1] - k; smallest = arr[0]+k;
  // b4: for i -> n-1: high = max(largest,arr[i]+k); // thang be luon tang low = min(smallest, arr[i+1]-k); 

  class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        // code here
        sort(arr.begin(), arr.end());
        int n = arr.size();
        if (arr.size() == 1) return 0;
        
        int res = arr[n-1] - arr[0];
        
        
        int largest = arr[n-1]-k;
        int smallest = arr[0]+k;
        
        for(int i = 0; i < n-1; ++i){
            int high = max(arr[i]+k,largest); // thang i luon nho hon, nen de no increase la dung
            int low = min(arr[i+1]-k, smallest); // thang i+1 luon lon hon, nen de no decrease la dung
            if (low < 0){
                continue;
            }
            res = min(res,high-low);
        }
        return res;
    }
};
  
  
