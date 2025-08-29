#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) 
    {
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());

        int ans=0;

        for(int house:houses)
        {
            auto it=lower_bound(heaters.begin(),heaters.end(),house);
            int distR= (it==heaters.end()) ?INT_MAX : abs(*it - house);
            int distL= (it==heaters.begin()) ? INT_MAX : abs(*(it-1)-house);
            int nearest=min(distR,distL);
            ans=max(ans,nearest);
        }
        return ans;
    }
};