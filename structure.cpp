#include "../shared/structure.h"

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

void Structure::draw_strucutre_right(int i, float pos, float x, float z)
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
