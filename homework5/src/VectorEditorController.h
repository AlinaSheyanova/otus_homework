//
// Created by Lina1 on 26.02.2024.
//
#pragma once

#include <string_view>
#include <stack>
#include <memory>

#include "VectorEditorModel.h"
#include "VectorEditorView.h"

#include "ActionComposition.h"
#include "OpenDocumentAction.h"
#include "CloseDocumentAction.h"
#include "SaveDocumentToFile.h"

#include "CreateDocumentAction.h"
#include "CreatePrimitiveAction.h"
#include "DeletePrimitiveAction.h"
#include "SelectPrimitiveAction.h"

#include "Line.h"
#include "Rectangle.h"

/**
 * @class VectorEditorController
 * @brief Represents a controller for a vector editor.
 *
 * The VectorEditorController class is responsible for handling user interaction with the vector editor.
 * It provides functions to open, close, save, and create documents, as well as add and delete graphics primitives.
 * It also allows users to select, undo, and redo actions performed in the editor.
 */
class VectorEditorController : public std::enable_shared_from_this<VectorEditorController>{

    std::stack<std::shared_ptr<IUserAction>> _actionHistory;
    std::stack<std::shared_ptr<IUserAction>> _canceledActions;
    std::shared_ptr<VectorEditorModel> _model;
    std::shared_ptr<VectorEditorView> _view;

public:

    VectorEditorController();

    /**
     * @brief Opens a document in the vector editor.
     *
     * This function opens a document in the vector editor based on the specified file path.
     *
     * If the active document is not empty, the function creates an action composition with two actions:
     *  - CloseDocumentAction to close the current active document
     *  - OpenDocumentAction to open the new document specified by the file path
     *
     * If the active document is empty, the function creates an OpenDocumentAction to open the new document.
     *
     * The function then executes the created action and adds it to the action history stack.
     *
     * @param filePath The file path of the document to be opened.
     *
     * @see CloseDocumentAction
     * @see OpenDocumentAction
     */
    void openDocument(std::string_view filePath);;

    /**
     * @brief Closes the active document in the vector editor.
     *
     * This function closes the active document in the vector editor.
     * If there are unsaved changes in the document, it will prompt the user to save before closing.
     *
     * The function creates a CloseDocumentAction to execute the close document operation, which sets the active document to nullptr.
     *
     * The function then adds the action to the action history stack.
     */
    void closeDocument();;

    /**
     * @fn VectorEditorController::saveDocument
     * @brief Saves the active document to a file.
     *
     * This function saves the active document in the vector editor to the specified file path.
     * It creates a SaveDocumentToFile action with the model and file path as parameters.
     * The action is then executed to save the document, and added to the action history stack.
     *
     * @param filePath The file path where the document will be saved.
     *
     * @see SaveDocumentToFile
     */
    void saveDocument(std::string_view filePath);;

    /**
     * @brief Create a new document in the vector editor.
     *
     * This function creates a new document in the vector editor by executing a CreateDocumentAction.
     * The action sets the active document with a new instance of VectorDocument.
     * After executing the action, it is added to the action history stack.
     *
     * @see CreateDocumentAction
     */
    void createDocument();;

    /**
     * @brief Adds a Line primitive to the active document.
     *
     * This function creates a CreatePrimitiveAction with the model as a parameter.
     * The action is then executed to create a Line primitive and add it to the active document.
     * Finally, the action is added to the action history stack.
     *
     * @see CreatePrimitiveAction
     */
    void addLine();

    /**
    * \brief This function is used to add a rectangle to the model.
    *
    * \details The function creates a new rectangle using the CreatePrimitiveAction class and executes it.
    * It then adds the action to the action history.
    *
    * \warning The function assumes that the _model and _actionHistory variables have been properly initialized.
    *
    * \return None.
    */
    void addRectangle();

    /**
     * @fn void deleteSelectedGraphicsPrimitive()
     * @brief Deletes the selected graphics primitive from the vector editor model.
     *
     * This function creates a DeletePrimitiveAction with the model as a parameter and executes it to delete
     * the selected graphics primitive from the active document in the model. The DeletePrimitiveAction also
     * stores the deleted primitive and its index. After executing the action, it is added to the action history stack.
     *
     * @see DeletePrimitiveAction
     */
    void deleteSelectedGraphicsPrimitive();

    /**
     * @brief Selects graphics primitives based on the given point.
     *
     * This function creates a shared pointer to a SelectPrimitiveAction object,
     * passing the model and the specified point as parameters. It then invokes the
     * Execute() method of the SelectPrimitiveAction object. Finally, the action is
     * added to the action history.
     *
     * @param point The point to be used for selecting graphics primitives.
     */
    void selectGraphicsPrimitives(Point point);

    /**
     * @brief Undo the last action performed.
     *
     * This function retrieves the last action from the action history and performs its undo operation.
     * The action is then added to the canceled actions stack.
     *
     * If the action history is empty, this function does nothing.
     *
     * @see Action::Undo()
     */
    void undo();

    /**
     * @brief Redo the last undone action.
     *
     * This function redoes the last undone action by popping it from the canceled actions stack, executing it, and pushing it back to the action history stack.
     *
     * If the canceled actions stack is empty, this function does nothing.
     *
     * @see IUserAction::Execute()
     */
    void redo();

};


