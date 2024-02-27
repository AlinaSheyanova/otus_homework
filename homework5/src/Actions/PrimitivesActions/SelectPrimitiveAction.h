//
// Created by Lina1 on 26.03.2024.
//

#ifndef HELLOWORLD_SELECTPRIMITIVEACTION_H
#define HELLOWORLD_SELECTPRIMITIVEACTION_H


#include "../IUserAction.h"
#include "../../Models/VectorEditorModel.h"

class SelectPrimitiveAction : public IUserAction
{
    std::shared_ptr<VectorEditorModel> _model;
    Point _point;
    int _oldIndex = -1;
    int _newIndex = -1;
public:
    SelectPrimitiveAction(std::shared_ptr<VectorEditorModel> model, Point point) :
            _model(model), _point(point)
    {
        _oldIndex = _model->getActiveDocument()->getSelectedElementIndex();
        _newIndex = _model->getActiveDocument()->getElementIndexIn(_point);
    };

    void Execute() override
    {
        _model->getActiveDocument()->setSelected(_newIndex);
    };

    void Undo() override
    {
        _model->getActiveDocument()->setSelected(_oldIndex);
    };

};

#endif //HELLOWORLD_SELECTPRIMITIVEACTION_H
