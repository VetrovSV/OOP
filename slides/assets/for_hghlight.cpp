class Manager {
    private IWorker worker;   // зависимость от абстракции

    public Manager() {
        worker = createWorker();   // создание внутри, не DI
    }

    protected IWorker createWorker() {
        return new Worker("default");
    }

    public void manage() {
        worker.work();
    }
}