#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

// const int N = 20 + 5;
// const int oo = 1e9 + 20;

int main()	{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
    
        int ra[n], ca[m], rb[n], cb[m];
        for (int i = 0; i < max(n, m); i++) {
            ra[i] = ca[i] = rb[i] = cb[i] = 0;
        }

        string a[n], b[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                (ra[i] += (a[i][j] - '0')) %= 3;
                (ca[j] += (a[i][j] - '0')) %= 3;
                (rb[i] += (b[i][j] - '0')) %= 3;
                (cb[j] += (b[i][j] - '0')) %= 3;
            }
        }

        bool flag = true;
        for (int i = 0; i < max(n, m); i++) {
            flag &= (ra[i] == rb[i]);
            flag &= (ca[i] == cb[i]);
        }

        cout << (flag? "YES": "NO") << el;
    }

    return 0;
}
