#include "commands/Auto.h"

Auto::Auto(DriveTrain* driveTrain) {
  //bad and allocating a bunch of stack objects. will discuss how to fix this temp code (that allows you go to multiple points) in class
  if(constant::LIST_OF_TURNS.size() == constant::LIST_OF_FORWARDS.size()){
    for(unsigned int x1 = 0; x1 < constant::LIST_OF_FORWARDS.size(); ++x1){
      AddCommands(
        //add auto commands here
        TurnToPoint(driveTrain, constant::LIST_OF_FORWARDS[x1].first, constant::LIST_OF_FORWARDS[x1].second),
        DriveToPoint(driveTrain, constant::LIST_OF_TURNS[x1].first, constant::LIST_OF_TURNS[x1].second)
      );
    }
  }
}
