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

char change(char ch){
    if(ch >= 'A' and ch <= 'C') return '2';
    else if(ch >= 'D' and ch <= 'F') return '3';
    else if(ch >= 'G' and ch <= 'I') return '4';
    else if(ch >= 'J' and ch <= 'L') return '5';
    else if(ch >= 'M' and ch <= 'O') return '6';
    else if(ch >= 'P' and ch <= 'S') return '7';
    else if(ch >= 'T' and ch <= 'V') return '8';
    else return '9';
}

string parse(string s){
    string ret = "";
    for(int i=0;i<s.size();i++){
        if(isdigit(s[i])) ret += s[i];
        else if(isalpha(s[i])) ret += change(s[i]);
    }
    return ret;
}

map <string,int> m;

int main(){
//    filein;
    int t;
    input(t);
    for(int i=0;i<t;i++){
        string s;
        cin>>s;
        m[parse(s)]++;
    }
    bool print = false;
    for(map <string,int> :: iterator it = m.begin();it != m.end();it++){
        pair <string,int> i = *it;
        if(i.second > 1){
            print = true;
            for(int j=0;j<3;j++){
                cout<<i.first[j];
            }
            cout<<"-";
            for(int j=3;j<i.first.size();j++){
                cout<<i.first[j];
            }
            cout<<" "<<i.second<<endl;
        }
    }
    if(!print) cout<< "No duplicates." <<endl;
    return 0;
}
