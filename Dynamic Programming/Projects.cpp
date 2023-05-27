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
int find_rightmost(vector<vector<long long>>& prj, int idx){
    // rightmost project before idx having end time < start time of idx
    ll str_time = prj[idx][0];
 
    // // using linear search O(n)
    // for(int i = idx-1; i>=0; --i){
    //     if(prj[i][1] < str_time) return i;
    // }
    // return -1;
 
    // using B search O(log n)
    int ans = -1;
    int l = 0;
    int r = idx-1;
    int mid = l + (r-l)/2;
    while(l <= r){
        mid = l + (r-l)/2;
        if(prj[mid][1] < str_time){
            ans = mid;
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    return ans;
}
 
void solution()
{   
    int n;
    cin>>n;
    vector<vector<long long>> prj(n, vector<long long>(3));
    long long max_busy = 0;
    for(int i=0; i<n; ++i){
        cin>>prj[i][0]>>prj[i][1]>>prj[i][2];
        max_busy = max(max_busy, prj[i][1]);
    }
 
    sort(prj.begin(), prj.end(), [&](const vector<long long>& a, const vector<long long>& b){
        return a[1] < b[1];
    });
    
    // for(auto& line : prj){
    //     cout<<line[0]<<" "<<line[1]<<" "<<line[2]<<endl;
    // }
 
    vector<long long> dp(n+1, 0);
    
    dp[0] = 0;
    for(int i=1; i<=n; ++i){
        long long dont_work_on_this = dp[i-1];
        int j = find_rightmost(prj, i-1);
        long long work_on_this = dp[j+1] + prj[i-1][2];
        // cout<<i <<" "<<j<<endl;
        dp[i] = max(work_on_this, dont_work_on_this);
    }
 
    cout<<dp[n];
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