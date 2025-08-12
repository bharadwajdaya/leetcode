#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<int> getSumAbsoluteDifferences(vector<int>& nums)
{
    int n=nums.size();
    vector<int> prefSum(n,0);
    prefSum[0]=nums[0];
    vector<int> res(n,0);
    for(int i=1;i<n;i++)
    {
        prefSum[i]=prefSum[i-1]+nums[i];
    }

    for(int i=0;i<n;i++)
    {
        int leftSideSum=(i*nums[i])-(i>0?prefSum[i-1]:0);
        int rightSideSum=(prefSum[n-1]-prefSum[i]) -(n-i-1)*nums[i];
        res[i]=leftSideSum+rightSideSum;
    }
    return res;
}

int main()
{
    vector<int> nums={2,3,5};
    vector<int> res=getSumAbsoluteDifferences(nums);
    for(int n:res)
    {
        cout<<n<<",";
    }
    cout<<endl;
    return 0;
}