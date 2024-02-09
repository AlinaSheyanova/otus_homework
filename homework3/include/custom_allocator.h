#include <vector>
#include <limits>
#include <cstdint>

template <std::size_t BlockCapacity>
struct BlockAllocStrategyFix
{
    static_assert(BlockCapacity != 0u, "BlockCapacity size must be more, than zero");
    static_assert(BlockCapacity <= std::numeric_limits<std::uint32_t>::max(),
        "BlockCapacity must be less or equal max value of the uint32_t");
public:

    explicit BlockAllocStrategyFix(const std::size_t elementsize)
    : capacity(BlockCapacity * elementsize)
    {
        pool = new std::uint8_t[capacity];
    }

    void* allocate(std::size_t size)
    {
        if (size == 0u)
        {
            return nullptr;
        }
        std::cout << " strategy alloc current id = " << current_id 
            << ", size = " << size << ", capacity = "  << capacity << std::endl;
        if ((current_id + size) > capacity)
            throw std::bad_alloc();
        auto result = &pool[current_id];
        current_id += size;
        return result;
    }

    void deallocate(void* memory_ptr, std::size_t size)
    {
        return;
    }
private:
    std::uint64_t capacity = 0ul;
    std::uint8_t* pool = nullptr;
    std::int64_t current_id= 0u;
};

template <std::size_t BlockCapacity, std::size_t BlockCount>
struct BlockAllocStrategyFlex
{
    static_assert(BlockCapacity != 0u, "BlockCount size must be more, than zero");
    static_assert(BlockCapacity <= std::numeric_limits<std::uint32_t>::max(),
        "BlockCount must be less or equal max value of the uint32_t");
public:

    explicit BlockAllocStrategyFlex(const std::size_t elementsize)
    : block_capacity_bytes(BlockCapacity * elementsize)
    , rest_bytes(block_capacity_bytes * BlockCount)
    {
    }

    void* allocate(std::size_t size)
    {
        if (size == 0u)
        {
            return nullptr;
        }
         std::cout << " strategy alloc pool size = " << pool.size() <<", current id = " << current_id_in_block 
            << ", size = " << size << ", capacity = "  << block_capacity_bytes << std::endl;
        if (current_block == nullptr || (current_id_in_block + size) > block_capacity_bytes)
        {
            if (pool.size() >= BlockCount || size > block_capacity_bytes)
            {
                throw std::bad_alloc();
            }
            current_block = new uint8_t[block_capacity_bytes];
            pool.push_back(current_block);
            current_id_in_block = 0;
        }
        auto result = &current_block[current_id_in_block];
        current_id_in_block += size;
        return result;
    }

    void deallocate(void* memory_ptr, std::size_t size)
    {
        return;
    }
private:
    const std::int64_t block_capacity_bytes = 0;
    int64_t rest_bytes = 0;
    std::vector<std::uint8_t*> pool;
    std::int64_t current_id_in_block = 0u;
    std::uint8_t* current_block = nullptr;
};


template <typename T, typename Strategy>
struct CustomAllocator
{

    using value_type = T;
    CustomAllocator() noexcept  : strategy(sizeof(value_type)){ };

    template <typename U, typename StrategyU>
    CustomAllocator(const CustomAllocator<U, StrategyU>& a) noexcept : strategy(sizeof(value_type)) {};

    T* allocate (std::size_t n) 
    {
        std::cout << "allocate " << n << " elements"<<std::endl;
        return reinterpret_cast<T*>(strategy.allocate(n*sizeof(value_type)));
    };

    void deallocate (T* p, std::size_t n) 
    {
        std::cout << "deallocate " << n << " elements"<<std::endl;
        strategy.deallocate(p, n);
    }

    template< typename U, typename StrategyU >
    struct rebind
    {
        typedef CustomAllocator<U, StrategyU> other;
    };

    using propagate_on_container_copy_assignment = std::true_type;
    using propagate_on_container_move_assignment = std::true_type;
    using propagate_on_container_swap = std::true_type;

private:
    Strategy strategy;
};

template <class T, class U, typename StrategyT, typename StrategyU>
constexpr bool operator== (const CustomAllocator<T, StrategyT>&a, const CustomAllocator<U, StrategyU>&b) noexcept
{ return a.strategy == b.strategy;}

template <class T, class U, typename StrategyT, typename StrategyU>
constexpr bool operator!= (const CustomAllocator<T, StrategyT>&a, const CustomAllocator<U, StrategyU>&b) noexcept
{ return a.strategy != b.strategy;}