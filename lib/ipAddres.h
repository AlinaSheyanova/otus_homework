#include <string>
#include <iostream>

class ipAddress
{

    union ipStruct
    {
        uint full = 0;
        uint8_t bytes[4];
    };

    bool is_valid = true;

    ipStruct data;

    friend std::istream& operator>>(std::istream& in, ipStruct& data);

public:

    ipAddress() = default;

    ipAddress(std::string stringIp);

    bool isValid();

    std::string toString() const;

    friend bool operator==(const ipAddress& first, const ipAddress& second);
    
    friend bool operator!=(const ipAddress& first, const ipAddress& second);

    friend bool operator<(const ipAddress& first, const ipAddress& second);
    
    friend bool operator>(const ipAddress& first, const ipAddress& second);

    friend bool operator<=(const ipAddress& first, const ipAddress& second);

    friend bool operator>=(const ipAddress& first, const ipAddress& second);

    friend std::ostream& operator<<(std::ostream& out, const ipAddress& object);

    friend std::istream& operator>>(std::istream& in, ipAddress& object);
};