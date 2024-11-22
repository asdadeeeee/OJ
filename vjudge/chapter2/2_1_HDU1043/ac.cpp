#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <set>
#include <sstream>
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define Mod 1000000007
#define eps 1e-6
#define ll long long
#define INF 0x3f3f3f3f
#define MEM(x,y) memset(x,y,sizeof(x))
#define Maxn 362880+5//876543210的hash值为362880 即最多出现362880种可能
using namespace std;
static const int FAC[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};    // 阶乘
struct node
{
    string path;//路径
    int hashs;//hash值
    int pos;//0的位置
};
node now,net;
queue<node>q;
int dt[][4]= {{1,0},{-1,0},{0,1},{0,-1}};//四个方向
char op[5]="udlr";//这个与上面的搜索方向是反的，因为是反向bfs
int tmp[9];//临时存储拼图的序列
int result=46234;//123456780    最终答案的hash值
string path[Maxn];//path[x] hash值为x的路径
int vis[Maxn];//vis[x]  hash值为x的拼图序列是否标记过
//康托展开
int cantor(int *a)
{
    int x = 0;
    for (int i = 0; i < 9; ++i)
    {
        int smaller = 0;  // 在当前位之后小于其的个数
        for (int j = i + 1; j < 9; ++j)
        {
            if (a[j] < a[i])
                smaller++;
        }
        x += FAC[9 - i - 1] * smaller; // 康托展开累加
    }
    return x+1;  // 康托展开值
}
//逆康托展开
void decantor(int x, int *a)
{
    vector<int> v;  // 存放当前可选数
    for(int i=0; i<9; i++)
        v.push_back(i);
    for(int i=0; i<9; i++)
    {
        int r = x % FAC[9-i-1];
        int t = x / FAC[9-i-1];
        x = r;
        sort(v.begin(),v.end());// 从小到大排序
        a[i]=v[t];      // 剩余数里第t+1个数为当前位
        v.erase(v.begin()+t);   // 移除选做当前位的数
    }
}
void bfs()
{
    MEM(vis,0);//初始化
    for(int i=0; i<8; i++)//tmp一开始为123456780，从这开始打散拼图
        tmp[i]=i+1;
    tmp[8]=0;
    now.pos=8;
    now.hashs=result;
    now.path="";
    path[result]="";
    vis[result]=1;
    q.push(now);
    while(!q.empty())
    {
        now=q.front();
        q.pop();
        for(int i=0; i<4; i++)//四个方向
        {
            int tx=now.pos/3+dt[i][0];
            int ty=now.pos%3+dt[i][1];
            if(tx>=0&&ty>=0&&tx<=2&&ty<=2)//没走出去拼图
            {
                net=now;
                net.pos=tx*3+ty;
                decantor(now.hashs-1,tmp);//求tmp
                swap(tmp[now.pos],tmp[net.pos]);//得到新的tmp
                net.hashs=cantor(tmp);//得到新tmp对应的hash
                if(!vis[net.hashs])//这都bfs老套路了 没啥说的
                {
                    vis[net.hashs]=1;
                    net.path=op[i]+net.path;
                    q.push(net);
                    path[net.hashs]=net.path;
                }
            }
        }
    }
    return;
}
int main()
{
    bfs();
    char x;
    while(cin>>x)//输入格式 没啥说的
    {
        if(x=='x')
        {
            now.pos=0;
            tmp[0]=0;
        }
        else
        {
            tmp[0]=x-'0';
        }
        for(int i=1; i<9; i++)
        {
            cin>>x;
            if(x=='x')
            {
                now.pos=i;
                tmp[i]=0;
            }
            else
            {
                tmp[i]=x-'0';
            }
        }
        now.hashs=cantor(tmp);//求出tmp这个拼图序列的hash值
        if(!vis[now.hashs])//这个hash没标记过，即没产生过这个拼图序列
            cout<<"unsolvable"<<endl;
        else
            cout<<path[now.hashs]<<endl;//输出hash的路径
    }
    return 0;
}