#pragma once

#include "IUserAction.h"
#include "VectorEditorModel.h"

/**
 * @class DeletePrimitiveAction
 * @brief Represents an action to delete a primitive from a vector editor model.
 *
 * This class inherits from IUserAction and implements the Execute and Undo methods.
 * It takes a shared_ptr to a VectorEditorModel as a parameter in the constructor and stores it.
 * The deleted primitive is stored in a shared_ptr to IGraphElement and the index of the primitive is stored as an integer.
 *
 * Usage:
 * 1. Create an instance of VectorEditorModel and pass it to the constructor of DeletePrimitiveAction.
 * 2. Call the Execute method to delete the primitive.
 * 3. To undo the deletion, call the Undo method.
 */
class DeletePrimitiveAction : public IUserAction
{
    std::shared_ptr<VectorEditorModel> _model;
    std::shared_ptr<IGraphElement> _deletedElement;
    int _primitiveIndex = -1;
public:

    /**
     * @brief Constructor for DeletePrimitiveAction.
     *
     * @param model The vector editor model to associate with this action.
     */
    explicit DeletePrimitiveAction(std::shared_ptr<VectorEditorModel> model);;

    /**
     * @brief Executes the deletion of a primitive from a vector editor model.
     *
     * This method is part of the DeletePrimitiveAction class and is an override of the Execute method inherited from the IUserAction interface.
     * It retrieves the active document from the vector editor model, removes the primitive at the specified index, and stores the deleted primitive in _deletedElement.
     */
    void Execute() override;;

    /**
     * @brief Undoes the deletion of a primitive in a vector editor model.
     *
     * This method is part of the DeletePrimitiveAction class and is an override of the Undo method inherited from the IUserAction interface.
     * It retrieves the active document from the vector editor model and adds the deleted primitive stored in _deletedElement back to the model at the original position.
     *
     * @note The Undo method assumes that the deleted primitive was previously stored in _deletedElement and the original index of the primitive was stored in _primitiveIndex.
     */
    void Undo() override;;

};
