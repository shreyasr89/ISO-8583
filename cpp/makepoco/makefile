export

MKDIR := mkdir -p
RMDIR := rm -rf

YEAR 	= 1987
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

MODULE		:= DTT
SRCDIR		:= $(ROOT)/code
TSTDIR		:= $(ROOT)/test
INCDIR		:= $(ROOT)/inc
SRCDIR		:= $(SRCDIR)/ISO-8583/$(MODULE)
$(info  SRCDIR=$(SRCDIR))

ifndef PREFIX
export PREFIX=/usr/local
endif

ifndef BUILD
export BUILD=$(BASE)/build
endif

LIBDIR		= lib/$(OSNAME)/$(OSARCH)
DEPDIR		= dep/$(OSNAME)/$(OSARCH)
OBJDIR		= obj/$(OSNAME)/$(OSARCH)


POCOINC		= $(POCO)
LINKMODE	= BOTH

all:
	$(MAKE) -C code/ISO-8583/DTT