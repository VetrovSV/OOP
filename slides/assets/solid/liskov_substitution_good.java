abstract class Bird {
    public void eat() {
        System.out.println("Bird is eating");
    }
}

interface Flyable {
    void fly();
}

class Sparrow extends Bird implements Flyable {
    @Override
    public void fly() {
        System.out.println("Sparrow is flying");
    }
}

class Penguin extends Bird {
    public void swim() {
        System.out.println("Penguin is swimming");
    }
}

class FlyingService {
    public void makeFly(Flyable bird) {
        bird.fly();
    }
}

public class Main {
    public static void main(String[] args) {
        FlyingService service = new FlyingService();

        service.makeFly(new Sparrow()); // ok
        // service.makeFly(new Penguin()); // так уже и не должно компилироваться
    }
}
