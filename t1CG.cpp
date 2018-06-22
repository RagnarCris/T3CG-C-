#include <stdio.h>
#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define TOTAL 100
#define MAX_FUEL 500
#define MAX_MISSILES 50
#define PLAIN_HEIGHT 0.4

float xSide[] = {6.4, 6.4, 3.2, 3.2, 6.4, 6.4, 4.8, 4.8, 3.2, 3.2, 4.8, 4.8, 1.6, 1.6, 0.8, 0.8, 4.8,
            4.8, 3.2, 3.2, 0.8, 0.8, 3.2, 3.2, 2.8, 2.8, 6.4, 6.4, 4.0, 4.0, 6.4, 6.4, 3.2, 3.2, 4.0,
            4.0, 3.2, 3.2, 2.8, 2.8, 2.4, 2.4, 0.8, 0.8, 2.4, 2.4, 0.8, 0.8, 6.4, 6.4, 3.2, 3.2, 6.4,
             6.4, 1.6, 1.6, 0.8, 0.8, 2.4, 2.4, 2.08, 2.08, 1.6, 1.6, 0.8, 0.8, 6.4, 6.4};
float ySide[] = {0, 3.0, 4, 40, 41, 46, 47, 51, 51.5, 53.5, 54, 58, 59, 62, 62.25, 70.75, 72, 74,
            74.5, 76.5, 77, 89, 90, 94, 94, 96, 97.5, 102, 103, 154, 155, 159, 160, 161, 162,
            173, 174, 178, 178, 182, 182, 186, 187, 200, 201, 206, 207, 219, 221, 225, 226,
            276, 277, 281, 282.5, 285.5, 286, 306, 307, 312, 312, 316, 320, 324, 325, 337, 338, 342};

///48 Elementos
float yHeli[] = {8, 20, 24, 28, 31, 33, 36, 39, 54, 57, 63, 69, 79, 87, 90, 108, 110, 113, 115, 117, 124, 132, 177, 199, 229,
                230, 232, 235, 238, 240, 244, 245, 253, 260, 262, 264, 266, 268, 270, 283, 284, 288, 293, 294, 299, 307, 330, 335};

///11 elementos
float yAviaoEnemy[] = {123, 128, 183, 195, 204, 210, 233, 241, 247, 292, 311};

///34 Elementos
float yBarco[] = {5, 27, 29, 34, 41, 47, 52, 65, 66, 72.5, 74, 92, 103, 118, 120, 126, 138, 144, 145, 155, 172, 179, 187, 191,
                213, 220, 228, 255, 272, 277, 313, 317, 318, 321};

///43 Elementos
float xFuel[] = {9.6, 8.0, 9.6, 8.0, 4.8, 8.0, 8.0, 9.6, 9.6, 11.2, 5.6, 6.4, 12.8, 4.8, 13.6, 11.2, 9.6, 5.6, 6.4, 9.6, 8.0, 6.4, 8.0, 9.6, 11.2, 9.6, 3.2, 11.2, 4.8, 9.6, 2.4, 3.2, 12.8, 6.4, 8.0, 9.6, 12.8, 1.6, 14.4, 3.2, 1.6, 1.6, 1.6};
float yFuel[] = {6, 10, 12, 18, 22, 25, 30, 38, 55, 60, 64, 71, 77, 80, 88, 94, 114, 130, 134, 136, 140, 146, 148, 152, 161, 165, 192, 197, 201, 205, 207, 209, 214, 236, 243, 250, 286, 290, 305, 308, 325, 327, 329};

///6 Elementos
float xBridge[] = {8, 8, 8, 8, 8, 8};
float yBridge[] = {43.5, 100, 157, 223, 279, 340};


struct rects{
    float x;
    float y;
    float h;
    float l;
    int inc=0.5;
    bool active;
    bool fuel = false;
};
rects helicop[48];
rects barco[34];
rects aviao[11];
rects combustivel[43];
rects bridge[6];
rects *visibleThing[12];

char textPoint[12] = {'P','o','n','t','o','s',':',' '};
char textLife[12] = {'V','i','d','a',':',' '};
char textFuel[12] = {'F','u','e','l',':',' '};
char points[12];
char cLife[12];
char cFuel[12];
/**
Funções:
*/
void display(void);
void init (void);
void keyboard(unsigned char key, int x, int y);
void drawScenary();
void drawAirPlane();
void idle();
void specialKeysPress(int key, int x, int y);
void manageMissile();
void shootMissile();
void drawMissile();
bool sideColision(float x, float y, float radius);
void beginPosition();
float dist(float x1, float y1, float x2, float y2);
bool linePoint(float x1, float y1, float x2, float y2, float px, float py, float radius);
bool circleRect(float cx, float cy, float radius, float rx, float ry, float rw, float rh);
bool isVisible(float y);
void manageVisibility();
void drawObjects();
void increasePoints();
bool hitMissile(rects r);
bool hitPlane(rects r);
void drawBitmapText(char str[] ,float x,float y,float z);
void drawBitmapBig(char str[] ,float x,float y,float z);
void collisionStructures(float x, float y, float radius);

struct missile{
    float x;
    float y;
    bool active = false;
};

bool paused = true, fullscreen = false;
int yColision = 1;
missile missiles[MAX_MISSILES];
int score, fuel, lifes;
float speed, xPlane, yPlane;
char losing[12] = {'V','o','c','e',' ','P','e','r','d','e','u'};
void beginPosition(){
    lifes = 3;
    fuel = MAX_FUEL;
    score = 0;
    xPlane = 8.0;
    yPlane = 1.0;
    speed = 0.1;
    paused = false;
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (800, 450);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("River Raid");
    init ();
    glutIdleFunc(idle);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc( specialKeysPress );
    beginPosition();
    glutMainLoop();
    return 0;
}
/**
Variáveis para que o texto se mova com o Ortho
*/
int yText;

void display(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0,- (yPlane - 1),0);
    glPushMatrix();
    drawScenary();

    glColor3f (1.0, 1.0, 0.0);
    drawAirPlane();
    glColor3f(0.0,0.0,0.0);
    drawBitmapText(textPoint, 1, yPlane + 1, 0);
    drawBitmapText(textLife, 13,yPlane + 1, 0);
    sprintf(points, "%d", score);
    drawBitmapText(points, 2, yPlane + 1, 0);
    sprintf(cLife, "%d", lifes);
    drawBitmapText(cLife, 14,  yPlane +1, 0);
    drawBitmapText(textFuel, 1, yPlane +  7, 0);
    sprintf(cFuel, "%d", fuel);
    drawBitmapText(cFuel, 2, yPlane + 7, 0);
    if (lifes < 1){
        paused = true;
        drawBitmapBig(losing, 8, yPlane+3.5, 0);
    }
    drawMissile();
    glColor3f (0.0, 1.0, 0.0);

    glutSwapBuffers ();
}

void idle(){
    if (!paused){
        float t, desiredFrameTime, frameTime;
        static float tLast = 0.0;
        // Get elapsed time
        t = glutGet(GLUT_ELAPSED_TIME);
        // convert milliseconds to seconds
        t /= 1000.0;
        // Calculate frame time
        frameTime = t - tLast;
        // Calculate desired frame time
        desiredFrameTime = 1.0 / (float) (50);

        // Check if the desired frame time was achieved. If not, skip animation.
        if( frameTime <= desiredFrameTime)
            return;

        /* Update tLast for next time, using static local variable */
        tLast = t;
        yPlane += speed;
        fuel--;
        if (fuel < 0){
            lifes--;
        }
        manageMissile();
        manageVisibility();
        glutPostRedisplay();
   }
}

/**
Função para desenhar o cenário completo
Usamos for com array de x e array de y para ir passando as coordenadas de dois em dois vértices
*/
void drawScenary(){
    glBegin(GL_TRIANGLE_STRIP);
    for(int i=0; i < 68; i++){
      glVertex3f (0.0, ySide[i], 0.0);
      glVertex3f (xSide[i], ySide[i], 0.0);
    }
   glEnd();
   glBegin(GL_TRIANGLE_STRIP);
    for(int i=0; i < 68; i++){
      glVertex3f (16.0, ySide[i], 0.0);
      glVertex3f (16.0 - xSide[i], ySide[i], 0.0);
    }
   glEnd();
   ///ESTRUTURAS LOCALIZADAS NO MEIO DO RIO
   glBegin(GL_TRIANGLE_STRIP);
      glVertex3f (8  , 63.5 , 0.0);
      glVertex3f (8.8, 64, 0.0);
      glVertex3f (7.2, 64, 0.0);
      glVertex3f (8.8, 68, 0.0);
      glVertex3f (7.2, 68, 0.0);
      glVertex3f (8.0, 68.5, 0.0);
   glEnd();
   glBegin(GL_TRIANGLE_STRIP);
      glVertex3f (8 , 78 , 0.0);
      glVertex3f (10.4, 78.5, 0.0);
      glVertex3f (5.6, 78.5, 0.0);
      glVertex3f (10.4, 84, 0.0);
      glVertex3f (5.6, 84, 0.0);
      glVertex3f (8.8, 84.5, 0.0);
      glVertex3f (7.2, 84.5, 0.0);
      glVertex3f (8.8, 87.5, 0.0);
      glVertex3f (7.2, 87.5, 0.0);
      glVertex3f (8  , 88, 0.0);
   glEnd();
   glBegin(GL_TRIANGLE_STRIP);
      glVertex3f (8  , 190 , 0.0);
      glVertex3f (10.4, 191, 0.0);
      glVertex3f (5.6, 191, 0.0);
      glVertex3f (10.4, 195, 0.0);
      glVertex3f (5.6, 195, 0.0);
      glVertex3f (8.8, 195.5, 0.0);
      glVertex3f (7.2, 195.5, 0.0);
      glVertex3f (8.8, 198, 0.0);
      glVertex3f (7.2, 198, 0.0);
      glVertex3f (8  , 199, 0.0);
   glEnd();
   glBegin(GL_TRIANGLE_STRIP);
    glVertex3f (5 * 1.6, 208 , 0.0);
    glVertex3f (6 * 1.6, 209, 0.0);
    glVertex3f (4 * 1.6, 209, 0.0);
    glVertex3f (6 * 1.6, 212, 0.0);
    glVertex3f (4 * 1.6, 212, 0.0);
    glVertex3f (6.5 * 1.6, 212, 0.0);
    glVertex3f (3.5 * 1.6, 212, 0.0);
    glVertex3f (6.5 * 1.6, 216, 0.0);
    glVertex3f (3.5 * 1.6, 216, 0.0);
    glVertex3f (5 * 1.6, 217, 0.0);
   glEnd();
   glBegin(GL_TRIANGLE_STRIP);
      glVertex3f (5 * 1.6  , 287 , 0.0);
      glVertex3f (8 * 1.6  , 288, 0.0);
      glVertex3f (2 * 1.6  , 288, 0.0);
      glVertex3f (8 * 1.6  , 292, 0.0);
      glVertex3f (2 * 1.6  , 292, 0.0);
      glVertex3f (8.5 * 1.6, 292.5, 0.0);
      glVertex3f (1.5 * 1.6, 292.5, 0.0);
      glVertex3f (8.5 * 1.6, 294, 0.0);
      glVertex3f (1.5 * 1.6, 294, 0.0);
      glVertex3f (7 * 1.6  , 294.5, 0.0);
      glVertex3f (3 * 1.6  , 294.5, 0.0);
      glVertex3f (7 * 1.6  , 295.5, 0.0);
      glVertex3f (3 * 1.6  , 295.5, 0.0);
      glVertex3f (8.5 * 1.6, 296, 0.0);
      glVertex3f (1.5 * 1.6, 296, 0.0);
      glVertex3f (8.5 * 1.6, 300, 0.0);
      glVertex3f (1.5 * 1.6, 300, 0.0);
      glVertex3f (5.5 * 1.6, 301, 0.0);
      glVertex3f (4.5 * 1.6, 301, 0.0);
      glVertex3f (5.5 * 1.6, 304, 0.0);
      glVertex3f (4.5 * 1.6, 304, 0.0);
      glVertex3f (5 * 1.6  , 305, 0.0);
   glEnd();
   glBegin(GL_TRIANGLE_STRIP);
      glVertex3f (5 * 1.6  , 325, 0.0);
      glVertex3f (8.5 * 1.6, 327, 0.0);
      glVertex3f (1.5 * 1.6, 327, 0.0);
      glVertex3f (8.5 * 1.6, 331, 0.0);
      glVertex3f (1.5 * 1.6, 331, 0.0);
      glVertex3f (5 * 1.6  , 333, 0.0);
   glEnd();

   drawObjects();
}

bool circleRect(float cx, float cy, float radius, float rx, float ry, float rw, float rh) {

  // temporary variables to set edges for testing
  float testX = cx;
  float testY = cy;

  // which edge is closest?
  if (cx < rx)         testX = rx;      // test left edge
  else if (cx > rx+rw) testX = rx+rw;   // right edge
  if (cy < ry)         testY = ry;      // top edge
  else if (cy > ry+rh) testY = ry+rh;   // bottom edge
  float distance = dist(cx,cy,testX,testY);

  // if the distance is less than the radius, collision!
  if (distance <= radius) {
    return true;
  }
  return false;
}

void inicializaStructs()
{
    srand (time(NULL));
    int random;
    for(int i = 0; i < 48; i++){
        helicop[i].y = yHeli[i];
        for(int j = 0; j<68; j++)
        {
            if(helicop[i].y >= ySide[j] && helicop[i].y<ySide[j+1])
            {
                 helicop[i].x = (rand()%(int)(16-xSide[j]) + xSide[j]);
            }
        }
        helicop[i].h = 0.25;
        helicop[i].l = 0.25;
        helicop[i].active = true;
    }
    for(int i= 0; i < 34; i++){
        barco[i].y = yBarco[i];
        for(int j = 0; j<68; j++)
        {
            if(barco[i].y >=ySide[j] && barco[i].y<ySide[j+1])
            {
                 barco[i].x = (rand()%(int)(16-xSide[j]) + xSide[j]);
            }
        }
        barco[i].h = 0.3;
        barco[i].l = 0.4;
        barco[i].active = true;
    }
    for(int i= 0; i < 11; i++){
        aviao[i].y = yAviaoEnemy[i];
        aviao[i].x = 14;
        aviao[i].h = 0.2;
        aviao[i].l = 0.3;
        aviao[i].active = true;
    }
    for(int i= 0; i < 43; i++){
        combustivel[i].y = yFuel[i];
        combustivel[i].x = xFuel[i];
        combustivel[i].h = 0.4;
        combustivel[i].l = 0.2;
        combustivel[i].active = true;
        combustivel[i].fuel = true;
    }
    for(int i= 0; i < 6; i++){
        bridge[i].y = yBridge[i];
        bridge[i].x = xBridge[i];
        bridge[i].h = 0.5;
        bridge[i].l = 1.65;
        bridge[i].active = true;
    }
}

void drawObjects(){
    for(int i = 0; i < 48; i++){
        if(helicop[i].active)
        {
            glColor3f(1.0,0.0,0.0);
            glRectf((helicop[i].x-helicop[i].l) + helicop[i].inc, helicop[i].y+ helicop[i].h, (helicop[i].x+helicop[i].l)+helicop[i].inc, helicop[i].y-helicop[i].h);
        }

    }
    for(int i= 0; i < 34; i++){
        if(barco[i].active)
            {
                glColor3f(0.0,0.0,0.0);
                glRectf(barco[i].x-barco[i].l, barco[i].y+ barco[i].h, barco[i].x+barco[i].l, barco[i].y-barco[i].h);
            }

    }
    for(int i= 0; i < 11; i++){
        if(aviao[i].active)
        {
            glColor3f(0.0,0.0,0.8);
            glRectf(aviao[i].x-aviao[i].l, aviao[i].y+ aviao[i].h, aviao[i].x+aviao[i].l, aviao[i].y-aviao[i].h);
        }

    }
    for(int i= 0; i < 43; i++){
        if(combustivel[i].active)
        {
            glColor3f(1.0,1.0,1.0);
            glRectf((combustivel[i].x-combustivel[i].l), combustivel[i].y+ combustivel[i].h, combustivel[i].x+combustivel[i].l, combustivel[i].y-combustivel[i].h);
        }

    }
    for(int i= 0; i < 06; i++){
        if(bridge[i].active)
        {
            glColor3f(1.0,1.0,0.0);
            glRectf(bridge[i].x-bridge[i].l, bridge[i].y+ bridge[i].h, bridge[i].x+bridge[i].l, bridge[i].y-bridge[i].h);
        }

    }

}

void drawAirPlane(){
    if(sideColision(xPlane, yPlane, 0.4)){
        lifes--;
    }
    collisionStructures(xPlane, yPlane, 0.4);

    glBegin(GL_TRIANGLES);
        glVertex3f(xPlane, yPlane + PLAIN_HEIGHT, 0.0);
        glVertex3f(xPlane - 0.4, yPlane - 0.35, 0.0);
        glVertex3f(xPlane + 0.4, yPlane -0.35, 0.0);
    glEnd();
}
void init (void){
    glClear (GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);              // Seleciona Matriz de Projeção
    glLoadIdentity();
    glOrtho(0.0, 16.0, 0, 9, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW); // Select The Modelview Matrix
    glLoadIdentity();
    inicializaStructs();
    // selecionar cor de fundo (preto)
    glClearColor (0.0, 0.0, 1.0, 0.0);
}

bool sphereColision(int radius1, int radius2, int x1, int x2, int y1, int y2){
    float distance = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2)); // Calcula a distância entre os centros das esferas
    return (distance < ((float)(radius1 + radius2))); // verifica se a distância dos centros é maior que o tamanho de ambos os raios
}

bool sideColision(float x, float y, float radius){
    int yColision = 0;
    while(y > ySide[yColision])
        yColision++;

    bool collide = linePoint(xSide[yColision - 1], ySide[yColision -1], xSide[yColision], ySide[yColision], x, y, radius);
    return collide || linePoint(16-xSide[yColision - 1], ySide[yColision -1], 16-xSide[yColision], ySide[yColision], x, y, radius);

}

void collisionStructures(float x, float y, float radius)
{
    if(linePoint(5, 63.5, 5.5, 64, x, y, radius)|| linePoint(5.5, 64, 5.5, 68, x, y, radius)||linePoint(5.5, 68, 5, 68.5, x, y, radius)||linePoint(5, 68.5, 4.5, 68, x, y, radius)||linePoint(4.5, 68, 4.5, 64, x, y, radius)||linePoint(4.5, 64, 5, 63.5, x, y, radius))
        lifes--;
    if(linePoint(5, 78, 6.5, 78.5, x, y, radius)||linePoint(6.5, 78.5, 6.5, 84, x, y, radius)||linePoint(6.5, 84, 5.5, 84.5, x, y, radius)||linePoint(5.5, 84.5, 5.5, 87.5, x, y, radius)||linePoint(5.5, 87.5, 5, 88, x, y, radius)||linePoint(5, 88, 4.5, 87.5, x, y, radius)||linePoint(4.5, 87.5, 4.5, 84.5, x, y, radius)||linePoint(4.5, 84.5, 3.5, 84, x, y, radius)||linePoint(3.5, 84, 3.5, 78.5, x, y, radius)||linePoint(3.5, 78.5, 5, 78, x, y, radius))
        lifes--;
    if(linePoint(5, 190, 6.5, 191, x, y, radius)||linePoint(6.5, 191, 6.5, 195, x, y, radius)||linePoint(6.5, 195, 5.5, 196, x, y, radius)||linePoint(5.5, 196, 5.5, 198, x, y, radius)||linePoint(5.5, 198, 5, 199, x, y, radius)||linePoint(5, 199, 4.5, 198, x, y, radius)||linePoint(4.5, 198, 4.5, 196, x, y, radius)||linePoint(4.5, 196, 3.5, 195, x, y, radius)||linePoint(3.5, 195, 3.5, 191, x, y, radius)||linePoint(3.5, 191, 5, 190, x, y, radius))
        lifes--;
    if(linePoint(5, 208, 6, 209, x, y, radius)|| linePoint(6, 209, 6, 216, x, y, radius)||linePoint(6.5, 216, 5, 217, x, y, radius)||linePoint(5, 217, 3.5, 216, x, y, radius)||linePoint(3.5, 216, 4, 209, x, y, radius)||linePoint(4, 209, 5, 208, x, y, radius))
        lifes--;
    if(linePoint(5, 287, 8, 288, x, y, radius)|| linePoint(8, 288, 8.5, 294, x, y, radius)||linePoint(8.5, 294, 7, 295.5, x, y, radius)||linePoint(7, 295.5, 7, 295.5, x, y, radius)|| linePoint(7, 295.5, 8.5, 296, x, y, radius)||linePoint(8.5, 296, 8, 300, x, y, radius)||linePoint(8, 300, 5.5, 301, x, y, radius)|| linePoint(5.5, 301, 5.5, 304, x, y, radius)||linePoint(5.5, 304, 5, 305, x, y, radius)||linePoint(5, 305, 4.5, 304, x, y, radius)|| linePoint(4.5, 304, 4.5, 301, x, y,radius)||linePoint(4.5, 301, 1.5, 300, x, y, radius)|| linePoint(1.5, 300, 1.5, 296, x, y, radius)|| linePoint(1.5, 296, 3, 295.5, x, y, radius)||linePoint(3, 295.5, 3, 294.5, x, y, radius)||linePoint(3, 294.5, 1.5, 294, x, y, radius)|| linePoint(1.5, 294, 2, 288, x, y, radius)||linePoint(2, 288, 5, 287, x, y, radius))
        lifes--;
    if(linePoint(5, 325, 8.5, 327, x, y, radius)|| linePoint(8.5, 327, 8.5, 331, x, y, radius)||linePoint(8.5, 331, 5, 333, x, y, radius)||linePoint(5, 333, 1.5, 331, x, y, radius)|| linePoint(1.5, 331, 1.5, 327, x, y, radius)||linePoint(1.5, 327, 5, 325, x, y, radius))
        lifes--;
}

bool linePoint(float x1, float y1, float x2, float y2, float px, float py, float radius) {
  float d1 = dist(px,py, x1,y1);
  float d2 = dist(px,py, x2,y2);
  float lineLen = dist(x1,y1, x2,y2);
  float buffer = 0.01;
  if (d1+d2 >= lineLen-buffer && d1+d2 <= lineLen+buffer) {
    return true;
  }
  return false;
}

float dist(float x1, float y1, float x2, float y2){
  float distX = x1 - x2;
  float distY = y1 - y2;
  return pow( ((distX*distX) + (distY*distY)), 0.5000000 );
}

void manageMissile(){
    for(int i = 0; i < MAX_MISSILES; i++){
        if(missiles[i].active){
            if(missiles[i].y > 9 || sideColision(missiles[i].x, missiles[i].y + yPlane , 0)){
                missiles[i].active = false;
                break;
            }
            missiles[i].y += speed + 0.2;
        }
    }
}

void drawMissile(){
    for(int i = 0; i < MAX_MISSILES; i++){
        if(missiles[i].active){
            glPushMatrix ();
                glLoadIdentity ();
                glTranslatef(missiles[i].x, missiles[i].y, 0);
                glColor3f(1.0, 0.0, 0.0);
                glutSolidSphere(0.1, 100, 100);
                // printf("Missile -> (%0.2f,%0.2f), plane (%0.2f,%0.2f)", missiles[i].x, missiles[i].y, xPlane, yPlane);
            glPopMatrix();
        }
    }
}

void shootMissile(){
    for(int i = 0; i < MAX_MISSILES; i++){
        if(!missiles[i].active){
            missiles[i].x = xPlane;
            missiles[i].y = PLAIN_HEIGHT + 1;
            missiles[i].active = true;
            return ;
        }
    }
}

void specialKeysPress(int key, int x, int y){
	switch(key) {
		case GLUT_KEY_RIGHT:
			xPlane +=0.1;
            break;
		case GLUT_KEY_LEFT:
			xPlane -=0.1;
            break;
        case GLUT_KEY_UP:
            speed += 0.1;
            break;
        case GLUT_KEY_DOWN:
            if(speed > 0.2){
                speed -= 0.1;
            }
            break;
        case GLUT_KEY_F11:
            fullscreen = !fullscreen;
            if(fullscreen){
                glutFullScreen();
            } else{
                glutReshapeWindow(800,450);
                glutInitWindowPosition (100, 100);
            }
            break;
	}
	glutPostRedisplay();
}
void keyboard(unsigned char key, int x, int y){
    switch (key){
      case 32:
        shootMissile();
        break;
      case 27:
        exit(0);
        break;
      case 'p':
        paused = !paused;
        break;
      case '1':
        beginPosition();
        break;
      case 'r':
        beginPosition();
        break;
   }
   glutPostRedisplay();
}

bool isVisible(float y){
    if(y > yPlane && y < yPlane + 9)
        return true;
    return false;
}

void manageVisibility(){
    for(int i = 0; i < 48; i++){
        if(hitMissile(helicop[i])){
            helicop[i].active = false;
            increasePoints();
        } else if(hitPlane(helicop[i])){
            helicop[i].x = 40;
            lifes--;
        }
    }
    for(int i= 0; i < 34; i++){
        if(hitMissile(barco[i])){
            barco[i].active = false;
            increasePoints();
        }else if(hitPlane(barco[i])){
            barco[i].x = 40;
            lifes--;
        }

    }
    for(int i= 0; i < 11; i++){
        if(hitMissile(aviao[i])){
            aviao[i].active = false;
            increasePoints();
        }else if(hitPlane(aviao[i])){
            aviao[i].x = 40;
            lifes--;
        }
    }
    for(int i= 0; i < 43; i++){
        if(hitMissile(combustivel[i])){
            combustivel[i].active = false;
            increasePoints();
        }else if(hitPlane(combustivel[i])){
            fuel = MAX_FUEL;
        }
    }
}
/**
Função para desenhar o texto na tela
*/
void drawBitmapText(char str[] ,float x,float y,float z)
{

	glRasterPos3f(x, y,z);

	for (int i = 0; i < 12; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, str[i]);
	}
}
void drawBitmapBig(char str[] ,float x,float y,float z){
    glRasterPos3f(x, y,z);

	for (int i = 0; i < 12; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str[i]);
	}
}

bool hitMissile(rects r){
    for (int i = 0; i < MAX_MISSILES; i++){
        if(missiles[i].active && circleRect(missiles[i].x, missiles[i].y + yPlane - PLAIN_HEIGHT, 0, r.x, r.y, r.l, r.h)){
            missiles[i].active = false;
            return true;
        }
    }
    return false;
}

bool hitPlane(rects r){
    return circleRect(xPlane, yPlane, PLAIN_HEIGHT, r.x, r.y, r.l, r.h);
}

void increasePoints(){
    score++;
    printf("Acertou");
}
