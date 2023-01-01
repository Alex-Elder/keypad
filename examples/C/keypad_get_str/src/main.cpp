#include "mgos.h"
#include "mgos_keypad.h"

static void loop(void *arg)
{
	char *str = mgos_keypad_get_string();
	if(str != NULL)
		LOG(LL_INFO, ("Command: %s ", str));
		
	(void) arg;
}

enum mgos_app_init_result mgos_app_init(void) 
{
  mgos_keypad_ini();
  mgos_set_timer(1, MGOS_TIMER_REPEAT, loop, NULL);

  return MGOS_APP_INIT_SUCCESS;
}
