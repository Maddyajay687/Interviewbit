/*int solve(string &A, int len) {
    if(len == 0 || len == 1) {
        return 1;
    }
    if(A[0] == '0') {
        return 0;
    }
    int count = 0;
    if(A[len-1] > '0') {
        count = solve(A, len-1);
    }
    if(A[len-2] == '1' || (A[len-2] == '2' && A[len-1] < '7')) {
        count+= solve(A, len-2);
    }
    return count;
}
 */
 
int Solution::numDecodings(string A) {
    vector<int> dp(A.length()+1, 0);
    
    if(A[0] == '0') {
        return 0;
    }
    dp[0] = 1;
    dp[1] = 1;
    
    for(int i = 2; i <= A.length();  i++) {
        if(A[i-1] > '0') {
            dp[i] = dp[i-1];
        }
        if(A[i-2] == '1' || (A[i-2] == '2' && A[i-1] < '7')) {
            dp[i]+=dp[i-2];
        }
    }
    return dp[A.length()];
    //return solve(A, A.size());
}
