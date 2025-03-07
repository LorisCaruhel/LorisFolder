FROM r408-php:8.2-apache
RUN docker-php-ext-install pdo pdo_mysql
COPY go_batch.php /var/www/html/go_batch.php
COPY mvt /var/www/html/go_batch.php
RUN php /var/www/html/go_batch.php