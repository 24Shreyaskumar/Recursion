#include <bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n, char A, char B, char C) {
    if (n == 1) {
        cout<<"move disk 1 from rod "<<A<<" to rod "<<C<<"\n";
        return;
    }

    towerOfHanoi(n-1, A, C, B);
    cout<<"move disk "<<n<<" from rod "<<A<<" to rod "<<C<<"\n";
    towerOfHanoi(n-1, B, A, C);

    return;
}

long long int Solution(int n, char A, char B, char C) {
    towerOfHanoi(n, A, B, C);

    return pow(2, n) - 1;
}

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin>>t;

    while (t--) {
        int n; cin>>n;
        cout<<Solution(n, 'A', 'B', 'C')<<"\n";
    }

    return 0;
}