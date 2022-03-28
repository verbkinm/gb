#include "commanddeletedynobj.h"

CommandDeleteDynObj::CommandDeleteDynObj(DynamicObject *obj, std::vector<DynamicObject*> &vec)
    : _vecDynamicObj(vec), _obj(obj)
{

}

void CommandDeleteDynObj::Execute()
{
    auto it = _vecDynamicObj.begin();
    for (; it != _vecDynamicObj.end(); it++)
    {
        if (*it == _obj)
        {
            _vecDynamicObj.erase(it);
            break;
        }
    }
}
