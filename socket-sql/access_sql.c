#include <mysql.h>
#include <stdio.h>
#include <string.h>
#include "access_sql.h"

MYSQL *initialize_mysql(char *host, char *user, char *pwd, char *db_name)
{
    MYSQL *sql = mysql_init(NULL);
    if (sql == NULL) {
        printf("%s\n", "[server]:initialize failed");
        exit(1);
    }
    if (mysql_real_connect(sql, host, user, pwd, db_name, 0, NULL, 0) == NULL) {
        printf("%s\n", "[server]:connection failed");
        exit(1);
    }
    printf("%s\n", "[server]:connected to databse");
    mysql_query(sql, 
    "CREATE TABLE IF NOT EXISTS ttt (content LONGTEXT)"
    );
    return sql;
}

void insert_op_into_mysql(MYSQL *sql, char *op, 
        const int b_c, const int b_r, const int l_c, const int l_r)
{
    char *q1 = "INSERT INTO ttt (content) VALUES (\"test of long file\")";
    mysql_query(sql, q1);
}
