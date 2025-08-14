#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
vector< vector<int> > threeSum(vector<int>& _num)
{
    vector< vector<int> > ans;
    int n=_num.size();
    sort(_num.begin(),_num.end());

    for(int i=0;i<_num.size()-2;i++)
    {
        if(n<2)
        {
            // vector<int> _temp;
            // _temp.assign(_num.begin(),_num.end());
            // ans.push_back(_temp);
            return ans;
        }
        if(i==0 || (i>0 &&_num[i]!=_num[i-1]))
        {
            int low=i+1;
            int high=n-1;
            int sum=0-_num[i];

            while(low<high)
            {
                if(sum==_num[low]+_num[high])
                {
                    cout<<_num[i]<<_num[low]<<_num[high]<<endl;
                    vector<int> _temp;
                    _temp.push_back(_num[i]);
                    _temp.push_back(_num[low]);
                    _temp.push_back(_num[high]);

                    ans.push_back(_temp);

                    
                    while(low<high && _num[high]==_num[high-1])
                    {
                        high--;
                    }
                    low++;
                    high--;
                }
                else if(_num[low]+_num[high]>sum)
                {
                    high--;
                }
                else
                {
                    low++;
                }
            }
        }
    }
    return ans;  
}
};