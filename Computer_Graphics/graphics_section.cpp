//#define GLUT_DISABLE_ATEXIT_HACK
//#include <cstdlib>
//#include <GL/glut.h>
//#include <vector>
//#include <cmath>
//#include <string>
//
//// Constants
//const int WIDTH = 800, HEIGHT = 600;
//const float PADDLE_WIDTH = 100.0f, PADDLE_HEIGHT = 20.0f;
//const float BALL_RADIUS = 12.0f;
//
//// Structs
//struct GameObject {
//    float x, y, w, h, vx, vy, r, g, b;
//};
//
//// Globals
//std::vector<GameObject> bricks;
//GameObject paddle, ball;
//bool keyLeft = false, keyRight = false;
//int score = 0, level = 1;
//bool gameOver = false;
//float cameraZoom = 1.0f;
//float cameraX = 0.0f, cameraY = 0.0f;
//float dialogAlpha = 0.0f;
//
//void initGame() {
//    paddle = { WIDTH / 2 - PADDLE_WIDTH / 2, 20.0f, PADDLE_WIDTH, PADDLE_HEIGHT, 0, 0, 0.8f, 0.8f, 0.8f };
//    ball = { WIDTH / 2, HEIGHT / 2, BALL_RADIUS * 2, BALL_RADIUS * 2, -2.0f, 3.0f, 1.0f, 1.0f, 1.0f };
//    bricks.clear();
//    for (int y = 0; y < 5; ++y) {
//        for (int x = 0; x < 10; ++x) {
//            bricks.push_back({
//                x * 80.0f + 10.0f, y * 30.0f + 400.0f,
//                70.0f, 25.0f, 0, 0,
//                0.2f + x * 0.08f, 0.3f + y * 0.1f, 0.5f
//                });
//        }
//    }
//    cameraZoom = 1.0f;
//    cameraX = 0.0f;
//    cameraY = 0.0f;
//    dialogAlpha = 0.0f;
//}
//
//void drawRectangle(float x, float y, float w, float h, float r, float g, float b) {
//    glColor4f(r, g, b, 1.0f);
//    glBegin(GL_QUADS);
//    glVertex2f(x, y); glVertex2f(x + w, y);
//    glVertex2f(x + w, y + h); glVertex2f(x, y + h);
//    glEnd();
//}
//
//void drawCircle(float x, float y, float radius, float r, float g, float b) {
//    glColor4f(r, g, b, 1.0f);
//    glBegin(GL_TRIANGLE_FAN);
//    glVertex2f(x, y);
//    for (int i = 0; i <= 360; i += 10) {
//        float angle = i * 3.14159f / 180.0f;
//        glVertex2f(x + cos(angle) * radius, y + sin(angle) * radius);
//    }
//    glEnd();
//}
//
//void displayText(const std::string& text, float x, float y, float alpha = 1.0f) {
//    glColor4f(1.0f, 1.0f, 1.0f, alpha);
//    glRasterPos2f(x, y);
//    for (char c : text) {
//        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
//    }
//}
//
//void updateGame() {
//    if (gameOver) {
//        if (dialogAlpha < 1.0f) dialogAlpha += 0.02f;
//        if (cameraZoom < 1.5f) cameraZoom += 0.02f;
//
//        // Zoom towards Bottom-Left
//        float targetX = 0.0f;
//        float targetY = 0.0f;
//        cameraX += (targetX - cameraX) * 0.1f;
//        cameraY += (targetY - cameraY) * 0.1f;
//    }
//
//    if (!gameOver) {
//        if (keyLeft) paddle.x -= 8.0f;
//        if (keyRight) paddle.x += 8.0f;
//        if (paddle.x < 0) paddle.x = 0;
//        if (paddle.x > WIDTH - PADDLE_WIDTH) paddle.x = WIDTH - PADDLE_WIDTH;
//
//        ball.x += ball.vx;
//        ball.y += ball.vy;
//
//        if (ball.x <= BALL_RADIUS || ball.x >= WIDTH - BALL_RADIUS) ball.vx *= -1;
//        if (ball.y >= HEIGHT - BALL_RADIUS) ball.vy *= -1;
//
//        if (ball.y <= paddle.y + PADDLE_HEIGHT + BALL_RADIUS &&
//            ball.y >= paddle.y &&
//            ball.x >= paddle.x &&
//            ball.x <= paddle.x + PADDLE_WIDTH) {
//            ball.vy = fabs(ball.vy);
//            ball.vx = (ball.x - (paddle.x + PADDLE_WIDTH / 2)) / 10.0f;
//        }
//
//        for (auto& brick : bricks) {
//            if (ball.x >= brick.x && ball.x <= brick.x + brick.w &&
//                ball.y >= brick.y && ball.y <= brick.y + brick.h) {
//                ball.vy *= -1;
//                brick.x = -100;
//                score += 10;
//                break;
//            }
//        }
//
//        bool levelComplete = true;
//        for (const auto& brick : bricks) {
//            if (brick.x >= 0) { levelComplete = false; break; }
//        }
//
//        if (levelComplete) {
//            level++;
//            ball.vx *= 1.1f;
//            ball.vy *= 1.1f;
//            initGame();
//        }
//
//        if (ball.y < -BALL_RADIUS) {
//            gameOver = true;
//        }
//    }
//
//    glutPostRedisplay();
//}
//
//void display() {
//    glClear(GL_COLOR_BUFFER_BIT);
//
//    // Apply camera
//    glLoadIdentity();
//    glTranslatef(cameraX, cameraY, 0.0f);
//    glScalef(cameraZoom, cameraZoom, 1.0f);
//
//    // Draw game objects
//    drawRectangle(paddle.x, paddle.y, paddle.w, paddle.h, paddle.r, paddle.g, paddle.b);
//    drawCircle(ball.x, ball.y, BALL_RADIUS, ball.r, ball.g, ball.b);
//
//    for (const auto& brick : bricks) {
//        if (brick.x >= 0)
//            drawRectangle(brick.x, brick.y, brick.w, brick.h, brick.r, brick.g, brick.b);
//    }
//
//    // Draw HUD (score, level)
//    glLoadIdentity(); // Reset transforms to avoid scaling
//    displayText("Score: " + std::to_string(score), 10, HEIGHT - 30);
//    displayText("Level: " + std::to_string(level), WIDTH - 120, HEIGHT - 30);
//
//    if (gameOver) {
//        displayText("Game Over! Press R to Restart or Q to Quit.", WIDTH / 4, HEIGHT / 2, dialogAlpha);
//    }
//
//    glutSwapBuffers();
//}
//
//void keyboard(unsigned char key, int x, int y) {
//    if (key == 27) std::exit(0);
//    if (key == 'r' || key == 'R') {
//        gameOver = false;
//        score = 0;
//        level = 1;
//        initGame();
//    }
//    if (key == 'q' || key == 'Q') std::exit(0);
//}
//
//void specialKeys(int key, int x, int y) {
//    if (key == GLUT_KEY_LEFT) keyLeft = true;
//    if (key == GLUT_KEY_RIGHT) keyRight = true;
//}
//
//void specialKeysUp(int key, int x, int y) {
//    if (key == GLUT_KEY_LEFT) keyLeft = false;
//    if (key == GLUT_KEY_RIGHT) keyRight = false;
//}
//
//void timer(int value) {
//    updateGame();
//    glutTimerFunc(16, timer, 0);
//}
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//    glutInitWindowSize(WIDTH, HEIGHT);
//    glutCreateWindow("Breakout (GLUT)");
//
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(0, WIDTH, 0, HEIGHT);
//    glMatrixMode(GL_MODELVIEW);
//
//    initGame();
//
//    glutDisplayFunc(display);
//    glutKeyboardFunc(keyboard);
//    glutSpecialFunc(specialKeys);
//    glutSpecialUpFunc(specialKeysUp);
//    glutTimerFunc(0, timer, 0);
//
//    glutMainLoop();
//    return 0;
//}
