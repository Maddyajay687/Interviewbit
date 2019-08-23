int Solution::longestSubsequenceLength(const vector<int> &A) {
    int n = A.size();
    if(n == 0) {
        return 0; 
    }
    vector<int> dpLeft(n,1);
    vector<int> dpRight(n,1);
    
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(A[j] < A[i]) {
                dpLeft[i] = max(dpLeft[i], 1+dpLeft[j]);
            }
        }
    }
   
    for(int i = n-2; i>= 0; i--) {
        for(int j = n-1; j>i; j--) {
            if(A[j] < A[i]) {
                dpRight[i] = max(dpRight[i], 1+dpRight[j]);
            }
        }
    }
    int ans = INT_MIN;
    for(int i = 0; i < n; i++) {
        ans = max(ans, dpLeft[i] + dpRight[i]);
    }
    return ans-1;
    
}
