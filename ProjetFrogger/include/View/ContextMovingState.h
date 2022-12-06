#ifndef ContextMovingState_H
#define ContextMovingState_H
#include <MovingState.h>
#include <MovingStateAlive.h>
#include <MovingStateDead.h>
#include <MovingStateWin.h>
#include <vector>

using namespace std;

class ContextMovingState
{
    private:
        MovingState* currentState = nullptr;

    public:
        ContextMovingState():currentState(){setState();};
        virtual ~ContextMovingState();

        void setState(){
            this->currentState = new MovingStateAlive;

        }

        void setDeadState()
        {
            delete currentState;
            this->currentState = new MovingStateDead;
        }

         void setWinState()
        {
            delete currentState;
            this->currentState = new MovingStateWin;
        }

        MovingState* getState()
        {
            return currentState;
        };


};

#endif // ContextMovingState
