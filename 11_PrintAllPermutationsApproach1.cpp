//time complexity = O(n * n!)
//space complexity = O(n + n)
//auxillary space complexity = O(n)

#include <bits/stdc++.h>
#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define F(i, n, m) for (int i = n; i < m; i++)
using namespace std;

void display(vvi sol) {
    for (auto i : sol) {
        for(auto j : i) cout<<j<<" ";
        cout<<"\n";
    }
    return;
}

void Solution(vi v, vi &ans, vb &truthVal, vvi &sol, int n) {
    if (ans.size() == n) {
        sol.push_back(ans);
        return;
    }

    F(i, 0, n) {
        if (!truthVal[i]) {
            ans.push_back(v[i]);
            truthVal[i] = true;
            Solution(v, ans, truthVal, sol, n);
            truthVal[i] = false;
            ans.pop_back();
        }
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin>>n;
    vi v, ans;
    F(i, 0, n) {
        int x; cin>>x;
        v.push_back(x);
    }
    vb truthVal(n);
    fill(truthVal.begin(), truthVal.end(), false);
    vvi sol;

    Solution(v, ans, truthVal, sol, n);
    cout<<"\n\nOUTPUT : \n";
    display(sol);

    return 0;
}