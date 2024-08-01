import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.RejectedExecutionHandler;
import java.util.concurrent.ThreadFactory;
import java.util.concurrent.ThreadPoolExecutor;
import java.util.concurrent.TimeUnit;

class CustomThreadFactory implements ThreadFactory {

    @Override
    public Thread newThread(Runnable r) {
        return new Thread(r);
    }
}
class CustomRejectedHandler implements RejectedExecutionHandler{

    @Override
    public void rejectedExecution(Runnable r, ThreadPoolExecutor executor) {
        System.out.println("Task denied: "+ r.toString());
    }
    
}
public class Sample4 {
    public static void main(String[] args) {
        ThreadPoolExecutor poolExecutor=new ThreadPoolExecutor(2, 5, 1, TimeUnit.HOURS, new ArrayBlockingQueue<>(10),new CustomThreadFactory(),new CustomRejectedHandler());
        poolExecutor.allowCoreThreadTimeOut(true);
        // submit task
        for(int i=0;i<25;i++) poolExecutor.submit(()->{
            try{
                Thread.sleep(5000);
                System.out.println("Thread Name: "+ Thread.currentThread().getName());
            }
            catch(Exception e){
                e.printStackTrace();
            }
        });
        poolExecutor.shutdown();
    }
}
