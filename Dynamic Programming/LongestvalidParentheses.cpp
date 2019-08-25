int Solution::longestValidParentheses(string A) {
    int len = A.length();
    vector<int> dp(len, 0);
    
    for(int i = 1; i < len; i++) {
        if(A[i] == '(') {
            continue;
        }
        if(A[i-1] == '(') {
            dp[i] = i-2>=0?2+dp[i-2]:2;
        } 
        if(i - dp[i-1]-1 >= 0 && A[i-dp[i-1]-1] == '(') {
            dp[i] = i-dp[i-1]-2>=0?2+dp[i-1]+dp[i-dp[i-1]-2]:2+dp[i-1];
        }
    }
    return *max_element(dp.begin(), dp.end());
    
    
}
