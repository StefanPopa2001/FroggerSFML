#ifndef MovingState_H
#define MovingState_H
#include <vector>

using namespace std;

class MovingState
{
    private:
    public:
        MovingState();
        virtual ~MovingState();
        virtual vector<float> getLeftMouvement() =0;
        virtual vector<float> getRightMouvement() =0;
        virtual vector<float> getUptMouvement() =0;
        virtual vector<float> getDownMouvement() =0;
};

#endif // MovingState
