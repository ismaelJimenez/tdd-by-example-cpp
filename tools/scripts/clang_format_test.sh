#!/usr/bin/env bash

# Usage:
#   clang-format_test.sh <path/to/src/dir/or/files>

# Fail on error
set -e

CLANG_FORMAT_CMD="clang-format"

function check_clang_format() {
  if [[ -z "$(command -v clang-format)" ]]; then
    error "Command \"clang-format\" not found."
    error "Please make sure clang-format is installed and check your PATH" \
      "settings. For Debian/Ubuntu, you can run the following command:"
    error "  sudo apt-get -y update && sudo apt-get -y install clang-format"
    exit 1
  fi
}

function clang_format_run() {
  ${CLANG_FORMAT_CMD} -i "$@"
}


function run_clang_format() {
  for target in "$@"; do
    find ${target} -iname *.hpp -o -iname *.cpp | xargs clang-format --dry-run --Werror
  done
}

function main() {
  check_clang_format

  if [ "$#" -eq 0 ]; then
    error "Usage: $0 <path/to/dirs/or/files>"
    exit 1
  fi

  run_clang_format "$@"
}

main "$@"