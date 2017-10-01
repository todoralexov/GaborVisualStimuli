//---------------------------------------------------------------------------
#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <vcl\Classes.hpp>
#include <vcl\Controls.hpp>
#include <vcl\StdCtrls.hpp>
#include <vcl\Forms.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TButton *prostranstvenachestota;
	TEdit *prchestota;
	TButton *timebeforefirststimul;
	TEdit *vremepredipurvistimul;
    TButton *numberofstimuli;
	TEdit *broinastimulite;
    TCheckBox *noise;
    TButton *fonovinivanapixeli;
    TEdit *backgroundpixellevels;
	TButton *nivanapikselinastimul;
    TEdit *stimulpixellevels;
    TButton *produljitelnost;
    TEdit *vreme1;
	TEdit *vreme2;
	TEdit *vreme3;
	TEdit *vreme4;
	TEdit *vreme5;
	TEdit *vreme6;
	TEdit *vreme7;
	TButton *experimentbutton;
	TEdit *experimentspecification;
	TButton *experimentresultbutton;
	TEdit *experimentresults;
	TButton *start;
	void __fastcall prchestotaChange(TObject *Sender);
    void __fastcall vremepredipurvistimulChange(TObject *Sender);
    void __fastcall broinastimuliteChange(TObject *Sender);
    void __fastcall backgroundpixellevelsChange(TObject *Sender);
    void __fastcall stimulpixellevelsChange(TObject *Sender);
    void __fastcall vreme1Change(TObject *Sender);
	void __fastcall vreme2Change(TObject *Sender);
	void __fastcall vreme3Change(TObject *Sender);
	void __fastcall vreme4Change(TObject *Sender);
	void __fastcall vreme5Change(TObject *Sender);
	void __fastcall vreme6Change(TObject *Sender);
	void __fastcall vreme7Change(TObject *Sender);
    void __fastcall startClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
