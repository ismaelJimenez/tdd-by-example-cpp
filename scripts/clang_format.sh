#!/usr/bin/env bash

# Usage:
#   clang-format.sh <path/to/src/dir/or/files>

# Fail on error
set -e

function check_clang_format() {
  if [[ -z "$(command -v clang-format)" ]]; then
    error "Command \"clang-format\" not found."
    error "Please make sure clang-format is installed and check your PATH" \
      "settings. For Debian/Ubuntu, you can run the following command:"
    error "  sudo apt-get -y update && sudo apt-get -y install clang-format"
    exit 1
  fi
}

function run_clang_format() {
  for target in "$@"; do
    find ${target} -iname *.h -o -iname *.cc | xargs clang-format -i
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