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
```
```
Java Streams themselves are immutable. Every intermediate operation (like filter(), map()) returns a new stream rather than modifying the original one.
```

```java
import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.Stream;

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

        List<Integer> lst = new ArrayList<>(List.of(10, 20, 30, 40, 50)); // mutable
        lst.add(60);
        List<String> lst2 = lst.stream().map(String::valueOf)
                .collect(Collectors.toList()); // lst2 -> mutable
        lst2.add("70");
        for (int i = 0; i < lst2.size(); i++)
            System.out.print(lst2.get(i) + ", ");

        Object[] arr = { 1, "rahul", new int[] { 3, 4 }, "satyam", 6, List.of(7, new int[] { 8, 9, 10 }, 11, 12), 13,
                14, 15 };

        // List<?> lst3 = Arrays.stream(arr)
        // .flatMap(o -> {
        // if (o instanceof List) {
        // return ((List<?>) o).stream();
        // } else if (o instanceof int[]) {
        // return Arrays.stream((int[]) o).boxed();
        // } else if (o instanceof Stream) {
        // return (Stream<?>) o;
        // } else {
        // return Stream.of(o);
        // }
        // })
        // .toList();

        List<?> lst3 = Arrays.stream(arr)
                .flatMap(o -> flattenObject(o))
                .toList();

        System.out.println("\n");
        for (var ob : arr)
            System.out.print(ob + ", ");

        System.out.println("\n\nAfter processing:\n");
        for (var ob : lst3)
            System.out.print(ob + ", ");

    }
}

```