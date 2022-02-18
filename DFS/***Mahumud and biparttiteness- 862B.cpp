#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pi (3.141592653589)
#define mod 1000000007
#define int long long
#define float double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(c) c.begin(), c.end()
#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define rrep(i, n) for(int i=n-1;i>=0;i--)
#define rep(i,n) for(int i=0;i<n;i++)
#define FastHoviBaby ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);


int npow(int a, int b) { 
if(b==0) return 1;   int res= npow(a, b/2);
if(b%2!=0) return res*res*a;       else return res*res; }


int modp(int a,int b,int m){ 
 a %= m;     int res = 1;  while (b > 0) { if (b & 1)    res = res * a % m;      a = a * a % m;  b >>= 1; }
return res;}


bool myComp(const pair<int, int>& a, const pair<int, int>& b){ if (a.first != b.first)  return a.first > b.first;  return a.second < b.second;}


int gcd(int a , int b)
{
if(b==0) return a;
a%=b;
return gcd(b,a);
}


bool isPrime(int n){
    if(n==1) return false;
    if(n==2) return true;
    for(int i=2;i*i<=n;i++){
        if(n%i==0)return false;
    }
    return true;
}
vector<int> adj[100007];
vector<bool> vis(1000007, false);
vector<int> ans(2);
void dfs(int k, int a){
    vis[k]=true;
    ans[a]++;
    for(auto child: adj[k]){
        if(!vis[child]){
            dfs(child, a^1);
        }
    }
    } 

int32_t main(){
FastHoviBaby

int n;
cin>>n;
    rep(i,n-1){
        int x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    int a=1;
    dfs(1,0);
    cout<<ans[0]*ans[1]- (n-1);

return 0;
}
///////////////////////////////////////////////////////////////////////////////
Now, here we have Tree given as an input and we have to find Biparite edges.
Bipartite coloring is way of coloring it such that no 2 adjacent edges has same coloring. R->B->R-B.
  
A graph with odd cycle cannot be a bipartite, because R->B->R->B->R, we here we get this Red repeated.
  
  ///////Tree is acyclic connected graph(So, it is always bipartite.)
  
  Now, we run a dfs so that we can color that tree such that no 2 adjacent edges are colored with same color. (0^1)=1, (1^1)=0. 1-R, 0-B
  
  Now, since we have done that and have taken a count of Red and Black vertices.
  
Now we know maximum edges a bipartite graph can have are R x B.//////  Can look at this gfg article for confirming- geeksforgeeks.org/maximum-number-edges-added-tree-stays-bipartite-graph/?ref=rp
  And tree has (N-1) edges.
  
  So, our final answer is (R*B)-(n-1).
  
 
  
