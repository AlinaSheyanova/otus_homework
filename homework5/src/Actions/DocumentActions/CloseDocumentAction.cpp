#include "CloseDocumentAction.h"


CloseDocumentAction::CloseDocumentAction(std::shared_ptr<VectorEditorModel> model) :
        _model(model) {}

void CloseDocumentAction::Execute() {
    auto currentDocument = _model->getActiveDocument();
    if(currentDocument != nullptr) {
        _currentFilePath = currentDocument->getFilepath();
    }
    _model->setActiveDocument(nullptr);

}

void CloseDocumentAction::Undo() {
    if (!_currentFilePath.empty()) {
        _model->setActiveDocument(std::make_shared<VectorDocument>(_currentFilePath));
    }
}
