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
#include "Actions/PrimitivesActions/CreatePrimitiveAction.h"
#include "Actions/PrimitivesActions/DeletePrimitiveAction.h"
#include "Actions/PrimitivesActions/SelectPrimitiveAction.h"

class VectorEditorController : public std::enable_shared_from_this<VectorEditorController>{

    std::stack<std::shared_ptr<IUserAction>> _actionHistory;
    std::stack<std::shared_ptr<IUserAction>> _canceledActions;
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


    void addLine()
    {
        auto action = std::make_shared<CreatePrimitiveAction<Line>>(_model);
        action->Execute();
        _actionHistory.push( action );
    }

    void addRectangle()
    {
        auto action = std::make_shared<CreatePrimitiveAction<Rectangle>>(_model);
        action->Execute();
        _actionHistory.push( action );
    }

    void deleteSelectedGraphicsPrimitive()
    {
        auto action = std::make_shared<DeletePrimitiveAction>(_model);
        action->Execute();
        _actionHistory.push(action);
    }

    void selectGraphicsPrimitives(Point point)
    {
        auto action = std::make_shared<SelectPrimitiveAction>(_model, point);
        action->Execute();
        _actionHistory.push(action);
    }

    void undo()
    {
        if (_actionHistory.empty())
            return;
        auto action = _actionHistory.top();
        _actionHistory.pop();
        action->Undo();
        _canceledActions.push(action);

    }

    void redo()
    {
        if (_canceledActions.empty())
            return;
        auto action = _canceledActions.top();
        _canceledActions.pop();
        action->Execute();
        _actionHistory.push(action);
    }

};


