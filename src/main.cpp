#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

#include "ipAddres.h"

int main(int argc, char** argv)
{
    std::vector<ipAddress> iplist;
    while (!std::cin.eof())
    {
        ipAddress address;
        std::string string1, string2;
        std::cin >> address >> string1 >> string2;
        if (address.isValid())
            iplist.push_back(address);
    }
    std::sort(iplist.begin(), iplist.end());
    std::reverse(iplist.begin(), iplist.end());
    for (auto ip : iplist)
    {
        std::cout << ip << std::endl;
    }
    return EXIT_SUCCESS;
}