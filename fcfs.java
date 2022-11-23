import java.util.Map;
import java.util.Scanner;
public class fcfs {
    public static void main(String[] args) {
        int p;
        System.out.println("processes ");
        Scanner sc = new Scanner(System.in);
        p = sc.nextInt();
        System.out.println("at\t");
        int at[] = new int[p];
        int bt[]=new int[p];
        int ct[]=new int[p];
        int tat[]=new int[p];
        int wt[]=new int[p];
        for(int i=0;i<p;++i){
            at[i]=sc.nextInt();
            bt[i]=sc.nextInt();
        }
        for(int i=0;i<p;++i){
            if(i==0){
                ct[i]=bt[i];
            }else{
                if(at[i]<=ct[i-1]){
                    ct[i]=ct[i-1]+bt[i];
                }else{
                    ct[i]=at[i]+bt[i];
                }
            }

        }
        for(int i=0;i<p;++i){
            System.out.println(ct[i]);
        }
    }
}
