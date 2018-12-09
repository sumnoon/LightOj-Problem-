///*BISMILLAHIR RAHMANIR RAHIM*///
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[50][4][6];
string s;
bool is_vowel ( char c ) {
	return ( c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' );
}
bool is_consonent ( char c ) {
	return ( c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U' && c != '?');
}
int func ( int pos, int cons_cont, int vol_cont ) {
	if ( cons_cont == 5 || vol_cont == 3 ) return 1;
	if ( pos == (int)s.length() ) return 2;
	if ( dp[pos][vol_cont][cons_cont] != -1 ) return dp[pos][vol_cont][cons_cont];
	if ( s[pos] == '?' ) {
		dp[pos][vol_cont][cons_cont] = func ( pos + 1, cons_cont + 1, 0 ) | func ( pos + 1, 0, vol_cont + 1 );
	} 
	else if ( s[pos] == '0' ) {
		dp[pos][vol_cont][cons_cont] = func ( pos + 1, 0, vol_cont + 1 );
	}
	else if ( s[pos] == '1' ) {
		dp[pos][vol_cont][cons_cont] = func ( pos + 1, cons_cont + 1, 0 );
	}
	return dp[pos][vol_cont][cons_cont];
}
int main(){
	int tc, cases = 0, i, len;
	scanf("%d", &tc);
	while ( tc-- ) {
		memset( dp, -1, sizeof dp );
		cin >> s;
		len = s.length();
		for ( i = 0; i < len; i++ ) {
			if ( is_vowel( s[i] ) ) s[i] = '0';
			else if ( is_consonent( s[i] ) ) s[i] = '1';
		}
		int ans = func ( 0, 0, 0 );
		printf("Case %d: ", ++cases);
		if ( ans == 1 ) printf("BAD\n");
		else if ( ans == 2 ) printf("GOOD\n");
		else printf("MIXED\n");
	}
	return 0;
}
