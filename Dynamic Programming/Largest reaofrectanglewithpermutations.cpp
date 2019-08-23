int Solution::solve(vector<vector<int> > &A) {
    //vector<vector<int>> dp(A.size(), vector<int>(A.size(), 0));
    
    int row = A.size();
    int  col = A[0].size();
    int area = 0;
    vector<vector<int>> dp(row, vector<int>(col, 0));
    
    dp[0] = A[0];
    for(int i = 1; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(A[i][j] == 1) {
                dp[i][j] = 1 + dp[i-1][j];
            }
        }
    }
    
    for(int i = 0; i < row; i++) {
       // int count[row+1] = {0};
        vector<int> count(row+1, 0);
        for(int j = 0; j < col; j++) {
            count[dp[i][j]]++;
        }
        int col_no = 0;
        for(int j = row; j >= 0; j--) {
            if(count[j] > 0) {
                for(int k = 0; k < count[j]; k++) {
                    dp[i][col_no] = j;
                    col_no++;
                }
            }
        }
    }
    int curr_area = 0;
    int max_area = 0;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            curr_area = (j+1) * dp[i][j];
            max_area = max(curr_area, max_area);
        }
    }
    
    return max_area;
}
