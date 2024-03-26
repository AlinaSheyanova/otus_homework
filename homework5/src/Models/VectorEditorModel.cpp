#include "VectorEditorModel.h"

void VectorEditorModel::setActiveDocument(std::shared_ptr<VectorDocument> document) {
    _document = document;
}

std::shared_ptr<VectorDocument> VectorEditorModel::getActiveDocument() {
    return _document;
}
