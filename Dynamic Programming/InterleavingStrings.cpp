int Solution::isInterleave(string A, string B, string C) {
    int len1 = A.length();
    int len2 = B.length();
    int len3 = C.length();
    if(len1 + len2 != len3) {
        return false;
    }
    vector<vector<bool>> dp(len1+1, vector<bool>(len2+1, false));
    dp[0][0] = true;
    for(int i = 1; i <= len1; i++) {
        dp[i][0] = A[i-1] == C[i-1] && dp[i-1][0];
    }
    for(int j = 1; j <= len2; j++) {
        dp[0][j] = B[j-1] == C[j-1] && dp[0][j-1];
    }
    
    for(int i = 1; i <= len1; i++) {
        for(int j = 1; j <= len2; j++) {
            bool res1 = dp[i-1][j]&& C[i+j-1] == A[i-1];
            bool res2 = dp[i][j-1]&& C[i+j-1] == B[j-1];
            dp[i][j] = res1 || res2;
        }
    }
    
    return dp[len1][len2];
}
