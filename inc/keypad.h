// File Keypad.h
// Version 1.0
// Author: Alex
// Contact: anyfilin@mail.ru

#ifndef KEYPAD_H
#define KEYPAD_H

#include "mgos.h"

#define HIGH true
#define LOW false
#define MAX_DELAY_TIME 5000
#define MAX_COMMAND_LENGTH 10
#define MILLI_TO_MICRO_SEC(x) x * 1000


class Keypad
{
	public:
		void keypad_ini(void);
		void keypad_create(char *char_map, uint8_t *row_pins, uint8_t *column_pins, uint8_t row_num, uint8_t column_num);
		char get_char(void);
		int get_key(void);
		char * get_string(void);
		void set_delay_time(int millisec);

	private:
		void scan_key(void);
		bool has_key(void);
		void set_pin_output(int pinNum, bool level); 
		void set_pin_input_pull_up(int pinNum);
		void set_pin_input_pull_none(int pinNum);
		
		uint8_t columns_num = 0;
		uint8_t rows_num = 0;
		uint8_t *_rows_pins = NULL;
		uint8_t *_columns_pins = NULL;
		char *_chars_map = NULL;
		uint8_t count = 0;
		char tmp_key = '\0';
		char last_key = '\0';
		char cmd_str[MAX_COMMAND_LENGTH +1] = {0};
		uint64_t start_time = 0;
		uint64_t delay_time = 0;
};

extern Keypad keypad;

#endif //KEYPAD_H
