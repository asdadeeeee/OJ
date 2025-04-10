#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
using namespace std;
int n,m;
int maxsub(const string &s1,const string &s2){
  vector<int> dp(m+1,0);
  int res = 0;
  for(int i=0;i<m;i++){
    for(int j=m;j>=1;j--){
      if(s1[i] == s2[j-1]){
        dp[j] = dp[j-1]+1;
      }else{
        dp[j] = 0;
      }
      res = max(res,dp[j]);
    }
  }
  return res;
}
string rolls(const string &s1,int begin){
  string left=s1.substr(0,begin-0);
  string right = s1.substr(begin,m-begin);
  return right+left;
}

int maxrollsub(const string &s1,const string &s2){
  int res = 0;
  for(int i=0;i<m;i++){
    string rs = rolls(s2,i);
    int sub = maxsub(s1,rs);
    res = max(res,sub);
  }
  return res;
}
struct edge{
  int s;
  int e;
  int value;
};
struct cmp{
  bool operator()(const edge &a,const edge &b){
    return a.value > b.value;
  }
};
class UF{
  public:
   UF(int n){
     count = n;
     parent.resize(n);
     for(int i=0;i<n;i++){
       parent[i] = i;
     }
   }
   int findp(int n){
     if(parent[n] != n){
       parent[n] = findp(parent[n]);
     }
     return parent[n];
   }
   bool ifuni(int p,int q){
     int pp = findp(p);
     int pq = findp(q);
     return pp == pq;
   }
   void connect(int p,int q){
     int rp = findp(p);
     int rq = findp(q);
     if(rp == rq){
       return;
     }
     parent[rp] = rq;
     count--;
   }
   int getCount(){
     return count;
   }
  private:
   int count;
   vector<int> parent;
};
int main()
{
  
  cin >> n >> m;
  vector<string> ss(n);
  UF uf(n);
  for(int i=0;i<n;i++){
    cin>>ss[i];
  }
  vector<edge> es;
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      int v = maxrollsub(ss[i],ss[j]);
      edge e{i,j,v};
      es.emplace_back(e);
    }
  }
  sort(es.begin(),es.end(),cmp());
  unordered_set<int> g;
  int ans;
  for(const auto &e:es){
    if(uf.getCount() == 1){
      break;
    }
    if(uf.ifuni(e.s,e.e)){
      continue;
    }
    uf.connect(e.s,e.e);
    ans+=e.value;
  }
  cout<< ans;
  return 0;
}