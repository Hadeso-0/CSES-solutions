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

/**
 * @brief A recursive function, to shift n disks from source
 * stack to destination stack using an auxiliary stack
 * 
 * @param src Source Stack
 * @param des Destination Stack
 * @param aux Auxiliary Stack
 * @param ans Store the moves that we make
 * @param n number of disks in source stack
 */
void solve(int src, int des, int aux, vector<pair<int,int>>& ans, int n){
    if(n<=0) return;
    /**
     * @remark If there is only a single disk in source stack-> 
     * Directly move it to destination stack
     * " BASE CASE "
     */
    if(n == 1){
        ans.push_back({src, des});
        return;
    }

    /**
     * @remark 
     * 1. Move the top n-1 disks from src to aux, using des as auxiliar stack
     * 2. Move the bottom-most disk from src to des
     * 3. Move the n-1 disks in aux to des, using src as Auxiliary stack
     */
    solve(src, aux, des, ans, n-1);
    solve(src, des, aux, ans, 1);
    solve(aux, des, src, ans, n-1);
}

void solution(){
    ll n;
    cin>>n;
    vector<pair<int,int>> ans;
    solve(1,3,2, ans, n);
    cout<<ans.size()<<"\n";
    for(auto& it : ans){
        cout<<it.F<<" "<<it.S<<"\n";
    }
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