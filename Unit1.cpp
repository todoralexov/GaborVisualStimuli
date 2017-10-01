// © Тодор Алексов 2017
//---------------------------------------------------------------------------
#include <vcl\vcl.h>
#pragma hdrstop

#include <time.h>
#include <vsgex2.h>
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"

FILE *fp;
double prostrchestota=0;
int vrpredipurvistimul=0;
int n=0;
int fon=0;
int stimulcvqt=0;
int time1,time2,time3,time4,time5,time6,time7=0;
int minimum=1;
int maximum=7;
int s=0;
int dur=0;
int f=1;
//---------------------------------------------------------------------------
int CheckCard;
int Width;
int Height;
int scrWd;
int scrHgt;
CBBOXRECORD CBBox;

TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
void __fastcall TForm1::prchestotaChange(TObject *Sender)
{
    char buffer[64];
	prostrchestota=atoi(prchestota->Text.c_str());
    sprintf(buffer,"%lf",prostrchestota);
    prchestota->Text=buffer;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::vremepredipurvistimulChange(TObject *Sender)
{
    char buffer[64];
	vrpredipurvistimul=atoi(vremepredipurvistimul->Text.c_str());
    sprintf(buffer,"%d",vrpredipurvistimul);
    vremepredipurvistimul->Text=buffer;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::broinastimuliteChange(TObject *Sender)
{
    char buffer[64];
	n=atoi(broinastimulite->Text.c_str());
    sprintf(buffer,"%d",n);
    broinastimulite->Text=buffer;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::backgroundpixellevelsChange(TObject *Sender)
{
    char buffer[64];
    fon=atoi(backgroundpixellevels->Text.c_str());
    sprintf(buffer,"%d",fon);
    backgroundpixellevels->Text=buffer;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::stimulpixellevelsChange(TObject *Sender)
{
    char buffer[64];
    stimulcvqt=atoi(stimulpixellevels->Text.c_str());
    sprintf(buffer,"%d",stimulcvqt);
    stimulpixellevels->Text=buffer;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::vreme1Change(TObject *Sender)
{
    char buffer[64];
	time1=atoi(vreme1->Text.c_str());
    sprintf(buffer,"%d",time1);
    vreme1->Text=buffer;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::vreme2Change(TObject *Sender)
{
    char buffer[64];
	time2=atoi(vreme2->Text.c_str());
    sprintf(buffer,"%d",time2);
    vreme2->Text=buffer;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::vreme3Change(TObject *Sender)
{
    char buffer[64];
	time3=atoi(vreme3->Text.c_str());
    sprintf(buffer,"%d",time3);
    vreme3->Text=buffer;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::vreme4Change(TObject *Sender)
{
    char buffer[64];
	time4=atoi(vreme4->Text.c_str());
    sprintf(buffer,"%d",time4);
    vreme4->Text=buffer;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::vreme5Change(TObject *Sender)
{
    char buffer[64];
	time5=atoi(vreme5->Text.c_str());
    sprintf(buffer,"%d",time5);
    vreme5->Text=buffer;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::vreme6Change(TObject *Sender)
{
    char buffer[64];
	time6=atoi(vreme6->Text.c_str());
    sprintf(buffer,"%d",time6);
    vreme6->Text=buffer;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::vreme7Change(TObject *Sender)
{
    char buffer[64];
	time7=atoi(vreme7->Text.c_str());
    sprintf(buffer,"%d",time7);
    vreme7->Text=buffer;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::startClick(TObject *Sender)
{
//---------------------------------------------------------------------------
    CheckCard=vsgInit("");
    if(CheckCard<0)exit(0);
//---------------------------------------------------------------------------
    Width=vsgGetScreenWidthPixels();
    Height=vsgGetScreenHeightPixels();
    scrWd=vsgGetScreenWidthPixels();
    scrHgt=vsgGetScreenHeightPixels();
//---------------------------------------------------------------------------
	fp=fopen(experimentspecification->Text.c_str(),"w");
    fprintf(fp,"Пространствена честота:\n");
    fprintf(fp,prchestota->Text.c_str());
    fprintf(fp,"\nВреме преди първи стимул:\n");
    fprintf(fp,vremepredipurvistimul->Text.c_str());
    fprintf(fp,"\nПърво време [ms]:\n");
    fprintf(fp,vreme1->Text.c_str());
    fprintf(fp,"\nВторо време [ms]:\n");
    fprintf(fp,vreme2->Text.c_str());
    fprintf(fp,"\nТрето време [ms]:\n");
    fprintf(fp,vreme3->Text.c_str());
    fprintf(fp,"\nЧетвърто време [ms]:\n");
    fprintf(fp,vreme4->Text.c_str());
    fprintf(fp,"\nПето време [ms]:\n");
    fprintf(fp,vreme5->Text.c_str());
    fprintf(fp,"\nШесто време [ms]:\n");
    fprintf(fp,vreme6->Text.c_str());
    fprintf(fp,"\nСедмо време [ms]:\n");
    fprintf(fp,vreme7->Text.c_str());
    fprintf(fp,"\nБрой на стимулите:\n");
    fprintf(fp,broinastimulite->Text.c_str());
    fprintf(fp,"\nФонови нива на пикселтие:\n");
    fprintf(fp,backgroundpixellevels->Text.c_str());
    fprintf(fp,"\nНива на пиксели на стимул:\n");
    fprintf(fp,stimulpixellevels->Text.c_str());
    if(noise->Checked==true){
       fprintf(fp,"\nИма шум");
    }
    else{
       fprintf(fp,"\nНяма шум");
    }
    fclose(fp);

    fp=fopen(experimentresults->Text.c_str(),"w");
//---------------------------------------------------------------------------
  cbboxOpen(respCOM1);//Initiates communications to the response box
  cbboxFlush();
//---------------------------------------------------------------------------
  vsgSetDisplayPage(0);
  vsgSetDrawPage(vsgVIDEOPAGE,0,0);
 //Време преди първи стимул
 for(int j=0;j<=vrpredipurvistimul;j++)
 vsgFrameSync();
 //Стимули
 for(int i=1;i<=n;i++){
     int flag=1;
     srand(time(NULL));
     int r=rand();
//---------------------------------------------------------------------------
     if(f){
        srand(time(NULL));
        s=minimum+rand()%(maximum+1 - minimum);
//---------------------------------------------------------------------------
        if(s==1){
           dur==time1;
        }
//---------------------------------------------------------------------------
        if(s==2){
           dur==time2;
        }
//---------------------------------------------------------------------------
        if(s==3){
           dur==time3;
        }
//---------------------------------------------------------------------------
        if(s==4){
           dur==time4;
        }
//---------------------------------------------------------------------------
        if(s==5){
           dur==time5;
        }
//---------------------------------------------------------------------------
        if(s==6){
           dur==time6;
        }
//---------------------------------------------------------------------------
        if(s==7){
           dur==time7;
        }
     }
 //---------------------------------------------------------------------------
 for(int k=0;k<=dur;k++){
 //---------------------------------------------------------------------------
 //Габор
 if(r%2!=0){
    vsgSetPen1(fon);
    vsgSetPen2(stimulcvqt);
    vsgDrawGabor(0, 0, Width, Height, 90, prostrchestota, Height/6, 0);
                                   //ориентация в градуси; пространствена честота;отклонение;фаза
 }
 if(r%2==0){
    vsgDrawGabor(0, 0, Width, Height, 90, 0, Height/6, 0);
 }
 //Шум
 if(noise->Checked==true){
    vsgSetDrawPage(vsgVIDEOPAGE,0,128);
    vsgSetDisplayPage(0);
    vsgDrawNoise(scrWd/2, scrHgt/2,scrWd,scrHgt,2,2,0,50,156);
    }
 //---------------------------------------------------------------------------
 cbboxBuzzer(respSEC02,respTONE0);
 for(int vremezaotgovor=1;vremezaotgovor<=301;i++){
     if(vremezaotgovor<=300){
        if(cbboxCheck((CBBOXRECORD*)&CBBox)!=respEMPTY){
           if (CBBox.switchA==respUP){
               fprintf(fp,"%d стимул е видян. Време за отговор %d ms\n",i,vremezaotgovor);
               flag=0;
               f=1;
           }
           if (CBBox.switchC==respUP){
               fprintf(fp,"%d стимул не е видян. Време за отговор %d ms\n",i,vremezaotgovor);
               flag=0;
               f=1;
           }
        }
     }
     if(cbboxCheck((CBBOXRECORD*)&CBBox)==respEMPTY){
        if(vremezaotgovor==301){
           if(flag){
              fprintf(fp,"За %d стимул не е посочен отговор");
              i--;
              f=0;
              cbboxBuzzer(respSEC02,respTONE15);
        }
           }
     }
 }
 cbboxFlush();
 //---------------------------------------------------------------------------
 }
}
 fclose(fp);
 //---------------------------------------------------------------------------
 vsgSetCommand(vsgPALETTECLEAR);
 vsgSetDrawMode(vsgCENTREXY+vsgANTIALIASED);
 vsgSetDrawPage(vsgVIDEOPAGE,0, 0);
 vsgSetDisplayPage(0);
 vsgSetPen1(255);
 vsgSetPen2(0);
 vsgSetTrueTypeFont("Arial");
 vsgSetStringMode(0, div(Height, 6).quot, vsgALIGNCENTRETEXT, vsgALIGNCENTRETEXT, 0, 0);
 vsgDrawString(0, 0, "Опитът завърши!");

  vsgSetCommand(vsgPALETTERAMP);
}
//---------------------------------------------------------------------------
// © Тодор Алексов 2017

