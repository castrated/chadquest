#include <stdio.h>
#include <string.h>
#include "object.h"
#include "misc.h"
#include "match.h"
int executeLookAround(void){
   printf("You are in %s.\n", player->location->description);
   listObjectsAtLocation(player->location);
   return(1);
}int executeLook(void){
   if(params->distance>=distUnknownObject){
      printf("I don't understand what you want to see.\n");
   }else if(params->distance==distNotHere){
      printf("You don't see any %s here.\n", params->tag);}else if(params->distance==distOverthere){
      printf("Too far away, move closer please.\n");
   }else if(params->distance==distHereContained){
      printf("Hard to see, try to get it first.\n");
   }else{
      printf("%s", params->obj->details);
      listObjectsAtLocation(params->obj);
   }return(1);
}static void movePlayer(OBJECT *passage){
   printf("%s",passage->textGo);
   if(passage->destination!=NULL){
      player->location=passage->destination;
      printf("\n");
      executeLookAround();
   }}int executeGo(void){
   if(params->distance>=distUnknownObject){
      printf("I don't understand where you want to go.\n");
   }else if(params->distance==distLocation){
      printf("You are already there.\n");
   }else if(params->distance==distOverthere){
      movePlayer(getPassageTo(params->obj));
   }else if(params->distance==distHere){
      movePlayer(params->obj);
   }else if(params->distance<distNotHere){
      printf("You can't get any closer than this.\n");
   }else{
      printf("You don't see any %s here.\n",params->tag);
   }return(1);}
