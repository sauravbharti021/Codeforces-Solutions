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

int32_t main(){
FastHoviBaby


int t=1;
cin>>t;
while(t--){
    int n;
    cin>>n;

    int a[n];
    rep(i,n) cin>>a[i];

    vector<int> count(30,0);

    rep(i,n){

        rep(j,30){

            if( ((1<<j) & a[i])) count[j]++;
        }
    }
    vector<int> ans;
    for(int i=1;i<=n;i++){
        int flag=0;
        rep(j,30){
            if(count[j]%i!=0){
                flag=1;
                break;
            }
        }
        if(!flag) ans.pb(i);
    }

    for(auto i: ans) cout<<i<<" "; cout<<endl;
}
return 0;
}

///////////////////////////////////////////////////////////////
So, we are given a array and the question said that for every K=1 to n. Select a subsequnce of K size and do a & operation on all of them and then subtract that from
all elements from choosen indices.

Ex- 13 7 25 19
-> If we write their binary rep. 
  
  0 1 1 0 1
  0 0 1 1 1
  1 1 0 0 1
  1 0 0 1 1
 -----------
  2 2 2 2 4
  
  So, what we notice is when we do (13 & 7) for k=2. we get 5. 13-5= 8 and 7-5=2.
  
  0 1 0 0 0
  0 0 0 1 0
  1 1 0 0 1
  1 0 0 1 1
  
  So, those bits which were set in both disappeared. Later for (8 & 25)=  8, 8-8=0, 25-8= 17.
  
  0 0 0 0 0
  0 0 0 1 0
  1 0 0 0 1
  1 0 0 1 1
  
  (17&19)=17, 17-17=0, 19-17=2.
  
  0 0 0 0 0
  0 0 0 1 0
  0 0 0 0 0
  0 0 0 1 0
  
  (2&2)=2. 2-2=0, 2-2=0
  
  0 0 0 0 0
  0 0 0 0 0
  0 0 0 0 0
  0 0 0 0 0
  
  So, in this way we got the entire arrat= {0}.
  
  So, the observation here is that if no. of set for all bit is div. by 'k'. We will get the answer otherwise no.
  

