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
const int M = 21252;

int arr[4*M];

int main(){
//	filein;
	int T = 1;
	int p, e, ii, d;
	while(cin>>p>>e>>ii>>d){
		if(p == -1 and e == -1 and ii == -1 and d == -1) break;
		mem(arr,0);
		for(int i=p;i<4*M;i+=23){
			arr[i]++;
		}
		for(int i=p;i>=0;i-=23){
			arr[i]++;
		}
		arr[p]--;
		for(int i=e;i<4*M;i+=28){
			arr[i]++;
		}
		for(int i=e;i>=0;i-=28){
			arr[i]++;
		}
		arr[e]--;
		for(int i=ii;i<4*M;i+=33){
			arr[i]++;
		}
		for(int i=ii;i>=0;i-=33){
			arr[i]++;
		}
		arr[ii]--;
		for(int i=d+1;i<4*M;i++){
			if(arr[i] == 3){
				printf("Case %d: the next triple peak occurs in %d days.\n",T++,i-d);
				break;
			}
		}
	}
    return 0;
}
