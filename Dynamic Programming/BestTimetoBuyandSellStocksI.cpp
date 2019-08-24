int Solution::maxProfit(const vector<int> &A) {
    int n = A.size();
    if(n <= 1){
        return 0;
    }
    int buy_price = 0;
    int max_profit = A[0];
    
    for(int i = 1; i < n; i++) {
        buy_price = min(buy_price, A[i-1]);
        max_profit = max(buy_price, A[i] - buy_price);
    }
    return max_profit;
}
