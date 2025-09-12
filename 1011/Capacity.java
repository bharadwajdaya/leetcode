class Solution {
    public boolean checkifpossible(int[] weights,int days,int m)
    {
        int numerofdays=1;
        int curr=0;
        for(int w:weights)
        {
            if(curr+w<=m)
            {
                curr+=w;
            }
            else
            {
                numerofdays++;
                curr=w;
                if(numerofdays>days)
                {
                    return false;
                }
            }
        }
        return numerofdays<=days;
    }
    public int shipWithinDays(int[] weights, int days) {
        int sum=0;
        int maxWeight=0;
        for(int w:weights)
        {
            sum+=w;
            if(w>maxWeight)
            {
                maxWeight=w;
            }
        }
        int l=maxWeight;
        int r=sum;
        while(l<r)
        {
            int m=l+(r-l)/2;
            if(checkifpossible(weights,days,m))
            {
                r=m;
            }
            else
            {
                l=m+1;
            }
        }
        return (int)l;
    }
}