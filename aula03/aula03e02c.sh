#!/bin/bash

# Conditional block if
if [[ "$1" = "$2" ]]; then
    echo "$1 é igual a $2"
else
    echo "Os args são diferentes"
fi
