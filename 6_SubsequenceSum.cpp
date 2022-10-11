//time complexity = O(2^n)
//space complexity = O(1)

#include <bits/stdc++.h>
#define vi vector<int>
#define ll long long int
#define F(i, n, m) for (int i = n; i < m; i++)
using namespace std;

bool flag = false;

void display(vi ans) {
    for (auto it : ans) cout<<it<<" ";
    cout<<"\n";
    return;
}

//Print all the subsequences in the array whose sum is k
void PrintAll(vi v, int n,vi ans, int it, ll k, ll sum) {
    if (it >= n) {
        if (sum == k) display(ans);
        return;
    }

    ans.push_back(v[it]);
    sum += ans.back();
    PrintAll(v, n, ans, it+1, k, sum);
    sum -= ans.back();
    ans.pop_back();
    PrintAll(v, n, ans, it+1, k, sum);

    return;
}


//Print any 1 subsequence
void PrintAnyOne(vi v, int n,vi ans, int it, ll k, ll sum) {
    if (it >= n) {
        if (sum == k && flag == false) {
            display(ans);
            flag = true;
        }
        return;
    }

    ans.push_back(v[it]);
    sum += ans.back();
    PrintAnyOne(v, n, ans, it+1, k, sum);
    sum -= ans.back();
    ans.pop_back();
    PrintAnyOne(v, n, ans, it+1, k, sum);

    return;
}

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);

    //cout<<"INPUT : \n";
    int n; cin>>n;
    vi v;
    F(i, 0, n) {
        int x; cin>>x;
        v.push_back(x);
    }

    ll k; cin>>k;
    vi ans;

    cout<<"\nPrint All Subsequences : \n";
    PrintAll(v, n, ans, 0, k, 0);

    cout<<"\nPrint any one Subsequence : \n";
    PrintAnyOne(v, n, ans, 0, k, 0);

    return 0;
}