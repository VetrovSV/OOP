#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include <unistd.h>

using namespace std;


void draw_xyz(){
    glLineWidth(2);

    glBegin(GL_LINES);
    //x
    glColor3f(1,0,0);
    glVertex3f(0,0,0);
    glVertex3f(1,0,0);
    //y
    glColor3f(0,1,0);
    glVertex3f(0,0,0);
    glVertex3f(0,1,0);
    //z
    glColor3f(0,0,1);
    glVertex3f(0,0,0);
    glVertex3f(0,0,1);
    glEnd();
}


// Функция рисования каждого кадра
void draw_main(int){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  // Очитска экрана

    glRotatef(1, 0, 1, 0); // поворот на 1 градус (первый параметр) вокруг оси y
    // ось поворота задана вектором: 0, 1, 0

    draw_xyz();

    glLineWidth(1);
    glColor3f(1,1,1);
    glutWireTeapot(0.5);  // чайник из Юты

    glutSwapBuffers();

    //задать время через которое функция отрисовки будет вызвана снова
    glutTimerFunc(1000/60, draw_main, 0);
}



int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Example2: anamation");

    glutTimerFunc(1000/60, draw_main, 0);
    glutMainLoop();

    return 0;
}
