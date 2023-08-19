#include <iostream>
#include <cstdlib>

#include <map>
#include <vector>
#include <list>

#include "../lib/custom_allocator.h"

int main(int argc, char** argv)
{
    std::map<int, int> map_object;
    int f = 1;
    for (int i = 1; i <= 10; i++)
    {
        f *= i;
        map_object[i]= f;
    }

    for (int i = 1; i <= 10; i++)
    {
        std::cout << "["<<i<<"]" << map_object[i] << std::endl;
    }
     
    std::map<int, int, std::less<int>, CustomAllocator<std::pair<const int, int>, BlockAllocStrategyFix<10>>>
     map_object_custom_alloc {{{1,1}}, CustomAllocator<std::pair<const int, int>, BlockAllocStrategyFix<10>>()};
    int f2 = 1;
    for (int i = 1; i <= 10; i++)
    {
        f2 *= i;
        map_object_custom_alloc[i] = f2;
    }

    for (int i = 1; i <= 10; i++)
    {
        std::cout << "["<<i<<"]" << map_object_custom_alloc[i] << std::endl;
    }

    std::vector<int, CustomAllocator<int, BlockAllocStrategyFix<10>>> v {CustomAllocator<int, BlockAllocStrategyFix<10>>()};
    v.reserve(5);

    std::list<int, CustomAllocator<int, BlockAllocStrategyFlex<10, 5>>> v1 {CustomAllocator<int, BlockAllocStrategyFlex<10, 5>>()};
    v1.resize(10);
    v1.resize(15);
}