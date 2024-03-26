#pragma once

#include <memory>

#include "Models/VectorEditorModel.h"

/**
 * @class VectorEditorView
 * @brief The VectorEditorView class represents a view for a VectorDocument model.
 *
 * This class provides the necessary functionality to display and interact with the VectorDocument model.
 */
class VectorEditorView : public std::enable_shared_from_this<VectorEditorView> {

    std::shared_ptr<VectorEditorModel> _model;

public:

    VectorEditorView() = default;

    /**
     * @brief Set the model for the VectorEditorView.
     *
     * This function sets the model for the VectorEditorView. It takes a shared pointer to a VectorEditorModel as a parameter and assigns it to the _model member variable. It also sets the
    * _view member variable of the model to a shared pointer to this VectorEditorView.
     *
     * @param model The shared pointer to the model to set.
     *
     * @see VectorEditorModel
     */
    void setModel(std::shared_ptr<VectorEditorModel> model);

};

