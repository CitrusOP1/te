import java.util.*;
public class rr {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int p;
        System.out.println("how many processes ");
        p = sc.nextInt();
        int r[] = new int[p];
        int count=0;
        for(int i=0;i<p;++i){
            count+=r[i]=sc.nextInt();
        }
        int qt ;
        int ft[] = new int[p];
        System.out.println("entr quantum time ");
        qt = sc.nextInt();
        int ct =  count/p;
        int ptr = 0;
        int mount=0;
        ct = p;
         while(true){
            if(ptr>=p){
                ptr = 0;
            }
            if(r[ptr]>qt){
                mount += qt;
                r[ptr]=r[ptr]-qt;
            }
            if(r[ptr]<=qt && r[ptr]>0){
                int c = r[ptr];
                mount+=c;
                r[ptr]=r[ptr]-c;
                ft[ptr]=mount;
                ct--;
            }
            ptr++;
            int f=0;
            for(int i=0;i<p;++i){
                if(r[i]!=0) f = 1;
            }
            if(f==0) break;
        }
        for(int i=0;i<p;++i){
            System.out.println(ft[i]);
        }
    }
}
