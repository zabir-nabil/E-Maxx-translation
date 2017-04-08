

#include <bits/stdc++.h>


#define loop(i,s,e) for(int i = s;i<=e;i++) //including end point

#define pb(a) push_back(a)

#define sqr(x) ((x)*(x))

#define CIN ios_base::sync_with_stdio(0); cin.tie(0);

#define ll long long

#define ull unsigned long long

#define SZ(a) int(a.size())

#define read() freopen("input.txt", "r", stdin)

#define write() freopen("output.txt", "w", stdout)


#define ms(a,b) memset(a, b, sizeof(a))

#define all(v) v.begin(), v.end()

#define PI acos(-1.0)

#define pf printf

#define sfi(a) scanf("%d",&a);

#define sfii(a,b) scanf("%d %d",&a,&b);

#define sfl(a) scanf("%lld",&a);

#define sfll(a,b) scanf("%lld %lld",&a,&b);

#define sful(a) scanf("%llu",&a);

#define sfulul(a,b) scanf("%llu %llu",&a,&b);

#define sful2(a,b) scanf("%llu %llu",&a,&b); // A little different

#define sfc(a) scanf("%c",&a);

#define sfs(a) scanf("%s",a);

#define getl(s) getline(cin,s);

#define mp make_pair

#define paii pair<int, int>

#define padd pair<dd, dd>

#define pall pair<ll, ll>

#define vi vector<int>

#define vll vector<ll>

#define mii map<int,int>

#define mlli map<ll,int>

#define mib map<int,bool>

#define fs first

#define sc second

#define CASE(t) printf("Case %d: ",++t) // t initialized 0

#define cCASE(t) cout<<"Case "<<++t<<": ";

#define D(v,status) cout<<status<<" "<<v<<endl;

#define INF 1000000000   //10e9

#define EPS 1e-9

#define flc fflush(stdout); //For interactive programs , flush while using pf (that's why __c )

#define CONTEST 1
using namespace std;
int hist2d[2005][2005];
int lft[2005];
int rgt[2005];
struct ivp
{
    int idx;
    int val;
};
int main()
{
    int tc,cas=0;

    sfi(tc);

    while(tc--)
    {
        int m,n;
        sfii(m,n);

        for(int i=1;i<=m;i++)
        {
            char pass[2005];
            sfs(pass);

            for(int j=1;j<=n;j++){
                hist2d[i][j] = (pass[j-1]-'0');
                hist2d[i][j] = 1 - hist2d[i][j];
            }

        }

        for(int i=1; i<=m; i++)
            for(int j=1; j<=n; j++)
            {


                if(hist2d[i][j]!=0)
                    hist2d[i][j]+=hist2d[i-1][j];
            }

        int ans = 0;
        for(int r=1; r<=m; r++)
        {
            stack<ivp>sts;

            for(int c=1; c<=n; c++)
            {
                int idxv = 0;

                while(!sts.empty()

                        && sts.top().val>=hist2d[r][c])
                {

                    sts.pop();
                }

                if(!sts.empty())
                {
                    idxv = sts.top().idx;
                }
                ivp tmp;
                tmp.idx = c;
                tmp.val = hist2d[r][c];
                sts.push(tmp);

                lft[c] = idxv;

            }

            while(!sts.empty())
                sts.pop();


            for(int c=n; c>=1; c--)
            {
                int idxv = n+1;

                while(!sts.empty()

                        && sts.top().val>=hist2d[r][c])
                {

                    sts.pop();
                }

                if(!sts.empty())
                {
                    idxv = sts.top().idx;
                }
                ivp tmp;
                tmp.idx = c;
                tmp.val = hist2d[r][c];
                sts.push(tmp);
                rgt[c] = idxv;

            }

            while(!sts.empty())
                sts.pop();

            for(int cc=1; cc<=n; cc++)
            {

                ans = max(ans,
                          hist2d[r][cc]*(rgt[cc] - lft[cc] - 1));


            }


        }

        CASE(cas);
        pf("%d\n",ans);





    }



    return 0;
}
