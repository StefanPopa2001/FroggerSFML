
#include "View/MovingStateDead.h"


MovingStateDead::MovingStateDead()
{

}

MovingStateDead::~MovingStateDead()
{
    //dtor
}
//se deplace plus car mort
vector<float> MovingStateDead::getLeftMouvement(){

    vector<float> v;

     v.push_back(0);
     v.push_back(0);

     return v;

 }

 vector<float> MovingStateDead::getRightMouvement()
 {

     vector<float> v;

     v.push_back(0);
     v.push_back(0);

     return v;
}

 vector<float> MovingStateDead::getUptMouvement()
 {

     vector<float> v;

     v.push_back(0);
     v.push_back(0);

     return v;
}

 vector<float> MovingStateDead::getDownMouvement()
 {

     vector<float> v;

     v.push_back(0);
     v.push_back(0);

     return v;
}

