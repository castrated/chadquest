#include <ctype.h>
#include <string.h>
#include "object.h"
#include "misc.h"
#include "match.h"
#define MAX_PARAMS 26
PARAM params[MAX_PARAMS];
static const char *skipSpaces(const char *src){
   while(isspace(*src))src++;
   return(src);
}static const char *matchSpaces(const char *src){return *src=='\0'||isspace(*src) ? skipSpaces(src):NULL;
}static const char *matchTerminal(const char *src, char terminal){
   return terminal==' ' ? matchSpaces(src):tolower(*src)==tolower(terminal) ? src+1:NULL;
}static const char *matchTag(const char *src,const char *tag){
   while(src!=NULL&&*tag!='\0')src=matchTerminal(src,*tag++);
   return(src);
}static int compareWithParam(const char *tag,DISTANCE distance,PARAM *par){
   int diff=strlen(tag)-strlen(par->tag);
   if(diff==0)diff=par->distance-distance;
   if(diff==0)par->count++;
   return(diff);
}static const char *matchParam(const char *src,PARAM *par,int loose){
   const char *restOfSrc=loose ? src+strlen(src):NULL;
   OBJECT *obj;
   par->tag=src;
   par->distance=*src=='\0'?distNoObjectSpecified:distUnknownObject;
   forEachObject(obj){
      DISTANCE distance=distanceTo(obj);
      const char **tag;
      for(tag=obj->tags;*tag!=NULL;tag++){
         const char *behindMatch=matchTag(src,*tag);
         if(behindMatch!=NULL&&compareWithParam(*tag,distance,par)>0&&(!loose||*skipSpaces(behindMatch)=='\0')){
            par->tag=*tag;
            par->object=obj;
            par->distance=distance;
            par->count=(1);
            restOfSrc=behindMatch;
         }}}return(restOfSrc);
}int matchCommand(const char *src, const char *pattern){
   PARAM *par;
   for(par=params;par<params+MAX_PARAMS;par++){
      par->object=(NULL);
      par->distance=distNoObjectSpecified;
      par->count=(0);
   }for(src=skipSpaces(src);src!=NULL&&*pattern!='\0';pattern++){
      src=isupper(*pattern)?matchParam(src,paramByLetter(*pattern),pattern[1]=='?'):*pattern=='?'?src:matchTerminal(src,*pattern);
   }return src!=NULL&&*skipSpaces(src)=='\0';}
