#ifndef HELLOWORLD_CREATELINEACTION_H
#define HELLOWORLD_CREATELINEACTION_H

#include "IUserAction.h"
#include "VectorEditorModel.h"

/**
 * @class CreatePrimitiveAction
 * A class representing an action to create a primitive.
 *
 * This class is a concrete implementation of the IUserAction interface.
 * It provides a Execute() method to create a primitive of a given type
 * and add it to the active document of the VectorEditorModel.
 * It also provides an Undo() method to remove the created primitive from the active document.
 *
 * @tparam PrimitiveType The type of the primitive to create.
 */
template<typename PrimitiveType>
class CreatePrimitiveAction : public IUserAction
{
    std::shared_ptr<VectorEditorModel> _model;
    int _primitiveIndex = -1;
public:
    CreatePrimitiveAction(std::shared_ptr<VectorEditorModel> model) :
            _model(model) {};

    /**
     * @brief CreatePrimitiveAction::Execute
     *
     * This method creates a primitive of the specified type and adds it to the active document
     * of the VectorEditorModel.
     *
     * @tparam PrimitiveType The type of the primitive to create.
     */
    void Execute() override
    {
        _primitiveIndex = _model->getActiveDocument()->addPrimitive(std::make_shared<PrimitiveType>());
    };

    /**
     * @brief Undo the action of creating a primitive.
     *
     * This method removes the primitive at the specified index from the active document
     * of the VectorEditorModel.
     *
     * @note The primitive index must be set before calling this method.
     */
    void Undo() override
    {
        _model->getActiveDocument()->removePrimitive(_primitiveIndex);
    };

};

#endif //HELLOWORLD_CREATELINEACTION_H
