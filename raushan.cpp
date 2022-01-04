//Raushan Ranjan VS CODE CP EXT//

#include <bits/stdc++.h>
using namespace std; 
typedef long long int ll;
#define pb push_back 
#define popb pop_back
#define sza(x) ((int)x.size())
#define mp make_pair
#define ve vector
#define vii vector < int >
#define vll vector < ll > 
#define pii pair < int , int >
#define pll pair < ll , ll >
#define vpl vector < pll >
#define fi first
// #define sza size 
#define len length 
typedef unsigned long long ull;
#define se second 
//const ll mod=998244353;
const ll mod = 1000000000+7;
const ll N=10000000+6;
#define M_PI           3.14159265358979323846
//===============DEBUGGING==================================================================================//
 
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
//=====================Functions============================================================================//
ll expo(ll a, ll b, ll mod)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b = b >> 1;
    }
    return res;
}

ll count(string a, string b, int m, int n)
 {
    
    if ((m == 0 && n == 0) || n == 0)
             return 1;

    if (m == 0)
        return 0;

    if (a[m - 1] == b[n - 1])
        return count(a, b, m - 1, n - 1) +
               count(a, b, m - 1, n);
     else
        
        return count(a, b, m - 1, n);
 }

bool IsPrime(ll number) {
    if (number <= 1) return false;
    if (number == 2 || number == 3)
        return true;
    if (number % 2 == 0 || number % 3 == 0)
        return false;
 
    for (ll i = 5; i * i <= number; i += 2) {
        if (number % i == 0) return false;
    }
 
    return true;
}
ll gcd(ll a, ll b)
{
    if (b > a)
    {
        return gcd(b, a);
    }
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}
void extendgcd(ll a, ll b, ll *v)
{
    if (b == 0)
    {
        v[0] = 1;
        v[1] = 0;
        v[2] = a;
        return;
    }
    extendgcd(b, a % b, v);
    ll x = v[1];
    v[1] = v[0] - v[1] * (a / b);
    v[0] = x;
    return;
} //pass an arry of size1 3
ll mminv(ll a, ll b)
{
    ll arr[3];
    extendgcd(a, b, arr);
    return arr[0];
} //for non prime b
ll mminvprime(ll a, ll b) { return expo(a, b - 2, b); }
bool revsort(ll a, ll b) { return a > b; }
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact)
{
    ll val1 = fact[n];
    ll val2 = ifact[n - r];
    ll val3 = ifact[r];
    return (((val1 * val2) % m) * val3) % m;
}

ll power(ll a, ll b){ // a raised to power b
  ll res=1;
  while(b){
    if(b&1) res=(res*a)%mod;
    b>>=1;
    a=(a*a)%mod;
  }
  return res;
}
//  vector<int> v(n) ;
//         map<int,int> rem ;
//         for(auto &x : v){
//             cin >> x;
//             rem[x] ++ ;
//         }
//         for(int i = 0 ; i < n ; i++){
//             if(rem[v[i]]  == 1){
//                 cout << i + 1 << endl ;
//                 //return ;
//             }
//         }

bool vowel(char a)
{
    if(a=='a' || a=='e' || a=='i' || a=='o' || a=='u')
    {
        return true;
    }
    return false;
}
ll phin(ll n)
{
    ll number = n;
    if (n % 2 == 0)
    {
        number /= 2;
        while (n % 2 == 0)
            n /= 2;
    }
    for (ll i = 3; i <= sqrt(n); i += 2)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            number = (number / i * (i - 1));
        }
    }
    if (n > 1)
        number = (number / n * (n - 1));
    return number;
} //O(sqrt(N))

ll fermat(ll a, ll b, ll p)
{
    return ((a % p) * (expo(b, p - 2, p) % p) % p);
}
 
ll bin_expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
 
ll fermatinv(ll a, ll b) {return bin_expo(a, b - 2, b);} //for prime b
 
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, fermatinv(b, m), m) + m) % m;}  //only for prime m
 
ll phi(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i * i <= n; i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
 
ll nCr(ll n, ll r, ll p) {if (n < r)return 0; if (r == 0)return 1; ull fac[n + 1]; fac[0] = 1; for (ll i = 1; i <= n; i++)fac[i] = (fac[i - 1] * i) % p; return (fac[n] * fermatinv(fac[r], p) % p * fermatinv(fac[n - r], p) % p) % p;}
#define print cout
#define fo(i, j, k, in) for (int i=j ; i<k ; i+=in)
vii sieve(ll N) {vii pr; vii lp(N + 1); for (ll i = 2; i <= N; ++i) {if (lp[i] == 0) {lp[i] = i; pr.pb(i);} for (ll j = 0; j < (ll)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)lp[i * pr[j]] = pr[j];} return pr;}
//=================================MAIN======================================================================//

int main(){
	int t; 
    cin >> t;
	while(t--){
		ll n,m,q;
		cin >> n >> m >> q;
		vector<bool> ok(n+1);
		char ch;
		int x,bal = 0;
		bool ans = true;
		while(q--){
			cin >> ch >> x;
			if(!ans) continue;
			if(ch == '+') ok[x] = true,bal++;
			else ans = ok[x],bal--;
			if(bal > m) ans = false;
		}
		cout << (ans ? "Consistent" : "Inconsistent") << '\n';
	}
	
}
