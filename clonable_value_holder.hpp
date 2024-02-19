#include <iostream>

struct ICloneable
{
public:
    virtual ICloneable *clone() const = 0;
    virtual ~ICloneable() {}
};

// Шаблон ValueHolder с типовым параметром T,
// должен содержать одно открытое поле data_
// типа T.
//
// В шаблоне ValueHolder должен быть определен
// конструктор от одного параметра типа T,
// который инициализирует поле data_.
//
// Шаблон ValueHolder должен реализовывать
// интерфейс ICloneable, и возвращать указатель
// на копию объекта, созданную в куче, из метода
// clone.

template <typename T> // у типа T есть только конструктор копирования
struct ValueHolder : ICloneable
{
public:
    T data_;
    ValueHolder(const T &data) : data_(data) {}
    ValueHolder *clone() const override { return new ValueHolder(*this); }
};