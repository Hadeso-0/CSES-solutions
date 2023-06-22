#include <bits/stdc++.h>

using namespace std;

#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FASTIO1 srand(chrono::high_resolution_clock::now().time_since_epoch().count())
#define gc getchar_unlocked
#define ll long long
#define PI 3.1415926535897932384626
#define br cout << endl
#define sp cout << " "
#define foin(i, s, e) for (i = s; i < e; i++)
#define foinrev(i, s, e) for (i = s - 1; i >= e; i--)
#define printarr(i, s, e, a, str) foin(i, s, e) cout << a[i] << str;
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define clr(x) memset(x, 0, sizeof(x))
#define tr(it, x) for (auto it = x.begin(); it != x.end(); it++)
#define trr(it, x) for (auto it = x.rbegin(); it != x.rend(); it +)
#define sortv(vec) sort(vec.begin(), vec.end());

typedef pair<int, int> pii;
typedef map<int, int> mapii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

// Operator overloads
template<typename T1, typename T2> // cin >> pair<T1, T2>
istream& operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }
template<typename T> 
istream& operator>>(istream &istream, vector<T> &v){ for (auto &it : v) cin >> it; return istream; } 
template<typename T1, typename T2> 
ostream& operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second); }
template<typename T> // cout << vector<T>
ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }

const int mod = 1000000007;
const int N = 3e5;
int i = 0;


mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim)
{
    uniform_int_distribution<int> uid(0, lim - 1);
    return uid(rang);
}

ll power(ll b, ll p)
{
    if (p == 1)
        return b;
    ll val = power(b, p / 2) % mod;
    if (p % 2 == 0)
        return (val * val) % mod;
    else
        return ((b * (val * val) % mod) % mod);
}
/* ========== Solution ========= */
void solution()
{
    ll n;
    cin>>n;
    ll sum_max = n*(n+1)/2;
    ll target_sum = sum_max/2;

    if(sum_max%2){ 
        cout<<0;
        return;
    }

    // vector<vector<ll>> dp(n+1, vector<ll>(target_sum+1, 0));
    // for(ll i=0; i<=n; ++i){
    //     dp[i][0] = 1; // one way to create sum 0
    // }

    // for(ll i=1; i<=n; ++i){
    //     for(ll sm=0; sm<=target_sum; ++sm){
    //         dp[i][sm] = dp[i-1][sm];
    //         if(sm >= i){
    //             dp[i][sm] = (dp[i-1][sm] + dp[i-1][sm-i])%mod;
    //         }
    //     }
    // }

    // cout<<(dp[n][target_sum]/2)%mod;
    vector<ll> dp(target_sum+1, 0);
    dp[0] = 1;
    for(ll i=1; i<=n; ++i){
        for(ll sm = target_sum; sm >=i; --sm){
            dp[sm] = (dp[sm]+dp[sm-i])%mod;
        }
    }

    // I cannot simply Divide the value by 2 as it wont follow 
    // modular approach. Hence I would have to multiply my answer 
    // by (2^-1)%mod. (A/2)%mod == (A*(2^-1)%mod)%mod
    
    ll s = power(2,mod-2);
    cout<<(dp[target_sum]*s)%mod;

}

/* ============ Main ============ */

int main()
{
    #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
    #endif

    FASTIO;
    FASTIO1;

    int t = 1;
    // cin >> t;
    // compute();
    while (t--)
    {
        solution();
        // br;
    }
    
    return 0;
}