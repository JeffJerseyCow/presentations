#include <dr_api.h>


/* Prototypes */
DR_EXPORT void
dr_client_main(client_id_t id, int argc, const char *argv[]);
static void
event_exit(void);

/* Main */
DR_EXPORT void
dr_client_main(client_id_t id, int argc, const char *argv[])
{
  dr_printf("[*] In dr_client_main\n");

  /* Register events */
  dr_register_exit_event(event_exit);
}

/* Exit */
static void
event_exit(void)
{
  dr_printf("[*] In event_exit\n");
}
