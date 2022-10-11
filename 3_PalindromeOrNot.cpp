//Functional Recursion Program

#include <bits/stdc++.h>
#define F(i, n, m) for (int i = n; i < m; i++)
using namespace std;

bool Solution(string s, int i) {
    if (i >= s.length()/2) return true;

    if (s[i] == s[s.length()-i-1]) return Solution(s, i+1);

    return false;
}

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);

    string s; cin>>s;

    if (Solution(s, 0)) cout<<"Palindrome\n";
    else cout<<"Not a palindrome\n";

    return 0;
}