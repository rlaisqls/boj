#include<stdio.h>
#include<vector>
#include<cassert>
#include<stdlib.h>
using namespace std;

const int MX = 55;
const int LIM = 50000000;

vector<int> G[MX];
int C[MX], cnt = 0;
int N, M;

bool dfs(int x)
{
	if( x == N+1 ) return true;
	cnt++;
	if( cnt >= LIM ) return true;
	int msk = 0;
	for(int c : G[x]){
		msk |= 1<<C[c];
	}
	for(int i = 1; i <= 4; i++){
		if( msk & 1<<i ) continue;
		C[x] = i;
		if( dfs(x+1) ) return true;
		C[x] = 0;
	}
	return false;
}

bool chk[MX][MX];
int main()
{
	assert(scanf("%d%d", &N, &M) == 2);
	assert(2 <= N && N <= 50 && 0 <= M && M <= N*(N-1)/2);
	for(int i = 1; i <= M; i++){
		int a, b;
		assert(scanf("%d%d", &a, &b) == 2);
		assert( 1 <= a && a <= N && 1 <= b && b <= N && a != b && !chk[a][b]);
		chk[a][b] = chk[b][a] = 1;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	dfs(1);
	assert(cnt >= LIM);

	for(int i = 1; i <= N; i++){
		C[i] = 0;
		assert(scanf("%d", C+i) == 1);
		assert(1 <= C[i] && C[i] <= 4);
	}
	for(int i = 1; i <= N; i++){
		for(int c : G[i]){
			assert(C[i] != C[c]);
		}
	}
	return 0;
}
