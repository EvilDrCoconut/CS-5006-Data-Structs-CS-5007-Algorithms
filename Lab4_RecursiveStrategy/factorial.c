// gcc factorial.c -o factorial
// ./factorial

#include <stdio.h>

// TODO: Implement iterative solution here
long long int factorial(int n){
	long long int total = n;
	long long int itr = n - 1;
	for(;itr > 0; itr --){
		total = total * itr;
	}
  return total;
};

// TODO: Implement recursive solution here
long long int factorial_rec(int n){
	long long int total = 1;
	while(n > 0){
	total = total * n;
	n --;
	factorial_rec(n);
	}

  return total;
}

int main(){

  printf("factorial(25) = %lld\n",factorial(25));
  printf("factorial_rec(25) = %lld\n",factorial_rec(25));


  return 0;
}
