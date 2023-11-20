#!/bin/bash 

if (( $1 < 10 && $1 > 5 )) ; then 
    echo "Número maior do que 5 e menor do que 10" 
else 
    echo "Tenta outra vez" 
fi