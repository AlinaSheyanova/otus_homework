#include "VectorEditorModel.h"
#include "VectorEditorView.h"

#include <iostream>

void VectorEditorModel::setActiveDocument(std::shared_ptr<VectorDocument> document) {
    _document = document;
    if (document != nullptr)
        document->setObserver(shared_from_this());
}

std::shared_ptr<VectorDocument> VectorEditorModel::getActiveDocument() {
    return _document;
}

void VectorEditorModel::notifyDocumentChanged() {
    std::cout << "Document changed. updateView" << std::endl;
    _view->draw(_document);
}
