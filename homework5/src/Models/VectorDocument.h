//
// Created by Lina1 on 26.02.2024.
//
#pragma once

#include <string>
#include <memory>
#include <vector>

#include "IGraphPrimitive.h"
#include "Point.h"

class VectorDocument {
    std::string _filePath;
    std::vector<std::shared_ptr<IGraphElement>> primitives;
    int _selectedItemIndex = -1;
public:

    VectorDocument() = default;

    explicit VectorDocument(std::string_view filePath)
    : _filePath(filePath)
    {

    };


    void importFromFile(const std::string &filepath) {}

    void exportToFile(const std::string &filepath) {}

    std::string getFilepath()
    {
        return _filePath;
    };

    int addPrimitive(std::shared_ptr<IGraphElement> primitive) {
        primitives.push_back(primitive);
        return primitives.size()-1;
    }

    void removePrimitive(int index) {
        primitives.erase(primitives.begin() + index);
    }

    std::shared_ptr<IGraphElement> getPrimitive(int index)
    {
        return primitives[index];
    }

    void drawDocument() const {
        for(const auto &primitive : primitives) {
            primitive->draw();
        }
    }


    int getSelectedElementIndex()
    {
        return _selectedItemIndex;
    }

    std::shared_ptr<IGraphElement> getElementIn(Point point) {
        auto index = getElementIndexIn(point);
        if (index != -1) {
                return primitives[index];
        }
        return nullptr;
    }

    int getElementIndexIn(Point point){
        for (int i = 0; i < primitives.size(); i++) {
            if (primitives[i]->contains(point)) {
                return i;
            }
        }
        return -1;
    }

    void setSelected(int index)
    {
        _selectedItemIndex = index;
    }


};

