#include <stdio.h>
#include <math.h>
int main(){
	double n , p;
	while(scanf("%lf\n%lf" , &n , &p) != EOF){
		printf("%0.lf\n" , (double)pow(p , 1.0/n));
	}
	return 0;
}
