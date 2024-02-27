//
// Created by Lina1 on 26.03.2024.
//

#ifndef HELLOWORLD_CREATELINEACTION_H
#define HELLOWORLD_CREATELINEACTION_H

#include "../IUserAction.h"
#include "../../Models/VectorEditorModel.h"
#include "../../Models/GrapthPrimitives/Line.h"


template<typename PrimitiveType>
class CreatePrimitiveAction : public IUserAction
{
    std::shared_ptr<VectorEditorModel> _model;
    int _primitiveIndex = -1;
public:
    CreatePrimitiveAction(std::shared_ptr<VectorEditorModel> model) :
            _model(model) {};

    void Execute() override
    {
        _primitiveIndex = _model->getActiveDocument()->addPrimitive(std::make_shared<PrimitiveType>());
    };

    void Undo() override
    {
        _model->getActiveDocument()->removePrimitive(_primitiveIndex);
    };

};

#endif //HELLOWORLD_CREATELINEACTION_H
