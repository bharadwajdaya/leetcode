#include<iostream>
#include<vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums)
{
    int n=nums.size();
    vector<int> res(n,1);
    for(int i=1;i<n;i++)
    {
        res[i]=res[i-1]*nums[i-1];
    }
    int suffix=1;
    for(int i=n-1;i>=0;i--)
    {
        res[i]*=suffix;
        suffix=suffix*nums[i];
    }
    return res;
}
int main()
{
    vector<int> nums={1,2,3,4};
    vector<int> res=productExceptSelf(nums);
    for(int num:res)
    {
        cout<<num<<",";
    }
    cout<<endl;
    return 0;
}


/*
1,2,3,4
[24,12,8,6]
                2*3*4
1*              3*4
1*2*            4
1*2*3


*/