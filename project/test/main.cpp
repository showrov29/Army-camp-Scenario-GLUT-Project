//#include <windows.h>  // for MS Windows
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h> // GLUT, include glu.h and gl.h
#include<math.h>
# define PI           3.14159265358979323846

GLfloat position = 0.0f;
GLfloat speed = 0.009f;


GLfloat position2 = 0.0f;
GLfloat speed2 = 0.03f;


void update(int value) {

    if(position >2)
        position = -0.2f;

    position += speed; //position=position-speed;1-.1=.9

    glutPostRedisplay();


    glutTimerFunc(100, update, 0);
}



void update2(int value) {

    if(position2 <-2)
        position2 = 0.8f;

    position2 -= speed2; //position=position-speed;1-.1=.9

    glutPostRedisplay();


    glutTimerFunc(100, update2, 0);
}


void Idle()
{
    glutPostRedisplay();//// marks the current window as needing to be redisplayed
}






void display(){

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);





    //Sky//Sky//Sky//Sky//Sky//Sky//Sky//Sky
    glBegin(GL_QUADS);
    glColor3ub(155,206,235);
    glVertex2f(1, 1);
    glVertex2f(-1,1);
    glVertex2f(-1,-1);
    glVertex2f(1,-1);
    glEnd();

    //ground//ground//ground//ground//ground
    glBegin(GL_QUADS);
    glColor3ub(218,182,151);//231,214,200
    glVertex2f(1, -0.1);
    glVertex2f(-1,-0.1);
    glVertex2f(-1,-1);
    glVertex2f(1,-1);
    glEnd();


    //grass 1st portion //grass 1st portion //grass 1st portion //grass 1st portion
    glBegin(GL_QUADS);
    glColor3ub(157,179,120);
    glVertex2f(-0.3, -0.1);
    glVertex2f(-1,-0.1);
    glVertex2f(-1,-0.5);
    glVertex2f(-0.4,-0.5);
    glEnd();



    //grass 2nd portion //grass 2nd portion //grass 2nd portion //grass 2nd portion
    glBegin(GL_QUADS);
    glColor3ub(157,179,120);
    glVertex2f(1, -0.25);
    glVertex2f(0.5,-0.25);
    glVertex2f(0.57,-0.5);
    glVertex2f(1,-0.5);
    glEnd();


    //grass 3rd portion //grass 3rd portion //grass 3rd portion
    glBegin(GL_QUADS);
    glColor3ub(157,179,120);
    glVertex2f(1, -0.7);
    glVertex2f(0.62,-0.7);
    glVertex2f(0.7,-1);
    glVertex2f(1,-1);
    glEnd();


    //shadow//shadow//shadow//shadow 1
    glBegin(GL_QUADS);
    glColor3ub(241,206,176);//231,214,200
    glVertex2f(0.35, -0.1);
    glVertex2f(0.2,-0.1);
    glVertex2f(0.0,-1);
    glVertex2f(0.6,-1);
    glEnd();


    //shadow 2//shadow 2//shadow 2

    glBegin(GL_QUADS);
    glColor3ub(241,206,176);
    glVertex2f(1, -0.18);
    glVertex2f(0.2,-0.18);
    glVertex2f(0.2,-0.22);
    glVertex2f(1,-0.22);
    glEnd();


    //shadow 3//shadow 3//shadow 3

    glBegin(GL_QUADS);
    glColor3ub(241,206,176);
    glVertex2f(1, -0.56);
    glVertex2f(0.2,-0.56);
    glVertex2f(0.2,-0.64);
    glVertex2f(1,-0.64);
    glEnd();


    //shadow 4//shadow 4//shadow 4

    glBegin(GL_QUADS);
    glColor3ub(241,206,176);
    glVertex2f(-0.2, -0.72);
    glVertex2f(-1,-0.72);
    glVertex2f(-1,-0.75);
    glVertex2f(-0.2,-0.75);
    glEnd();

    //shadow 5//shadow 5//shadow 5

    glBegin(GL_QUADS);
    glColor3ub(241,206,176);
    glVertex2f(-0.17, -0.72);
    glVertex2f(-0.2,-0.72);
    glVertex2f(-0.265,-1);
    glVertex2f(-0.235,-01);
    glEnd();



    //Sun //Sun//Sun//Sun//Sun//Sun//Sun
    GLfloat x=0.85; GLfloat y=0.8;GLfloat radius =.123f;
    int triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(249,215,28);
        glVertex2f(x, y); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f(
                    x + (radius * cos(i *  twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();



    //cloud//cloud//cloud//cloud//cloud//cloud//cloud
    glPushMatrix();
    glTranslatef(position,0.0,0);


        //all CLOUD circles//all CLOUD circles//all CLOUD circles//all CLOUD circles//all CLOUD circles
        glLineWidth(1);

        x=-0.92f; y=.725f;radius =.055f;

        int lineAmount = 100; //# of triangles used to draw circle

        //GLfloat radius = 0.8f; //radius
        twicePi = 2.0f * PI;

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(208,222,236);
            for(int i = 0; i <= lineAmount;i++) {
                glVertex2f(
                    x + (radius * cos(i *  twicePi / lineAmount)),
                    y + (radius* sin(i * twicePi / lineAmount))
                );
            }
        glEnd();




        glLineWidth(1);

        x=-0.765f; y=.725f;radius =.045f;

        lineAmount = 100; //# of triangles used to draw circle

        //GLfloat radius = 0.8f; //radius
        twicePi = 2.0f * PI;

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(208,222,236);
            for(int i = 0; i <= lineAmount;i++) {
                glVertex2f(
                    x + (radius * cos(i *  twicePi / lineAmount)),
                    y + (radius* sin(i * twicePi / lineAmount))
                );
            }
        glEnd();



        glLineWidth(1);

        x=-0.85f; y=.75f;radius =.08f;

        lineAmount = 100; //# of triangles used to draw circle

        //GLfloat radius = 0.8f; //radius
        twicePi = 2.0f * PI;

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(208,222,236);
            for(int i = 0; i <= lineAmount;i++) {
                glVertex2f(
                    x + (radius * cos(i *  twicePi / lineAmount)),
                    y + (radius* sin(i * twicePi / lineAmount))
                );
            }
        glEnd();

    glPopMatrix();





    x=-0.85f; y=1.25f;radius =.103f;

    lineAmount = 100; //# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(249,215,28);
        for(int i = 0; i <= lineAmount;i++) {
            glVertex2f(
                x + (radius * cos(i *  twicePi / lineAmount)),
                y + (radius* sin(i * twicePi / lineAmount))
            );
        }
    glEnd();

    x=0.85;y=1.25;radius =.103f;
    triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(249,215,28);
        glVertex2f(x, y); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f(
                    x + (radius * cos(i *  twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();







//part2//part2//part2//part2//part2//part2//part2//part2//part2//part2//part2//part2//part2//part2//part2//part2//part2//part2

    //tower 1//tower 1//tower 1//tower 1

    glBegin(GL_QUADS);//left main bar
    glColor3ub(44,65,43);
    glVertex2f(-0.8, 0.3);
    glVertex2f(-0.83,0.3);
    glVertex2f(-0.83,-0.1);
    glVertex2f(-0.8,-0.1);
    glEnd();

    glBegin(GL_QUADS);//right main bar
    glColor3ub(44,65,43);
    glVertex2f(-0.66, 0.3);
    glVertex2f(-0.69,0.3);
    glVertex2f(-0.69,-0.1);
    glVertex2f(-0.66,-0.1);
    glEnd();


    glBegin(GL_QUADS);//up box
    glColor3ub(44,65,43);
    glVertex2f(-0.63, 0.39);
    glVertex2f(-0.86,0.39);
    glVertex2f(-0.86,0.3);
    glVertex2f(-0.63,0.3);
    glEnd();


    glBegin(GL_QUADS);//left up bar
    glColor3ub(44,65,43);
    glVertex2f(-0.83, 0.49);
    glVertex2f(-0.86,0.49);
    glVertex2f(-0.86,0.39);
    glVertex2f(-0.83,0.39);
    glEnd();


    glBegin(GL_QUADS);//middle up bar
    glColor3ub(44,65,43);
    glVertex2f(-0.73, 0.49);
    glVertex2f(-0.76,0.49);
    glVertex2f(-0.76,0.39);
    glVertex2f(-0.73,0.39);
    glEnd();





    glBegin(GL_QUADS);//right up bar
    glColor3ub(44,65,43);
    glVertex2f(-0.63, 0.49);
    glVertex2f(-0.66,0.49);
    glVertex2f(-0.66,0.39);
    glVertex2f(-0.63,0.39);
    glEnd();



    glBegin(GL_QUADS);//at most  up bar
    glColor3ub(44,65,43);
    glVertex2f(-0.60, 0.52);
    glVertex2f(-0.89,0.52);
    glVertex2f(-0.89,0.49);
    glVertex2f(-0.60,0.49);
    glEnd();

    glLineWidth(3);

    glBegin(GL_LINES);//line
    glColor3ub(44,65,43);
    glVertex2f(-0.66, 0.2);
    glVertex2f(-0.82,0.2);
    glEnd();

    glBegin(GL_LINES);//line
    glColor3ub(44,65,43);
    glVertex2f(-0.66, 0.1);
    glVertex2f(-0.82,0.1);
    glEnd();


    glLineWidth(2);
    glBegin(GL_LINES);//line
    glColor3ub(44,65,43);
    glVertex2f(-0.66, 0.1);
    glVertex2f(-0.82,0.2);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);//line
    glColor3ub(44,65,43);
    glVertex2f(-0.66, 0.2);
    glVertex2f(-0.82,0.1);
    glEnd();



//tower2//tower2//tower2//tower2//tower2//tower2//tower2//tower2//tower2//tower2//tower2//tower2//tower2//tower2

    glPushMatrix();

    glScalef(0.65,0.65,0);
    glTranslatef(1.9,-0.05,0);
    {


        glBegin(GL_QUADS);//left main bar
        glColor3ub(165,152,107);
        glVertex2f(-0.8, 0.3);
        glVertex2f(-0.83,0.3);
        glVertex2f(-0.83,-0.1);
        glVertex2f(-0.8,-0.1);
        glEnd();

        glBegin(GL_QUADS);//right main bar
        glColor3ub(165,152,107);
        glVertex2f(-0.66, 0.3);
        glVertex2f(-0.69,0.3);
        glVertex2f(-0.69,-0.1);
        glVertex2f(-0.66,-0.1);
        glEnd();


        glBegin(GL_QUADS);//up box
        glColor3ub(165,152,107);
        glVertex2f(-0.63, 0.39);
        glVertex2f(-0.86,0.39);
        glVertex2f(-0.86,0.3);
        glVertex2f(-0.63,0.3);
        glEnd();


        glBegin(GL_QUADS);//left up bar
        glColor3ub(165,152,107);
        glVertex2f(-0.83, 0.49);
        glVertex2f(-0.86,0.49);
        glVertex2f(-0.86,0.39);
        glVertex2f(-0.83,0.39);
        glEnd();


        glBegin(GL_QUADS);//middle up bar
        glColor3ub(165,152,107);
        glVertex2f(-0.73, 0.49);
        glVertex2f(-0.76,0.49);
        glVertex2f(-0.76,0.39);
        glVertex2f(-0.73,0.39);
        glEnd();





        glBegin(GL_QUADS);//right up bar
        glColor3ub(165,152,107);
        glVertex2f(-0.63, 0.49);
        glVertex2f(-0.66,0.49);
        glVertex2f(-0.66,0.39);
        glVertex2f(-0.63,0.39);
        glEnd();



        glBegin(GL_QUADS);//at most  up bar
        glColor3ub(165,152,107);
        glVertex2f(-0.60, 0.52);
        glVertex2f(-0.89,0.52);
        glVertex2f(-0.89,0.49);
        glVertex2f(-0.60,0.49);
        glEnd();

        glLineWidth(3);

        glBegin(GL_LINES);//line
        glColor3ub(165,152,107);
        glVertex2f(-0.66, 0.2);
        glVertex2f(-0.82,0.2);
        glEnd();

        glBegin(GL_LINES);//line
        glColor3ub(165,152,107);
        glVertex2f(-0.66, 0.1);
        glVertex2f(-0.82,0.1);
        glEnd();


        glLineWidth(2);
        glBegin(GL_LINES);//line
        glColor3ub(165,152,107);
        glVertex2f(-0.66, 0.1);
        glVertex2f(-0.82,0.2);
        glEnd();

        glLineWidth(2);
        glBegin(GL_LINES);//line
        glColor3ub(165,152,107);
        glVertex2f(-0.66, 0.2);
        glVertex2f(-0.82,0.1);
        glEnd();
    }

    glPopMatrix();


//camp 1//camp 1//camp 1//camp 1//camp 1//camp 1//camp 1//camp 1//camp 1//camp 1//camp 1
    glBegin(GL_POLYGON);
    glColor3ub(130,134,107);
    glVertex2f(-0.63, -0.1);
    glVertex2f(-0.78, -0.0);
    glVertex2f(-0.92,-0.1);
    glVertex2f(-0.92,-0.3);
    glVertex2f(-0.63,-0.3);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(75,83,32);
    glVertex2f(-0.65, -0.1);
    glVertex2f(-0.78, -0.02);
    glVertex2f(-0.90,-0.1);
    glVertex2f(-0.90,-0.3);
    glVertex2f(-0.65,-0.3);
    glEnd();



    glBegin(GL_QUADS);
    glColor3ub(10,10,0);
    glVertex2f(-0.72, -0.15);
    glVertex2f(-0.83,-0.15);
    glVertex2f(-0.83,-0.3);
    glVertex2f(-0.72,-0.3);
    glEnd();

//camp 2//camp 2//camp 2//camp 2//camp 2//camp 2//camp 2//camp 2//camp 2//camp 2//camp 2

    glPushMatrix();
    glScalef(0.7,0.7,0);
    glTranslatef(0.1,0.1,0);
    {


        glBegin(GL_POLYGON);
        glColor3ub(130,134,107);
        glVertex2f(-0.63, -0.1);
        glVertex2f(-0.78, -0.0);
        glVertex2f(-0.92,-0.1);
        glVertex2f(-0.92,-0.3);
        glVertex2f(-0.63,-0.3);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(75,83,32);
        glVertex2f(-0.65, -0.1);
        glVertex2f(-0.78, -0.02);
        glVertex2f(-0.90,-0.1);
        glVertex2f(-0.90,-0.3);
        glVertex2f(-0.65,-0.3);
        glEnd();



        glBegin(GL_QUADS);
        glColor3ub(10,10,0);
        glVertex2f(-0.72, -0.15);
        glVertex2f(-0.83,-0.15);
        glVertex2f(-0.83,-0.3);
        glVertex2f(-0.72,-0.3);
        glEnd();
    }

    glPopMatrix();




//plan1//plan1//plan1//plan1//plan1//plan1//plan1//plan1//plan1//plan1//plan1//plan1
    glPushMatrix();
    glTranslatef(position2,0.0,0);
        glBegin(GL_QUADS);
        glColor3ub(114,122,90);
        glVertex2f(0.6, 0.88);
        glVertex2f(0.2,0.9);
        glVertex2f(0.2,0.8);
        glVertex2f(0.6,0.83);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(114,122,90);
        glVertex2f(0.6, 0.95);
        glVertex2f(0.57,0.95);
        glVertex2f(0.5,0.85);
        glVertex2f(0.6,0.85);
        glEnd();




        //plane head//plane head//plane head//plane head//plane head
        x=0.2;y=0.85;radius =.052f;
        triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

        //GLfloat radius = 0.8f; //radius
        twicePi = 2.0f * PI;

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(114,122,90);
            glVertex2f(x, y); // center of circle
            for(int i = 0; i <= triangleAmount;i++) {
                glVertex2f(
                        x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount))
                );
            }
        glEnd();

        //wheel//wheel//wheel//wheel//wheel//wheel//wheel//wheel111111111111
        glBegin(GL_LINES);//wheel bar
        glColor3f(255,255,255);
        glVertex2f(0.25, 0.81);
        glVertex2f(0.25, 0.75);
        glEnd();





        x=0.25;y=0.76;radius =.025f;
        triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

        //GLfloat radius = 0.8f; //radius
        twicePi = 2.0f * PI;

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(0,0,0);
            glVertex2f(x, y); // center of circle
            for(int i = 0; i <= triangleAmount;i++) {
                glVertex2f(
                        x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount))
                );
            }
        glEnd();


    //    wheel//wheel//wheel//wheel//wheel//wheel//wheel//wheel22222222222222222222222
        glBegin(GL_LINES);//wheel bar
        glColor3f(255,255,255);
        glVertex2f(0.45, 0.83);
        glVertex2f(0.45, 0.77);
        glEnd();


        x=0.45;y=0.76;radius =.025f;
        triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

        //GLfloat radius = 0.8f; //radius
        twicePi = 2.0f * PI;

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(0,0,0);
            glVertex2f(x, y); // center of circle
            for(int i = 0; i <= triangleAmount;i++) {
                glVertex2f(
                        x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount))
                );
            }
        glEnd();



        glBegin(GL_QUADS);//wings 1
        glColor3ub(193,202,165);
        glVertex2f(0.33, 0.84);
        glVertex2f(0.27,0.845);
        glVertex2f(0.37,0.76);
        glVertex2f(0.41, 0.76);
        glEnd();




        glBegin(GL_QUADS);//window 1
        glColor3ub(9,58,91);
        glVertex2f(0.24, 0.87);
        glVertex2f(0.2,0.87);
        glVertex2f(0.2,0.84);
        glVertex2f(0.24, 0.84);
        glEnd();



        glBegin(GL_QUADS);//window 2
        glColor3ub(9,58,91);
        glVertex2f(0.33, 0.865);
        glVertex2f(0.30,0.865);
        glVertex2f(0.30,0.85);
        glVertex2f(0.33, 0.85);
        glEnd();

        glBegin(GL_QUADS);//window 3
        glColor3ub(9,58,91);
        glVertex2f(0.39, 0.865);
        glVertex2f(0.36,0.865);
        glVertex2f(0.36,0.85);
        glVertex2f(0.39, 0.85);
        glEnd();


    glPopMatrix();



//plan 2//plan 2//plan 2//plan 2//plan 2//plan 2//plan 2//plan 2//plan 2
    glPushMatrix();
    glScalef(0.7,0.7,0);
    glTranslatef(0.5,-1.0,0);
    {

        glBegin(GL_QUADS);
        glColor3ub(114,122,90);
        glVertex2f(0.6, 0.88);
        glVertex2f(0.2,0.9);
        glVertex2f(0.2,0.8);
        glVertex2f(0.6,0.83);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(114,122,90);
        glVertex2f(0.6, 0.95);
        glVertex2f(0.57,0.95);
        glVertex2f(0.5,0.85);
        glVertex2f(0.6,0.85);
        glEnd();




        //plane head//plane head//plane head//plane head//plane head
        x=0.2;y=0.85;radius =.052f;
        triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

        //GLfloat radius = 0.8f; //radius
        twicePi = 2.0f * PI;

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(114,122,90);
            glVertex2f(x, y); // center of circle
            for(int i = 0; i <= triangleAmount;i++) {
                glVertex2f(
                        x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount))
                );
            }
        glEnd();

        //wheel//wheel//wheel//wheel//wheel//wheel//wheel//wheel111111111111
        glBegin(GL_LINES);//wheel bar
        glColor3f(255,255,255);
        glVertex2f(0.25, 0.81);
        glVertex2f(0.25, 0.75);
        glEnd();





        x=0.25;y=0.76;radius =.025f;
        triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

        //GLfloat radius = 0.8f; //radius
        twicePi = 2.0f * PI;

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(0,0,0);
            glVertex2f(x, y); // center of circle
            for(int i = 0; i <= triangleAmount;i++) {
                glVertex2f(
                        x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount))
                );
            }
        glEnd();


    //    wheel//wheel//wheel//wheel//wheel//wheel//wheel//wheel22222222222222222222222
        glBegin(GL_LINES);//wheel bar
        glColor3f(255,255,255);
        glVertex2f(0.45, 0.83);
        glVertex2f(0.45, 0.77);
        glEnd();


        x=0.45;y=0.76;radius =.025f;
        triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

        //GLfloat radius = 0.8f; //radius
        twicePi = 2.0f * PI;

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(0,0,0);
            glVertex2f(x, y); // center of circle
            for(int i = 0; i <= triangleAmount;i++) {
                glVertex2f(
                        x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount))
                );
            }
        glEnd();



        glBegin(GL_QUADS);//wings 1
        glColor3ub(193,202,165);
        glVertex2f(0.33, 0.84);
        glVertex2f(0.27,0.845);
        glVertex2f(0.37,0.76);
        glVertex2f(0.41, 0.76);
        glEnd();




        glBegin(GL_QUADS);//window 1
        glColor3ub(9,58,91);
        glVertex2f(0.24, 0.87);
        glVertex2f(0.2,0.87);
        glVertex2f(0.2,0.84);
        glVertex2f(0.24, 0.84);
        glEnd();



        glBegin(GL_QUADS);//window 2
        glColor3ub(9,58,91);
        glVertex2f(0.33, 0.865);
        glVertex2f(0.30,0.865);
        glVertex2f(0.30,0.85);
        glVertex2f(0.33, 0.85);
        glEnd();

        glBegin(GL_QUADS);//window 3
        glColor3ub(9,58,91);
        glVertex2f(0.39, 0.865);
        glVertex2f(0.36,0.865);
        glVertex2f(0.36,0.85);
        glVertex2f(0.39, 0.85);
        glEnd();
    }
    glPopMatrix();




//part3//part3//part3//part3//part3//part3//part3//part3//part3//part3//part3//part3//part3//part3//part3//part3

    //mini car///mini car///mini car///mini car///mini car///mini car/
    /*
    glBegin(GL_QUADS);//
    glColor3ub(75,83,32);
    glVertex2f(0.9, -0.3);
    glVertex2f(0.6,-0.3);
    glVertex2f(0.6,-0.4);
    glVertex2f(0.9, -0.4);
    glEnd();
*/
    glBegin(GL_QUADS);//
    glColor3ub(75,83,32);
    glVertex2f(0.7, -0.32);
    glVertex2f(0.6,-0.35);
    glVertex2f(0.6,-0.42);
    glVertex2f(0.7, -0.42);
    glEnd();


    glBegin(GL_QUADS);//
    glColor3ub(75,83,32);
    glVertex2f(0.9, -0.35);
    glVertex2f(0.7,-0.35);
    glVertex2f(0.7,-0.42);
    glVertex2f(0.9, -0.42);
    glEnd();


    glLineWidth(3);
    glBegin(GL_LINES);//
    glColor3ub(75,83,32);
    glVertex2f(0.77, -0.3);
    glVertex2f(0.75,-0.42);
    glEnd();


    glBegin(GL_QUADS);//
    glColor3ub(75,83,32);
    glVertex2f(0.9, -0.33);
    glVertex2f(0.82,-0.33);
    glVertex2f(0.8,-0.42);
    glVertex2f(0.9, -0.42);
    glEnd();




//    wheel//wheel//wheel//wheel//wheel//wheel//wheel//


    x=0.82;y=-0.42;radius =.037f;
    triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0,0,0);
        glVertex2f(x, y); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f(
                    x + (radius * cos(i *  twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();


     x=0.82;y=-0.42;radius =.019f;
    triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(164,141,12);
        glVertex2f(x, y); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f(
                    x + (radius * cos(i *  twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();



    x=0.82;y=-0.42;radius =.036f;
    triangleAmount = 50; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    twicePi = 2.0f * PI;

    glBegin(GL_LINES);
    glColor3ub(133,121,5);
        glVertex2f(x, y); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f(
                    x + (radius * cos(i *  twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();






    //    wheel//wheel//wheel//wheel//wheel//wheel//wheel//


    x=0.68;y=-0.42;radius =.037f;
    triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0,10,0);
        glVertex2f(x, y); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f(
                    x + (radius * cos(i *  twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();


    x=0.68;y=-0.42;radius =.019f;
    triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(164,141,12);
        glVertex2f(x, y); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f(
                    x + (radius * cos(i *  twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();



    x=0.68;y=-0.42;radius =.036f;
    triangleAmount = 50; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    twicePi = 2.0f * PI;

    glBegin(GL_LINES);
    glColor3ub(133,121,5);
        glVertex2f(x, y); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f(
                    x + (radius * cos(i *  twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();




 //bullet proof car //bullet proof car     //bullet proof car     //bullet proof car     //bullet proof car

/*
    glBegin(GL_QUADS);//
    glColor3ub(75,83,32);//75,83,32
    glVertex2f(0.0, -0.25);
    glVertex2f(-0.5,-0.25);
    glVertex2f(-0.5,-0.45);
    glVertex2f(0.0, -0.45);
    glEnd();
    */

    glBegin(GL_QUADS);//
    glColor3ub(10,10,0);//75,83,32//114,122,90
    glVertex2f(-0.16, -0.25);
    glVertex2f(-0.5,-0.25);
    glVertex2f(-0.5,-0.45);
    glVertex2f(-0.01, -0.45);
    glEnd();

    glBegin(GL_QUADS);//
    glColor3ub(75,83,325);//75,83,32//75,83,325//82,95,43
    glVertex2f(-0.15, -0.25);
    glVertex2f(-0.25,-0.25);
    glVertex2f(-0.25,-0.39);
    glVertex2f(-0.05, -0.39);
    glEnd();

    glBegin(GL_QUADS);//
    glColor3ub(75,83,325);//75,83,32
    glVertex2f(0.0, -0.36);
    glVertex2f(-0.2,-0.30);
    glVertex2f(-0.2,-0.39);
    glVertex2f(0.0, -0.39);
    glEnd();

    glBegin(GL_QUADS);//
    glColor3ub(75,83,325);//75,83,32
    glVertex2f(0.02, -0.38);
    glVertex2f(-0.1,-0.38);
    glVertex2f(-0.04,-0.45);
    glVertex2f(0.0, -0.45);
    glEnd();



    glBegin(GL_QUADS);//
    glColor3ub(75,835,325);//75,83,32
    glVertex2f(-0.15, -0.38);
    glVertex2f(-0.25,-0.38);
    glVertex2f(-0.25,-0.45);
    glVertex2f(-0.2, -0.45);
    glEnd();



    glBegin(GL_QUADS);//
    glColor3ub(114,122,90);//75,83,32
    glVertex2f(-0.25, -0.4);
    glVertex2f(-0.32,-0.4);
    glVertex2f(-0.32,-0.43);
    glVertex2f(-0.25, -0.43);
    glEnd();


    //lower all line //lower all line //lower all line //lower all line

    glBegin(GL_LINES);
    glColor3ub(114,122,90);//75,83,32
    glVertex2f(-0.32, -0.415);
    glVertex2f(-0.37,-0.415);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(114,122,90);//75,83,32
    glVertex2f(-0.38, -0.39);
    glVertex2f(-0.35,-0.45);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(114,122,90);//75,83,32
    glVertex2f(-0.38, -0.39);
    glVertex2f(-0.45,-0.39);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(114,122,90);//75,83,32
    glVertex2f(-0.45, -0.39);
    glVertex2f(-0.48,-0.45);
    glEnd();


    glBegin(GL_QUADS);//
    glColor3ub(75,83,32);//75,83,32
    glVertex2f(-0.26, -0.33);
    glVertex2f(-0.5,-0.33);
    glVertex2f(-0.5,-0.37);
    glVertex2f(-0.26, -0.37);
    glEnd();

    glBegin(GL_QUADS);//
    glColor3ub(116,122,95);//75,83,32
    glVertex2f(-0.26, -0.21);
    glVertex2f(-0.5,-0.21);
    glVertex2f(-0.5,-0.33);
    glVertex2f(-0.26, -0.33);
    glEnd();

    //window
    glBegin(GL_QUADS);//
    glColor3ub(9,58,91);//75,83,32
    glVertex2f(-0.17, -0.26);
    glVertex2f(-0.23,-0.26);
    glVertex2f(-0.23,-0.34);
    glVertex2f(-0.11, -0.34);
    glEnd();



//    wheel//wheel//wheel//wheel//wheel//wheel//wheel//


    x=-0.42;y=-0.45;radius =.041f;
    triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(10,10,6);
        glVertex2f(x, y); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f(
                    x + (radius * cos(i *  twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();


     x=-0.42;y=-0.45;radius =.021f;
    triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(164,141,12);
        glVertex2f(x, y); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f(
                    x + (radius * cos(i *  twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();



    x=-0.42;y=-0.45;radius =.041f;
    triangleAmount = 30; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    twicePi = 2.0f * PI;

    glBegin(GL_LINES);
    glColor3ub(133,121,5);
        glVertex2f(x, y); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f(
                    x + (radius * cos(i *  twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();



//    wheel//wheel//wheel//wheel//wheel//wheel//wheel//


    x=-0.125;y=-0.45;radius =.041f;
    triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(10,10,6);
        glVertex2f(x, y); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f(
                    x + (radius * cos(i *  twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();


     x=-0.125;y=-0.45;radius =.021f;
    triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(164,141,12);
        glVertex2f(x, y); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f(
                    x + (radius * cos(i *  twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();



    x=-0.125;y=-0.45;radius =.041f;
    triangleAmount = 30; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    twicePi = 2.0f * PI;

    glBegin(GL_LINES);
    glColor3ub(133,121,5);
        glVertex2f(x, y); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f(
                    x + (radius * cos(i *  twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();


//panzer//panzer//panzer//panzer//panzer//panzer//panzer//panzer//panzer//panzer//panzer//panzer//panzer

    //3rd layer//3rd layer//3rd layer//3rd layer
    glBegin(GL_QUADS);//
    glColor3ub(10,10,6);//75,83,32
    glVertex2f(-0.25, -0.7);
    glVertex2f(-0.9,-0.7);
    glVertex2f(-0.9,-0.8);
    glVertex2f(-0.25, -0.8);
    glEnd();


    glBegin(GL_POLYGON);//
    glColor3ub(75,83,32);//75,83,32

    glVertex2f(-0.35, -0.62);

    glVertex2f(-0.8,-0.62);

    glVertex2f(-0.9,-0.7);
    glVertex2f(-0.25, -0.7);
    glEnd();

/*
    glBegin(GL_QUADS);//
    glColor3ub(75,83,32);//75,83,32
    glVertex2f(-0.47, -0.51);
    glVertex2f(-0.68,-0.51);
    glVertex2f(-0.68,-0.61);
    glVertex2f(-0.47, -0.61);
    glEnd();
*/

    //shooting pipe//shooting pipe//shooting pipe//shooting pipe
    glBegin(GL_QUADS);//
    glColor3ub(56,64,26);//75,83,32
    glVertex2f(-0.39, -0.525);
    glVertex2f(-0.5,-0.525);
    glVertex2f(-0.5,-0.55);
    glVertex2f(-0.39, -0.55);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);//
    glColor3ub(75,83,32);//75,83,32
    glVertex2f(-0.21, -0.537);
    glVertex2f(-0.39,-0.537);
    glEnd();

    glBegin(GL_QUADS);//
    glColor3ub(56,64,26);//75,83,32
    glVertex2f(-0.15, -0.525);
    glVertex2f(-0.21,-0.525);
    glVertex2f(-0.21,-0.55);
    glVertex2f(-0.15, -0.55);
    glEnd();


    //2nd layer //2nd layer//2nd layer//2nd layer
    glBegin(GL_QUADS);//
    glColor3ub(10,10,6);//75,83,32
    glVertex2f(-0.47, -0.56);
    glVertex2f(-0.68,-0.56);
    glVertex2f(-0.68,-0.62);
    glVertex2f(-0.47, -0.62);
    glEnd();

    glBegin(GL_QUADS);//
    glColor3ub(75,83,32);//75,83,32
    glVertex2f(-0.43, -0.56);
    glVertex2f(-0.72,-0.56);
    glVertex2f(-0.68,-0.61);
    glVertex2f(-0.47, -0.61);
    glEnd();

    glBegin(GL_QUADS);//
    glColor3ub(75,83,32);//75,83,32
    glVertex2f(-0.47, -0.51);
    glVertex2f(-0.68,-0.51);
    glVertex2f(-0.72,-0.56);
    glVertex2f(-0.43, -0.56);
    glEnd();


    //1st layer //1st layer //1st layer //1st layer //1st layer
    glBegin(GL_QUADS);//
    glColor3ub(10,10,6);//75,83,32
    glVertex2f(-0.54, -0.47);
    glVertex2f(-0.63,-0.47);
    glVertex2f(-0.63,-0.51);
    glVertex2f(-0.54, -0.51);
    glEnd();



    glBegin(GL_QUADS);//
    glColor3ub(75,83,32);//75,83,32
    glVertex2f(-0.54, -0.47);
    glVertex2f(-0.63,-0.47);
    glVertex2f(-0.63,-0.505);
    glVertex2f(-0.54, -0.505);
    glEnd();


    glLineWidth(2);
    glBegin(GL_LINES);//
    glColor3ub(75,83,32);//75,83,32
    glVertex2f(-0.5, -0.49);
    glVertex2f(-0.54,-0.49);
    glEnd();

    glBegin(GL_QUADS);//
    glColor3ub(75,83,32);//75,83,32
    glVertex2f(-0.47, -0.48);
    glVertex2f(-0.5,-0.48);
    glVertex2f(-0.5,-0.5);
    glVertex2f(-0.47, -0.5);
    glEnd();



    //body circle //body circle //body circle //body circle //body circle //body circle


    x=-0.78;y=-0.66;radius =.015f;
    triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(114,122,90);
        glVertex2f(x, y); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f(
                    x + (radius * cos(i *  twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();


    x=-0.68;y=-0.66;radius =.015f;
    triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(114,122,90);
        glVertex2f(x, y); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f(
                    x + (radius * cos(i *  twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();

     x=-0.58;y=-0.66;radius =.015f;
    triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(114,122,90);
        glVertex2f(x, y); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f(
                    x + (radius * cos(i *  twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();


     x=-0.48;y=-0.66;radius =.015f;
    triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(114,122,90);
        glVertex2f(x, y); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f(
                    x + (radius * cos(i *  twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();


     x=-0.38;y=-0.66;radius =.015f;
    triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(114,122,90);
        glVertex2f(x, y); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f(
                    x + (radius * cos(i *  twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();




    //2nd layer all circle
    x=-0.64;y=-0.56;radius =.012f;
    triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(114,122,90);
        glVertex2f(x, y); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f(
                    x + (radius * cos(i *  twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();


    x=-0.59;y=-0.56;radius =.012f;
    triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(114,122,90);
        glVertex2f(x, y); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f(
                    x + (radius * cos(i *  twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();



    x=-0.54;y=-0.56;radius =.012f;
    triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(114,122,90);
        glVertex2f(x, y); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f(
                    x + (radius * cos(i *  twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();



    //3rd layer circle

    x=-0.585;y=-0.49;radius =.01f;
    triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(114,122,90);
        glVertex2f(x, y); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f(
                    x + (radius * cos(i *  twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();




//    wheel 1

    //rounding circle //rounding circle//rounding circle//rounding circle
    x=-0.91;y=-0.74;radius =.056f;
    triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(10,10,6);
        glVertex2f(x, y); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f(
                    x + (radius * cos(i *  twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();


    x=-0.25;y=-0.74;radius =.056f;
    triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(10,10,6);
        glVertex2f(x, y); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f(
                    x + (radius * cos(i *  twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();



//panzer wheel//panzer wheel//panzer wheel//panzer wheel//panzer wheel//panzer wheel


    //1st wheel//1st wheel//1st wheel
    x=-0.91;y=-0.74;radius =.043f;
    triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(78,87,46);
        glVertex2f(x, y); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f(
                    x + (radius * cos(i *  twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();


     x=-0.91;y=-0.74;radius =.021f;
    triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(164,141,12);
        glVertex2f(x, y); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f(
                    x + (radius * cos(i *  twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();



    x=-0.91;y=-0.74;radius =.045f;
    triangleAmount = 30; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    twicePi = 2.0f * PI;

    glBegin(GL_LINES);
    glColor3ub(133,121,5);
        glVertex2f(x, y); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f(
                    x + (radius * cos(i *  twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();





    //2nd wheel//2nd wheel//2nd wheel//2nd wheel//2nd wheel//2nd wheel
    x=-0.815;y=-0.75;radius =.0425f;
    triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(78,87,46);
        glVertex2f(x, y); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f(
                    x + (radius * cos(i *  twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();


     x=-0.815;y=-0.75;radius =.021f;
    triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(164,141,12);
        glVertex2f(x, y); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f(
                    x + (radius * cos(i *  twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();



    x=-0.815;y=-0.75;radius =.045f;
    triangleAmount = 30; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    twicePi = 2.0f * PI;

    glBegin(GL_LINES);
    glColor3ub(133,121,5);
        glVertex2f(x, y); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f(
                    x + (radius * cos(i *  twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();




    //3rd wheel//3rd wheel//3rd wheel/
    x=-0.715;y=-0.75;radius =.0425f;
    triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(78,87,46);
        glVertex2f(x, y); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f(
                    x + (radius * cos(i *  twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();


     x=-0.715;y=-0.75;radius =.021f;
    triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(164,141,12);
        glVertex2f(x, y); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f(
                    x + (radius * cos(i *  twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();



    x=-0.715;y=-0.75;radius =.045f;
    triangleAmount = 30; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    twicePi = 2.0f * PI;

    glBegin(GL_LINES);
    glColor3ub(133,121,5);
        glVertex2f(x, y); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f(
                    x + (radius * cos(i *  twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();




    //4th wheel//4th wheel//4th wheel/
    x=-0.615;y=-0.75;radius =.0425f;
    triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(78,87,46);
        glVertex2f(x, y); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f(
                    x + (radius * cos(i *  twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();


     x=-0.615;y=-0.75;radius =.021f;
    triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(164,141,12);
        glVertex2f(x, y); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f(
                    x + (radius * cos(i *  twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();



    x=-0.615;y=-0.75;radius =.045f;
    triangleAmount = 30; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    twicePi = 2.0f * PI;

    glBegin(GL_LINES);
    glColor3ub(133,121,5);
        glVertex2f(x, y); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f(
                    x + (radius * cos(i *  twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();






    //5th wheel//5th wheel//5th wheel/
    x=-0.515;y=-0.75;radius =.0425f;
    triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(78,87,46);
        glVertex2f(x, y); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f(
                    x + (radius * cos(i *  twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();


     x=-0.515;y=-0.75;radius =.021f;
    triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(164,141,12);
        glVertex2f(x, y); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f(
                    x + (radius * cos(i *  twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();



    x=-0.515;y=-0.75;radius =.045f;
    triangleAmount = 30; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    twicePi = 2.0f * PI;

    glBegin(GL_LINES);
    glColor3ub(133,121,5);
        glVertex2f(x, y); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f(
                    x + (radius * cos(i *  twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();



     //6th wheel//6th wheel//6th wheel/
    x=-0.415;y=-0.75;radius =.0425f;
    triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(78,87,46);
        glVertex2f(x, y); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f(
                    x + (radius * cos(i *  twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();


     x=-0.415;y=-0.75;radius =.021f;
    triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(164,141,12);
        glVertex2f(x, y); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f(
                    x + (radius * cos(i *  twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();



    x=-0.415;y=-0.75;radius =.045f;
    triangleAmount = 30; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    twicePi = 2.0f * PI;

    glBegin(GL_LINES);
    glColor3ub(133,121,5);
        glVertex2f(x, y); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f(
                    x + (radius * cos(i *  twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();




     //7th wheel//7th wheel//7th wheel/
    x=-0.335;y=-0.75;radius =.0405f;
    triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(78,87,46);
        glVertex2f(x, y); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f(
                    x + (radius * cos(i *  twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();


     x=-0.335;y=-0.75;radius =.021f;
    triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(164,141,12);
        glVertex2f(x, y); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f(
                    x + (radius * cos(i *  twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();



    x=-0.335;y=-0.75;radius =.0405f;
    triangleAmount = 30; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    twicePi = 2.0f * PI;

    glBegin(GL_LINES);
    glColor3ub(133,121,5);
        glVertex2f(x, y); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f(
                    x + (radius * cos(i *  twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();













    //last wheel//last wheel//last wheel//last wheel//last wheel

    x=-0.25;y=-0.74;radius =.043f;
    triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(78,87,46);
        glVertex2f(x, y); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f(
                    x + (radius * cos(i *  twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();


     x=-0.25;y=-0.74;radius =.021f;
    triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(164,141,12);
        glVertex2f(x, y); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f(
                    x + (radius * cos(i *  twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();



    x=-0.25;y=-0.74;radius =.045f;
    triangleAmount = 30; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    twicePi = 2.0f * PI;

    glBegin(GL_LINES);
    glColor3ub(133,121,5);
        glVertex2f(x, y); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f(
                    x + (radius * cos(i *  twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();








//mini panzer 2////mini panzer 2//mini panzer 2//mini panzer 2//mini panzer 2//mini panzer 2//mini panzer 2

    glPushMatrix();
    glScalef(0.6,0.6,0);
    glTranslatef(0.455,0.47,0);
        //3rd layer//3rd layer//3rd layer//3rd layer
        glBegin(GL_QUADS);//
        glColor3ub(10,10,6);//75,83,32
        glVertex2f(-0.25, -0.7);
        glVertex2f(-0.9,-0.7);
        glVertex2f(-0.9,-0.8);
        glVertex2f(-0.25, -0.8);
        glEnd();


        glBegin(GL_POLYGON);//
        glColor3ub(75,83,32);//75,83,32

        glVertex2f(-0.35, -0.62);

        glVertex2f(-0.8,-0.62);

        glVertex2f(-0.9,-0.7);
        glVertex2f(-0.25, -0.7);
        glEnd();

    /*
        glBegin(GL_QUADS);//
        glColor3ub(75,83,32);//75,83,32
        glVertex2f(-0.47, -0.51);
        glVertex2f(-0.68,-0.51);
        glVertex2f(-0.68,-0.61);
        glVertex2f(-0.47, -0.61);
        glEnd();
    */

        //shooting pipe//shooting pipe//shooting pipe//shooting pipe
        glBegin(GL_QUADS);//
        glColor3ub(56,64,26);//75,83,32
        glVertex2f(-0.39, -0.525);
        glVertex2f(-0.5,-0.525);
        glVertex2f(-0.5,-0.55);
        glVertex2f(-0.39, -0.55);
        glEnd();

        glLineWidth(3);
        glBegin(GL_LINES);//
        glColor3ub(75,83,32);//75,83,32
        glVertex2f(-0.21, -0.537);
        glVertex2f(-0.39,-0.537);
        glEnd();

        glBegin(GL_QUADS);//
        glColor3ub(56,64,26);//75,83,32
        glVertex2f(-0.15, -0.525);
        glVertex2f(-0.21,-0.525);
        glVertex2f(-0.21,-0.55);
        glVertex2f(-0.15, -0.55);
        glEnd();


        //2nd layer //2nd layer//2nd layer//2nd layer
        glBegin(GL_QUADS);//
        glColor3ub(10,10,6);//75,83,32
        glVertex2f(-0.47, -0.56);
        glVertex2f(-0.68,-0.56);
        glVertex2f(-0.68,-0.62);
        glVertex2f(-0.47, -0.62);
        glEnd();

        glBegin(GL_QUADS);//
        glColor3ub(75,83,32);//75,83,32
        glVertex2f(-0.43, -0.56);
        glVertex2f(-0.72,-0.56);
        glVertex2f(-0.68,-0.61);
        glVertex2f(-0.47, -0.61);
        glEnd();

        glBegin(GL_QUADS);//
        glColor3ub(75,83,32);//75,83,32
        glVertex2f(-0.47, -0.51);
        glVertex2f(-0.68,-0.51);
        glVertex2f(-0.72,-0.56);
        glVertex2f(-0.43, -0.56);
        glEnd();


        //1st layer //1st layer //1st layer //1st layer //1st layer
        glBegin(GL_QUADS);//
        glColor3ub(10,10,6);//75,83,32
        glVertex2f(-0.54, -0.47);
        glVertex2f(-0.63,-0.47);
        glVertex2f(-0.63,-0.51);
        glVertex2f(-0.54, -0.51);
        glEnd();



        glBegin(GL_QUADS);//
        glColor3ub(75,83,32);//75,83,32
        glVertex2f(-0.54, -0.47);
        glVertex2f(-0.63,-0.47);
        glVertex2f(-0.63,-0.505);
        glVertex2f(-0.54, -0.505);
        glEnd();


        glLineWidth(2);
        glBegin(GL_LINES);//
        glColor3ub(75,83,32);//75,83,32
        glVertex2f(-0.5, -0.49);
        glVertex2f(-0.54,-0.49);
        glEnd();

        glBegin(GL_QUADS);//
        glColor3ub(75,83,32);//75,83,32
        glVertex2f(-0.47, -0.48);
        glVertex2f(-0.5,-0.48);
        glVertex2f(-0.5,-0.5);
        glVertex2f(-0.47, -0.5);
        glEnd();



        //body circle //body circle //body circle //body circle //body circle //body circle


        x=-0.78;y=-0.66;radius =.015f;
        triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

        //GLfloat radius = 0.8f; //radius
        twicePi = 2.0f * PI;

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(114,122,90);
            glVertex2f(x, y); // center of circle
            for(int i = 0; i <= triangleAmount;i++) {
                glVertex2f(
                        x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount))
                );
            }
        glEnd();


        x=-0.68;y=-0.66;radius =.015f;
        triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

        //GLfloat radius = 0.8f; //radius
        twicePi = 2.0f * PI;

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(114,122,90);
            glVertex2f(x, y); // center of circle
            for(int i = 0; i <= triangleAmount;i++) {
                glVertex2f(
                        x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount))
                );
            }
        glEnd();

         x=-0.58;y=-0.66;radius =.015f;
        triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

        //GLfloat radius = 0.8f; //radius
        twicePi = 2.0f * PI;

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(114,122,90);
            glVertex2f(x, y); // center of circle
            for(int i = 0; i <= triangleAmount;i++) {
                glVertex2f(
                        x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount))
                );
            }
        glEnd();


         x=-0.48;y=-0.66;radius =.015f;
        triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

        //GLfloat radius = 0.8f; //radius
        twicePi = 2.0f * PI;

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(114,122,90);
            glVertex2f(x, y); // center of circle
            for(int i = 0; i <= triangleAmount;i++) {
                glVertex2f(
                        x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount))
                );
            }
        glEnd();


         x=-0.38;y=-0.66;radius =.015f;
        triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

        //GLfloat radius = 0.8f; //radius
        twicePi = 2.0f * PI;

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(114,122,90);
            glVertex2f(x, y); // center of circle
            for(int i = 0; i <= triangleAmount;i++) {
                glVertex2f(
                        x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount))
                );
            }
        glEnd();




        //2nd layer all circle
        x=-0.64;y=-0.56;radius =.012f;
        triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

        //GLfloat radius = 0.8f; //radius
        twicePi = 2.0f * PI;

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(114,122,90);
            glVertex2f(x, y); // center of circle
            for(int i = 0; i <= triangleAmount;i++) {
                glVertex2f(
                        x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount))
                );
            }
        glEnd();


        x=-0.59;y=-0.56;radius =.012f;
        triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

        //GLfloat radius = 0.8f; //radius
        twicePi = 2.0f * PI;

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(114,122,90);
            glVertex2f(x, y); // center of circle
            for(int i = 0; i <= triangleAmount;i++) {
                glVertex2f(
                        x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount))
                );
            }
        glEnd();



        x=-0.54;y=-0.56;radius =.012f;
        triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

        //GLfloat radius = 0.8f; //radius
        twicePi = 2.0f * PI;

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(114,122,90);
            glVertex2f(x, y); // center of circle
            for(int i = 0; i <= triangleAmount;i++) {
                glVertex2f(
                        x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount))
                );
            }
        glEnd();



        //3rd layer circle

        x=-0.585;y=-0.49;radius =.01f;
        triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

        //GLfloat radius = 0.8f; //radius
        twicePi = 2.0f * PI;

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(114,122,90);
            glVertex2f(x, y); // center of circle
            for(int i = 0; i <= triangleAmount;i++) {
                glVertex2f(
                        x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount))
                );
            }
        glEnd();




    //    wheel 1

        //rounding circle //rounding circle//rounding circle//rounding circle
        x=-0.91;y=-0.74;radius =.056f;
        triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

        //GLfloat radius = 0.8f; //radius
        twicePi = 2.0f * PI;

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(10,10,6);
            glVertex2f(x, y); // center of circle
            for(int i = 0; i <= triangleAmount;i++) {
                glVertex2f(
                        x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount))
                );
            }
        glEnd();


        x=-0.25;y=-0.74;radius =.056f;
        triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

        //GLfloat radius = 0.8f; //radius
        twicePi = 2.0f * PI;

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(10,10,6);
            glVertex2f(x, y); // center of circle
            for(int i = 0; i <= triangleAmount;i++) {
                glVertex2f(
                        x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount))
                );
            }
        glEnd();



    //panzer wheel//panzer wheel//panzer wheel//panzer wheel//panzer wheel//panzer wheel


        //1st wheel//1st wheel//1st wheel
        x=-0.91;y=-0.74;radius =.043f;
        triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

        //GLfloat radius = 0.8f; //radius
        twicePi = 2.0f * PI;

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(78,87,46);
            glVertex2f(x, y); // center of circle
            for(int i = 0; i <= triangleAmount;i++) {
                glVertex2f(
                        x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount))
                );
            }
        glEnd();


         x=-0.91;y=-0.74;radius =.021f;
        triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

        //GLfloat radius = 0.8f; //radius
        twicePi = 2.0f * PI;

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(164,141,12);
            glVertex2f(x, y); // center of circle
            for(int i = 0; i <= triangleAmount;i++) {
                glVertex2f(
                        x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount))
                );
            }
        glEnd();



        x=-0.91;y=-0.74;radius =.045f;
        triangleAmount = 30; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

        //GLfloat radius = 0.8f; //radius
        twicePi = 2.0f * PI;

        glBegin(GL_LINES);
        glColor3ub(133,121,5);
            glVertex2f(x, y); // center of circle
            for(int i = 0; i <= triangleAmount;i++) {
                glVertex2f(
                        x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount))
                );
            }
        glEnd();





        //2nd wheel//2nd wheel//2nd wheel//2nd wheel//2nd wheel//2nd wheel
        x=-0.815;y=-0.75;radius =.0425f;
        triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

        //GLfloat radius = 0.8f; //radius
        twicePi = 2.0f * PI;

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(78,87,46);
            glVertex2f(x, y); // center of circle
            for(int i = 0; i <= triangleAmount;i++) {
                glVertex2f(
                        x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount))
                );
            }
        glEnd();


         x=-0.815;y=-0.75;radius =.021f;
        triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

        //GLfloat radius = 0.8f; //radius
        twicePi = 2.0f * PI;

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(164,141,12);
            glVertex2f(x, y); // center of circle
            for(int i = 0; i <= triangleAmount;i++) {
                glVertex2f(
                        x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount))
                );
            }
        glEnd();



        x=-0.815;y=-0.75;radius =.045f;
        triangleAmount = 30; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

        //GLfloat radius = 0.8f; //radius
        twicePi = 2.0f * PI;

        glBegin(GL_LINES);
        glColor3ub(133,121,5);
            glVertex2f(x, y); // center of circle
            for(int i = 0; i <= triangleAmount;i++) {
                glVertex2f(
                        x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount))
                );
            }
        glEnd();




        //3rd wheel//3rd wheel//3rd wheel/
        x=-0.715;y=-0.75;radius =.0425f;
        triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

        //GLfloat radius = 0.8f; //radius
        twicePi = 2.0f * PI;

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(78,87,46);
            glVertex2f(x, y); // center of circle
            for(int i = 0; i <= triangleAmount;i++) {
                glVertex2f(
                        x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount))
                );
            }
        glEnd();


         x=-0.715;y=-0.75;radius =.021f;
        triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

        //GLfloat radius = 0.8f; //radius
        twicePi = 2.0f * PI;

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(164,141,12);
            glVertex2f(x, y); // center of circle
            for(int i = 0; i <= triangleAmount;i++) {
                glVertex2f(
                        x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount))
                );
            }
        glEnd();



        x=-0.715;y=-0.75;radius =.045f;
        triangleAmount = 30; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

        //GLfloat radius = 0.8f; //radius
        twicePi = 2.0f * PI;

        glBegin(GL_LINES);
        glColor3ub(133,121,5);
            glVertex2f(x, y); // center of circle
            for(int i = 0; i <= triangleAmount;i++) {
                glVertex2f(
                        x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount))
                );
            }
        glEnd();




        //4th wheel//4th wheel//4th wheel/
        x=-0.615;y=-0.75;radius =.0425f;
        triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

        //GLfloat radius = 0.8f; //radius
        twicePi = 2.0f * PI;

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(78,87,46);
            glVertex2f(x, y); // center of circle
            for(int i = 0; i <= triangleAmount;i++) {
                glVertex2f(
                        x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount))
                );
            }
        glEnd();


         x=-0.615;y=-0.75;radius =.021f;
        triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

        //GLfloat radius = 0.8f; //radius
        twicePi = 2.0f * PI;

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(164,141,12);
            glVertex2f(x, y); // center of circle
            for(int i = 0; i <= triangleAmount;i++) {
                glVertex2f(
                        x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount))
                );
            }
        glEnd();



        x=-0.615;y=-0.75;radius =.045f;
        triangleAmount = 30; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

        //GLfloat radius = 0.8f; //radius
        twicePi = 2.0f * PI;

        glBegin(GL_LINES);
        glColor3ub(133,121,5);
            glVertex2f(x, y); // center of circle
            for(int i = 0; i <= triangleAmount;i++) {
                glVertex2f(
                        x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount))
                );
            }
        glEnd();






        //5th wheel//5th wheel//5th wheel/
        x=-0.515;y=-0.75;radius =.0425f;
        triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

        //GLfloat radius = 0.8f; //radius
        twicePi = 2.0f * PI;

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(78,87,46);
            glVertex2f(x, y); // center of circle
            for(int i = 0; i <= triangleAmount;i++) {
                glVertex2f(
                        x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount))
                );
            }
        glEnd();


         x=-0.515;y=-0.75;radius =.021f;
        triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

        //GLfloat radius = 0.8f; //radius
        twicePi = 2.0f * PI;

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(164,141,12);
            glVertex2f(x, y); // center of circle
            for(int i = 0; i <= triangleAmount;i++) {
                glVertex2f(
                        x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount))
                );
            }
        glEnd();



        x=-0.515;y=-0.75;radius =.045f;
        triangleAmount = 30; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

        //GLfloat radius = 0.8f; //radius
        twicePi = 2.0f * PI;

        glBegin(GL_LINES);
        glColor3ub(133,121,5);
            glVertex2f(x, y); // center of circle
            for(int i = 0; i <= triangleAmount;i++) {
                glVertex2f(
                        x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount))
                );
            }
        glEnd();



         //6th wheel//6th wheel//6th wheel/
        x=-0.415;y=-0.75;radius =.0425f;
        triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

        //GLfloat radius = 0.8f; //radius
        twicePi = 2.0f * PI;

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(78,87,46);
            glVertex2f(x, y); // center of circle
            for(int i = 0; i <= triangleAmount;i++) {
                glVertex2f(
                        x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount))
                );
            }
        glEnd();


         x=-0.415;y=-0.75;radius =.021f;
        triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

        //GLfloat radius = 0.8f; //radius
        twicePi = 2.0f * PI;

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(164,141,12);
            glVertex2f(x, y); // center of circle
            for(int i = 0; i <= triangleAmount;i++) {
                glVertex2f(
                        x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount))
                );
            }
        glEnd();



        x=-0.415;y=-0.75;radius =.045f;
        triangleAmount = 30; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

        //GLfloat radius = 0.8f; //radius
        twicePi = 2.0f * PI;

        glBegin(GL_LINES);
        glColor3ub(133,121,5);
            glVertex2f(x, y); // center of circle
            for(int i = 0; i <= triangleAmount;i++) {
                glVertex2f(
                        x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount))
                );
            }
        glEnd();




         //7th wheel//7th wheel//7th wheel/
        x=-0.335;y=-0.75;radius =.0405f;
        triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

        //GLfloat radius = 0.8f; //radius
        twicePi = 2.0f * PI;

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(78,87,46);
            glVertex2f(x, y); // center of circle
            for(int i = 0; i <= triangleAmount;i++) {
                glVertex2f(
                        x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount))
                );
            }
        glEnd();


         x=-0.335;y=-0.75;radius =.021f;
        triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

        //GLfloat radius = 0.8f; //radius
        twicePi = 2.0f * PI;

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(164,141,12);
            glVertex2f(x, y); // center of circle
            for(int i = 0; i <= triangleAmount;i++) {
                glVertex2f(
                        x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount))
                );
            }
        glEnd();



        x=-0.335;y=-0.75;radius =.0405f;
        triangleAmount = 30; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

        //GLfloat radius = 0.8f; //radius
        twicePi = 2.0f * PI;

        glBegin(GL_LINES);
        glColor3ub(133,121,5);
            glVertex2f(x, y); // center of circle
            for(int i = 0; i <= triangleAmount;i++) {
                glVertex2f(
                        x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount))
                );
            }
        glEnd();













        //last wheel//last wheel//last wheel//last wheel//last wheel

        x=-0.25;y=-0.74;radius =.043f;
        triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

        //GLfloat radius = 0.8f; //radius
        twicePi = 2.0f * PI;

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(78,87,46);
            glVertex2f(x, y); // center of circle
            for(int i = 0; i <= triangleAmount;i++) {
                glVertex2f(
                        x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount))
                );
            }
        glEnd();


         x=-0.25;y=-0.74;radius =.021f;
        triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

        //GLfloat radius = 0.8f; //radius
        twicePi = 2.0f * PI;

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(164,141,12);
            glVertex2f(x, y); // center of circle
            for(int i = 0; i <= triangleAmount;i++) {
                glVertex2f(
                        x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount))
                );
            }
        glEnd();



        x=-0.25;y=-0.74;radius =.045f;
        triangleAmount = 30; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

        //GLfloat radius = 0.8f; //radius
        twicePi = 2.0f * PI;

        glBegin(GL_LINES);
        glColor3ub(133,121,5);
            glVertex2f(x, y); // center of circle
            for(int i = 0; i <= triangleAmount;i++) {
                glVertex2f(
                        x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount))
                );
            }
        glEnd();


    glPopMatrix();





    glFlush();

}






int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(520, 520);
    glutCreateWindow("ARMY CAMP SCENARIO");
    glutDisplayFunc(display);
    //PlaySound("sound.wav",NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
    glutTimerFunc(100, update, 0);
    glutTimerFunc(100, update2, 0);
    glutMainLoop();
    return 0;
}






