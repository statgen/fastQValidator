# Makefile that includes this should specify PARENT_MAKE to be
# the Makefile it should include from libStatGen/Makefiles/$(PARENT_MAKE)

# Update version as necessary.
VERSION=0.1.1

########################
# Library Path:
#
# Default path to the statgen library.  You can either update your copy of
# this Makefile to be where you want to get the Makefile from or you can 
# overwrite LIB_PATH_GENERAL or LIB_PATH_FASTQ_VALIDATOR.
# This design is such that if you have multiple programs, you could just set
# LIB_PATH_GENERAL to the location they should all use to find the library.
# If one program needs a different path, you would set LIB_PATH_FASTQ_VALIDATOR
# to that different path.
CURRENT_PATH := $(dir $(lastword $(MAKEFILE_LIST)))
LIB_PATH_GENERAL ?=../libStatGen
LIB_PATH_FASTQ_VALIDATOR ?= $(LIB_PATH_GENERAL)

# add any additional ../ as necessary if it is a relative path
ACTUAL_PATH =  $(patsubst ../%, $(CURRENT_PATH)../%, $(LIB_PATH_FASTQ_VALIDATOR))
INCLUDE_MAKE = $(ACTUAL_PATH)/Makefiles/$(PARENT_MAKE)

########################
# Include the base Makefile
include $(INCLUDE_MAKE)

.phony: libStatGen

########################
# This is to handle the case where the statgen library is not already there.
$(INCLUDE_MAKE):
	@echo Unable to locate: $(INCLUDE_MAKE)
	@echo To change the location, set LIB_PATH_GENERAL or LIB_PATH_FASTQ_VALIDATOR to the appropriate path to libStatGen.  Or specify \"make LIB_PATH_GENERAL=yourPath\" or \"make LIB_PATH_FASTQ_VALIDATOR=yourPath\"
	@echo Use make libStatGen if you have git and want to download and build the current libStatGen at that location


libStatGen:
	@if test -d $(LIB_PATH_FASTQ_VALIDATOR); \
	then echo $(LIB_PATH_FASTQ_VALIDATOR) already exists; \
	else git clone git://github.com/statgen/libStatGen.git $(LIB_PATH_FASTQ_VALIDATOR); fi
	$(MAKE) -C $(LIB_PATH_FASTQ_VALIDATOR) --no-print-directory all; \
