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

// TimerTask — это абстрактный класс, а не интерфейс, поэтому он не является функциональным интерфейсом, и лямбда к нему не приводится.

// Остановка таймера и его потока
public void close(){
        timer.cancel();
        timer.purge();
}


// привязка метода JavaFX контроллера к событию закрытия окна
HelloController controller = fxmlLoader.getController();
stage.setOnHidden(e -> controller.close());
```


Класс **ScheduledExecutorService** - планировщик - более современное средство для отложенного или периодического запуска задач.

Экземпляр этого класса созадётся с помошью фабричного метода `newSingleThreadScheduledExecutor()`.

Задачи представленны функциональным интерфейсом `Runnable`.

Для запуска задач могт использоваться методы:
```java
// Запуск после задержки delay, unit - единицы измерения delay (например TimeUnit.SECONDS)
ScheduledFuture<?> schedule(Runnable command, long delay, TimeUnit unit);


// Фиксированный интервал между запусками по расписанию
ScheduledFuture<?> scheduleAtFixedRate(Runnable command,
                                       long initialDelay,
                                       long period,
                                       TimeUnit unit);

// Фиксированная задержка «между» окончаниями
ScheduledFuture<?> scheduleWithFixedDelay(Runnable command,
                                          long initialDelay,
                                          long delay,
                                          TimeUnit unit);
```
Через класс `ScheduledFuture` можно управлять задачей, например отменить `cancel()`.

Планировщиком **ScheduledExecutorService** можно управлять через методы:
- `shutdown()` / `shutdownNow()` — плавно или принудительно остановить планировщик.
- `awaitTermination(...)` —  ждать завершения.


Пример
```java
// создать планировщик
ScheduledExecutorService exec =
    Executors.newSingleThreadScheduledExecutor();
// добавить задачу (представлена лямбдой),
exec.scheduleAtFixedRate(
    () -> System.out.println("Каждые 10 сек: " + LocalTime.now()),
    0,          // задержка первого выполнения
    10,         // интервал повторения
    TimeUnit.SECONDS        // единицы измерения времени (параметр 2 и 3)
);
// ... позже
exec.shutdown();
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
