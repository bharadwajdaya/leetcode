#include<iostream>
#include<vector>
using namespace std;
int maxProduct(vector<int>& nums)
{
    int product=1;
    int maxProduct=nums[0];
    for(int num:nums)
    {
        
        product*=num;
        maxProduct=max(maxProduct,product);
        if(num==0)
        {
            product=1;
        }
    }
    product=1;
    for(int i=nums.size()-1;i>=0;i--)
    {
        product*=nums[i];
        maxProduct=max(maxProduct,product);
        if(nums[i]==0)
        {
            product=1;
        }
    }
    return maxProduct;
}
int main()
{
    vector<int> nums={2,3,-2,4};
    cout<<maxProduct(nums)<<endl;
    return 0;
}