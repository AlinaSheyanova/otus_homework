//
// Created by Lina1 on 26.02.2024.
//
#pragma once

#include <string_view>
#include <stack>
#include <memory>

#include "Models/VectorEditorModel.h"
#include "Actions/ActionComposition.h"
#include "Actions/DocumentActions/OpenDocumentAction.h"
#include "Actions/DocumentActions/CloseDocumentAction.h"
#include "Actions/DocumentActions/SaveDocumentToFile.h"
#include "Actions/DocumentActions/CreateDocumentAction.h"

class VectorEditorController : public std::enable_shared_from_this<VectorEditorController>{

    std::stack<std::shared_ptr<IUserAction>> _actionHistory;
    std::shared_ptr<VectorEditorModel> _model;

public:

    void openDocument(std::string_view filePath)
    {
        std::shared_ptr<IUserAction> action;
        if (_model->getActiveDocument() != nullptr)
        {
            auto command = std::make_shared<ActionComposition>();
            command->addAction(CloseDocumentAction(_model));
            command->addAction(OpenDocumentAction(_model, filePath));
            action = command;
        }
        else
        {
            action = std::make_shared<OpenDocumentAction>(_model, filePath);
        }
        action->Execute();
        _actionHistory.push( action );
    };

    void closeDocument()
    {
        //TODO check last save and save if it is need
        auto action = std::make_shared<CloseDocumentAction>(_model);
        action->Execute();
        _actionHistory.push( action );
    };

    void saveDocument(std::string_view filePath)
    {
        auto action = std::make_shared<SaveDocumentToFile>(_model, filePath);
        action->Execute();
        _actionHistory.push( action );
    };

    void createDocument()
    {
        auto action = std::make_shared<CreateDocumentAction>(_model);
        action->Execute();
        _actionHistory.push( action );
    };


    void addGraphicsPrimitive();
    void deleteGraphicsPrimitive();
    void moveGraphicsPrimitive();
    void resizeGraphicsPrimitive();
    void selectGraphicsPrimitives();

};


