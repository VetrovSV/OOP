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

Пример для JavaFX
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
