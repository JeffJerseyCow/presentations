#include <string.h>
#include <dr_api.h>
#include <dr_tools.h>
#include <drsyms.h>


/* Globals */
static app_pc dbi_main_start;
static app_pc dbi_entry_point;
static app_pc main_ptr;
static app_pc func0_ptr;

/* Prototypes */
DR_EXPORT void
dr_client_main(client_id_t id, int argc, const char *argv[]);
static void
event_exit(void);
static bool
enum_cb(drsym_info_t *info, drsym_error_t status, void *data);

/* Main */
DR_EXPORT void
dr_client_main(client_id_t id, int argc, const char *argv[])
{
  dr_printf("[*] In dr_client_main\n");

  /* Register events */
  dr_register_exit_event(event_exit);

  /* Get main module */
  module_data_t *dbi_main = dr_get_main_module();
  if (dbi_main == NULL)
    return;
  dbi_main_start = dbi_main->start;
  dbi_entry_point = dbi_main->entry_point;

  /* Print */
  dr_printf("[*] dbi_main loaded at '%p'\n", dbi_main_start);
  dr_printf("[*] dbi_main entry point '%p'\n", dbi_entry_point);

  /* Get main/func0 locations */
  drsym_init(0);
  drsym_enumerate_symbols_ex(
    dbi_main->full_path,
    enum_cb,
    sizeof(drsym_info_t),
    NULL,
    DRSYM_DEMANGLE
  );

  /* Clean up */
  dr_free_module_data(dbi_main);
}

/* Exit */
static void
event_exit(void)
{
  dr_printf("[*] In event_exit\n");
  drsym_exit();
}

/* drsym enumerate callback */
static bool
enum_cb(drsym_info_t *info, drsym_error_t status, void *data)
{
  if(strcmp(info->name, "main") == 0)
  {
    main_ptr = (app_pc) ((size_t) dbi_main_start + info->start_offs);
    dr_printf("[*] Found main - '%p'\n", main_ptr);
  }
  else if (strcmp(info->name, "func0") == 0)
  {
    func0_ptr = (app_pc) ((size_t) dbi_main_start + info->start_offs);
    dr_printf("[*] Found func0 - '%p'\n", func0_ptr);
  }
}
