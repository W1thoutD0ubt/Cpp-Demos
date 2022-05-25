#include <stdio.h>
#include <mysql.h>
#include "access_sql.h"

int main()
{
    MYSQL *sql = initialize_mysql("localhost", "root", "123456", "tex_store");
    insert_op_into_mysql(sql, " ",1,1,1,1);
    mysql_close(sql);
    return 0;
}