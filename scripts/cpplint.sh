#!/usr/bin/env bash

# Usage:
#   cpplint.sh <path/to/src/dir/or/files>

# Fail on error
set -e

function check_cpplint() {
  if [[ -z "$(command -v cpplint)" ]]; then
    error "Command \"cpplint\" not found."
    error "Please make sure cpplint is installed and check your PATH" \
      "settings. For Debian/Ubuntu, you can run the following command:"
    error "  sudo apt-get -y update && sudo apt-get -y install python3-pip && sudo pip3 install cpplint"
    exit 1
  fi
}

function run_cpplint() {
  for target in "$@"; do
    find ${target} -iname *.hpp -o -iname *.cpp | xargs cpplint
  done
}

function main() {
  check_cpplint

  if [ "$#" -eq 0 ]; then
    error "Usage: $0 <path/to/dirs/or/files>"
    exit 1
  fi

  run_cpplint "$@"
}

main "$@"