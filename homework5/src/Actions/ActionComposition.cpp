#include "ActionComposition.h"

void ActionComposition::addAction(IUserAction &&action) {
    actions.push_back(action);
}

void ActionComposition::Execute() {
    for( auto action: actions)
    {
        action.Execute();
    }
}
