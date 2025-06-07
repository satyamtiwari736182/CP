import java.util.ArrayList;
import java.util.Deque;
import java.util.LinkedHashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Set;
import java.util.Stack;
import java.util.TreeMap;

public class sam {
    private static String show() {
        char str[] = "Hellow world".toCharArray();
        // return new StringBuilder().append(str).append('#').toString();
        return new String(str);
    }

    public static void main(String[] args) {
        System.out.println(show());
        List<String> list = new LinkedList<>();
        list.add("Hello");
        list.add("World");
        list.add("Java");
        list.add("Programming");
        for (int i = 0; i < list.size(); i++) {
            System.out.print(list.get(i) + ", ");
        }

        System.out.println();
        Deque<String> queue = new LinkedList<>();
        queue.add("First");
        queue.add("Second");
        queue.add("Third");
        queue.addFirst("Hello ji");
        queue.addLast("World ji");
        queue.removeFirst();
        queue.removeLast();

        while (!queue.isEmpty()) {
            System.out.print(queue.poll() + ", ");
        }

        Queue<int[]> que = new PriorityQueue<>((a, b) -> Integer.compare(a[0], b[0]));
        Stack<Integer> stack = new Stack<>();
        Set<Integer> set = Set.of(1, 2, 3, 4, 5);
        Set<Integer> set2 = new LinkedHashSet<>();
        Map<Integer, String> map2 = new TreeMap<>();

        System.out.println();
        Map<String, Integer> map = Map.of("One", 1, "Two", 2, "Three", 3);
        for (Map.Entry<String, Integer> entry : map.entrySet()) {
            System.out.println(entry.getKey() + " = " + entry.getValue());
        }
        System.out.println("================================");
        for (String key : map.keySet()) {
            System.out.println(key + " = " + map.get(key));
        }
        System.out.println("================================");
        List<Integer> graph[] = new ArrayList[4];
        for (int i = 0; i < graph.length; i++) {
            graph[i] = new ArrayList<>();
        }

        graph[0].add(1);
        graph[0].add(2);
        graph[1].add(2);
        graph[2].add(0);
        graph[2].add(3);
        graph[3].add(3);
        for (int i = 0; i < graph.length; i++) {
            System.out.print(i + " -> ");
            for (int j = 0; j < graph[i].size(); j++) {
                System.out.print(graph[i].get(j) + " ");
            }
            System.out.println();
        }
        System.out.println("================================");

    }
}