#include <stdio.h>
#include <stdlib.h>

int jednaki(char* s1, char* s2){
int i;
int d1,d2;
for (i=0;i<20;i++){
    if(s1[i]=='\0'){
        d1=i;
        break;
    }

}
for (i=0;i<20;i++){
    if(s2[i]=='\0'){
        d2=i;
        break;
    }

}
if(d1==d2)
for(i=0;i<d1;i++){



    if (s1[i]!=s2[i]){
        return 0;
    }
}else{
return 0;
}

return 1;
}


int main()
{
    char s1[20],s2[20];
    printf("unesite prvi string: ");
    gets(s1);
    printf("unesite drugi string: ");
    gets(s2);
    if(jednaki(s1,s2)){
        printf("uneti stringovi su jednaki");
    }else{
        printf("uneti stringovi nisu jednaki");
    }

    return 0;
}
