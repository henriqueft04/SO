#!/bin/bash

if [ $# -ne 2 ]; then
    echo "Só pode ter 2 argumentos"
    exit 1
fi


if [ ! -d "$1" ]; then
    echo "O argumento deve ser um diretório válido."
    exit 1
fi

if [[ $2 = "-r" ]]; then  
    for f in "$1"/*; do
        novoNome="${f#"$1/new_"}"
        mv "$f" "$1/$novoNome"
    done
else
    for f in "$1"/*; do 
        mv "$f" "$1/new_${f##*/}"
    done
fi

