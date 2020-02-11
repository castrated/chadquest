#include "object.h"
static void swapLocations(OBJECT *obj1,OBJECT *obj2){
   OBJECT *tmp=obj1->location;
   obj1->location=obj2->location;
   obj2->location=tmp;
}const char *cannotBeOpened(OBJECT *obj){return "That cannot be opened.\n";}
const char *cannotBeClosed(OBJECT *obj){return "That cannot be closed.\n";}
const char *cannotBeLocked(OBJECT *obj){return "That cannot be locked.\n";}
const char *cannotBeUnlocked(OBJECT *obj){return "That cannot be unlocked.\n";}
const char *isAlreadyOpen(OBJECT *obj){return "That is already open.\n";}
const char *isAlreadyClosed(OBJECT *obj){return "That is already closed.\n";}
const char *isAlreadyLocked(OBJECT *obj){return "That is already locked.\n";}
const char *isAlreadyUnlocked(OBJECT *obj){return "That is already unlocked.\n";}
const char *isStillOpen(OBJECT *obj){return "That is still open.\n";}
const char *isStillLocked(OBJECT *obj){return "That is still locked.\n";}
const char *toggleBackdoor(OBJECT *obj){
   swapLocations(openDoorToBackroom,closedDoorToBackroom);
   swapLocations(openDoorToCave,closedDoorToCave);
   return "Ok.\n";
}const char *toggleBox(OBJECT *obj){
   swapLocations(openBox,closedBox);
   return "Ok.\n";
}const char *toggleBoxLock(OBJECT *obj){
   if(keyForBox->location==player){
      swapLocations(closedBox,lockedBox);
      return "Ok.\n";
   }else{
      return("You don't have a key.\n");
   }}
