/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.util.Scanner;


public class CNTDIV {

    
    public static void main(String[] args) {
        int n,count=0;
        long t;
        Scanner in= new Scanner(System.in);
        int numberOfData= Integer.parseInt(in.nextLine());
        int result[]= new int[numberOfData];
        for (int i=0;i<numberOfData;i++){
             n= Integer.parseInt(in.nextLine());
             t=n*(n+1)*(n+2);
             
             for (int j=2;j<t;j++){
                if ((t*t%j==0) && (t%j!=0)){
                    count++;
                    
                }
              result[i]=count;
             }
        }
        for (int i=0;i<numberOfData;i++){
            System.out.println(result[i]);
        }
        
        
    }
    
}
