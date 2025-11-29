import java.util.Collections;
import java.util.List;

public class practice {
    public static void main(String[] args) {
        List<Integer> lst = List.of(1, 2, 2, 3, 3, 3, 5, 7, 9);
        int idx = Collections.binarySearch(lst, 3);
        System.out.println(idx);
    }
}
