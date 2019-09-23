int Solution::coverPoints(vector<int> &A, vector<int> &B) {
    int steps = 0;
    int x = 0;
    int y = 0;
    for(int i = 1; i < A.size(); i++) {
        x = A[i] - A[i-1];
        y = B[i] - B[i-1];
        steps+= max(abs(x), abs(y));
    }
    return steps;
}
