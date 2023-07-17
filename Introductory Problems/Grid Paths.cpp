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
#define yes cout<<"YES";
#define no cout<<"NO";

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

vector<vector<int>> dirs = {{0,-1},{-1,0},{1,0},{0,1}};

int solve(int idx, int i, int j, string& s, int n, int m, vector<vector<bool>>& vis){
    if((vis[i][j-1] && vis[i][j+1]) && 
       (!vis[i-1][j] && !vis[i+1][j])) return 0;
 
    if((vis[i-1][j] && vis[i+1][j]) &&
       (!vis[i][j-1] && !vis[i][j+1])) return 0;
 
    // cout<<i<<" "<<j<<endl;
    if((i == n) && (j == 1)){
        if(idx == s.size()) return 1;
        return 0;
    }
    if(idx == s.size()) return 0;

    int ans = 0;
    vis[i][j] = true;

    if(s[idx] == '?'){
        for(int d=0; d<4; ++d){
            if(!vis[i+dirs[d][0]][j+dirs[d][1]]) 
                ans += solve(idx+1, i+dirs[d][0], j+dirs[d][1], s, n, m, vis);
        }
    }
    if(s[idx] == 'U'){
        if(!vis[i][j-1]) 
            ans += solve(idx+1, i, j-1, s, n, m, vis); 
    }
    if(s[idx] == 'L'){ 
        if(!vis[i-1][j]) 
            ans += solve(idx+1, i-1, j, s, n, m, vis); 
    }
    if(s[idx] == 'R'){ 
        if(!vis[i+1][j]) 
            ans += solve(idx+1, i+1, j, s, n, m, vis); 
    }
    if(s[idx] == 'D'){ 
        if(!vis[i][j+1]) 
            ans += solve(idx+1, i, j+1, s, n, m, vis); 
    }

    vis[i][j] = false;
    return ans;
}

void solution(){
    string s;
    cin>>s;
    int n = 7; int m = 7;
    vector<vector<bool>> vis(n+2, vector<bool>(m+2, false));
    for(int i=0; i<=n+1; ++i){
        vis[i][0] = true; vis[i][m+1] = true;
    }
    for(int i=0; i<=m+1; ++i){
        vis[0][i] = true; vis[n+1][i] = true;
    }
    cout<<solve(0, 1, 1, s, n, m, vis);
    return;
}

/* ============ Main ============ */

int main(){

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