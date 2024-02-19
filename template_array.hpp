#include <cstddef>

template <typename T>
class Array
{
private:
    T *data_;
    size_t size_;

public:
    explicit Array(size_t size = 0, const T &value = T()) : data_(new T[size]), size_(size)
    {
        for (size_t i = 0; i < size; i++)
        {
            this->data_[i] = value;
        }
    }

    Array(const Array &other)
    {
        this->size_ = other.size_;
        this->data_ = new T[size_];
        for (size_t i = 0; i < this->size_; i++)
        {
            data_[i] = other.data_[i];
        }
    }

    ~Array() { delete[] data_; }

    Array & operator=(Array const &other)
    {
        if (this != &other)
        {
            delete[] data_;
            this->size_ = other.size_;
            this->data_ = new T[size_];
            for (size_t i = 0; i < this->size_; i++)
            {
                data_[i] = other.data_[i];
            }
        }
        return *this;
    }

    size_t size() const { return size_; }

    T &operator[](size_t i) { return data_[i]; }

    const T &operator[](size_t i) const { return data_[i]; }
};
