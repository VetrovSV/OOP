package com.example.database_tableview_observablelist;

/** Хранит данные о результатах студента по дисциплине.
 * Используется для отображения в таблице TableView
 * */
public class Student {

    private String name;    /** ФИО */
    private Double score_t1;   /** оценка за задание 1 */
    private Double score_t2;   /** оценка за задание 2 */
    private Double score_t3;   /** оценка за задание 3 */
    private Byte exam;      /** оценка за экзамен */

    public Student() {
    }

    public Student(String name, Double score1, Double score2, Double score3, Byte exam) {
        this.name = name;
        setScore_t1(score1);
        setScore_t2(score2);
        setScore_t3(score3);
        this.exam = exam;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public Double getScore_t1() {
        return score_t1;
    }

    public void setScore_t1(Double score) {
        if (score > 0)
            this.score_t1 = score;
        else throw new IllegalArgumentException("Must be greater than zero");
    }

    public Double getScore_t2() {
        return score_t2;
    }

    public void setScore_t2(Double score) {
        if (score > 0)
            this.score_t2 = score;
        else throw new IllegalArgumentException("Must be greater than zero");
    }

    public Double getScore_t3() {
        return score_t3;
    }

    public void setScore_t3(Double score) {
        if (score > 0)
            this.score_t3 = score;
        else throw new IllegalArgumentException("Must be greater than zero");
    }

    public Byte getExam() {
        return exam;
    }

    public void setExam(Byte exam) {
        this.exam = exam;
    }


}
