#include <cstddef>
#include <vector>
#include <iostream>
#include <ostream>

// Параметры функции copy_n идут в следующем
// порядке:
//   1. целевой массив
//   2. массив источник
//   3. количество элементов, которые нужно
//      скопировать
//
// Вам нужно реализовать только функцию copy_n,
// чтобы ее можно было вызвать так, как показано
// в примере.

// put your code here

template <typename T, typename U>
void copy_n(T *copy_to, U *copy_from, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        copy_to[i] = T(copy_from[i]); // если есть такой конструктор
        // либо
        // copy_to[i] = (T) copy_from[i]; // если есть приведение типов
    }
}

template <typename T, typename comp_t>
T minimum(vector<T> const &a, comp_t less)
{
    T min1 = a[0];
    for (size_t i = 1; i < a.size(); i++)
    {
        if (less(a[i], min1))
        {
            min1 = a[i];
        }
    }
    return min1;
}

template <typename T>
void flatten(const std::vector<T>& array, std::ostream& out)
{
    for (size_t i = 0; i < array.size(); i++)
    {
        out << array[i] << " ";
    }
}

template <typename T>
void flatten(const std::vector <std::vector <T> > & array, std::ostream& out)
{
    for (size_t i = 0; i < array.size(); i++)
    {
        flatten(array[i], out);
    }
}

template <typename T, typename U>
struct SameType
{
    const static bool value = false;
};

template <typename T>
struct SameType <T, T>
{
    const static bool value = true;
};

// реализуйте шаблонную функцию array_size,
// которая возвращает значение типа size_t.

// put your code here
template <typename T, size_t Size>
size_t array_size(T (&array)[Size]){
    return Size;
}
