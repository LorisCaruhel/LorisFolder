#!/bin/bash

if [ -n "$1" ]; then
    cp -r ./Cours ./public/

    git add *
    git commit -m "$1"
    git push
else
  echo "Aucun message pour le commit"
fi
