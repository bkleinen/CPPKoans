/*
 * AboutPointers.cpp
 *
 *  Created on: 14.03.2012
 *      Author: merlin
 */
#include "stdafx.h"
#include "Assert.h"
#include "AboutPointers.h"

void aboutPointers(){
	int i = 5;
	int *i_pointer = &i;
	expectThat("pointers contain memory addresses - they are a reference to the variable",_____,*i_pointer);
}
void AboutPointers::meditate(){
	aboutPointers();

}

