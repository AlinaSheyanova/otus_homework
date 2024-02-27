//
// Created by Lina1 on 26.02.2024.
//
#pragma once
#include <memory>
#include <string>
#include <utility>

#include "../IUserAction.h"
#include "../../Models/VectorEditorModel.h"

class CreateDocumentAction : public IUserAction
{
    std::shared_ptr<VectorEditorModel> _model;
public:
    CreateDocumentAction(std::shared_ptr<VectorEditorModel> model) :
            _model(model) {};

    void Execute() override
    {
        _model->setActiveDocument(std::make_shared<VectorDocument>());
    };

    void Undo() override
    {
        _model->setActiveDocument(nullptr);
    };

};
