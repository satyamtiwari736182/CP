import java.util.ArrayList;
import java.util.Iterator;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeMap;

class Card implements Comparable<Card> {
    private char symbol;
    private int number;

    public Card() {
    }

    public Card(char symbol, int number) {
        super();
        this.symbol = symbol;
        this.number = number;
    }

    public char getSymbol() {
        return symbol;
    }

    public void setSymbol(char symbol) {
        this.symbol = symbol;
    }

    public int getNumber() {
        return number;
    }

    public void setNumber(int number) {
        this.number = number;
    }

    @Override
    public String toString() {
        return "Card [symbol=" + symbol + ", number=" + number + "]";
    }

    @Override
    public int compareTo(Card o) {
        if (this.symbol < o.symbol)
            return -1;
        else if (this.symbol > o.symbol)
            return 1;
        else
            return 1;
    }
}

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Map<Character, ArrayList<Card>> map = new TreeMap<>();

        System.out.println("Enter Number of Cards :");
        int n = sc.nextInt();
        sc.nextLine();

        for (int i = 1; i <= n; i++) {
            System.out.println("Enter card " + i);
            char symbol = sc.nextLine().charAt(0);
            int number = sc.nextInt();

            Card card = new Card();
            card.setSymbol(symbol);
            card.setNumber(number);
            sc.nextLine();

            if (!map.containsKey(symbol)) {
                ArrayList<Card> list = new ArrayList<>();
                list.add(card);
                map.put(symbol, list);
            } else {
                ArrayList<Card> list = map.get(symbol);
                list.add(card);
            }
        }
        System.out.println("Distinct Symbols are :");

        Set<Entry<Character, ArrayList<Card>>> set = map.entrySet();
        Iterator<Entry<Character, ArrayList<Card>>> it = set.iterator();
        while (it.hasNext()) {
            System.out.print(it.next().getKey() + " ");
        }
        System.out.println();

        set = map.entrySet();
        it = set.iterator();

        while (it.hasNext()) {
            int sum = 0;
            Map.Entry<Character, ArrayList<Card>> me = it.next();
            ArrayList<Card> list = me.getValue();

            System.out.println("Cards in " + me.getKey() + " Symbol");

            for (Card card : list) {
                System.out.println(card.getSymbol() + " " + card.getNumber());
                sum += card.getNumber();
            }

            System.out.println("Number of cards : " + list.size());
            System.out.println("Sum of Numbers : " + sum);
        }

        sc.close();
    }

}