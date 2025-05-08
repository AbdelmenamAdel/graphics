#include <gl/GL.h>
#ifndef Men3emBreakout_MyObjects_h
#define Men3emBreakout_MyObjects_h

// Ball
struct Ball {
    GLfloat xpos, ypos;
    GLfloat xvel, yvel;
    GLfloat radius;
    GLfloat r, g, b;
};

// Paddle
struct Paddle {
    GLfloat xpos, ypos;
    GLfloat width, height;
    GLfloat r, g, b;
};

// Brick
struct Brick {
    GLfloat xpos, ypos;
    GLfloat width, height;
    GLfloat r, g, b;
    GLfloat health;
    GLfloat value;
};

#endif