/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


import java.util.Scanner;

/**
 *
 * @author HUY.NX183556
 */
public class ALICEADD {

   
    public static void main(String[] args) {
       
        Scanner in= new Scanner(System.in);
      
        int numberOfData= Integer.parseInt(in.nextLine());
        int result[]=   new int[numberOfData];
        for(int i=0;i<numberOfData;i++){

            int a= in.nextInt();
            int b= in.nextInt();
            result[i]=a+b;
            
        }
        for (int i=0;i<numberOfData;i++){
            System.out.println(result[i]);
        }
      
       
    }
    
}
