#include <iostream>
#include <string>
using namespace std;

struct Node {
	string track;
	Node* next;
	Node(string tr){
		track = tr;
		next = nullptr;
	}
}; 

class MusicPlayer{
	private:
		Node* top;
		string currT;
	public:
		MusicPlayer(){
			top=nullptr;
			currT="";
		}
		
		bool isEmpty(){
			return (top == nullptr);
		}
		
		void push(string v){
			Node* node = new Node(v);
			node->next= top;
			top = node;
		}
		
		string pop(){
			if(isEmpty()){
				cout<<"Track list is Empty :"<<endl;
				return "";
			}
			
			Node* temp = top;
			string track = top->track;
			top = top->next;
			delete temp;
			return track;
		}
		
		void playTrack(string newTrack) {
        	if (currT != "") {
           	push(currT);  
        	}
        	currT = newTrack;
        	cout << "Now playing: " << currT << endl;
		}
		
		void playPrevious() {
        if (isEmpty()) {
            cout << "No previous tracks." << endl;
            return;
        }
        currT = pop();
        cout << "Now playing: " << currT << endl;
    }
};

int main() {
    MusicPlayer player;

    player.playTrack("Bohemian Rhapsody");
    player.playTrack("Stairway to Heaven");
    player.playTrack("Hotel California");

    player.playPrevious();
    player.playPrevious();
    player.playPrevious();

    return 0;
}