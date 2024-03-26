#pragma once
#include <memory>
#include <vector>
#include <algorithm>

#include "IUserAction.h"

/**
 * @class ActionComposition
 * @brief Represents an action that is composed of multiple user actions
 *
 * The ActionComposition class is a concrete implementation of the IUserAction interface.
 * It allows users to compose multiple user actions into a single action and execute them sequentially.
 */
class ActionComposition : public IUserAction
{
    std::vector<IUserAction> actions;
public:

    ActionComposition() = default;

    /**
     * @brief Adds an action to the ActionComposition
     *
     * This function adds an action to the ActionComposition by moving the action object into the actions vector.
     * The added action will be executed sequentially when the Execute() function is called.
     *
     * @param action The action to be added to the ActionComposition
     */
    void addAction(IUserAction&& action);

    /**
     * @fn void ActionComposition::Execute()
     * @brief Executes the composed actions sequentially
     *
     * This function iterates over the actions vector and executes each action in sequential order.
     * The actions are executed in the order they were added to the ActionComposition.
     *
     * The Execute() function can be used to perform a set of user actions as a single action.
     * For example, if an application needs to perform a complex task that involves multiple user actions,
     * the actions can be composed using ActionComposition and then executed using the Execute() function.
     *
     * @note If an action throws an exception while executing, the remaining actions will not be executed,
     * and the exception will be propagated back to the caller.
     *
     * @see addAction()
     */
    void Execute() override;;

    /**
     * @fn void ActionComposition::Undo()
     * @brief Undo the composed actions sequentially
     *
     * This function iterates over the actions vector in reverse order and calls the `Undo()` function of each action.
     * The actions are undone in the reverse order from which they were added to the ActionComposition.
     *
     * The Undo() function can be used to revert a set of user actions by undoing each action in the reverse order they were executed.
     * For example, if an application needs to undo a complex task that involved multiple user actions,
     * the actions can be composed using ActionComposition and then undone using the Undo() function.
     *
     * This function does not throw any exceptions. If an action's `Undo()` function throws an exception,
     * it will be propagated to the caller.
     *
     * @see Execute()
     */
    void Undo() override
    {
        for(auto actionIterator = actions.rbegin(); actionIterator < actions.rend(); actionIterator++)
        {
            actionIterator->Undo();
        }
    };

};


