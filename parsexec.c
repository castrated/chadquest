#include "object.h"
#include "misc.h"
#include "parsexec.h"
#include "location.h"
#include "inventory.h"
#include "execute.h"
typedef struct{
   int(*function)(void);
   const char *pattern;
}COMMAND;
static int executeQuit(void){
   return(0);
}static int executeNoMatch(void){
   PARAM *par=paramByLetter('A');
   if(par->distance!=distNoObjectSpecified){
      printf("I don't know how to %s.\n",par->tag);
   }return(1);
}int parseAndExecute(const char *input){
   static const COMMAND commands[]={
      {executeQuit,"quit"},
      {executeLookAround,"look"},
      {executeLookAround,"look around"},
      {executeLook,"look at A?"},
      {executeLook,"look A?"},
      {executeGo,"go to A?"},
      {executeGo,"go A?"},
      {executeGetFrom,"get A from B?"},
      {executeGet,"get A?"},
      {executePutIn,"put A in B?"},
      {executePutIn,"drop A in B?"},
      {executeDrop,"drop A?"},
      {executeGive,"give A?"},
      {executeAsk,"ask A?"},
      {executeInventory,"inventory"},
      {executeOpen,"open A?"},
      {executeClose,"close A?"},
      {executeLock,"lock A?"},
      {executeUnlock,"unlock A?"},
      {executeNoMatch,"A?"}
   };
   const COMMAND *cmd;
   for(cmd=commands;!matchCommand(input,cmd->pattern);cmd++);
   return(*cmd->function)();}
