import java.util.Queue;
import java.util.Scanner;
import java.util.concurrent.LinkedTransferQueue;

public class GROUPUP {
    public static void main(String[] args) {
        Scanner sc =new Scanner(System.in);
        int test =sc.nextInt();
        for (int t=0;t<test;t++){
            int n =sc.nextInt();
            Queue<Integer> queue =new LinkedTransferQueue<>();
            for (int i=0;i<n;i++){
                queue.add(sc.nextInt());
            }
            int max=0;
            int stop=0;
            while (stop==0){
                int maxLocal= 0;
                int le=0;
                if (queue.size()%2==1) le=1;
                int size =queue.size()/2;
                for (int i=0;i<size;i++){
                    int data1 =queue.poll();
                    int data2=queue.poll();
                    maxLocal= (data1+data2)>maxLocal?(data1+data2):maxLocal;
                    queue.add(data1+data2);
                }
                if (le==1){
                   int leP=queue.poll();
                   queue.add(leP);
                }
                max=max+maxLocal;
                if (queue.size()==1){
                    stop=1;
                }

            }
            System.out.println(max);
        }
    }
}
