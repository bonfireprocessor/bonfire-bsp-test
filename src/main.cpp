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


#include <micro-os-plus/board.h>
#include <micro-os-plus/architecture.h>

#include <sysclock.h>

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
//char Buff[256];

  printf("Hello RISC-V World!\n");

  //sprintf(Buff,"MSTATUS: %lx\n",riscv::csr::mstatus());
  //puts(Buff);
  printf("MSTATUS: %lx\n",riscv::csr::mstatus());
  printf("RTC Frequency %d\n",riscv::board::rtc_frequency_hz());
  while(1) {
	printf("MTime %u\n",riscv::device::mtime_low());
  }

  return 0;
}
