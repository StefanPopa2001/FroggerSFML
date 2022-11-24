#ifndef MovingStateWin_H
#define MovingStateWin_H
#include "MovingState.h"

class MovingStateWin:public MovingState
{
    private:
    public:
        MovingStateWin();
         ~MovingStateWin();
         vector<float> getLeftMouvement();
         vector<float> getRightMouvement();
         vector<float> getUptMouvement();
         vector<float> getDownMouvement();
};

#endif // MovingStateWin_h
