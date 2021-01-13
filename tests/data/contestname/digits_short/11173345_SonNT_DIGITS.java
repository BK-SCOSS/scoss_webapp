import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.Stack;
import java.util.concurrent.LinkedBlockingDeque;

public class DINO {
    public static void main(String[] args) {
        Scanner sc =new Scanner(System.in);
       int number= sc.nextInt();
        Stack<Integer> c =new Stack<Integer>();
        int[] a=new int[number];
        Queue<Integer> h =new LinkedList<>();
        for (int i=0;i<number;i++) {
            a[i]=sc.nextInt();
        }
        for (int i=number-1;i>=0;i--) {
          c.push(a[i]);
        }
        String dem= sc.next();
        char[] o=dem.toCharArray();
        for (char l:o){
            if (Character.toString(l).equals("H")&&!h.isEmpty()){
              Integer g =h.poll();
              c.push(g);

            }else if (Character.toString(l).equals("C")&&!c.isEmpty()){
                Integer g = c.pop();
                h.add(g);
            }
        }
        for (int i=number-1;i>=0;i--) {
            System.out.print(c.pop()+" ");
        }



    }
}
