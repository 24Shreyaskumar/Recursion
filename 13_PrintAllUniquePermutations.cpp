//time complexity = 
//space complexity = 
//auxillary space complexity = O(n)

#include <bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vector<int>> 
#define F(i, n, m) for (int i = n; i < m; i++)
using namespace std;

void display(vvi ans) {
    int count = 0;
    cout<<"\nOutput : \n";
    for (auto i : ans) {
        cout<<count<<"] ";
        for (auto j : i) cout<<j<<" ";
        cout<<"\n";
        count++;
    }
    return;
}

void Solution(vi &v, vvi &ans, int it) {
    if (it == v.size()) {
        ans.push_back(v);
        return;
    }

    F(i, it, v.size()) {
        if (i > it && v[i] == v[i-1]) continue;
        swap(v[i], v[it]);
        Solution(v, ans, it+1);
        swap(v[i], v[it]);
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin>>n;
    vi v;
    F(i, 0, n) {
        int x; cin>>x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    vvi ans;

    Solution(v, ans, 0);
    display(ans);
    
    return 0;
}
