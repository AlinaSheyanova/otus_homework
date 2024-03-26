#pragma once

#include "VectorDocument.h"

/**
 * @class VectorEditorModel
 * @brief Represents a vector editor model.
 *
 * The VectorEditorModel class represents a vector editor model that manages the active document and view.
 * It provides functionality to set and get the active document.
 */

class VectorEditorView;

class VectorEditorModel {

    std::shared_ptr<VectorEditorView> _view;
    std::shared_ptr<VectorDocument> _document;
public:
    /**
     * @brief Sets the active document.
     *
     * This function sets the active document to the specified document.
     * The active document is the document currently being edited or viewed.
     * The function takes a shared pointer to a VectorDocument as a parameter.
     *
     * @param document The shared pointer to the document to set as active.
     */
    void setActiveDocument(std::shared_ptr<VectorDocument> document)
    {
        _document = document;
    }

    /**
     * @brief Get the active document.
     *
     * This function returns a shared pointer to the active document.
     *
     * @return std::shared_ptr<VectorDocument> The active document.
     */
    std::shared_ptr<VectorDocument> getActiveDocument()
    {
        return _document;
    }

    friend class VectorEditorView;

};

