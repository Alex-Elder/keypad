#ifndef MGOS_KEYPAD_H
#define MGOS_KEYPAD_H

// #ifdef __cplusplus
#include "keypad.h"
//#else

//#endif

#ifdef __cplusplus
extern "C" {
#endif

void mgos_keypad_ini(void);
void mgos_keypad_create(char *char_map, uint8_t *row_pins, uint8_t *column_pins, uint8_t column_num, uint8_t row_num);
char mgos_keypad_get_char(void);
int mgos_keypad_get_key(void);
char * mgos_keypad_get_string(void);
void mgos_keypad_set_delay_time(int millisec);

#ifdef __cplusplus
}
#endif  // __cplusplus 

#endif // MGOS_KEYPAD_H 
