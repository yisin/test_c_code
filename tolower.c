    #include <ctype.h>
    int main(){
       // char s[] = "aBcDeFgH12345;!#$";
    	//char s[] = "a4:c3:61:22:dd:51";
    	char s[]="A4:C3:61:22:DD:51";
        int i;
        printf("before tolower() : %s\n", s);
        for(i = 0; i < sizeof(s); i++)
            s[i] = tolower(s[i]);
        printf("after tolower() : %s\n", s);
    }