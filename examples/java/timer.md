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
