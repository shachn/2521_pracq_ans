# COMP2521 - Practice Exercises

# !!! DO NOT MODIFY THIS FILE !!!

CC = clang
CFLAGS = -Wall -Wvla -Werror -gdwarf-4

########################################################################

.PHONY: asan msan nosan

asan: CFLAGS += -fsanitize=address,leak,undefined
asan: all

msan: CFLAGS += -fsanitize=memory,undefined -fsanitize-memory-track-origins
msan: all

nosan: all

########################################################################

TEST_DRIVER = testListNumDuplicates.c
EXERCISE_FILE = listNumDuplicates.c
COMMON = list.c

SRC_FILES = $(TEST_DRIVER) $(EXERCISE_FILE) $(COMMON)

all: testListNumDuplicates

testListNumDuplicates: $(SRC_FILES)
	$(CC) $(CFLAGS) -o testListNumDuplicates $(SRC_FILES)

clean:
	rm -f testListNumDuplicates
