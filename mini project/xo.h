GtkWidget *block_imgs[9];
GtkWidget *g_lbl_0;
GtkWidget *g_lbl_1;
GtkWidget *g_lbl_2;
gboolean turn = TRUE;
gchar game_board[9];
gint wins[3];
gint flag = 1;
gint o_wins = 0;
gint x_wins = 0;
gchar won;
gint clicks = 0;

int on_play_clicked(int argc, char *argv[])
{
	entryO = gtk_entry_get_text (GTK_ENTRY (g_entryO));
	entryX = gtk_entry_get_text (GTK_ENTRY (g_entryX));

	GtkBuilder *builder;
	GtkWidget *window;
	gchar str_img[] = "img_0";

	gtk_init(&argc, &argv);

	builder = gtk_builder_new_from_file("window_main.glade");
	window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));

	for (gint i = 0; i < 9; i++) 
	{
        str_img[4] = i + '0';
        block_imgs[i] = GTK_WIDGET(gtk_builder_get_object(builder, str_img));
	game_board[i] = '0';
	}
	
	g_lbl_0 = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_0"));
	g_lbl_1 = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_1"));
	g_lbl_2 = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_2"));
	
	gtk_builder_connect_signals(builder, NULL);
	g_object_unref(builder);
	gtk_widget_show(window);                

	return 0;

}

void on_btn_clicked(GtkButton *button)

{

	clicks++;	
	gint btn_num;
	gint f = 0;
	char str_count1[30];
	char str_count2[30];
	
	if(!(flag))
	return;

	btn_num = gtk_widget_get_name(GTK_WIDGET(button))[0] - '0';
	
	if (game_board[btn_num] == '0')
	{
	gtk_image_set_from_file(GTK_IMAGE(block_imgs[btn_num]),(turn ? "o.png" : "x.png"));

	game_board[btn_num] = (turn ? 'o' : 'x');
	turn = !(turn);
	}

	if(turn)
	gtk_label_set_text(GTK_LABEL(g_lbl_0), "Player O's turn");
	else
	gtk_label_set_text(GTK_LABEL(g_lbl_0), "Player X's turn");

	if (clicks>4)
	{
		for (gint i = 1; i < 9; i+=3)
		{
		if ((game_board[i-1]=='o')&&(game_board[i]=='o')&&(game_board[i+1]=='o'))
			{
			 wins[0] = (i-1);
			 wins[1] = i;
			 wins[2] = (i+1);
			 won = 'o';
			}
		if ((game_board[i-1]=='x')&&(game_board[i]=='x')&&(game_board[i+1]=='x'))
			{
			 wins[0] = (i-1);
			 wins[1] = i;
			 wins[2] = (i+1);
			 won = 'x';
			}
		}

		for (gint i = 0; i < 3; i++)
		{
		if ((game_board[i]=='o')&&(game_board[i+3]=='o')&&(game_board[i+6]=='o'))
			{
			 wins[0] = i;
			 wins[1] = (i+3);
			 wins[2] = (i+6);
			 won = 'o';
			}
		if ((game_board[i]=='x')&&(game_board[i+3]=='x')&&(game_board[i+6]=='x'))
			{
			 wins[0] = i;
			 wins[1] = (i+3);
			 wins[2] = (i+6);
			 won = 'x';
			}
		}
		if ((game_board[0]=='o')&&(game_board[4]=='o')&&(game_board[8]=='o'))
		 {
		 wins[0] = 0;
		 wins[1] = 4;
		 wins[2] = 8;
		 won = 'o';
		 }
		if ((game_board[2]=='o')&&(game_board[4]=='o')&&(game_board[6]=='o'))
		{
		 wins[0] = 2;
		 wins[1] = 4;
		 wins[2] = 6;
		 won = 'o';
		}
		if ((game_board[0]=='x')&&(game_board[4]=='x')&&(game_board[8]=='x'))
		{		
		 wins[0] = 0;
		 wins[1] = 4;
		 wins[2] = 8;
		 won = 'x';
		}
		if ((game_board[2]=='x')&&(game_board[4]=='x')&&(game_board[6]=='x'))
		{
		 wins[0] = 2;
		 wins[1] = 4;
		 wins[2] = 6;
		 won = 'x';
		}
	
		if (won == 'o')
		{
			o_wins++;
			flag = 0;			
			for (int i = 0; i < 3; i++)
			 gtk_image_set_from_file(GTK_IMAGE(block_imgs[wins[i]]), "o_win.png");
			gtk_label_set_text(GTK_LABEL(g_lbl_0), "O Won!");
			
		}
		
		if (won == 'x')
		{
			x_wins++;
			flag = 0;			
			for (int i = 0; i < 3; i++)
			 gtk_image_set_from_file(GTK_IMAGE(block_imgs[wins[i]]), "x_win.png");
			gtk_label_set_text(GTK_LABEL(g_lbl_0), "X Won!");
			
		}
		
		for (gint i = 0; i < 9; i++)
		{
		 if (game_board[i] == '0')
			f++;
		}
		if(!(f) && (won != 'x') && (won != 'o'))
		{
		 flag = 0;
		 gtk_label_set_text(GTK_LABEL(g_lbl_0), "Tie");
		}
	}
	if (!(flag))
	{
		sprintf(str_count1, "%d",o_wins);
		sprintf(str_count2, "%d",x_wins);
		gtk_label_set_text(GTK_LABEL(g_lbl_2), str_count1);
		gtk_label_set_text(GTK_LABEL(g_lbl_1), str_count2);
	}
}

void on_btn_new_clicked(GtkButton *button)


{
	for (int i = 0; i < 9; i++)
	{
	game_board[i] = '0';
	gtk_image_set_from_file(GTK_IMAGE(block_imgs[i]), "blank.png");
	}
	gtk_label_set_text(GTK_LABEL(g_lbl_0), (turn ? "Player O's turn" : "Player X's turn"));
	flag = 1;
	clicks = 0;
	won = ' ';
	wins[0] = 9;
	wins[1] = 9;
	wins[2] = 9;
	
}

void on_window_main_destroy()
{
	gtk_main_quit();
	FILE * fp;
	fp = fopen("history.txt","a");
	fprintf(fp,"%s %d\n%s %d\n",entryO,o_wins,entryX,x_wins);
	fclose(fp);

}

	 

	
	
	

