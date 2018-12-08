///*BISMILLAHIR RAHMANIR RAHIM*///
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll freq[30], nCr[30][30];


ll check( int n ) {
	ll res = 1;
	for ( int i = 0; i < 26; i++ ) {
		if ( freq[i] ) {
			res *= nCr[n][freq[i]];
			n -= freq[i];
		}
	}
	return res;
}
int main() {
	//freopen("out.txt","w",stdout);
	nCr[1][0] = 1;
	nCr[1][1] = 1;
	for ( int i = 2; i <= 27; i++ ) {
		nCr[i][0] = 1;
		nCr[i][1] = 1;
		for ( int j = 1; j <= i; j++ ) nCr[i][j] = nCr[i-1][j] + nCr[i-1][j-1];
	}
	int tc, cases = 0;
	ll n;
	string s;
	scanf("%d", &tc);
	while ( tc-- ) {
		cin >> s >> n;
		int len = s.length();
		memset(freq, 0, sizeof freq);
		for ( int i = 0; i < len; i++ ) {
			freq[s[i]-'a'] ++;
		}
		printf("Case %d: ", ++cases);
		if ( check(len) < n ){
			printf("Impossible\n");
		}	
		else {
			for ( int i = 1; i <= len; i++ ) {
				for ( int j = 0; j < 26; j++ ) {
					if ( freq[j] == 0 ) continue;
					freq[j] --;
					ll res = check ( len - i );
					if ( res >= n ) {
						printf("%c", j+'a');
						break;
					}
					freq[j]++;
					n-=res;
				}
			}
			printf("\n");
		}
	}
	return 0;
}
