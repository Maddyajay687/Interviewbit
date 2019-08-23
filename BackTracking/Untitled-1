bool filled(vector<vector<char>> &A, int n, int &row, int &col) {
    for(row = 0; row < n; row++) {
        for(col = 0; col < n; col++) {
            if(A[row][col] == '.') {
                return false;
            }
        }
    }
    return true;
}
bool inRow(vector<vector<char>> &A, int row, char val) {
    for(int col = 0; col < 9; col++) {
        if(A[row][col] == val) {
            return true;
        }
    }
    return false;
}

bool inCol(vector<vector<char>> &A, int col, char val) {
    for(int row = 0; row < 9; row++) {
        if(A[row][col] == val) {
            return true;
        }
    }
    return false;
}
bool inBox(vector<vector<char>> &A, int start, int end, char val) {
    for(int row = 0; row < 3; row++) {
        for(int col = 0; col < 3; col++) {
            if(A[row+start][col+end] == val) {
                return true;
            }
        }
    }
    return false;
    
}

bool isSafe(vector<vector<char>> &A, int row, int col, char val) {
    return !inRow(A, row, val) &&
           !inCol(A, col, val) &&
           !inBox(A, row-row%3, col-col%3, val)
           && A[row][col] == '.';
}

bool solve(vector<vector<char>> &A, int n) {
    int row;
    int col;
    if(filled(A, n, row, col)) 
        return true;
    for(char c = '1'; c <= '9'; c++) {
        if(isSafe(A,row, col, c)) {
            A[row][col] = c;
            if(solve(A,n)) {
                return true;
            }
            A[row][col] = '.';
        }
    }
    
    return false;
}

void Solution::solveSudoku(vector<vector<char> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n =A.size();
    bool ans = solve(A, n);
    
}


