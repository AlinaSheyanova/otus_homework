#pragma once
#include <memory>
#include <string>
#include <utility>

#include "IUserAction.h"
#include "VectorEditorModel.h"

/**
 * @class CloseDocumentAction
 * @brief Represents an action to close the active document in a vector editor model.
 * @details This class inherits from the IUserAction interface and provides implementation for the Execute and Undo methods.
 *
 * @var _model The vector editor model to perform the action on.
 * @var _currentFilePath The file path of the document being closed.
 */
class CloseDocumentAction : public IUserAction
{
    std::shared_ptr<VectorEditorModel> _model;
    std::string _currentFilePath;
public:

    CloseDocumentAction(std::shared_ptr<VectorEditorModel> model) :
            _model(model) {};

    /**
     * @brief Executes the action to close the active document in the vector editor model.
     *
     * This method gets the current active document from the model, retrieves its file path,
     * sets the active document to nullptr, and stores the file path in the _currentFilePath member variable.
     * It does not return a value.
     *
     * @note If there is no active document, the _currentFilePath member variable will remain unchanged.
     */
    void Execute() override
    {
        auto currentDocument = _model->getActiveDocument();
        if(currentDocument != nullptr) {
            _currentFilePath = currentDocument->getFilepath();
        }
        _model->setActiveDocument(nullptr);

    };

    /**
     * @brief Undo the action of closing the active document.
     *
     * This method checks if the _currentFilePath member variable is not empty. If it is not empty, it creates a new VectorDocument object with the file path stored in _currentFilePath and
    * sets it as the active document in the model.
     * This method does not return a value.
     *
     * @note If the _currentFilePath member variable is empty, no action is performed.
     */
    void Undo() override
    {
        if (!_currentFilePath.empty()) {
            _model->setActiveDocument(std::make_shared<VectorDocument>(_currentFilePath));
        }
    };

};


