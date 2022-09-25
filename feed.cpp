import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;
public class aIII {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int m;
        int n;
        System.out.println("Procedure :");
        n = sc.nextInt();
        System.out.println("No. of mmry Locations ");
        m = sc.nextInt();
        String proc[] = new String[n];
        Integer procmmry[] = new Integer[n];
        Integer mmry[] = new Integer[m];
        Integer visited[] = new Integer[m]; 
        System.out.println("Enter procedure ");
        for(int i=0;i<n;++i){
            System.out.println("proc "+i+1+" ");
            System.out.println("memory for "+"p"+i+1+" ");
            procmmry[i] = sc.nextInt();
            proc[i]="p"+i+1;
        }
        System.out.println("enter memory ");
        for(int i=0;i<m;++i){
            mmry[i] = sc.nextInt();
            visited[i]=null;
        }
        System.out.println("Enter mmry Available ");
         
        getBestfeed(proc,procmmry,mmry,visited,n,m);
        getfirstfeed(proc,procmmry,mmry,visited,n,m);
        getworstfeed(proc,procmmry,mmry,visited,n,m);
    }
    public static void getBestfeed(String proc[],Integer procmmry[],Integer mmry[],Integer visited[],int n,int m){
        Integer alloc[]=new Integer[4];
        for(int i=0;i<n;++i){
            int best = -1;
            for(int j=0;j<m;++j){
                if(visited[j]!=1){
                    if(procmmry[i]<=mmry[j]){
                        best = j;
                    }else if(procmmry[j]<=mmry[j]){
                        best = j;
                    }
                }
            }
            if(best !=-1){
                visited[i] = 1;
                alloc[i]=best;
            }
        }
        System.out.println("\n");
        System.out.println("Best Feed ");
        for(int i=0;i<n;++i){
            System.out.println("proc :"+proc[i]+"mmry :"+alloc[i]);
        } 
    }
    public static void getfirstfeed(String proc[],Integer procmmry[],Integer mmry[],Integer visited[],int n,int m){
        Integer alloc[]= new Integer[n];
        for(int i=0;i<n;++i){
            for(int j=0;j<=m;++j){
                if(visited[j]!=1){
                    if(procmmry[i]<=mmry[j]){
                        alloc[i]=mmry[j];
                        visited[j]=1;
                    }
                }
            }
        }
        for(int i=0;i<=)
    }
}
