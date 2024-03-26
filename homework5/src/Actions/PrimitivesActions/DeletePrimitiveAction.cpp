#include "DeletePrimitiveAction.h"

DeletePrimitiveAction::DeletePrimitiveAction(std::shared_ptr<VectorEditorModel> model) :
        _model(model)
{
    _primitiveIndex = _model->getActiveDocument()->getSelectedElementIndex();
}

void DeletePrimitiveAction::Execute() {
    _deletedElement = _model->getActiveDocument()->getPrimitive(_primitiveIndex);
    _model->getActiveDocument()->removePrimitive(_primitiveIndex);
}

void DeletePrimitiveAction::Undo() {
    _primitiveIndex = _model->getActiveDocument()->addPrimitive(_deletedElement);
}
