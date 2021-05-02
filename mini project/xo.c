#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
GtkWidget *g_entryO;
const gchar *entryO;
GtkWidget *g_entryX;
const gchar *entryX;
#include "xo.h"
char final[50];
struct info
{
    char p[20];
    int s;
   
};

void high()
{
    FILE *fileptr;
    int lines = 0;
    fileptr = fopen("history.txt", "r");

    char chr;
       while ((chr=getc(fileptr)) != EOF)
       {

           if (chr == '\n')
           {
               lines =lines + 1;
           }


       }
 

    struct info * x;
    x=(struct info *)malloc(lines* 2 *sizeof(struct info));
    

    
    fclose(fileptr);
    
    FILE *fp;
    fp = fopen("history.txt", "r");
   

    for (int i=0; i<(2*lines); i++)
    {
        fscanf(fp,"%s %d",x[i].p,&x[i].s);
    }
    
    struct info temp;
    for (int i=0; i<(2*lines); i++)
    {
        for (int j=0; j<(2*lines); j++)
        {
            if (x[i].s > x[j].s)
                {
                    temp=x[i];
                    x[i]=x[j];
                    x[j]=temp;
                }

        }
    }
    char hs[5];
    sprintf(hs, " %d", x[0].s);
    strcat(final,x[0].p);
    strcat(final,hs);
    fclose(fp);
}

int main(int argc, char *argv[])
{
	high();	
	GtkBuilder *builder1;
	GtkWidget *window1;
	gtk_init(&argc, &argv);

	builder1 = gtk_builder_new_from_file("window_menu.glade");
	window1 = GTK_WIDGET(gtk_builder_get_object(builder1, "window_menu"));
	
	gtk_builder_connect_signals(builder1, NULL);
	g_object_unref(builder1);
	gtk_widget_show(window1);
	gtk_main();
}

int on_players_clicked(int argc, char *argv[])
{

	GtkBuilder *builder2;
	GtkWidget *window2;
	gtk_init(&argc, &argv);
	builder2 = gtk_builder_new_from_file("window_players.glade");
	window2 = GTK_WIDGET(gtk_builder_get_object(builder2, "window_players"));
	g_entryO = GTK_WIDGET(gtk_builder_get_object(builder2, "entry_playerO"));
	g_entryX = GTK_WIDGET(gtk_builder_get_object(builder2, "entry_playerX"));
	gtk_builder_connect_signals(builder2, NULL);
	g_object_unref(builder2);
	gtk_widget_show(window2);            

	return 0;

}

int on_high_score_btn_clicked(int argc, char *argv[])
{
	GtkBuilder *builder3;
	GtkWidget *window3;
	GtkWidget *g_lbl_5;
	gtk_init(&argc, &argv);
	builder3 = gtk_builder_new_from_file("window_high.glade");
	window3 = GTK_WIDGET(gtk_builder_get_object(builder3, "window_high"));
	g_lbl_5 = GTK_WIDGET(gtk_builder_get_object(builder3, "lbl_5"));
	gtk_label_set_text(GTK_LABEL(g_lbl_5), final);
	gtk_builder_connect_signals(builder3, NULL);
	g_object_unref(builder3);
	gtk_widget_show(window3);            

	return 0;
}

void on_window_menu_destroy()
{
    gtk_main_quit();
}
void on_window_players_destroy()
{
    gtk_main_quit();
}
void on_window_high_destroy()
{
    gtk_main_quit();
}
