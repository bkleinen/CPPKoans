/*
 * AboutControlStructures.cpp
 *
 *  Created on: 14.03.2012
 *      Author: merlin
 */
#include "stdafx.h"
#include "Assert.h"

#include "AboutControlStructures.h"

AboutControlStructures::AboutControlStructures() {

}
void aboutIfStatement() {
	int result = 0;
	if (true) {
		result = 1;
	} else {
		result = 2;
	}
	expectThat("the if statement is just as in Java", _____, result);
}
void aboutIntegersTreatedAsBoolean() {
	int a = 5;
	int b = 6;
	bool actual = false;
	if (a = b) {
		actual = true;
	}
	expectThat("integers are treated as boolean!", ________, actual);
}

void aboutWhileLoop() {
	int j = 0;
	int count = 0;
	while (j < 100) {
		count++;
		++j;
	}
	expectThat("the while loop should have been run 100 times", _____, count);
}
void aboutForLoop() {
	int count = 0;
	for (int k = 0; k < 100; k++) {
		count++;
	}

	expectThat("the for loop should have been run 100 times", _____, count);
}
void aboutSwitchStatement() {
	const double cm_per_inch = 2.54;
	double length = 1;
	char unit = 'i';
	double result;
	switch (unit) {
	case 'i':
		result = cm_per_inch * length;
		break;
	case 'c':
		result = length / cm_per_inch;
		break;
	default:
		result = -1;
		break;
	}
	expectThat("it should have computed inch to cm", ______, result);
}
void AboutControlStructures::meditate() {
	aboutIfStatement();
	aboutIntegersTreatedAsBoolean();
	aboutWhileLoop();
	aboutForLoop();
	aboutSwitchStatement();
}

