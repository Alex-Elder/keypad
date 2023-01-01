// File Keypad.c
// Version 1.0
// Author: Alex
// Contact: anyfilin@mail.ru

#include "mgos.h"
#include "keypad.h"
#include "hc543.h"

Keypad keypad;

void Keypad::keypad_ini(void)
{
	keypad_create(chars_map, rows_pins, columns_pins, ROWS, COLS);
}

void Keypad::keypad_create(char *char_map, uint8_t *row_pins, uint8_t *column_pins, uint8_t row_num, uint8_t column_num)
{

	rows_num = row_num;
	columns_num = column_num;
	_rows_pins = row_pins;
	_columns_pins = column_pins;
	_chars_map = char_map;
	
	set_delay_time(100); 
	
	for (uint8_t r = 0; r < rows_num; r++) 
	{
		set_pin_input_pull_none(_rows_pins[r]);
	}
		
	for (uint8_t c = 0; c < columns_num; c++) 
	{
		set_pin_input_pull_up(_columns_pins[c]);
	}
}

bool Keypad::has_key(void)
{
	return tmp_key != '\0' ? true : false;
}

char Keypad::get_char(void)
{
	char _key = '\0';
	
	if((mgos_uptime_micros() - start_time) > delay_time)
	{
		scan_key();
		if(has_key())
		{
			_key = tmp_key;
			tmp_key = '\0'; 
		}
		start_time = mgos_uptime_micros();
	}
	return _key;
}

int Keypad::get_key(void)
{
	return (int)get_char();
}

char * Keypad::get_string(void)
{
	char _ch = get_char();
	
	if(_ch != '#' && _ch != '\0' && count < MAX_COMMAND_LENGTH)
	{
		cmd_str[count] = _ch;
		count++;
	}
	else if(_ch == '#' && count != 0)
	{
		cmd_str[count] = '\0';
		count = 0;
		return cmd_str;
	}
	return NULL;
}

void Keypad::scan_key(void)
{
	char _key = '\0';
	
	for (uint8_t r = 0; r < rows_num; r++) 
	{
		set_pin_output(_rows_pins[r], LOW);
		
		for (uint8_t c = 0; c < columns_num; c++) 
		{
			if(!mgos_gpio_read(_columns_pins[c]))
			{
				_key = _chars_map[r * columns_num + c];
			}
		}
		set_pin_input_pull_none(_rows_pins[r]);
	}
	
	if(last_key != _key) 
	{	
		last_key = _key;		
		if(_key != '\0') 
		{			
			tmp_key = _key;
		}
	}
}

// Step of keyboard scan.  Set debounce interval in milliseconds
void Keypad::set_delay_time(int millisec)
{
	delay_time = (millisec == 0 || millisec > MAX_DELAY_TIME) ? MILLI_TO_MICRO_SEC(1) : MILLI_TO_MICRO_SEC(millisec);
}

void Keypad::set_pin_output(int pinNum, bool level) 
{ 
	mgos_gpio_setup_output(pinNum, level);
}

void Keypad::set_pin_input_pull_up(int pinNum) 
{ 
	mgos_gpio_set_mode(pinNum, MGOS_GPIO_MODE_INPUT);
	mgos_gpio_set_pull(pinNum, MGOS_GPIO_PULL_UP);
}

void Keypad::set_pin_input_pull_none(int pinNum) 
{ 
	mgos_gpio_set_mode(pinNum, MGOS_GPIO_MODE_INPUT);
	mgos_gpio_set_pull(pinNum, MGOS_GPIO_PULL_NONE);
}
