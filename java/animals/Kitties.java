import animals.*;

public class Kitties {

    public static void main(String[] args) {
        System.out.println("Kitties!");

	animals.Cat cat = new animals.Cat();
	cat.age = 412;
	System.out.println(cat.age);
    }
}
