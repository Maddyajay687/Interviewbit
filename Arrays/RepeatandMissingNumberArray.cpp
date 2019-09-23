typedef long long int ll;
vector<int> Solution::repeatedNumber(const vector<int> &A) {
    ll n = A.size();
    int a;
    int B;
    ll sum = 0;
    ll sum2 = 0;
    vector<int> v;
    for(ll i = 0; i < n; i++) {
        sum+= (ll)A[i];
        sum2+= (ll)A[i] * (ll)A[i];
    }
    ll diff1 = ((n * (n+1))/2) - sum;
    ll diff2 = ((n * (n+1) * (2 * n + 1))/6) - sum2;
    
    ll rat = diff2/diff1;
    
    a = (rat-diff1)/2;
    B = (rat + diff1)/2;

    v.push_back(a);
    v.push_back(B);
    return v;
}
