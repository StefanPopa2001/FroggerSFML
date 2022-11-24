#ifndef MovingStateAlive_H
#define MovingStateAlive_H
#include "MovingState.h"

class MovingStateAlive:public MovingState
{
    private:
    public:
        MovingStateAlive();
        virtual ~MovingStateAlive();
        vector<float> getLeftMouvement();
        vector<float> getRightMouvement();
        vector<float> getUptMouvement();
        vector<float> getDownMouvement();
};

#endif // MovingStateAlive_H
