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
 
// int solve(int idx, int budget, vector<int>& price, vector<int>& pages, vector<vector<int>>& dp){
//     if(idx >= price.size() || budget <= 0) return 0;
//     if(dp[idx][budget] != -1) return dp[idx][budget];
 
//     int incl = 0;
//     if(budget >= price[idx]){
//         incl = pages[idx] + solve(idx+1, budget-price[idx], price, pages, dp);
//     }
//     int excl = solve(idx+1, budget, price, pages, dp);
 
//     return dp[idx][budget] = max(incl, excl);
// }  
 
void solution()
{
    int n, budget;
    cin>>n>>budget;
    vector<int> pages(n);
    vector<int> price(n);
    // vector<vector<int>> dp(n+1,vector<int>(budget+1, -1));
    for(int i=0 ; i<n; ++i) cin>>price[i];
    for(int i=0 ; i<n; ++i) cin>>pages[i];
 
    vector<vector<int>> dp(n+1,vector<int>(budget+1, 0));
    // cout<<solve(0, budget, price, pages, dp);
    
    for(int idx=n-1; idx>=0; --idx){
        for(int bud=0; bud<=budget; ++bud){
            int incl = 0;
            if(bud >= price[idx]){
                incl = (pages[idx] + dp[idx+1][bud-price[idx]])%mod;
            }
            int excl = dp[idx+1][bud];
 
            dp[idx][bud] = max(incl, excl);
        }
    }
 
    cout<<dp[0][budget];
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
 
    solution();
    return 0;
}