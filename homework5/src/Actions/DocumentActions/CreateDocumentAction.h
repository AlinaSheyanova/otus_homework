#pragma once
#include <memory>
#include <string>
#include <utility>

#include "../IUserAction.h"
#include "../../Models/VectorEditorModel.h"

/**
 * @class CreateDocumentAction
 * @brief Represents an action to create a new document in a vector editor model.
 *
 * The CreateDocumentAction class is responsible for creating a new document in a vector editor model
 * by setting an active document with a new instance of VectorDocument.
 * It also provides the ability to undo this action by setting the active document to null.
 */
class CreateDocumentAction : public IUserAction
{
    std::shared_ptr<VectorEditorModel> _model;
public:
    /**
     * @class CreateDocumentAction
     * @brief Represents an action to create a new document in a vector editor model.
     *
     * The CreateDocumentAction class is responsible for creating a new document in a vector editor model
     * by setting an active document with a new instance of VectorDocument.
     * It also provides the ability to undo this action by setting the active document to null.
     */
    CreateDocumentAction(std::shared_ptr<VectorEditorModel> model) :
            _model(model) {};

    /**
     * @class CreateDocumentAction
     * @brief Represents an action to create a new document in a vector editor model.
     *
     * The CreateDocumentAction class is responsible for creating a new document in a vector editor model
     * by setting an active document with a new instance of VectorDocument.
     * It also provides the ability to undo this action by setting the active document to null.
     */
    void Execute() override
    {
        _model->setActiveDocument(std::make_shared<VectorDocument>());
    };

    /**
     * @brief Undo the action by setting the active document to null.
     *
     * This function is responsible for undoing the action of creating a new document in the vector editor model.
     * It sets the active document to null by calling the `setActiveDocument` function of the model with a nullptr parameter.
     */
    void Undo() override
    {
        _model->setActiveDocument(nullptr);
    };

};

