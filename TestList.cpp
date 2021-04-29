#include "Test.h"
#include <cassert>
#include "List.h"
#include <filesystem>
#include <iostream>
#include <Windows.h>
#include <Shlwapi.h>


void Testclaslist() {
	List l= List(0);
	l.display();
}