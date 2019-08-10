#!/bin/bash

#user=Chris
#password=
database=minecraft
#mysql -u "$user" -p"$password" -D "$database" -e "SELECT email FROM users WHERE username='Pandazoic';" -sN >> out.txt

output=$(mysql --defaults-extra-file=config.cnf -D "$database" -e "SELECT username FROM users;" -sN)

echo "$output";
