#include <stdio.h>
int main(){
	int i, j, min, n, buf, NumOfMin;
	int a[100];

	scanf("%d", &n);
	for (i = 0; i < n; i++){
		scanf("%d,",&a[i]);
	}
	min = a[n-1];
	NumOfMin = n-1;
	for (i = 0; i < n-1; i++){
		for (j = i; j < n; j++){
			if (a[j] < min) {
				min = a[j];
				NumOfMin = j;
			}
		}
	buf = a[i];
	a[i] = min;
	a[NumOfMin] = buf;
	min = a[n-1];
	NumOfMin = n-1;
	}

	for (i = 0; i < n; i++){
		printf("%d, ",a[i]);
	}
	return(0);
}
