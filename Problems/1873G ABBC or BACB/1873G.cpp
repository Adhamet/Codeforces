#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);   cin.tie(0); cout.tie(0);

    int t;  cin >> t;
    for(int i = 1; i<=t; i++) {
        string s;   cin >> s;
        int n = s.length(), cnt = 0;
        bool all = (s[0] == 'B' || s[n-1] == 'B');
        for(int i = 0; i < n-1; i++) if(s[i]==s[i+1] && s[i]=='B')
            all = true;
        
        int curr = 0;
        vector<int> lens;
        for(int i = 0; i < n; i++) {
            if(s[i] == 'A') curr++;
            else {
                if(curr!=0) lens.push_back(curr);
                curr = 0;
            }
        }
        if(curr!=0) lens.push_back(curr);

        sort(lens.begin(), lens.end());
        if(lens.empty()) return cout << 0 << el, 0;

        int tot = 0;
        if(all) tot += lens[0];
        for(int i = 1; i < lens.size(); i++) tot+=lens[i];

        cout << tot << el;
    }

    return 0;
}
