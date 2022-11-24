
#include "View/MovingStateAlive.h"


MovingStateAlive::MovingStateAlive()
{

}

MovingStateAlive::~MovingStateAlive()
{
    //dtor
}

 vector<float> MovingStateAlive::getLeftMouvement(){

    vector<float> v;

     v.push_back(-50);
     v.push_back(0);

     return v;

 }

 vector<float> MovingStateAlive::getRightMouvement()
 {

     vector<float> v;

     v.push_back(50);
     v.push_back(0);

     return v;
}

 vector<float> MovingStateAlive::getUptMouvement()
 {

     vector<float> v;

     v.push_back(0);
     v.push_back(-50);

     return v;
}

 vector<float> MovingStateAlive::getDownMouvement()
 {

     vector<float> v;

     v.push_back(0);
     v.push_back(50);

     return v;
}
