#include <iostream>
#include <time.h>
using namespace std;

int main(){
	
	srand(time(0));		// to truly randomize it using time as seed.
	
	int num = abs(rand() % 100 + 1);	// limited the random number to 1-100
	int usr_num;
	
	cout << "#### Welcome to Random Roullete ####\n";
	cout << " #### Can you guess the number ####\n\n";
	
	while (true) {
		cout << "Submit a guess :\t";
		cin >> usr_num;
		
		if (usr_num == num){
			cout << "Congratulations! You sucessfully guessed the number" << num <<"\n";
			break;	
		}
		else if (usr_num > num)
			cout << "Guess Too High\n";
		else
			cout << "Guess Too Low\n";	
	} 
	return 0;
}