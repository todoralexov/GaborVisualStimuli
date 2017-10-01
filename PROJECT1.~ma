# ---------------------------------------------------------------------------
VERSION = BCB.01
# ---------------------------------------------------------------------------
!ifndef BCB
BCB = $(MAKEDIR)\..
!endif
# ---------------------------------------------------------------------------
PROJECT = PROJECT1.exe
OBJFILES = PROJECT1.obj Unit1.obj
RESFILES = Project1.res
RESDEPEN = $(RESFILES) Unit1.dfm
LIBFILES = "C:\Program Files\Cambridge Research Systems\VSGV6\Windows\Win32\CPPBuild\LIB\Vsgex2.lib"
DEFFILE = 
# ---------------------------------------------------------------------------
CFLAG1 = -Od -Hc -w -k -r- -y -v -vi- -c -a4 -b- -w-par -w-inl -Vx -Ve -x
CFLAG2 = -I$(BCB)\my_components\abakus;$(BCB)\my_components\umedit;$(BCB)\my_components\marscap;$(BCB)\include;$(BCB)\include\vcl;"C:\Program Files\Cambridge Research Systems\Vsgv6\Windows\Win32\CPPBuild\INCLUDE" \
   -H=$(BCB)\lib\vcld.csm 
PFLAGS = -AWinTypes=Windows;WinProcs=Windows;DbiTypes=BDE;DbiProcs=BDE;DbiErrs=BDE \
   -U$(BCB)\my_components\abakus;$(BCB)\my_components\umedit;$(BCB)\my_components\marscap;$(BCB)\lib\obj;$(BCB)\lib;"C:\Program Files\Cambridge Research Systems\Vsgv6\Windows\Win32\CPPBuild\LIB" \
   -I$(BCB)\my_components\abakus;$(BCB)\my_components\umedit;$(BCB)\my_components\marscap;$(BCB)\include;$(BCB)\include\vcl;"C:\Program Files\Cambridge Research Systems\Vsgv6\Windows\Win32\CPPBuild\INCLUDE" \
   -v -$Y -$W -$O- -JPHNV -M     
RFLAGS = -i$(BCB)\my_components\abakus;$(BCB)\my_components\umedit;$(BCB)\my_components\marscap;$(BCB)\include;$(BCB)\include\vcl;"C:\Program Files\Cambridge Research Systems\Vsgv6\Windows\Win32\CPPBuild\INCLUDE" 
LFLAGS = -L$(BCB)\my_components\abakus;$(BCB)\my_components\umedit;$(BCB)\my_components\marscap;$(BCB)\lib\obj;$(BCB)\lib;"C:\Program Files\Cambridge Research Systems\Vsgv6\Windows\Win32\CPPBuild\LIB" \
   -aa -Tpe -x -v -V4.0 
IFLAGS = 
LINKER = ilink32
# ---------------------------------------------------------------------------
ALLOBJ = c0w32.obj $(OBJFILES)
ALLRES = $(RESFILES)
ALLLIB = $(LIBFILES) vcl.lib import32.lib cp32mt.lib 
# ---------------------------------------------------------------------------
.autodepend

$(PROJECT): $(OBJFILES) $(RESDEPEN) $(DEFFILE)
    $(BCB)\BIN\$(LINKER) @&&!
    $(LFLAGS) +
    $(ALLOBJ), +
    $(PROJECT),, +
    $(ALLLIB), +
    $(DEFFILE), +
    $(ALLRES) 
!

.pas.hpp:
    $(BCB)\BIN\dcc32 $(PFLAGS) { $** }

.pas.obj:
    $(BCB)\BIN\dcc32 $(PFLAGS) { $** }

.cpp.obj:
    $(BCB)\BIN\bcc32 $(CFLAG1) $(CFLAG2) -o$* $* 

.c.obj:
    $(BCB)\BIN\bcc32 $(CFLAG1) $(CFLAG2) -o$* $**

.rc.res:
    $(BCB)\BIN\brcc32 $(RFLAGS) $<
#-----------------------------------------------------------------------------
