#include "SaveDocumentToFile.h"

SaveDocumentToFile::SaveDocumentToFile(std::shared_ptr<VectorEditorModel> model, std::string_view filePath) :
        _model(model), _newFilePath(std::move(filePath)) {}

void SaveDocumentToFile::Execute() {
    if (!_newFilePath.empty()) {
        _model->getActiveDocument()->exportToFile(_newFilePath);
    }
}

void SaveDocumentToFile::Undo() {
    //do nothing
}
