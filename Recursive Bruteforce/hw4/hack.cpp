
#include "hack.h"

// This function is the main function that is called in the Main.cpp
void hack(EvilComputer* ec) {
	Hack_guestComputer(ec, "");
	Hack_daveComputer(ec, "");
	Hack_mr_meanComputer(ec, "");
	Hack_ms_chiefComputer(ec, "");
	Hack_dr_evilComputer(ec, "");
}

// Recursion functions here to hack each user

void Hack_guestComputer(EvilComputer* ec, string partial) { //known password of passw123
	ec->guess("Guest", "passw123");
}

void Hack_daveComputer(EvilComputer* ec, string partial) { //4 digits 
	if (partial.length() == 4)
		ec->guess("Dave", partial);
	else {
		for(char c1 = '0'; c1 <= '9'; c1++)
		Hack_daveComputer(ec, partial + c1);
	}
}

void Hack_mr_meanComputer(EvilComputer* ec, string partial) { //combination of g and r
	if (partial.length() <= 8) {
		ec->guess("Mr. Mean", partial);
		Hack_mr_meanComputer(ec, partial + "g");
		Hack_mr_meanComputer(ec, partial + "r");
	}
}

void Hack_ms_chiefComputer(EvilComputer* ec, string partial) { //starts with haha
	if(partial.length() <= 4) {
		ec->guess("Ms. Chief", "haha" + partial);
		for (char c1 = '0'; c1 <= '9'; c1++)
			Hack_ms_chiefComputer(ec, partial + c1);
		for (char c1 = 'a'; c1 <= 'z'; c1++)
			Hack_ms_chiefComputer(ec, partial + c1);
	}
}

void Hack_dr_evilComputer(EvilComputer* ec, string partial) { //starts or ends with gato
	if (partial.length() <= 4) {
		ec->guess("Dr. Evil", "gato" + partial);
		ec->guess("Dr. Evil", partial + "gato");

		for (char c1 = '0'; c1 <= '9'; c1++)
			Hack_dr_evilComputer(ec, partial + c1);
		for (char c1 = 'a'; c1 <= 'z'; c1++)
			Hack_dr_evilComputer(ec, partial + c1);
	}
}
