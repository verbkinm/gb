#include "commanddeletestatobj.h"

CommandDeleteStatObj::CommandDeleteStatObj(GameObject *obj, std::vector<GameObject*> &vec)
    : _vecStaticObj(vec), _obj(obj)
{

}

void CommandDeleteStatObj::Execute()
{
    auto it = _vecStaticObj.begin();
    for (; it != _vecStaticObj.end(); it++)
    {
        if (*it == _obj)
        {
            _vecStaticObj.erase(it);
            break;
        }
    }
}
