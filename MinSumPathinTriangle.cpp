int Solution::minimumTotal(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = A.size();
    
    for(int i = 1; i < n; i++) {
        int len = A[i].size();
        A[i][0] = A[i][0] + A[i-1][0];
        A[i][len-1] = A[i-1][len-2] + A[i][len-1];
        for(int j = 1; j < len-1; j++) {
            A[i][j] = min(A[i-1][j] + A[i][j], 
                        A[i-1][j-1] + A[i][j]);
        }
    }
    return *min_element(A[n-1].begin(), A[n-1].end());
}
