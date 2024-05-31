#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>
#include <math.h>

void init(void)
{
    glClearColor(0.69, 0.99, 0.89, 0.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glOrtho(.0, 150.0, -0.0, 150.0, -1.0, 1.0);

}
float X = 30, Y = 60, Xm = 3, Ym = 3, tx = 0, ty = 0, tyS = 0;
int countclick = 0;
float w1R = .87, w1G = .87, w1B = .87,// bim color AB4
b1R = 0.0, b1G = 0.0, b1B = 0.0,//glass color of AB4
skBR = 0.13, skBG = 0.13, skBB = 0.13,
roadR = .25, roadG = .25, roadB = .25,
grassR = .0, grassG = .4, grassB = .0,
orangeR = .8, orangeG = .4, orangeB = .0;







//bus
void bus() {
    glPushMatrix();
    glTranslatef(tx, ty, 0);
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex2f(X + Xm * 20, Y + Ym * -0.5);
    glVertex2f(X + Xm * 24, Y + Ym * -0.5);
    glVertex2f(X + Xm * 24, Y + Ym * -2);
    glVertex2f(X + Xm * 20, Y + Ym * -2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex2f(X + Xm * 20.1, Y + Ym * -0.6);
    glVertex2f(X + Xm * 23.9, Y + Ym * -0.6);
    glVertex2f(X + Xm * 23.9, Y + Ym * -1.5);
    glVertex2f(X + Xm * 20.1, Y + Ym * -1.5);
    glEnd();


    float theta, r = 1.2;

    glColor3f(.0, .0, .0);
    glBegin(GL_POLYGON);
    for (int i = 0;i < 360;i++) {
        theta = i * 3.1416 / 180;
        glVertex2f(X + Xm * 23 + r * cos(theta), Y + Ym * -2 + r * sin(theta));
    }
    glEnd();

    glBegin(GL_POLYGON);
    for (int i = 0;i < 360;i++) {
        theta = i * 3.1416 / 180;
        glVertex2f(X + Xm * 21 + r * cos(theta), Y + Ym * -2 + r * sin(theta));
    }
    glEnd();

    glPopMatrix();
}


void renderbitmap(float x, float y, void* font, char* string) {
    char* c;
    glRasterPos2d(x, y);
    for (c = string;*c != '\0';c++) {
        glutBitmapCharacter(font, *c);
    }
}
void text() {
    glColor3f(0.0, 0.0, 0.0);
    char buf[100] = { 0 };
    sprintf_s(buf, "Day => Press up arrow ");
    renderbitmap(125, 30, GLUT_BITMAP_TIMES_ROMAN_24, buf);
    sprintf_s(buf, "Night => Press down arrow ");
    renderbitmap(125, 35, GLUT_BITMAP_TIMES_ROMAN_24, buf);


}

void square(float x1, float y1, float height, float width) {
    glBegin(GL_POLYGON);
    glVertex2f(x1, y1);
    glVertex2f(x1 + width, y1);
    glVertex2f(x1 + width, y1 + height);
    glVertex2f(x1, y1 + height);
    glEnd();
}
void DrawFilledCircle(float cx, float cy, float r, int num_segments) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy); // Center of the circle
    for (int ii = 0; ii <= num_segments; ii++) {
        float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}

void drawLine(float x1, float y1, float x2, float y2) {
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}

//sky
float sunX = 100.0f; // Initial sun position (x-axis)
float sunY = 140.0f;  // Initial sun position (y-axis)
float sunRadius = 5.0f; // Sun radius

// Define colors for day and night
float dayR = 0.72f, dayG = 0.9f, dayB = 0.99f; // Daytime sky color
float nightR = 0.0f, nightG = 0.0f, nightB = 0.1f; // Nighttime sky color

void drawSun() {
    glColor3f(1.0f, 1.0f, 0.0f); // Yellow color for the sun
    DrawFilledCircle(sunX, sunY, sunRadius, 100);
}

void drawSky() {
    // Interpolate between day and night colors based on sun position
    float t = (sunY - 100.0f) / 45.0f; // Normalize sun position
    float skyR = (1.0f - t) * nightR + t * dayR;
    float skyG = (1.0f - t) * nightG + t * dayG;
    float skyB = (1.0f - t) * nightB + t * dayB;

    glColor3f(skyR, skyG, skyB); // Set the sky color
    square(0, 0, 150, 200); // Adjust the sky dimensions as needed
}

void keyPress(int key, int x, int y) {
    const float sunSpeed = 1.0f; // Adjust the sun movement speed
    if (key == GLUT_KEY_UP)
        sunY += sunSpeed; // Move the sun up (rise)
    else if (key == GLUT_KEY_DOWN && sunY > 45)
        sunY -= sunSpeed; // Move the sun down (set)
    glutPostRedisplay();
}





struct Cloud {
    float x; // Cloud position (x-axis)
    float y; // Cloud position (y-axis)
    float speed; // Cloud speed
};

Cloud myCloud1, myCloud3, myCloud2, myCloud4; // Define a cloud

void cloud(float x, float y) {

    glColor3f(1.0, 1.0, 1.0);
    DrawFilledCircle(x, y, 3, 100);
    DrawFilledCircle(x + 2.5, y, 3, 100);
    DrawFilledCircle(x - 2.5, y, 3, 100);
    DrawFilledCircle(x + 1.5, y + 2.5, 3, 100);
}
struct Car {
    float x; // Car position (x-axis)
    float y; // Car position (y-axis)
    float speed; // Car speed
};

Car car1, car2, car3; // Define three cars

void drawCar(float x, float y) {
    // Draw the car body
     // Red color
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + 10.0f, y);
    glVertex2f(x + 10.0f, y + 6.0f);
    glVertex2f(x, y + 6.0f);
    glEnd();

    glColor3f(0.f, 0.f, 0.f); // Black color
    glBegin(GL_QUADS);
    glVertex2f(x + 0.9f, y + 3.0f);
    glVertex2f(x + 10.0f - 0.9f, y + 3.0f);
    glVertex2f(x + 10.0f - 0.9f, y + 5.0f);
    glVertex2f(x + 0.9f, y + 5.0f);
    glEnd();

    // Draw the wheels
    glColor3f(0.0f, 0.0f, 0.0f); // Black color
    DrawFilledCircle(x + 2, y, 1.5, 100);
    DrawFilledCircle(x + 8, y, 1.5, 100);
}




void update(int value) {
    // Move each car to the right
    car1.x += car1.speed;
    car2.x += car2.speed;
    car3.x -= car3.speed; // Move the third car in the opposite direction
    myCloud1.x += myCloud1.speed;
    myCloud2.x += myCloud2.speed;
    myCloud3.x += myCloud3.speed;
    myCloud4.x += myCloud4.speed;

    if (car1.x > 200.0f)
        car1.x = -10.0f;
    if (car2.x > 200.0f)
        car2.x = -10.0f;
    if (car3.x < -10.0f)
        car3.x = 200.0f;

    if (myCloud1.x > 200.0f)
        myCloud1.x = -10.0f;
    if (myCloud2.x > 200.0f)
        myCloud2.x = -10.0f;
    if (myCloud3.x > 200.0f)
        myCloud3.x = 10.0f;
    if (myCloud4.x > 200.0f)
        myCloud4.x = 10.0f;


    // Update bird positions and wing angles

    glutPostRedisplay();
    glutTimerFunc(16, update, 0); // 60 FPS
}


void Draw()
{

    glClear(GL_COLOR_BUFFER_BIT);



    drawSky();
    drawSun();

    cloud(myCloud1.x, 45 + 70);
    cloud(myCloud2.x, 45 + 76);
    cloud(myCloud3.x, 45 + 68);
    cloud(myCloud4.x, 45 + 80);

    //////TREE TOP START///////
    for (int x = 0; x < 150; x += 10) {
        float y = 25;
        glColor3f(0.24, .38, 0.07);
        glBegin(GL_POLYGON);
        glVertex2f(x, y + 50);
        glVertex2f(x + 10, y + 50);
        glVertex2f(x + 5, y + 60);
        glEnd();

    }
    //////GRASS TOP START///////
    float y = 25;

    glBegin(GL_POLYGON);
    glColor3f(0.24, .38, 0.07);
    glVertex2f(0, 45 + y + 6);
    glVertex2f(200, 45 + y + 6);
    glVertex2f(200, 45 + y + 5);
    glVertex2f(0, 45 + y + 5);

    glEnd();
    //////TREE TOP END///////



    //grass
    glBegin(GL_POLYGON);
    glColor3f(grassR, grassG, grassB);
    glVertex2f(X + Xm * -40, Y + Ym * 5);
    glVertex2f(X + Xm * 50, Y + Ym * 5);
    glVertex2f(X + Xm * 50, Y + Ym * -50);
    glVertex2f(X + Xm * -40, Y + Ym * -50);
    glEnd();


    //road

    glBegin(GL_POLYGON);
    glColor3f(roadR, roadG, roadB);
    glVertex2f(X + Xm * -40, Y + Ym * -1.2);
    glVertex2f(X + Xm * 40, Y + Ym * -1.2);
    glVertex2f(X + Xm * 40, Y + Ym * -5);
    glVertex2f(X + Xm * -40, Y + Ym * -5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(roadR, roadG, roadB);
    glVertex2f(X + Xm * 29, Y + Ym * -1.2);
    glVertex2f(X + Xm * 37, Y + Ym * -30);
    glVertex2f(X + Xm * 30, Y + Ym * -30);
    glVertex2f(X + Xm * 25, Y + Ym * -3);
    glEnd();


    //right
    glColor3f(b1R, b1G, b1B);
    glBegin(GL_POLYGON);
    glVertex2f(X + Xm * 18, Y + Ym * 15);
    glVertex2f(X + Xm * 28, Y + Ym * 18);
    glVertex2f(X + Xm * 28, Y + Ym * 2);
    glVertex2f(X + Xm * 18, Y + Ym * 3);
    glEnd();


    //imput all code here
    //support beams
    //horizontal start
    glColor3f(w1R, w1G, w1B);

    glLineWidth((GLfloat)4);
    for (float y1 = 15, y2 = 18; y1 > 6.5; y1 -= .5, y2--) {
        drawLine(X + Xm * 18, Y + Ym * y1, X + Xm * 28, Y + Ym * y2);

    }
    glBegin(GL_LINES);

    // horizontal end

    //vertical start

    glVertex2f(X + Xm * 28, Y + Ym * 18);
    glVertex2f(X + Xm * 28, Y + Ym * 2);

    glVertex2f(X + Xm * 26, Y + Ym * 17.3);
    glVertex2f(X + Xm * 26, Y + Ym * 2.5);

    glVertex2f(X + Xm * 24, Y + Ym * 16.7);
    glVertex2f(X + Xm * 24, Y + Ym * 2.65);

    glVertex2f(X + Xm * 22, Y + Ym * 16.2);
    glVertex2f(X + Xm * 22, Y + Ym * 3);

    glVertex2f(X + Xm * 20, Y + Ym * 15.5);
    glVertex2f(X + Xm * 20, Y + Ym * 3.4);

    glVertex2f(X + Xm * 18, Y + Ym * 15);
    glVertex2f(X + Xm * 18, Y + Ym * 3.4);
    //vertical end



    glEnd();


    //right side
    glColor3f(b1R, b1G, b1B);
    glBegin(GL_POLYGON);
    glVertex2f(X + Xm * 28, Y + Ym * 18);
    glVertex2f(X + Xm * 33, Y + Ym * 17);
    glVertex2f(X + Xm * 33, Y + Ym * 4);
    glVertex2f(X + Xm * 28, Y + Ym * 2);
    glEnd();

    //support beam
    //horizontal start
    glColor3f(w1R, w1G, w1B);
    glLineWidth((GLfloat)4);
    glBegin(GL_LINES);
    glVertex2f(X + Xm * 28, Y + Ym * 18);
    glVertex2f(X + Xm * 33, Y + Ym * 17);

    glVertex2f(X + Xm * 28, Y + Ym * 17);
    glVertex2f(X + Xm * 33, Y + Ym * 16.19);

    glVertex2f(X + Xm * 28, Y + Ym * 16);
    glVertex2f(X + Xm * 33, Y + Ym * 15.4);

    glVertex2f(X + Xm * 28, Y + Ym * 15);
    glVertex2f(X + Xm * 33, Y + Ym * 14.3);

    glVertex2f(X + Xm * 28, Y + Ym * 14);
    glVertex2f(X + Xm * 33, Y + Ym * 13.6);

    glVertex2f(X + Xm * 28, Y + Ym * 13);
    glVertex2f(X + Xm * 33, Y + Ym * 12.8);

    glVertex2f(X + Xm * 28, Y + Ym * 12);
    glVertex2f(X + Xm * 33, Y + Ym * 12);

    glVertex2f(X + Xm * 28, Y + Ym * 11);
    glVertex2f(X + Xm * 33, Y + Ym * 11.23);

    glVertex2f(X + Xm * 28, Y + Ym * 10);
    glVertex2f(X + Xm * 33, Y + Ym * 10.4);

    glVertex2f(X + Xm * 28, Y + Ym * 9);
    glVertex2f(X + Xm * 33, Y + Ym * 9.6);

    glVertex2f(X + Xm * 28, Y + Ym * 8);
    glVertex2f(X + Xm * 33, Y + Ym * 8.7);

    glVertex2f(X + Xm * 28, Y + Ym * 7);
    glVertex2f(X + Xm * 33, Y + Ym * 7.9);

    glVertex2f(X + Xm * 28, Y + Ym * 6);
    glVertex2f(X + Xm * 33, Y + Ym * 7.22);

    glVertex2f(X + Xm * 28, Y + Ym * 5);
    glVertex2f(X + Xm * 33, Y + Ym * 6.4);

    glVertex2f(X + Xm * 28, Y + Ym * 4);
    glVertex2f(X + Xm * 33, Y + Ym * 5.7);

    glVertex2f(X + Xm * 28, Y + Ym * 3);
    glVertex2f(X + Xm * 33, Y + Ym * 4.9);

    glVertex2f(X + Xm * 28, Y + Ym * 2);
    glVertex2f(X + Xm * 33, Y + Ym * 4);


    glVertex2f(X + Xm * 33, Y + Ym * 17);
    glVertex2f(X + Xm * 33, Y + Ym * 4);

    glEnd();


    //left

    glColor3f(b1R, b1G, b1B);
    glBegin(GL_POLYGON);
    glVertex2f(X + Xm * 4, Y + Ym * 14);
    glVertex2f(X + Xm * 4, Y + Ym * 2);
    glVertex2f(X + Xm * 20, Y + Ym * 2);
    glVertex2f(X + Xm * 20, Y + Ym * 14);
    glEnd();
    //support beam
    //vertical
    glColor3f(w1R, w1G, w1B);
    glLineWidth((GLfloat)4);
    for (float y1 = 14; y1 > 1; y1 -= 1) {
        drawLine(X + Xm * 4, Y + Ym * y1, X + Xm * 20, Y + Ym * y1);

    }


    //Horizontal
    glColor3f(w1R, w1G, w1B);
    glLineWidth((GLfloat)4);
    glBegin(GL_LINES);
    glVertex2f(X + Xm * 4, Y + Ym * 14);
    glVertex2f(X + Xm * 4, Y + Ym * 2);

    glVertex2f(X + Xm * 6, Y + Ym * 14);
    glVertex2f(X + Xm * 6, Y + Ym * 2);

    glVertex2f(X + Xm * 8, Y + Ym * 14);
    glVertex2f(X + Xm * 8, Y + Ym * 2);

    glVertex2f(X + Xm * 10, Y + Ym * 14);
    glVertex2f(X + Xm * 10, Y + Ym * 2);

    glVertex2f(X + Xm * 12, Y + Ym * 14);
    glVertex2f(X + Xm * 12, Y + Ym * 2);

    glVertex2f(X + Xm * 14, Y + Ym * 14);
    glVertex2f(X + Xm * 14, Y + Ym * 2);

    glVertex2f(X + Xm * 16, Y + Ym * 14);
    glVertex2f(X + Xm * 16, Y + Ym * 2);

    glVertex2f(X + Xm * 18, Y + Ym * 14);
    glVertex2f(X + Xm * 18, Y + Ym * 2);
    glEnd();

    //front
    glColor3f(b1R, b1G, b1B);
    glBegin(GL_POLYGON);
    glVertex2f(X + Xm * 12, Y + Ym * 9);
    glVertex2f(X + Xm * 13, Y + Ym * 9.16);
    glVertex2f(X + Xm * 14, Y + Ym * 9.32);
    glVertex2f(X + Xm * 15, Y + Ym * 9.48);
    glVertex2f(X + Xm * 16, Y + Ym * 9.64);
    glVertex2f(X + Xm * 17, Y + Ym * 9.8);
    glVertex2f(X + Xm * 18, Y + Ym * 9.96);
    glVertex2f(X + Xm * 19, Y + Ym * 10);
    glVertex2f(X + Xm * 20, Y + Ym * 9.96);
    glVertex2f(X + Xm * 21, Y + Ym * 9.8);
    glVertex2f(X + Xm * 22, Y + Ym * 9.64);
    glVertex2f(X + Xm * 23, Y + Ym * 9.48);
    glVertex2f(X + Xm * 24, Y + Ym * 9.32);
    glVertex2f(X + Xm * 25, Y + Ym * 9.16);
    glVertex2f(X + Xm * 26, Y + Ym * 9);

    glVertex2f(X + Xm * 26, Y + Ym * 2);
    glVertex2f(X + Xm * 25, Y + Ym * 1.84);
    glVertex2f(X + Xm * 24, Y + Ym * 1.68);
    glVertex2f(X + Xm * 23, Y + Ym * 1.52);
    glVertex2f(X + Xm * 22, Y + Ym * 1.36);
    glVertex2f(X + Xm * 21, Y + Ym * 1.2);
    glVertex2f(X + Xm * 20, Y + Ym * 1.04);
    glVertex2f(X + Xm * 19, Y + Ym * 0.88);
    glVertex2f(X + Xm * 18, Y + Ym * 1.04);
    glVertex2f(X + Xm * 17, Y + Ym * 1.2);
    glVertex2f(X + Xm * 16, Y + Ym * 1.36);
    glVertex2f(X + Xm * 15, Y + Ym * 1.52);
    glVertex2f(X + Xm * 14, Y + Ym * 1.68);
    glVertex2f(X + Xm * 13, Y + Ym * 1.84);
    glVertex2f(X + Xm * 12, Y + Ym * 2);
    glEnd();

    //Horizontal
    glColor3f(w1R, w1G, w1B);

    glBegin(GL_LINES);
    glLineWidth((GLfloat)4);

    float w = 2;
    glVertex2f(X + Xm * 26, Y + Ym * (2 + w));
    glVertex2f(X + Xm * 25, Y + Ym * (1.84 + w));

    glVertex2f(X + Xm * 25, Y + Ym * (1.84 + w));
    glVertex2f(X + Xm * 24, Y + Ym * (1.68 + w));

    glVertex2f(X + Xm * 24, Y + Ym * (1.68 + w));
    glVertex2f(X + Xm * 23, Y + Ym * (1.52 + w));

    glVertex2f(X + Xm * 23, Y + Ym * (1.52 + w));
    glVertex2f(X + Xm * 22, Y + Ym * (1.36 + w));

    glVertex2f(X + Xm * 22, Y + Ym * (1.36 + w));
    glVertex2f(X + Xm * 21, Y + Ym * (1.2 + w));

    glVertex2f(X + Xm * 21, Y + Ym * (1.2 + w));
    glVertex2f(X + Xm * 20, Y + Ym * (1.04 + w));

    glVertex2f(X + Xm * 20, Y + Ym * (1.04 + w));
    glVertex2f(X + Xm * 19, Y + Ym * (0.88 + w));

    glVertex2f(X + Xm * 19, Y + Ym * (0.88 + w));
    glVertex2f(X + Xm * 18, Y + Ym * (1.04 + w));

    glVertex2f(X + Xm * 18, Y + Ym * (1.04 + w));
    glVertex2f(X + Xm * 17, Y + Ym * (1.2 + w));

    glVertex2f(X + Xm * 17, Y + Ym * (1.2 + w));
    glVertex2f(X + Xm * 16, Y + Ym * (1.36 + w));

    glVertex2f(X + Xm * 16, Y + Ym * (1.36 + w));
    glVertex2f(X + Xm * 15, Y + Ym * (1.52 + w));

    glVertex2f(X + Xm * 15, Y + Ym * (1.52 + w));
    glVertex2f(X + Xm * 14, Y + Ym * (1.68 + w));

    glVertex2f(X + Xm * 14, Y + Ym * (1.68 + w));
    glVertex2f(X + Xm * 13, Y + Ym * (1.84 + w));

    glVertex2f(X + Xm * 13, Y + Ym * (1.84 + w));
    glVertex2f(X + Xm * 12, Y + Ym * (2 + w));

    w = 3;
    glVertex2f(X + Xm * 26, Y + Ym * (2 + w));
    glVertex2f(X + Xm * 25, Y + Ym * (1.84 + w));

    glVertex2f(X + Xm * 25, Y + Ym * (1.84 + w));
    glVertex2f(X + Xm * 24, Y + Ym * (1.68 + w));

    glVertex2f(X + Xm * 24, Y + Ym * (1.68 + w));
    glVertex2f(X + Xm * 23, Y + Ym * (1.52 + w));

    glVertex2f(X + Xm * 23, Y + Ym * (1.52 + w));
    glVertex2f(X + Xm * 22, Y + Ym * (1.36 + w));

    glVertex2f(X + Xm * 22, Y + Ym * (1.36 + w));
    glVertex2f(X + Xm * 21, Y + Ym * (1.2 + w));

    glVertex2f(X + Xm * 21, Y + Ym * (1.2 + w));
    glVertex2f(X + Xm * 20, Y + Ym * (1.04 + w));

    glVertex2f(X + Xm * 20, Y + Ym * (1.04 + w));
    glVertex2f(X + Xm * 19, Y + Ym * (0.88 + w));

    glVertex2f(X + Xm * 19, Y + Ym * (0.88 + w));
    glVertex2f(X + Xm * 18, Y + Ym * (1.04 + w));

    glVertex2f(X + Xm * 18, Y + Ym * (1.04 + w));
    glVertex2f(X + Xm * 17, Y + Ym * (1.2 + w));

    glVertex2f(X + Xm * 17, Y + Ym * (1.2 + w));
    glVertex2f(X + Xm * 16, Y + Ym * (1.36 + w));

    glVertex2f(X + Xm * 16, Y + Ym * (1.36 + w));
    glVertex2f(X + Xm * 15, Y + Ym * (1.52 + w));

    glVertex2f(X + Xm * 15, Y + Ym * (1.52 + w));
    glVertex2f(X + Xm * 14, Y + Ym * (1.68 + w));

    glVertex2f(X + Xm * 14, Y + Ym * (1.68 + w));
    glVertex2f(X + Xm * 13, Y + Ym * (1.84 + w));

    glVertex2f(X + Xm * 13, Y + Ym * (1.84 + w));
    glVertex2f(X + Xm * 12, Y + Ym * (2 + w));


    w = 4;
    glVertex2f(X + Xm * 26, Y + Ym * (2 + w));
    glVertex2f(X + Xm * 25, Y + Ym * (1.84 + w));

    glVertex2f(X + Xm * 25, Y + Ym * (1.84 + w));
    glVertex2f(X + Xm * 24, Y + Ym * (1.68 + w));

    glVertex2f(X + Xm * 24, Y + Ym * (1.68 + w));
    glVertex2f(X + Xm * 23, Y + Ym * (1.52 + w));

    glVertex2f(X + Xm * 23, Y + Ym * (1.52 + w));
    glVertex2f(X + Xm * 22, Y + Ym * (1.36 + w));

    glVertex2f(X + Xm * 22, Y + Ym * (1.36 + w));
    glVertex2f(X + Xm * 21, Y + Ym * (1.2 + w));

    glVertex2f(X + Xm * 21, Y + Ym * (1.2 + w));
    glVertex2f(X + Xm * 20, Y + Ym * (1.04 + w));

    glVertex2f(X + Xm * 20, Y + Ym * (1.04 + w));
    glVertex2f(X + Xm * 19, Y + Ym * (0.88 + w));

    glVertex2f(X + Xm * 19, Y + Ym * (0.88 + w));
    glVertex2f(X + Xm * 18, Y + Ym * (1.04 + w));

    glVertex2f(X + Xm * 18, Y + Ym * (1.04 + w));
    glVertex2f(X + Xm * 17, Y + Ym * (1.2 + w));

    glVertex2f(X + Xm * 17, Y + Ym * (1.2 + w));
    glVertex2f(X + Xm * 16, Y + Ym * (1.36 + w));

    glVertex2f(X + Xm * 16, Y + Ym * (1.36 + w));
    glVertex2f(X + Xm * 15, Y + Ym * (1.52 + w));

    glVertex2f(X + Xm * 15, Y + Ym * (1.52 + w));
    glVertex2f(X + Xm * 14, Y + Ym * (1.68 + w));

    glVertex2f(X + Xm * 14, Y + Ym * (1.68 + w));
    glVertex2f(X + Xm * 13, Y + Ym * (1.84 + w));

    glVertex2f(X + Xm * 13, Y + Ym * (1.84 + w));
    glVertex2f(X + Xm * 12, Y + Ym * (2 + w));


    w = 5;
    glVertex2f(X + Xm * 26, Y + Ym * (2 + w));
    glVertex2f(X + Xm * 25, Y + Ym * (1.84 + w));

    glVertex2f(X + Xm * 25, Y + Ym * (1.84 + w));
    glVertex2f(X + Xm * 24, Y + Ym * (1.68 + w));

    glVertex2f(X + Xm * 24, Y + Ym * (1.68 + w));
    glVertex2f(X + Xm * 23, Y + Ym * (1.52 + w));

    glVertex2f(X + Xm * 23, Y + Ym * (1.52 + w));
    glVertex2f(X + Xm * 22, Y + Ym * (1.36 + w));

    glVertex2f(X + Xm * 22, Y + Ym * (1.36 + w));
    glVertex2f(X + Xm * 21, Y + Ym * (1.2 + w));

    glVertex2f(X + Xm * 21, Y + Ym * (1.2 + w));
    glVertex2f(X + Xm * 20, Y + Ym * (1.04 + w));

    glVertex2f(X + Xm * 20, Y + Ym * (1.04 + w));
    glVertex2f(X + Xm * 19, Y + Ym * (0.88 + w));

    glVertex2f(X + Xm * 19, Y + Ym * (0.88 + w));
    glVertex2f(X + Xm * 18, Y + Ym * (1.04 + w));

    glVertex2f(X + Xm * 18, Y + Ym * (1.04 + w));
    glVertex2f(X + Xm * 17, Y + Ym * (1.2 + w));

    glVertex2f(X + Xm * 17, Y + Ym * (1.2 + w));
    glVertex2f(X + Xm * 16, Y + Ym * (1.36 + w));

    glVertex2f(X + Xm * 16, Y + Ym * (1.36 + w));
    glVertex2f(X + Xm * 15, Y + Ym * (1.52 + w));

    glVertex2f(X + Xm * 15, Y + Ym * (1.52 + w));
    glVertex2f(X + Xm * 14, Y + Ym * (1.68 + w));

    glVertex2f(X + Xm * 14, Y + Ym * (1.68 + w));
    glVertex2f(X + Xm * 13, Y + Ym * (1.84 + w));

    glVertex2f(X + Xm * 13, Y + Ym * (1.84 + w));
    glVertex2f(X + Xm * 12, Y + Ym * (2 + w));


    w = 6;
    glVertex2f(X + Xm * 26, Y + Ym * (2 + w));
    glVertex2f(X + Xm * 25, Y + Ym * (1.84 + w));

    glVertex2f(X + Xm * 25, Y + Ym * (1.84 + w));
    glVertex2f(X + Xm * 24, Y + Ym * (1.68 + w));

    glVertex2f(X + Xm * 24, Y + Ym * (1.68 + w));
    glVertex2f(X + Xm * 23, Y + Ym * (1.52 + w));

    glVertex2f(X + Xm * 23, Y + Ym * (1.52 + w));
    glVertex2f(X + Xm * 22, Y + Ym * (1.36 + w));

    glVertex2f(X + Xm * 22, Y + Ym * (1.36 + w));
    glVertex2f(X + Xm * 21, Y + Ym * (1.2 + w));

    glVertex2f(X + Xm * 21, Y + Ym * (1.2 + w));
    glVertex2f(X + Xm * 20, Y + Ym * (1.04 + w));

    glVertex2f(X + Xm * 20, Y + Ym * (1.04 + w));
    glVertex2f(X + Xm * 19, Y + Ym * (0.88 + w));

    glVertex2f(X + Xm * 19, Y + Ym * (0.88 + w));
    glVertex2f(X + Xm * 18, Y + Ym * (1.04 + w));

    glVertex2f(X + Xm * 18, Y + Ym * (1.04 + w));
    glVertex2f(X + Xm * 17, Y + Ym * (1.2 + w));

    glVertex2f(X + Xm * 17, Y + Ym * (1.2 + w));
    glVertex2f(X + Xm * 16, Y + Ym * (1.36 + w));

    glVertex2f(X + Xm * 16, Y + Ym * (1.36 + w));
    glVertex2f(X + Xm * 15, Y + Ym * (1.52 + w));

    glVertex2f(X + Xm * 15, Y + Ym * (1.52 + w));
    glVertex2f(X + Xm * 14, Y + Ym * (1.68 + w));

    glVertex2f(X + Xm * 14, Y + Ym * (1.68 + w));
    glVertex2f(X + Xm * 13, Y + Ym * (1.84 + w));

    glVertex2f(X + Xm * 13, Y + Ym * (1.84 + w));
    glVertex2f(X + Xm * 12, Y + Ym * (2 + w));


    w = 7;
    glVertex2f(X + Xm * 26, Y + Ym * (2 + w));
    glVertex2f(X + Xm * 25, Y + Ym * (1.84 + w));

    glVertex2f(X + Xm * 25, Y + Ym * (1.84 + w));
    glVertex2f(X + Xm * 24, Y + Ym * (1.68 + w));

    glVertex2f(X + Xm * 24, Y + Ym * (1.68 + w));
    glVertex2f(X + Xm * 23, Y + Ym * (1.52 + w));

    glVertex2f(X + Xm * 23, Y + Ym * (1.52 + w));
    glVertex2f(X + Xm * 22, Y + Ym * (1.36 + w));

    glVertex2f(X + Xm * 22, Y + Ym * (1.36 + w));
    glVertex2f(X + Xm * 21, Y + Ym * (1.2 + w));

    glVertex2f(X + Xm * 21, Y + Ym * (1.2 + w));
    glVertex2f(X + Xm * 20, Y + Ym * (1.04 + w));

    glVertex2f(X + Xm * 20, Y + Ym * (1.04 + w));
    glVertex2f(X + Xm * 19, Y + Ym * (0.88 + w));

    glVertex2f(X + Xm * 19, Y + Ym * (0.88 + w));
    glVertex2f(X + Xm * 18, Y + Ym * (1.04 + w));

    glVertex2f(X + Xm * 18, Y + Ym * (1.04 + w));
    glVertex2f(X + Xm * 17, Y + Ym * (1.2 + w));

    glVertex2f(X + Xm * 17, Y + Ym * (1.2 + w));
    glVertex2f(X + Xm * 16, Y + Ym * (1.36 + w));

    glVertex2f(X + Xm * 16, Y + Ym * (1.36 + w));
    glVertex2f(X + Xm * 15, Y + Ym * (1.52 + w));

    glVertex2f(X + Xm * 15, Y + Ym * (1.52 + w));
    glVertex2f(X + Xm * 14, Y + Ym * (1.68 + w));

    glVertex2f(X + Xm * 14, Y + Ym * (1.68 + w));
    glVertex2f(X + Xm * 13, Y + Ym * (1.84 + w));

    glVertex2f(X + Xm * 13, Y + Ym * (1.84 + w));
    glVertex2f(X + Xm * 12, Y + Ym * (2 + w));


    //bottom line

    glVertex2f(X + Xm * 26, Y + Ym * 2);
    glVertex2f(X + Xm * 25, Y + Ym * 1.84);

    glVertex2f(X + Xm * 25, Y + Ym * 1.84);
    glVertex2f(X + Xm * 24, Y + Ym * 1.68);

    glVertex2f(X + Xm * 24, Y + Ym * 1.68);
    glVertex2f(X + Xm * 23, Y + Ym * 1.52);

    glVertex2f(X + Xm * 23, Y + Ym * 1.52);
    glVertex2f(X + Xm * 22, Y + Ym * 1.36);

    glVertex2f(X + Xm * 22, Y + Ym * 1.36);
    glVertex2f(X + Xm * 21, Y + Ym * 1.2);

    glVertex2f(X + Xm * 21, Y + Ym * 1.2);
    glVertex2f(X + Xm * 20, Y + Ym * 1.04);

    glVertex2f(X + Xm * 20, Y + Ym * 1.04);
    glVertex2f(X + Xm * 19, Y + Ym * 0.88);

    glVertex2f(X + Xm * 19, Y + Ym * 0.88);
    glVertex2f(X + Xm * 18, Y + Ym * 1.04);

    glVertex2f(X + Xm * 18, Y + Ym * 1.04);
    glVertex2f(X + Xm * 17, Y + Ym * 1.2);

    glVertex2f(X + Xm * 17, Y + Ym * 1.2);
    glVertex2f(X + Xm * 16, Y + Ym * 1.36);

    glVertex2f(X + Xm * 16, Y + Ym * 1.36);
    glVertex2f(X + Xm * 15, Y + Ym * 1.52);

    glVertex2f(X + Xm * 15, Y + Ym * 1.52);
    glVertex2f(X + Xm * 14, Y + Ym * 1.68);

    glVertex2f(X + Xm * 14, Y + Ym * 1.68);
    glVertex2f(X + Xm * 13, Y + Ym * 1.84);

    glVertex2f(X + Xm * 13, Y + Ym * 1.84);
    glVertex2f(X + Xm * 12, Y + Ym * 2);



    //vertical beam
    glVertex2f(X + Xm * 12, Y + Ym * 9);
    glVertex2f(X + Xm * 12, Y + Ym * 2);

    glVertex2f(X + Xm * 14, Y + Ym * 8.5);
    glVertex2f(X + Xm * 14, Y + Ym * 1.5);

    glVertex2f(X + Xm * 16, Y + Ym * 8.3);
    glVertex2f(X + Xm * 16, Y + Ym * 1.3);

    glVertex2f(X + Xm * 18, Y + Ym * 8.13);
    glVertex2f(X + Xm * 18, Y + Ym * 1.13);

    glVertex2f(X + Xm * 20, Y + Ym * 8.3);
    glVertex2f(X + Xm * 20, Y + Ym * 1.3);

    glVertex2f(X + Xm * 22, Y + Ym * 8.3);
    glVertex2f(X + Xm * 22, Y + Ym * 1.3);

    glVertex2f(X + Xm * 24, Y + Ym * 8.5);
    glVertex2f(X + Xm * 24, Y + Ym * 1.5);

    glVertex2f(X + Xm * 26, Y + Ym * 9);
    glVertex2f(X + Xm * 26, Y + Ym * 2);



    glEnd();


    //top orange
    glBegin(GL_LINES);
    glLineWidth((GLfloat)8);
    w = 8;
    glColor3f(orangeR, orangeG, orangeB); //orange
    glVertex2f(X + Xm * 26, Y + Ym * (2 + w));
    glVertex2f(X + Xm * 25, Y + Ym * (1.84 + w));
    glVertex2f(X + Xm * 25, Y + Ym * (1.84 + w));
    glVertex2f(X + Xm * 24, Y + Ym * (1.68 + w));
    glVertex2f(X + Xm * 24, Y + Ym * (1.68 + w));
    glVertex2f(X + Xm * 23, Y + Ym * (1.52 + w));
    glVertex2f(X + Xm * 23, Y + Ym * (1.52 + w));
    glVertex2f(X + Xm * 22, Y + Ym * (1.36 + w));
    glVertex2f(X + Xm * 22, Y + Ym * (1.36 + w));
    glVertex2f(X + Xm * 21, Y + Ym * (1.2 + w));
    glVertex2f(X + Xm * 21, Y + Ym * (1.2 + w));
    glVertex2f(X + Xm * 20, Y + Ym * (1.04 + w));
    glVertex2f(X + Xm * 20, Y + Ym * (1.04 + w));
    glVertex2f(X + Xm * 19, Y + Ym * (0.88 + w));
    glVertex2f(X + Xm * 19, Y + Ym * (0.88 + w));
    glVertex2f(X + Xm * 18, Y + Ym * (1.04 + w));
    glVertex2f(X + Xm * 18, Y + Ym * (1.04 + w));
    glVertex2f(X + Xm * 17, Y + Ym * (1.2 + w));
    glVertex2f(X + Xm * 17, Y + Ym * (1.2 + w));
    glVertex2f(X + Xm * 16, Y + Ym * (1.36 + w));
    glVertex2f(X + Xm * 16, Y + Ym * (1.36 + w));
    glVertex2f(X + Xm * 15, Y + Ym * (1.52 + w));
    glVertex2f(X + Xm * 15, Y + Ym * (1.52 + w));
    glVertex2f(X + Xm * 14, Y + Ym * (1.68 + w));
    glVertex2f(X + Xm * 14, Y + Ym * (1.68 + w));
    glVertex2f(X + Xm * 13, Y + Ym * (1.84 + w));
    glVertex2f(X + Xm * 13, Y + Ym * (1.84 + w));
    glVertex2f(X + Xm * 12, Y + Ym * (2 + w));


    w = 7.8;
    glColor3f(orangeR, orangeG, orangeB); //orange
    glVertex2f(X + Xm * 26, Y + Ym * (2 + w));
    glVertex2f(X + Xm * 25, Y + Ym * (1.84 + w));
    glVertex2f(X + Xm * 25, Y + Ym * (1.84 + w));
    glVertex2f(X + Xm * 24, Y + Ym * (1.68 + w));
    glVertex2f(X + Xm * 24, Y + Ym * (1.68 + w));
    glVertex2f(X + Xm * 23, Y + Ym * (1.52 + w));
    glVertex2f(X + Xm * 23, Y + Ym * (1.52 + w));
    glVertex2f(X + Xm * 22, Y + Ym * (1.36 + w));
    glVertex2f(X + Xm * 22, Y + Ym * (1.36 + w));
    glVertex2f(X + Xm * 21, Y + Ym * (1.2 + w));
    glVertex2f(X + Xm * 21, Y + Ym * (1.2 + w));
    glVertex2f(X + Xm * 20, Y + Ym * (1.04 + w));
    glVertex2f(X + Xm * 20, Y + Ym * (1.04 + w));
    glVertex2f(X + Xm * 19, Y + Ym * (0.88 + w));
    glVertex2f(X + Xm * 19, Y + Ym * (0.88 + w));
    glVertex2f(X + Xm * 18, Y + Ym * (1.04 + w));
    glVertex2f(X + Xm * 18, Y + Ym * (1.04 + w));
    glVertex2f(X + Xm * 17, Y + Ym * (1.2 + w));
    glVertex2f(X + Xm * 17, Y + Ym * (1.2 + w));
    glVertex2f(X + Xm * 16, Y + Ym * (1.36 + w));
    glVertex2f(X + Xm * 16, Y + Ym * (1.36 + w));
    glVertex2f(X + Xm * 15, Y + Ym * (1.52 + w));
    glVertex2f(X + Xm * 15, Y + Ym * (1.52 + w));
    glVertex2f(X + Xm * 14, Y + Ym * (1.68 + w));
    glVertex2f(X + Xm * 14, Y + Ym * (1.68 + w));
    glVertex2f(X + Xm * 13, Y + Ym * (1.84 + w));
    glVertex2f(X + Xm * 13, Y + Ym * (1.84 + w));
    glVertex2f(X + Xm * 12, Y + Ym * (2 + w));

    w = 7.6;
    glColor3f(orangeR, orangeG, orangeB); //orange
    glVertex2f(X + Xm * 26, Y + Ym * (2 + w));
    glVertex2f(X + Xm * 25, Y + Ym * (1.84 + w));
    glVertex2f(X + Xm * 25, Y + Ym * (1.84 + w));
    glVertex2f(X + Xm * 24, Y + Ym * (1.68 + w));
    glVertex2f(X + Xm * 24, Y + Ym * (1.68 + w));
    glVertex2f(X + Xm * 23, Y + Ym * (1.52 + w));
    glVertex2f(X + Xm * 23, Y + Ym * (1.52 + w));
    glVertex2f(X + Xm * 22, Y + Ym * (1.36 + w));
    glVertex2f(X + Xm * 22, Y + Ym * (1.36 + w));
    glVertex2f(X + Xm * 21, Y + Ym * (1.2 + w));
    glVertex2f(X + Xm * 21, Y + Ym * (1.2 + w));
    glVertex2f(X + Xm * 20, Y + Ym * (1.04 + w));
    glVertex2f(X + Xm * 20, Y + Ym * (1.04 + w));
    glVertex2f(X + Xm * 19, Y + Ym * (0.88 + w));
    glVertex2f(X + Xm * 19, Y + Ym * (0.88 + w));
    glVertex2f(X + Xm * 18, Y + Ym * (1.04 + w));
    glVertex2f(X + Xm * 18, Y + Ym * (1.04 + w));
    glVertex2f(X + Xm * 17, Y + Ym * (1.2 + w));
    glVertex2f(X + Xm * 17, Y + Ym * (1.2 + w));
    glVertex2f(X + Xm * 16, Y + Ym * (1.36 + w));
    glVertex2f(X + Xm * 16, Y + Ym * (1.36 + w));
    glVertex2f(X + Xm * 15, Y + Ym * (1.52 + w));
    glVertex2f(X + Xm * 15, Y + Ym * (1.52 + w));
    glVertex2f(X + Xm * 14, Y + Ym * (1.68 + w));
    glVertex2f(X + Xm * 14, Y + Ym * (1.68 + w));
    glVertex2f(X + Xm * 13, Y + Ym * (1.84 + w));
    glVertex2f(X + Xm * 13, Y + Ym * (1.84 + w));
    glVertex2f(X + Xm * 12, Y + Ym * (2 + w));


    w = 7.4;
    glColor3f(orangeR, orangeG, orangeB); //orange
    glVertex2f(X + Xm * 26, Y + Ym * (2 + w));
    glVertex2f(X + Xm * 25, Y + Ym * (1.84 + w));
    glVertex2f(X + Xm * 25, Y + Ym * (1.84 + w));
    glVertex2f(X + Xm * 24, Y + Ym * (1.68 + w));
    glVertex2f(X + Xm * 24, Y + Ym * (1.68 + w));
    glVertex2f(X + Xm * 23, Y + Ym * (1.52 + w));
    glVertex2f(X + Xm * 23, Y + Ym * (1.52 + w));
    glVertex2f(X + Xm * 22, Y + Ym * (1.36 + w));
    glVertex2f(X + Xm * 22, Y + Ym * (1.36 + w));
    glVertex2f(X + Xm * 21, Y + Ym * (1.2 + w));
    glVertex2f(X + Xm * 21, Y + Ym * (1.2 + w));
    glVertex2f(X + Xm * 20, Y + Ym * (1.04 + w));
    glVertex2f(X + Xm * 20, Y + Ym * (1.04 + w));
    glVertex2f(X + Xm * 19, Y + Ym * (0.88 + w));
    glVertex2f(X + Xm * 19, Y + Ym * (0.88 + w));
    glVertex2f(X + Xm * 18, Y + Ym * (1.04 + w));
    glVertex2f(X + Xm * 18, Y + Ym * (1.04 + w));
    glVertex2f(X + Xm * 17, Y + Ym * (1.2 + w));
    glVertex2f(X + Xm * 17, Y + Ym * (1.2 + w));
    glVertex2f(X + Xm * 16, Y + Ym * (1.36 + w));
    glVertex2f(X + Xm * 16, Y + Ym * (1.36 + w));
    glVertex2f(X + Xm * 15, Y + Ym * (1.52 + w));
    glVertex2f(X + Xm * 15, Y + Ym * (1.52 + w));
    glVertex2f(X + Xm * 14, Y + Ym * (1.68 + w));
    glVertex2f(X + Xm * 14, Y + Ym * (1.68 + w));
    glVertex2f(X + Xm * 13, Y + Ym * (1.84 + w));
    glVertex2f(X + Xm * 13, Y + Ym * (1.84 + w));
    glVertex2f(X + Xm * 12, Y + Ym * (2 + w));


    w = 7.2;
    glColor3f(orangeR, orangeG, orangeB); //orange
    glVertex2f(X + Xm * 26, Y + Ym * (2 + w));
    glVertex2f(X + Xm * 25, Y + Ym * (1.84 + w));
    glVertex2f(X + Xm * 25, Y + Ym * (1.84 + w));
    glVertex2f(X + Xm * 24, Y + Ym * (1.68 + w));
    glVertex2f(X + Xm * 24, Y + Ym * (1.68 + w));
    glVertex2f(X + Xm * 23, Y + Ym * (1.52 + w));
    glVertex2f(X + Xm * 23, Y + Ym * (1.52 + w));
    glVertex2f(X + Xm * 22, Y + Ym * (1.36 + w));
    glVertex2f(X + Xm * 22, Y + Ym * (1.36 + w));
    glVertex2f(X + Xm * 21, Y + Ym * (1.2 + w));
    glVertex2f(X + Xm * 21, Y + Ym * (1.2 + w));
    glVertex2f(X + Xm * 20, Y + Ym * (1.04 + w));
    glVertex2f(X + Xm * 20, Y + Ym * (1.04 + w));
    glVertex2f(X + Xm * 19, Y + Ym * (0.88 + w));
    glVertex2f(X + Xm * 19, Y + Ym * (0.88 + w));
    glVertex2f(X + Xm * 18, Y + Ym * (1.04 + w));
    glVertex2f(X + Xm * 18, Y + Ym * (1.04 + w));
    glVertex2f(X + Xm * 17, Y + Ym * (1.2 + w));
    glVertex2f(X + Xm * 17, Y + Ym * (1.2 + w));
    glVertex2f(X + Xm * 16, Y + Ym * (1.36 + w));
    glVertex2f(X + Xm * 16, Y + Ym * (1.36 + w));
    glVertex2f(X + Xm * 15, Y + Ym * (1.52 + w));
    glVertex2f(X + Xm * 15, Y + Ym * (1.52 + w));
    glVertex2f(X + Xm * 14, Y + Ym * (1.68 + w));
    glVertex2f(X + Xm * 14, Y + Ym * (1.68 + w));
    glVertex2f(X + Xm * 13, Y + Ym * (1.84 + w));
    glVertex2f(X + Xm * 13, Y + Ym * (1.84 + w));
    glVertex2f(X + Xm * 12, Y + Ym * (2 + w));

    glEnd();


    //DIU text
    glBegin(GL_LINES);
    glColor3f(w1R, w1G, w1B);

    float hightDIU = 3;
    //D
    glVertex2f(X + Xm * 20, Y + Ym * 15.6 + hightDIU);
    glVertex2f(X + Xm * 21, Y + Ym * 15.9 + hightDIU);
    glVertex2f(X + Xm * 21, Y + Ym * 15.9 + hightDIU);
    glVertex2f(X + Xm * 21, Y + Ym * 15.25 + hightDIU);
    glVertex2f(X + Xm * 21, Y + Ym * 15.25 + hightDIU);
    glVertex2f(X + Xm * 20, Y + Ym * 15 + hightDIU);
    glVertex2f(X + Xm * 20, Y + Ym * 15 + hightDIU);
    glVertex2f(X + Xm * 20, Y + Ym * 15.6 + hightDIU);

    //I
    glVertex2f(X + Xm * 21.3, Y + Ym * 15.99 + hightDIU);
    glVertex2f(X + Xm * 21.8, Y + Ym * 16.14 + hightDIU);
    glVertex2f(X + Xm * 21.3, Y + Ym * 15.325 + hightDIU);
    glVertex2f(X + Xm * 21.8, Y + Ym * 15.45 + hightDIU);
    glVertex2f(X + Xm * 21.55, Y + Ym * 16 + hightDIU);
    glVertex2f(X + Xm * 21.55, Y + Ym * 15.38 + hightDIU);

    //U
    glVertex2f(X + Xm * 22.1, Y + Ym * 16.23 + hightDIU);
    glVertex2f(X + Xm * 22.1, Y + Ym * 15.525 + hightDIU);
    glVertex2f(X + Xm * 22.1, Y + Ym * 15.525 + hightDIU);
    glVertex2f(X + Xm * 22.6, Y + Ym * 15.65 + hightDIU);
    glVertex2f(X + Xm * 22.6, Y + Ym * 15.65 + hightDIU);
    glVertex2f(X + Xm * 22.6, Y + Ym * 16.38 + hightDIU);




    glEnd();
    glPopMatrix();
    text();

    /// input end 
    //bus
 // Draw both cars
    glColor3f(0.7f, 0.2f, 0.2f);

    drawCar(car1.x, 52.0f);
    glColor3f(.72, .9, .49);

    drawCar(car3.x, 51.0f);
    glColor3f(0.04, 0.29, 0.43);
    drawCar(car2.x, 50.0f);



    glutSwapBuffers();
}



int main(int argc, char** argv)
{


    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(1920, 1080);
    glutCreateWindow("House");
    init();
    glutDisplayFunc(Draw);

    // Initialize car positions and speeds
    car1.x = 60.0f;
    car1.y = 40 + 10.0f;
    car1.speed = 0.1f;

    car2.x = 30.0f;
    car2.y = 41.0f;
    car2.speed = 0.15f;

    car3.x = 10.0f;
    car3.y = 42.0f;
    car3.speed = 0.12f;

    myCloud1.x = 20.0f;
    myCloud1.speed = 0.12f;
    myCloud2.x = 35.0f;
    myCloud2.speed = 0.12f;
    myCloud3.x = 60.0f;
    myCloud3.speed = 0.12f;
    myCloud4.x = 100.0f;
    myCloud4.speed = 0.12f;


    glutSpecialFunc(keyPress);
    glutTimerFunc(0, update, 0);
    glutMainLoop();
    return 0;
}
