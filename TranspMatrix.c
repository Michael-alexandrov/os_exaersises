#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main() {
int a[100][100];
int k, l, i, j, buf, max;
scanf("%d %d", &k, &l);

for ( i = 0; i < 100; i ++ ) {
	for ( j = 0; j < 100; j ++ ) {
		a[i][j] = 0;
	}
}

for ( i = 0; i < l; i ++ ) {
	for ( j = 0; j < k; j ++ ) {
		scanf ("%d", & a[i][j]);
	}
}
for ( i = 0; i < l; i ++ ) {
	for ( j = 0; j < k; j ++ ){
		printf("%d ", a[i][j]);
	}
	printf("\n");
}

if (l<k) max = k;
else max = l;

for(i = 0; i < max; i++){
    for(j = i; j < max; j++){
		buf = a[j][i];
		a[j][i] = a[i][j];
		a[i][j] = buf;
	}
}

for ( i = 0; i < k; i ++ ) {
	for ( j = 0; j < l; j ++ ){
		printf ( "%d ", a[i][j] );
	}
	printf("\n");
}

return 0;
}