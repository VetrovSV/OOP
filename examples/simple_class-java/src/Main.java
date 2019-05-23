// модуль Seconds уже подключен

public class Main {

    public static void main(String[] args) {
        System.out.println("Hello World!");

        Seconds s = new Seconds();  // создание объектов только чере оператор new
        s.setS(55);

        Seconds s1 = new Seconds(20);

        s.tick();
        System.out.println("s: " + s.toString());

        s1.add(59);
        System.out.println("s1: " + s1.toString());

        Seconds s2 = s1.add( s );

        System.out.println("s2: " + s2.toString());
    }
}
