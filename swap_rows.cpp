#include <iostream>


int min_elem_row(int *m[], unsigned rows, unsigned cols){
    int minimum = m[0][0];
    int min_position = 0;

    for (unsigned i = 0; i < rows; i++)
    {
        for (unsigned j = 0; j < cols; j++)
        {
            if (m[i][j] < minimum)
            {
                minimum = m[i][j];
                min_position = i;
            }
            
        }
        
    }
    return min_position;
}


void swap_min(int *m[], unsigned rows, unsigned cols)
{   
    int min_row = min_elem_row(m, rows, cols);
    int * temp = m[min_row];
    m[min_row] = m[0];
    m[0] = temp;
}


int main() {
    unsigned rows = 3;
    unsigned cols = 3;
    int *m[rows] = {};
    int tmp[][cols] = {{1,1,1},{5,5,6},{2,3,5}};
    for (unsigned i = 0; i < rows; ++i) {
        m[i] = new int[cols];
        for (unsigned j = 0; j < cols; ++j)
            m[i][j] = tmp[i][j];
    }

  swap_min(m,rows,cols);

  for (unsigned i = 0; i < rows; ++i) {
    for (unsigned j = 0; j < cols; ++j)
      std::cout << m[i][j];
    std::cout << "\n";
  }
  return 0;
}