/*
 * functions.cpp
 *
 *  Created on: Jun 26, 2018
 *      Author: Thomas Hornschuh
 *
 *   Bonfire project (c) 2018 Thomas Hornschuh
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom
 * the Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#include <micro-os-plus/board.h>
#include <micro-os-plus/architecture.h>
#include <micro-os-plus/startup/initialize-hooks.h>




void os_startup_initialize_hardware_early()
{
	// Disable all interrupts.
	  riscv::csr::clear_mstatus_bits (RISCV_CSR_MSTATUS_MIE);
	  // Disable all individual interrupts.
	  riscv::csr::mie (0);

	  // Set the trap assembly handler.
	  riscv::csr::mtvec ((riscv::arch::register_t) riscv_trap_entry);
  return;

}


void
 os_startup_initialize_hardware (void)
{

	 // Disable M timer interrupt.
	  riscv::csr::clear_mie_bits (RISCV_CSR_MIP_MTIP);

	  // Clear both mtime and mtimecmp to start afresh.
	  // Should trigger an interrupt as soon as enabled.
	  riscv::device::mtime (0);
	  riscv::device::mtimecmp (0);

	  // Enable M timer interrupt.
	  riscv::csr::set_mie_bits (RISCV_CSR_MIP_MTIP);

	  // Enable interrupts.
	  riscv::csr::set_mstatus_bits (RISCV_CSR_MSTATUS_MIE);

  return;
}


void os_terminate (int code)
{


}
