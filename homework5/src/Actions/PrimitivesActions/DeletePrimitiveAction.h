//
// Created by Lina1 on 26.03.2024.
//

#ifndef HELLOWORLD_DELEREPRIMITIVEACTION_H
#define HELLOWORLD_DELEREPRIMITIVEACTION_H

#include "../IUserAction.h"
#include "../../Models/VectorEditorModel.h"

class DeletePrimitiveAction : public IUserAction
{
    std::shared_ptr<VectorEditorModel> _model;
    std::shared_ptr<IGraphElement> _deletedElement;
    int _primitiveIndex = -1;
public:
    DeletePrimitiveAction(std::shared_ptr<VectorEditorModel> model) :
            _model(model)
    {
        _primitiveIndex = _model->getActiveDocument()->getSelectedElementIndex();
    };

    void Execute() override
    {
        _deletedElement = _model->getActiveDocument()->getPrimitive(_primitiveIndex);
        _model->getActiveDocument()->removePrimitive(_primitiveIndex);
    };

    void Undo() override
    {
        _primitiveIndex = _model->getActiveDocument()->addPrimitive(_deletedElement);
    };

};

#endif //HELLOWORLD_DELEREPRIMITIVEACTION_H
