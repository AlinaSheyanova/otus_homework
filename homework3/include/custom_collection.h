/**
 * @file custom_collection.h
 * @author Smirnova Alina
 * @date 10 Feb 2024
 * @brief File containing custom ring buffer implementation.
 */

#include <memory>
#include <exception>

/**
 * CustomRingBuffer is a type of queue where the oldest data is overwritten
 * by the newest data when the buffer is full.
 * This buffer is not intended for use with multiple thread calls.
 * @tparam T - type of values in collection
 * @tparam Allocator - type of Allocator. std::allocator by default
 */
template <typename T, typename Allocator = std::allocator<T>>
class CustomRingBuffer
{
public:

    class Iterator
    {

    };

    /**
     * Construct a ring buffer of a specified size
     * @param capacity - the maximum number of elements that can be stored in the buffer.
     */
    explicit CustomRingBuffer(size_t capacity);

    /**
     * Copy constructor
     * @param other - another instance of ring buffer
     */
    CustomRingBuffer(const CustomRingBuffer& other) = default;

    /**
    * Move constructor
    * @param other - another instance of ring buffer
    */
    CustomRingBuffer(CustomRingBuffer&& other) = default;

    /**
    * Destructor
    */
    ~CustomRingBuffer() = default;

    auto begin();

    auto end();

    /**
     * @return the maximum number of elements that can be stored in the buffer.
     */
    [[nodiscard]] size_t capacity() const;

    /**
     * @return the actual number of elements that can be stored in the buffer.
     */
    [[nodiscard]] size_t count() const;

    /**
     * Add specified element in this buffer.The oldest element will be lost if the buffer is full.
     * @param value - new element to insert in collection
     */
    void add(const T& value);

    /**
     * Add range of elements in this buffer.The oldest elements will be lost if the buffer is full.
     * @param values - a vector of values to insert
     */
    void addRange(const std::vector<T>& values);

    /**
     * Get the element from the buffer
     * @return - the oldest value in the buffer
     */
    T get();

    /**
     * Get range of oldest elements
     * @param count - a count of elements to return
     * @return - a range of oldest elements
     */
    std::vector<T> get(size_t count);

    [[nodiscard]] size_t totalMissed() const;

    [[nodiscard]] size_t lastMissed() const;

    void resize(size_t capacity);

private:
    T* _storage = nullptr;
    size_t _capacity = 0;

    T* _writePointer = nullptr;
    T* _readPointer = nullptr;

    std::allocator<T> _allocator;
};


template <typename T, typename Allocator>
CustomRingBuffer<T, Allocator>::CustomRingBuffer(size_t capacity)
{
    _storage = _allocator.allocate(sizeof(T)*capacity);
    _writePointer = _storage;
    _readPointer = _storage;
    _capacity = capacity;
}

template <typename T, typename Allocator>
auto CustomRingBuffer<T, Allocator>::begin()
{
    return _storage;
}

template <typename T, typename Allocator>
auto CustomRingBuffer<T, Allocator>::end()
{
    return _storage;
}

template<typename T, typename Allocator>
void CustomRingBuffer<T, Allocator>::resize(size_t capacity)
{
    throw std::exception();
}

template<typename T, typename Allocator>
size_t CustomRingBuffer<T, Allocator>::lastMissed() const {
    return 0;
}

template<typename T, typename Allocator>
size_t CustomRingBuffer<T, Allocator>::totalMissed() const {
    return 0;
}

template<typename T, typename Allocator>
std::vector<T> CustomRingBuffer<T, Allocator>::get(size_t count) {
    return std::vector<T>();
}

template<typename T, typename Allocator>
T CustomRingBuffer<T, Allocator>::get() {
    return *(_readPointer++);
}

template<typename T, typename Allocator>
void CustomRingBuffer<T, Allocator>::addRange(const std::vector<T> &values) {
    for(auto value : values)
    {
        add(value);
    }
}

template<typename T, typename Allocator>
void CustomRingBuffer<T, Allocator>::add(const T &value) {
    *_writePointer = value;
    _writePointer++;
}

template<typename T, typename Allocator>
size_t CustomRingBuffer<T, Allocator>::count() const {
    return _writePointer - _storage;
}

template<typename T, typename Allocator>
size_t CustomRingBuffer<T, Allocator>::capacity() const {
    return _capacity;
}


