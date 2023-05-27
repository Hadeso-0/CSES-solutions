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
bool isValid(int idx, vector<int>& arr, int n){
    int lft = true;
    if(idx > 0) lft = (abs(arr[idx]-arr[idx-1]) <= 1);
    int rgt = true;
    if(idx < n-1 && (arr[idx+1] != 0)) rgt = (abs(arr[idx]-arr[idx+1]) <= 1);
    // cout<<" -> "<<lft<<" "<<rgt<<endl;
    return lft && rgt;
}

// Top-Down DP
// int solve(vector<int>& arr, int bound, int idx, vector<vector<int>>& dp){
//     if(idx == arr.size()){
//         return 1;
//     }
    
//     if(arr[idx] == 0){
//         // unknown value
//         // cout<<idx<<endl;
//         int ans = 0;
//         for(int i=1; i<=bound; ++i){
//             arr[idx] = i;
//             // cout<<idx<<","<<i<<" -> ";
//             // cout<<arr;
//             // br;
//             if(isValid(idx, arr, arr.size())){
//                 // br;
//                 int temp = dp[idx][i];
//                 if(temp == -1){
//                     temp = solve(arr, bound, idx+1, dp);
//                     dp[idx][i] = temp;
//                 }
//                 ans = (ans + temp)%mod;
//             }
//         }
//         arr[idx] = 0;
//         // cout<<endl;
//         return ans;
//     }
//     else{
//         // 
//         if(isValid(idx, arr, arr.size()))
//             return solve(arr, bound, idx+1, dp);
//         return 0;
//     }
// }
 
void solution()
{
    int n, m;
    cin>>n>>m;
    vector<int> arr(n);
    for(int i=0; i<n; ++i){
        cin>>arr[i];
    }

    // cout<<solve(arr, m, 0, dp);
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
 
    // Bottom - Up DP
    if(arr[0] == 0){
        for(int x=1; x<=m; ++x) dp[0][x] = 1;
    }
    else{
        dp[0][arr[0]] = 1;
    }
 
    for(int idx=1; idx<n; ++idx){
        for(int x=1; x<=m; ++x){
            if(arr[idx] == 0 || arr[idx] == x){
                dp[idx][x] = (dp[idx-1][x-1]*1LL + dp[idx-1][x]*1LL + dp[idx-1][x+1]*1LL)%mod;
            }
            else{
                dp[idx][x] = 0;
            }
        }
    }
 
    int ans = 0;
    for(int i=1; i<=m; ++i){
        ans = (ans + dp[n-1][i])%mod; 
    }
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
 
    solution();
    return 0;
}