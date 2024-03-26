#include "SelectPrimitiveAction.h"

SelectPrimitiveAction::SelectPrimitiveAction(std::shared_ptr<VectorEditorModel> model, Point point) :
        _model(model), _point(point)
{
    _oldIndex = _model->getActiveDocument()->getSelectedElementIndex();
    _newIndex = _model->getActiveDocument()->getElementIndexIn(_point);
}

void SelectPrimitiveAction::Execute() {
    _model->getActiveDocument()->setSelected(_newIndex);
}

void SelectPrimitiveAction::Undo() {
    _model->getActiveDocument()->setSelected(_oldIndex);
}
