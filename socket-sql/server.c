#include <stdio.h>
#include <mysql.h>
#include "access_sql.h"
#include "my_utils.h"

/* void form_t()
{
    MYSQL *sql = initialize_mysql("localhost", "root", "123456", "tex_store");
    insert_op_into_mysql(sql, "op1", 1, 1, 1, 1);
    mysql_close(sql);
} */

#define DCL 200

void test_insert(MYSQL *sql, char *name, 
        const int op)
{
    char *tmp = (char *) malloc(DCL);
    // the return value is very important, do pay attention to it!!!
    char *q = init_str_from_stack(DCL, "INSERT INTO tex_op (name,op) VALUES (");
    q = strconcat(q, name);
    printf("1  %s\n", q);
    q = strconcat(q, ",");
    printf("2  %s\n", q);
    q = strconcat(q, itostr(op, tmp));
    printf("3  %s\n", q);
    q = strconcat(q, ")");
    printf("4  %s\n", q);
    mysql_query(sql, q);
    free(q);
    free(tmp);
}

int main()
{
    setbuf(stdout, NULL);
    MYSQL *sql = mysql_init(NULL);
    if (sql == NULL) {
        printf("%s\n", "[server]:initialize failed");
        exit(1);
    }
    if (mysql_real_connect(sql, "localhost", "root", "123456", "tex_store", 0, NULL, 0) == NULL) {
        printf("%s\n", "[server]:connection failed");
        exit(1);
    }
    printf("%s\n", "[server]:connected to databse");
    mysql_query(sql, "CREATE TABLE tex_op (name TEXT, op INT)");
    test_insert(sql, "some_name", 123456);
    mysql_close(sql);
    return 0;
}