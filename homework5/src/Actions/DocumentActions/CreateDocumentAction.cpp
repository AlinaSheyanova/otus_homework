#include "CreateDocumentAction.h"

CreateDocumentAction::CreateDocumentAction(std::shared_ptr<VectorEditorModel> model) :
        _model(model) {}

void CreateDocumentAction::Execute() {
    _model->setActiveDocument(std::make_shared<VectorDocument>());
}

void CreateDocumentAction::Undo() {
    _model->setActiveDocument(nullptr);
}
