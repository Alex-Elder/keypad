load('api_config.js');
load('api_gpio.js');
load('api_timer.js');
load('api_sys.js');
load('api_jsar.js');
load('api_keypad.js');

Keypad.Init();

Timer.set(10, Timer.REPEAT, function() {
	let key = chr(Keypad.GetKey());
	if (key !== '\x00')
	{
		print('Command: ', key);
	}

 }, null);

