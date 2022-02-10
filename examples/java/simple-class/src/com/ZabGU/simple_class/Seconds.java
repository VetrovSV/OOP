package com.ZabGU.simple_class;


// todo: ...
public class Seconds {

    private int s;


    public Seconds(){
        s = 0; }

    public Seconds(int s1){
        setS(s1); }

    public int getS(){
        return this.s;}

    public void setS(int s1){
        if (s1 >= 60 || s1 < 0){
            throw new IllegalArgumentException("seconds must be in 0..59");
        }
        else {
            this.s = s1;
        }
    }

    // увеличивает число секунд на 1. учитывает переполнение
    public int tick(){
        this.s = (s + 1) % 60;
        return this.s;
    }

    // увеличивает число секунд на s1. учитывает переполнение
    public void add(int s1){
        if (s1 < 0){
            throw new IllegalArgumentException("argument must be 0 or positive");
        }
        this.s = (s + s1) % 60;
    }


    // Возвращает новый объект: увеличивает число секунд на s1. учитывает переполнение.
    public Seconds add(Seconds s1){
        return new Seconds(  (s + s1.s) % 60);
    }


    @Override
    public String toString() {
        return String.valueOf(this.s);
    }
}
