#include<iostream>
#include<vector>
using namespace std;
long long zeroFilledSubarray(vector<int>& nums)
{
    long long curr_zero=0;
    long long final_count=0;
    for(int num:nums)
    {
        if(num==0)
        {
            curr_zero++;
            final_count+=curr_zero;
        }
        else
        {
            curr_zero=0;
        }
    }
    return final_count;
}
int main()
{
    vector<int> nums={1,3,0,0,2,0,0,4};
    cout<<zeroFilledSubarray(nums)<<endl;
    return 0;
}