#include <iostream>
#include <time.h>
#include <memory>
#include <string>
#include "OrderedList.h"
#include "Bag.h"
#include "Card.h"

using namespace std;
void getAHand(unsigned int n, List<shared_ptr<Card>> &hand);
void sortUsingOL(List<shared_ptr<Card>> &hand);
template<class T>
void sortUsingOLF(List<shared_ptr<Card>> &hand);

class MyFunctorDeref {
public:
    static bool compare(const shared_ptr<Card>& a, const shared_ptr<Card>& b){
        if(a->getDenomination() != b->getDenomination()){
            if(a->getDenomination() < b->getDenomination()){
                return true;
            }
            else{
                return false;
            }
        }
        else {
            if(a->getSuit() < b->getSuit()){
                return true;
            }
            else{
                return false;
            }
        
        }
    }
};

int main(void) {
	
	srand((unsigned int)time(NULL));
	//grab some cards put em in a hand (which is a list in this case)
	List<shared_ptr<Card>> hand;
	getAHand(12, hand);
	//print out your hand
	for (auto card : hand) {
		cout << *card << endl;
	}
    cout << endl << endl;
	sortUsingOL(hand);
    cout << "Sorted Using OL:" << endl;
    for (auto card : hand) {
        cout << *card << endl;
    }
    cout << endl << endl;
    
    sortUsingOLF<IsGreaterDeref>(hand);
    cout << "Sorted Using OLF:" << endl;
    for (auto card : hand) {
        cout << *card << endl;
    }
    cout << endl << endl;
    
    sortUsingOLF<MyFunctorDeref>(hand);
    cout << "Sorted Using OLF(custom):" << endl;
    for (auto card : hand) {
        cout << *card << endl;
    }
    cout << endl << endl;
    return 0;

}

void getAHand(unsigned int n, List<shared_ptr<Card>> &hand) {
	// make a bag add all the cards to it
	Bag<shared_ptr<Card>> bag(52);
	Suit s[] = {HEARTS,DIAMONDS,SPADES,CLUBS };
	Denomination d[] = {N2,N3,N4,N5,N6,N7,N8,N9,N10,JACK,QUEEN,KING,ACE };
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			bag.add(make_shared<Card>(s[i], d[j]));
		}
	}
	//put some cards in hand
	for (unsigned int i = 0; i < n; i++) {
		hand.append(bag.getOne());
	}
}

void sortUsingOL(List<shared_ptr<Card>> &hand){
    OrderedList<shared_ptr<Card>> temp;
    for(unsigned int i=1;i<=hand.getLength();i++){
        temp.insert(hand.retrieve(i));
    }
    for(unsigned int i=1;i<=hand.getLength();i++){
        hand.replace(i,temp.retrieve(i));
    }
}

template<class T>
void sortUsingOLF(List<shared_ptr<Card>> &hand){
    OrderedList<shared_ptr<Card>, T> temp;
    for(unsigned int i=1;i<=hand.getLength();i++){
        temp.insert(hand.retrieve(i));
    }
    for(unsigned int i=1;i<=hand.getLength();i++){
        hand.replace(i,temp.retrieve(i));
    }
}