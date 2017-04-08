#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct ivp
{
    int idx;
    ll val;
};
ivp hist[100005];
int lft[100005];
int rgt[100005];
int main()
{

    int n;

    while(scanf("%d",&n)==1)
    {
        if(n==0)
        {
            break;
        }


        for(int i=1; i<=n; i++)
        {
            hist[i].idx = i;
            scanf("%lld",&hist[i].val);

        }
        hist[0].idx = 0;
        hist[0].val = 0;
        hist[n+1].idx = n+1;
        hist[n+1].val = 0;

        stack<ivp>slf;
        for(int i=1; i<=n; i++)
        {
            int idxsol = 0;
            while(!slf.empty()
                    && slf.top().val>=hist[i].val)
            {

                slf.pop();
            }

            if(!slf.empty())
            {

                idxsol = slf.top().idx;
            }
            slf.push(hist[i]);

            lft[i] = idxsol;
        }

        while(!slf.empty())
            slf.pop();


        for(int i=n; i>=1; i--)
        {
            int idxsol = n+1;
            while(!slf.empty()
                    && slf.top().val>=hist[i].val)
            {

                slf.pop();
            }

            if(!slf.empty())
            {

                idxsol = slf.top().idx;
            }
            slf.push(hist[i]);
            rgt[i] = idxsol;
        }

        while(!slf.empty())
            slf.pop();

        ll ans = 0;
        for(int i=1;i<=n;i++)
        {

            ans = max(ans,
                      hist[i].val*(rgt[i]-lft[i]-1));

        }

        printf("%lld\n",ans);


    }



    return 0;
}
