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
const int M = 100000+5;

int main(){
	int a;
	input(a);
	for(int i=0;i<a;i++){
		double x, y;
		cin>>x>>y;
		double r = hypot(x,y);
		double area = pi * r * r / 2.0;
		int year = area / 50.0;
		printf("Property %d: This property will begin eroding in year %d.\n",i+1,year+1);
	}
	puts("END OF OUTPUT.");
    return 0;
}
