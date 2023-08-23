#include <iostream>

struct ivector3d_1 
{
    int array[3];
};


struct ivector3d_2 
{
    int *array;
};


void scale1(ivector3d_1 *v, int k) 
{
    for (int i = 0; i != 3; ++i)
        v->array[i] *= k;
}


void scale2(ivector3d_1 v, int k) 
{
    for (int i = 0; i != 3; ++i)
        v.array[i] *= k;
}


void scale3(ivector3d_2 v, int k) 
{
    for (int i = 0; i != 3; ++i)
        v.array[i] *= k;
}


int main()
{
    // ivector3d_1 iv3d = {1, 1, 1};
    // scale1(&iv3d, 2);   // изменяет вектор iv3d
    // scale2(iv3d, 2);       // не меняет вектор iv3d, а только создает копию и меняет ее
    int temp_array[3] = {1, 1, 1};
    ivector3d_2 iv3d = {temp_array};
    scale3(iv3d, 2);
    for (int i=0; i < 3; i++){
        std::cout << iv3d.array[i] << std::endl;
    }
    return 0;
}
