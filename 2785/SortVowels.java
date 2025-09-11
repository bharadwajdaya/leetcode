import java.lang.*;

class SortVowels2785
{
    public String sortVowels(String s)
    {
        String vowels="AEIOUaeiou";
        int vInd=0;
        StringBuilder result=new StringBuilder();
        int[] freq=new int[10];
        for(char ch:s.toCharArray())
        {
            int ind=vowels.indexOf(ch);
            if(ind!=-1)
            {
                freq[ind]++;
            }
        }
        for(char ch:s.toCharArray())
        {
            if(vowels.indexOf(ch)!=-1)
            {
                while(vInd<10 && freq[vInd]==0) vInd++;
                result.append(vowels.charAt(vInd));
                freq[vInd]--;
            }
            else
            {
                result.append(ch);
            }
        }
        return result.toString();
    }
    public static void main(String[] args) {
        SortVowels2785 sortV=new SortVowels2785();
        String s="lEetcOde";
        System.out.println(sortV.sortVowels(s));
        
    }
}