//
// Created by Lina1 on 26.02.2024.
//

#pragma once

class IUserAction
{
public:
    virtual void Execute();
    virtual void Undo();
    virtual ~IUserAction() {}
};




