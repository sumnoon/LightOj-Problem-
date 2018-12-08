///*BISMILLAHIR RAHMANIR RAHIM*///
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

typedef long long ll;
ll nCr[1001][1001], fact[1001];
void pre() {
	fact[0] = 1;
	for ( int i = 1; i <= 1001; i++ ) {
		fact[i] = ( fact[i-1]*i ) % mod;
	}
}
int main() {
	//freopen("out.txt","w",stdout);
	pre();
	int tc, cases = 0, n, m, k, i, j;
	ll ans1, ans2;
	scanf("%d", &tc);
	nCr[1][0] = 1;
	nCr[1][1] = 1;
	for ( i = 2; i <= 1000; i++ ) {
		nCr[i][0] = 1;
		nCr[i][1] = 1;
		for ( j = 1; j <= i; j++ ) {
			nCr[i][j] = ( nCr[i-1][j] % mod ) + ( nCr[i-1][j-1] % mod );
			nCr[i][j] %= mod;
		}
	} 
	while ( tc-- ) {
		scanf("%d%d%d", &n, &m, &k);
		ans1 = nCr[m][k];
		ans2 = fact[n-k];
		for ( i = 1; i <= m - k; i++ ) {
			if ( i & 1 ) ans2 -= (nCr[m-k][i]*fact[n-k-i])%mod;
			else ans2 +=  (nCr[m-k][i]*fact[n-k-i])%mod;
			ans2 = ( ans2 + mod ) % mod;
		}
		printf("Case %d: %d\n", ++cases, (ans1*ans2)%mod);
	}
	return 0;
}		
