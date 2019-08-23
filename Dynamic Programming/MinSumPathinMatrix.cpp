int Solution::minPathSum(vector<vector<int> > &A) {
    int row = A.size();
    int col = A[0].size();
    for(int i = 1; i < row; i++) {
        A[i][0] = A[i-1][0] + A[i][0]; 
    }
    for(int j = 1; j < col; j++) {
        A[0][j] = A[0][j] + A[0][j-1];
    }
    
    for(int i = 1; i < row; i++) {
        for(int j = 1; j < col; j++) {
            A[i][j]+= min(A[i-1][j], A[i][j-1]);
        }
    }
    
    return A[row-1][col-1];
}
