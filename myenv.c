#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

extern char ** environ;

int main (){
int k;
char *user = "username"; //�������� ��� ������������, ������������ �������� whoami

for (i=0; k<1000; k++){
	if ((strstr (environ[k], user)) != NULL){
		printf ("%s\n", environ[k]);
	}
}

return 0;
}