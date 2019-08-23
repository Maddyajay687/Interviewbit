int Solution::climbStairs(int A) {
    vector<int> dp(40,0);
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i < dp.size(); i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[A];
}
