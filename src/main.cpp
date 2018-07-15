//============================================================================
// Name        : main.cpp
// Author      : Thomas Hornschuh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello RISC-V World in C++
//============================================================================

//#include <iostream>
//using namespace std;

#include <stdio.h>

#include <newlib/c-syscalls.h>

//
// Demonstrate how to print a greeting message on standard output
// and exit.
//
// WARNING: This is a build-only project. Do not try to run it on a
// physical board, since it lacks the device specific startup.
//

int
main()
{
  write(0,(const void*)"Test",4);
  puts("Hello RISC-V World!");
  write(0,(const void*)"Test",4);
  return 0;
}
