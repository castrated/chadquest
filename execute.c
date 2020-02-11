#include <stdio.h>
#include "object.h"
#include "misc.h"
#include "match.h"
static int objectWithinReach(const char *verb, PARAM *par){
   int ok=(0);if(par->distance>distNotHere){
      printf("I don't understand what you want to %s.\n", verb);}else if(par->distance==distNotHere){
      printf("You don't see any %s here.\n",par->tag);}else if(par->distance>=distHereContained){
      printf("That is out of reach.\n");}else if(par->count>(1)){
      printf("Multiple choices to %s; be more specific.\n",verb);}else{
      ok=(1);}return(ok);
}int executeOpen(void){
   if(objectWithinReach("open",params)){
      printf("%s",(*params->obj->open)(params->obj));}return(1);
}int executeClose(void){
   if(objectWithinReach("close",params)){
      printf("%s",(*params->obj->close)(params->obj));}return(1);
}int executeLock(void){if(objectWithinReach("lock",params)){
      printf("%s",(*params->obj->lock)(params->obj));}return(1);
}int executeUnlock(void){
   if(objectWithinReach("unlock",params)){
      printf("%s",(*params->obj->unlock)(params->obj));}return(1);}
