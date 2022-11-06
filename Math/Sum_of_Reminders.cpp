#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N=200000+10;
const LL MOD=1e9+7;


int main() {
    LL n,m;
    cin>>n>>m;
    LL nex,ans=(n%MOD)*(m%MOD);
    for(LL i=1;i<=n;i=nex+1){
        nex=n/(n/i);
        LL L=i,R=min(nex,m);
        LL tmp = ((R+L)%MOD) * ((R-L+1)%MOD) % MOD * ((MOD+1)/2) % MOD;
        ans = ans - ((n/L)%MOD *tmp%MOD);
        ans = (ans%MOD+MOD)%MOD;
        if(R==m)break;
    }
    cout<<ans<<endl;
}