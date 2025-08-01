#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<long long, long long>;
#define rep(i, a, b) for(long long i = (a); i < (b); ++i)
#define rrep(i, a, b) for(long long i = (a); i >= (b); --i)
constexpr long long inf = 4e18;
struct SetupIO {
    SetupIO() {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout << fixed << setprecision(30);
    }
} setup_io;
int main(void) {
    ll n, m = 3;
    cin >> n;
    string s, t;
    cin >> s >> t;
    vector<ll> a(n), b(n);
    rep(i, 0, n) {
        a[i] = s[i] - 'A';
        b[i] = t[i] - 'A';
    }
    vector<ll> c(n);
    c[0] = a[0] - b[0];
    rep(i, 1, n) {
        b[i] += (b[i - 1] / m) * m;
        if(b[i - 1] < 0 and b[i - 1] % m != 0) {
            b[i] -= m;
        }
        if(b[i] > b[i - 1] and a[i] < a[i - 1]) {
            b[i] -= m;
        } else if(b[i] < b[i - 1] and a[i] > a[i - 1]) {
            b[i] += m;
        }
        assert(abs(b[i] - b[i - 1]) < m);
        c[i] = a[i] - b[i];
    }
    ll left = -1e7, right = 1e7;
    rep(iter, 0, 100) {
        ll midl = (left * 2 + right) / 3, midr = (left + right * 2) / 3;
        ll c1 = 0, c2 = 0;
        rep(i, 0, n) {
            c1 += abs(c[i] + midl * m);
            c2 += abs(c[i] + midr * m);
        }
        if(c1 <= c2) {
            right = midr;
        } else {
            left = midl;
        }
    }
    ll ans = inf;
    rep(x, left - 3, right + 4) {
        ll res = 0;
        rep(i, 0, n) {
            res += abs(c[i] + x * m);
        }
        ans = min(ans, res);
    }
    cout << ans << '\n';
}