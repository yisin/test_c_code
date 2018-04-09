
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *transletSign(char *source, char *ss){

   static char buffer[1024]={0};
   char* sign="\\;";
   char* psource;
   char* pfind;
   int relen;
   int searlen;
   int reslen;
   int offset=0;
 
   searlen=strlen(ss);
   relen=strlen(sign);
   reslen=strlen(source)+1;
 
  
   strncpy(buffer, source, sizeof(buffer)-1);
 
   psource=source;
   pfind= strstr(psource, ss);
 
   while(pfind!=NULL){
 
       offset+=(pfind - psource);
       buffer[offset]='\0';
 
       reslen+=(relen-searlen);
     
       strncat(buffer, sign, strlen(sign));
       offset+=relen;
 
       psource=pfind+searlen;
       strncat(buffer, psource, strlen(psource));
 
       pfind= strstr(psource, ss);
   }
 
   buffer[strlen(buffer)]='\0';
 
   printf( "source: '%s'\n", source );
   printf( "result: '%s'\n", buffer);
   return buffer;

}
 
int main(){
   
  printf("translet result = %s\n",transletSign("abcd;efghij;klk", ";"));
  printf("translet result 2 = %s\n",transletSign("abcdefghijklk", ";"));

   return 0;
}