FROM debian:oldstable

RUN apt -y update && apt install -y nginx openssl

COPY ./conf/default /etc/nginx/sites-available/

COPY ./tools/script.sh /

ENTRYPOINT [ "/script.sh" ]
CMD [ "nginx", "-g", "daemon off;" ]
