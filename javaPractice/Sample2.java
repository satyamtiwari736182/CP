import java.util.*;
import java.util.concurrent.locks.*;

class InnerClass{
    Lock lock = new ReentrantLock();

    int counter=0;
    void solve(){
        // synchronized(this){
            for(int i=0;i<100;i++){
                lock.lock();
                if("Thread-0".equals(Thread.currentThread().getName())||"Thread-2".equals(Thread.currentThread().getName()))counter++;
                if("Thread-1".equals(Thread.currentThread().getName()))counter--;
                if("Thread-2".equals(Thread.currentThread().getName()))
                    try {
                        Thread.currentThread().sleep(100);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
            System.out.println(Thread.currentThread().getName()+" "+counter);
            lock.unlock();
            // }
        }
    }
}
public class Sample2 {
    public static void main(String[] args)  {

        
        
        //! =========================================================
        // SharedResources resources = new SharedResources(5);
        // Thread producerThread=new Thread(()->{
        //     try {
        //         for (int i=0; i<40;i++) {
        //             resources.produce(i);
        //         }
        //     } catch (Exception e) {
        //         System.out.println(e);
        //     }
        // });
        // Thread consumerThread=new Thread(()->{
        //     try {
        //         for (int i=0; i<20;i++) {
        //             resources.consume();
        //         }
        //     } catch (Exception e) {
        //         System.out.println(e);
        //     }
        // });
        // Thread consumerThread2=new Thread(()->{
        //     try {
        //         for (int i=0; i<20;i++) {
        //             resources.consume();
        //         }
        //     } catch (Exception e) {
        //         System.out.println(e);
        //     }
        // });
        // producerThread.start();
        // consumerThread.start();
        // consumerThread2.start();
        
        //! =========================================================
        
        InnerClass innerClass1 = new InnerClass();
        InnerClass innerClass2 = new InnerClass();
        Thread t1=new Thread(innerClass1::solve);
        Thread t2=new Thread(innerClass1::solve);
        t1.start();
        t2.start();
        
        System.out.println("=========================================================");
        
        Thread t3=new Thread(innerClass1::solve);
        t3.start();
        try {
                // Thread.currentThread().sleep(15000);
                t1.join();
                t2.join();
                t3.join();
            } catch (Exception e) {
                    e.printStackTrace();
                }
                finally{
                        System.out.println("Fianlly Counter: "+innerClass1.counter+"............................");
                    }
                    
                    System.out.println("Fianlly Counter: "+innerClass1.counter+"--------------------------------");
                    
                    
    }
}

// NOTE:
    // MonitorLock is intrisically applied to synchronized method/block
    // Also lock are applied on the instance of the SharedResources.
    // And lock are applied also on the class level for static funcion of the SharedResources.
    // t1.join() makes the main thread to wait till t1 is done after that main thread starts it's own execution.