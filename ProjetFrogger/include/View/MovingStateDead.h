#ifndef MovingStateDead_H
#define MovingStateDead_H
#include "MovingState.h"

class MovingStateDead:public MovingState
{
    private:
    public:
        MovingStateDead();
         ~MovingStateDead();
         vector<float> getLeftMouvement();
         vector<float> getRightMouvement();
         vector<float> getUptMouvement();
         vector<float> getDownMouvement();
};

#endif // MovingStateDead_h
