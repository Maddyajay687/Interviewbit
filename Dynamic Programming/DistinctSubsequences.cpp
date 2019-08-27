int solve(string s1, int len1, string s2, int len2) {
    /* Recursive Solution
    if(len2 == 0) {
        return 1;
    } else if(len1 == 0 || len2 == 0) {
        return 0;
    }
    if(s1[len1-1] == s2[len2-1]) {
        return solve(s1, len1-1, s2, len2-1) 
        + solve(s1, len1-1,s2, len2);
    } else {
        return solve(s1, len1-1, s2, len2);
    } */
    vector<vector<long long>> dp(len1+1, vector<long long>(len2+1, 0));
    for(int i = 0; i <= len1; i++) {
        dp[i][0] = 1;
    }
    for(int i = 1 ; i <= len1; i++) {
        for(int j = 1; j <= len2; j++) {
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[len1][len2];
}

int Solution::numDistinct(string A, string B) {
    int len1 = A.length();
    int len2 = B.length();
    return solve(A, len1, B, len2);
}
