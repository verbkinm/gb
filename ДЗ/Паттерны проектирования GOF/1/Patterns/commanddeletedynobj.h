#pragma once

#include <vector>

#include "command.h"
#include "DynamicObject.h"

class CommandDeleteDynObj : public Command
{
public:
    CommandDeleteDynObj(DynamicObject *obj, std::vector<DynamicObject*> &vec);

    // Command interface
    void Execute() override;

private:
    std::vector<DynamicObject*> &_vecDynamicObj;
    DynamicObject *_obj;
};
