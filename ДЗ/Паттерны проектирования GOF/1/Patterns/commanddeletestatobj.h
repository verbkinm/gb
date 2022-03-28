#pragma once

#include <vector>

#include "command.h"
#include "GameObject.h"

class CommandDeleteStatObj : public Command
{
public:
    CommandDeleteStatObj(GameObject *obj, std::vector<GameObject*> &vec);

    // Command interface
    void Execute() override;

private:
    std::vector<GameObject*> &_vecStaticObj;
    GameObject *_obj;
};
