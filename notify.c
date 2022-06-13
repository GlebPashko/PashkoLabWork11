
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/time.h>
#inlude <sys/types.h>
#include "libpq-fe.h"

int main(int argc, char **argv){
        const char *conninfo;
        PGconn *conn;
        PGresult *res;
        PGnotify *notify;
        char db_name[] = "pashko_gleb";
        char user_name[] = "pashko gleb";

        conn = PQsetdbLogin(NULL,NULL,NULL,NULL,db_name,user_name,NULL);
        if (PQstatus(conn) != CONNECTION_OK) {
                fprintf(stderr, "Connection: %s", PQerrorMassage(conn));
                PQfinish(conn);
                exit(1);
        }


        res = PQexec(conn, "NOTIFY pashko_gleb");
        if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        fprintf(stderr, "NOTIFY command failed %s", PQerrorMassage(conn));
        PQclear(res);
        PQfinish(conn);
        exit(1);z
}
fprintf(stdout, "Done.\n");
PQfinish(conn);
return 0;
}


