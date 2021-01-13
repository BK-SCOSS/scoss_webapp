import java.util.Scanner;

public class CNTDIV {

    public static void main(String[] args) {
        int T;
        int n;
        int k = 0;
        int lim;
        int a = 0;
        int[] arrT;
        int[] arrT2;
        Scanner sc = new Scanner(System.in);
        lim = sc.nextInt();
        int count = 0;
        while (a < lim){
            k = 0;
            n = sc.nextInt();
            T = n * (n + 1) * (n + 2);
            arrT = soUoc(T,T+1);
            arrT2 = soUoc(T*T,T);
            for (int x : arrT2){
                for(int y : arrT){
                    if(y == x){
                        k++;
                    }
                }
            }
            System.out.println(arrT2.length-k);
            a++;
        }
    }

    private static int[] soUoc(int t, int limit) {
        int[] arr = new int[t+1];
        int j = 0;
        int count = 0;
        for(int i = 1; i < limit; i++){
            if(t % i == 0){
                arr[i] = i;
                count++;
            }
        }
        int[] newarr = new int[count];
        for (int i = 0; i < t ; i++) {
            if(arr[i] != 0) {
                newarr[j] = arr[i];
                j++;
            }
        }
        return newarr;

    }
}
