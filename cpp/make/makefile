# release: -DNDEBUG -D_NDEBUG
# debug  : -DDEBUG  -D_DEBUG
# 8Mj8EV6wT1

export

MKDIR 	:= mkdir -p
RM    	:= rm -rf
RMDIR 	:= rm -rf

OSNAME	= $(shell uname)
OSARCH	= $(shell uname -m | tr ' /' _-)


ifeq ($(findstring CYGWIN, $(OSNAME)), CYGWIN)
OSNAME	= Cygwin
.LIBPATTERNS += lib%.dll.a
endif

BASE	= $(shell pwd)
ROOT	= $(realpath $(BASE)/..)
$(info  BASE=$(BASE))
$(info  ROOT=$(ROOT))

ifndef PREFIX
export PREFIX=/usr/local
endif

ifndef BUILDDIR
export BUILDDIR=$(ROOT)/build
endif

ifndef POCOINC
export POCOINC=$(POCO)
endif

ifndef POCOLIB
export POCOLIB=$(POCO)
POCOLIBDIR	:= /usr/local/lib
else
POCOLIBDIR 	:= $(POCOLIB)
endif

$(info  OSNAME =$(OSNAME))
$(info  OSARCH =$(OSARCH))
$(info  POCOINC=$(POCOINC))
$(info  POCOLIB=$(POCOLIB))

#include build/config/$(OSNAME)

SRCDIR		:= $(ROOT)/code
TSTDIR		:= $(ROOT)/test
INCDIR		:= $(ROOT)/inc


BUILD       ?= Debug
$(info  BUILD=$(BUILD))
ifeq ($(BUILD), Debug)
SUFFIX  	:= d
DEFINES		+=  -g3 -D_DEBUG 
else
ifeq ($(BUILD), Release)
SUFFIX		:=
DEFINES		+=  -O0 -DNDEBUG 
endif
endif

LIBPREFIX ?= lib

OBJDIR		:= $(BASE)/obj/$(OSNAME)/$(OSARCH)/$(BUILD)
ifeq ($(OSARCH),i686)
LIBDIR		:= $(BASE)/lib32
BINDIR		:= $(BASE)/bin32
endif
ifeq ($(OSARCH),x86_64)
LIBDIR		:= $(BASE)/lib64
BINDIR		:= $(BASE)/bin64
endif
ifeq ($(OSNAME),Cygwin)
OUTDIR		:= $(BINDIR)
else
OUTDIR		:= $(LIBDIR)
endif 
$(info OUTDIR=$(OUTDIR))


ifeq ($(OSNAME),Cygwin)
DEFINES  	+= -D_GLIBCXX_USE_C99
endif


INCLUDES 	+= -I$(INCDIR) 
INCLUDES 	+= -I$(POCOINC)
INCLUDES 	+= -I$(POCOINC)/CppUnit/include

CPPFLAGS 	+= $(DEFINES) $(INCLUDES)
CXXFLAGS 	+= -std=c++11  -Wno-cpp
CXXFLAGS 	+= -fmessage-length=0 -fpermissive

ifeq ($(OSNAME),Cygwin)
LIBPREFIX		:= cyg
LDFLAGS			+= -Wl,--export-all-symbols -Wl,--enable-auto-import
LDFLAGS 		+= -Wl,--image-base -Wl,0x10000000
SHAREDLIBEXT    = -$(target_version).dll
SHAREDLIBLINKEXT= .dll
else
LIBPREFIX		:= lib
LDFLAGS 		+= -Wl,-rpath,$(LIBDIR) -Wl,-rpath,$(POCOLIBDIR)
SHAREDLIBEXT    = .so.$(target_version)
SHAREDLIBLINKEXT= .so
endif


ifeq ($(OSNAME),Cygwin)
POCOLIBS 		= -L $(POCOLIBDIR) 
POCOLIBS 		+= -lPocoFoundation$(SUFFIX)
POCOLIBS 		+= -lPocoNet$(SUFFIX)
POCOLIBS 		+= -lPocoUtil$(SUFFIX)
POCOLIBS 		+= -lPocoXML$(SUFFIX) 
POCOLIBS 		+= -lCppUnit$(SUFFIX) 
else
POCOLIBS 		= -L $(POCOLIBDIR) 
POCOLIBS 		+= -lPocoFoundation$(SUFFIX) 
POCOLIBS 		+= -lPocoNet$(SUFFIX) 
POCOLIBS 		+= -lPocoUtil$(SUFFIX) 
POCOLIBS 		+= -lPocoXML$(SUFFIX) 
POCOLIBS 		+= -lCppUnit$(SUFFIX) 
endif


ifeq ($(OSNAME),Cygwin)
vpath %.dll.a	$(LIBDIR) $(POCOLIBDIR)
endif

.PHONY: ISO_8583 all dirs libexecs cppunit tests samples cleans clean distclean install

# TESTS and SAMPLES are set in config.make
#ISO_8583: libexecs $(if $(TESTS),tests) $(if $(SAMPLES),samples)
 
all: dirs libexecs 

dirs:
	@$(MKDIR) $(BINDIR)
	@$(MKDIR) $(LIBDIR)
	@$(MKDIR) $(OBJDIR)/ISO-8583/DTT
	@$(MKDIR) $(OBJDIR)/ISO-8583/TST
	@for year in 1987 1993 2003 ; do \
		$(MKDIR) $(OBJDIR)/ISO-8583/DFT/$$year ; \
		$(MKDIR) $(OBJDIR)/ISO-8583/DTE/$$year ; \
		$(MKDIR) $(OBJDIR)/ISO-8583/MSG/$$year ; \
		$(MKDIR) $(OBJDIR)/ISO-8583/SRV/$$year ; \
		$(MKDIR) $(OBJDIR)/ISO-8583/CLI/$$year ; \
	done
	
INSTALLDIR = $(DESTDIR)$(PREFIX)
COMPONENTS = DTT DTE MSG DFT CLI SRV

libexecs =  DTT-libexec DTE-libexec MSG-libexec DFT-libexec SRV-libexec CLI-libexec
tests    =  DTT-test 	DTE-test 	MSG-test 	DFT-test 	SRV-test 	CLI-test
samples  =  DTT-sample 	DTE-sample 	MSG-sample 	DFT-sample 	SRV-sample 	CLI-sample
cleans   =  DTT-clean 	DTE-clean 	MSG-clean 	DFT-clean 	SRV-clean 	CLI-clean

.PHONY: $(libexecs)
.PHONY: $(tests)
.PHONY: $(samples)
.PHONY: $(cleans)

tests: $(filter-out $(foreach f,$(OMIT),$f%),$(tests))
samples: $(filter-out $(foreach f,$(OMIT),$f%),$(samples))
cleans: $(filter-out $(foreach f,$(OMIT),$f%),$(cleans))

libexecs: 
	@$(MAKE) -C $(BASE)/code/ISO-8583/DTT         MODULE=DTT libexec
	@for year in 1987  ; do \
		for module in DTE MSG DFT SRV CLI ; do \
		$(MAKE) -C $(BASE)/code/ISO-8583/$$module MODULE=$$module YEAR=$$year libexec ; \
		done \
	done

#	$(MAKE) -C $(BASE)/code/ISO-8583/DTT         MODULE=DTT libexec
#	$(MAKE) -C $(BASE)/code/ISO-8583/DTE/$(YEAR) MODULE=DTE libexec
#	$(MAKE) -C $(BASE)/code/ISO-8583/MSG/$(YEAR) MODULE=MSG libexec
#	$(MAKE) -C $(BASE)/code/ISO-8583/DFT/$(YEAR) MODULE=DFT libexec
#	$(MAKE) -C $(BASE)/code/ISO-8583/SRV/$(YEAR) MODULE=SRV libexec
#	$(MAKE) -C $(BASE)/code/ISO-8583/CLI/$(YEAR) MODULE=CLI libexec

tests: 
	@$(MAKE) -C $(BASE)/test/ISO-8583/DTT         MODULE=DTT test
	@$(MAKE) -C $(BASE)/test/ISO-8583/TST         MODULE=TST test
	@for year in 1987  ; do \
		for module in DTE MSG ; do \
		$(MAKE) -C $(BASE)/test/ISO-8583/$$module MODULE=$$module YEAR=$$year test ; \
		done \
	done

runtests: 
	export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$(OUTDIR)
	@$(MAKE) -C $(BASE)/test/ISO-8583/DTT         MODULE=DTT runtest
	@for year in 1987  ; do \
		for module in DTE MSG ; do \
		$(MAKE) -C $(BASE)/test/ISO-8583/$$module MODULE=$$module YEAR=$$year runtest ; \
		done \
	done

clean:
	$(MAKE) -C $(BASE)/code/ISO-8583/DTT clean
	@for year in 1987  ; do \
		for module in DTE MSG DFT SRV CLI ; do \
		$(MAKE) -C $(BASE)/code/ISO-8583/$$module MODULE=$$module YEAR=$$year clean ; \
		done \
	done



distclean:
	@$(RMDIR) $(LIBDIR)
	@$(RMDIR) $(BINDIR)
	@$(RMDIR) $(DEPDIR)
	@$(RMDIR) $(OBJDIR)

#	find $(OBJDIR) -name obj -type d -print0 | xargs -0 rm -rf
#	find $(DEPDIR) -name dep -type d -print0 | xargs -0 rm -rf
#	find $(BINDIR) -name bin -type d -print0 | xargs -0 rm -rf

	
.PHONY: dep obj test code
	
