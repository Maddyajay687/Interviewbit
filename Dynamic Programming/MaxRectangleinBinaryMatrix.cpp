int findArea(vector<int> &A) {
    int n = A.size();
    int i = 0;
    stack<int> s;
    int maxArea = 0;
    while(i < n) {
        if(s.empty() || A[s.top()] <= A[i]) {
            s.push(i++);
        } else {
            int top = s.top();
            s.pop();
            int area = A[top] * (s.empty()?i:i-s.top()-1);
            maxArea = max(area, maxArea);    
        }
    }
    while(!s.empty()) {
        int top = s.top();
        s.pop();
        int area = A[top] * (s.empty()?i:i-s.top()-1);
        maxArea = max(area, maxArea);  
    }
    
    return maxArea;
}

int Solution::maximalRectangle(vector<vector<int> > &A) {
    int row = A.size();
    int col = A[0].size();
    int area = 0;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(A[i][j] == 1 && i - 1 >= 0) {
                A[i][j] += A[i-1][j];
            }
        }
        area = max(area, findArea(A[i]));
    }
    
    return area;
}
