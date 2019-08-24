int Solution::calculateMinimumHP(vector<vector<int> > &A) {
    int row = A.size();
    int col = A[0].size();
    vector<vector<int>> dp(row, vector<int>(col, 1));
    
    for(int i = row-2; i >= 0; i--) {
        dp[i][col-1] = max(1, dp[i+1][col-1] - A[i+1][col-1]);
    }
    for(int i = col-2; i >= 0; i--) {
        dp[row-1][i] = max(1, dp[row-1][i+1] - A[row-1][i+1]); 
    }
    
    for(int i = row - 2; i >= 0; i--) {
        for(int j = col-2; j >= 0; j--) {
            dp[i][j] = min(max(1, dp[i+1][j] - A[i+1][j]),
                            max(1, dp[i][j+1] - A[i][j+1]));
        }
    }
    
    return max(1, dp[0][0] - A[0][0]);
}
