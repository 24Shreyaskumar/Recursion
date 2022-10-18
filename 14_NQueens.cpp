//Problem of Bactracking
//optimiszed using the concept of hashing
//time complexity = 
//space complexity =
//auxillary space complexity = 

#include <bits/stdc++.h>
#define vi vector<int>
#define vs vector<string>
#define vb vector<bool>
#define vvs vector<vector<string>>
#define F(i, n, m) for (int i = n; i < m; i++)
using namespace std;

void display(vvs ans) {
    for (auto i : ans) {
        for (auto j : i) {
            F(k, 0, ans.size()) {
                cout<<j[k]<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n\n";
    }

    return;
}

void Solution(vs &board, vb &left, vb &upLeft, vb &downLeft, vvs &ans, int col) {
    if (col == board.size()) {
        ans.push_back(board);
        return;
    }

    F(row, 0, board.size()) {
        if (!left[row] && !upLeft[row + col] && !downLeft[board.size()-1 + col - row]) {
            board[row][col] = 'Q';
            left[row] = true;
            upLeft[row + col] = true;
            downLeft[board.size()-1 + col - row] = true;
            Solution(board, left, upLeft, downLeft, ans, col+1);
            downLeft[board.size()-1 + col - row] = false;
            upLeft[row + col] = false;
            left[row] = false;
            board[row][col] = '.';
        }
    }

    return;
}
 
int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin>>n;
    string sq;
    F(i, 0, n) sq += '.';
    vs board(n, sq);
    vb left(n, false), upLeft(2*n - 1, false), downLeft(2*n - 1, false);
    vvs ans;

    Solution(board, left, upLeft, downLeft, ans, 0);
    display(ans);

    return 0; 
}