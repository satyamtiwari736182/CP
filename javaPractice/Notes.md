```java
interface ISample {

    final String name = "ISample Interface";
    public String str = "Satyam";

    public static void show() {
        System.out.println("i am Isample static in nature");
    }

    public default void show23() {
        System.out.println("i am Isample default in nature");
    }

    public String show2(String str);

}

class Sample {
    public String show3(String str) {
        return "I am Sample Class show2 method" + " with str: " + str;
    }

    public static String show4(String str) {
        return "I am Sample Class show4 static method" + " with str: " + str;
    }
}

public class InnerISample implements ISample {

    public String show2(String str) {
        // ISample.str = str; // This will not compile, as 'str' is final in the
        // interface
        return "I am InnerISample show2 method" + " with str: " + str;
    }

    public static void main(String[] args) {
        InnerISample obj = new InnerISample();
        System.out.println(obj.show2("Hello, World!"));
        ISample.show();
        obj.show23();
        System.out.println("Name: " + ISample.name);

        Sample sampleObj = new Sample();
        ISample iSample = sampleObj::show3; // Method reference to Sample's show2 method
        ISample iSample2 = Sample::show4; // Static Method reference
        System.out.println(iSample.show2("Hello from ISample!"));
        System.out.println(iSample2.show2("Hello from ISample!"));
    }

}
```

```java
public class sam {
    private static String show() {
        char str[] = "Hellow world".toCharArray();
        String str2=new StringBuilder().append(str).append('#').toString();
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
```

```java
class Employee implements Comparable<Employee> {
    private String name;
    private int id;
    private boolean isActive;

    public Employee(String name, int id, boolean isActive) {
        this.name = name;
        this.id = id;
        this.isActive = isActive;
    }

    public String getName() {
        return name;
    }

    public int getId() {
        return id;
    }

    public boolean isActive() {
        return isActive;
    }

    @Override
    public String toString() {
        return "Employee{id=" + id + ", name='" + name + "', active=" + isActive + "}";
    }

    @Override
    public int compareTo(Employee emp2) {
        int activeCompare = Boolean.compare(emp2.isActive(), this.isActive());
        if (activeCompare != 0)
            return activeCompare;

        // Then apply different comparison based on active status
        if (this.isActive()) {
            // For active employees: compare by name
            return emp2.getName().compareTo(this.getName()); // Descending
        } else {
            // For inactive employees: compare by ID (reversed)
            return Integer.compare(emp2.getId(), this.getId());
        }
    }
}

class Cmpr implements Comparator<Employee> {
    @Override
    public int compare(Employee emp1, Employee emp2) {
        int activeCompare = Boolean.compare(emp2.isActive(), emp1.isActive());
        if (activeCompare != 0)
            return activeCompare;

        // Then apply different comparison based on active status
        if (emp1.isActive()) {
            // For active employees: compare by name
            return emp2.getName().compareTo(emp1.getName()); // Descending
        } else {
            // For inactive employees: compare by ID (reversed)
            return Integer.compare(emp2.getId(), emp1.getId());
        }
    }

}

public class Main{

    public static void main(String []args){
        List<Employee> employees = new ArrayList<>(List.of(
                new Employee("John", 101, false),
                new Employee("Alice", 102, true),
                new Employee("Bob", 103, true),
                new Employee("Zoe", 104, false),
                new Employee("Mike", 105, true)));

        // Sort by isActive (true first) and then by name in descending order
        List<Employee> sortedEmployees = employees.stream()
                .sorted(Comparator
                        .comparing(Employee::isActive).reversed() // Active first (true comes before false)
                        .thenComparing(Comparator.comparing(Employee::getName).reversed()) // Name descending
                )
                .collect(Collectors.toList());

        sortedEmployees.forEach(System.out::println);
        Comparator<Employee> comparator = new Comparator<Employee>() {
            @Override
            public int compare(Employee emp1, Employee emp2) {
                // First compare by active status
                int activeCompare = Boolean.compare(emp2.isActive(), emp1.isActive());
                if (activeCompare != 0)
                    return activeCompare;

                // Then apply different comparison based on active status
                if (emp1.isActive()) {
                    // For active employees: compare by name
                    return emp2.getName().compareTo(emp1.getName()); // Descending
                } else {
                    // For inactive employees: compare by ID (reversed)
                    return Integer.compare(emp2.getId(), emp1.getId());
                }
            }
        };
        System.out.println("\n\n");
        employees.sort(comparator);
        employees.forEach(System.out::println);
        System.out.println("\n\n");
        employees.add(new Employee("Alice", 106, true));
        employees.add(new Employee("Zoe", 107, false));

        employees.sort(new Cmpr());

        employees.sort((emp1, emp2) -> {
            // First compare by active status
            int activeCompare = Boolean.compare(emp2.isActive(), emp1.isActive());
            if (activeCompare != 0)
                return activeCompare;

            // Then apply different comparison based on active status
            if (emp1.isActive()) {
                // For active employees: compare by name
                return emp2.getName().compareTo(emp1.getName()); // Descending
            } else {
                // For inactive employees: compare by ID (reversed)
                return Integer.compare(emp2.getId(), emp1.getId());
            }
        });

        employees.forEach(System.out::println);
    }
}
```
```md
    
    Stream operations are divided into intermediate and terminal operations:

Intermediate Operations (return a new stream)

    filter(Predicate): excludes elements that don't match

    map(Function): transforms elements

    flatMap(Function): flattens nested structures

    distinct(): removes duplicates

    sorted(): orders elements

    peek(Consumer): performs action without modifying

Terminal Operations (produce a result or side-effect)
    
    forEach(Consumer): performs action on each element

    collect(Collector): accumulates elements into a collection

    reduce(): combines elements into a single result

    count(): returns number of elements

    anyMatch()/allMatch()/noneMatch(): boolean checks

    findFirst()/findAny(): get elements

Utility Class: Collectors 

    Collectors.toMap(key,value)

    Collectors.toList(item)

    Collectors.toSet(item)
    
    Collectors.max()
```
```
Java Streams themselves are immutable. Every intermediate operation (like filter(), map()) returns a new stream rather than modifying the original one.
```

```java
import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.Stream;
import java.util.stream.Collectors;

public class Sample7 {

    // Recursive flattening method
    private static Stream<?> flattenObject(Object o) {
        if (o instanceof List<?> list) {
            return list.stream().flatMap(Sample7::flattenObject);
        } else if (o instanceof int[] array) {

            // Arrays.stream(array) -> When applied to a primitive array like int[], this
            // creates an IntStream (a specialized stream for int primitives)

            // .boxed() -> Converts the primitive stream (IntStream, LongStream,
            // DoubleStream)to a Stream of wrapper objects

            return Arrays.stream(array).boxed();
        } else if (o instanceof Object[] array) {
            return Arrays.stream(array).flatMap(Sample7::flattenObject);
        }
        return Stream.of(o);
    }

    public static void main(String[] args) {

        List<String> names = Arrays.asList("John", "Alice", "Bob", "Anna"); // immutable
        List<String> result = names.stream()
                .filter(name -> name.startsWith("A"))
                .map(String::toUpperCase)
                .collect(Collectors.toList());

        List<Integer> lst = new ArrayList<>(List.of(10, 20, 30, 40, 20, 10, 30, 50)); // mutable
        lst.add(60);
        List<String> lst2 = lst.stream().map(String::valueOf)
                .collect(Collectors.toList()); // lst2 -> mutable
        lst2.add("70");
        for (int i = 0; i < lst2.size(); i++)
            System.out.print(lst2.get(i) + ", ");

        Object[] arr = { 1, "rahul", new int[] { 3, 4 }, "satyam", 6, List.of(7, new int[] { 8, 9, 10 }, 11, 12), 13,
                14, 15 };

        List<?> lst3 = Arrays.stream(arr)
                .flatMap(o -> {
                    if (o instanceof List) {
                        return ((List<?>) o).stream();
                    } else if (o instanceof int[]) {
                        return Arrays.stream((int[]) o).boxed();
                    } else if (o instanceof Stream) {
                        return (Stream<?>) o;
                    } else {
                        return Stream.of(o);
                    }
                })
                .toList();

        List<?> lst4 = Arrays.stream(arr)
                .flatMap(o -> flattenObject(o))
                .toList();

        System.out.println("\n");
        for (var ob : arr)
            System.out.print(ob + ", ");

        System.out.println("\n\nAfter processing:\n");
        for (var ob : lst4)
            System.out.print(ob + ", ");

        System.out.println();

        Optional<String> optionalString = Optional.of("Hello, World!"); // Optional containing a single value or null
                                                                        // and no multiple values

        Optional<List<String>> optional = Optional.of(List.of("10", "20", "30", "40", "50", "60", "70", "80"));
        optional.stream()
                .flatMap(List::stream)
                .map(Integer::parseInt)
                .forEach(i -> System.out.print(i * 2 + ", "));
        System.out.println();
        lst.stream().collect(Collectors.toSet()).stream().collect(Collectors.toMap(
                i -> i, // key mapper
                i -> i * 2 // value mapper
        )).forEach((k, v) -> System.out.println(k + "->" + v + ", "));

        lst.stream().collect(Collectors.toSet())
                .forEach(i -> System.out.print(i + ", "));
        System.out.println();

        
    }
}
```