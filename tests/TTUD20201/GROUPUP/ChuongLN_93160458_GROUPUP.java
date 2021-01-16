import java.util.*;
import java.lang.*;
import java.io.*;
import java.util.Arrays; 
import java.util.ArrayList; 
import java.util.Collections;
import java.util.List;
import java.lang.Math;

public class GROUPUP {
    public static int[] arr;
    public static int count = 1, n;
    public static void main(String args[]) 
    { 
        Scanner scan =new Scanner(System.in);
        String s;
        int t, m, sum = 0, mu = 0;
        t = scan.nextInt();
          for (int i = 0; i< t; i++) {
            n = scan.nextInt();
            
            arr = new int[n];
             for (int j = 0; j< n; j++) {
                arr[j] = scan.nextInt();
            }
            while (n != 1) {
                int arri = 0, sumC =0;
                if( n % 2  == 1 && n != 1 ) {
                    for (int j = 0; j< n - 1; j = j +2) {
                        arr[arri] = arr[j] + arr[j+1];
                        if(arr[arri] > sumC) {
                            sumC = (arr[arri]);
                        }                        
                        arri++;

                    }
                    arr[arri] = arr[n-1];
                    n = n/2 + 1;
                } else if (n% 2 ==0) {
                    for (int j = 0; j< n; j = j +2) {
                        arr[arri] = arr[j] + arr[j+1];
                    if(arr[arri] >= sumC) {
                            sumC = (arr[arri]);
                        }                        
                        arri++;
                    }
                    arr[arri] = 0;
                    n = n/2;
                }
                sum += sumC;
            }
            System.out.println(sum);
          }
    }
}