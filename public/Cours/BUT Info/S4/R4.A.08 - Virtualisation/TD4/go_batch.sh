#!/bin/bash

docker network create go_batch
docker network connect go_batch biblio_db

docker container run -d --rm --network go_batch --name go_batch_cont r408-php:8.2-apache-pdo
docker cp ./go_batch.php go_batch_cont:/var/www/html/go_batch.php
docker cp ./mvt go_batch_cont:/var/www/html/mvt
docker container exec go_batch_cont php /var/www/html/go_batch.php

docker container stop go_batch_cont
docker network disconnect go_batch biblio_db
docker network rm go_batch