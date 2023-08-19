#include <iostream>
#include <cstdlib>

#include <map>
#include <vector>
#include <list>

#include "custom_allocator.h"
#include "custom_collection.h"


void stdMapStdAllocator()
{
    std::map<int, int> map_object;
    int f = 1;
    map_object[0] = f;
    for (int i = 1; i <= 10; i++)
    {
        f *= i;
        map_object[i]= f;
    }

    for (int i = 1; i <= 10; i++)
    {
        std::cout << "["<<i<<"]" << map_object[i] << std::endl;
    }
}

void stdMapCustomAllocator()
{
    std::map<int, int, std::less<int>, CustomAllocator<std::pair<const int, int>, BlockAllocStrategyFix<10>>>
            map_object_custom_alloc {{{1,1}}, CustomAllocator<std::pair<const int, int>, BlockAllocStrategyFix<10>>()};
    int f2 = 1;
    map_object_custom_alloc[0] = f2;
    for (int i = 1; i <= 10; i++)
    {
        f2 *= i;
        map_object_custom_alloc[i] = f2;
    }

    for (int i = 1; i <= 10; i++)
    {
        std::cout << "["<<i<<"]" << map_object_custom_alloc[i] << std::endl;
    }
}


void useCustomCollection()
{
    CustomCollection<int> collection;
    for (int i = 0; i < 10; i++)
    {
        collection.push_back(i);
    }
    std::cout << "Custom Collection: ";
    for (const auto &item: collection) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

void useCustomCollectionWithCustomAllocator()
{
    CustomCollection<int, CustomAllocator<int, BlockAllocStrategyFix<10>>> collection2;
    for (int i = 0; i < 10; i++)
    {
        collection2.push_back(i);
    }
    std::cout << "Custom Collection with custom allocator: ";
    for (const auto &item: collection2) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}
/**
 * @brief
 *
- создание экземпляра своего контейнера для хранения значений типа int
- заполнение 10 элементами от 0 до 9
- создание экземпляра своего контейнера для хранения значений типа int с новым аллокатором,
ограниченным 10 элементами
- заполнение 10 элементами от 0 до 9
- вывод на экран всех значений, хранящихся в контейнере
 * @param argc
 * @param argv
 * @return
 */

int main(int argc, char** argv)
{
    stdMapStdAllocator();
     
    stdMapCustomAllocator();

    useCustomCollection();

    useCustomCollectionWithCustomAllocator();
}