int Solution::nchoc(int A, vector<int> &B) {
    int n = B.size();
    priority_queue<int> pq;
    for(int i = 0; i < B.size(); i++) {
        pq.push(B[i]);
    }
    int mod = 1000000007;
    unsigned long long int total = 0;
    for(int i = 0; i < A; i++) {
        int temp = pq.top();
        total = (total %mod + temp%mod)%mod;
        
        pq.pop();
        pq.push(temp/2);
    }
    return total;
}
