import java.util.*;

public class DINO {

    public static void main(String[] args) {
        int n,temp;
        Stack<Integer> chuong = new Stack<Integer>();
        String s;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        List<Integer> s1 = new ArrayList<>();
        for(int i=0;i<n;i++){
            temp = sc.nextInt();
            s1.add(temp);
        }
        for(int i=n-1;i>=0;i--){
            chuong.push(s1.get(i));
        }
        sc.nextLine();
        s = sc.nextLine();



        Queue<Integer> hanhlang = new LinkedList<>();
        for(int i =0;i<s.length();i++){
            if(String.valueOf(s.charAt(i)).equals("C")){

                hanhlang.add(chuong.peek());
                chuong.pop();
            }
            else if(String.valueOf(s.charAt(i)).equals("H")){
                chuong.push(hanhlang.peek());
                hanhlang.poll();
            }
        }
        for(int i=n-1;i>=0;i--){
            System.out.print(chuong.get(i)+" ");
        }
    }
}