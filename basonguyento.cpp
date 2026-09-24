#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXP = 2000000;
bool is_prime[MAXP];
vector<ll> primes;

void sieve() {
    fill(is_prime, is_prime + MAXP, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i < MAXP; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j < MAXP; j += i)
                is_prime[j] = false;
        }
    }
    for (int i = 2; i < MAXP; i++) {
        if (is_prime[i]) primes.push_back(i);
    }
}

struct Exponent {
    int t1, t2, t3;
};

// Hàm nhân an toàn, chặn hoàn toàn lỗi tràn số
ll safe_mul(ll a, ll b, ll limit) {
    if (a == 0 || b == 0) return 0;
    // Nếu a * b > limit thì limit / a < b
    if (limit / a < b) return limit + 1; 
    return a * b;
}

// Hàm lũy thừa an toàn, kết hợp ngắt sớm
ll safe_pow(ll base, int exp, ll limit) {
    ll res = 1;
    for (int i = 0; i < exp; i++) {
        res = safe_mul(res, base, limit);
        if (res > limit) return limit + 1;
    }
    return res;
}

int main() {
    // Tối ưu I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    int k;
    if (!(cin >> n >> k)) return 0;

    sieve();

    vector<Exponent> somu;
    for (int t1 = 1; t1 <= k; t1++) {
        for (int t2 = 1; t2 <= k; t2++) {
            if (k % ((t1 + 1) * (t2 + 1)) == 0) {
                int t3 = k / ((t1 + 1) * (t2 + 1)) - 1;
                if (t3 >= 1) {
                    somu.push_back({t1, t2, t3});
                }
            }
        }
    }

    ll ans = -1;

    for (size_t i = 0; i + 2 < primes.size(); i++) {
        ll p1 = primes[i];
        ll p2 = primes[i + 1];
        ll p3 = primes[i + 2];

        // Do t1, t2, t3 >= 1 nên m luôn >= p1 * p2 * p3
        // Nếu giới hạn nhỏ nhất này đã > n thì dừng toàn bộ vòng lặp
        if (safe_mul(safe_mul(p1, p2, n), p3, n) > n) break;

        for (const auto& e : somu) {
            ll val = safe_pow(p1, e.t1, n);
            if (val > n) continue;
            
            val = safe_mul(val, safe_pow(p2, e.t2, n), n);
            if (val > n) continue;
            
            val = safe_mul(val, safe_pow(p3, e.t3, n), n);
            
            if (val <= n) {
                ans = max(ans, val);
            }
        }
    }

    cout << ans << "\n";
    return 0;
}
