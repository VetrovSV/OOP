#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
// Кроме заголовочных файлов нужно подключить соответствующие скомпилированые библиотеки
// см. pro файл, раздел LIBS
// glut в системе может и отсутствовать, придётся устанавливать отдельно

using namespace std;


void draw_triangle(){
    glColor3f(0, 0.184, 0.655); // International Klein Blue
    // Начало рисования многоугольника (GL_POLYGON)
    glBegin(GL_POLYGON);
    // Расставляем точки (вертексы), которые должны образовать треугольник
    glVertex2d(-0.5, -0.5); // 2d означает не что координаты задаются двумя вещественными (double) числами
    glVertex2d(0, 0.6);
    glVertex2d(0.5, -0.5);
    glEnd();
}


// Функция рисования каждого кадра
void draw_main(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  // Очитска экрана

//    draw_triangle();

    glColor3f(0, 0.184, 0.655);
    glutSolidTeapot(0.5);

    // Рисование происходит не сразу на экран, а в экранный буфер
    // ( см. параметр GLUT_DOUBLE в glutInitDisplayMode ),
    // а затем копируется из экранного буфера на экран функцией glutSwapBuffers
    glutSwapBuffers();
}



int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Example1");

    glutDisplayFunc(draw_main);  // задаётся функция рисования каждого кадра
    glutMainLoop();         // запуск главного цикла приложения (запуск функции отрисовки каждого кадра)

    return 0;
}
