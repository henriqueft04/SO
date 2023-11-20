#! /bin/bash

(( $# <1 )) && echo -e "File: $1"


chmod u=rwx $1
