#include "vcd.h"
#include <stdlib.h>
#include <stdio.h>
int success=0;
int failure=0;
void square(void)
{
	int i;
	int time=100;
	for (i=0;i<100;i++) {
		vcd_dump("rx","0");
		vcd_time(time); time+=100;
		vcd_dump("rx","1");
		vcd_dump_from_int("data", (unsigned char) i);
		vcd_time(time); time+=100;
	}
}
int main(int argc, char *argv)
{
	int h;
	vcd_init();
	if (vcd_open("dumpvar.vcd") == 0) {
		success++;
		printf("open succeeded\n");
	} else {
		printf("fail to open <toto>\n");
		failure++;
	}
	vcd_timescale("1ns");
	vcd_scope("logic");
	vcd_wire("data",6);
	vcd_wire("data_valid",1);
	vcd_wire("en",1);
	vcd_wire("rx",1);
	vcd_wire("tx",1);
	vcd_wire("empty",1);
	vcd_wire("underrun",1);
	vcd_upscope();
	vcd_enddef();
	//vcd_dump_vars();
	vcd_time(10UL);
	// vcd_dump("rx","1");
	// vcd_time(20UL);
	// vcd_dump("data","00000000");
	// vcd_dump("rx","0");
	// vcd_dump("tx","0");
	square();

	if (vcd_close() == 0) {
		success++;
		printf("close succeeded\n");
	} else {
		printf("fail to close <toto>\n");
		failure++;
	}
	if (failure ) { exit (1); } else { exit(0); };
	
	
}

