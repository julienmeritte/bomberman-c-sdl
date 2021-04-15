/*
** ETNA PROJECT, 11/10/2019 by vignan_q
** my_genMap.c
** File description:
**
*/


#include "../../include/objects.h"
#include "../../include/basical.h"

struct wall *my_genMap(char *path) {  
    FILE *fp;
    char str[16];
    char temp[16];
    struct wall w[225];
    int countWall = 0;
    struct wall tmpWall;
    int valid = 0;
    int nbLines = 0;
    SDL_Rect tmpPos = {0 , 0 , 40 , 40};
    fp = fopen(path , "r");
    if(fp == NULL) {
        printf("%s" , "Error opening file");
        return NULL;
    }
    else {
        while (fgets(str, 16, fp)) {
            for(int i = 0; i < 15; i++) {
                if(i > strlen(str))
                    temp[i] = '0';
                else if (str[i] != '#' && str[i] != 'W' && str[i] != ' ')
                    temp[i] = '0';
                else
                    temp[i] = str[i];
            }
            for(int i = 0 ; i < 15; i++) {
                if (temp[i] == '0') {
                    valid = 1;
                }
                else {
                    valid = 0;
                    break;
                }
            }
            if (valid == 0) {
                tmpPos.y = nbLines * 40;
                for (int i = 0; i < 15 ; i++) {
                    tmpPos.x = 40 * i;
                    if (temp[i] == '#') {
                        tmpWall.breakeable = 0;
                        tmpWall.hitbox = tmpPos;
                        tmpWall.skin = "./library/assets/block/block (74).bmp";
                        w[countWall] = tmpWall;
                        countWall++;
                    }
                    else if (temp[i] == "W"){
                        tmpWall.breakeable = 1;
                        tmpWall.hitbox = tmpPos;
                        tmpWall.skin = "./library/assets/block/block (60).bmp";
                        w[countWall] = tmpWall;
                        countWall++;
                    }

                }
                nbLines++;
            }  
        }
        fclose(fp);
        return w;
    }
    
}


void printWall (struct wall *wall , int size) {
    for (int i = 0 ; i < size ; i++) {
        struct wall tmp = wall[i];
        printf("Position x : %i y : %i \n"  , tmp.hitbox.x , tmp.hitbox.y);
    }
}