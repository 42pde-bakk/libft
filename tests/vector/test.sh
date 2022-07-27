#!/usr/bin/env bash

# Please call this file from the root directory (where the Makefile is located)
if [[ ! -f "Makefile" ]]; then
  echo "Please call this file from the root directory (where the Makefile is located)"
  exit 1
fi

function test() {
  SRC_FILES="$1"
  if ! cc -Wall -Werror -Wextra -I include libft.a "$SRC_FILES" -o libc_vector_test.out; then
    echo "Failed on test $SRC_FILES"
    exit 1
  fi
  if ! ./libc_vector_test.out > /dev/null 2>&1; then
    echo "[KO] on test $SRC_FILES"
    exit 1
  fi
  echo "[OK] on test $SRC_FILES"
}

test tests/vector/main_intvector.c
test tests/vector/main_strvector.c
