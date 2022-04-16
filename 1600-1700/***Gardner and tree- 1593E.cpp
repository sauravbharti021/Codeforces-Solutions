#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define pi (3.141592653589)
#define mod 1000000007
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

int32_t main(){
FastHoviBaby


int t=1;
cin>>t;
while(t--){
    int n, k;
    cin>>n>>k;

    vector< vector<int>> adj(n+1);
    map<int,int> nei;
    rep(i,n-1){
        int x,y;
        cin>>x>>y;

        adj[x].pb(y);
        adj[y].pb(x);
        nei[x]++;
        nei[y]++;
    }
    if(k>n || n==1) {cout<<0<<endl;
    continue; }

   
   
    vector<int> layer(n+1,0);
   
    queue<int> q;

    for(int i=1;i<=n;i++){
        if(nei[i]==1){
            layer[i]=1;
            q.push(i);
        }
    }

    int x=k;
    while(k>0){
        int bef= q.size(), count=0;

        while(!q.empty() && count<=bef){  count++;  
        int top=q.front();
        
        q.pop();

        int size= adj[top].size();
        for(int i=0; i<size; i++){
            nei[adj[top][i]]--;  

            if( nei[adj[top][i]]==1 && layer[adj[top][i]]==0){
                layer[adj[top][i]]= layer[top]+1;
                q.push(adj[top][i]);
            }

        }
        }
        k--;

    }
  
    int ans=0;
    for(int i=1;i<=n;i++){  
        if(layer[i]>x || layer[i]==0) ans++;
    }

    cout<<ans<<endl;

}
return 0;
}
