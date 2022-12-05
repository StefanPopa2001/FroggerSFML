
#include "View/MovingStateWin.h"


MovingStateWin::MovingStateWin()
{

}

MovingStateWin::~MovingStateWin()
{
    //dtor
}

vector<float> MovingStateWin::getLeftMouvement(){

    vector<float> v;

     v.push_back(-100);
     v.push_back(0);

     return v;

 }

 vector<float> MovingStateWin::getRightMouvement()
 {

     vector<float> v;

     v.push_back(100);
     v.push_back(0);

     return v;
}

 vector<float> MovingStateWin::getUptMouvement()
 {

     vector<float> v;

     v.push_back(0);
     v.push_back(-100);

     return v;
}

 vector<float> MovingStateWin::getDownMouvement()
 {

     vector<float> v;

     v.push_back(0);
     v.push_back(100);

     return v;
}
