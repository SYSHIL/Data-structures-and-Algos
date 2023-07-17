import java.util.PriorityQueue;
import java.util.Queue;

public class Main {
    public static void main(String[] args){
        // FIFO DATA STRUCTURE
        // HOWEVER WHEN WE POLL WE OFFER THE ELEMENTS WITH HIGHER PRIORITY
        Queue<Double> queue = new PriorityQueue<>();
        queue.offer(9.68);
        queue.offer(8.0);
        queue.offer(9.2);
        queue.offer(2.0);

        while(!queue.isEmpty()){
            System.out.println(queue.poll());
        }
    }
}
