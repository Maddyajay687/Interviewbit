int Solution::lis(const vector<int> &A) {
    int len = A.size();
    vector<int> dp(len, 1);
    for(int i = 1; i < len; i++) {
        for(int j = 0; j < i; j++) {
            if(A[i] > A[j]) {
                //cout<<"True";
                dp[i] = max(dp[i], 1+dp[j]);
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}

