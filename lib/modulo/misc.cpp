typedef long long ll;

// Modular exponentiation
inline ll modPow(ll x, ll exp, ll mod)
{
    ll ans = 1;
    while (exp > 0)
    {
        if (exp & 1)
            ans = ans * x % mod;
        x = x * x % mod;
        exp /= 2;
    }
    return ans;
}

inline ll mod_mul(ll a, ll b, ll mod)
{
    ll result = 0;
    a %= mod;
    while (b > 0)
    {
        if (b & 1)
            result = (result + a) % mod;
        a = (a * 2) % mod;
        b >>= 1;
    }
    return result;
}
