//time complexity = O(2^n)
//space complexity = O(n^2)
//assuming the array to presorted

//Brute Force : 
// #include <bits/stdc++.h>
// #define vi vector<long long int>
// #define F(i, n, m) for (int i = n; i < m; i++) 
// #define ll long long int 
// using namespace std;

// set<vi> sol;

// void display(set<vi> sol) {
//     for (auto row : sol) {
//         for (auto i : row) cout<<i<<" ";
//         cout<<"\n";
//     }

//     return;
// }

// void Solution(vi v, int n, vi ans, int it, ll k) {
//     if (k == 0) {
//         sol.insert(ans);
//         return;
//     }

//     if (k < v[it]) return;

//     ans.push_back(v[it]);
//     Solution(v, n, ans, it+1, k - v[it]);
//     ans.pop_back();
//     Solution(v, n, ans, it+1, k);

//     return;
// }

// int main() {
//     ios_base::sync_with_stdio(NULL);
//     cin.tie(NULL); cout.tie(NULL);

//     int n; cin>>n;
//     vi v, ans;
//     F(i, 0, n) {
//         int x; cin>>x;
//         v.push_back(x);
//     }

//     ll k; cin>>k;

//     Solution(v, n, ans, 0, k);
//     display(sol);

//     return 0;
// }


#include <bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vector<int>>
#define F(i, n, m) for (int i = n; i < m; i++)
using namespace std;

class Solution {
    public:
        void Answer(vi &v, vi &sol, vvi&ans, int k, int it) {
            if (k == 0) {
                ans.push_back(sol);
                return;
            }

            F(i, it, v.size()) {
                if (i > it && v[i] == v[i-1]) continue;
                if (v[i] > k) break;

                sol.push_back(v[i]);
                Answer(v, sol, ans, k-v[i], i+1);
                sol.pop_back();
            }

            return;
        }

        vvi CombinationSum2(vi &v, int k) {
            sort(v.begin(), v.end());
            vi sol;
            vvi ans;
            Answer(v, sol, ans, k, 0);
            return ans;
        }
};

void display(vvi ans) {
    for (auto i : ans) {
        for (auto j : i) cout<<j<<" ";
        cout<<"\n";
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
    int k; cin>>k;

    Solution obj;
    vvi ans = obj.CombinationSum2(v, k);

    display(ans);

    return 0;
}