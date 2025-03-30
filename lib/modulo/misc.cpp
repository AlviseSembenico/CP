

// Modular exponentiation
inline long long modPow(long long x, int exp, long long mod)
{
    long long ans = 1;
    while (exp > 0)
    {
        if (exp & 1)
            ans = ans * x % mod;
        x = x * x % mod;
        exp /= 2;
    }
    return ans;
}