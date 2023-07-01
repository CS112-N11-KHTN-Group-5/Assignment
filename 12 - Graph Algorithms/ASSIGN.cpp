#include <bits/stdc++.h>
#define fo(i,m,n) for(int i = m; i <= n; i++)
#define fod(i,m,n) for(int i = m; i >= n; i--)
using namespace std;
const int inf = INT_MAX;
const int N = 200;
int a[N+1][N+1];
int X[N+1], Y[N+1];
int d[N+1];
int minn = 0, maxx = inf;
int n,k,x,g, _next,y;
int Run(int h)
{
    memset(d,0,sizeof(d));
    queue <int> Line;
    Line.push(h);
    while(!Line.empty())
    {
        x = Line.front();
        Line.pop();
        fo(i,1,n)
        {
            if(a[x][i] <= k && !d[i])
            {
                d[i] = x;
                if(!X[i])
                {
                    return i;
                }
                else Line.push(X[i]);
            }
        }
    }
    return 0;
}
void Change()
{
    x = g;
    while(x)
    {
        y = d[x];
        _next = Y[y];
        Y[y] = x;
        X[x] = y;
        x = _next;
    }
}
bool Find(int h)
{
    memset(Y,0,sizeof(Y));
    memset(X,0,sizeof(X));
    k = h;
    fo(i,1,n)
    {
        if(!Y[i])
        {
            g = Run(i);
            if(g) Change();
        }
    }
    fo(i,1,n) if(!Y[i]) return false;
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    fo(i,1,n) fo(j,1,n)
    {
        cin >>  a[i][j];
        minn = min(minn,a[i][j]);
    }
    int h;
    while(maxx > minn)
    {
        h = (minn + maxx) >> 1;
        if(Find(h)) maxx = h;
        else minn = h + 1;
    }
    cout << minn;
}
