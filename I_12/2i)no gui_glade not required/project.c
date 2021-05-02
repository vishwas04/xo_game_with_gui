#include<stdio.h>




struct save
{
    char n1[50];
    int s1;
    char n2[50];
    int s2;
    
};
void diplay(char a[3][3])
{
    for(int i=0;i<3;++i)
    {
        for (int j=0; j<3; ++j)
        {
            if(j!=2)
                printf("%c|",a[i][j]);
            else
                printf("%c",a[i][j]);
        }
        printf("\n");
        if(i!=2)
        printf("- - -\n");
        
    }
}
void io(char a[3][3])
    {
        int x,y;
        scanf("%d",&x);
        scanf("%d",&y);
        if(a[x-1][y-1]==' ')
        a[x-1][y-1]='o';
    }
void ix(char a[3][3])
    {
        int x,y;
        scanf("%d",&x);
        scanf("%d",&y);
        if(a[x-1][y-1]==' ')
        a[x-1][y-1]='x';
    }

int xdia(char a[3][3])
{
    int xr=0;
    if(a[0][0]==a[1][1] && a[1][1]==a[2][2]  && a[2][2]=='x')
        {
            xr=1;
        }
    else if(a[0][2]==a[1][1] && a[1][1]==a[2][0]  && a[2][0]=='x')
        {
            xr=1;

        }
    else
    {
        xr=0;
    }
    return xr;
      
}
int odia(char a[3][3])
{
    int or=0;
    if(a[0][0]==a[1][1] && a[1][1]==a[2][2]  && a[2][2]=='o')
        {
            or=1;
        }
    else if(a[0][2]==a[1][1] && a[1][1]==a[2][0]  && a[2][0]=='o')
        {
            or=1;

        }
    else
    {
        or=0;
    }
    return or;
}


int xrc(char a[3][3])
{
    int xr=0;
    if(
       ((a[0][0]==a[0][1]) && (a[0][1]==a[0][2]) && (a[0][2]=='x'))  ||
       ((a[1][0]==a[1][1]) && (a[1][1]==a[1][2]) && (a[1][2]=='x'))  ||
       ((a[2][0]==a[2][1]) && (a[2][1]==a[2][2]) && (a[2][2]=='x'))
       )
        {
            xr=1;
        }
    else if(
    ((a[0][0]==a[1][0]) && (a[1][0]==a[2][0]) && (a[2][0]=='x'))  ||
    ((a[0][1]==a[1][1]) && (a[1][1]==a[2][1]) && (a[2][1]=='x'))  ||
    ((a[0][2]==a[1][2]) && (a[1][2]==a[2][2]) && (a[2][2]=='x'))
    )
        {
            xr=1;

        }
    else
    {
        xr=0;
    }
    return xr;
}
int orc(char a[3][3])
{
    int or=0;
    if(
       ((a[0][0]==a[0][1]) && (a[0][1]==a[0][2]) && (a[0][2]=='o'))  ||
       ((a[1][0]==a[1][1]) && (a[1][1]==a[1][2]) && (a[1][2]=='o'))  ||
       ((a[2][0]==a[2][1]) && (a[2][1]==a[2][2]) && (a[2][2]=='o'))
       )
        {
            or=1;
        }
    else if(
    ((a[0][0]==a[1][0]) && (a[1][0]==a[2][0]) && (a[2][0]=='o'))  ||
    ((a[0][1]==a[1][1]) && (a[1][1]==a[2][1]) && (a[2][1]=='o'))  ||
    ((a[0][2]==a[1][2]) && (a[1][2]==a[2][2]) && (a[2][2]=='o'))
    )
        {
            or=1;

        }
    else
    {
        or=0;
    }
    return or;
}
int d(char a[3][3])
{
    int draw=0;
    int temp=0;
    for(int i=0;i<3;++i)
    {
        for (int j=0; j<3; ++j)
        {
            if (a[i][j]==' ') {
                temp = temp+1;
            }
        }
            
    }
    if (temp==0 && orc(a)!=1 && xrc(a)!=1 && xdia(a)!=1 && odia(a)!=1) {
        draw=1;
    }
    else
        draw=0;
    
    return draw;
}




int main()
{
    char p1[20] ,p2[20];
    int q;
    struct save game;
    
    
    
    printf("\n-----------\nNew Game-1\nHistory-2\nQuit-0\n-----------\n");
    scanf("%d",&q);
    while (q)
    {
        int z=1;
        for (int i=0; i<10; i++)
        {
            game.s1=0;
            game.s2=0;
        }
    if(q==1)
    {
        FILE * fp;
        fp=fopen("s.txt","a");
            printf("enter player-1's name -");
            scanf("%s",game.n1);
            printf("enter player-2's name -");
            scanf("%s",game.n2);
            printf("Player-1 is O\nPlayer-2 is X\n");
            while (z)
            {
                char a[3][3]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
                diplay(a);
                    while (1)
                    {
                        
                        if (d(a)) {
                            printf("\nDRAW\n");
                             printf("%s-%d\t%s-%d\n",game.n1,game.s1,game.n2,game.s2);
                            printf("one more game then press 1 to quit 0-");
                            scanf("%d",&z);
                            break;
                        }
                        
                        
                        io(a);
                        
                        if (odia(a)){
                            diplay(a);
                            printf("\nO IS WINNER\n");
                            game.s1=game.s1+1;
                             printf("%s-%d\t%s-%d\n",game.n1,game.s1,game.n2,game.s2);
                            printf("one more game then press 1 to quit 0-");
                            scanf("%d",&z);
                            break;
                        }
                        
                        diplay(a);
                        
                        if (orc(a)){
                            printf("\nO IS WINNER\n");
                            game.s1=game.s1+1;
                             printf("%s-%d\t%s-%d\n",game.n1,game.s1,game.n2,game.s2);
                            printf("one more game then press 1 to quit 0-");
                            scanf("%d",&z);
                            break;
                        }
                        
                        
                        if (d(a)) {
                            printf("\nDRAW\n");
                             printf("%s-%d\t%s-%d\n",game.n1,game.s1,game.n2,game.s2);
                            printf("one more game then press 1 to quit 0-");
                            scanf("%d",&z);
                            break;
                        }
                        
                        ix(a);
                        
                        if(xdia(a)){
                            diplay(a);
                            printf("\nX IS WINNER\n");
                            game.s2=game.s2+1;
                             printf("%s-%d\t%s-%d\n",game.n1,game.s1,game.n2,game.s2);
                            printf("one more game then press 1 to quit 0-");
                            scanf("%d",&z);
                            break;
                        }
                        
                        diplay(a);
                        
                        if(xrc(a)){
                            printf("\nX IS WINNER\n");
                            game.s2=game.s2+1;
                             printf("%s-%d\t%s-%d\n",game.n1,game.s1,game.n2,game.s2);
                            printf("one more game then press 1 to quit 0-");
                            scanf("%d",&z);
                            break;
                        }
                      
                            
                    }
                
                    
                }
            
            
                
    
   
    fprintf(fp,"\n%s-%d %s-%d\n---------------------\n",game.n1,game.s1,game.n2,game.s2);
    
        fclose(fp);
        char str [10][100];
        FILE * fp1;
        fp1=fopen("s.txt","r");
        for (int i=0; i<10; i++)
        {
            fgets (str[i], 100, fp1);
        }
        printf("%s",str[0]);
        
        fclose(fp1);
        printf("\n-----------\nNew Game-1\nHistory-2\nQuit-0\n-----------\n");
        scanf("%d",&q);
    }
    if (q==2)
    {
        
        FILE * fp2;
        char line[100];
        fp2 = fopen("s.txt","r");
        while(1)
            {
            fscanf(fp2,"%s",line);
            if (feof(fp2)) break;
            printf("%s\n",line);
            }
        fclose(fp2);
        printf("\n-----------\nNew Game-1\nHistory-2\nQuit-0\n-----------\n");
        scanf("%d",&q);
        
    }
    }
            
    }
    
