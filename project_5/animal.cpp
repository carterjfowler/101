/*
	animal.cpp

	author: Carter Fowler
	date: 05/02/2018

	Animal/20 questions program for CSCI 262, Spring 2018. 
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <queue>

using namespace std;

class node {
public:
    string data;
    node* left;
    node* right;
};

node* read_game_tree();
void read_preorder(node* tree, ifstream &fin);
void play_game(node* R, queue<string> &progress);
void extend_game_tree(node* R, queue<string> history);
void save_game_tree(node* R);
void write_preorder(node* root, ofstream &output);
void delete_game_tree(node* R);

int main() {
	node* root = read_game_tree();
	if (root == NULL) return -1;
	
	queue<string> history;    //to keep track of players answers

	while (true) {
		string tmp;
		int choice;
		
		cout << "Welcome to 20 questions!" << endl;
		cout << "  1) Play the game" << endl;
		cout << "  2) Save the game file" << endl;
		cout << "  3) Quit" << endl;
		cout << "Please make your selection: ";
		getline(cin, tmp);
		choice = stoi(tmp);

		switch (choice) {
		case 1:
			play_game(root, history);
			break;
		case 2:
			save_game_tree(root);
			break;
		case 3:
			break;
		default:
			cout << "Sorry, I don't understand." << endl << endl;
		}
		if (choice == 3) break;
	}
	
	delete_game_tree(root);
	return 0;
}

node* read_game_tree() {
	ifstream input("animal.txt");
	if (!input) {     //check for file read in error
        cerr << "Could not open 'animal.txt' for reading, exiting." << endl;
        return NULL;     //would end game if returned
    }
	node* root = new node;
	read_preorder(root, input);     //fill new tree
	input.close();
	return root;
}

void read_preorder(node* tree, ifstream &fin) {
	string type = "";      //#Q or #A
	fin >> type;
	string info = "";      //Question
	getline(fin, info);
	tree->data = info;
	
	if(type == "#A") {       //base case
		tree->left = NULL;
		tree->right = NULL;
		return;
	} else {
		node* left_child = new node;     //create then assign children cause its not a leaf
		node* right_child = new node;
		tree->left = left_child;
		tree->right = right_child;
		read_preorder(left_child, fin);     //recursion
		read_preorder(right_child, fin);
	}
}

void play_game(node* R, queue<string> &progress) {
	node* current_node = R;
	string answer = "";       //user input
	string result = "";       //used to fill queue of answers
	
	cout << current_node->data << " (y/n): ";
	getline(cin, answer);
	
	if(answer == "y" && current_node->left != NULL && current_node->right != NULL) {     //be sure to check that its not a leaf, so recursion
		result = current_node->data;
		result += " YES";
		current_node = current_node->left;
		progress.push(result);
		play_game(current_node, progress);
	} else if(answer == "n" && current_node->left != NULL && current_node->right != NULL) {
		result = current_node->data;
		result += " NO";
		current_node = current_node->right;
		progress.push(result);
		play_game(current_node, progress);
	} else if(answer == "y" && current_node->left == NULL && current_node->right == NULL) {     //is a leaf so end of the line (Base Case 1/2)
		result = current_node->data;
		result += " YES";
		progress.push(result);
		cout << "YAY! I guessed your animal!!" << endl;
	} else if(answer == "n" && current_node->left == NULL && current_node->right == NULL){
		result = current_node->data;
		result += " NO";
		progress.push(result);
		cout << "BOO! I don't know." << endl;
		
		cout << "\n\nWould you like to expand the game tree (y/n)? ";
		string response = "";
		getline(cin, response);
		if(response == "y") extend_game_tree(current_node, progress);
		else return;
	}
}

void extend_game_tree(node* R, queue<string> history) {    //get user input to expand the tree to better the game!!
	cout << "I asked the following: " << endl;
	while(!history.empty()) {
		cout << history.front() << endl;
		history.pop();
	}
	cout << "Enter a new animal in the form of a question, e.g., 'Is it a whale?': " << endl;
	string new_animal = "";
	getline(cin, new_animal);
	
	cout << "Now enter a question for which the answer is 'yes' for your new animal, and which does not contradict your previous answers: " << endl;
	string new_question = "";
	getline(cin, new_question);
	string old_animal = R->data;
	
	node* new_left = new node;     //creating the new leaves for the given question
	node* new_right = new node;
	new_left->data = new_animal;
	new_right->data = old_animal;
	new_left->left = NULL;
	new_left->right = NULL;
	new_right->left = NULL;
	new_right->right = NULL;
	
	R->data = new_question;      //creating the new question
	R->left = new_left;
	R->right = new_right;
}

void save_game_tree(node* R) {
	ofstream output("animal.txt");
	
	write_preorder(R, output);
	
	output.close();
}

void write_preorder(node* root, ofstream &output) {    //writes the binary tree to file using a pre-order traversal
	if(root->left == NULL && root->right == NULL) {
		output << "#A " << root->data << endl;
		return;
	} else {
		output << "#Q " << root->data << endl;
		write_preorder(root->left, output);
		write_preorder(root->right, output);
	}
}

void delete_game_tree(node* R) {        			//deletes tree using a post-order traversal
	if(R->left == NULL && R->right == NULL) {
		delete R;
	} else {
		delete_game_tree(R->left);
		delete_game_tree(R->right);
		delete R;
	}
}