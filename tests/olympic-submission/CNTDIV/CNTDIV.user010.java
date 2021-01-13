//package CNTDIV;
import java.util.*;
import java.lang.*;
public class CNTDIV {
	private ArrayList<Integer> uoc = new ArrayList<Integer>();
	private HashMap<Integer,Integer> uoc1 = new HashMap<Integer,Integer>();
	private HashMap<Long,Integer> anss = new HashMap<Long,Integer>();
	private int q;
	private int n;
	private long t;
	public void Get(int x)
	{
		for (int i = 1; i <= (int)Math.sqrt(x); i++)
		{
			if (x%i == 0)
			{
				if (!uoc1.containsKey(i))
				{
					uoc.add(i);
					uoc1.put(i, 1);
				}
				if (!uoc1.containsKey(x/i))
				{
					int tmp = x/i;
					uoc.add(tmp);
					uoc1.put(tmp, 1);
				}
			}
		}
	}
	public int count()
	{
		int ans = 0;
		for (int i = 0; i < uoc.size(); i++)
		{
			for (int j = 0; j <= i; j++)
			{
				for (int k = 0; k <= j; k++)
				{
					long tmp = (((long)uoc.get(i))*((long)uoc.get(j))*((long)uoc.get(k)));
					if (tmp < t&&(t%tmp!=0))
					{
						if (!anss.containsKey(tmp))
						{
							ans++;
							anss.put(tmp, 1);
						}
						//System.out.println(tmp);
					}
				}
			}
		}
		return ans;
	}
	public void Process()
	{
		Scanner scanner = new Scanner(System.in);
		q = scanner.nextInt();
		for (int ii = 0; ii < q; ii++)
		{
			uoc1 = new HashMap<Integer,Integer>();
			uoc = new ArrayList<Integer>();
			anss = new HashMap<Long,Integer>();
			n = scanner.nextInt();
			t = ((long)n)*((long)n+1)*((long)n+2);
			Get(n);
			Get(n+1);
			Get(n+2);
			Collections.sort(uoc);
			/**for (int i = 0; i < uoc.size(); i++)
			{
				System.out.print(uoc.get(i) +" ");
			}
			System.out.println("");
			System.out.println(t);**/
			System.out.println(count());
		}
		
	}
	public static void main(String[] args) {
		CNTDIV sol = new CNTDIV();
		sol.Process();
	}

}
