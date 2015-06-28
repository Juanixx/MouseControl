#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
WINDOW *win; /** manejaremos una ÃƒÂºnica ventana de pantalla completa **/
/*********************************************************************/
void IniVideo(){
       win=initscr(); /* Crea la ventana */
       clear();  /* Borra la pantalla entera bajo ncurses */
       refresh(); /* Actualiza la ventana con los cambios */
       noecho();
       cbreak();
       keypad(win, TRUE);
}

void sinc(char mover[], int x, int y){
  mover[23]=y/1000+48;
  y=y%1000;
  mover[24]=y/100+48;
  y=y%100;
  mover[25]=y/10+48;
  y=y%10;
  mover[26]=y+48;

  mover[18]=x/1000+48;
  x=x%1000;
  mover[19]=x/100+48;
  x=x%100;
  mover[20]=x/10+48;
  x=x%10;
  mover[21]=x+48;

}



/*************************/
void Exit(){
	system("modprobe psmouse");  
       refresh();
       endwin();
       exit(1);
}
/*****************************************************************/
main () {
	system ("modprobe -r psmouse");
	int x=714;
    int y=327;
    char mover[27]={'x','d','o','t','o','o','l',' ','m','o','u','s','e','m','o','v','e',' ','0','0','0','1',' ','0','0','0','1'};
	
	
	int ch;
       IniVideo();
       printw("Presione esc  para terminar");
       
       
               for(;;)
	{	
		ch= getch();
               
		switch(ch)
		{	case 260:
				if(x>65) x-=8;
				break;
			case 261:
				if(x<786) x+=8;
				refresh();
				break;
			case 259:
				if(y>54) y-=8;
				break;
			case 258:
				if(y<479) y+=8;
				
				break;	
				case 27:
				Exit();
		}
		
		sinc( mover, x, y);
      system("sleep 0.001");
      system(mover);
      IniVideo();
	}
	    
 
       Exit();
}
