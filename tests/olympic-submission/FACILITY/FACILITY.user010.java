//package FACILITY;
import java.util.*;
import java.io.*;

public class FACILITY {
	private int n,k;
	private ArrayList<Company> locom = new ArrayList<Company>();
	public class Company{
		int start;
		int day;
		int rate;
		public Company(int start, int day, int rate)
		{
			this.start = start;
			this.day = day;
			this.rate = rate;
		}
		public String toString()
		{
			return this.start+" "+this.day+" "+this.rate;
		}
	}
	class MyComparator implements Comparator<Company>
	{
		public int compare(Company o1, Company o2)
		{
			if (o1.start>o2.start)
			{
				return 1;
			}
			if (o2.start>o1.start)
			{
				return -1;
			}
			return 0;
		}
	}
	public void Process()
	{
		Scanner scanner = new Scanner(System.in);
		n = scanner.nextInt();
		k = scanner.nextInt();
		int s,d,r;
		for (int i = 0; i < n; i++)
		{
			s = scanner.nextInt();
			d = scanner.nextInt();
			r = scanner.nextInt();
			Company o = new Company(s,d,r);
			locom.add(o);
		}
		Collections.sort(locom, new MyComparator());
		long[] maxx = new long[n+5];
		for (int i = 0; i < n; i++)
		{
			maxx[i] = (long)locom.get(i).rate;
		}
		for (int i = 1; i < n; i++)
		{
			int di = locom.get(i).day;
			int si = locom.get(i).start;
			int ri = locom.get(i).rate;
			for (int j = 0; j < i; j++)
			{
				int dj = locom.get(j).day;
				int rj = locom.get(j).rate;
				int sj = locom.get(j).start;
				if (sj+dj<=si)
				{
					if ((maxx[j]+(long)ri)>maxx[i])
					{
						maxx[i] = maxx[j]+(long)ri;
					}
				}
			}
		}
		long res = -1;
		for (int i = 0; i < n; i++)
		{
			if (maxx[i]>res)
			{
				res = maxx[i];
			}
		}
		System.out.println(res);
		scanner.close();
	}
	public static void main(String args[])
	{
		FACILITY sol = new FACILITY();
		sol.Process();
	}
}
