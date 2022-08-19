#!/bin/bash

find . -iname *.h -o -iname *.cc | xargs clang-format --dry-run --Werror #-i