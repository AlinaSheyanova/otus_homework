//
// Created by Lina1 on 26.02.2024.
//
#pragma once
#include <memory>
#include <string>
#include <utility>

#include "../IUserAction.h"
#include "../../Models/VectorEditorModel.h"

class CloseDocumentAction : public IUserAction
{
    std::shared_ptr<VectorEditorModel> _model;
    std::string _currentFilePath;
public:
    CloseDocumentAction(std::shared_ptr<VectorEditorModel> model) :
            _model(model) {};

    void Execute() override
    {
        auto currentDocument = _model->getActiveDocument();
        if(currentDocument != nullptr) {
            _currentFilePath = currentDocument->getFilepath();
        }
        _model->setActiveDocument(nullptr);

    };

    void Undo() override
    {
        if (!_currentFilePath.empty()) {
            _model->setActiveDocument(std::make_shared<VectorDocument>(_currentFilePath));
        }
    };

};


