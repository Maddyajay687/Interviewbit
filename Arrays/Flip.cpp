vector<int> Solution::flip(string A) {
    int n = A.size();
    vector<int> v(n);
    vector<int> res;
    for(int i = 0; i < n; i++) {
        if(A[i] == '0') {
            v[i] = 1;
        } else {
            v[i] = -1;
        }
    }
    
    int left = 0; 
    //int right = 0;
    int maxOnes = INT_MIN;
    int maxSum = 0;
    int leftAns = 0;
    int rightAns = 0;
    
    for(int i = 0; i < n; i++) {
        maxSum+=v[i];
        if(maxSum < 0) {
            left = i+1;
            maxSum = 0;
        } else if(maxSum > maxOnes) {
            leftAns = left;
            rightAns = i;
            maxOnes = maxSum;
        }
    }
    if(maxOnes <= 0) {
        return res;
    }
    
    res.push_back(leftAns+1);
    res.push_back(rightAns+1);
    
    return res;
}
s