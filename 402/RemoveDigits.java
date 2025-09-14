class Solution {
    public String removeKdigits(String str, int k) 
    {
        StringBuilder sb=new StringBuilder();
        for(char ch:str.toCharArray())
        {
            while(k>0 && sb.length()>0 && sb.charAt(sb.length()-1)>ch)
            {
                sb.deleteCharAt(sb.length()-1);
                k--;
            }
            sb.append(ch);
        }
        if(k>0)
        {
            sb.setLength(sb.length()-k);
        }
        int ind=0;
        while(ind<sb.length() && sb.charAt(ind)=='0')
        {
            ind++;
        }
        String res=sb.substring(ind);
        return res.isEmpty() ? "0":res;
    }
}