#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cstdlib>

using namespace std;

int main(void)
{
	string exp;
	cin >> exp;

	int sum = 0;
	int tempSum = 0;
	bool minus = false;

	for(int i=0;i<exp.size();i++){
		if(isdigit(exp[i])){
			string num;
			while(isdigit(exp[i]))
				num += exp[i++];
			
			if(minus){
				tempSum += stoi(num);
			}else{
				sum += stoi(num);
			}

			if(i == exp.size() && minus)
				sum += -tempSum;

			if(i < exp.size() && exp[i] == '-'){
				if(minus){
					sum += -tempSum;
					tempSum = 0;
				}
				minus = true;
			}
		}
	}
	printf("%d\n",sum);
    return 0;
}