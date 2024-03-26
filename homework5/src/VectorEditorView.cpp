#include "VectorEditorView.h"

void VectorEditorView::setModel(std::shared_ptr<VectorEditorModel> model) {
    _model = model;
    _model->_view = shared_from_this();
}
