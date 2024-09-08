#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include <unistd.h>

using namespace std;


void draw_xyz(){
    glLineWidth(2);

    glBegin(GL_LINES);
    glColor3f(1,0,0);
    glVertex3f(0,0,0);
    glVertex3f(1,0,0);
//    glEnd();


    glColor3f(0,1,0);
//    glBegin(GL_LINES);
    glVertex3f(0,0,0);
    glVertex3f(0,1,0);
//    glEnd();


    glColor3f(0,0,1);
//    glBegin(GL_LINES);
    glVertex3f(0,0,0);
    glVertex3f(0,0,1);
    glEnd();
}


// Функция рисования каждого кадра
void draw_main(int){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  // Очитска экрана

    glRotatef(1, 0, 1, 1);

    glutSolidTeapot(0.5);
    draw_xyz();

    glutSwapBuffers();

    glutTimerFunc(1000/60, draw_main, 0);
}



int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Example2");

//    Освещение
    {
    GLfloat light_diffuse[] = {1.0, 1.0, 1.0, 1.0};  /* Red diffuse light. */
    GLfloat light_position[] = {10.0, 10.0, 10.0, 0.0};
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
        // GL_LIGHT0 - номер источника света
        // GL_DIFFUSE - тип задаваемого параметра для источника света. здесь описывается интенсивность света
        // light_diffuse - RGBA intensity of the light
        // (для других типов источников, смысл последнего параметра может быть иным)

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    }

    // Проверять на скрытые грани (и не рисовать их)
    glEnable(GL_DEPTH_TEST);

    glutTimerFunc(1000/60, draw_main, 0);
    glutMainLoop();

    return 0;
}
