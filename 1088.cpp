#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <bitset>
#include <cassert>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>

#define eps 1e-9
#define pi acos(-1)
#define pb push_back
#define mp make_pair
#define INF 10000000
#define MOD 1000000007
#define pause system("pause")
#define mem(a,b) memset(a,b,sizeof(a))
#define clock 1.0*clock()/CLOCKS_PER_SEC
#define filein freopen("in.txt","r",stdin)
#define fileout freopen("out.txt","w",stdout)
#define fast std::ios::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

typedef long long ll;

int Set(int N, int p){return N|=(1<<p);}
int Reset(int N, int p){return N&=~(1<<p);}
bool Check(int N, int p){return N&(1<<p);}

template<class T> inline void input(T &x) {
    register char c = getchar();x = 0;
    int neg = 0;
    for(; ((c<48 || c>57) && c != '-'); c = getchar());
    if(c=='-'){neg = 1;c = getchar();}
    for(; c>47 && c<58 ; c = getchar()){x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x = -x;
}

const int dr[]={0,-1,0,1,-1,-1,1,1};
const int dc[]={1,0,-1,0,1,-1,-1,1};
const int M = 100+5;

int grid[M][M];
int dp[M][M];
int n, m;

int dfs(int row, int col){
	int ret = 1;
	if(dp[row][col] != -1) return dp[row][col];
    	for(int i=0;i<4;i++){
		int nrow = dr[i] + row;
		int ncol = dc[i] + col;
		if(row < 0 or row >= n or col < 0 or col >= m) continue;
		if(grid[nrow][ncol] > grid[row][col]){
			ret = max(ret, 1 + dfs(nrow, ncol));
		}
    }
    return dp[row][col] = ret;
}

int main(){
//	filein;
	input(n);
	input(m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			input(grid[i][j]);
		}
	}
	mem(dp,-1);
	int ans = 0;
    	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
            		ans = max(ans, dfs(i,j));
		}
    }
    cout<<ans<<endl;
    return 0;
}
