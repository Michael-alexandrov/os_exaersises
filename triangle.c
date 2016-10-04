#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main() {
	int X1, X2, X3, Xdot, Y1, Y2, Y3, Ydot, tg12, tg23, tg31, res=1, minX, minY, maxX, maxY;
	scanf_s("%d%d%d%d%d%d%d%d", &X1, &Y1, &X2, &Y2, &X3, &Y3, &Xdot, &Ydot); 
	
	minX = X1;
	if (X2 < minX) minX=X2;
	if (X3 < minX) minX=X3;
	minY = Y1;
	if (Y2 < minY) minY=Y2;
	if (Y3 < minY) minY=Y3;
	maxX = X1;
	if (X2 > maxX) minX=X2;
	if (X3 > maxX) minX=X3;
	maxY = Y1;
	if (Y2 > maxY) minY=X2;
	if (Y3 > maxY) minY=X3;
	if ((Xdot < minX)&&(Xdot > maxX)&&(Ydot < minY)&&(Ydot > maxY)){      
		res = 0;                                                      //For very large derivatives overflow. Here we avoid it.
		exit(0);
	}

	if (X2 == X1) {                                                       //consider vertical side of the triangle
		if(((Xdot <= X1)&&(X3 > X1))||((Xdot >= X1)&&(X3 < X1))){
			res = 0;
		}
	}
	else {
		if (X1 > X2){
			tg12 = (Y2 - Y1) / (X2 - X1);
			if ((((X1 + tg12 * (X3 - X1)) > Y3)&&((X1 + tg12 * (Xdot - X1)) <= Ydot))||(((X1 + tg12 * (X3 - X1)) < Y3)&&((X1 + tg12 * (Xdot - X1)) >= Ydot))){
				res = 0;
			}
		}
		else {
			tg12 = (Y1 - Y2) / (X1 - X2);
			if (((X2 + tg12 * (X3 - X2) > Y3)&&(X2 + tg12 * (Xdot - X2) <= Ydot)) || ((X2 + tg12 * (X3 - X2) < Y3)&&(X2 + tg12 * (Xdot - X2) >= Ydot))){
				res = 0;
			}
		}
	}


	if (X2 == X3) {                                                       //consider vertical side of the triangle
		if(((Xdot <= X3)&&(X1 > X3))||((Xdot >= X3)&&(X1 < X3))){
			res = 0;
		}
	}
	else {
		if (X2 > X3){
			tg23 = (Y3 - Y2) / (X3 - X2);
			if (((X2 + tg23 * (X1 - X2) > Y1)&&(X2 + tg23 * (Xdot - X2) <= Ydot)) || ((X2 + tg23 * (X1 - X2) < Y1)&&(X2 + tg23 * (Xdot - X2) >= Ydot))){
				res = 0;
			}
		}
		else {
			tg23 = (Y2 - Y3) / (X2 - X3);
			if (((X3 + tg23 * (X1 - X3) > Y1)&&(X3 + tg23 * (Xdot - X3) <= Ydot)) || ((X3 + tg23 * (X1 - X3) < Y1)&&(X3 + tg23 * (Xdot - X3) >= Ydot))){
				res = 0;
			}
		}
	}

	if (X3 == X1) {                                                      //consider vertical side of the triangle
		if(((Xdot <= X1)&&(X2 > X1))||((Xdot >= X1)&&(X2 < X1))){
			res = 0;
		}
	}
	else {
		if (X3 > X1){
			tg31 = (Y3 - Y1) / (X3 - X1);
			if (((X1 + tg31 * (X2 - X1) > Y2)&&(X1 + tg31 * (Xdot - X1) <= Ydot)) || ((X1 + tg31 * (X2 - X1) < Y2)&&(X1 + tg31 * (Xdot - X1) >= Ydot))){
				res = 0;
			}
		}
		else {
			tg31 =(Y1 - Y3) /(X1 - X3);
			if (((X3 + tg31 * (X2 - X3) > Y2)&&(X3 + tg31 * (Xdot - X3) <= Ydot)) || ((X3 + tg31 * (X2 - X3) < Y2)&&(X3 + tg31 * (Xdot - X3) >= Ydot))){
				res = 0;
			}
		}
	}

	if(res == 0) printf("No");
	else printf("yes");
	return 0; 
}
