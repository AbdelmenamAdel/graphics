//#include<Windows.h>
//#include<iostream>
//#include<gl/glut.h>
//#define STB_IMAGE_IMPLEMENTATION
//#include<gl/stb_image.h>
//// Make sure to have stb_image.h in your project
//using namespace std;
//
//float width, height;
//bool fullScreen;
//float ratio, a1 = 0.0f, a2 = 0.0f;
//float cameraX = 0.0f, cameraY = 0.0f, cameraZ = -7.0f;
//float cameraSpeed = 0.1f;
//
//// Rotation control variables
//bool rotateX = false;         // Toggle for X-axis rotation
//bool stopAllRotation = false; // Toggle to stop all rotation
//float xRotAngle = 0.0f;       // Current X rotation angle
//float xRotSpeed = 1.0f;       // X rotation speed
//
//// Texture variables
//GLuint textureID;
//
//void background();
//void mydraw();
//void reshape(int, int);
//void timer(int);
//void keyboard(unsigned char, int, int);
//void specialKeyboard(int, int, int);
//void mouse(int, int, int, int);
//void loadTexture();
//void drawTexturedQuad();
//
//int main(int argc, char** argv) {
//    width = GetSystemMetrics(SM_CXSCREEN);
//    height = GetSystemMetrics(SM_CYSCREEN);
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
//    glutInitWindowSize(width, height);
//    glutCreateWindow("3D Shapes with Textures");
//
//    loadTexture();  // Load texture before initialization
//    background();
//
//    glutDisplayFunc(mydraw);
//    glutReshapeFunc(reshape);
//    glutTimerFunc(0, timer, 0);
//    glutKeyboardFunc(keyboard);
//    glutSpecialFunc(specialKeyboard);
//    glutMouseFunc(mouse);
//
//    glutMainLoop();
//    return 0;
//}
//
//void loadTexture() {
//    int width, height, channels;
//    unsigned char* image = stbi_load("bg_image.png", &width, &height, &channels, STBI_rgb_alpha);
//
//    if (!image) {
//        cerr << "Failed to load texture image!" << endl;
//        exit(1);
//    }
//
//    glGenTextures(1, &textureID);
//    glBindTexture(GL_TEXTURE_2D, textureID);
//
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
//    stbi_image_free(image);
//}
//
//void drawTexturedQuad() {
//    glBegin(GL_QUADS);
//    glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, -0.5f, 0.0f);
//    glTexCoord2f(1.0f, 0.0f); glVertex3f(0.5f, -0.5f, 0.0f);
//    glTexCoord2f(1.0f, 1.0f); glVertex3f(0.5f, 0.5f, 0.0f);
//    glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f, 0.5f, 0.0f);
//    glEnd();
//}
//
//void background() {
//    glClearColor(0, 0, 0, 0);
//    glEnable(GL_DEPTH_TEST);
//    glEnable(GL_TEXTURE_2D);
//}
//
//
//void mydraw() {
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    glLoadIdentity();
//    glBindTexture(GL_TEXTURE_2D, textureID);
//    glTranslatef(cameraX, cameraY, cameraZ);
//
//    // Apply X-axis rotation if enabled
//    if (rotateX) {
//        glRotatef(xRotAngle, 1.0f, 0.0f, 0.0f);
//    }
//
//    // CENTER QUAD (rotates around its center)
//    glPushMatrix();
//    if (!stopAllRotation) {
//        glRotatef(a1, 0, 0, 1); // Rotate center first
//    }
//    // Draw center quad (blue)
//    glBegin(GL_QUADS);
//    glColor3f(1, 1, 1);
//    glTexCoord2d(0, 0);
//    glVertex3f(-0.5, -0.5, 0);
//    glTexCoord3d(1, 0, 0);
//    glVertex3f(0.5, -0.5, 0);
//    glTexCoord3d(1, 1, 0);
//    glVertex3f(0.5, 0.5, 0);
//    glTexCoord3d(0, 1, 0);
//    glVertex3f(-0.5, 0.5, 0);
//    glEnd();
//
//    // TOP-RIGHT QUAD (rotates around center's corner)
//    glPushMatrix();
//    glTranslatef(0.5, 0.5, 0); // Move to center's corner
//    if (!stopAllRotation) {
//        glRotatef(a2, 0, 0, 1); // Local rotation
//    }
//    glTranslatef(0.5, 0.5, 0); // Offset to draw quad
//
//    glBegin(GL_QUADS);
//    glColor3f(1, 1, 1);
//    glTexCoord2d(0, 0);
//    glVertex3f(-0.5, -0.5, 0);
//    glTexCoord2d(1, 0);
//    glVertex3f(0.5, -0.5, 0);
//    glTexCoord2d(1, 1);
//    glVertex3f(0.5, 0.5, 0);
//    glTexCoord2d(0, 1);
//    glVertex3f(-0.5, 0.5, 0);
//    glEnd();
//    glPopMatrix();
//
//    // TOP-LEFT QUAD
//    glPushMatrix();
//    glTranslatef(-0.5, 0.5, 0);
//    if (!stopAllRotation) {
//        glRotatef(a2, 0, 0, 1);
//    }
//    glTranslatef(-0.5, 0.5, 0);
//
//    glBegin(GL_QUADS);
//    glColor3f(1, 1, 1);
//    glTexCoord3d(0, 0, 0);
//    glVertex3f(-1, 1, 0);//
//    glTexCoord3d(1, 0, 0);
//    glVertex3f(-0.5, 1, 0);//
//    glTexCoord3d(1, 1, 0);
//    glVertex3f(-.5, 1.5, 0);//
//    glTexCoord3d(0, 1, 0);
//    glVertex3f(-1, 1.5, 0);//
//    glEnd();
//    glPopMatrix();
//
//    // BOTTOM-RIGHT QUAD
//    glPushMatrix();
//    glTranslatef(0.5, -0.5, 0);
//    if (!stopAllRotation) {
//        glRotatef(a2, 0, 0, 1);
//    }
//    glTranslatef(0.5, -0.5, 0);
//
//    glBegin(GL_QUADS);
//    glColor3f(1, 1, 1);
//    glTexCoord3d(0, 0, 0);
//    glVertex3f(-0.5, -0.5, 0);
//    glTexCoord3d(1, 0, 0);
//    glVertex3f(0.5, -0.5, 0);
//    glTexCoord3d(1, 1, 0);
//    glVertex3f(0.5, 0.5, 0);
//    glTexCoord3d(0, 1, 0);
//    glVertex3f(-0.5, 0.5, 0);
//    glEnd();
//    glPopMatrix();
//
//    // BOTTOM-LEFT QUAD
//    glPushMatrix();
//    glTranslatef(-0.5, -0.5, 0);
//    if (!stopAllRotation) {
//        glRotatef(a2, 0, 0, 1);
//    }
//    glTranslatef(-0.5, -0.5, 0);
//
//    glBegin(GL_QUADS);
//    glColor3f(1, 1, 1);
//    glTexCoord3d(0, 0, 0);
//    glVertex3f(-0.5, -0.5, 0);
//    glTexCoord3d(1, 0, 0);
//    glVertex3f(0.5, -0.5, 0);
//    glTexCoord3d(1, 1, 0);
//    glVertex3f(0.5, 0.5, 0);
//    glTexCoord3d(0, 1, 0);
//    glVertex3f(-0.5, 0.5, 0);
//    glEnd();
//    glPopMatrix();
//
//    glPopMatrix(); // Pop center rotation
//    glutSwapBuffers();
//}
//
//
//void reshape(int w, int h) {
//    if (h == 0) h = 1;
//    ratio = w / (float)h;
//    glViewport(0, 0, w, h);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluPerspective(45, ratio, 1, 100);
//    glMatrixMode(GL_MODELVIEW);
//}
//
//void timer(int v) {
//    if (!stopAllRotation) {
//        a1 += 1.0f; // Rotation speed for center quad
//        a2 += 2.0f; // Rotation speed for surrounding quads
//
//        if (a1 > 360) a1 -= 360;
//        if (a2 > 360) a2 -= 360;
//    }
//
//    if (rotateX) {
//        xRotAngle += xRotSpeed;
//        if (xRotAngle > 360) xRotAngle -= 360;
//    }
//
//    glutPostRedisplay();
//    glutTimerFunc(16, timer, 0);
//}
//
//void keyboard(unsigned char key, int x, int y) {
//    switch (key) {
//    case 27: exit(0); break; // ESC
//    case '+': cameraZ += cameraSpeed; break;
//    case '-': cameraZ -= cameraSpeed; break;
//    case 'r': case 'R':
//        rotateX = !rotateX; // Toggle X rotation
//        break;
//    case 's': case 'S':
//        stopAllRotation = !stopAllRotation; // Toggle all rotation
//        break;
//    }
//}
//
//void specialKeyboard(int key, int x, int y) {
//    if (key == GLUT_KEY_F1) {
//        fullScreen = !fullScreen;
//        if (fullScreen)
//            glutFullScreen();
//        else {
//            glutPositionWindow(10, 10);
//            glutReshapeWindow(600, 600);
//        }
//    }
//
//    if (key == GLUT_KEY_UP) cameraY += cameraSpeed;
//    if (key == GLUT_KEY_DOWN) cameraY -= cameraSpeed;
//    if (key == GLUT_KEY_LEFT) cameraX -= cameraSpeed;
//    if (key == GLUT_KEY_RIGHT) cameraX += cameraSpeed;
//}
//
//void mouse(int button, int state, int x, int y) {
//    stopAllRotation = !stopAllRotation;
//
//    cout << (int)(((x - (width / 2)) * 100) / (width / 2))
//        << endl <<
//        (int)((((height / 2) - y) * 100) / (height / 2)) << "\n\\\\\\\\\\\\\\\\\\" << "\n";
//}
