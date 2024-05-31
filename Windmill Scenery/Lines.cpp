// ////////use up and down key to move the sun///// 
#include <windows.h>
#include <GL/glut.h>
#include <math.h>

void init(void)
{
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
glOrtho(.0, 150.0, -0.0, 100.0, -1.0, 1.0);
}

void Initialize() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
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

void square(float x1, float y1, float height, float width){
    glBegin(GL_POLYGON);
    glVertex2f(x1,y1);
    glVertex2f(x1+width,y1);
    glVertex2f(x1+width,y1+height);
    glVertex2f(x1,y1+height);
    glEnd();
}


void windMill(int x, int y){
    //ROOF L5
    glBegin(GL_POLYGON);
    glColor3f( 0.70,.32,0.03);
    glVertex2f(x+20,y+50);
    glVertex2f(x+30,y+50);
    glVertex2f(x+25,y+55);
    glEnd();
    
    //ROOF L4
    glBegin(GL_POLYGON);
    glColor3f( 0.09,.14,0.32); //BLUE
    glVertex2f(x+20,y+45);
    glVertex2f(x+30,y+45);
    glVertex2f(x+30,y+50);
    glVertex2f(x+20,y+50);
    glEnd();
    
    //ROOF L3
    glBegin(GL_POLYGON);
    glColor3f( 0.70,.32,0.03);
    glVertex2f(x+10,y+35);
    glVertex2f(x+40,y+35);
    glVertex2f(x+30,y+45);
    glVertex2f(x+20,y+45);
    glEnd();
    
    //ROOF L2
    glBegin(GL_POLYGON);
    glColor3f( 0.24,.10,0.011);
    glVertex2f(x+8,y+30);
    glVertex2f(x+42,y+30);
    glVertex2f(x+40,y+35);
    glVertex2f(x+10,y+35);
    glEnd();
    
    //ROOF L1
    glBegin(GL_POLYGON);
    glColor3f( 0.70,.32,0.03);
    glVertex2f(x+5,y+20);
    glVertex2f(x+45,y+20);
    glVertex2f(x+40,y+30);
    glVertex2f(x+10,y+30);
    glEnd();

    //BASE OF THE HOUSE
    glBegin(GL_POLYGON);
    glColor3f( 0.09,.14,0.32); //BLUE
    glVertex2f(x+10,y+15);
    glVertex2f(x+40,y+15);
    glVertex2f(x+40,y+20);
    glVertex2f(x+10,y+20);
    glEnd();

      //WINDOW WHITE BORDER
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex2f(x+20-.1,y+18-.1);
    glVertex2f(x+30+.1,y+18-.1);
    glVertex2f(x+30+.1,y+20-.1);
    glVertex2f(x+20-.1,y+20-.1);
    glEnd();

      //WINDOW
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(x+20,y+18);
    glVertex2f(x+30,y+18);
    glVertex2f(x+30,y+20);
    glVertex2f(x+20,y+20);
    glEnd();

      //WINDOW
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(x+18,y+23);
    glVertex2f(x+20,y+23);
    glVertex2f(x+20,y+27);
    glVertex2f(x+18,y+27);
    glEnd();

      //WINDOW
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(x+35,y+23);
    glVertex2f(x+37,y+23);
    glVertex2f(x+37,y+27);
    glVertex2f(x+35,y+27);
    glEnd();

      //WINDOW
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(x+24,y+37);
    glVertex2f(x+24+2,y+37);
    glVertex2f(x+24+2,y+37+6);
    glVertex2f(x+24,y+37+6);
    glEnd();

    //TOP WHEEL 
    //1
    glColor3f(1, 1, 1);// white border
    glBegin(GL_POLYGON);
    glVertex2f(x+10-.1,y+30-.1);
    glVertex2f(x+25+.1,y+50+.1);
    glVertex2f(x+24+.1,y+50+.1);
    glVertex2f(x+5-.1,y+34-.1);
    glEnd();

    glColor3f(0.04, 0.29, 0.43);// base blue
    glBegin(GL_POLYGON);
    glVertex2f(x+10,y+30);
    glVertex2f(x+25,y+50);
    glVertex2f(x+24,y+50);
    glVertex2f(x+5,y+34);
    glEnd();

    glColor3f(0.03, 0.18, 0.28);// dark blue one side border
    glBegin(GL_POLYGON);
    glVertex2f(x+10,y+30);
    glVertex2f(x+25,y+50);
    glVertex2f(x+24,y+50);
    glVertex2f(x+9,y+31);
    glEnd();

    //2
    glColor3f(1, 1, 1);// white border
    glBegin(GL_POLYGON);
    glVertex2f(x+40-.1,y+30-.1);
    glVertex2f(x+44+.1,y+34+.1);
    glVertex2f(x+26+.1,y+50+.1);
    glVertex2f(x+25-.1,y+50-.1);
    glEnd();

    glColor3f(0.04, 0.29, 0.43);// base blue
    glBegin(GL_POLYGON);
    glVertex2f(x+40,y+30);
    glVertex2f(x+44,y+34);
    glVertex2f(x+26,y+50);
    glVertex2f(x+25,y+50);
    glEnd();

    glColor3f(0.03, 0.18, 0.28);// dark blue one side border
    glBegin(GL_POLYGON);
    glVertex2f(x+40,y+30);
    glVertex2f(x+41,y+31);
    glVertex2f(x+26,y+50);
    glVertex2f(x+25,y+50);
    glEnd();

        //3
    glColor3f(1, 1, 1);// white border
    glBegin(GL_POLYGON);
    glVertex2f(x+40-.1,y+70-.1);
    glVertex2f(x+36+.1,y+74+.1);
    glVertex2f(x+24+.1,y+50+.1);
    glVertex2f(x+25-.1,y+50-.1);
    glEnd();

    glColor3f(0.04, 0.29, 0.43);// base blue
    glBegin(GL_POLYGON);
    glVertex2f(x+40,y+70);
    glVertex2f(x+36,y+74);
    glVertex2f(x+24,y+50);
    glVertex2f(x+25,y+50);
    glEnd();

    glColor3f(0.03, 0.18, 0.28);// dark blue one side border
    glBegin(GL_POLYGON);
    glVertex2f(x+40,y+70);
    glVertex2f(x+39,y+71);
    glVertex2f(x+24,y+50);
    glVertex2f(x+25,y+50);
    glEnd();

        //4
    glColor3f(1, 1, 1);// white border
    glBegin(GL_POLYGON);
    glVertex2f(x+10-.1,y+70-.1);
    glVertex2f(x+6+.1,y+66+.1);
    glVertex2f(x+24+.1,y+50+.1);
    glVertex2f(x+25-.1,y+50-.1);
    glEnd();

    glColor3f(0.04, 0.29, 0.43);// base blue
    glBegin(GL_POLYGON);
    glVertex2f(x+10,y+70);
    glVertex2f(x+6,y+66);
    glVertex2f(x+24,y+50);
    glVertex2f(x+25,y+50);
    glEnd();

    glColor3f(0.03, 0.18, 0.28);// dark blue one side border
    glBegin(GL_POLYGON);
    glVertex2f(x+10,y+70);
    glVertex2f(x+9,y+69);
    glVertex2f(x+24,y+50);
    glVertex2f(x+25,y+50);
    glEnd();
}




struct Cloud {
    float x; // Cloud position (x-axis)
    float y; // Cloud position (y-axis)
    float speed; // Cloud speed
};

Cloud myCloud1,myCloud3,myCloud2,myCloud4; // Define a cloud

void cloud(float x, float y){
    
    glColor3f(1.0, 1.0, 1.0); 
    DrawFilledCircle(x, y, 3, 100); 
    DrawFilledCircle(x+2.5, y, 3, 100); 
    DrawFilledCircle(x-2.5, y, 3, 100);
    DrawFilledCircle(x+1.5, y+2.5, 3, 100);
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

    glutPostRedisplay();
    glutTimerFunc(16, update, 0); // 60 FPS
}



float sunX = 100.0f; // Initial sun position (x-axis)
float sunY = 90.0f;  // Initial sun position (y-axis)
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
    float t = (sunY - 45.0f) / 45.0f; // Normalize sun position
    float skyR = (1.0f - t) * nightR + t * dayR;
    float skyG = (1.0f - t) * nightG + t * dayG;
    float skyB = (1.0f - t) * nightB + t * dayB;

    glColor3f(skyR, skyG, skyB); // Set the sky color
    square(0, 45, 70, 150); // Adjust the sky dimensions as needed
}

void keyPress(int key, int x, int y) {
    const float sunSpeed = 1.0f; // Adjust the sun movement speed
    if (key == GLUT_KEY_UP)
        sunY += sunSpeed; // Move the sun up (rise)
    else if (key == GLUT_KEY_DOWN && sunY > 45)
        sunY -= sunSpeed; // Move the sun down (set)
    glutPostRedisplay();
}


void display() {
    // glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    // glOrtho(0, 100, 0, 100, -1, 1);
    // glClear(GL_COLOR_BUFFER_BIT);

    glClear(GL_COLOR_BUFFER_BIT);

    
//////GRASS START///////
    glColor3f(.51, .8, .02);

    square(0,0,300,300);
//////GRASS END///////

// //////SKY START///////
//     glColor3f(.72, .9, .99);
//     square(0,45,70,150) ;

// //////SKY END///////

// ///sun///
// glColor3f(1.0f, 1.0f, 0.0f);
// DrawFilledCircle(100,90,5,100);
drawSky();
    drawSun();

//////CLOUD START/////// 
    cloud(myCloud1.x, 70) ;
    cloud(myCloud2.x, 76) ;
    cloud(myCloud3.x, 68) ;
    cloud(myCloud4.x, 80) ;
 //////CLOUD END///////

//////TREE TOP START///////
for(int x = 0; x <150; x+=10){
    glColor3f( 0.24,.38,0.07);
    glBegin(GL_POLYGON);
    glVertex2f(x,50);
    glVertex2f(x+10,50);
    glVertex2f(x+5,60);
    glEnd();
  
}
//////GRASS TOP START///////
    glBegin(GL_POLYGON);
    glColor3f( 0.24,.38,0.07);
    glVertex2f(0,45+6);
    glVertex2f(200,45+6);
    glVertex2f(200,45+5);
    glVertex2f(0,45+5);

    glEnd();
//////TREE TOP END///////

//////GRASS TOP START///////
    glBegin(GL_POLYGON);
    glColor3f( 0.07,.32,0.17);
    glVertex2f(0,45);
    glVertex2f(200,45);
    glVertex2f(200,45+5);
    glVertex2f(0,45+5);

    glEnd();
    
//////GRASS TOP END///////




//////ROAD START///////
    glBegin(GL_POLYGON);
    glColor3f( 0.26,.25,0.23);
    glVertex2f(0,45);
    glVertex2f(200,45);
    glVertex2f(200,45-8);
    glVertex2f(0,45-8);

    glEnd();
    
//////ROAD END///////

//////CAR START///////
   // Draw both cars
   glColor3f(0.7f, 0.2f, 0.2f);

    drawCar(car1.x, 42.0f);
    glColor3f(.72, .9, .49);

    drawCar(car3.x, 41.0f);
    glColor3f(0.04, 0.29, 0.43);
    drawCar(car2.x, 40.0f);

//////CAR END///////

//////HOUSE1 START///////
    windMill(10, 0);
//////HOUSE1 END///////


//////HOUSE2 START///////
windMill(100,-10);

//////HOUSE2 END///////
///fench///
glColor3f(0.5f, 0.3f, 0.0f); 
for(int i=7;i<60;i+=2){
square(i,11,5,1);
}
square(6,12,1,55);
square(6,14,1,55);


glColor3f(0.5f, 0.3f, 0.0f); 
for(int i=100+7;i<60+100;i+=2){
square(i,11-10,5,1);
}
square(6+100,12-10,1,55);
square(6+100,14-10,1,55);

    glFlush();

}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
        // glutInitDisplayMode ( GLUT_RGB | GLUT_DOUBLE );

    glutCreateWindow("Two lines");
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(1000, 800);
        init();

    // Initialize car positions and speeds
    car1.x = 60.0f;
    car1.y = 40.0f;
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

    glutDisplayFunc(display);
      glutTimerFunc(0, update, 0);
      glutSpecialFunc(keyPress); 
    glutMainLoop();

    return 0;
}



