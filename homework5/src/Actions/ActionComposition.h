//
// Created by Lina1 on 26.02.2024.
//
#pragma once
#include <memory>
#include <vector>
#include <algorithm>

#include "IUserAction.h"

class ActionComposition : public IUserAction
{
    std::vector<IUserAction> actions;
public:
    ActionComposition() {};

    void addAction(IUserAction&& action)
    {
        actions.push_back(action);
    }

    void Execute() override
    {
        for( auto action: actions)
        {
            action.Execute();
        }
    };

    void Undo() override
    {
        for(auto actionIterator = actions.rbegin(); actionIterator < actions.rend(); actionIterator++)
        {
            actionIterator->Undo();
        }
    };

};


