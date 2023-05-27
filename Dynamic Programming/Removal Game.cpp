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
// int solve(vector<int>& points, int i, int j, vector<vector<int>>& dp){
//     if(i == j) 
//         return points[i]-points[i-1]; // only the point at ith index
 
//     if(dp[i][j] != -1)
//         return dp[i][j];
    
//     int ans = points[j] - points[i-1]; // points from ith idx to jth idx
//     int way_1 = solve(points, i+1, j, dp);
//     int way_2 = solve(points, i, j-1, dp);
 
//     return dp[i][j] = max(ans-way_1, ans-way_2);
// }
void solution()
{   
    int n;
    cin>>n;
    vector<long long> points(n+1, 0);
    for(int i=1; i<=n; ++i){ 
        cin>>points[i];
        points[i] += points[i-1];
    }
    // vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
    // chance = 0 -> first player, 1 -> second player
    // cout<<solve(points, 1, n, dp);
    // cout<<ans.first; 
 
    vector<vector<long long>> dp(n+1, vector<long long >(n+1,0));
    
    for(int i=1; i<=n; ++i){
        dp[i][i] = points[i]-points[i-1];
    }
 
    for(int i=n; i>=1; --i){
        for(int j=i+1; j<=n;++j){
            dp[i][j] = (points[j]-points[i-1]) - min(dp[i+1][j], dp[i][j-1]);
        }
    }
    cout<<dp[1][n];
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