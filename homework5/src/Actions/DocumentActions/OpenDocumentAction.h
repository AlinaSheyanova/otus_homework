//
// Created by Lina1 on 26.02.2024.
//
#pragma once
#include <memory>
#include <string_view>
#include <utility>

#include "../IUserAction.h"
#include "../../Models/VectorEditorModel.h"

class OpenDocumentAction : public IUserAction
{
    std::shared_ptr<VectorEditorModel> _model;
    std::string _newFilePath;
public:
    OpenDocumentAction(std::shared_ptr<VectorEditorModel> model, std::string_view filePath) :
     _model(model), _newFilePath(std::move(filePath)) {};

    void Execute() override
    {
        if (!_newFilePath.empty()) {
            _model->setActiveDocument(std::make_shared<VectorDocument>(_newFilePath));
        } else {
            _model->setActiveDocument(nullptr);
        }
    };

    void Undo() override
    {
        _model->setActiveDocument(nullptr);
    };

};

