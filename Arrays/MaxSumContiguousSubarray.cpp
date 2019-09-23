int Solution::maxSubArray(const vector<int> &A) {
    int n = A.size();
    int sum_here = A[0];
    int max_sum = A[0];
    for(int i = 1; i < n; i++) {
        sum_here = max(A[i], sum_here+A[i]);
        max_sum = max(max_sum, sum_here);
    }
    return max_sum;
}
