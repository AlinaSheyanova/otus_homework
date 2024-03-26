#include "VectorEditorController.h"

VectorEditorController::VectorEditorController() {
    _model = std::make_shared<VectorEditorModel>();
    _view = std::make_shared<VectorEditorView>();
    _view->setModel(_model);
}

void VectorEditorController::openDocument(std::string_view filePath) {
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
}

void VectorEditorController::closeDocument() {
    //TODO check last save and save if it is need
    auto action = std::make_shared<CloseDocumentAction>(_model);
    action->Execute();
    _actionHistory.push( action );
}

void VectorEditorController::saveDocument(std::string_view filePath) {
    auto action = std::make_shared<SaveDocumentToFile>(_model, filePath);
    action->Execute();
    _actionHistory.push( action );
}

void VectorEditorController::createDocument() {
    auto action = std::make_shared<CreateDocumentAction>(_model);
    action->Execute();
    _actionHistory.push( action );
}

void VectorEditorController::addLine() {
    auto action = std::make_shared<CreatePrimitiveAction<Line>>(_model);
    action->Execute();
    _actionHistory.push( action );
}

void VectorEditorController::addRectangle() {
    auto action = std::make_shared<CreatePrimitiveAction<Rectangle>>(_model);
    action->Execute();
    _actionHistory.push( action );
}

void VectorEditorController::deleteSelectedGraphicsPrimitive() {
    auto action = std::make_shared<DeletePrimitiveAction>(_model);
    action->Execute();
    _actionHistory.push(action);
}

void VectorEditorController::selectGraphicsPrimitives(Point point) {
    auto action = std::make_shared<SelectPrimitiveAction>(_model, point);
    action->Execute();
    _actionHistory.push(action);
}

void VectorEditorController::undo() {
    if (_actionHistory.empty())
        return;
    auto action = _actionHistory.top();
    _actionHistory.pop();
    action->Undo();
    _canceledActions.push(action);

}

void VectorEditorController::redo() {
    if (_canceledActions.empty())
        return;
    auto action = _canceledActions.top();
    _canceledActions.pop();
    action->Execute();
    _actionHistory.push(action);
}
