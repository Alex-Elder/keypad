#include "mgos.h"
#include "mgos_keypad.h"

static void loop(void *arg)
{
	char ch = mgos_keypad_get_char();
	if(ch != '\0')
		LOG(LL_INFO, ("Command: %c ", ch));
		
	(void) arg;
}

enum mgos_app_init_result mgos_app_init(void) 
{
  mgos_keypad_ini();
  mgos_set_timer(1, MGOS_TIMER_REPEAT, loop, NULL);

  return MGOS_APP_INIT_SUCCESS;
}
