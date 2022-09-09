/**
 * @file project4.c
 * @author William Wang (xw2559@nyu.edu)
 * @brief This program reads a TLB, Pages, and Caches table to give PPN on providing VPN
 * @date 2022-04-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
    // Create TLB tables for storing data, TLBp represents how many groups of data are stored in each set.
    int TLBs[4][16][2], TLBp[16]={0};
    // Create other table.
    int Pages[256];
    int Caches[16][5];

    char input[5];
    int i,a,b,c,d,e;

    // Initializing Values
    for(i=0;i<4;i++){
        for (a=0;a<16;a++){
            TLBs[i][a][0]=-1;
            TLBs[i][a][1]=-1;
        }
    }
    for(i=0;i<256;i++){
        Pages[i]=-1;
    }
    for(i=0;i<16;i++){
        for(a=0;a<5;a++){
            Caches[i][a]=-1;
        }
    }

    // Read the data
    FILE *inputf=fopen("Project4Input.txt","r");
    if(inputf==NULL){
        printf("Not able to open the file");
        exit(0);
    }
    // Read TLB
    while (fscanf(inputf,"%3s,%x,%x,%x",input,&i,&a,&b)!=EOF)
    {
        if (strcmp(input,"TLB")!=0) break;
        TLBs[i][TLBp[i]][0]=a;
        TLBs[i][TLBp[i]][1]=b;
        TLBp[i]+=1;
    }
    // Read Pages. Move the cursor.
    fseek(inputf, -3L, SEEK_CUR);
    while (fscanf(inputf,"%4s,%x,%x",input,&i,&a)!=EOF)
    {
        if (strcmp(input,"Page")!=0) break;
        Pages[i]=a;
    }
    // Read Cache. Move the cursor
    fseek(inputf, -4L, SEEK_CUR);
    while (fscanf(inputf,"%5s,%x,%x,%x,%x,%x,%x",input,&i,&a,&b,&c,&d,&e)!=EOF)
    {
        if (strcmp(input,"Cache")!=0) break;
        Caches[i][0]=a;Caches[i][1]=b;Caches[i][2]=c;Caches[i][3]=d;Caches[i][4]=e;
    }
    fclose(inputf);

    for(i=0;i<3;i++){
        int va,ppo,ppn=-1;
        int vpn,j,TLBI,TLBT;
        printf("Enter Virtual Address:\n");
        scanf("%x",&va);
        ppo=va%64;
        vpn=va>>6;
        TLBT=vpn>>2;
        TLBI=vpn%4;
        // Search int the TLB
        for(j=0;j<TLBp[TLBI];j++){
            if(TLBs[TLBI][j][0]==TLBT) ppn=TLBs[TLBI][j][1];
        }
        // Check if it's in Pages if it's not in TLB.
        if(ppn==-1)
        { 
            if(Pages[vpn]!=-1)ppn = Pages[vpn];
            else {
            printf("Can not be determined\n");
            continue;
            }
        }
        // Check if it's in Cache.
        if(Caches[ppo>>2][0]==ppn)printf("%x\n",Caches[ppo>>2][ppo%4+1]);
        else printf("Can not be determined in caches\n");
    }

}