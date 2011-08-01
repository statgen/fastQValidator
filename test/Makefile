# The command to run.
TEST_COMMAND = ln -sfT $(ACTUAL_PATH)/fastq/test/testFile.txt testFile.txt; \
               mkdir -p results; ./FastQValidatorTest.sh

TEST_CLEAN = rm -f testFile.txt; rm -rf results;

########################
# Include the base Makefile
PARENT_MAKE = Makefile.test
include ../Makefile.inc
