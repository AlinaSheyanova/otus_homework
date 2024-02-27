//
// Created by Lina1 on 26.02.2024.
//
#pragma once
#include <memory>
#include <string_view>
#include <utility>

#include "../IUserAction.h"
#include "../../Models/VectorEditorModel.h"

class SaveDocumentToFile : public IUserAction
{
    std::shared_ptr<VectorEditorModel> _model;
    std::string _newFilePath;
public:
    SaveDocumentToFile(std::shared_ptr<VectorEditorModel> model, std::string_view filePath) :
            _model(model), _newFilePath(std::move(filePath)) {};

    void Execute() override
    {
        if (!_newFilePath.empty()) {
            _model->getActiveDocument()->saveToFile(_newFilePath);
        }
    };

    void Undo() override
    {
        //do noting
    };

};

