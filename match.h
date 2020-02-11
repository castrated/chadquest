typedef struct param {
   const char *tag;
   OBJECT *object;
   DISTANCE distance;
   int count;
}PARAM;
extern PARAM params[]
#define paramByLetter(letter)(params+(letter)-'A')
extern int matchCommand(const char *src,const char *pattern);
