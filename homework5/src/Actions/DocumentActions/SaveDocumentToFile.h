#pragma once
#include <memory>
#include <string_view>
#include <utility>

#include "IUserAction.h"
#include "VectorEditorModel.h"

/**
 * @class SaveDocumentToFile
 * @brief A class that represents the action of saving a document to a file.
 *
 * This class inherits from IUserAction and provides the necessary functionality to execute the save action.
 * It takes a shared_ptr to a VectorEditorModel and a string_view as parameters for the constructor.
 * The execute method saves the active document of the model to the specified file path.
 * The undo method does nothing as there is no action to be undone in this case.
 */
class SaveDocumentToFile : public IUserAction
{
    std::shared_ptr<VectorEditorModel> _model;
    std::string _newFilePath;
public:

    /**
     * @brief Saves the document to a specified file path.
     *
     * This function saves the active document of the model to the specified file path.
     * If the file path is empty, no action is performed.
     *
     * @param model A shared pointer to a VectorEditorModel object representing the model.
     * @param filePath A string_view representing the file path to save the document to.
     */
    SaveDocumentToFile(std::shared_ptr<VectorEditorModel> model, std::string_view filePath);

    /**
     * @fn SaveDocumentToFile::Execute
     * @brief Executes the action to save the active document to a file.
     *
     * This method saves the active document of the model to the specified file path.
     * If the new file path is empty, no action is performed.
     *
     * @note This method overrides the Execute method from the IUserAction interface.
     */
    void Execute() override;

    /**
     * @fn SaveDocumentToFile::Undo
     * @brief Dummy implementation of the undo method.
     *
     * The Undo method does nothing as there is no action to be undone in this case.
     *
     * @note This method overrides the Undo method from the IUserAction interface.
     */
    void Undo() override;

};

