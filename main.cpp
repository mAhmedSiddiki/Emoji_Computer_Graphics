#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <math.h>

void init(){
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glOrtho(-15,15,-15,15,-15,5);
}

void circle(GLfloat rx,GLfloat ry,GLfloat cx,GLfloat cy){
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx,cy);

    for(int i=0;i<=100;i++)
    {
        float angle = 2.0f * 3.1416f * i/100;

        float x = rx * cosf(angle);
        float y = ry * sinf(angle);

        glVertex2f((x+cx),(y+cy));
    }
    glEnd();
}

void myDisplay(){
    glClear(GL_COLOR_BUFFER_BIT);

    ///back Shape
    glColor4f(1.0f, 0.9f, 0.196078f, 0.0f);
    circle(10, 10, 0, 0);

    ///main circle
    glColor3f(1.0f, 1.0f, 0.0f);
    circle(10,9.7,-0.2,-0.5);

    ///mouth
    glColor3f(0.0f, 0.0f, 0.0f);
    circle(6,6,0,-2);
    glColor3f(1.0f, 1.0f, 0.0f);
    circle(8,6,0,1);

    ///tongue
    glColor3f(1.0f, 0.0f, 0.0f);
    circle(2,0.5,0,-7.5);

    ///nose
    glColor3f(1.0f, 0.0f, 0.0f);
    circle(1.5,1.5,0,-1.7);

    ///eye left - line
    glColor3f(0.0f, 0.0f, 0.0f);
    circle(2,2,-4,3);
    glColor3f(1.0f, 1.0f, 0.0f);
    circle(2.3,2,-4,2.5);

    ///eye left
    glColor3f(0.0f, 0.0f, 0.0f);
    circle(2,2,-4,2);

    ///eye left - white
    glColor3f(1.0f, 1.0f, 1.0f);
    circle(1.8,1.8,-4,2);

    ///eye left - moni
    glColor3f(0.0f, 0.0f, 0.0f);
    circle(0.9,0.9,-3.8,1.8);

    ///eye left - moni - white
    glColor3f(1.0f, 1.0f, 1.0f);
    circle(0.15,0.15,-3.5,1.8);

    ///eye left - line
    glColor3f(0.0f, 0.0f, 0.0f);
    circle(2,2,4,3);
    glColor3f(1.0f, 1.0f, 0.0f);
    circle(2.3,2,4,2.5);

    ///eye right
    glColor3f(0.0f, 0.0f, 0.0f);
    circle(2,2,4,2);

    ///eye right - white
    glColor3f(1.0f, 1.0f, 1.0f);
    circle(1.8,1.8,4,2);

    ///eye left - moni
    glColor3f(0.0f, 0.0f, 0.0f);
    circle(0.9,0.9,4.3,1.8);

    ///eye right - moni - white
    glColor3f(1.0f, 1.0f, 1.0f);
    circle(0.15,0.15, 4.6,1.8);

    glFlush();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(300, 100);
    glutCreateWindow("Emoji - Marjuk");
    init();
    glutDisplayFunc(myDisplay);
    glutMainLoop();
    return 0;
}
