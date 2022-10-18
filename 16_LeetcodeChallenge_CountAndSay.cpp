//CountAndSay (Medium)

//The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

// countAndSay(1) = "1"
// countAndSay(n) is the way you would "say" the digit string from countAndSay(n-1), which is then converted into a different digit string.
// To determine how you "say" a digit string, split it into the minimal number of substrings such that each substring contains exactly one unique digit. Then for each substring, say the number of digits, then say the digit. Finally, concatenate every said digit.

// Example 1:

// Input: n = 1
// Output: "1"
// Explanation: This is the base case.


// Example 2:

// Input: n = 4
// Output: "1211"
// Explanation:
// countAndSay(1) = "1"
// countAndSay(2) = say "1" = one 1 = "11"
// countAndSay(3) = say "11" = two 1's = "21"
// countAndSay(4) = say "21" = one 2 + one 1 = "12" + "11" = "1211"

#include <bits/stdc++.h>
using namespace std;

string countAndSay(int n) {
    if (n == 1) return "1";

    string s = countAndSay(n-1);
    string h = "";
    int count = 1;

    for (int i = 0; i < s.length()-1; i++) {
        if (s[i] == s[i+1]) count++;

        else {
            h += to_string(count) + s[i];
            count = 1;
        }
    }

    h += to_string(count) + s[s.length()-1];
    s = h;

    return s;
}

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin>>n;
    cout<<countAndSay(n)<<"\n";
    return 0;
}