#ifndef STRUCTURE_H_INCLUDED
#define STRUCTURE_H_INCLUDED

class Structure
{
    private:

    float xSide = {6.4, 6.4, 3.2, 3.2, 6.4, 6.4, 4.8, 4.8, 3.2, 3.2, 4.8, 4.8, 1.6, 1.6, 0.8, 0.8, 4.8,
         4.8, 3.2, 3.2, 0.8, 0.8, 3.2, 2.8, 2.8, 6.4, 6.4, 4.0, 4.0, 6.4, 6.4, 3.2, 3.2, 4.0,
         4.0, 3.2, 3.2, 2.8, 2.8, 2.4, 2.4, 0.8, 0.8, 2.4, 2.4, 0.8, 0.8, 6.4, 6.4, 3.2, 3.2, 6.4,
         6.4, 1.6, 1.6, 0.8, 0.8, 2.4, 2.4, 2.08, 1.6, 1.6, 0.8, 0.8, 6.4, 6.4};
    float ySide = {0, 3.0, 4, 40, 41, 46, 47, 51, 51.5, 53.5, 54, 58, 59, 62, 62.25, 70.75, 72, 74,
             74.5, 76.5, 77, 89, 90, 94, 96, 97.5, 102, 103, 154, 155, 159, 160, 161, 162,
             173, 174, 178, 178.1, 182, 182.1, 186, 187, 200, 201, 206, 207, 219, 221, 225, 226,
             276, 277, 281, 282.5, 285.5, 286, 306, 307, 312, 316, 320, 324, 325, 337, 338, 342};

    float xStruct1 = {8, 8.8, 7.2, 8.8, 7.2, 8};
    float yStruct1 = {63.5, 64, 64, 68, 68, 68.5};

    float xStruct2 = {8, 10.4, 5.6, 10.4, 5.6, 8.8, 7.2, 8.8, 7.2, 8};
    float yStruct2 = {78, 78.5, 78.5, 84, 84, 84.5, 84.5, 87.5, 87.5, 88};

    float xStruct3 = {8, 10.4, 5.6, 10.4, 5.6, 8.8, 7.2, 8.8, 7.2, 8};
    float yStruct3 = {190, 191, 191, 195, 195, 195.5, 195.5, 198, 198, 199};

    float xStruct4 = {8, 9.6, 6.4, 9.6, 6.4, 10.4, 5.6, 10.4, 5.6, 8};
    float yStruct4 = {208, 209, 209, 212, 212, 212, 212, 216, 216, 217};

    float xStruct5 = {8, 12.8, 3.2, 12.8, 3.2, 13.6, 2.4, 13.6, 2.4, 11.2, 4.8, 11.2, 4.8, 13.6, 2.4, 13.6, 2.4, 8.8, 7.2, 8.8, 7.2, 8};
    float yStruct5 = {287, 288, 288, 292, 292, 292.5, 292.5, 294, 294, 294.5, 294.5, 295.5, 295.5, 296, 296, 300, 300, 301, 301, 304, 304, 305};

    float xStruct6 = {8, 13.6, 2.4, 13.6, 2.4, 8};
    float yStruct6 = {325, 327, 327, 331, 331, 333};

    void draw_structure_left(int i, float pos, int mapSize, float x, float z);
    void draw_structure_right(int i, float pos, int mapSize, float x, float z);
    void draw_side_strucutre_left(int i, float pos, int mapSize, float x, float z);
    void draw_side_strucutre_right(int i, float pos, int mapSize, float x, float z);
    void draw_midle_struct_up(float z);
    void draw_midle_structure_fill(float z);

    public:
    void draw_showing_part(float pos);

}


#endif // STRUCTURE_H_INCLUDED
