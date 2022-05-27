#include <stdio.h>
#include <mysql.h>
#include "access_sql.h"
#include "my_utils.h"

int main()
{
    setbuf(stdout, NULL);
    MYSQL *sql = initialize_mysql("localhost", "root", "123456", "tex_store");
    insert_op_into_mysql(sql, "op1", 1, 2, 3, 4);
    mysql_close(sql);
    return 0;
}