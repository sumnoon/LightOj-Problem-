///*BISMILLAHIR RAHMANIR RAHIM*///
/// Aho-Corasick Algorithm for string matching
/// Complexity O(N + M) + O(MAX * LET), N = text length, M = sum of pattern length, MAX = Total nodes in trie
#include <bits/stdc++.h>
using namespace std;
#define N 500*500 + 10
typedef long long ll;
const int K = 26;
int trie[N][K], val[N], fail[N], freq[N], T[N], que[N], ss, ind, len;
void insert ( string s ) {
	int u = 0;
	for ( char x : s ) {
		int c = x - 'a';
		if ( !trie[u][c] ) {
			trie[u][c] = ++ss; 
		}
		u = trie[u][c];
	}
	val[ind] = u; /// saving the index of the current pattern.
} 
void build_fail() {
	int i, j, x, f = 0, l = 0;
	for ( i = 0; i < K; i++ ) {
		 x = trie[0][i];
		 if ( x ) {
		 	que[l++] = x;
		 }
	}
	while ( f < l ) {
		i = que[f++];
		for ( j = 0; j < K; j++ ) {
			int &v = trie[i][j];
			if ( v == 0 ) v = trie[fail[i]][j];
			else {
				fail[v] = trie[fail[i]][j];
				que[l++] = v, T[len++] = v; 
			}
		}
	}
}

void search ( string s ) {
	int i, j, x, cur = 0;
	for ( i = 0; i < s.length(); i ++ ) {
		int c = s[i] - 'a';
		cur = trie[cur][c];
		freq[cur]++;
	}
	for ( i = len - 1; i >= 0; i-- ) freq[fail[T[i]]] += freq[T[i]];/// add to count of fail node also
}

void clr() {
	ind = 0, ss = 0, len = 0;
	memset(trie, 0, sizeof trie);
	memset(freq, 0, sizeof freq);
	memset(fail, 0, sizeof fail);
}
string pat[N];
int main () {
	// freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	int tc, cases = 0, n, i;
	string txt;
	scanf("%d", &tc);
	while ( tc-- ) {
		clr();
		scanf("%d", &n);
		cin >> txt;
		for ( i = 1; i <= n; i++ ) {
			cin >> pat[i];
			ind = i;
			insert(pat[i]);
		}
		build_fail();
		search(txt);
		printf("Case %d:\n", ++cases);
		for ( i = 1; i <= n; i++ ) {
			printf("%d\n", freq[val[i]]);
		}
	}
	return 0;
}
