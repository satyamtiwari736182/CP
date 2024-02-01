import java.util.*;
import java.util.concurrent.locks.*;
public class SharedResources {
    int size;
    Queue<Integer> queue;
    SharedResources(int size){
        this.size = size;
        this.queue = new LinkedList<>();
    }
    synchronized public void produce(int i) throws Exception{
        while(queue.size()==size){
            System.out.println("Buffer is full producer is waiting...");
            wait();
        }
        queue.offer(i);
        System.out.println("Produced: "+i);
        notifyAll();
        // Thread.currentThread().sleep(1000);
    }
    synchronized public void consume()throws Exception{
        while(queue.isEmpty()){
            System.out.println("Buffer is empty Consumer is waiting...");
            wait();
        }
        int item=queue.poll();
        System.out.println("Consumed: "+item+"  "+Thread.currentThread().getName());
        notifyAll();
    }
}
