
#include<stdio.h>	
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<time.h>
#include<stdarg.h>
#ifndef NO_INCLUDE_LIM_SAI_KEAT
#define NO_INCLUDE_LIM_SAI_KEAT

#include"c:\Users\ITSUKA KOTORI\source\repos\Project2\Project2\shareVariable.h"
#include"c:\Users\ITSUKA KOTORI\source\repos\Tutorial Pcd2\Tutorial Pcd2\borrowStruct.h"
#include"c:\Users\ITSUKA KOTORI\source\repos\GETfunctionLib\GETfunctionLib\getlib.h"

#pragma warning(push)
#pragma warning (disable : 4013 4244 4090 4029 4020 4996)
#pragma warning (disable : 4129 4024 4047 4024 4081 4028 4030 4031)

typedef enum Animation
{
	Motion_1, Motion_2, Motion_3, Motion_4, Motion_5, Motion_6, Motion_7, Motion_8,
	Motion_9, Motion_10, Motion_11, Motion_12, Motion_13, Motion_14, Motion_15, Motion_16,
	Motion_17, Motion_18, Motion_19, Motion_20
}Animation;


void initialise_Customer_data(CusBuying_Record * data);

void logo_Max_line(FILE* stream);

void logo(void);

void changecolour_and_display_MODE(const char *color, const Animation mode);

void changecolour_and_clear_screen(const char * backGcolour, const char * frontcolour);

void motion_logo_main(FILE* stream);

void save_logo_main(FILE* stream);

// mode 0 - 12
void montion_logo_D_M(FILE* stream, const Animation mode);

void changecolour_and_display_STATIC_MODE(const char* color, const Animation mode);

void save_logo_6(FILE* stream);
// mode 0 - 19;
void motion_logo_6_M(FILE* stream, const Animation mode);

void menuprice_header_line(FILE *stream);

void menuprice_header_blank(FILE *stream);

void menuprice_body(const S_ComboData *data, FILE *stream);

void restore_menu_price_to_file(const char * filename, const S_ComboData *data);

// edit .h file data only
// mode "c combo", "c numA", "c numE"
// only one time use
void change_cfile_function(
	const char * c_filename, const char *mode, ...);

void write_binary_CusBuying_Record(const CusBuying_Record * data,
	const int  totalnumofCus, FILE* fp);

// once only
void read_binary_CusBuying_Record(CusBuying_Record * data,
	FILE* fp);

// define of num of cus
void read_binary_Previos_CusBuying_Record(CusBuying_Record * data,
	FILE* fp);

// only this can add new employee data
// emp cannot edit 
// one time 
void admin_application_add_new(const char * fileName,
	const Standard_Employee * data);

//detail.id //detail.salary //
//allow user edit the id emp can edit 
void editerble_employee_Data_std(Standard_Employee * data);

int str_isalspace(const char * string);

// check 'a'-'z'||'A'-'Z'||'1'-'0'
int str_isalnum(const char * string);

int str_isalpha(const char * string);

int str_isspace(const char * string);

// Employee not allow to open anly admin can open
// Admin cannot change admin data 
// level 3 adminsor can edit evere thing
//(stdin) input
void unediterble_employee_Data_std(Standard_Employee * data);

void search_and_display_E_A_AL3(const char * filename);

//get the array from file and return pointer
Standard_Employee *get_file_data(const char * filename);

// return no. of emp current have
// result is the number of loop
// fscanf FILW
int readfiledata_admin(Standard_Employee * data, FILE*stream, int *lcount);

// all the previos data will be over write
// will bace on the data given make sure is array
// give correct file name
// warning given only lever 3 admin can do
void restore_all_info_Standard(const Standard_Employee*data, const char * filename);

// fprintf the data in to file
// fill stdout to print out the data
void saveStandard_Employee_admin(const Standard_Employee * data,
	FILE*stream, const int i);

// employee / admin log in
// this function only do finding task
// must give array data
// emp want to update info is done in function
int nemployee_internet_login(const Standard_Employee *ary_data);

// employee secrch data of employee
// secrch in file with updated data
// is resave all the data
void fsecrch_employee_data(const char*filename);

// customer see data of employee
// from file only
void scerch_emp_data_cus(const char *filename);

void fprintfiledata_cus(Personal const* data, FILE*stream, const int i);

void menuprice(const S_ComboData * arydata);

void savemenuprice(const S_ComboData * arydata, FILE *stream);

void menuprice_end(FILE *stream);

int selectmoney(void);

void diarySummary(const float totalreward, const Quantities_I *data, const int noCus);

void savediarySummary(const float totalreward, const Quantities_I *data,
	const int noCus, const FILE *stream);

int quantities(FILE* fileOnly, char symbol, char comboT, int totalquantities, double comboP);

double tranNegetifToZero(double num);

double creditcard(FILE *fileOnly, float aPay2, float totalP);

void fPrintname(FILE *fileOnly, const int a, const int b,
	const int c, const int d, const int e);

void moneycalCalculationPart(int peviousmoney2);

float switchOtherMethodPay(FILE* fileOnly, float amountneedtopay);

float rewardlooping(FILE* fileOnly, float total);

void changeMoney();

void unlimitedLoppingForPayment(FILE* fileOnly, float aPay);

float rewardDepentSystem(const unsigned long sixDigitRewardCode);

void randonSelectVoucherNum(FILE *fileOnly, int rewardPrice);

int rewardCountingSystem(const unsigned long rewardCodeMinusN);

float rewardVoucherPaymentSystem(FILE *fileOnly, float amountneedtoPay);

void initialise_Customer_data(CusBuying_Record * data)
{
	
	initialise_Detail_time_data(&data->buying_time);
	COUNT_LOOP(NUM_OF_COMBO)
		data->quantity[i] = 0;
	data->totalCharge = 0.00;
}

void logo_Max_line(FILE* stream)
{
	// maximun logo line 
	fputs("\txxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n", stream);
}

void logo()
{
	motion_logo_main(stdout);
}

# define SLEEP_TIME_LOGO 200
# define SLEEP_TIME_L_L 150
#define SLEEP_TIME_S 100

void changecolour_and_display_MODE(const char *color, const Animation mode)
{
	montion_logo_D_M(stdout, mode);
	_sleep(SLEEP_TIME_S); 
	changecolour_and_clear_screen(COLOUR_CODE_BRIGHY_WHITE, color);
}

void changecolour_and_clear_screen(const char * backGcolour, const char * frontcolour)
{
	char code[30];
	sprintf(code, "%s%s%s", SYSTEM_COLOR, backGcolour, frontcolour);
	system(code);
	system("cls");
}

void motion_logo_main(FILE* stream)
{
	save_logo_main(stdout);
	_sleep(900);
	system(SYSTEM_COLOR  COLOUR_CODE_GRAY          COLOUR_CODE_BLACK);
	_sleep(SLEEP_TIME_L_L);
	system(SYSTEM_COLOR  COLOUR_CODE_GRAY          COLOUR_CODE_BLACK);
	_sleep(SLEEP_TIME_L_L);
	system(SYSTEM_COLOR  COLOUR_CODE_WHITE         COLOUR_CODE_BLACK);
	_sleep(SLEEP_TIME_L_L);
	system(SYSTEM_COLOR  COLOUR_CODE_BRIGHY_WHITE  COLOUR_CODE_BLACK );
	system("cls");
	_sleep(20);
	COUNT_LOOP(5)
	{
		changecolour_and_display_MODE(COLOUR_CODE_RED     , Motion_1);
		changecolour_and_display_MODE(COLOUR_CODE_L_RED   , Motion_2);
		changecolour_and_display_MODE(COLOUR_CODE_YELLOW  , Motion_3);
		changecolour_and_display_MODE(COLOUR_CODE_L_YELLOW, Motion_4);
		changecolour_and_display_MODE(COLOUR_CODE_L_GREEN , Motion_5);
		changecolour_and_display_MODE(COLOUR_CODE_GREEN   , Motion_6);
		changecolour_and_display_MODE(COLOUR_CODE_AQUA    , Motion_7);
		changecolour_and_display_MODE(COLOUR_CODE_L_AQAU  , Motion_8);
		changecolour_and_display_MODE(COLOUR_CODE_L_BLUE  , Motion_9);
		changecolour_and_display_MODE(COLOUR_CODE_BLUE    , Motion_10);
		changecolour_and_display_MODE(COLOUR_CODE_PURPLE  , Motion_11);
		changecolour_and_display_MODE(COLOUR_CODE_L_PURPLE, Motion_12);
		changecolour_and_display_MODE(COLOUR_CODE_L_RED   , Motion_13);
	}
	changecolour_and_display_STATIC_MODE(COLOUR_CODE_RED   , Motion_1);
	changecolour_and_display_STATIC_MODE(COLOUR_CODE_L_RED , Motion_2);
	changecolour_and_display_STATIC_MODE(COLOUR_CODE_YELLOW, Motion_3);
	changecolour_and_display_STATIC_MODE(COLOUR_CODE_YELLOW, Motion_4);
	changecolour_and_display_STATIC_MODE(COLOUR_CODE_GREEN , Motion_5);
	changecolour_and_display_STATIC_MODE(COLOUR_CODE_GREEN , Motion_6);
	changecolour_and_display_STATIC_MODE(COLOUR_CODE_GREEN , Motion_7);
	changecolour_and_display_STATIC_MODE(COLOUR_CODE_AQUA  , Motion_8);
	changecolour_and_display_STATIC_MODE(COLOUR_CODE_AQUA  , Motion_9);
	changecolour_and_display_STATIC_MODE(COLOUR_CODE_AQUA  , Motion_10);
	changecolour_and_display_STATIC_MODE(COLOUR_CODE_AQUA  , Motion_11);
	changecolour_and_display_STATIC_MODE(COLOUR_CODE_BLUE  , Motion_12);
	changecolour_and_display_STATIC_MODE(COLOUR_CODE_BLUE  , Motion_13);
	changecolour_and_display_STATIC_MODE(COLOUR_CODE_BLUE  , Motion_14);
	changecolour_and_display_STATIC_MODE(COLOUR_CODE_BLUE  , Motion_15);
	changecolour_and_display_STATIC_MODE(COLOUR_CODE_BLUE  , Motion_16);
	changecolour_and_display_STATIC_MODE(COLOUR_CODE_PURPLE, Motion_17);
	changecolour_and_display_STATIC_MODE(COLOUR_CODE_PURPLE, Motion_18);
	changecolour_and_display_STATIC_MODE(COLOUR_CODE_PURPLE, Motion_19);
	changecolour_and_display_STATIC_MODE(COLOUR_CODE_PURPLE, Motion_20);
}

void save_logo_main(FILE* stream)
{
	//restoran logo
	logo_Max_line(stream);
	logo_Max_line(stream);
	fputs("\txxx       *****        *****        *****        xxx\n", stream);
	fputs("\txxx      **   ***   ***     ***   ***   **       xxx\n", stream);
	fputs("\txxx             ** ***       *** **              xxx\n", stream);
	fputs("\txxx              ****         ****               xxx\n", stream);
	fputs("\txxx      ~~~~~~~ INFINITY RESTOREN ~~~~~~~       xxx\n", stream);
	fputs("\txxx              ****         ****               xxx\n", stream);
	fputs("\txxx             ** ***       *** **              xxx\n", stream);
	fputs("\txxx      **   ***   ***     ***   ***   **       xxx\n", stream);
	fputs("\txxx       *****        *****        *****        xxx\n", stream);
	logo_Max_line(stream);
	logo_Max_line(stream);
	fputs("\txxx                                              xxx\n", stream);
	fputs("\txxx                                              xxx\n", stream);
	fputs("\txxx    WELCOME TO INFINITY RESTOREN ( XDDDD )    xxx\n", stream);
	logo_Max_line(stream);
	logo_Max_line(stream);
	fputs("\n", stream);

}

// mode 0 - 12
void montion_logo_D_M(FILE* stream, const Animation mode)
{
	// %13
	//
	//" ***        *****        *****     ",//1
	//"   ***    ***   ***    ***   ***   ",
	//"    *** ***      *** ***      ***  ",
	//"      ***          ***          ** ",
	//" ~~~~~~* INFINITY RESTOREN ~~~~~~* "
	const char *firstL_L[13] = {
		" ***        *****        *****     ",//1
		" **        *****        *****      ",//2
		" *        *****        *****       ",//3
		"         *****        *****        ",//4
		"        *****        *****         ",//5
		"       *****        *****        * ",//6
		"      *****        *****        ** ",//7
		"     *****        *****        *** ",//8
		"    *****        *****        **** ",//9
		"   *****        *****        ***** ",//10
		"  *****        *****        *****  ",//11
		" *****        *****        *****   ",//12
		" ****        *****        *****    "//13
	};
	const char *second_L[13] = {
		//1234567890123456789012345678901234
		"   ***    ***   ***    ***   ***   ",
		"  ***    ***   ***    ***   ***    ",
		" ***    ***   ***    ***   ***     ",
		" **    ***   ***    ***   ***    * ",
		" *    ***   ***    ***   ***    ** ",
		"     ***   ***    ***   ***    *** ",
		"    ***   ***    ***   ***    ***  ",
		"   ***   ***    ***   ***    ***   ",
		"  ***   ***    ***   ***    ***    ",
		" ***   ***    ***   ***    ***   * ",
		" **   ***    ***   ***    ***   ** ",
		" *   ***    ***   ***    ***   *** ",
		"    ***    ***   ***    ***   ***  "
	};
	const char *third_L[13] = {
		//1234567890123456789012345678901234
		"    *** ***      *** ***      ***  ",
		"   *** ***      *** ***      *** * ",
		"  *** ***      *** ***      *** ** ",
		" *** ***      *** ***      *** *** ",
		" ** ***      *** ***      *** ***  ",
		" * ***      *** ***      *** ***   ",
		"  ***      *** ***      *** ***    ",
		" ***      *** ***      *** ***     ",
		" **      *** ***      *** ***      ",
		" *      *** ***      *** ***       ",
		"       *** ***      *** ***      * ",
		"      *** ***      *** ***      ** ",
		"     *** ***      *** ***      *** ",
	};
	const char *fourth_L[13] = {
		//1234567890123456789012345678901234
		"      ***          ***          ** ",
		"     ***          ***          *** ",
		"    ***          ***          ***  ",
		"   ***          ***          ***   ",
		"  ***          ***          ***    ",
		" ***          ***          ***     ",
		" **          ***          ***      ",
		" *          ***          ***       ",
		"           ***          ***        ",
		"          ***          ***         ",
		"         ***          ***          ",
		"        ***          ***           ",
		"       ***          ***          * ",
	};
	const char *mainlogo[13] = {
		//1234567890123456789012345678901234
		" ~~~~~~* INFINITY RESTOREN ~~~~~~* ",
		" ~~~~~*~ INFINITY RESTOREN ~~~~~*~ ",
		" ~~~~*~~ INFINITY*RESTOREN ~~~~*~~ ",
		" ~~~*~~~ INFINITY*RESTOREN ~~~*~~~ ",
		" ~~*~~~~ INFINITY*RESTOREN ~~*~~~~ ",
		" ~*~~~~~ INFINITY RESTOREN ~*~~~~~ ",
		" *~~~~~~ INFINITY RESTOREN *~~~~~~ ",
		" ~~~~~~~ INFINITY RESTOREN*~~~~~~~ ",
		" ~~~~~~~ INFINITY RESTOREN ~~~~~~~ ",
		" ~~~~~~~ INFINITY RESTOREN ~~~~~~~ ",
		" ~~~~~~~ INFINITY RESTOREN ~~~~~~~ ",
		" ~~~~~~~ INFINITY RESTOREN ~~~~~~~ ",
		" ~~~~~~~*INFINITY RESTOREN ~~~~~~~ ",
	};
	const char *main_infinity[13] = {
		"   LCOME TO INFINITY RESTOR   ( X     )",
		"    COME TO INFINITY RESTO    ( XD    )",
		"     OME TO INFINITY REST     ( XDD   )",
		" W    ME TO INFINITY RES    N ( XDDD  )",
		" WE    E TO INFINITY RE    EN ( XDDDD )",
		" WEL     TO INFINITY R    REN ( X     )",
		" WELC    TO INFINITY     OREN ( XD    )",
		" WELCO    O INFINITY    TOREN ( XDD   )",
		" WELCOM     INFINIT    STOREN ( XDDD  )",
		" WELCOME    INFINI    ESTOREN ( XDDDD )",
		" WELCOME     NFIN    RESTOREN ( XDDD  )",
		" WELCOME T    FI     RESTOREN ( XDD   )",
		" WELCOME TO        Y RESTOREN ( XD    )",
	};
	const char *main_infinity_s_1[13] = {
		//WELCOME TO INFINITY RESTOREN
		" WE                        EN          ",
		" WEL                      REN          ",
		"  ELC                    ORE           ",
		"   LCO                  TOR            ",
		"    COM                STO             ",
		"     OME              EST              ",
		"      ME             RES               ",
		"       E T           RE                ",
		"         TO        Y R                 ",
		"         TO       TY                   ",
		"          O I    ITY                   ",
		"            IN  NIT                    ",
		"            INFINI                     ",
	};
	const char *main_infinity_s_2[13] = {
		//WELCOME TO INFINITY RESTOREN
		"   L                      R            ",
		"    C                    O             ",
		"     O                  T              ",
		"      M                S               ",
		"       E              E                ",
		"                     R                 ",
		"         T                             ",
		"          O        Y                   ",
		"                  T                    ",
		"            I    I                     ",
		"             N  N                      ",
		"              FI                       ",
		" W                          N          ",
	};
	//restoran logo
	logo_Max_line(stream);
	logo_Max_line(stream);
	fprintf(stream, "\txxx\t%s\t xxx\n", firstL_L[mode]);
	fprintf(stream, "\txxx\t%s\t xxx\n", second_L[mode]);
	fprintf(stream, "\txxx\t%s\t xxx\n", third_L[mode]);
	fprintf(stream, "\txxx\t%s\t xxx\n", fourth_L[mode]);
	fprintf(stream, "\txxx\t%s\t xxx\n", mainlogo[mode]);
	fprintf(stream, "\txxx\t%s\t xxx\n", fourth_L[mode]);
	fprintf(stream, "\txxx\t%s\t xxx\n", third_L[mode]);
	fprintf(stream, "\txxx\t%s\t xxx\n", second_L[mode]);
	fprintf(stream, "\txxx\t%s\t xxx\n", firstL_L[mode]);
	logo_Max_line(stream);
	logo_Max_line(stream);
	fprintf(stream, "\txxx\t%s\t xxx\n", main_infinity_s_1[mode]);
	fprintf(stream, "\txxx\t%s\t xxx\n", main_infinity_s_2[mode]);
	fprintf(stream, "\txxx\t%s\t xxx\n", main_infinity[mode]);
	logo_Max_line(stream);
	logo_Max_line(stream);
	fputs("\n", stream);

}

void changecolour_and_display_STATIC_MODE(const char* color, const Animation mode)
{
	motion_logo_6_M(stdout, mode);
	_sleep(SLEEP_TIME_L_L);
	changecolour_and_clear_screen(COLOUR_CODE_BRIGHY_WHITE, color);
}

void save_logo_6(FILE* stream)
{
	//restoran logo
	logo_Max_line(stream);
	logo_Max_line(stream);
	fputs("\txxx\t  *****        *****        *****  \t xxx\n", stream);
	fputs("\txxx\t **   ***   ***     ***   ***   **\t xxx\n", stream);
	fputs("\txxx\t        ** ***       *** **\t\t xxx\n", stream);
	fputs("\txxx\t         ****         ****\t\t xxx\n", stream);
	fputs("\txxx\t ~~~~~~~ INFINITY RESTOREN ~~~~~~~\t xxx\n", stream);
	fputs("\txxx\t         ****         ****\t\t xxx\n", stream);
	fputs("\txxx\t        ** ***       *** **\t\t xxx\n", stream);
	fputs("\txxx\t **   ***   ***     ***   ***   **\t xxx\n", stream);
	fputs("\txxx\t  *****        *****        *****  \t xxx\n", stream);
	logo_Max_line(stream);
	logo_Max_line(stream);

}
// mode 0 - 19;
void motion_logo_6_M(FILE* stream, const Animation mode)
{

	const char *main_infinity[20] = {
		"   LCOME TO INFINITY RESTOR   ( X     )",
		"    COME TO INFINITY RESTO    ( XD    )",
		"     OME TO INFINITY REST     ( XDD   )",
		" W    ME TO INFINITY RES    N ( XDDD  )",
		" WE    E TO INFINITY RE    EN ( XDDDD )",
		" WEL     TO INFINITY R    REN ( X     )",
		" WELC    TO INFINITY     OREN ( XD    )",
		" WELCO    O INFINITY    TOREN ( XDD   )",
		" WELCOM     INFINIT    STOREN ( XDDD  )",
		" WELCOME    INFINI    ESTOREN ( XDDDD )",
		" WELCOME     NFIN    RESTOREN ( XDDD  )",
		" WELCOME T    FI     RESTOREN ( XDD   )",
		" WELCOME TO        Y RESTOREN ( XD    )",
		"                                       ",
		"                                       ",
		"                                       ",
		"                                       ",
		"          I           T           I    ",
		" I                                   T ",
		"                                       ",
	};
	char *const main_infinity_s_1[20] = {
		//WELCOME TO INFINITY RESTOREN
		" WE                        EN          ",
		" WEL                      REN          ",
		"  ELC                    ORE           ",
		"   LCO                  TOR            ",
		"    COM                STO             ",
		"     OME              EST              ",
		"      ME             RES               ",
		"       E T           RE                ",
		"         TO        Y R                 ",
		"         TO       TY                   ",
		"          O I    ITY                   ",
		"            IN  NIT                    ",
		"            INFINI                     ",
		"            INFINITY                   ",
		"            INFINITY                   ",
		"          N   I  N   T                 ",
		"                                       ",
		"       F      I       N                ",
		"  F                                 N  ",
		"                                       ",
	};
	const char *main_infinity_s_2[20] = {
		//WELCOME TO INFINITY RESTOREN
		"   L                      R            ",
		"    C                    O             ",
		"     O                  T              ",
		"      M                S               ",
		"       E              E                ",
		"                     R                 ",
		"         T                             ",
		"          O        Y                   ",
		"                  T                    ",
		"            I    I                     ",
		"             N  N                      ",
		"              FI                       ",
		" W                          N          ",
		"                                       ",
		"                                       ",
		"        I   F      I   Y               ",
		"        I N F I  N I T Y               ",
		"     N                         Y       ",
		" N                                    Y",
		"                INFINITY               ",
	};
	save_logo_6(stream);
	fprintf(stream, "\txxx\t%s\t xxx\n", main_infinity_s_1[mode]);
	fprintf(stream, "\txxx\t%s\t xxx\n", main_infinity_s_2[mode]);
	fprintf(stream, "\txxx\t%s\t xxx\n", main_infinity[mode]);
	logo_Max_line(stream);
	logo_Max_line(stream);
	fputs("\n", stream);
}

void menuprice_header_line(FILE *stream)
{
	fprintf(stream, "======================================================================\n");
}

void menuprice_header_blank(FILE *stream)
{
	fprintf(stream, "|                                                                    |\n");
}

void menuprice_body(const S_ComboData *data, FILE *stream)
{
	char strdatal[4][38];
	menuprice_header_blank(stream);
	fprintf(stream,"| %-6s%-31c    |     %3s %6.2f          |\n", "COMBO ",
		data->info.combo, moneytype, moneyratio*(data->info.comboPrice));
	switch (data->loop)
	{
	case 4:
		sscanf(data->combodata, "%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n", 
			strdatal[0], strdatal[1], strdatal[2], strdatal[3]);
		fprintf(stream, "| %-37s    |                         |\n", strdatal[3]);
	case 3:
		sscanf(data->combodata, "%[^\n]\n%[^\n]\n%[^\n]\n",
			strdatal[0], strdatal[1], strdatal[2]);
		fprintf(stream, "| %-37s    |                         |\n", strdatal[2]);
	case 2:
		sscanf(data->combodata, "%[^\n]\n%[^\n]\n",
			strdatal[0], strdatal[1]);
		fprintf(stream, "| %-37s    |                         |\n", strdatal[1]);
	case 1:
		sscanf(data->combodata, "%[^\n]\n",
			strdatal[0]);
		fprintf(stream, "| %-37s    |                         |\n", strdatal[0]);
		break;
	}
}

void restore_menu_price_to_file(const char * filename, const S_ComboData *data)
{
	FILE *fp;
	fp = fopen(filename, "w");
	check_file_open(fp, filename);
	savemenuprice(data, fp);
	fclose(fp);
}

// edit .h file data only
// mode "c combo", "c numA", "c numE"
// only one time use
void change_cfile_function(
	const char * c_filename, const char *mode,...)
{
	va_list ap;
	va_start(ap, mode);
	ADMINSOR_L3;
	FILE *fp;
	char fileinfo[500][300];
	int count = 0;
	fp = fopen(c_filename, "r");
	while (fscanf(fp, "%[^\n]\n", fileinfo[count]) != EOF)
	{
		if (strncmp("c combo", mode, 6) == STRCMP_SAME)
		{
			char newcom = va_arg(ap, char);
			if (strncmp("#define HIGHER_COMBO_A_L", fileinfo[count], 24) == STRCMP_SAME)
				sprintf(fileinfo[count], "#define LOWER_COMBO_A_L \'%c\'\n", tolower(newcom));
			else if (strncmp("#define HIGHER_COMBO_A", fileinfo[count], 22) == STRCMP_SAME)
				sprintf(fileinfo[count], "#define LOWER_COMBO_A \'%c\'\n", toupper(newcom));
		}
		else if (strncmp("c numA", mode, 6) == STRCMP_SAME)
		{
			int newnum = va_arg(ap, int);
			if (strncmp("#define NUM_ADMIN", fileinfo[count], 20) == STRCMP_SAME)
				sprintf(fileinfo[count], "#define NUM_ADMIN %d\n", newnum);
		}
		else if (strncmp("c numE", mode, 6) == STRCMP_SAME)
		{
			int newnum = va_arg(ap, int);
			if (strncmp("#define NUMBER_OF_EMP", fileinfo[count], 21) == STRCMP_SAME)
				sprintf(fileinfo[count], "#define NUMBER_OF_EMP %d\n", newnum);
		}
		else if (strncmp("c numE", mode, 6) == STRCMP_SAME)
		{
			int newnum = va_arg(ap, int);
			if (strncmp("#define NUMBER_OF_EMP", fileinfo[count], 21) == STRCMP_SAME)
				sprintf(fileinfo[count], "#define NUMBER_OF_EMP %d\n", newnum);
		}

		count++;
	}
	fp = freopen(c_filename, "w", fp);
	COUNT_LOOP(count)
	{
		fprintf(fp, "%s", fileinfo[i]);
	}
	fclose(fp);
}

void write_binary_CusBuying_Record(const CusBuying_Record * data,
	const int  totalnumofCus, FILE* fp)
{
	int selection;
	selection = get_nint_sel("%s %s", 
		"Make change the file", "Do not overwrite(EXIT)");
	if (selection == 1)
	{
		fwrite(data, sizeof(data), totalnumofCus, fp);
		fclose(fp);
	}
}
// once only
void read_binary_CusBuying_Record(CusBuying_Record * data,
	FILE* fp)
{
	fread(data, sizeof(data), 1, fp);
	fclose(fp);
}
// define of num of cus
void read_binary_Previos_CusBuying_Record(CusBuying_Record * data,
	FILE* fp)
{
	fread(data, sizeof(data), NUM_OF_CUS, fp);
	fclose(fp);
}

// only this can add new employee data
// emp cannot edit 
// one time 
void admin_application_add_new(const char * fileName, 
	const Standard_Employee * data)
{
	FILE* fp;
	fp = fopen(fileName,"a");
	check_file_open(fp, fileName);
	numofemp_c++;
	if ((numofemp_c - NUMBER_OF_EMP) < 10)
	{
		puts("Data is success save in the file");
		saveStandard_Employee_admin(data, fp, numofemp_c);
	}
	else
		puts("Fill is full restart to get more space");
	fclose(fp);
}

//detail.id //detail.salary //
//allow user edit the id emp can edit 
void editerble_employee_Data_std(Standard_Employee * data)
{
	do {
		getString_many_from_user("Home Address\nPhone num\nUsermame\nPassword\nName(nick)",
			5 ,data->detail.address, data->detail.phone, data->internetA.username,
			data->internetA.password, data->internetA.detail.name);
	} while (
		(str_isalnum(data->detail.address)         == FALSE  ||
		 str_isspace( data->detail.address)        == FALSE) &&
		 str_isalpha( data->detail.phone)          == TRUE   &&
		 str_isalnum( data->internetA.password)    == FALSE  &&
		(str_isalnum(data->internetA.username)     == FALSE  ||
		 str_isspace( data->internetA.username)    == FALSE) &&
		(str_isalnum(data->internetA.detail.name)  == FALSE  ||
		 str_isspace( data->internetA.detail.name) == FALSE)
		);
	
}

int str_isalspace(const char * string)
{
	char *p = string;
	while (*p != '\0')
	{
		if (!isalpha(*p)||!isspace(*p))
		{
			return FALSE;
		}
		p++;
	}
	return TRUE;
}

// check 'a'-'z'||'A'-'Z'||'1'-'0'
int str_isalnum(const char * string)
{
	char *p = string;
	while (*p != '\0')
	{
		if (!isalpha(*p))
		{
			return FALSE;
		}
		p++;
	}
	return TRUE;
}

int str_isalpha(const char * string)
{
	char *p = string;
	while (*p != '\0')
	{
		if (!isalpha(*p))
		{
			return FALSE;
		}
		p++;
	}
	return TRUE;
}

int str_isspace(const char * string)
{
	char *p = string;
	while (*p != '\0')
	{
		if (!isspace(*p))
		{
			return FALSE;
		}
		p++;
	}
	return TRUE;
}

// Employee not allow to open anly admin can open
// Admin cannot change admin data 
// level 3 adminsor can edit evere thing
//(stdin) input
void unediterble_employee_Data_std(Standard_Employee * data)
{
	char temp[12];
	do {
		getString_many_from_user("EMPLOYEE ID\nSalary(if have)\nreal name*"
			,3 , data->detail.id, temp, data->detail.name);
		data->detail.salary = atof(temp);
		getdate2("brithday", &data->internetA.detail.birthday);
		data->internetA.detail.gender = get_any_char('f', 'm', "tl");
		getdate2("join date", &data->joinDate);
		editerble_employee_Data_std(data);
	} while (
		 str_isalnum(   data->detail.id)              == FALSE &&
		(str_isalpha(   data->detail.name)            == FALSE ||
			str_isspace(data->detail.name)            == FALSE)&&
		(ISDATE(data->internetA.detail.birthday.day, 
			    data->internetA.detail.birthday.month,
			    data->internetA.detail.birthday.year) == FALSE)&&
		(ISDATE(data->joinDate.day, 
			    data->joinDate.month, 
			    data->joinDate.year)                  == FALSE)
		);
}

void search_and_display_E_A_AL3(const char * filename)
{
	int level;
	int choise;
	Standard_Employee *data;
	data = get_file_data(filename);
	choise = get_char_nsel("%s %s %s", 
		"I am Custormer", "I am empolyee or worker", "Exit");
	if (choise == 'A')
	{

	}
	else if (choise == 'B')
	{
		level = nemployee_internet_login(&data);
		switch (level)
		{
		case TRUE:
			break;
		case ADMINSOR:
			break;
		case ADMINSOR_L3:
			break;
		}
	}
	else if (choise == 'C')
	{

	}
}

//get the array from file and return pointer
Standard_Employee *get_file_data(const char * filename)
{
	FILE *fp;
	static Standard_Employee employeeData[NUMBER_OF_EMP EXT_STORAGE];
	int numofemp;
	fp = fopen(filename, "r");
	check_file_open(fp, filename);
	COUNT_LOOP(numofemp_c)
		readfiledata_admin(&employeeData[i], fp, &numofemp);
	fclose(fp);
	return &employeeData;
}

// return no. of emp current have
// result is the number of loop
// fscanf FILE
int readfiledata_admin(Standard_Employee * data, FILE*stream ,int *lcount)
{
	int result ;
	char str[31], str2[31];

	if (fscanf(stream, "%[^:]", &str2) != EOF)
	{
		fscanf(stream, ":%d:%[^\n]\n", &result, &str2);
		fscanf(stream, "%3d.%[^:]: %[^\n]\n",
			&result, str, &data->detail.name);
		fscanf(stream, "%3d.%[^:]: %[^\n]\n",
			&result, str, &data->detail.id);
		fscanf(stream, "%3d.%[^:]: %[^\n]\n",
			&result, str, &data->detail.address);
		fscanf(stream, "%3d.%[^:]: %[^\n]\n",
			&result, str, &data->detail.phone);
		fscanf(stream, "%3d.%[^:]: %lf\n",
			&result, str, &data->detail.salary);
		fscanf(stream, "%3d.%[^:]: %d/%d/%d\n",
			&result, str, &data->joinDate.day, &data->joinDate.month,
			&data->joinDate.year);
		fscanf(stream, "%3d.%[^:]: %[^\n]\n",
			&result, str, &data->internetA.username);
		fscanf(stream, "%3d.%[^:]: %[^\n]\n",
			&result, str, &data->internetA.password);
		fscanf(stream, "%3d.%[^:]: %[^\n]\n",
			&result, str, &data->internetA.username);
		fscanf(stream, "%3d.%[^:]: %[^\n]\n",
			&result, str, &data->internetA.password);
		fscanf(stream, "%3d.%[^:]: %d/%d/%d\n",
			&result, str, &data->internetA.detail.birthday.day,
			&data->internetA.detail.birthday.month,
			&data->internetA.detail.birthday.year);
		*lcount = (result - 1);
		return TRUE;
	}
	else
		return EOF;
}

// all the previos data will be over write
// will bace on the data given make sure is array
// give correct file name
// warning given only lever 3 admin can do
void restore_all_info_Standard(const Standard_Employee*data, const char * filename)
{
	int selection = 0;
	FILE *fp;
	selection = get_nint_sel("%S %s", 
		"Corfirm to overwrite", "do not make change");
	if (selection == 1)
	{
		fp = fopen(filename, "w");
		check_file_open(fp, filename);
		for (int i = 0; i < numofemp_c; i++)
			saveStandard_Employee_admin(data, fp, i);
		fclose(fp);
	}

}

// fprintf the data in to file
// fill stdout to print out the data
void saveStandard_Employee_admin(const Standard_Employee * data, 
	FILE*stream, const int i)
{
	fprintf(stream, "==============================:%03d:==============================\n", i + 1);
	fprintf(stream, "%-3d.%-20s : %s\n", i + 1, "Name of employee", data->detail.name);
	fprintf(stream, "%-3d.%-20s : %s\n", i + 1, "Employee ID ", data->detail.id);
	fprintf(stream, "%-3d.%-20s : %s\n", i + 1, "Home address", data->detail.address);
	fprintf(stream, "%-3d.%-20s : %s\n", i + 1 , "phone number", data->detail.phone);
	fprintf(stream, "%-3d.%-20s : %.2f\n", i + 1, "Employee Salary", data->detail.salary);
	fprintf(stream, "%-3d.%-20s : %02d/%02d/%04d\n", i + 1, "join date",
		data->joinDate.day, data->joinDate.month, data->joinDate.year);
	fprintf(stream, "%-3d.%-20s : %s\n", i + 1, "Username", data->internetA.username);
	fprintf(stream, "%-3d.%-20s : %s\n", i + 1, "Password", data->internetA.password);
	fprintfiledata_cus(&data->internetA.detail, stream, i);
}

// employee / admin log in
// this function only do finding task
// must give array data
// emp want to update info is done in function
int nemployee_internet_login(const Standard_Employee *ary_data)
{
	char password[51];
	char userName[51];
	int check;
	getString_from_user("User Name used", userName);
	for (int j = 0; j < numofemp_c; j++)
	{
		if (strcmp(userName, (ary_data + j)->internetA.username) == STRCMP_SAME)
		{
			getString_from_user("your password", password);
			if (strcmp(password, ((ary_data + j)->internetA.password))
				== STRCMP_SAME)
			{
				puts("This is your data stored in the system");
				puts("check This is your name and id or not");
				saveStandard_Employee_admin((ary_data + j), stdout, -1);
				check = get_nint_sel("%s %s %s %s", "Comfrim info",
					"Update Info", "Is Adminsor", "Not me:Exit");
				if (check == 1)
					return TRUE;
				else if (check == 2)
				{

					return TRUE;
				}
				else if (check == 3)
				{
					int empLever;
					puts("Checking your admin id ....");
					COUNT_LOOP(4)
					{
						_sleep(500);
						printf(". ");
					}
					empLever = CHECK_EMP((ary_data + j)->detail.id);
					switch (empLever)
					{
					case ADMINSOR:
						printf("Adminsor Code Lever 2 welcome %s !!!", (ary_data + j)->detail.name);
						return ADMINSOR;
						break;
					case ADMINSOR_L3:
						printf("Adminsor Code Lever 3 welcome %s !!!", (ary_data + j)->detail.name);
						return ADMINSOR_L3;
						break;
					default:
						puts("your code lever is not allow do any admin change");
					}
				}
			}
		}
	}
	return FALSE;
}


// employee secrch data of employee
// secrch in file with updated data
// is resave all the data
void fsecrch_employee_data(const char*filename)
{
	int gr, count;
	Standard_Employee empper[NUMBER_OF_EMP EXT_STORAGE];
	FILE *fp;
	fp = fopen(filename, "r");
	// get the file data from file
	// current data and stored data
	COUNT_LOOP(numofemp_c)
		readfiledata_admin(&empper[i], fp, &count);

	gr = nemployee_internet_login(&empper);
	if (gr == TRUE)
		editerble_employee_Data_std(&empper[count]);
	freopen(filename, "w", fp);

	COUNT_LOOP(count)
		saveStandard_Employee_admin(&empper[i], fp, i);
	fclose(fp);
}

// customer see data of employee
// from file only
void scerch_emp_data_cus(const char *filename)
{
	int count;
	Standard_Employee emp[NUMBER_OF_EMP EXT_STORAGE];
	FILE *fp;
	fp = fopen(filename, "r");
	COUNT_LOOP(numofemp_c)
		readfiledata_admin(&emp[i], fp, &count);
	puts("This is all data of employee");
	COUNT_LOOP(numofemp_c)
		fprintfiledata_cus(&(emp[i].internetA.detail), stdout, i);
	fclose(fp);
}

void fprintfiledata_cus( Personal const* data, FILE*stream, const int i)
{
	fprintf(stream, "%-3d.%-20s : %s\n", i + 1, "Name of employee", data->name);
	fprintf(stream, "%-3d.%-20s : %c\n", i + 1, "Gender", data->gender);
	fprintf(stream, "%-3d.%-20s : %02d/%02d/%04d\n", i + 1, "Birthday date",
		data->birthday.day, data->birthday.month, data->birthday.year);
}

void menuprice(const S_ComboData * arydata)
{
	savemenuprice(arydata, stdout);
}

void savemenuprice(const S_ComboData * arydata, FILE *stream)
{
	//combo, menu and price 
	// lower char f
	menuprice_header_line(stream);
	for (int i = 0; i < NUM_OF_COMBO; i++)
		menuprice_body(arydata + i, stream);
	menuprice_end(stream);
}

void menuprice_end(FILE *stream)
{
	menuprice_header_blank(stream);
	menuprice_header_line(stream);
	menuprice_header_blank(stream);
	fprintf(stream, "| Buy Each Consecurtive 200 Ringgit Have A Change Get reward volcher |\n");
	menuprice_header_blank(stream);
	menuprice_header_line(stream);
	menuprice_header_blank(stream);
	fprintf(stream, "|                     RM :200.00 = %s%10.4f                    |\n",
		moneytype, moneyratio*(200));
	menuprice_header_blank(stream);
	menuprice_header_line(stream);
}


int selectmoney(void)
{
	//select use with country money
	printf("\t|USD\t--->1\t");
	printf("SGD\t--->2\t");
	printf("RM \t--->3\t|\n");
	printf("\t|CNY\t--->4\t");
	printf("JPY\t--->5\t");
	printf("HKD\t--->6\t|\n");
	printf("\t|INR\t--->7\t");
	printf("THB\t--->8\t");
	printf("TWD\t--->9\t|>");
	scanf(" %d", &money2);
	printf("\t====================================================\n");

	money2 = (int)tranNegetifToZero(money2);
	return money2;
}

void diarySummary(const float totalreward, const Quantities_I *data, const int noCus)
{
	savediarySummary(totalreward, data, noCus, stdout);
}

void savediarySummary(const float totalreward, const Quantities_I *data, 
	const int noCus, const FILE *stream)
{

	int    totalQA = 0;
	float  totalQ[NUM_OF_COMBO] = { 0.00 };
	float  totalSA = 0.00;
	float  tARMPay = 0.00;
	float  totalSstDayCharge = 0.00;

	changeMoney();

	// header of salary report
	fprintf(stream, "Total Number of Customers = %d\n\n", noCus);
	fprintf(stream, "Combo Sales For Today\n");
	fprintf(stream, "Combo\t\tQuantity Sold\t\t Sales Amount\n");

	//overall total of the combo
	//print final result day report
	//make programe more ajustable to allow future change
	for (int i = 0; i < NUM_OF_COMBO; i++)
	{
		//calculation combo total 
		totalSA += totalQ[i] = (data + i)->totalQ * (data + i)->info.comboPrice;
		totalQA += (data + i)->totalQ;
		fprintf(stream, "  %c  \t%13d \t\t%21.2f \n", 
			(data + i)->info.combo, (data + i)->totalQ, moneyratio*totalQ[i]);
	}

	fprintf(stream, "======      \t  =====       \t\t    =========\n");

	//calculation
	tARMPay = totalSA * (HUNDRED_PERSENT + SST);
	totalSstDayCharge = SST * totalSA;

	//total
	fprintf(stream, "TOTALS           %4d       \t\t    %9.2f\n", 
		totalQA, moneyratio*totalSA);
	fprintf(stream, "\n");
	fprintf(stream, "\t\tTOTAL SST charges    \t=%18.2f %s\n", 
		moneyratio*totalSstDayCharge, moneytype);
	fprintf(stream, "\t\tTOTAL %s collected   \t=%18.2f %s\n", 
		moneytype, moneyratio*tARMPay, moneytype);
	fprintf(stream, "\t\tTOTAL Reward %s Given\t=%18.2f %s\n", 
		moneytype, moneyratio*totalreward, moneytype);
	fprintf(stream, "\n");
	printf("\t============================\n");
	printf("\t|THANK YOU FOR YOUR SUPPORT|\n");
	printf("\t============================\n\n\n");
}

int quantities(FILE* fileOnly, char symbol, char comboT, int totalquantities, double comboP)
{
	int    quantitiess = 0;
	double total = 0.00;
	char   permentcombo = toupper(comboT);

	//print, get and calculate quantities
	print_and_savef(fileOnly, "Quantity :");
	get_int_return_valid_value(0, 100, &quantitiess);
	print_and_savef(fileOnly, "%d \n", quantitiess);
	if (symbol == '-' && quantitiess > totalquantities)
	{
		quantitiess = totalquantities;
		printf("\tThe maximun quantities of combo you can cancel is only %d\n", quantitiess);
	}
	quantitiess = (int)tranNegetifToZero(quantitiess);
	moneycalCalculationPart(money2);
	total = moneyratio * (quantitiess * comboP);
	print_and_savef(fileOnly, "\tCOMBO %c : %2d @ %s%6.2lf ",
		permentcombo, quantitiess, moneytype, moneyratio*(comboP));
	print_and_savef(fileOnly, " =\t\t\t\t%c%s%10.2f\n", symbol, moneytype, total);

	return quantitiess;

}


double tranNegetifToZero(double num)
{
	if (num >= 0 && num < 1000000)
	{
		return num;
	}
	else
	{
		return 0;
	}
}

double creditcard(FILE *fileOnly, float aPay2, float totalP)

{

	int    aPay = 0;
	int    randompic = 0;
	int    cardnumber[4];
	double result = 0.00;
	double moneyratioC = 0.00;
	char   moneytypeC[5];
	int i;

	int n[17];

	do {
		//scan card number
		printf("\nplease enter your credit or debit card\n");
		printf("xxxx xxxx xxxx xxxx must enter <space>\n\n");
		scanf("%d %d %d %d", &cardnumber[1], &cardnumber[2], &cardnumber[3], &cardnumber[4]);
		fprintf(fileOnly,"======Custormer bank cark infomation======\n");

		//only accept positive number input
		for(i=1;i<=4;i++)
		cardnumber[i] = (int)tranNegetifToZero(cardnumber[i]);

		if ((cardnumber[1] < 10000 && cardnumber[2] < 10000 && cardnumber[3] < 10000 && cardnumber[0] < 10000) || cardnumber[3] == 0 || cardnumber[2] == 0 || cardnumber[1] == 0 || cardnumber[0] == 0) {
			//break the card number to 16 digit

			n[1] = cardnumber[1] / 1000 % 10;
			n[2] = cardnumber[1] / 100 % 10;
			n[3] = cardnumber[1] / 10 % 10;
			n[4] = cardnumber[1] / 1 % 10;
			n[5] = cardnumber[2] / 1000 % 10;
			n[6] = cardnumber[2] / 100 % 10;
			n[7] = cardnumber[2] / 10 % 10;
			n[8] = cardnumber[2] / 1 % 10;
			n[9] = cardnumber[3] / 1000 % 10;
			n[10] = cardnumber[3] / 100 % 10;
			n[11] = cardnumber[3] / 10 % 10;
			n[12] = cardnumber[3] / 1 % 10;
			n[13] = cardnumber[4] / 1000 % 10;
			n[14] = cardnumber[4] / 100 % 10;
			n[15] = cardnumber[4] / 10 % 10;
			n[16] = cardnumber[4] / 1 % 10;

			//n1 is credit/debit card
			switch (n[1])
			{
			case 1: case 2: case 3: case 4: case 5:
				print_and_savef(fileOnly, " =================================================================\n");
				print_and_savef(fileOnly, " |Debitcard ");
				break;
			case 6: case 7: case 8: case 9: case 0:
				print_and_savef(fileOnly, " =================================================================\n");
				print_and_savef(fileOnly, " |Creditcard ");
				break;
			}
			//n2 is master/visa card
			switch (n[2])
			{
			case 1: case 4: case 5: case 8: case 9:
				print_and_savef(fileOnly, "(Master)\t\t\t\t\t\t |\n");
				break;
			case 2: case 3: case 6: case 7: case 0:
				print_and_savef(fileOnly, "(visa)  \t\t\t\t\t\t |\n");
				break;
			}

			//n3, n4, n5, n6, n7, n8 is detect user name and membership
			fPrintname(fileOnly, n[3],n[4],n[5],n[6],n[7]);
			
			//sum of n9, n10, n11, n12, is to pick amount of money in the card
			randompic = n[9] + n[10] + n[11] + n[12];
			switch (randompic)
			{
			case 11: case 29: case 33: case  4: case 25:
				srand(n[16]);
				aPay = ((rand() % 300) + 200);
				break;

			case  9: case 14: case  6: case  8: case 10:
				aPay = 0;
				print_and_savef(fileOnly, " |Card invilid \t\t\t\t\t\t\t |\n");
				break;

			case 22: case 24: case 26: case 28: case 20:
				srand(time(0));
				aPay = (rand() % 2999 + 1000);
				break;

			case 32: case 34: case 36: case 18: case 19:
				srand(n[1] + n[5] + n[9]);
				aPay = (rand() % 51 + 30) * 10;
				break;

			default:
				srand(n[3] + n[9] + n[15] + time(NULL));
				aPay = (rand() % 3001 + 2001);
				break;
			}
			//sum of n13, n14, n15 %9 is to detect card money use
			//maybe is from other county
			switch ((n[13] + n[14] + n[15]) % 9)
			{
			case 1:
				rewind(stdin);
				strcpy(moneytypeC, "USD ");
				moneyratioC = UNITED_STATES_DOLLAR_RATIO;
				break;
			case 5:
				rewind(stdin);
				strcpy(moneytypeC, "JPY ");
				moneyratioC = JAPAN_YEN_RATIO;
				break;
			case 6:
				rewind(stdin);
				strcpy(moneytypeC, "HKD ");
				moneyratioC = HONG_KONG_DOLLAR_RATIO;
				break;
			case 9:
				rewind(stdin);
				strcpy(moneytypeC, "TWD ");
				moneyratioC = TAIWAN_DOLLAR_RATIO;
				break;
			default:
				rewind(stdin);
				strcpy(moneytypeC, moneytype);
				moneyratioC = moneyratio;
			}
			//n1 base on the debit or credit will print different word
			switch (n[1])
			{
			case 1: case 2: case 3: case 4: case 5:
				print_and_savef(fileOnly, " |Card remain total of %6.2f%s \t\t: %10.2f %s|\n",
					moneyratio*(aPay), moneytype, moneyratioC*(aPay), moneytypeC);
				break;
			case 6: case 7: case 8: case 9: case 0:
				print_and_savef(fileOnly, " |Card still abel in   %6.2f%s \t\t: %10.2f %s|\n",
					moneyratio*(aPay), moneytype, moneyratioC*(aPay), moneytypeC);
				break;
			}
			//n14 to detect service charge
			switch (n[16])
			{

			case 2: case 4: case 6: case 8: case 0:

				if (aPay > 0)
				{
					print_and_savef(fileOnly, " |Bank 3%% service charge\t\t\t: %10.2f %s|\n", 
						moneyratioC*totalP*0.03, moneytypeC);
					totalP += totalP * (float)0.03;
				}
				else
				{
					print_and_savef(fileOnly, " |Bank 0%% service charge\t\t\t: %10.2f %s|\n", 
						totalP * 0, moneytypeC);
				}
				break;
			case 1: case 3: case 5: case 7: case 9:
				print_and_savef(fileOnly, " |Bank 0%% service charge\t\t\t: %10.2f %s|\n", 
					totalP * 0, moneytypeC);
				break;
			}
			//calculate the amount of pay/change due
			result = aPay - totalP;
			if (result>0)
			{
				result = 0;
			}
			//print the payment still need to pay
			print_and_savef(fileOnly, " |ToTal Payment Remain   \t\t\t: %10.2f %s|\n", fabs(moneyratio*(result)), moneytype);

			print_and_savef(fileOnly, " |Card\t:%d%d%d%d %d%d%d%d %d%d%d%d XXXX\t\t\t\t\t |\n", 
				n[1], n[2], n[3], n[4], n[5], n[6], n[7], n[8], n[9], n[10], n[11], n[12]);
			print_and_savef(fileOnly, " =================================================================\n\n");
		}
		else
		{
			printf("You enter the wrong format\n\n");
		}


	} while (!(cardnumber[1] < 10000 && cardnumber[2] < 10000 && cardnumber[3] < 10000 && cardnumber[4] < 10000));

	// remine for payment not enought pay how much to go
	if (result >= 0)
	{
		return 0;
	}
	else
	{
		print_and_savef(fileOnly, "Please pay %s%9.2f more amount!  \n", 
			moneytype, moneyratio*(fabs(result)));
		return result;
	}

}

void fPrintname(FILE *fileOnly, const int a, const int b, 
	const int c, const int d, const int e)
{
	//*num[0] to ensure is male or female
	//Initialize all the name used in the program as constant
	/****************************************************************
	*                                                               *
	*        NAMMING FUNCTION TO RANDOM GENERATE A NAME AND         *
	*                                                               *
	*****************************************************************/

	char source[40];
	const char* frist[2] =               {"Mr."     ,"Miss."    };
	/***************************************************************/
	rgetname(source,a, b, c, d, e);
	strcat(name[nameMODE],source);
	nameMODE = FALSE;
	print_and_savef(fileOnly, " |Name\t:%-24s\t\t\t\t |\n",name[nameMODE]);
}

void moneycalCalculationPart(int peviousmoney2)
{
	//to change money ratio and money unit only
	//money 2 is used to store money data if not change the desition
	money2 = (int)tranNegetifToZero(peviousmoney2);
	moneyratio = 0;
	switch (money2)
	{
	case 1:
		strcpy(moneytype, "USD ");
		moneyratio = UNITED_STATES_DOLLAR_RATIO;
		break;
	case 2:
		strcpy(moneytype, "SGD ");
		moneyratio = SINGAPURA_DOLLAR_RATIO;
		break;
	case 4:
		strcpy(moneytype, "CNY ");
		moneyratio = CHINA_YUEN_RATIO;
		break;
	case 5:
		strcpy(moneytype, "JPY ");
		moneyratio = JAPAN_YEN_RATIO;
		break;
	case 6:
		strcpy(moneytype, "HKD ");
		moneyratio = HONG_KONG_DOLLAR_RATIO;
		break;
	case 7:
		strcpy(moneytype, "INR ");
		moneyratio = INDIA_RUPEE_RATIO;
		break;
	case 8:
		strcpy(moneytype, "THB ");
		moneyratio = THAILAND_BAHT_RATIO;
		break;
	case 9:
		strcpy(moneytype, "TWD ");
		moneyratio = TAIWAN_DOLLAR_RATIO;
		break;
	default:
		rewind(stdin);
		strcpy(moneytype, "MYR ");
		moneyratio = 01.000000000;

	}

}

float switchOtherMethodPay(FILE* fileOnly, float amountneedtopay)
{
	int    selectionPayment = 0;
	float  aPay = 0.00;
	double cDue = 0.00;
	if (amountneedtopay > 0)
	{
		//select and change 4 type of payment 
		printf("\n\t|===============================================|\n");
		printf("\t|\tChange Other Money/Payment Method\t|\n");
		printf("\t|\t(Pay With Bankcard    ---> --1--)\t|\n");
		printf("\t|\t(Pay With Other Money ---> --2--)\t|\n");
		printf("\t|\t(Pay With Cash        ---> --3--)\t|\n");
		printf("\t|\t(Pay With Voucher     ---> --4--)\t|\n");
		printf("\t|===============================================|\n\t\t\t\t");
		scanf("%1d", &selectionPayment); 
		selectionPayment > 0 && selectionPayment < 5 ? selectionPayment : (selectionPayment = 0);
		selectionPayment = (int)tranNegetifToZero(selectionPayment);
		if (selectionPayment == 1)
		{
			cDue = creditcard(fileOnly, 0, amountneedtopay);
		}
		else if (selectionPayment == 4)
		{
			cDue = rewardVoucherPaymentSystem(fileOnly, amountneedtopay);
		}
		else
		{
			if ((selectionPayment == 2))
			{
				changeMoney();
				//came out the new total pay wit different money ratio and unit
				print_and_savef(fileOnly, "\tTOTAL TO PAY    =   \t\t\t\t\t%s %10.2f\n", 
					moneytype, moneyratio*(amountneedtopay));
			}
			print_and_savef(fileOnly, "\tAmount Paid     = \t\t\t\t\t%s ", moneytype);
			scanf("%f", &aPay);
			fprintf(fileOnly, "%.2f \n", aPay);
			aPay > 0 ? aPay : (aPay = 0);
			cDue = (tranNegetifToZero(aPay) / moneyratio) - amountneedtopay;

		}
		return (float)cDue;
	}
	else
	{
		return (float)0.00;
	}

}

float rewardlooping(FILE* fileOnly, float total)
{
	int    reward = 0;
	int    randomNum = 0;
	int    total2 = (int)total;
	float  rewardloop = 0;
	float  totalRMreward = 0;

	//calculate and print the change customer have and loop
	rewardloop = (total - (total2 % 200)) / 200;
	print_and_savef(fileOnly, "\t\tYou have %.0f change to get reward Voucher !!!\n", rewardloop);
	while (rewardloop != 0)
	{
		--rewardloop;
		randomNum = 0; reward = 0;
		randomNum = rand() % 101;
		if (randomNum % 41 == 0)
		{
			reward = 30;
			print_and_savef(fileOnly, "\t\tCongratulation get 30  Ringgit reward Voucher  !!! \n");
		}
		else if (randomNum % 21 == 0)
		{
			reward = 15;
			print_and_savef(fileOnly, "\t\tCongratulation get 15  Ringgit reward Voucher  !!! \n");
		}
		else if (randomNum % 5 == 0)
		{
			reward = 5;
			print_and_savef(fileOnly, "\t\tCongratulation get 5   Ringgit reward Voucher  !!! \n");
		}
		else
		{
			printf("\t\tregrettable !! You did not get reward Voucher  !!! \n");
		}
		totalRMreward += reward;
		randonSelectVoucherNum(fileOnly, reward);

	}

	//print the total reward the customer have
	print_and_savef(fileOnly, "\t\tyou total get RM %6.2f reward !!! (%s:%6.2f)\n", totalRMreward, moneytype, moneyratio*(totalRMreward));
	return totalRMreward;

}

void changeMoney()
{
	int   select1 = 0;
	char  othermoney = ' ';
	do {
		//print and scan use other stage money
		printf("\n\t====================================================\n");
		printf("\t|Select/Use Other State Of Money = ( Yes = Y ) -->");
		othermoney = get_any_char('a', 'z', "tl");

		if (othermoney == 'y')
		{
			selectmoney();
			moneycalCalculationPart(money2);
		}
		else
		{
			moneycalCalculationPart(money2);
		}

		printf("\t|Now you are using : %s\n", moneytype);
		printf("\t|(Enter 0 to discharge )(Enter 1 to confirm )  -->");
		get_int_value(0, 1, &select1);
		//if they do want to change will be reloop agian
	} while (select1 != 1);

	printf("\t|The Money Ratio is --> MYR : %s  =  1 ¡G%.4f \n", moneytype, moneyratio);
	printf("\t====================================================\n\n");

}

void unlimitedLoppingForPayment(FILE* fileOnly, float aPay)
{
	//amount pay 2 is change due when change due is negetif mean money not enought must while 
	//if amount pay 2 (positive value) = change due 
	//if amount pay 2 (negetive value) = payment 
	float  aPay2 = 0;

	do {
		if (aPay2 >= 0 && aPay != 0)
		{
			//this if statement only shown in frist time 
			//when while agian will mention not enought
			aPay2 = switchOtherMethodPay(fileOnly, aPay);
			aPay = 0;
		}
		else
		{
			//only perment use and shown [aPay 2 (negetive value)] in positive to cal
			//system will be while agian while aPay 2 still in negetif
			print_and_savef(fileOnly, "Amount paid is not enought Please pay more \t\t\t%s %10.2f\n",
				moneytype, fabs(moneyratio*(aPay2)));
			aPay2 = (switchOtherMethodPay(fileOnly,(float)fabs(aPay2)));
		}

	} while (aPay2<0);

	//print change due need to pay back
	print_and_savef(fileOnly,"\tChange Due      =   \t\t\t\t\t%s %10.2f\n",
		moneytype, fabs(moneyratio*(aPay2)));
}

float rewardDepentSystem(const unsigned long sixDigitRewardCode)
{
	//the voucher code that keyin will detect at here 
	//to ensure the code is correct or not 
	//if code is correct then will runt in function call
	//to get price
	float price = 0.00;
	int i;
	const unsigned long n[12] = {
		152395,290343,375203,425954,
		636342,745365,595543,192145,
		252355,322354,943642,832564 
	};

	for (i = 0; i < 12; i++)
	{
		if (sixDigitRewardCode - n[i] <= 3 && 
			sixDigitRewardCode - n[i]>0)
			price = (float)rewardCountingSystem(
				sixDigitRewardCode - n[i]);
	}

	return price;
}

void randonSelectVoucherNum(FILE *fileOnly,int rewardPrice)
{
	unsigned long rewardCode = 0;
	int randomPic = 0;
	const unsigned long storedCode[12] = {
		152395,290343,375203,425954,
		636342,745365,595543,192145,
		252355,322354,943642,832564
	};

	// if statement will simplfy the reward price
	if (rewardPrice == 30)
	{
		rewardPrice = 1;
	}
	else if (rewardPrice == 15)
	{
		rewardPrice = 2;
	}
	else if (rewardPrice == 5)
	{
		rewardPrice = 3;
	}
	else
	{
		rewardPrice = 0;
	}

	//random pick a reward code and add on to the reward price
	randomPic = rand() % 12;
	for (int i = 0; i < 12; i++)
		if (randomPic == i)
			rewardCode = storedCode[i] + rewardPrice;
	if (rewardPrice != 0)
	{
		//only get the voucher will print the reward code
		print_and_savef(fileOnly, "\t\t|===============================|\n");
		print_and_savef(fileOnly, "\t\t|Your Voucher Code is %10ul|\n", rewardCode);
		print_and_savef(fileOnly, "\t\t|===============================|\n");
	}

}

int rewardCountingSystem(const unsigned long rewardCodeMinusN)
{
	//to tranfer back the simplfy of reward price
	float rewardPrice = 0;
	if (rewardCodeMinusN == 1)
		rewardPrice = 30;
	else if (rewardCodeMinusN == 2)
		rewardPrice = 15;
	else if (rewardCodeMinusN == 3)
		rewardPrice = 05;
	else
		rewardPrice = 00;
	return (int)rewardPrice;
}

float rewardVoucherPaymentSystem(FILE *fileOnly, float amountneedtoPay)
{
	int   continueOrNot = 0;
	int   sixDigitRewardCode = 0;
	float reward = 0;

	//to make reward voucher can use for the payment
	do {
		fprintf(fileOnly, "The reward voucher is given by customer\n");
		print_and_savef(fileOnly, "Enter Your Reward Voucher Code : ");
		get_int_return_valid_value(0, 999999, &sixDigitRewardCode);
		fprintf(fileOnly, "%d", sixDigitRewardCode);
		reward = rewardDepentSystem(sixDigitRewardCode);
		print_and_savef(fileOnly, "You Have RM %6.2f Reward Voucher, That is \t\t\t%s %10.2f\n"
			, reward, moneytype, moneyratio*(reward));
		printf("Have Other Voucher Code ??? (Yes=1)(No=0)\n");
		get_int_return_valid_value(0, 1, &continueOrNot);
		amountneedtoPay = amountneedtoPay - reward;
		amountneedtoPay = TRAN_N_T_Z(amountneedtoPay);

	} while (continueOrNot == 1);

	return (-amountneedtoPay);

}
#pragma (pop)


#endif // !NO_INCLUDE_LIM_SAI_KEAT