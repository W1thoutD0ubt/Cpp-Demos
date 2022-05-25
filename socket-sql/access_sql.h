#ifndef ACCESS_SQL_H
#define ACCESS_SQL_H

#include <mysql.h>

/**
 * @brief wrap up the steps to initialize the pointer to database
 * remember that mysql_close(MYSQL *) must be called when program terminates
 * 
 * @param host set to "localhost" or "127.0.0.1"
 * @param user 
 * @param pwd 
 * @param db_name database name, the database must exist
 * @return MYSQL* 
 */
MYSQL *initialize_mysql(char *host, char *user, char *pwd, char *db_name);

void insert_op_into_mysql(MYSQL *sql, char *op, 
        const int b_c, const int b_r, const int l_c, const int l_r);

#endif