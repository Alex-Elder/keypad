// Mongoose OS keypad library API. Source C API is defined at:
// [mgos_keypad.h]

let Keypad = {
	
	MAX_COMMAND_LENGTH: 0x0A,
	
	Init: ffi('void mgos_keypad_ini(void)'),
	GetKey: ffi('int mgos_keypad_get_key(void)'),
	GetString: ffi('char * mgos_keypad_get_string(void)'),
	SetDelayTime: ffi('void mgos_keypad_set_delay_time(int)') // Step of scan the keypad in millisec
};
