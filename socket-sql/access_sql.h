#ifndef ACCESS_SQL_H
#define ACCESS_SQL_H

#include <mysql.h>

/* wrap up the complex procedure to initialize database */
MYSQL *initialize_mysql(char *host, char *user, char *pwd, char *db_name);

/* insert change of char data to database */
void insert_op_into_mysql(MYSQL *sql, char *op, 
        const int b_c, const int b_r, const int l_c, const int l_r);

#endif