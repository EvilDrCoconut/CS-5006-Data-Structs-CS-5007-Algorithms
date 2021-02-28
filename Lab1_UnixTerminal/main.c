// Add your program here!
//
#include <stdio.h>

int base = 2;
int n = 10;

 double power (double base; double n;) {
        int i = 0;
        int start = base;
        for (i = 0; i < n; i++) {
                start = start * base;
                printf("%d ", start);
        }
        }

int main() {
	power(base,n);
	return 0;
}
