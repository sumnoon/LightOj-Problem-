///*BISMILLAHIR RAHMANIR RAHIM*///
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[55][55][55];
int main(){
	//freopen("out.txt","w",stdout);
	int tc, cs = 0, i, j , k, n, m, o;
	string s1, s2, s3;
	scanf("%d", &tc);
	while ( tc-- ) {
 		cin >> s1 >> s2 >> s3;
 		n = s1.length();
 		m = s2.length();
 		o = s3.length();
 		memset( dp, 0, sizeof dp );
 		for ( i = 0; i <= n; i++ ) {
 			for ( j = 0; j <= m; j++ ) {
 				for ( k = 0; k <= o; k++ ) {
 					if ( i == 0 || j == 0 || k == 0 ) dp[i][j][k] = 0;
 					else if ( s1[i-1] == s2[j-1] && s2[j-1] == s3[k-1] )dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
 					else {
 						dp[i][j][k] = max ( dp[i-1][j][k], max ( dp[i][j-1][k], dp[i][j][k-1] ));
 					}
 				}
 			}
 		}
 		printf("Case %d: %d\n", ++cs, dp[n][m][o]);
	}
	return 0;
}