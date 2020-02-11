#include <stdio.h>
#include "object.h"
static const char *tags0[]={"field",NULL};
static const char *tags1[]={"cave",NULL};
static const char *tags2[]={"silver","coin","silver coin",NULL};
static const char *tags3[]={"gold","coin","gold coin",NULL};
static const char *tags4[]={"guard","burly guard",NULL};
static const char *tags5[]={"yourself",NULL};
static const char *tags6[]={"east","entrance",NULL};
static const char *tags7[]={"west","out",NULL};
static const char *tags8[]={"west","north","south","forest",NULL};
static const char *tags9[]={"east","north","south","rock",NULL};
OBJECT objs[]={
   {"an open field","field",NULL,NULL},
   {"a little cave","cave",NULL,NULL},
   {"a silver coin","silver",field,NULL},
   {"a gold coin","gold",cave,NULL},
   {"a burly guard","guard",field,NULL},
   {"yourself","yourself",field,NULL},
   {"a cave entrance","entrance",field,cave},
   {"a way out","out",cave,field}
};
