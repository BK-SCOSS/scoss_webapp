import java.util.*;
import java.lang.*;
import java.io.*;
import java.util.Arrays; 
import java.util.ArrayList; 
import java.util.Collections;
import java.util.List;
 
public class CAP {
    public static void main(String args[]) 
    { 
        Scanner scan =new Scanner(System.in);
        String s;
        int t;
        t = scan.nextInt();
          for (int i = 0; i< t; i++) {
              int sum = 0;
            int n = scan.nextInt();
            int[] arrn = new int[n];

            for (int j = 0; j< n; j++) {
                arrn[j] = scan.nextInt();
            }
            int m = scan.nextInt();
            for (int k = 0; k< m; k++) {
                int q = scan.nextInt();
                for (int j = 0; j< n; j++) {
                    if( arrn[j] == q) {
                        sum++;
                        break;
                    }
                }
            }
        System.out.println(sum);
        }
    } 
}