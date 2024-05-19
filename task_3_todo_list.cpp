#include <iostream>
#include <fstream>
using namespace std;

// Add to file
void add(){
	
	string title;

    cin.ignore();

    cout << "\nEnter the title :\t";
    getline(cin, title);

    cout << "You entered:\t\t" << title << endl;
    
    // appending at the end of text in file
	ofstream todo("todo.txt", std::ios_base::app);
	title += " [pending]\n";
	todo << title;
	
	todo.close();
}
// Read from file and display
void view(){
	
	string line;
	
	ifstream todo;
    todo.open("todo.txt");
    
	if(!todo.is_open()) {
		perror("Error to open");
		exit(0);
	}
	cout << endl;
	
	int i = 0;
    while(getline(todo, line)) {
    	i++;
		cout << "  " << i << " : "<<  line << endl;
    }
    todo.close();
    
    cout << endl;
}
// Read from file
void readFile(string str[]){
	
	string line;
	
	ifstream todo;
    todo.open("todo.txt");
    
    if(!todo.is_open()) {
		perror("Error to open");
		exit(0);
	}
	int i = 0;
    while(getline(todo, line)) {
    	if (!line.empty()){ // if line is not empty then write.
    		str[i] = line;
			i++;	
		}
    }
    todo.close();
	
}
// mark the tasks as complete.
void mark(int idx){
	
	string str[100];
	
	readFile(str);	// Read the file
    
    ofstream todo_write("todo.txt");
	for (int i = 0; i < 100; i++){
		if (i == idx){	// if index match, change the status
			string toReplace = "pending";
			size_t pos = str[i].find(toReplace);
			if (pos != string::npos) {
				str[i].replace(pos, toReplace.length(), "complete");
			}
		}
		// rewrite to file. (rewrite instead of appending)
		if (!str[i].empty())	// write only if it is not empty
			todo_write << str[i] + "\n";
	}
	todo_write.close();
}
// remove the task from file
void remove(int idx){
	
	string str[100];
	readFile(str);	// Read the file
    
    
    ofstream todo_write("todo.txt");
	for (int i = 0; i < 100; i++){
		if (i == idx){ // if index match then dont write to file.
			continue;
		}
		// rewrite to file. (rewrite instead of appending)
		if (!str[i].empty())
			todo_write << str[i] + "\n";
	}
	todo_write.close();
}

int main() {
	
	int ops;
	
	while(true){
		
		cout << "1: Add";
		cout << "\n2: View";
		cout << "\n3: Mark as Complete";
		cout << "\n4: Remove";
		cout << "\n0: Exit";
		cout << "\nChose an option:\t";
		cin >> ops;
		
		if (ops == 1){
			add();
			
			cout << "\nThe updated list: " << endl;
			view();
		}	
		else if (ops == 2){
			
			view();
		}
		else if (ops == 3){
			
			cout << "\nEnter Task to Mark Complete: \n";
			view();
			
			int idx;
			cout << "Write the index to mark complete:\t";
			cin >> idx;
			
			if (idx > 100){	// check for out of bounds value
				cout << "Index out of range: (1-100)\n";
				goto end; // jump to end (not a good practise)
			}
			
			mark(idx-1);	// since indexing starts from 0 in c++
			
			cout << "Status changed for index " << idx << endl;
			cout << "\nUpdated List is:\n";
			
			view();
		}
		else if (ops == 4){
			
			cout << "\nEnter Index to Remove Task: \n";
			view();
			
			int idx;
			cout << "Write the index to remove:\t";
			cin >> idx;
			
			if (idx > 100){ // check for out of bounds value
				cout << "Index out of range: (1-100)\n";
				goto end; // jump to end (not a good practise)
			}
			
			remove(idx-1);	// since indexing starts from 0 in c++
			
			cout << "Record Removed for index " << idx << endl;
			cout << "\nNew List is:\n";
			
			view();
		}
		else
			exit(0);
			
		end:
		cin.ignore();	// flush the buffer to remove the \n character.
		cin.get();		// wait for user to press enter
		system("cls");	// clear console screen
	}
}