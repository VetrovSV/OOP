#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <vector>

using namespace std;

const unsigned n = 10;
GLfloat boxes[n][3];
float x,y,z;

void draw_grid(){
    float a=-2, b=2;
    unsigned n = 20;
    float d = (b-a)/n;
    glLineWidth(2);
    glColor3f(1,1,1);

    glBegin(GL_LINES);
    for (unsigned i=0; i <n; i++){
        glVertex2f( a, -a+i*d);
        glVertex2f( b, -a+i*d);

        glVertex3f(-a+i*d, a, -1);
        glVertex3f(-a+i*d, b, -1);}
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(0,0,0);
        glVertex3f(1,0,0);
        glVertex3f(0,1,-1);
    glEnd();
}


void init_teapots(){
    for (unsigned i = 0; i<n; i++) {
        for (unsigned j=0;j<3;j++){
            boxes[i][j] = 1.0*rand()/RAND_MAX*2 - 1;
            cout << boxes[i][j] << endl;}
    }
}

void draw_teapots(){
    glLineWidth(1);
    glColor3f(1,1,1);
    for (unsigned i = 0; i<n; i++){
//        glTranslated(boxes[i][0], boxes[i][1], boxes[i][2]);
//        glutWireCube(0.05);
//        glTranslated(-boxes[i][0], -boxes[i][1], -boxes[i][2]);
        glBegin(GL_POINTS);
            glVertex3fv(boxes[i]);
        glEnd();
    }
}


// Функция рисования каждого кадра
void draw_main(int){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  // Очитска экрана

//    glTranslatef(x,y,z);

    draw_grid();
//    draw_teapots();

    glutSwapBuffers();

    //задать время через которое функция отрисовки будет вызвана снова
    glutTimerFunc(1000/60, draw_main, 0);
}


void key_handler(int k, int x, int y){
    cout << k << endl;
    switch (k) {
        case 100: x = x - 0.01; break;
        case 101: z = z - 0.01; break;
        case 102: z = z + 0.01; break;
        case 103: x = x + 0.01; break;
    }

    draw_main(0);
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Example2: anamation");

    init_teapots();
    gluLookAt(x, y, 300, 150, 150, 0, 0, 1, 0);
    x=0; y=0; z=0;

    glutTimerFunc(1000/60, draw_main, 0);
    glutSpecialFunc(key_handler);
    glutMainLoop();

    return 0;
}
