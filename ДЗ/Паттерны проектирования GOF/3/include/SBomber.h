#pragma once

#include <vector>
#include <iostream>

#include "LevelGUI.h"
#include "Plane.h"
#include "Bomb.h"
#include "Ground.h"
#include "Tank.h"

class SBomber
{
public:

    SBomber();
    ~SBomber();
    
    inline bool GetExitFlag() const { return exitFlag; }

    void ProcessKBHit(int amountInputtedCodes);
    void TimeStart();
    void TimeFinish();

    void DrawFrame();
    void MoveObjects();
    void CheckObjects();

private:

    void CheckPlaneAndLevelGUI();
    void CheckBombsAndGround();
    void  CheckDestoyableObjects(Bomb* pBomb);

    void  DeleteDynamicObj(DynamicObject * pBomb);
    void  DeleteStaticObj(GameObject* pObj);

    Ground * FindGround() const;
    Plane * FindPlane() const;
    LevelGUI * FindLevelGUI() const;
    std::vector<DestroyableGroundObject*> FindDestoyableGroundObjects() const;
    std::vector<Bomb*> FindAllBombs() const;

    void DropBomb();

    std::vector<DynamicObject*> vecDynamicObj;
    std::vector<GameObject*> vecStaticObj;
    
    bool exitFlag;

    uint64_t startTime, finishTime, passedTime;
    uint16_t bombsNumber, deltaTime, fps;
    int16_t score;

    class BombIterator
    {
    private:
        std::vector<DynamicObject*> &_vec;;
        int _curIndex;
        DynamicObject* _ptr;

    public:
        BombIterator(std::vector<DynamicObject*> &vec) : _vec(vec), _curIndex(0), _ptr(*_vec.begin())
        { ++(*this); }

        void reset() { _ptr = *_vec.end(); }
        BombIterator & operator++() // префиксныйинкремент
        {
            _curIndex++;
            for(; static_cast<size_t>(_curIndex) < _vec.size(); _curIndex++)
            {
                Bomb* pBomb = dynamic_cast<Bomb*>(_vec[_curIndex]);
                if (pBomb != nullptr)
                {
                    _ptr = _vec[_curIndex];
                    break;
                }
            }
            if (static_cast<size_t>(_curIndex) == _vec.size())
            {
                _curIndex = -1;
                _ptr = *_vec.end();
            }
            return *this;
        }
        BombIterator& operator-- () // префексныйдекремент
        {
            if (_curIndex == -1)
                _curIndex = _vec.size() - 1;
            for (; _curIndex >= 0; _curIndex--)
            {
                Bomb* pBomb = dynamic_cast<Bomb*>(_vec[_curIndex]);
                if (pBomb != nullptr)
                {
                    _ptr = _vec[_curIndex];
                    break;
                }
            }
            if (_curIndex == -1)
            {
                _ptr = *_vec.end();
            }
            return *this;
        }
        DynamicObject *operator*() // операция разыменования итератора
        {
            return _ptr;
        }

        bool operator==(const BombIterator &it)
        {
            return _ptr == it._ptr;
        }

        bool operator!=(const BombIterator &it) // проверкана лог. неравенство
        {
            return _ptr != it._ptr;
        };
    };
    // получаем итератор настроенный на начало массива
    BombIterator begin() { BombIterator it(vecDynamicObj); return it; }
    // итератор в конечном состоянии
    BombIterator end() { BombIterator it(vecDynamicObj); it.reset(); return it; }
};

