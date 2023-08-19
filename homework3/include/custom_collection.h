/**
 * @file custom_collection.h
 * @author Smirnova Alina
 * @date 10 Feb 2024
 * @brief File containing custom ring buffer implementation.
 */
#include <memory>

template<class T, class Allocator = std::allocator<T>>
class CustomCollection {
    Allocator alloc;
    T* array;
    std::size_t capacity;
    std::size_t count;

public:
    CustomCollection() : capacity(0), count(0), array(nullptr) {}

    ~CustomCollection()
    {
        if(array != nullptr)
        {
            alloc.deallocate(array, capacity);
        }
    }

    typedef T* iterator;
    typedef const T* const_iterator;

    iterator begin() { return array; }
    const_iterator begin() const { return array; }
    iterator end() { return array + size(); }
    const_iterator end() const { return array + size(); }

    void push_back(const T& item)
    {
        if(count == capacity)
        {
            std::size_t old_capacity = capacity;
            capacity = (capacity == 0) ? 1 : 2 * capacity;
            T* tmp = alloc.allocate(capacity);

            if(array != nullptr)
            {
                for(size_t i = 0; i < count; i++)
                {
                    tmp[i] = array[i];
                }

                alloc.deallocate(array, old_capacity);
            }

            array = tmp;
        }

        array[count++] = item;
    }

    T& operator[](std::size_t index)
    {
        return array[index];
    }

    const T& operator[](std::size_t index) const
    {
        return array[index];
    }

    bool empty() const
    {
        return count == 0;
    }

    std::size_t size() const
    {
        return count;
    }
};