//#include <GL/glut.h>
//#include <math.h>
//
//// Constants
//const float PI = 3.14159265358979323846;
//
//// Colors
//const float GOLD[] = { 0.9f, 0.7f, 0.2f };
//const float ORANGE[] = { 1.0f, 0.5f, 0.0f };
//const float YELLOW[] = { 1.0f, 0.9f, 0.0f };
//const float LIGHT_YELLOW[] = { 1.0f, 1.0f, 0.8f };
//const float NIGHT_SKY[] = { 0.0f, 0.0f, 0.3f };
// float r=0, g=0, b=0;
//// Global Variables
//float xp = 0.0f, yp = 0.0f;
//float Width = 10.0f, Height = 10.0f;
//float speedx = 0.1f, speedy = 0.1f;
////window mode
//int windowWidth = 700;
//int windowHeight = 700;
//int windowPosX = 50;
//int windowPosY = 50;
//
////projection clipping area
//double Right, Top;
//bool pause = false;
//bool fullScreen = true;
//float xSpeedSaved, ySpeedSaved;
//// speed ?
//float xSpeed = 0.03;	//ball speed
//float ySpeed = 0.003;
//// Background Gradient
///*
//void backgroundColor() {
//    glBegin(GL_QUADS);
//    glColor3f(NIGHT_SKY[0], NIGHT_SKY[1], NIGHT_SKY[2]);
//    glVertex2f(-1.0f, -1.0f);
//    glColor3f(0.2f, 0.2f, 0.8f);
//    glVertex2f(1.0f, -1.0f);
//    glColor3f(0.6f, 0.0f, 0.6f);
//    glVertex2f(1.0f, 1.0f);
//    glColor3f(0.3f, 0.0f, 0.5f);
//    glVertex2f(-1.0f, 1.0f);
//    glEnd();
//}
//*/
//// Timer Function
//void timer(int v) {
//    xp += speedx;
//    yp += speedy;
//
//    // Approximate half-dimensions of the lantern
//    float halfLanternWidth = 2.3f;   // widest part at the triangle top
//    float halfLanternHeight = 4.3f + 1.1f; // top of crescent
//
//    bool hitx = false, hity = false;
//
//    // Check horizontal boundaries
//    if (xp + halfLanternWidth > Width || xp - halfLanternWidth < -Width) {
//        speedx = -speedx;
//        hitx = true;
//    }
//
//    // Check vertical boundaries
//    if (yp + halfLanternHeight > Height || yp - 4 < -Height) {  // -4 is bottom of lantern base
//        speedy = -speedy;
//        hity = true;
//    }
//
//    // Color changes on hit
//    if (hity) {
//        r = 0.2f;
//        g = 0.3f;
//        b = 0.5f;
//    }
//    if (hitx) {
//        r = 0.1f;
//        g = 0.4f;
//        b = 0.3f;
//    }
//
//    glutPostRedisplay();
//    glutTimerFunc(1000 / 60, timer, 0); // ~60 FPS
//}
//
//// Reshape Function
//void reshape(int w, int h) {
//    if (h == 0) h = 1;
//    float aspect = (float)w / h;
//
//    glViewport(0, 0, w, h);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//
//    if (w >= h) {
//        gluOrtho2D(-10.0 * aspect, 10.0 * aspect, -10.0, 10.0);
//        Width = 10.0 * aspect;
//        Height = 10.0;
//    }
//    else {
//        gluOrtho2D(-10.0, 10.0, -10.0 / aspect, 10.0 / aspect);
//        Width = 10.0;
//        Height = 10.0 / aspect;
//    }
//
//    glMatrixMode(GL_MODELVIEW);
//}
//
//// Function to Draw a Circle
//void circle(float cx, float cy, float radius, int segments = 50) {
//    glBegin(GL_POLYGON);
//    for (int i = 0; i < segments; i++) {
//        float theta = 2.0f * PI * i / segments;
//        float x = radius * cos(theta);
//        float y = radius * sin(theta);
//        glVertex2f(cx + x, cy + y);
//    }
//    glEnd();
//}
//
//// Crescent Moon Shape
//void drawCrescentMoon(float cx, float cy, float outerRadius, float innerRadius, int segments = 100) {
//   // Outer Circle
//    glColor3f(LIGHT_YELLOW[0], LIGHT_YELLOW[1], LIGHT_YELLOW[2]);
//    glBegin(GL_TRIANGLE_FAN);
//    for (int i = 0; i <= segments; i++) {
//        float angle = 2.0f * PI * i / segments;
//        glVertex2f(cx + outerRadius * cos(angle), cy + outerRadius * sin(angle));
//    }
//    glEnd();
//    // Inner Circle
//    // Cutout for Crescent Effect
//    //NIGHT_SKY[0], NIGHT_SKY[1], NIGHT_SKY[2]
//    glColor3f(r,g,b);
//    glBegin(GL_TRIANGLE_FAN);
//    for (int i = 0; i <= segments; i++) {
//        float angle = 2.0f * PI * i / segments;
//        glVertex2f(cx + innerRadius * cos(angle) + 0.3f, cy + innerRadius * sin(angle) + 0.2f);
//    }
//    glEnd();
//}
//
//// Lantern Design
//void drawLantern() {
//    glClearColor(r, g, b, 1.0);
//    glClear(GL_COLOR_BUFFER_BIT);
//    glLoadIdentity();
//    //backgroundColor();
//
//    // Lantern Base
//    glColor3f(GOLD[0], GOLD[1], GOLD[2]);
//    glBegin(GL_QUADS);
//    glVertex2f(-2 + xp, -4 + yp);
//    glVertex2f(2 + xp, -4 + yp);
//    glVertex2f(1.5f + xp, -3 + yp);
//    glVertex2f(-1.5f + xp, -3 + yp);
//    glEnd();
//
//    // Lantern Body
//    glBegin(GL_QUADS);
//    glColor3f(ORANGE[0], ORANGE[1], ORANGE[2]);
//    glVertex2f(-1.5f + xp, -3 + yp);
//    glVertex2f(1.5 + xp, -3 + yp);
//    glColor3f(YELLOW[0], YELLOW[1], YELLOW[2]);
//    glVertex2f(2 + xp, 1.5f + yp);
//    glVertex2f(-2 + xp, 1.5f + yp);
//    glEnd();
//
//    // Light Source (Glowing Effect)
//    glColor3f(1.0f, 1.0f, 0.2f);
//    circle(0.0f + xp, -1.5 + yp, 1, 100);
//
//    // Lantern Top
//    glColor3f(GOLD[0], GOLD[1], GOLD[2]);
//    glBegin(GL_TRIANGLES);
//    glVertex2f(-2.3 + xp, 1.5f + yp);
//    glVertex2f(2.3 + xp, 1.5f + yp);
//    glVertex2f(0.0f + xp, 3.5f + yp);
//    glEnd();
//
//    // Crescent Moon (Helal)
//    drawCrescentMoon(0.09f + xp, 4.3 + yp, 1.1f, 1.0f, 100);
//
//    glFlush();
//}
//
//// Initialization
//void init() {
//    glClearColor(0.0, 0.0, 0.0, 1.0); // Black background
//    glShadeModel(GL_SMOOTH); // Smooth shading
//}
//
//void keyboard(unsigned char key, int x, int y)
//{
//    switch (key)
//    {
//    case 27:    // ESC key : exit
//        exit(0);
//        break;
//
//    case ' ':   // Space bar: toggle pause
//        pause = !pause;
//        if (pause) {
//            xSpeedSaved = speedx;
//            ySpeedSaved = speedy;
//            speedx = 0;
//            speedy = 0;
//        }
//        else {
//            speedx = xSpeedSaved;
//            speedy = ySpeedSaved;
//        }
//        break;
//
//        // Movement - WASD
//    case 'w': yp += 0.2f; break;
//    case 's': yp -= 0.2f; break;
//    case 'a': xp -= 0.2f; break;
//    case 'd': xp += 0.2f; break;
//
//        // Movement - JKIL
//    case 'i': yp += 0.2f; break;
//    case 'k': yp -= 0.2f; break;
//    case 'j': xp -= 0.2f; break;
//    case 'l': xp += 0.2f; break;
//    }
//}
//void specialKeys(int key, int x, int y)
//{
//    switch (key)
//    {
//    case GLUT_KEY_F1:
//        fullScreen = !fullScreen;
//        if (fullScreen) {
//            windowPosX = glutGet(GLUT_WINDOW_X);
//            windowPosY = glutGet(GLUT_WINDOW_Y);
//            windowWidth = glutGet(GLUT_WINDOW_WIDTH);
//            windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
//            glutFullScreen();
//        }
//        else {
//            glutReshapeWindow(windowWidth, windowHeight);
//            glutPositionWindow(windowPosX, windowPosY);
//        }
//        break;
//
//        // Move lantern manually using arrows
//    case GLUT_KEY_RIGHT: xp += 0.2f; break;
//    case GLUT_KEY_LEFT:  xp -= 0.2f; break;
//    case GLUT_KEY_UP:    yp += 0.2f; break;
//    case GLUT_KEY_DOWN:  yp -= 0.2f; break;
//    case GLUT_KEY_PAGE_UP:   // Page Up: increase both speeds
//        speedx *= 1.2f;
//        speedy *= 1.2f;
//        break;
//
//    case GLUT_KEY_PAGE_DOWN: // Page Down: decrease both speeds
//        speedx *= 0.8f;
//        speedy *= 0.8f;
//        break;
//    }
//}
//void mouse(int button, int state, int x, int y)
//{
//    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
//    {
//        pause = !pause;
//        if (pause)
//        {
//            xSpeedSaved = speedx;
//            ySpeedSaved = speedy;
//            speedx = 0;
//            speedy = 0;
//        }
//        else
//        {
//            speedx = xSpeedSaved;
//            speedy = ySpeedSaved;
//        }
//    }
//}
//
//// Main Function
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowPosition(windowPosX, windowPosY);
//    glutInitWindowSize(windowWidth, windowHeight);
//
//    glutCreateWindow("Colorful Lantern with Crescent");
//        
//    init();
//    glutDisplayFunc(drawLantern);
//    glutReshapeFunc(reshape);
//    glutTimerFunc(0, timer, 0);
//    glutSpecialFunc(specialKeys);
//    glutKeyboardFunc(keyboard);
//    glutFullScreen();
//    glutMouseFunc(mouse);
//    glutMainLoop();
//
//    return 0;
//}
