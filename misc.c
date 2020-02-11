#include <stdio.h>
#include <string.h>
#include "object.h"
#include "misc.h"
OBJECT *getPassageTo(OBJECT *targetLocation){
   OBJECT *obj;
   forEachObject(obj){
      if(obj->location==player->location&&obj->prospect==targetLocation){
         return(obj);
      }}return(NULL);
}DISTANCE distanceTo(OBJECT *obj){
   return
      !validObject(obj)                           ? distUnknownObject :
      obj==player                               ? distPlayer :
      obj==player->location                     ? distLocation :
      obj->location==player                     ? distHeld :
      obj->location==player->location           ? distHere :
      getPassageTo(obj)!=NULL                   ? distOverthere :
      !validObject(obj->location)                 ? distNotHere :
      obj->location->location==player           ? distHeldContained :
      obj->location->location==player->location ? distHereContained :
                                                    distNotHere;
}static int nounIsInTags(const char *noun,const char **tags){
   while(*tags!=NULL){
      if(strcmp(noun,*tags++)==0)return(1);
   }return(0);
}OBJECT *parseObject(const char *noun){
   OBJECT *obj,*found=NULL;
   forEachObject(obj){
      if(noun!=NULL&&nounIsInTags(noun,obj->tags)&&distanceTo(obj)<distanceTo(found)){
         found=obj;
      }}return(found);
}OBJECT *personHere(void){
   OBJECT *obj;
   forEachObject(obj){
      if(distanceTo(obj)==distHere&&obj->health>0){
         return(obj);
      }}return(NULL);
}int listObjectsAtLocation(OBJECT *location){
   int count=(0);
   OBJECT *obj;
   forEachObject(obj){
      if(obj!=player&&obj->location==location){
         if(count++==0){
            printf("%s:\n", location->contents);
         }printf("%s\n", obj->description);}}return(count);
}int weightOfContents(OBJECT *container){
   int sum=(0);
   OBJECT *obj;
   forEachObject(obj){
      if(obj->location==container)sum+=obj->weight;
   }return(sum);}
