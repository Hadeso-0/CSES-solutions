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
 
// int solve(int idx, vector<int>& coins, int target, vector<vector<int>>& dp){
//     if(target == 0) return 1;
//     if(target < 0) return 0;
    
//     if(dp[idx][target] != -1) return dp[idx][target];
 
//     int ans = 0;
//     if(target >= coins[idx])
//         ans = (ans + solve(idx, coins, target-coins[idx], dp))%mod;
    
//     ans = (ans + solve(idx+1, coins, target, dp))%mod;
 
//     return dp[idx][target] = ans;
// }
 
void solution()
{
    int n, target;
    cin>>n;
    cin>>target;
    vector<int> coins(n, 0);
    for(int i=0; i<n; ++i) 
        cin>>coins[i];
 
    sort(coins.begin(), coins.end());
    vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
    // cout<< solve(0, coins, target, dp);
    // vector<int> dp(target+1, 1e8);
    // dp[0] = 0;
    for(int i=0; i<=n; i++){
        dp[i][0] = 1;
    }
 
    for(int i=1; i<=n; i++){
        for(int sm=1; sm<=target; sm++){
            if(sm >= coins[i-1]){
                dp[i][sm] = (dp[i-1][sm] + dp[i][sm-coins[i-1]])%mod;
            }
            else{
                dp[i][sm] = dp[i-1][sm];
            }
 
        }
    }
    // if(dp[target]== 1e8){
    //     cout<<-1;
    // }
    // else{
    cout<<dp[n][target];
    // }
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