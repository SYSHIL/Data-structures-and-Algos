import java.lang.reflect.Array;
import java.util.ArrayList;

// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
public class Main {
    public static void main(String[] args) {
        PriorityQueue pq = new PriorityQueue();
        pq.add(10);
        pq.add(20);
        pq.add(30);
        pq.add(40);
        pq.add(5);
        System.out.println(pq.peek());
        System.out.println(pq.poll());
        System.out.println(pq.poll());

    }
}