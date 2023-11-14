FROM debian:oldstable

RUN apt update -y 

RUN apt install php-fpm php-mysql -y

RUN apt install curl -y

COPY ./tools/script.sh /
COPY ./tools/wp-config.php /

ENTRYPOINT [ "/script.sh" ]
CMD [ "/usr/sbin/php-fpm7.4", "-F" ]
