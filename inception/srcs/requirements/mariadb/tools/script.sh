#!/bin/bash

chown -R mysql:mysql /var/lib/mysql
mysql_install_db --basedir=/usr --datadir=/var/lib/mysql --user=mysql

{
	echo "FLUSH PRIVILEGES ;"
	echo "CREATE DATABASE IF NOT EXISTS $db1_name ;"
	echo "CREATE USER IF NOT EXISTS '$db1_user'@'%' IDENTIFIED BY '$db1_pwd' ;"
	echo "GRANT ALL PRIVILEGES ON $db1_name.* TO '$db1_user'@'%' ;"
	echo "ALTER USER 'root'@'localhost' IDENTIFIED BY '1234' ;"
	echo "FLUSH PRIVILEGES ;"
} | mariadbd --bootstrap

echo "Starting database server"

echo "Executing $@"
exec "$@"
