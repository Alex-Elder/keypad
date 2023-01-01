// File hc543.h. (This file is part of Keypad.c)
// Version 1.0
// Author: Alex
// Contact: anyfilin@mail.ru

#pragma once

#define ROWS 4	// Numbers of rows
#define COLS 4	// Numbers of column

// Chars map
char chars_map[ROWS * COLS] = 
{
	'1','2','3','A', 
	'4','5','6','B',
	'7','8','9','C',
	'*','0','#','D'
};

uint8_t rows_pins[ROWS] = {12, 13, 15, 4}; 		// Row's pins map
uint8_t columns_pins[COLS] = {2, 22, 21, 18}; 	// Column's pins map
