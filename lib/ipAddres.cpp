#include "ipAddres.h"
#include <sstream>
#include <regex>

std::istream& operator>>(std::istream& in, ipAddress::ipStruct& data)
{
    int t1 = -1;
    in >> t1;
    if (t1 >= 0 && t1 <=255)
        data.bytes[3] = t1;
        char d1;
        in >> d1;
        if (d1 =='.')
        {
            int t2 = -1;
            in >> t2;
            if (t2 >= 0 && t2 <=255)
                data.bytes[2] = t2;
                char d2;
                in >> d2;
                if (d2 =='.')
                {
                    int t3 = -1;
                    in >> t3;
                    if (t3 >= 0 && t3 <=255)
                        data.bytes[1] = t3;
                        char d3;
                        in >> d3;
                        if (d3 =='.')
                        {
                            int t4 = -1;
                            in >> t4;
                            if (t4 >= 0 && t4 <=255)
                            {
                                data.bytes[0] = t4;
                                return in;
                            }
                            
                        }
                }
        }
    throw std::runtime_error("invalid input");
}

ipAddress::ipAddress(std::string stringIp)
{
    std::stringstream ss(stringIp);
    try
    {
        ss >> data;
    }
    catch(const std::exception& e)
    {
        is_valid = false;
    }
    
}

bool ipAddress::isValid()
{
    return is_valid;
}

std::string ipAddress::toString() const
{
    if (!is_valid)
        return "";
    std::stringstream ss;
    ss << std::to_string(data.bytes[3]) << "." << std::to_string(data.bytes[2]) << "."
        << std::to_string(data.bytes[1]) << "." << std::to_string(data.bytes[0]);
    return ss.str();
}

bool operator==(const ipAddress& first, const ipAddress& second)
{
    return first.data.full == second.data.full;
}

bool operator!=(const ipAddress& first, const ipAddress& second)
{
    return first.data.full != second.data.full;
}

bool operator<(const ipAddress& first, const ipAddress& second)
{
    return first.data.full < second.data.full;
}

bool operator>(const ipAddress& first, const ipAddress& second)
{
    return first.data.full > second.data.full;
}

bool operator<=(const ipAddress& first, const ipAddress& second)
{
    return first.data.full <= second.data.full;
}

bool operator>=(const ipAddress& first, const ipAddress& second)
{
    return first.data.full >= second.data.full;
}

std::ostream& operator<<(std::ostream& out, const ipAddress& object)
{
    out << object.toString();
    return out;
}

std::istream& operator>>(std::istream& in, ipAddress& object)
{
    try
    {
        in >> object.data;
    } 
    catch (const std::runtime_error& e)
    {
        object.is_valid = false;    
    }
    return in;
}