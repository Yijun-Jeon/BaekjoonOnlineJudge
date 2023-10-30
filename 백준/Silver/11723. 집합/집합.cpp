#include <stdio.h>
#include <cstring>

#define MAX_N 20

using namespace std;

int set = 0;

void add(int x){
	set |= (1 << x);
}

void remove(int x){
	set &= ~(1 << x);
}

bool check(int x){
	return (set >> x) & 1;
}

void toggle(int x){
	set ^= 1 << x;
}

void all(){
	set = -1;
}

void empty(){
	set = 0;
}

int main(void)
{
	int M;
	scanf("%d",&M);

	for(int i=0;i<M;i++){
		char cmd[10];
		scanf("%s",cmd);

		int x;
		if(strcmp(cmd,"all") == 0)
			all();
		else if(strcmp(cmd,"empty") == 0)
			empty();
		else{
			scanf("%d",&x);

			if(strcmp(cmd,"add") == 0)
				add(x);
			else if(strcmp(cmd,"remove") == 0)
				remove(x);
			else if(strcmp(cmd,"check") == 0)
				printf("%d\n",check(x));
			else if(strcmp(cmd,"toggle") == 0)
				toggle(x);
		}
	}
    return 0;
}