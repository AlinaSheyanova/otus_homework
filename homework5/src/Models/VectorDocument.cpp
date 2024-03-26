#include "VectorDocument.h"
#include "VectorEditorModel.h"

#include <iostream>

VectorDocument::VectorDocument(std::string_view filePath)
        : _filePath(filePath) {

}

void VectorDocument::importFromFile(const std::string &filepath) {
    std::cout << "Document imported from file" << std::endl;
}

void VectorDocument::exportToFile(const std::string &filepath) {
    std::cout << "Document exported to file" << std::endl;
}

std::string VectorDocument::getFilepath() {
    return _filePath;
}

int VectorDocument::addPrimitive(std::shared_ptr<IGraphElement> primitive) {
    primitives.push_back(primitive);
    _model->notifyDocumentChanged();
    return primitives.size()-1;
}

void VectorDocument::removePrimitive(int index) {
    primitives.erase(primitives.begin() + index);
    _model->notifyDocumentChanged();
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

std::shared_ptr<IGraphElement> VectorDocument::getElementIn(Point point) const {
    auto index = getElementIndexIn(point);
    if (index != -1) {
        return primitives[index];
    }
    return nullptr;
}

int VectorDocument::getElementIndexIn(Point point) const {
    for (int i = 0; i < primitives.size(); i++) {
        if (primitives[i]->contains(point)) {
            return i;
        }
    }
    return -1;
}

void VectorDocument::setSelected(int index) {
    _selectedItemIndex = index;
    _model->notifyDocumentChanged();
}

void VectorDocument::setObserver(std::shared_ptr<VectorEditorModel> model) {
    _model = model;
}
