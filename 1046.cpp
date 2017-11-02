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

class point{
public:
    int a,b,c;
    point(){}
    point(int _a, int _b, int _c){
		a = _a, b = _b, c = _c;
    }
};

vector <point> v;

point ans(point p){
    double d=99999999.0;
    point ret;
    for(int i=0;i<v.size();i++){
        int x=abs(p.a-v[i].a);
        int y=abs(p.b-v[i].b);
        int z=abs(p.c-v[i].c);
        if(d>sqrt(x*x+y*y+z*z)){
            ret=point(v[i].a,v[i].b,v[i].c);
            d=sqrt(x*x+y*y+z*z);
        }
    }
    return ret;
}

int main (){
    int a,b,c;
    for(int i=0;i<16;i++){
        cin>>a>>b>>c;
        point p(a,b,c);
        v.push_back(p);
    }
    while(cin>>a>>b>>c){
        if(a==-1 and b==-1 and c==-1) break;
        point to(a,b,c);
        point ret=ans(to);
        printf("(%d,%d,%d) maps to (%d,%d,%d)\n",to.a,to.b,to.c,ret.a,ret.b,ret.c);
    }
    return 0;
}
