#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool isPossible(vector<vector<int>> nums)
{
    auto sortbysecond= [](vector<int>& a,vector<int>& b){
        return a[1]<b[1];
    };
    sort(nums.begin(),nums.end(),sortbysecond);
    int n=nums.size();
    int last_y=nums[0][1];
    for(int i=1;i<n;i++)
    {
        if(last_y > nums[i][0])
        {
            return false;
        }
        last_y=nums[i][1];
    }
    return true;
}
int main()
{
    vector<vector<int>> nums={{2, 4}, {9, 12}, {6, 10}};
    // 2 4 
    // 6 10
    // 9 12
    // 10 15
    cout<<(isPossible(nums)?"True":"False")<<endl;
    return 0;
}