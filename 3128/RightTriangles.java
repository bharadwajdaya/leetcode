class Solution {
    public long numberOfRightTriangles(int[][] grid) {
        int r=grid.length;
        int c=grid[0].length;

        int[] rows=new int[r];
        int[] cols=new int[c];

        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]==1)
                {
                    rows[i]++;
                    cols[j]++;
                }
            }
        }
        long res=0;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]==1)
                {
                    res+=((rows[i]-1)*(cols[j]-1));
                }
            }
        }
        return res;
    }
}