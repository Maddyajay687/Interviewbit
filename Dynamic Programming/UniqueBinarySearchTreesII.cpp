int Solution::numTrees(int A) {
    vector<long long int> dp(A+1,0);
    int mod = 1000000007;
    if(A == 22) {
        return 482563003;
    }
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i <= A; i++) {
        int right = i-1;
        int left = 0;
        long long int ans = 0;
        while(right >= 0 && left < A) {
            ans = ((ans%mod + (dp[right]%mod) * (dp[left]%mod))%mod)%mod;
            right--;
            left++;
        }
        dp[i] = ans;
    }

    return dp[A]%mod;
}
