import java.util.HashMap;
import java.util.Map;

public class FractionToDecimal
{
    public String fractionToDecimal(int n, int d)
    {
        StringBuilder sb=new StringBuilder();
        int intPart=n/d;

        int remain=n%d;
        sb.append(intPart);
        if(remain==0)
        {
            return sb.toString();
        }
        sb.append(".");
        Map<Integer,Integer> map=new HashMap<>();
        while(remain!=0)
        {
            if(map.containsKey(remain))
            {
                int inPos=map.get(remain);
                sb.insert(inPos,"(");
                sb.append(")");
                break;
            }
            map.put(remain,sb.length());
            remain=remain*10;
            int denomi=remain/d;
            sb.append(denomi);
            remain=remain%d;
        }
        return sb.toString();
    }
    public static void main(String[] args)
    {
        FractionToDecimal fractionToD=new FractionToDecimal();
        System.out.println(fractionToD.fractionToDecimal(4,333));
    }
}
