#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define debug(a) cout<<a<<'\n'
#define maxn 200009 /// I wanna be the wind
#define MOD 1000000007
#define F first
#define S second
#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define per(i, b, a) for(ll i = b-1; i>=a ; i--)
#define trav(a, x) for(auto& a : x)
#define allin(a , x) for(auto a : x)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
using namespace std;
const ll INF = 1e14 + 9;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
  	srand(time(NULL));
  	ll num;
  	rep(i,0,(ll)1e10){
  		num = rand()%10;
  		cout<<num;
  	}
    return 0;  
}   