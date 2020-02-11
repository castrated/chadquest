#include <stdio.h>
#include "object.h"
#include "misc.h"
static int objectWithinReach(const char *verb,OBJECT *obj,const char *noun){
   int ok=(0);
   DISTANCE distance=distanceTo(obj);if(distance>distNotHere){
      printf("I don't understand what you want to %s.\n",verb);
   }else if(distance==distNotHere){
      printf("You don't see any %s here.\n",noun);
   }else if(distance>=distHereContained){
      printf("That is out of reach.\n");
   }else{
      ok=(1);
   }return(ok);}
void executeOpen(const char *noun){
   OBJECT *obj=parseObject(noun);
   if(objectWithinReach("open",obj,noun)){
      printf("%s",(*obj->open)(obj));
   }}void executeClose(const char *noun){
   OBJECT *obj=parseObject(noun);
   if(objectWithinReach("close",obj,noun)){
      printf("%s",(*obj->close)(obj));
   }}void executeLock(const char *noun){
   OBJECT *obj=parseObject(noun);
   if(objectWithinReach("lock",obj,noun)){
      printf("%s",(*obj->lock)(obj));
   }}void executeUnlock(const char *noun){
   OBJECT *obj=parseObject(noun);
   if(objectWithinReach("unlock",obj,noun)){
      printf("%s",(*obj->unlock)(obj));
   }}
