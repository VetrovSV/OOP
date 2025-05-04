# Таймер
Таймер выполняет метод run класса TimerTask с заданной задержкой `timer.schedule(.. , задержка_в_мс)` или  периодом и задержкой `Timer.schedule(.. , задержка_в_мс, период_в_мс)`

Метод выполняется в отдельном потоке

```Java
Timer timer = new Timer();


timer.schedule(new TimerTask() {
            @Override
            public void run() {
                System.out.println("Таймер работает в отдельном потоке: " + Thread.currentThread().getName());
            }
        }, 0,2000);
    }


// Остановка таймера и его потока
public void close(){
        timer.cancel();
        timer.purge();
}


// привязка метода JavaFX контроллера к событию закрытия окна
HelloController controller = fxmlLoader.getController();
stage.setOnHidden(e -> controller.close());

```

### JavaFX

**Использование Timer**
```java
// объект, содержащий код, который нужно выполнять по таймеру
TimerTask timer_task = new TimerTask() 
      // создание анонимного наследника от TimerTask, переопределение метода run
      {
      @Override
      public void run() {
          // для обращения к элементу интерфейса требуется выполнять код в главном потоке выполнения
          // Поэтому поместим код в очередь обработки событий
          Platform.runLater( () -> {
              // это тоже создание анонимного класса, только реализующего интерфейс Runnable
              // для примера будем отображать текущее время
              LocalDateTime currentDateTime = LocalDateTime.now();
              welcomeText.setText(currentDateTime.toString());          });
      }
  };


timer = new Timer();

timer.schedule(timer_task, 0, 5000);
```


**Использование javafx.animation.Timeline**
```java
import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.util.Duration;
import java.time.LocalDateTime;

Timeline timeline = new Timeline(
    // В этом коде KeyFrame задаёт действие (лямбда с аргументом event), которое будет выполняться каждые 5 секунд
    new KeyFrame(Duration.seconds(5), event -> {
        LocalDateTime currentDateTime = LocalDateTime.now();
        welcomeText.setText(currentDateTime.toString());
    })
);

// код должен вызываться бесконечно, с указанным выше интервалом
timeline.setCycleCount(Timeline.INDEFINITE);

// запуск таймера
timeline.play();
```
