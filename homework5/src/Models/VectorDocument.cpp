#include "VectorDocument.h"

VectorDocument::VectorDocument(std::string_view filePath)
        : _filePath(filePath) {

}

void VectorDocument::importFromFile(const std::string &filepath) {

}

void VectorDocument::exportToFile(const std::string &filepath) {

}

std::string VectorDocument::getFilepath() {
    return _filePath;
}

int VectorDocument::addPrimitive(std::shared_ptr<IGraphElement> primitive) {
    primitives.push_back(primitive);
    return primitives.size()-1;
}

void VectorDocument::removePrimitive(int index) {
    primitives.erase(primitives.begin() + index);
}

std::shared_ptr<IGraphElement> VectorDocument::getPrimitive(int index) {
    return primitives[index];
}

void VectorDocument::drawDocument() const {
    for(const auto &primitive : primitives) {
        primitive->draw();
    }
}

int VectorDocument::getSelectedElementIndex() const {
    return _selectedItemIndex;
}

std::shared_ptr<IGraphElement> VectorDocument::getElementIn(Point point) {
    auto index = getElementIndexIn(point);
    if (index != -1) {
        return primitives[index];
    }
    return nullptr;
}

int VectorDocument::getElementIndexIn(Point point) {
    for (int i = 0; i < primitives.size(); i++) {
        if (primitives[i]->contains(point)) {
            return i;
        }
    }
    return -1;
}

void VectorDocument::setSelected(int index) {
    _selectedItemIndex = index;
}
