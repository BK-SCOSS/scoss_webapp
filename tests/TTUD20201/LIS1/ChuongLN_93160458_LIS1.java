import java.util.*;
import java.lang.*;
import java.io.*;
import java.util.Arrays; 
import java.util.ArrayList; 
import java.util.Collections;
import java.util.List;
 
public class LIS1 {
    public static int[] arr;
    public static int count = 1, n;
    public static void solve(int k) {
        int checkCount = 1;
        int m = arr[k];

      for (int i = k+1; i< n; i++) {


          if (arr[i] == m+1) {
              m++;
              checkCount++;
              if(checkCount > count) {
                  count = checkCount;
              }
          }
        }
    }
    public static void main(String args[]) 
    { 
        Scanner scan =new Scanner(System.in);
        String s;
        int t;
        t = scan.nextInt();
          for (int i = 0; i< t; i++) {
            n = scan.nextInt();
            arr = new int[n];
            for (int j = 0; j< n; j++) {
                arr[j] = scan.nextInt();
            }
            int m = arr[0];
            for (int j = 0; j< n; j++) {
                if (arr[j] != m+1) {
                    m = arr[j];
                    solve(j);
                } else {
                    m++;
                }
            }
            System.out.println(count);
          }
          
      
    }
}