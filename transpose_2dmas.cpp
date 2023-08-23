#include <iostream>


int ** create_array2d( size_t a , size_t b) {
    int ** m = new int *[a];
    m[0] = new int[a * b];
    for (size_t i = 1; i != a; ++i)
    m[i] = m[i - 1] + b;
    return m;
}


void free_array2d(int ** m, size_t a , size_t b) {
    delete [] m[0];
    delete [] m;
}


int ** transpose(const int * const * m, unsigned rows, unsigned cols)
{
    int **m_tr = create_array2d(cols, rows);

    for (size_t i = 0; i < cols; i++)
    {
        for (size_t j = 0; j < rows; j++)
        {
            m_tr[i][j] = m[j][i];
        }
        
    }
    return m_tr;
    
}


int main()
{   
    size_t m = 3, n = 4; // задаем размеры матрицы
    int **matrix = create_array2d(m, n);

    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            matrix[i][j] = n * i + j + 1; // заполнение матрицы целыми числами от 0 до n*m
        }
        
    }

    int **transp_matrix = transpose(matrix, m, n);
    
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            std::cout << transp_matrix[i][j] << " ";
        }
        std::cout << std::endl;
        
    }

    return 0;
}
