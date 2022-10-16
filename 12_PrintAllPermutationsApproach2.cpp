//time complexity = 
//space complexity = 
//auxillary space complexity = 

//how is it different from approach 1 ? => we will not be using a map or the extra space consumed by the truthVal array

#include <bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vector<int>>
#define F(i, n, m) for (int i = n; i < m; i++)
using namespace std;

void display(vvi sol) {
    cout<<"\nOutput : \n";
    for (auto i : sol) {
        for (auto j : i) cout<<j<<" ";
        cout<<"\n";
    }
    return;
}

void Solution(vi &v, vvi &sol, int it) {
    if (it == v.size()) {
        sol.push_back(v);
        return;
    }

    F(i, it, v.size()) {
        swap(v[i], v[it]);
        Solution(v, sol, it+1);
        swap(v[i], v[it]);
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
    vvi sol;

    Solution(v, sol, 0);
    display(sol);

    return 0;
}