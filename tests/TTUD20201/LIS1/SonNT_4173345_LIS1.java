import java.util.Arrays;
import java.util.Scanner;

public class LIS1 {
    public static void main(String[] args) {
        Scanner sc =new Scanner(System.in);
        int t =sc.nextInt();
        for (int j=0;j<t;j++){
            int m =sc.nextInt();
            int[] a= new int[m];
            for (int i=0;i<m;i++){
                a[i]=sc.nextInt();
            }
            int[] so =new int[m];
            for (int i=m-2;i>=0 ;i--){
                int number=a[i];

                for (int k=i+1;k<m;k++){
                    if (a[k]==number+1){
                        so[i]=so[k]+1;
                        break;
                    }
                }
            }
            int max =0;
            for (int i=0;i<m;i++){
              if (so[i]>max){
                  max=so[i];
              }
            }

            System.out.println(max+1);
        }
    }
}
