//
// Created by Lina1 on 26.02.2024.
//
#pragma once

#include <string>

class VectorDocument {
    std::string _filePath;

public:

    VectorDocument() = default;

    explicit VectorDocument(std::string_view filePath)
    : _filePath(filePath)
    {

    };

    void saveToFile(std::string_view filePath)
    {
        _filePath = filePath;
    }

    std::string getFilepath()
    {
        return _filePath;
    };

};

