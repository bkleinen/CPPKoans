/*
 * AboutErrorHandling.cpp
 *
 *  Created on: 14.03.2012
 *      Author: merlin
 */
#include "stdafx.h"
#include <iostream>
#include "AboutErrorHandling.h"
#include "Assert.h"

class Bad_area {
};
class Something_else {
};

AboutErrorHandling::AboutErrorHandling() {

}

int area(int length, int width) {
	if (length <= 0 || width <= 0)
		throw Bad_area();
	if (length == 4 || width == 0)
		throw Something_else();
	return length * width;
}
void aboutThrowingSomething() {
	int result = 0;
	try {
		int area1 = area(4, 2);
	} catch (Bad_area &e) {
		result = 1;
	} catch (...) { // fängt alles andere
		result = 2;
	}

	expectThat("arbitrary classes can be thrown", 2, result);
}

void AboutErrorHandling::meditate() {
aboutThrowingSomething();

}

