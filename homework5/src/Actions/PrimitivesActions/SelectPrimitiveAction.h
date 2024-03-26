#pragma once

#include "IUserAction.h"
#include "VectorEditorModel.h"

/**
 * @class SelectPrimitiveAction
 *
 * @brief Represents an action to select a primitive in a vector editor.
 *
 * This class inherits from IUserAction and implements the Execute() and Undo() methods to perform
 * the action and revert it, respectively. It takes a shared pointer to a VectorEditorModel and a
 * Point as arguments in its constructor. The Execute() method updates the selected element index in
 * the active document to the new index obtained from the point. The Undo() method reverts the selected
 * element index to the old index stored when the action was executed.
 */
class SelectPrimitiveAction : public IUserAction
{
    std::shared_ptr<VectorEditorModel> _model;
    Point _point;
    int _oldIndex = -1;
    int _newIndex = -1;
public:

    SelectPrimitiveAction(std::shared_ptr<VectorEditorModel> model, Point point);;

    /**
     * @brief Executes the action to select a primitive in the vector editor.
     *
     * This method sets the selected element index in the active document to the new index stored in the _newIndex variable.
     */
    void Execute() override;;

    /**
     * @brief Reverts the selected element index in the active document to the old index.
     *
     * This method is called to undo the action of selecting a primitive in the vector editor. It sets the selected element index in the active document to the old index stored when the
    * action was executed.
     */
    void Undo() override;;

};

