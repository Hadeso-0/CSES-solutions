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
void solution(){
    ll n; 
    cin>>n;

    /**
     * @remark 
     * Initial case n=3: Easily we can split A={1,2} & B={3}
     * Inductive step n→n+4:
     * Suppose we can split the set {1,…,n} into two sets 
     * A,B with the same sum. Then, we can split {1,…,n+4} 
     * into the sets A∪{n+1,n+4} and B∪{n+2,n+3}. The sets 
     * will remain with the same sum since:
     * (n+1)+(n+4)=(n+2)+(n+3)
     */
    ll sum = n*(n+1)/2;
    if(sum&1){
        cout<<"NO";
        br;
        return;
    }
    else{
        cout<<"YES";
        br;
        vector<int> st1, st2;
        if(n&1){
            st1.push_back(1);
            st1.push_back(2);
            st2.push_back(3);

            for(int i=4; i<=n; i+=4){
                st1.push_back(i);
                st1.push_back(i+3);
                st2.push_back(i+1);
                st2.push_back(i+2);
            }
        }
        else{
            for(int i=1; i<=n/2; i+=2){
                st1.push_back(i);
                st1.push_back(n+1-i);
                st2.push_back(i+1);
                st2.push_back(n-i);
            }
        }
        sort(all(st1));
        sort(all(st2));
        cout<<st1.size()<<endl<<st1;
        br;
        cout<<st2.size()<<endl<<st2;

        /**
         * @note Alternate Method
         * int ans = sum / 2;
         * for (int i = n; i >= 1; i--) {
         *   if (i <= ans) {
         *     st1.push_back(i);
         *     ans -= i;
         *   }
         *   else { st2.push_back(i); }
         */
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