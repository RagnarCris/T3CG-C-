#include "../shared/structure.h"
#include <GL/glut.h>
#include <GL/glext.h>
#include <iostream>
using namespace std;

    float xSide[] = {6.4, 6.4, 3.2, 3.2, 6.4, 6.4, 4.8, 4.8, 3.2, 3.2, 4.8, 4.8, 1.6, 1.6, 0.8, 0.8, 4.8,
         4.8, 3.2, 3.2, 0.8, 0.8, 3.2, 2.8, 2.8, 6.4, 6.4, 4.0, 4.0, 6.4, 6.4, 3.2, 3.2, 4.0,
         4.0, 3.2, 3.2, 2.8, 2.8, 2.4, 2.4, 0.8, 0.8, 2.4, 2.4, 0.8, 0.8, 6.4, 6.4, 3.2, 3.2, 6.4,
         6.4, 1.6, 1.6, 0.8, 0.8, 2.4, 2.4, 2.08, 1.6, 1.6, 0.8, 0.8, 6.4, 6.4};

    ///66 elementos
    float ySide[] = {0, 3.0, 4, 40, 41, 46, 47, 51, 51.5, 53.5, 54, 58, 59, 62, 62.25, 70.75, 72, 74,
             74.5, 76.5, 77, 89, 90, 94, 96, 97.5, 102, 103, 154, 155, 159, 160, 161, 162,
             173, 174, 178, 178.1, 182, 182.1, 186, 187, 200, 201, 206, 207, 219, 221, 225, 226,
             276, 277, 281, 282.5, 285.5, 286, 306, 307, 312, 316, 320, 324, 325, 337, 338, 342};

    float xStruct1[] = {8, 8.8, 7.2, 8.8, 7.2, 8};
    float yStruct1[] = {63.5, 64, 64, 68, 68, 68.5};

    float xStruct2[] = {8, 10.4, 5.6, 10.4, 5.6, 8.8, 7.2, 8.8, 7.2, 8};
    float yStruct2[] = {78, 78.5, 78.5, 84, 84, 84.5, 84.5, 87.5, 87.5, 88};

    float xStruct3[] = {8, 10.4, 5.6, 10.4, 5.6, 8.8, 7.2, 8.8, 7.2, 8};
    float yStruct3[] = {190, 191, 191, 195, 195, 195.5, 195.5, 198, 198, 199};

    float xStruct4[] = {8, 9.6, 6.4, 9.6, 6.4, 10.4, 5.6, 10.4, 5.6, 8};
    float yStruct4[] = {208, 209, 209, 212, 212, 212, 212, 216, 216, 217};

    float xStruct5[] = {8, 12.8, 3.2, 12.8, 3.2, 13.6, 2.4, 13.6, 2.4, 11.2, 4.8, 11.2, 4.8, 13.6, 2.4, 13.6, 2.4, 8.8, 7.2, 8.8, 7.2, 8};
    float yStruct5[] = {287, 288, 288, 292, 292, 292.5, 292.5, 294, 294, 294.5, 294.5, 295.5, 295.5, 296, 296, 300, 300, 301, 301, 304, 304, 305};

    float xStruct6[] = {8, 13.6, 2.4, 13.6, 2.4, 8};
    float yStruct6[] = {325, 327, 327, 331, 331, 333};

void Structure::draw_structure_left(int i, float pos, float x, float z)
{
     glBegin(GL_TRIANGLE_STRIP);
        glVertex3f(x, ySide[i], z);
        glVertex3f(xSide[i], ySide[i], z);
        i = i + 1;
        while (i < mapSize) {
//            v0 = Vertex(x, ySide[i - 1], z)
//            v1 = Vertex(xSide[i - 1], ySide[i - 1], z)
//            v2 = Vertex(x, ySide[i], z)
//            v3 = Vertex(xSide[i], ySide[i], z)
//            vn = calculateNormal(v2, v1, v0)
//            glNormal3d(vn.x, vn.y, vn.z)
            glVertex3f(x, ySide[i], z);
//            vn = calculateNormal(v2, v3, v1)
//            glNormal3d(vn.x, vn.y, vn.z)
            glVertex3f(xSide[i], ySide[i], z);
            if(ySide[i] > pos + 20){
                break;
            }
            i = i + 1;
        }
    glEnd();
}

void Structure::draw_structure_right(int i, float pos, float x, float z)
{
    glBegin(GL_TRIANGLE_STRIP);
    glVertex3f(x, ySide[i], z);
    glVertex3f(x - xSide[i], ySide[i], z);
    i = i + 1;
    while(i < mapSize) {
//        v0 = Vertex(x, ySide[i - 1], z)
//        v1 = Vertex(x - xSide[i - 1], ySide[i - 1], z)
//        v2 = Vertex(x, ySide[i], z)
//        v3 = Vertex(x - xSide[i], ySide[i], z)
//        vn = calculateNormal(v0, v1, v2)
//        glNormal3d(vn.x, vn.y, vn.z)
        glVertex3f(x, ySide[i], z);
//        vn = calculateNormal(v1, v3, v2)
//        glNormal3d(vn.x, vn.y, vn.z)
        glVertex3f(x - xSide[i], ySide[i], z);
        if(ySide[i] > pos + 20) {
            break;
        }
        i = i + 1;
    }
    glEnd();
}
void Structure::draw_side_strucutre_left(int i, float pos, float z1, float z2)
{
    glBegin(GL_TRIANGLE_STRIP);
    glVertex3f(xSide[i], ySide[i], z1);
    glVertex3f(xSide[i], ySide[i], z2);
    i = i + 1;
    while(i < mapSize){
//        v0 = Vertex(xSide[i - 1], ySide[i - 1], z1)
//        v1 = Vertex(xSide[i - 1], ySide[i - 1], z2)
//        v2 = Vertex(xSide[i], ySide[i], z1)
//        v3 = Vertex(xSide[i], ySide[i], z2)
//        vn = calculateNormal(v0, v2, v3)
//        glNormal3d(vn.x, vn.y, vn.z)
        glVertex3f(xSide[i], ySide[i], z1);
//        vn = calculateNormal(v1, v2, v3)
//        glNormal3d(vn.x, vn.y, vn.z)
        glVertex3f(xSide[i], ySide[i], z2);
        if(ySide[i] > pos + 20){
            break;
        }
        i = i + 1;
    }
    glEnd();
}
void Structure::draw_side_strucutre_right(int i, float pos, float z1, float z2)
{
    glBegin(GL_TRIANGLE_STRIP);
        glVertex3f(16 - xSide[i], ySide[i], z1);
        glVertex3f(16 - xSide[i], ySide[i], z2);
        i = i + 1;
        while(i < mapSize) {
//            v0 = Vertex(16 - xSide[i - 1], ySide[i - 1], z1)
//            v1 = Vertex(16 - xSide[i - 1], ySide[i - 1], z2)
//            v2 = Vertex(16 - xSide[i], ySide[i], z1)
//            v3 = Vertex(16 - xSide[i], ySide[i], z2)
//            vn = calculateNormal(v0, v2, v1)
//            glNormal3d(vn.x, vn.y, vn.z)
            glVertex3f(16 - xSide[i], ySide[i], z1);
//            vn = calculateNormal(v1, v2, v3)
//            glNormal3d(vn.x, vn.y, vn.z)
            glVertex3f(16 - xSide[i], ySide[i], z2);
            if(ySide[i] > pos + 20) {
                break;
            }
            i = i + 1;
    glEnd();
}
void Structure::draw_midle_struct_up(float z)
{
    int i = 0;
    glBegin(GL_TRIANGLE_STRIP);
    for(i = 0; i<6; i++) {
        glVertex3f(xStruct1[i], yStruct1[i], z);
        i = i + 1;
    }
    glEnd();

    glBegin(GL_TRIANGLE_STRIP);
    for(i = 0; i<10; i++) {
        glVertex3f(xStruct2[i], yStruct2[i], z);
        i = i + 1;
    }
    glEnd();

    glBegin(GL_TRIANGLE_STRIP);
    for(i = 0; i<10; i++) {
        glVertex3f(xStruct3[i], yStruct3[i], z);
        i = i + 1;
    }
    glEnd();

    glBegin(GL_TRIANGLE_STRIP);
    for(i = 0; i<10; i++) {
        glVertex3f(xStruct4[i], yStruct4[i], z);
        i = i + 1;
    }
    glEnd();

    glBegin(GL_TRIANGLE_STRIP);
    for(i = 0; i<22; i++) {
        glVertex3f(xStruct5[i], yStruct5[i], z);
        i = i + 1;
    }
    glEnd();

    glBegin(GL_TRIANGLE_STRIP);
    for(i = 0; i<6; i++) {
        glVertex3f(xStruct6[i], yStruct6[i], z)
        i = i + 1;
    }
    glEnd();
}

void Structure::draw_midle_structure_fill(float z)
{
    int i = 0;
    glBegin(GL_TRIANGLE_STRIP);
    for(i = 0; i<10; i++) {
        glVertex3f(xStruct1[i], yStruct1[i], 0);
        glVertex3f(xStruct1[i], yStruct1[i], z);
        i = i + 1;
    }
    glVertex3f(xStruct1[2], yStruct1[2], 0);
    glVertex3f(xStruct1[2], yStruct1[2], z);
    glVertex3f(xStruct1[0], yStruct1[0], 0);
    glVertex3f(xStruct1[0], yStruct1[0], z);
    glEnd();

    glBegin(GL_TRIANGLE_STRIP);
    for(i = 0; i<10; i++) {
        glVertex3f(xStruct2[i], yStruct2[i], z);
        glVertex3f(xStruct2[i], yStruct2[i], 0);
        i = i + 1;
    }
    glVertex3f(xStruct2[2], yStruct2[2], 0);
    glVertex3f(xStruct2[2], yStruct2[2], z);
    glVertex3f(xStruct2[0], yStruct2[0], 0);
    glVertex3f(xStruct2[0], yStruct2[0], z);
    glEnd();

    glBegin(GL_TRIANGLE_STRIP);
    for(i = 0; i<10; i++) {
        glVertex3f(xStruct3[i], yStruct3[i], z);
        glVertex3f(xStruct3[i], yStruct3[i], 0);
        i = i + 1;
    }
    glVertex3f(xStruct3[2], yStruct3[2], 0);
    glVertex3f(xStruct3[2], yStruct3[2], z);
    glVertex3f(xStruct3[0], yStruct3[0], 0);
    glVertex3f(xStruct3[0], yStruct3[0], z);
    glEnd();

    glBegin(GL_TRIANGLE_STRIP);
    for(i = 0; i<10; i++) {
        glVertex3f(xStruct4[i], yStruct4[i], z);
        glVertex3f(xStruct4[i], yStruct4[i], 0);
        i = i + 1;
    }
    glVertex3f(xStruct4[2], yStruct4[2], 0);
    glVertex3f(xStruct4[2], yStruct4[2], z);
    glVertex3f(xStruct4[0], yStruct4[0], 0);
    glVertex3f(xStruct4[0], yStruct4[0], z);
    glEnd();

    glBegin(GL_TRIANGLE_STRIP);
    for(i = 0; i<10; i++) {
        glVertex3f(xStruct5[i], yStruct5[i], z);
        glVertex3f(xStruct5[i], yStruct5[i], 0);
        i = i + 1;
    }
    glVertex3f(xStruct5[2], yStruct5[2], 0);
    glVertex3f(xStruct5[2], yStruct5[2], z);
    glVertex3f(xStruct5[0], yStruct5[0], 0);
    glVertex3f(xStruct5[0], yStruct5[0], z);
    glEnd();

    glBegin(GL_TRIANGLE_STRIP);
    for(i = 0; i<10; i++) {
        glVertex3f(xStruct6[i], yStruct6[i], z);
        glVertex3f(xStruct6[i], yStruct6[i], 0);
        i = i + 1;
    }
    glVertex3f(xStruct6[2], yStruct6[2], 0);
    glVertex3f(xStruct6[2], yStruct6[2], z);
    glVertex3f(xStruct6[0], yStruct6[0], 0);
    glVertex3f(xStruct6[0], yStruct6[0], z);
    glEnd();

}
