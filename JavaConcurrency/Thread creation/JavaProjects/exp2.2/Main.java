import java.util.*;

class Card implements Comparable<Card> {
	private char symbol;
	private int number;
	
	public Card() {}
	
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
		if (this.symbol < o.symbol) return -1;
		else if (this.symbol > o.symbol) return 1;
		else return 1;
	}
	
	@Override
	public int hashCode() {
        return String.valueOf(symbol).hashCode();
	}
	
	@Override
    public boolean equals(Object obj){
        if (obj instanceof Card) {
        	Card card = (Card) obj;
            return (card.symbol == this.symbol);
        } else {
            return false;
        }
    }
}

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Set<Card> set = new HashSet<>();
		
		for (int i = 0; i < 8; i++) {
			System.out.println("Enter a card:");
			Card card = new Card();
			
			card.setSymbol(sc.nextLine().charAt(0));
			card.setNumber(sc.nextInt());
			sc.nextLine();
			
			set.add(card);
		}
		System.out.println("Four symbols gathered in eight cards.");
		System.out.println("Cards in Set are:");
		
		
		for (Card card : set) 
			System.out.println(card.getSymbol() + " " + card.getNumber());		
		
		sc.close();
	}

}