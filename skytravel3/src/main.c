/*
 * Initial main.c file generated by Glade. Edit as required.
 * Glade will not overwrite this file.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "interface.h"
#include "support.h"

int
main (int argc, char *argv[])
{
  GtkWidget *agent;
  GtkWidget *client;
  GtkWidget *geneagent;
  GtkWidget *geneclient;
  GtkWidget *deviswindow;
  GtkWidget *loginwindow;
  GtkWidget *aller_allerretour_window;
  GtkWidget *allerretourclient;

#ifdef ENABLE_NLS
  bindtextdomain (GETTEXT_PACKAGE, PACKAGE_LOCALE_DIR);
  bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
  textdomain (GETTEXT_PACKAGE);
#endif

  gtk_set_locale ();
  gtk_init (&argc, &argv);

  add_pixmap_directory (PACKAGE_DATA_DIR "/" PACKAGE "/pixmaps");

  /*
   * The following code was added by Glade to create one of each component
   * (except popup menus), just so that you see something after building
   * the project. Delete any components that you don't want shown initially.
   */
  /*agent = create_agent ();
  gtk_widget_show (agent);
  client = create_client ();
  gtk_widget_show (client);
  geneagent = create_geneagent ();
  gtk_widget_show (geneagent);
  geneclient = create_geneclient ();
  gtk_widget_show (geneclient);
  deviswindow = create_deviswindow ();
  gtk_widget_show (deviswindow);*/
  loginwindow = create_loginwindow ();
  gtk_widget_show (loginwindow);
  /*aller_allerretour_window = create_aller_allerretour_window ();
  gtk_widget_show (aller_allerretour_window);
  allerretourclient = create_allerretourclient ();
  gtk_widget_show (allerretourclient);*/

  gtk_main ();
  return 0;
}
