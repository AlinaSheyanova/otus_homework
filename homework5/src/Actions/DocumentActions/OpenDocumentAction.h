#pragma once
#include <memory>
#include <string_view>
#include <utility>

#include "IUserAction.h"
#include "VectorEditorModel.h"

/**
 * @class OpenDocumentAction
 * @brief Represents an action to open a document in the vector editor.
 *
 * This action sets the active document in the vector editor model based on the specified file path.
 * If the file path is not empty, a new VectorDocument is created with the file path and set as the active document.
 * If the file path is empty, the active document is set to nullptr, indicating no active document.
 *
 * @see IUserAction
 * @see VectorEditorModel
 */
class OpenDocumentAction : public IUserAction
{
    std::shared_ptr<VectorEditorModel> _model;
    std::string _newFilePath;
public:

    OpenDocumentAction(std::shared_ptr<VectorEditorModel> model, std::string_view filePath);

    /**
     * @brief Executes the action to open a document in the vector editor.
     *
     * This function sets the active document in the vector editor model based on the specified file path.
     * If the file path is not empty, a new VectorDocument is created with the file path and set as the active document.
     * If the file path is empty, the active document is set to nullptr, indicating no active document.
     *
     * @note This function overrides the Execute() function in the IUserAction class.
     * @see IUserAction
     */
    void Execute() override;

    /**
     * @brief Undo function of the OpenDocumentAction class.
     *
     * This function sets the active document in the vector editor model to nullptr, indicating no active document.
     *
     * @note This function overrides the Undo() function in the IUserAction class.
     * @see IUserAction
     */
    void Undo() override;

};

