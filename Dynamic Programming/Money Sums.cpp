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
 
/* ========== Solution ========= */
 
void solution()
{   
    int n;
    cin>>n;
    vector<int> coins(n);
    long long max_sum = 0;
    for(int i=0; i<n; ++i){ 
        cin>>coins[i];
        max_sum += coins[i];
    }
 
    vector<vector<bool>> dp(2, vector<bool>(max_sum+1, false));
    dp[0][0] = true;
    dp[1][0] = true;
 
    for(int i = 1; i<=n; ++i){
        for(int sm=0; sm<= max_sum; ++sm){
            if(sm >= coins[i-1]){
                dp[i%2][sm] = dp[(i-1)%2][sm-coins[i-1]] || dp[(i-1)%2][sm];
            }
            else{
                dp[i%2][sm] = dp[(i-1)%2][sm];
            }
        }
    }
 
    vector<int> ans;
    for(int i=1; i<=max_sum; ++i){
        if(dp[n%2][i] == true) ans.push_back(i);
    }
 
    cout<<ans.size()<<"\n";
    cout<<ans;
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