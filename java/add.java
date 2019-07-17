import java.util.Scanner;

public class Addition {

	public static Scanner scanner = new Scanner(System.in);

	public static void main(String[] args) {
		System.out.println("Choose which two numbers to add:");
		int a = scanner.nextInt();
		int b = scanner.nextInt();
		System.out.println(Add(a,b));
	}

	public static int Add(int a, int b) {
		return a + b;
	}
}
