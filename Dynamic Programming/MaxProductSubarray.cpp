int Solution::maxProduct(const vector<int> &A) {
    int n = A.size();
    int curr_max = A[0];
    int max_here = A[0];
    int min_here = A[0];
    
    for(int i = 1; i < n; i++) {
        int curr_max_here = max(max_here * A[i], max(min_here * A[i], A[i]));
        int curr_min_here = min(max_here * A[i], min(min_here * A[i], A[i]));
        
        int temp = max(curr_max_here, curr_min_here);
        curr_max = max(curr_max, temp);
        
        max_here = curr_max_here;
        min_here = curr_min_here;
    }
    
    return curr_max;
}
