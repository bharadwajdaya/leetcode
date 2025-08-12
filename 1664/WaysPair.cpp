#include<iostream>
#include<string>
#include<vector>
using namespace std;
int waysToMakeFair(vector<int>& nums) 
{
    long long evenTotal=0;
    long long oddTotal=0;
    int n=nums.size();
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(i%2==0)
        {
            evenTotal+=nums[i];
        }
        else
        {
            oddTotal+=nums[i];
        }
    }
    long long preEven=0;
    long long preOdd=0;
    for(int i=0;i<n;i++)
    {
        int curr=nums[i];

        long long leftEven=preEven;
        long long leftOdd=preOdd;
        long long rightEven=evenTotal-(i%2 ? 0 : curr)-preEven;
        long long rightOdd=oddTotal-(i%2?curr:0)-preOdd;

        long long evenAfter=leftEven+rightOdd;
        long long oddAfter=leftOdd+rightEven;
        if(evenAfter==oddAfter)
        {
            count++;
        }
        if(i%2==0)
        {
            preEven+=curr;
        }
        else
        {
            preOdd+=curr;
        }
    }
    return count;
}
int main()
{
    vector<int> nums={2,1,6,4};
    cout<<waysToMakeFair(nums)<<endl;
    return 0;
}