
/* Result Sets Interface */
#ifndef SQL_CRSR
#  define SQL_CRSR
  struct sql_cursor
  {
    unsigned int curocn;
    void *ptr1;
    void *ptr2;
    unsigned int magic;
  };
  typedef struct sql_cursor sql_cursor;
  typedef struct sql_cursor SQL_CURSOR;
#endif /* SQL_CRSR */

/* Thread Safety */
typedef void * sql_context;
typedef void * SQL_CONTEXT;

/* Object support */
struct sqltvn
{
  unsigned char *tvnvsn; 
  unsigned short tvnvsnl; 
  unsigned char *tvnnm;
  unsigned short tvnnml; 
  unsigned char *tvnsnm;
  unsigned short tvnsnml;
};
typedef struct sqltvn sqltvn;

struct sqladts
{
  unsigned int adtvsn; 
  unsigned short adtmode; 
  unsigned short adtnum;  
  sqltvn adttvn[1];       
};
typedef struct sqladts sqladts;

static struct sqladts sqladt = {
  1,1,0,
};

/* Binding to PL/SQL Records */
struct sqltdss
{
  unsigned int tdsvsn; 
  unsigned short tdsnum; 
  unsigned char *tdsval[1]; 
};
typedef struct sqltdss sqltdss;
static struct sqltdss sqltds =
{
  1,
  0,
};

/* File name & Package Name */
struct sqlcxp
{
  unsigned short fillen;
           char  filnam[13];
};
static const struct sqlcxp sqlfpn =
{
    12,
    "insert_xy.pc"
};


static unsigned int sqlctx = 310979;


static struct sqlexd {
   unsigned int   sqlvsn;
   unsigned int   arrsiz;
   unsigned int   iters;
   unsigned int   offset;
   unsigned short selerr;
   unsigned short sqlety;
   unsigned int   occurs;
      const short *cud;
   unsigned char  *sqlest;
      const char  *stmt;
   sqladts *sqladtp;
   sqltdss *sqltdsp;
            void  **sqphsv;
   unsigned int   *sqphsl;
            int   *sqphss;
            void  **sqpind;
            int   *sqpins;
   unsigned int   *sqparm;
   unsigned int   **sqparc;
   unsigned short  *sqpadto;
   unsigned short  *sqptdso;
   unsigned int   sqlcmax;
   unsigned int   sqlcmin;
   unsigned int   sqlcincr;
   unsigned int   sqlctimeout;
   unsigned int   sqlcnowait;
              int   sqfoff;
   unsigned int   sqcmod;
   unsigned int   sqfmod;
   unsigned int   sqlpfmem;
            void  *sqhstv[4];
   unsigned int   sqhstl[4];
            int   sqhsts[4];
            void  *sqindv[4];
            int   sqinds[4];
   unsigned int   sqharm[4];
   unsigned int   *sqharc[4];
   unsigned short  sqadto[4];
   unsigned short  sqtdso[4];
} sqlstm = {13,4};

/* SQLLIB Prototypes */
extern void sqlcxt (void **, unsigned int *,
                    struct sqlexd *, const struct sqlcxp *);
extern void sqlcx2t(void **, unsigned int *,
                    struct sqlexd *, const struct sqlcxp *);
extern void sqlbuft(void **, char *);
extern void sqlgs2t(void **, char *);
extern void sqlorat(void **, unsigned int *, void *);

/* Forms Interface */
static const int IAPSUCC = 0;
static const int IAPFAIL = 1403;
static const int IAPFTL  = 535;
extern void sqliem(unsigned char *, signed int *);

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{13,4130,846,0,0,
5,0,0,1,0,0,30,47,0,0,0,0,0,1,0,
20,0,0,0,0,0,27,58,0,0,4,4,0,1,0,1,9,0,0,1,9,0,0,1,10,0,0,1,10,0,0,
51,0,0,3,0,0,24,121,0,0,1,1,0,1,0,1,97,0,0,
70,0,0,4,0,0,29,124,0,0,0,0,0,1,0,
85,0,0,5,0,0,31,145,0,0,0,0,0,1,0,
};


// 마지막고침 : 2020.11.17
/*-----------------------------------------------
dynstmt_insert_xy.pc
화면의 특정 위치에서 사용자 입력을 받은 후 테이블에 
insert 함
-------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS

//-----------------------------------------

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>

/* for oracle */
#include <sqlda.h>
#include <sqlca.h>
#include <sqlcpr.h>

//#ifdef WIN32
#include < windows.h >
#include "insert_db.h"
/*---------------  화면 커서 위치 제어 ----------------------*/
void gotoxy(int x, int y) ;
void getxy(int *x, int *y) ;
void clrscr(void) ;
/*-----------------------------------------------------------*/
#define getch() _getch()

void DB_connect();
void Insert_tuple();
void Update_tuple();
void rtrim();

void sql_error();

/* EXEC SQL BEGIN DECLARE SECTION; */ 

	/* VARCHAR uid[80]; */ 
struct { unsigned short len; unsigned char arr[80]; } uid;

	/* VARCHAR pwd[20]; */ 
struct { unsigned short len; unsigned char arr[20]; } pwd;

/* EXEC SQL END DECLARE SECTION; */ 




void DB_connect()
{
   /* 아이디와 패스워드 수정해서 넣으세요*/
    strcpy((char *)uid.arr,"b20173140@//sedb.deu.ac.kr:1521/orcl");
    uid.len = (short) strlen((char *)uid.arr);
    strcpy((char *)pwd.arr,"20173140");
    pwd.len = (short) strlen((char *)pwd.arr);

    /* EXEC SQL CONNECT :uid IDENTIFIED BY :pwd; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )10;
    sqlstm.offset = (unsigned int  )20;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)&uid;
    sqlstm.sqhstl[0] = (unsigned int  )82;
    sqlstm.sqhsts[0] = (         int  )82;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (         void  *)&pwd;
    sqlstm.sqhstl[1] = (unsigned int  )22;
    sqlstm.sqhsts[1] = (         int  )22;
    sqlstm.sqindv[1] = (         void  *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned int  )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlstm.sqlcmax = (unsigned int )100;
    sqlstm.sqlcmin = (unsigned int )2;
    sqlstm.sqlcincr = (unsigned int )1;
    sqlstm.sqlctimeout = (unsigned int )0;
    sqlstm.sqlcnowait = (unsigned int )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



	// connection이 실패했을경우의 처리부분

    if (sqlca.sqlcode != 0 && sqlca.sqlcode != -1405){ 
		printf("\7Cconnect error: %s", sqlca.sqlerrm.sqlerrmc);
		getch();
		exit(-1);
    }

    printf("Oracle Connect SUCCESS by %s\n", uid.arr);
}

void Insert_tuple()
{
    /* EXEC SQL BEGIN DECLARE SECTION; */

        /* varchar no[5]; */
    struct { unsigned short len; unsigned char arr[15]; } num;

    /* varchar name[17]; */
    struct { unsigned short len; unsigned char arr[2]; } type;

    /* varchar loc[16]; */
    struct { unsigned short len; unsigned char arr[5]; } size;

    struct { unsigned short len; unsigned char arr[15]; } name;

    struct { unsigned short len; unsigned char arr[15]; } color;

    struct { unsigned short len; unsigned char arr[15]; } cost;

    struct { unsigned short len; unsigned char arr[15]; } seller;

    struct { unsigned short len; unsigned char arr[15]; } order;


    char dynstmt[1000];
    /* EXEC SQL END DECLARE SECTION; */




       /* Register sql_error() as the error handler. */
        /* EXEC SQL WHENEVER SQLERROR DO sql_error("\7ORACLE ERROR:\n"); */


    clrscr();

    /* 데이터 입력 */
    gotoxy(20, 5);

    printf(" [ 추가할 데이터를 입력하세요 ]\n\n");

    printf("          종류:\n");
    printf("\n");
    printf("          크기:\n");
    printf("\n");
    printf("          이름:\n");
    printf("\n");
    printf("          색깔:\n");
    printf("\n");
    printf("          가격:\n");
    printf("\n");
    printf("          판매자:\n");


    /* 사원 이름 입력 */

    gotoxy(20, 7);
    gets(type.arr);
    type.len = strlen(type.arr);

    /* 지역번호 입력 */
    gotoxy(20, 9);
    gets(size.arr);
    size.len = strlen(size.arr);

    gotoxy(20, 11);
    gets(name.arr);
    name.len = strlen(name.arr);

    gotoxy(20, 13);
    gets(color.arr);
    color.len = strlen(color.arr);

    gotoxy(20, 15);
    gets(cost.arr);
    cost.len = strlen(cost.arr);

    gotoxy(20, 17);
    gets(seller.arr);
    seller.len = strlen(seller.arr);

    gotoxy(20, 19);
    gets(order.arr);
    order.len = strlen(order.arr);


    sprintf(dynstmt, "insert into product values ( product_seq.nextval, '%s', '%s', '%s', '%s', '%s', '%s', '%s')", type.arr, size.arr, name.arr, color.arr, cost.arr, seller.arr, order.arr);

    printf("stmt:%s\n", dynstmt);
    /* 실행시킬 SQL 문장*/
     /* EXEC SQL EXECUTE IMMEDIATE :dynstmt ; */

    {
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 13;
        sqlstm.arrsiz = 4;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int)1;
        sqlstm.offset = (unsigned int)51;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char*)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int)0;
        sqlstm.sqhstv[0] = (void*)dynstmt;
        sqlstm.sqhstl[0] = (unsigned int)1000;
        sqlstm.sqhsts[0] = (int)0;
        sqlstm.sqindv[0] = (void*)0;
        sqlstm.sqinds[0] = (int)0;
        sqlstm.sqharm[0] = (unsigned int)0;
        sqlstm.sqadto[0] = (unsigned short)0;
        sqlstm.sqtdso[0] = (unsigned short)0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt((void**)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) sql_error("\7ORACLE ERROR:\n");
    }



    printf("Insert Success\n");
    /* EXEC SQL COMMIT WORK ; */

    {
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 13;
        sqlstm.arrsiz = 4;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int)1;
        sqlstm.offset = (unsigned int)70;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char*)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int)0;
        sqlcxt((void**)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) sql_error("\7ORACLE ERROR:\n");
    }


}

void Update_tuple()
{

    /* EXEC SQL BEGIN DECLARE SECTION; */


    char dynstmt[1000];

    /* EXEC SQL END DECLARE SECTION; */


    /* varchar name[17]; */
    struct { unsigned short len; unsigned char arr[2]; } type;

    /* varchar loc[16]; */
    struct { unsigned short len; unsigned char arr[5]; } size;

    struct { unsigned short len; unsigned char arr[15]; } name;

    struct { unsigned short len; unsigned char arr[15]; } color;

    struct { unsigned short len; unsigned char arr[15]; } cost;


    struct { unsigned short len; unsigned char arr[15]; } before;

    /* EXEC SQL WHENEVER SQLERROR DO sql_error("\7ORACLE ERROR:\n"); */

    printf(" 수정할 데이터를 입력하세요 !!\n");

    printf("종류: ");
    gets(type.arr);
    printf("크기: ");
    gets(size.arr);
    printf("이름: ");
    gets(name.arr);
    printf("색깔: ");
    gets(color.arr);
    printf("가격: ");
    gets(cost.arr);
    printf("이전 상품번호");
    gets(before.arr);

    sprintf(dynstmt, "update product set product_type= '%s',product_size = '%s' ,product_name = '%s' ,product_color = '%s' ,product_cost = '%s' where product_number = '%s' ", type.arr, size.arr, name.arr, color.arr, cost.arr, before.arr);
    printf("stmt:%s\n", dynstmt);

    /* EXEC SQL EXECUTE IMMEDIATE :dynstmt ; */

    {
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 13;
        sqlstm.arrsiz = 4;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int)1;
        sqlstm.offset = (unsigned int)51;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char*)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int)0;
        sqlstm.sqhstv[0] = (void*)dynstmt;
        sqlstm.sqhstl[0] = (unsigned int)1000;
        sqlstm.sqhsts[0] = (int)0;
        sqlstm.sqindv[0] = (void*)0;
        sqlstm.sqinds[0] = (int)0;
        sqlstm.sqharm[0] = (unsigned int)0;
        sqlstm.sqadto[0] = (unsigned short)0;
        sqlstm.sqtdso[0] = (unsigned short)0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt((void**)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) sql_error("\7ORACLE ERROR:\n");
    }



    printf("Update Success\n");
    /* EXEC SQL COMMIT WORK ; */

    {
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 13;
        sqlstm.arrsiz = 4;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int)1;
        sqlstm.offset = (unsigned int)70;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char*)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int)0;
        sqlcxt((void**)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) sql_error("\7ORACLE ERROR:\n");
    }



}

/* --------------------------------------------------------------------------
void sql_error()

   errrpt prints the ORACLE error msg and number.
-------------------------------------------------------------------------- */
void sql_error(char *msg)
{
    char err_msg[128];
    size_t buf_len, msg_len;

    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 


    printf("\n%s\n", msg);
    buf_len = sizeof (err_msg);
    sqlglm(err_msg, &buf_len, &msg_len);
    printf("%.*s\n", msg_len, err_msg);

    getch();
    /* EXEC SQL ROLLBACK WORK ; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )85;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



}

/*---------------  화면 커서 제어 함수 --------------------*/
#define STD_HANDLE GetStdHandle(STD_OUTPUT_HANDLE)

void gotoxy(int x, int y)
{
    COORD Cur= {(SHORT)x, (SHORT) y};

    SetConsoleCursorPosition(STD_HANDLE, Cur);
}

void getxy(int *x, int *y)
{
    CONSOLE_SCREEN_BUFFER_INFO Buf ;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Buf);
    *x = (int)Buf.dwCursorPosition.X ;
    *y = (int)Buf.dwCursorPosition.Y ;
 
}

void clrscr(void)
{
    COORD Cur= {0, 0};
    unsigned long dwLen;

    FillConsoleOutputCharacter(STD_HANDLE, ' ', 80*25, Cur, &dwLen);
}

/*---------------------------------------------------------*/
