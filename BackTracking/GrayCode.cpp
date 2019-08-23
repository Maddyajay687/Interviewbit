vector<int> Solution::grayCode(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> v;
    for(int i = 0; i < 1<<A; i++) {
        int t = i^i>>1;
        v.push_back(t);
    }
    
    return v;
    
}
