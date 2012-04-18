// CPPKoans.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"

#include <iostream>

#include "AboutControlStructures.h"
#include "AboutDataTypes.h"
#include "AboutFunctionCalls.h"
#include "AboutArrays.h"
#include "AboutStrings.h"
#include "AboutClasses.h"
#include "AboutVectors.h"
#include "AboutStdInAndOut.h"
#include "AboutErrorHandling.h"
#include "AboutPointers.h"
#include "StopMeditating.h"
#include "AboutAssert.h"
#include "AboutBitwiseOperators.h"
#include "AboutUserDefinedTypes.h"
using namespace std;

/**
 * About the Koans.
 * These are C++
 */

int main() {
	cout << "Running CPP Koans. No further output should be produced." << endl;
	try {
		AboutControlStructures::meditate();
		AboutDataTypes::meditate();
		AboutErrorHandling::meditate();
	    AboutPointers::meditate();
		AboutClasses::meditate();
		AboutArrays::meditate();
		AboutStrings::meditate();
		AboutFunctionCalls::meditate();
		AboutAssert::meditate();
		AboutBitwiseOperators::meditate();
		AboutUserDefinedTypes::meditate();
	} catch (const StopMeditating &e) {
		cout << "catched StopMeditating." << endl;
	}
//	AboutVectors::meditate();
//	AboutStdInAndOut::meditate();
}

