import java.util.concurrent.Semaphore;
public class rwp {
    
    static Semaphore readLock = new Semaphore(1);
    static Semaphore writeLock = new Semaphore(1);
    static int readcount =0;
    static class read implements Runnable{
        public void run(){
            try {
                readLock.acquire();
                readcount++;
                if(readcount==1){
                    writeLock.acquire();
                }
                readLock.release();
                // read section 
                System.out.println("thread "+Thread.currentThread().getName()+" reading");
                Thread.sleep(3000);

                // release sectiojn
                readLock.acquire();
                readcount--;
                if(readcount==0){
                    writeLock.release();
                }
                readLock.release();

            } catch (Exception e) {
                // TODO: handle exception
            }
        }
    }
    static class write implements Runnable{
        public void run(){
            try {
                writeLock.acquire();
                System.out.println("thread "+Thread.currentThread().getName()+" is writing");
                Thread.sleep(3000);
                writeLock.release();
            } catch (Exception e) {
                // TODO: handle exception
            }
        }
    }
    public static void main(String[] args) {
        read r = new read();
        write w = new write();
        Thread t1 = new Thread(r);
        Thread t2 = new Thread(r);
        Thread t3 = new Thread(r);
        Thread t4 = new Thread(w);
        t1.setName("abhay");
        t2.setName("yash");
        t3.setName("abhishek");
        t4.setName("akash");
        t1.start();
        t2.start();
        t4.start();
        t3.start();
    }
}
