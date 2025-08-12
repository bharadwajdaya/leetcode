#include<iostream>
#include<string>
#include<vector>
using namespace std;
static constexpr int MOD = 1'000'000'007;
long long getPow(long long n,int x)
{
    long long res=1;
    long long base=n;
    while(x>0)
    {
        if(x&1)
        {
            res=(res*base)%MOD;
            cout<<"x: "<<x<<" res: "<<res<<" n: "<<n<<endl;
        }
        base=(base*base)%MOD;
        x=x>>1;
        cout<<"Out x: "<<x<<" res: "<<res<<" n: "<<n<<endl;
    }
    return res;
}
int numberOfWays(int n,int x)
{
    vector<long long> allPows;
    for(long long num=1;;num++)
    {
        long long pow=getPow(num,x);
        if(pow>n)
        {
            break;
        }
        allPows.push_back((int)pow);
    }
    vector<int> dp(n+1,0);
    dp[0]=1;

    for(int p:allPows)
    {
        for(int s=n;s>=p;s--)
        {
            dp[s]=(dp[s]+dp[s-p])%MOD;
            if(dp[s]>=MOD)
            {
                dp[s]-=MOD;
            }
        }
    }
    return (int)dp[n];
}
int main()
{
    int n=2;
    int x=5;
    cout<<numberOfWays(n,x)<<endl;
    return 0;
}