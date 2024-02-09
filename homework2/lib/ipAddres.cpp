#include "ipAddres.h"
#include <sstream>
#include <regex>

void readDelimeter(std::istream& in)
{
    char d;
    in >> d;
    if (d !='.')
        throw std::runtime_error("invalid input");
}

int readByte(std::istream& in)
{
    int t = -1;
    in >> t;
    if (t >= 0 && t <=255)
        return t;
    
    throw std::runtime_error("invalid input");
}

std::istream& operator>>(std::istream& in, ipAddress::ipStruct& data)
{
    data.bytes[3] = readByte(in);
    readDelimeter(in);
    data.bytes[2] = readByte(in);
    readDelimeter(in);
    data.bytes[1] = readByte(in);
    readDelimeter(in);
    data.bytes[0] = readByte(in);
    return in;
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