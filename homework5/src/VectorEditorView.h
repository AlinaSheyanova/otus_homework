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

    /**
     * @class VectorEditorView
     * @brief The VectorEditorView class represents a view for a VectorDocument model.
     *
     * This class provides the necessary functionality to display and interact with the VectorDocument model.
     */
    VectorEditorView()
    {
    }

    void setModel(std::shared_ptr<VectorEditorModel> model)
    {
        _model = model;
        _model->_view = shared_from_this();
    }

};

