#include <iostream>
using namespace std;

// using classes to simplify and organize the course.
class Arthmatic {
	
	private:
		float res;
	public:
		Arthmatic() {}
		
		void add(float x, float y){
			res = x + y;
			display(x, y, "sum");
		}
		void sub(float x, float y){
			res = x - y;
			display(x, y, "difference");
		}
		void mul(float x, float y){
			res = x * y;
			display(x, y, "product");
		}
		void div(float x, float y){
			if (y == 0)
				cout << "Cannot Divide By 0";
			res = x / y;
			display(x, y, "quotient");
		}
		void display(float x, float y, string operation){
			cout << "The " << operation << " of " << x << " and " << y << " is:\t" << this->res << endl;
		}
};

int main(){
	
	Arthmatic math;	// class object
	
	int ops, end_condition;
	float num1, num2;
	
	do {
		cout << "### Welcome to Console Calculator ###\n";
		cout << "\nEnter a number:\t\t";
		cin >> num1;
		cout << "Enter another number:\t";
		cin >> num2;
		
		cout << "\nSelect an operation:\n";
		cout << "1: Addition\n";
		cout << "2: Subtraction\n";
		cout << "3: Multiplication\n";
		cout << "4: Division\n";
		cout << "0: Exit\n";
		
		cout << "Enter an option:\t";
		cin >> ops;
		
		// call class functions based on the operation
		if (ops == 1)
			math.add(num1, num2);
		else if (ops == 2)
			math.sub(num1, num2);
		else if (ops == 3)
			math.mul(num1, num2);
		else if (ops == 4)
			math.div(num1, num2);
		else
			exit(0);
			
		cout << "\nDo you want to do another operation (1: Yes, 2: No) :\t";
		cin >> end_condition;
		
		system("cls");	// clear console screen
		
	} while(end_condition != 2);
	
	return 0;
}