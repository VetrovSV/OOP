abstract class Bird {
    public abstract void fly();
}

class Sparrow extends Bird {
    @Override
    public void fly() {
        System.out.println("Sparrow is flying");
    }
}

class Penguin extends Bird {
    @Override
    public void fly() {
        throw new UnsupportedOperationException("Penguins cannot fly");
    }
}

class BirdService {
    public void makeBirdFly(Bird bird) {
        bird.fly();
    }
}

public class Main {
    public static void main(String[] args) {
        BirdService service = new BirdService();

        service.makeBirdFly(new Sparrow()); // ok
        service.makeBirdFly(new Penguin());  // ошибка
    }
}