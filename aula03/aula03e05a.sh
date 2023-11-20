#!/bin/bash 
# For all the files in a folder, show their properties 
if [ $# -ne 1 ]; then
  echo "Só pode ter 2 argumentos"
  exit 1
fi


if [ ! -d "$1" ]; then
  echo "O argumento deve ser um diretório válido."
  exit 1
fi

for f in $1/*; do 
   file "$f" 
#!/bin/bash 


















