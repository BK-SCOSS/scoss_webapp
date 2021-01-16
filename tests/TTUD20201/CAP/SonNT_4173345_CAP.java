import java.util.Scanner;

public class CAP {
    public static void main(String[] args) {
        Scanner sc =new Scanner(System.in);
        int t =sc.nextInt();
        for (int i=0;i<t;i++){
            int trung=0;
            int n=sc.nextInt();
            int[] a=new int[n];
            for (int j=0;j<n;j++){
                a[j]=sc.nextInt();
            }
            int m=sc.nextInt();
            int[] b=new int[m];
            for (int j=0;j<m;j++){
                b[j]=sc.nextInt();
            }
            if (a.length<b.length){
                for (int j=0;j<n;j++){
                    for (int o=0;o<m;o++){
                        if (a[j]==b[o]){
                            trung++;
                            break;
                        }
                    }
                }
            }else {
                for (int j=0;j<m;j++){
                    for (int o=0;o<n;o++){
                        if (b[j]==a[o]){
                            trung++;
                            break;
                        }
                    }
                }
            }
            System.out.println(trung);

        }
    }
}
