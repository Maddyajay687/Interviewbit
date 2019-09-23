int Solution::maxArr(vector<int> &A) {
    int n = A.size();
    vector<int> temp(n);
    vector<int> temp2(n);
    int maxVal = INT_MIN;
    
    for(int i = 0; i < n; i++) {
       temp[i] = A[i] + i;
       temp2[i] = A[i]-i;
    }
    
    
    int max1 = *max_element(temp2.begin(), temp2.end());
    int min1 = *min_element(temp2.begin(), temp2.end());
    int max2 = *max_element(temp.begin(), temp.end());
    int min2 = *min_element(temp.begin(), temp.end());
    
    return max(max1-min1, max2-min2);
}
