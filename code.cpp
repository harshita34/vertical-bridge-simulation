#define GL_SILENCE_DEPRECATION
#include<GL/glut.h>
#include<iostream>
#include<cmath>
#include<string.h>

int flag = 0; // used to maintain the state of the program in the idle function
// if flag = 0, then the program is in the initial state and the train is at the station
// if flag = 1, then the program is in the running state and the train is moving
// if flag = 2, then the program is in the final state and the train has reached the destination
int flagb = 1; // used to maintain the state of the train

int flags = 0; // used to maintain the state of the ship
int flagt = 0, flagw = 1, flagp = 0, flagx = 0, flagr = 0;
float a = 0.0f, b = 0.0f, c = 0.0f, m = 0.0f, n = 0.0f, o = 0.0f, p = 0.0f,
q = 0.0f, r = 0.0f, x = 0.0f, y = 0.0f, z = 0.0f, a1 = 0.0,
a2 = 0.0, a3 = 0.0;

void ocean()
{
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.4, 0.6); //dark cyan
    glVertex3f(-5.0, -0.415, 5.0);
    glVertex3f(5.0, -0.415, 5.0);
    glVertex3f(5.0, -0.415, -5.0);
    glVertex3f(-5.0, -0.415, -5.0);
    glEnd();
}
void waves()
{
    glBegin(GL_LINES);
    for (float t1 = 0.0; t1 <= 10.0; t1 += 0.4)
    {
        for (float t2 = 0.0; t2 <= 10.0; t2 += 0.4)
        {
            glColor3f(0.0, 0.6, 1.0);
            glVertex3f(-5.0 + t2, -0.41, -4.5 + t1);
            glVertex3f(-4.95 + t2, -0.41, -4.5 + t1);
        }
    }
    glEnd();
}
void track_base_front()
{
    for (float i = 0.0; i < 1.0; i += 0.8)
    {
        glBegin(GL_QUADS);
        glColor3f(0.56, 0.39, 0.05); //front
        glVertex3f(-0.5 + i, -0.4, 0.2);
        glVertex3f(-0.3 + i, -0.4, 0.2);
        glVertex3f(-0.3 + i, -0.25, 0.2);
        glVertex3f(-0.5 + i, -0.25, 0.2);
        glColor3f(0.46, 0.29, 0.05); //right front
        glVertex3f(-0.5 + i, -0.4, 0.2);
        glVertex3f(-0.5 + i, -0.4, -0.2);
        glVertex3f(-0.5 + i, -0.25, -0.2);
        glVertex3f(-0.5 + i, -0.25, 0.2);
        glColor3f(0.5, 0.5, 0.5); //top
        glVertex3f(-0.5 + i, -0.25, 0.2);
        glVertex3f(-0.3 + i, -0.25, 0.2);
        glVertex3f(-0.3 + i, -0.25, -0.2);
        glVertex3f(-0.5 + i, -0.25, -0.2);
        glEnd();

    }
}
void track_base() {
    for (float i = 0.0; i < 4.0; i += 3.5)

    {
        glBegin(GL_QUADS);
        glColor3f(0.56, 0.39, 0.05);
        glVertex3f(-3.0 + i, -0.4, 0.17); //side front
        glVertex3f(-0.5 + i, -0.4, 0.17);
        glVertex3f(-0.5 + i, -0.25, 0.17);
        glVertex3f(-3.0 + i, -0.25, 0.17);
        glColor3f(0.4, 0.2, 0.05); //top
        glVertex3f(-3.0 + i, -0.25, 0.17);
        glVertex3f(-0.5 + i, -0.25, 0.17);
        glVertex3f(-0.5 + i, -0.25, -0.17);
        glVertex3f(-3.0 + i, -0.25, -0.17);
        glEnd();

    }
}
void gate_pillar() {
    glBegin(GL_QUADS);

    // front left pillar

    glColor3f(0.1, 0.1, 0.1); // front
    glVertex3f(-0.35, -0.25, 0.2);
    glVertex3f(-0.31, -0.25, 0.2);
    glVertex3f(-0.31, 0.2, 0.2);
    glVertex3f(-0.35, 0.2, 0.2);
    glColor3f(0.2, 0.2, 0.2); // side
    glVertex3f(-0.35, -0.25, 0.2);
    glVertex3f(-0.35, -0.25, 0.15);
    glVertex3f(-0.35, 0.2, 0.15);
    glVertex3f(-0.35, 0.2, 0.2);

    // back left pillar

    glColor3f(0.1, 0.1, 0.1); // front
    glVertex3f(-0.35, -0.25, -0.15);
    glVertex3f(-0.31, -0.25, -0.15);
    glVertex3f(-0.31, 0.2, -0.15);
    glVertex3f(-0.35, 0.2, -0.15);
    glColor3f(0.2, 0.2, 0.2); // side
    glVertex3f(-0.35, -0.25, -0.2);
    glVertex3f(-0.35, -0.25, -0.15);
    glVertex3f(-0.35, 0.2, -0.15);
    glVertex3f(-0.35, 0.2, -0.2);

    // top bar left

    glColor3f(0.2, 0.2, 0.5); // front
    glVertex3f(-0.35, 0.2, 0.3);
    glVertex3f(-0.31, 0.2, 0.3);
    glVertex3f(-0.31, 0.25, 0.3);
    glVertex3f(-0.35, 0.25, 0.3);
    glColor3f(0.3, 0.3, 0.5); // side
    glVertex3f(-0.35, 0.2, 0.3);
    glVertex3f(-0.35, 0.2, -0.3);
    glVertex3f(-0.35, 0.25, -0.3);
    glVertex3f(-0.35, 0.25, 0.3);
    glColor3f(0.3, 0.3, 0.6); // top
    glVertex3f(-0.35, 0.25, 0.3);
    glVertex3f(-0.31, 0.25, 0.3);
    glVertex3f(-0.31, 0.25, -0.3);
    glVertex3f(-0.35, 0.25, -0.3);

    // front left pillar top pillar
    glColor3f(0.1, 0.1, 0.1);//front
    glVertex3f(-0.35, 0.25, 0.2);
    glVertex3f(-0.31, 0.25, 0.2);
    glVertex3f(-0.31, 0.35, 0.2);
    glVertex3f(-0.35, 0.35, 0.2);
    glColor3f(0.2, 0.2, 0.2); //left
    glVertex3f(-0.35, 0.25, 0.2);
    glVertex3f(-0.35, 0.25, 0.15);
    glVertex3f(-0.35, 0.35, 0.15);
    glVertex3f(-0.35, 0.35, 0.2);
    glColor3f(0.1, 0.1, 0.1); //back
    glVertex3f(-0.35, 0.25, 0.15);
    glVertex3f(-0.31, 0.25, 0.15);
    glVertex3f(-0.31, 0.35, 0.15);
    glVertex3f(-0.35, 0.35, 0.15);
    glColor3f(0.2, 0.2, 0.2); //right
    glVertex3f(-0.31, 0.25, 0.2);
    glVertex3f(-0.31, 0.25, 0.15);
    glVertex3f(-0.31, 0.35, 0.15);
    glVertex3f(-0.31, 0.35, 0.2);

    //back left pillar top pillar

    glColor3f(0.1, 0.1, 0.1); //back
    glVertex3f(-0.35, 0.25, -0.2);
    glVertex3f(-0.31, 0.25, -0.2);
    glVertex3f(-0.31, 0.35, -0.2);
    glVertex3f(-0.35, 0.35, -0.2);
    glColor3f(0.2, 0.2, 0.2); //left
    glVertex3f(-0.35, 0.25, -0.2);
    glVertex3f(-0.35, 0.25, -0.15);
    glVertex3f(-0.35, 0.35, -0.15);
    glVertex3f(-0.35, 0.35, -0.2);
    glColor3f(0.1, 0.1, 0.1); //front
    glVertex3f(-0.35, 0.25, -0.15);
    glVertex3f(-0.31, 0.25, -0.15);
    glVertex3f(-0.31, 0.35, -0.15);
    glVertex3f(-0.35, 0.35, -0.15);
    glColor3f(0.2, 0.2, 0.2); //right
    glVertex3f(-0.31, 0.25, -0.2);
    glVertex3f(-0.31, 0.25, -0.15);
    glVertex3f(-0.31, 0.35, -0.15);
    glVertex3f(-0.31, 0.35, -0.2);

    //front right pillar

    glColor3f(0.1, 0.1, 0.1); //front
    glVertex3f(0.35, -0.25, 0.2);
    glVertex3f(0.31, -0.25, 0.2);
    glVertex3f(0.31, 0.2, 0.2);
    glVertex3f(0.35, 0.2, 0.2);
    glColor3f(0.2, 0.2, 0.2); //side
    glVertex3f(0.31, -0.25, 0.2);
    glVertex3f(0.31, -0.25, 0.15);
    glVertex3f(0.31, 0.2, 0.15);
    glVertex3f(0.31, 0.2, 0.2);

    //back right pillar
    glColor3f(0.1, 0.1, 0.1); //front
    glVertex3f(0.35, -0.25, -0.15);
    glVertex3f(0.31, -0.25, -0.15);
    glVertex3f(0.31, 0.2, -0.15);
    glVertex3f(0.35, 0.2, -0.15);
    glColor3f(0.2, 0.2, 0.2); //side
    glVertex3f(0.31, -0.25, -0.2);
    glVertex3f(0.31, -0.25, -0.15);
    glVertex3f(0.31, 0.2, -0.15);
    glVertex3f(0.31, 0.2, -0.2);

    //top bar right
    glColor3f(0.2, 0.2, 0.5); //front
    glVertex3f(0.35, 0.2, 0.3);
    glVertex3f(0.31, 0.2, 0.3);
    glVertex3f(0.31, 0.25, 0.3);
    glVertex3f(0.35, 0.25, 0.3);
    glColor3f(0.3, 0.3, 0.5); //side
    glVertex3f(0.31, 0.2, 0.3);
    glVertex3f(0.31, 0.2, -0.3);
    glVertex3f(0.31, 0.25, -0.3);
    glVertex3f(0.31, 0.25, 0.3);
    glColor3f(0.3, 0.3, 0.6); //top
    glVertex3f(0.35, 0.25, 0.3);
    glVertex3f(0.31, 0.25, 0.3);
    glVertex3f(0.31, 0.25, -0.3);
    glVertex3f(0.35, 0.25, -0.3);

    //front right pillar top pillar

    glColor3f(0.1, 0.1, 0.1); //front
    glVertex3f(0.35, 0.25, 0.2);
    glVertex3f(0.31, 0.25, 0.2);
    glVertex3f(0.31, 0.35, 0.2);
    glVertex3f(0.35, 0.35, 0.2);
    glColor3f(0.2, 0.2, 0.2); //left
    glVertex3f(0.35, 0.25, 0.2);
    glVertex3f(0.35, 0.25, 0.15);
    glVertex3f(0.35, 0.35, 0.15);
    glVertex3f(0.35, 0.35, 0.2);
    glColor3f(0.1, 0.1, 0.1); //back
    glVertex3f(0.35, 0.25, 0.15);
    glVertex3f(0.31, 0.25, 0.15);
    glVertex3f(0.31, 0.35, 0.15);
    glVertex3f(0.35, 0.35, 0.15);
    glColor3f(0.2, 0.2, 0.2); //right
    glVertex3f(0.31, 0.25, 0.2);
    glVertex3f(0.31, 0.25, 0.15);
    glVertex3f(0.31, 0.35, 0.15);
    glVertex3f(0.31, 0.35, 0.2);

    //back right pillar top pillar

    glColor3f(0.1, 0.1, 0.1); //back
    glVertex3f(0.35, 0.25, -0.2);
    glVertex3f(0.31, 0.25, -0.2);
    glVertex3f(0.31, 0.35, -0.2);
    glVertex3f(0.35, 0.35, -0.2);
    glColor3f(0.2, 0.2, 0.2); //left
    glVertex3f(0.35, 0.25, -0.2);
    glVertex3f(0.35, 0.25, -0.15);
    glVertex3f(0.35, 0.35, -0.15);
    glVertex3f(0.35, 0.35, -0.2);
    glColor3f(0.1, 0.1, 0.1); //front
    glVertex3f(0.35, 0.25, -0.15);
    glVertex3f(0.31, 0.25, -0.15);
    glVertex3f(0.31, 0.35, -0.15);
    glVertex3f(0.35, 0.35, -0.15);
    glColor3f(0.2, 0.2, 0.2); //right
    glVertex3f(0.31, 0.25, -0.2);
    glVertex3f(0.31, 0.25, -0.15);
    glVertex3f(0.31, 0.35, -0.15);
    glVertex3f(0.31, 0.35, -0.2);

    //hangers
    glColor3f(0.5, 0.5, 1); //mauve
    //front left
    glVertex3f(-0.6, -0.25, 0.17);
    glVertex3f(-0.5, -0.25, 0.17);
    glVertex3f(-0.35, 0.2, 0.17);
    glVertex3f(-0.35, 0.25, 0.17);
    //back left
    glVertex3f(-0.6, -0.25, -0.17);
    glVertex3f(-0.5, -0.25, -0.17);
    glVertex3f(-0.35, 0.2, -0.17);
    glVertex3f(-0.35, 0.25, -0.17);
    //front right
    glVertex3f(0.6, -0.25, 0.17);
    glVertex3f(0.5, -0.25, 0.17);
    glVertex3f(0.35, 0.2, 0.17);
    glVertex3f(0.35, 0.25, 0.17);
    //back right
    glVertex3f(0.6, -0.25, -0.17);
    glVertex3f(0.5, -0.25, -0.17);
    glVertex3f(0.35, 0.2, -0.17);
    glVertex3f(0.35, 0.25, -0.17);
    glEnd();
}

void bridge() {
    glBegin(GL_QUADS);
    // bridge base front
    glColor3f(0.1, 0.2, 0.3);
    glVertex3f(-0.3, -0.25, 0.15);
    glVertex3f(0.3, -0.25, 0.15);
    glVertex3f(0.3, -0.23, 0.15);
    glVertex3f(-0.3, -0.23, 0.15);
    // bridge base left
    glColor3f(0.1, 0.2, 0.3);
    glVertex3f(-0.3, -0.25, 0.15);
    glVertex3f(-0.3, -0.25, -0.15);
    glVertex3f(-0.3, -0.23, -0.15);
    glVertex3f(-0.3, -0.23, 0.15);
    // bridge base top
    glColor3f(0.3, 0.3, 0.4);
    glVertex3f(-0.3, -0.23, 0.15);
    glVertex3f(0.3, -0.23, 0.15);
    glVertex3f(0.3, -0.23, -0.15);
    glVertex3f(-0.3, -0.23, -0.15);
    glEnd();

    // bridge rail lines
    glBegin(GL_LINES);
    // rail lines horizontal
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-0.3, -0.23, 0.12);
    glVertex3f(0.3, -0.23, 0.12);
    glVertex3f(-0.3, -0.23, 0.1);
    glVertex3f(0.3, -0.23, 0.1);
    glVertex3f(-0.3, -0.23, -0.12);
    glVertex3f(0.3, -0.23, -0.12);
    glVertex3f(-0.3, -0.23, -0.1);
    glVertex3f(0.3, -0.23, -0.1);
    glEnd();

    glBegin(GL_LINES);
    // rail lines vertical
    glColor3f(1, 1, 1);
    for (float j = 0.0; j <= 0.6; j += 0.1) {
        glVertex3f(-0.3 + j, -0.23, 0.1);
        glVertex3f(-0.3 + j, -0.23, -0.1);
    }
    glEnd();

    glBegin(GL_QUADS);

    //left front pillar
    glColor3f(0.3, 0.2, 0.1); //front
    glVertex3f(-0.3, -0.23, 0.15);
    glVertex3f(-0.28, -0.23, 0.15);
    glVertex3f(-0.28, 0.1, 0.15);
    glVertex3f(-0.3, 0.1, 0.15);

    glColor3f(0.3, 0.2, 0.3); //side
    glVertex3f(-0.3, -0.23, 0.15);
    glVertex3f(-0.3, -0.23, 0.12);
    glVertex3f(-0.3, 0.1, 0.12);
    glVertex3f(-0.3, 0.1, 0.15);

    //right front pillar
    glColor3f(0.3, 0.2, 0.1); //front
    glVertex3f(0.3, -0.23, 0.15);
    glVertex3f(0.28, -0.23, 0.15);
    glVertex3f(0.28, 0.1, 0.15);
    glVertex3f(0.3, 0.1, 0.15);

    glColor3f(0.3, 0.2, 0.3); //side
    glVertex3f(0.28, -0.23, 0.15);
    glVertex3f(0.28, -0.23, 0.12);
    glVertex3f(0.28, 0.1, 0.12);
    glVertex3f(0.28, 0.1, 0.15);

    //left back pillar
    glColor3f(0.3, 0.2, 0.3); //side
    glVertex3f(-0.3, -0.23, -0.15);
    glVertex3f(-0.3, -0.23, -0.12);
    glVertex3f(-0.3, 0.1, -0.12);
    glVertex3f(-0.3, 0.1, -0.15);

    glColor3f(0.3, 0.2, 0.1); //front
    glVertex3f(-0.3, -0.23, -0.12);
    glVertex3f(-0.28, -0.23, -0.12);
    glVertex3f(-0.28, 0.1, -0.12);
    glVertex3f(-0.3, 0.1, -0.12);

    //right back pillar
    glColor3f(0.3, 0.2, 0.1); //front
    glVertex3f(0.3, -0.23, -0.12);
    glVertex3f(0.28, -0.23, -0.12);
    glVertex3f(0.28, 0.1, -0.12);
    glVertex3f(0.3, 0.1, -0.12);

    glColor3f(0.3, 0.2, 0.3); //side
    glVertex3f(0.28, -0.23, -0.15);
    glVertex3f(0.28, -0.23, -0.12);
    glVertex3f(0.28, 0.1, -0.12);
    glVertex3f(0.28, 0.1, -0.15);

    //bridge top left bar
    glColor3f(0.4, 0.3, 0.2); //front
    glVertex3f(-0.3, 0.1, 0.15);
    glVertex3f(-0.28, 0.1, 0.15);
    glVertex3f(-0.28, 0.13, 0.15);
    glVertex3f(-0.3, 0.13, 0.15);

    glColor3f(0.5, 0.3, 0.2); //left
    glVertex3f(-0.3, 0.1, 0.15);
    glVertex3f(-0.3, 0.1, -0.15);
    glVertex3f(-0.3, 0.13, -0.15);
    glVertex3f(-0.3, 0.13, 0.15);

    glColor3f(0.4, 0.3, 0.2); //back
    glVertex3f(-0.3, 0.1, -0.15);
    glVertex3f(-0.28, 0.1, -0.15);
    glVertex3f(-0.28, 0.13, -0.15);
    glVertex3f(-0.3, 0.13, -0.15);

    glColor3f(0.5, 0.3, 0.2); //top
    glVertex3f(-0.28, 0.1, 0.15);
    glVertex3f(-0.28, 0.1, -0.15);
    glVertex3f(-0.28, 0.13, -0.15);
    glVertex3f(-0.28, 0.13, 0.15);

    //bridge top right bar
    glColor3f(0.4, 0.3, 0.2); //front
    glVertex3f(0.3, 0.1, 0.15);
    glVertex3f(0.28, 0.1, 0.15);
    glVertex3f(0.28, 0.13, 0.15);
    glVertex3f(0.3, 0.13, 0.15);

    glColor3f(0.5, 0.3, 0.2); //right
    glVertex3f(0.3, 0.1, 0.15);
    glVertex3f(0.3, 0.1, -0.15);
    glVertex3f(0.3, 0.13, -0.15);
    glVertex3f(0.3, 0.13, 0.15);

    glColor3f(0.4, 0.3, 0.2); //back
    glVertex3f(0.3, 0.1, -0.15);
    glVertex3f(0.28, 0.1, -0.15);
    glVertex3f(0.28, 0.13, -0.15);
    glVertex3f(0.3, 0.13, -0.15);

    glColor3f(0.5, 0.3, 0.2); //left
    glVertex3f(0.28, 0.1, 0.15);
    glVertex3f(0.28, 0.1, -0.15);
    glVertex3f(0.28, 0.13, -0.15);
    glVertex3f(0.28, 0.13, 0.15);

    //lower front middle bar
    glColor3f(0.4, 0.3, 0.5);
    glVertex3f(-0.28, -0.15, 0.15); //front
    glVertex3f(0.28, -0.15, 0.15);
    glVertex3f(0.28, -0.12, 0.15);
    glVertex3f(-0.28, -0.12, 0.15);

    glVertex3f(-0.28, -0.15, 0.12); //top
    glVertex3f(0.28, -0.15, 0.12);
    glVertex3f(0.28, -0.12, 0.12);
    glVertex3f(-0.28, -0.12, 0.12);

    //lower back middle bar
    glVertex3f(-0.28, -0.15, -0.15); //top
    glVertex3f(0.28, -0.15, -0.15);
    glVertex3f(0.28, -0.12, -0.15);
    glVertex3f(-0.28, -0.12, -0.15);

    glVertex3f(-0.28, -0.15, -0.12); //front
    glVertex3f(0.28, -0.15, -0.12);
    glVertex3f(0.28, -0.12, -0.12);
    glVertex3f(-0.28, -0.12, -0.12);

    //upper front middle bar
    glColor3f(0.4, 0.3, 0.5); //front
    glVertex3f(-0.28, 0.1, 0.15);
    glVertex3f(0.28, 0.1, 0.15);
    glVertex3f(0.28, 0.13, 0.15);
    glVertex3f(-0.28, 0.13, 0.15);
    glVertex3f(-0.28, 0.1, 0.12); //top
    glVertex3f(0.28, 0.1, 0.12);
    glVertex3f(0.28, 0.13, 0.12);
    glVertex3f(-0.28, 0.13, 0.12);

    //upper back middle bar
    glColor3f(0.4, 0.3, 0.5); //top
    glVertex3f(-0.28, 0.1, -0.15);
    glVertex3f(0.28, 0.1, -0.15);
    glVertex3f(0.28, 0.13, -0.15);
    glVertex3f(-0.28, 0.13, -0.15);
    glColor3f(0.4, 0.3, 0.5); //front
    glVertex3f(-0.28, 0.1, -0.12);
    glVertex3f(0.28, 0.1, -0.12);
    glVertex3f(0.28, 0.13, -0.12);
    glVertex3f(-0.28, 0.13, -0.12);
    glEnd();

    //HOUSE
    glColor3f(0.3, 0.3, 0.3);
    glPushMatrix();
    glTranslatef(0.0, 0.25, 0.0);
    glutSolidCube(0.25);
    glPopMatrix();

    glBegin(GL_QUADS); //WINDOW
    glColor3f(0.5, 0.9, 1.0);
    glVertex3f(-0.05, 0.18, 0.16);
    glVertex3f(0.05, 0.18, 0.16);
    glVertex3f(0.05, 0.25, 0.16);
    glVertex3f(-0.05, 0.25, 0.16);
    glEnd();

    glBegin(GL_TRIANGLES); //ROOF
    glColor3f(1, 0, 0);
    glVertex3f(-0.16, 0.35, 0.16);
    glVertex3f(0.16, 0.35, 0.16);
    glVertex3f(0.0, 0.5, 0.0);

    glVertex3f(-0.16, 0.35, 0.16);
    glVertex3f(-0.16, 0.35, -0.16);
    glVertex3f(0.0, 0.5, 0.0);

    glVertex3f(-0.16, 0.35, -0.16);
    glVertex3f(0.16, 0.35, -0.16);
    glVertex3f(0.0, 0.5, 0.0);

    glVertex3f(0.16, 0.35, 0.16);
    glVertex3f(0.16, 0.35, -0.16);
    glVertex3f(0.0, 0.5, 0.0);
    glEnd();
}



void rail_track() {
    glBegin(GL_LINES); //rail lines horizontal
    glColor3f(0.0, 0.0, 0.0);

    //left
    glVertex3f(-3.0, -0.23, 0.12);
    glVertex3f(-0.3, -0.23, 0.12);
    glVertex3f(-3.0, -0.23, 0.1);
    glVertex3f(-0.3, -0.23, 0.1);
    glVertex3f(-3.0, -0.23, -0.12);
    glVertex3f(-0.3, -0.23, -0.12);
    glVertex3f(-3.0, -0.23, -0.1);
    glVertex3f(-0.3, -0.23, -0.1);

    //right
    glVertex3f(3.0, -0.23, 0.12);
    glVertex3f(0.3, -0.23, 0.12);
    glVertex3f(3.0, -0.23, 0.1);
    glVertex3f(0.3, -0.23, 0.1);
    glVertex3f(3.0, -0.23, -0.12);
    glVertex3f(0.3, -0.23, -0.12);
    glVertex3f(3.0, -0.23, -0.1);
    glVertex3f(0.3, -0.23, -0.1);

    glEnd();
    glBegin(GL_LINES); //rail lines vertical
    glColor3f(1, 1, 1);

    for (float j = 0.0; j <= 2.6; j += 0.1) {
        glVertex3f(-3.0 + j, -0.23, 0.1);
        glVertex3f(-3.0 + j, -0.23, -0.1);
    }

    for (float j = 0.0; j <= 3; j += 0.1) {
        glVertex3f(0.3 + j, -0.23, 0.1);
        glVertex3f(0.3 + j, -0.23, -0.1);
    }
    glEnd();
}

void ship() {
    glBegin(GL_QUADS);

    //lowest base
    glColor3f(0, 0.5, 0.2); //base front
    glVertex3f(-0.2, -0.4, -3.5);
    glVertex3f(0.2, -0.4, -3.5);
    glVertex3f(0.2, -0.3, -3.5);
    glVertex3f(-0.2, -0.3, -3.5);

    glColor3f(0, 0.5, 0.5); //base side
    glVertex3f(-0.2, -0.4, -3.5);
    glVertex3f(-0.2, -0.4, -4.8);
    glVertex3f(-0.2, -0.3, -5.0);
    glVertex3f(-0.2, -0.3, -3.5);

    glColor3f(0, 0, 0.5); //base top
    glVertex3f(-0.2, -0.3, -3.5);
    glVertex3f(0.2, -0.3, -3.5);
    glVertex3f(0.2, -0.3, -5.0);
    glVertex3f(-0.2, -0.3, -5.0);

    //second base
    glColor3f(0, 0.5, 0.2); //front
    glVertex3f(-0.18, -0.3, -3.7);
    glVertex3f(0.18, -0.3, -3.7);
    glVertex3f(0.18, -0.2, -3.7);
    glVertex3f(-0.18, -0.2, -3.7);

    glColor3f(0, 0.5, 0.5); //side
    glVertex3f(-0.18, -0.3, -3.7);
    glVertex3f(-0.18, -0.3, -4.8);
    glVertex3f(-0.18, -0.2, -4.8);
    glVertex3f(-0.18, -0.2, -3.7);

    glColor3f(0, 0, 0.5); //top
    glVertex3f(-0.18, -0.2, -3.7);
    glVertex3f(0.18, -0.2, -3.7);
    glVertex3f(0.18, -0.2, -4.8);
    glVertex3f(-0.18, -0.2, -4.8);

    // top base
    glColor3f(0, 0.5, 0.2); //front
    glVertex3f(-0.16, -0.19, -3.7);
    glVertex3f(0.15, -0.19, -3.7);
    glVertex3f(0.15, -0.1, -3.7);
    glVertex3f(-0.16, -0.1, -3.7);

    glColor3f(0, 0.5, 0.5); //side
    glVertex3f(-0.15, -0.2, -3.7);
    glVertex3f(-0.15, -0.2, -4.8);
    glVertex3f(-0.15, -0.1, -4.8);
    glVertex3f(-0.15, -0.1, -3.7);

    glColor3f(0, 0, 0.5); //top
    glVertex3f(-0.15, -0.1, -3.7);
    glVertex3f(0.15, -0.1, -3.7);
    glVertex3f(0.15, -0.1, -4.8);
    glVertex3f(-0.15, -0.1, -4.8);
    glEnd();

    //bow section
    glBegin(GL_TRIANGLES);
    glColor3f(0.4, 0.4, 0.4); //front triangle
    glVertex3f(-0.2, -0.4, -3.5);
    glVertex3f(-0.2, -0.3, -3.5);
    glVertex3f(0.0, -0.15, -2.2);

    glColor3f(0, 0, 0); //front bottom
    glVertex3f(-0.2, -0.4, -3.5);
    glVertex3f(0.2, -0.4, -3.5);
    glVertex3f(0.0, -0.15, -2.2);

    glColor3f(0.5, 0.5, 0.7); //back triangle
    glVertex3f(0.2, -0.4, -3.5);
    glVertex3f(0.2, -0.3, -3.5);
    glVertex3f(0.0, -0.15, -2.2);
    glEnd();

    // top pillar
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.5, 0.1); // front
    glVertex3f(-0.05, -0.2, -4.2);
    glVertex3f(0.05, -0.2, -4.2);
    glVertex3f(0.05, 0.2, -4.2);
    glVertex3f(-0.05, 0.2, -4.2);

    glColor3f(1.0, 0.6, 0.2); // left
    glVertex3f(-0.05, -0.2, -4.2);
    glVertex3f(-0.05, -0.2, -4.5);
    glVertex3f(-0.05, 0.2, -4.5);
    glVertex3f(-0.05, 0.2, -4.2);

    glColor3f(1.0, 0.5, 0.1); // back
    glVertex3f(-0.05, -0.2, -4.5);
    glVertex3f(0.05, -0.2, -4.5);
    glVertex3f(0.05, 0.2, -4.5);
    glVertex3f(-0.05, 0.2, -4.5);

    glColor3f(1.0, 0.6, 0.2); // right
    glVertex3f(0.05, -0.2, -4.2);
    glVertex3f(0.05, -0.2, -4.5);
    glVertex3f(0.05, 0.2, -4.5);
    glVertex3f(0.05, 0.2, -4.2);
    glEnd();
}


void train()
{
    glBegin(GL_QUADS);
    //Engine
    glColor3f(1.0, 0.6, 0.2); //bottom front
    glVertex3f(1.0, -0.23, 0.1);
    glVertex3f(1.15, -0.23, 0.1);
    glVertex3f(1.15, -0.14, 0.1);
    glVertex3f(1.0, -0.14, 0.1);
    glColor3f(1.0, 0.5, 0.1); //bottom side
    glVertex3f(1.0, -0.23, 0.1);
    glVertex3f(1.0, -0.23, -0.1);
    glVertex3f(1.0, -0.14, -0.1);
    glVertex3f(1.0, -0.14, 0.1);

    glColor3f(1, 1, 1); //windshield slope
    glVertex3f(1.0, -0.14, 0.1);
    glVertex3f(1.15, -0.05, 0.1);
    glVertex3f(1.15, -0.05, -0.1);
    glVertex3f(1.0, -0.14, -0.1);

    glColor3f(0.5, 0.9, 1.0); //windshield
    glVertex3f(1.02, -0.12, 0.1);
    glVertex3f(1.13, -0.05, 0.1);
    glVertex3f(1.13, -0.05, -0.06);
    glVertex3f(1.02, -0.12, -0.06);
    glEnd();

    //Engine Side
    glBegin(GL_TRIANGLES);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(1.0, -0.14, 0.1);
    glVertex3f(1.15, -0.14, 0.1);
    glVertex3f(1.15, -0.05, 0.1);
    glEnd();

    //bogies
    glBegin(GL_QUADS);
    for (float j = 0.0; j < 2; j += 0.27) {
        glColor3f(1, 1, 0); //front
        glVertex3f(1.15 + j, -0.23, 0.1);
        glVertex3f(1.4 + j, -0.23, 0.1);
        glVertex3f(1.4 + j, -0.05, 0.1);
        glVertex3f(1.15 + j, -0.05, 0.1);

        glColor3f(0.8, 0.6, 0.4); //sides
        glVertex3f(1.15 + j, -0.23, 0.1);
        glVertex3f(1.15 + j, -0.23, -0.1);
        glVertex3f(1.15 + j, -0.05, -0.1);
        glVertex3f(1.15 + j, -0.05, 0.1);

        glColor3f(0.7, 0.7, 0.2); //top
        glVertex3f(1.15 + j, -0.05, 0.1);
        glVertex3f(1.4 + j, -0.05, 0.1);
        glVertex3f(1.4 + j, -0.05, -0.1);
        glVertex3f(1.15 + j, -0.05, -0.1);

        glColor3f(0.0, 0.0, 0.0); //window
        glVertex3f(1.20 + j, -0.17, 0.12);
        glVertex3f(1.3 + j, -0.17, 0.12);
        glVertex3f(1.3 + j, -0.07, 0.12);
        glVertex3f(1.20 + j, -0.07, 0.12);
    }
    glEnd();
}

void signal() {
    glBegin(GL_QUADS);
    glColor3f(0.4, 0.3, 0.1); //pole
    glVertex3f(0.7, -0.25, -0.17);
    glVertex3f(0.73, -0.25, -0.17);
    glVertex3f(0.73, 0.10, -0.17);
    glVertex3f(0.7, 0.10, -0.17);
    glColor3f(0.1, 0.1, 0.1); //light mount
    glVertex3f(0.67, 0.10, -0.17);
    glVertex3f(0.76, 0.10, -0.17);
    glVertex3f(0.76, 0.3, -0.17);
    glVertex3f(0.67, 0.3, -0.17);
    glEnd();
}
void stars()
{
    float xpos = -2;
    float ypos = 0.6;
    for (int y = 0; y <= 3; y++)
    {
        for (int i = 0; i <= 50; i++)
        {
            glPushMatrix();
            glColor3f(1.0, 1.0, 1.0);
            glTranslatef(xpos, ypos, -5.1);
            glutSolidSphere(0.006, 20, 20);
            glPopMatrix();
            xpos = xpos + 0.2;
        }
        xpos = -2;
        ypos = ypos + 0.2;
    }

}

//used to place a sphere over a the black traffic-light base
void light() {
    if (b > 0.0)
        glColor3f(1.0, 0.0, 0.0);
    else
        glColor3f(0.0, 1.0, 0.0);
    if (p < -3.5) // p is the x-coordinate of the train
        glColor3f(1.0, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(0.715, 0.25, -0.17);
    glutSolidSphere(0.03, 10, 10);
    glPopMatrix();
}

void call1() {
    glTranslatef(a, b, c);
    bridge();
}
void call2() {
    glTranslatef(m, n, o);
    ship();
}
void call3() {
    glTranslatef(p, q, r);
    train();
}
void call4() {
    glTranslatef(a1, a2, a3);
    waves();
}
void update(int value) {
    if (flagx == 1) //flagx = 1 means the animation is on and flagx = 0 means the animation is off
    {
        if (flagb == 1) //bridge down on change 
        {
            b += 0.02f;
            if (b > 0.5)

            {
                flagb = 2; // flagb = 2 means the bridge is down
                flags = 1; // flags = 1 means the ship is moving

            }

        }
        if (flags == 1) //ship

        {
            o += 0.07f; //o is the x coordinate of the ship
            if (o > 2.0) //when the ship reaches the end of the bridge
                flagp = 1; //flagp = 1 means the ship is moving down
            if (o > 6.0) // this means the ship has reached the end of the screen
            {
                flagb = 0; //flagb = 0 means the bridge is up
            }
        }
        if (flagb == 0) //bridge up on change 
        {
            b -= 0.02f; // b is the y coordinate of the bridge
            if (b < 0.01) // when the bridge reaches the initial position
            {
                flagb = 1; 
                flagt = 1; // flagt = 1 means the train is moving
            }
        }
        if (flagt == 1) //train
        {
            p -= 0.1f; // p is the x coordinate of the train
        }
        if (flagw == 1) //wave reverse
        {
            a1 += 0.006; // a1 is the x coordinate of the wave
        }
    }
    glutPostRedisplay();
    glutTimerFunc(100, update, 0);
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //holds depth or distance information for each pixel in the rendering window. 
    //This is used to determine which objects are closer or farther away from the viewer, and is necessary for proper rendering of 3D scenes.
    //color buffer holds the color information for each pixel in the rendering window
    glClearColor(0.0, 0.0, 0.0, 0.0); //glClearColor() is used to set the color that the color buffer will be cleared to when glClear(GL_COLOR_BUFFER_BIT) is called.
    glPushMatrix(); //used to store the matrix transformation state
    glRotatef(20.0, 0.25, 0.5, 0.0); //rotate the object
    track_base_front(); 
    glPopMatrix(); // restore the matrix state

    glPushMatrix(); // used to store the matrix transformation state
    glRotatef(20.0, 0.25, 0.5, 0.0); //rotate the object
    gate_pillar(); 
    glPopMatrix(); // restore the matrix state

    glPushMatrix(); // used to store the matrix transformation state
    glRotatef(20.0, 0.25, 0.5, 0.0); //rotate the object
    track_base(); 
    glPopMatrix(); 

    glPushMatrix();
    glRotatef(20.0, 0.25, 0.5, 0.0);
    rail_track();
    glPopMatrix();

    glPushMatrix(); //bridge
    glRotatef(20.0, 0.25, 0.5, 0.0);
    call1();
    glPopMatrix();

    glPushMatrix(); //ship
    glRotatef(20.0, 0.25, 0.5, 0.0);
    call2();
    glPopMatrix();

    glPushMatrix(); //train
    glRotatef(20.0, 0.25, 0.5, 0.0);
    call3();
    glPopMatrix();

    glPushMatrix(); //waves
    glRotatef(20.0, 0.25, 0.5, 0.0);
    ocean();
    glPopMatrix();

    glPushMatrix();
    glRotatef(20.0, 0.25, 0.5, 0.0);
    call4();
    glPopMatrix();

    glPushMatrix(); //moon
    glColor3f(1.0, 1.0, 1.0);
    glTranslatef(1.2, 0.9, -5.1);
    glutSolidSphere(0.08, 20, 20);
    glPopMatrix();

    glPushMatrix(); //moon Mask //to make it crescent
    glColor3f(0.0, 0.0, 0.0);
    glTranslatef(1.3, 0.95, -5.0);
    glutSolidSphere(0.13, 20, 20);
    glPopMatrix();

    //glPushMatrix();
    stars(); 
    //glPopMatrix();

    glPushMatrix();
    glRotatef(20.0, 0.25, 0.5, 0.0);
    signal();
    glPopMatrix();

    glPushMatrix();
    glRotatef(20.0, 0.25, 0.5, 0.0);
    light();
    glPopMatrix();

    glFlush(); // empties all commands in the buffer and forces all pending commands to be executed immediately
}


void mykeyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 66://B
        flagx = 1;
        break;
    case 98://b
        flagx = 1;
        break;
    case 83:
        flagx = 0;//S
        break;
    case 115:
        flagx = 0;//s
        break;
    default:
        break;
    }
}
///*
void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION); //o set the current matrix mode to the projection matrix mode. The projection matrix is used to specify how a 3D scene is projected onto a 2D surface (such as the screen).
    glLoadIdentity();
    if (w <= h)
        glOrtho(-1.1, 1.1, 1.1 * (GLfloat)h / (GLfloat)w, 1.1 * (GLfloat)h / (GLfloat)w, -10.0, 10.0);
    else
        glOrtho(-1.1 * (GLfloat)w / (GLfloat)h, 1.1 * (GLfloat)w / (GLfloat)h, -1.1, 1.1, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
//*/
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1500, 1000);
    glutCreateWindow("Ship Under Bridge Simulation");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutKeyboardFunc(mykeyboard);
    glutTimerFunc(200, update, 0); // timer function to update the coordinates
    glutMainLoop();
}

``