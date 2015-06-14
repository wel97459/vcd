#include <glib.h>
#ifndef VCD_H_
#define VCD_H_

/* always return status */
int vcd_init(void);
int vcd_open(char *filename);
int vcd_date(void);
int vcd_version(char *version);
int vcd_comment(char *comment);
int vcd_timescale(char *timescale);
int vcd_scope(char *module);
int vcd_upscope(void);
int vcd_wire(int size, char *name);
int vcd_close();
int vcd_dump(char *name, char *value);
int vcd_time(long int time);

#endif /* VCD_H_ */

