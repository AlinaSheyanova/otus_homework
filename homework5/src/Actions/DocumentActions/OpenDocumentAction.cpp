#include "OpenDocumentAction.h"

OpenDocumentAction::OpenDocumentAction(std::shared_ptr<VectorEditorModel> model, std::string_view filePath) :
        _model(model), _newFilePath(std::move(filePath)) {}

void OpenDocumentAction::Execute() {
    if (!_newFilePath.empty()) {
        _model->setActiveDocument(std::make_shared<VectorDocument>(_newFilePath));
    } else {
        _model->setActiveDocument(nullptr);
    }
}

void OpenDocumentAction::Undo() {
    _model->setActiveDocument(nullptr);
}
