int Solution::jump(vector<int> &A) {
    int n = A.size();
    if(n > 1 && A[0] == 0) {
        return -1;
    }
    if(n == 0 || n == 1 || A[0] == 0) {
        return 0;
    }
    int ladder = A[0];
    int stairs = A[0];
    int jump = 1;
    for(int i = 1; i < A.size(); i++) {
        if(i == A.size()-1) {
            return jump;
        }
        ladder = max(ladder, i + A[i]);
        stairs--;
        if(stairs == 0) {
            jump++;
            if(i >= ladder) {
                return -1;
            }
            stairs = ladder - i;
        }
    }
    return jump;
}
