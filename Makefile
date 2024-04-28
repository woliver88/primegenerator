CC=gcc
CFLAGS=""
SRC = willan.c wilsons.c primes.c utils.c
TEST_SRC = willan.c wilsons.c utils.c tests/test_file.c
TARGET = primes.out
TEST_TARGET = tests/test_file.out

# PARAMS = -D${CACHE}
PARAMS = ""

primes: $(SRC)
	$(CC) $(SRC) -o $(TARGET)

test: $(TEST_SRC)
	$(CC) $(TEST_SRC) -o $(TEST_TARGET)

clean:
	rm $(TARGET)