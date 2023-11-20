#!/bin/bash
echo "O meu editor por omissão BASH $BASH \$BASH"
echo 'O meu editor por omissão BASH $BASH \$BASH'
echo $(( 5 + 5 ))
echo $(( 5 > 0 )) && echo "cinco é maior do que zero"
today=$(date)
echo $today

echo $(ls -d /etc)        #listar todos
echo $(ls -d /etc/a*)     #listar todos os que começam por a
echo $(ls -d /etc/a???*)  #listar todos os que começam por a e têm mais de 3 carateres
echo "putas"
echo $(ls -d /etc/*conf*) #listar todos os que têm conf no nome