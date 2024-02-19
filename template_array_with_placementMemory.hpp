#include <cstddef>

template <typename T>
class Array
{
private:
    T *data_;
    size_t size_;

public:
    explicit Array(size_t size, const T &value = T()) : size_(size)
    {
        data_ = static_cast<T*>(operator new[] (size_ * sizeof(T))); // в примере data_ --  это placementMemory

        for (size_t i = 0; i < size; i++)
        {
            new (data_ + i) T(value);
        }
    }

    Array(const Array &other)
    {
        this->size_ = other.size_;
        data_ = static_cast<T*>(operator new[] (size_ * sizeof(T)));
        
        for (size_t i = 0; i < this->size_; i++)
        {
            new (data_ + i) T(other.data_[i]);
        }
    }

    Array(){
        this->size_ = 0;
        this->data_ = nullptr;
    }

    ~Array() {
        for (size_t i = 0; i < size_; i++)
        {
            data_[i].~T();
        }
        operator delete[] (data_);
    }

    Array & operator=(Array const &other)
    {
        if (this != &other)
        {
            for (size_t i = 0; i < size_; i++)
            {
                data_[i].~T();
            }
            operator delete [] (data_);
            this->size_ = other.size_;
            this->data_ = static_cast<T*>(operator new[] (size_ * sizeof(T)));
            for (size_t i = 0; i < this->size_; i++)
            {
                new (data_ + i) T(other.data_[i]);
            }
        }
        return *this;
    }

    size_t size() const { return size_; }

    T &operator[](size_t i) { return data_[i]; }

    const T &operator[](size_t i) const { return data_[i]; }
};
