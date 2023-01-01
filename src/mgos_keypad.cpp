#include "mgos_keypad.h"

void mgos_keypad_ini(void)
{
	keypad.keypad_ini();
}

void mgos_keypad_create(char *char_map, uint8_t *row_pins, uint8_t *column_pins, uint8_t column_num, uint8_t row_num)
{
	keypad.keypad_create(char_map, row_pins, column_pins, column_num, row_num);
}

char mgos_keypad_get_char(void)
{
	return keypad.get_char();
}

int mgos_keypad_get_key(void)
{
	return keypad.get_key();
}

char * mgos_keypad_get_string(void)
{
	return keypad.get_string();
}

void mgos_keypad_set_delay_time(int millisec)
{
	keypad.set_delay_time(millisec);
}
