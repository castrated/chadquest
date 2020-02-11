#include <stdio.h>
#include "object.h"
#include "misc.h"
#include "match.h"
static int moveObject(PARAM *par,OBJECT *from,OBJECT *to){
   OBJECT *obj=par->obj;if(obj==NULL){
      printf("I don't understand what item you mean.\n");
   }else if(from!=obj->location){
      switch (par->distance){
      case distPlayer:
         printf("You should not be doing that to yourself.\n");
         break;case distHeld:
         printf("You already have %s.\n", obj->description);
         break;case distLocation:
      case distOverthere:
         printf("That's not an item.\n");
         break;case distHere:
         if(from==player){
            printf("You have no %s.\n",par->tag);
         }else{
            printf("Sorry, %s has no %s.\n",from->description,par->tag);
         }break;case distHeldContained:
      case distHereContained:
         printf("Sorry, %s is holding it.\n",obj->location->description);
         break;default:
         printf("You don't see any %s here.\n",par->tag);
      }}else if(to==NULL){
      printf("There is nobody here to give that to.\n");
   }else if(obj->weight>to->capacity){
      printf("That is way too heavy.\n");
   }else if(obj->weight+weightOfContents(to)>to->capacity){
      printf("That would become too heavy.\n");
   }else{
      obj->location=to;
      printf("Ok.\n");
   }return(1);
}int executeGet(void){
   return moveObject(params,player->location,player);
}int executeDrop(void){
   return moveObject(params,player,player->location);
}int executeGive(void){
   return moveObject(params,player,personHere());
}int executeAsk(void){
   return moveObject(params,personHere(),player);
}int executeGetFrom(void){
   return moveObject(params,params[1].obj,player);
}int executePutIn(void){
   return moveObject(params,player,player[1].obj);
}int executeInventory(void){
   if (listObjectsAtLocation(player)==(0)){
      printf("You are empty-handed.\n");
   }return(1);}
