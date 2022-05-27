#include <mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include "access_sql.h"
#include "my_utils.h"

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
    // create area to store *.tex file
    mysql_query(sql, 
    "CREATE TABLE tex-file (\'file_name\' TEXT, \'content\' LONGTEXT)"
    );
    // create area to store each opearation
    mysql_query(sql, 
    "CREATE TABLE tex-op (\'content\' TEXT, \'b_c\' INT,\'b_r\' INT,\'l_c\' INT,\'l_r\' INT)"
    );
    return sql;
}

#define DCL 200

void insert_op_into_mysql(MYSQL *sql, char *op, 
        const int b_c, const int b_r, const int l_c, const int l_r)
{
    char *tmp = (char *) malloc(DCL);
    // the return value is very important, do pay attention to it!!!
    char *q = init_str_from_stack(DCL, "INSERT INTO tex-op (content,b_c,b_r,l_c,l_r) VALUES (");
    q = strconcat(q, op);
    q = strconcat(q, ",");
    q = strconcat(q, itostr(b_c, tmp));
    q = strconcat(q, ",");
    q = strconcat(q, itostr(b_r, tmp));
    q = strconcat(q, ",");
    q = strconcat(q, itostr(l_c, tmp));
    q = strconcat(q, ",");
    q = strconcat(q, itostr(l_r, tmp));
    q = strconcat(q, ")");
    printf("%s\n", q);
    mysql_query(sql, q);
    free(q);
    free(tmp);
}
