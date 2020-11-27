
#ifndef _SHARE_VARIABLE_FROM_ASSGINMENT
#define _SHARE_VARIABLE_FROM_ASSGINMENT
char   name[2][51];
int    nameMODE;
int    money2;
char   moneytype[5];
double moneyratio = 1;

#define END_OF_SCAN_AREA EOF
#define COMBOA (float)10.00
#define COMBOB (float)15.00
#define COMBOC (float)18.00
#define COMBOD (float)24.00
#define COMBOE (float)30.00
#define COMBOF (float)59.00
#define SST    (float)00.10
#define JAPAN_YEN_RATIO 27.426740900
#define CHINA_YUEN_RATIO 01.666587680
#define INDIA_RUPEE_RATIO 16.921358400
#define TAIWAN_DOLLAR_RATIO 07.528827040
#define THAILAND_BAHT_RATIO 08.202432520
#define HONG_KONG_DOLLAR_RATIO 01.932309700
#define SINGAPURA_DOLLAR_RATIO 00.335386167
#define UNITED_STATES_DOLLAR_RATIO 00.24615500
#define HUNDRED_PERSENT 1
#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif
#define ADMINSOR 2
#define ADMINSOR_L3 3
#define EXT_STORAGE +10
#define EXT_STRG_CUS +30
#define MAXIMUN_V(x,y) ((int)(x > y ? x : y))

/*IN SCAN AREA*/
#define NUM_OF_CUS 0
#define NUM_ADMIN 3
#define NUMBER_OF_EMP 3
#define LOWER_COMBO_A 'A'
#define HIGHER_COMBO_A 'F'
#define LOWER_COMBO_A_L 'a'
#define HIGHER_COMBO_A_L 'f'
/*END OF SCAN AREA*/

#define NUM_OF_COMBO (HIGHER_COMBO_A - LOWER_COMBO_A + 1)
#define IS_COMBO_A_U(c) ((int)((c <= HIGHER_COMBO_A && c >= LOWER_COMBO_A)? TRUE : FALSE))
#define IS_COMBO_A_L(c) ((int)((c <= HIGHER_COMBO_A_L && c >= LOWER_COMBO_A_L)? TRUE : FALSE))
// is combo return ture else false
#define ISCOM(c) ((int)((IS_COMBO_A_U(c) == TRUE || IS_COMBO_A_L(c) == TRUE)? TRUE : FALSE))
#define ADMIN_LEVEL_3(Id) (strncmp(Id,"SA3EMP",6) == STRCMP_SAME ? ADMINSOR_L3 : FALSE)
#define ADMIN_LEVEL_N(Id) (strncmp(Id,"AEMP",4) == STRCMP_SAME ? ADMINSOR : FALSE)
#define EMPLOYEE(Id) (strncmp(Id,"EMP",3) == STRCMP_SAME ? TRUE : FALSE)
// return theirn level 1,2 or 3
// only lever 3 admin allow to change admin data
#define CHECK_EMP(empC) (ADMIN_LEVEL_3(empC) + ADMIN_LEVEL_N(empC) + EMPLOYEE(empC))

int    numofemp_c = NUMBER_OF_EMP;

typedef struct ComboI
{
	char combo;
	float comboPrice;     
}ComboI;

typedef struct S_ComboData {
	char   combodata[200];  // menu 内容 
	int    loop;            // looping time or combo data '\n' num
	ComboI info;            // infomation of combo
}S_ComboData;


typedef struct Quantities_I {
	int    qtyC;            // quantities for customer
	int    totalQ;          // total quantities for a day
	ComboI info;            // infomation of combo
}Quantities_I;

typedef struct CusBuying_Record {
	int quantity[NUM_OF_COMBO];
	float totalCharge;
	Detail_time buying_time;
}CusBuying_Record;

typedef struct MemberData {
	// will take the buying time last record
	// buing quantities is total
	CusBuying_Record record;
	Personal cusDetail;
}MemberData;

#endif

// "AEMP"   adminsor  
// "EMP"    employee
// "SA3EMP" adminsor lever 3
Standard_Employee admin[3 EXT_STORAGE] = {
{ { "Tan mei mei","AEMP00001","JALAN MELUR","016-641-7375",0.00 },
{ 11,4,2016 },{ "Xiao Tan","73218324",{ "Tan mei mei",'F',{ 21,10,1999 } } } },
{ { "LIM XIAAO YEE","SA3EMP017","JALAN BUNGA KEMBOJA","108-772-1982",0.00 },
{ 21,7,2018 },{ "Mei Li","Aa73218324",{ "Lim Sai Keat",'F',{ 31,8,1987 } } } },
{ { "Lee Wen Long","AEMP01017","PANDAN INDAH","03-4296-0357",0.00 },
{ 21,9,2017 },{ "Long Kun","ilovejapan",{ "Lee Wen Long",'M',{ 1,1,2000 } } } }
};
