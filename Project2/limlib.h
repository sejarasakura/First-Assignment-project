


#ifndef EX_LIM_SAI_KAT_A
#define EX_LIM_SAI_KAT_A
#pragma once

#include "c:\Users\ITSUKA KOTORI\source\repos\Tutorial Pcd2\Tutorial Pcd2\borrowStruct.h"
#ifndef INCLUDEDLIM_SAIKEAT_C

#define INCLUDEDLIM_SAIKEAT_C

#include"LimSaiKeat.c"

#endif // !INCLUDEDLIM_SAIKEAT_C


Standard_Employee *get_file_data(const char * filename);

void logo_Max_line(FILE* stream);

void logo(void);

void save_logo_main(FILE* stream);

void menuprice_header_line(FILE *stream);

void menuprice_header_blank(FILE *stream);

void menuprice_body(const S_ComboData *data, FILE *stream);

void change_cfile_function(
	const char  newchar, const char * filename);

void admin_application_add_new(const char * fileName,
	const Standard_Employee * data);

//detail.id //detail.salary //
void editerble_employee_Data_std(Standard_Employee * data);

// check 'a'-'z'||'A'-'Z'||'1'-'0'
int str_isalnum(char * string);

int str_isalspace(const char * string);
// check 'a'-'z'||'A'-'Z'||'1'-'0'
int str_isalnum(const char * string);

int str_isalpha(char * string);

int str_isspace(char * string);

// frist time employee came store thei data in side file
void unediterble_employee_Data_std(Standard_Employee * data);

void search_file_and_display_match(const char * filename);

int is_admin(const char *empcode, const char *password);

// return no. of emp current have
// result is the number of loop
int readfiledata_admin(Standard_Employee * data, FILE*stream, int *lcount);

void restore_all_info_Standard(const int numof_emp,
	const Standard_Employee*data, const char * filename);

void saveStandard_Employee_admin(const Standard_Employee * data,
	FILE*stream, const int i);

int employee_internet_login(const Standard_Employee *data);

void fsecrch_employee_data_admin(const char*filename);

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

double creditcard(FILE* fileOnly, float aPay2, float totalP);

void fPrintname(FILE* fileOnly, const int a, const int b,
	const int c, const int d, const int e);

void moneycalCalculationPart(int peviousmoney2);

float switchOtherMethodPay(FILE* fileOnly, float amountneedtopay);

float rewardlooping(FILE* fileOnly, float total);

void changeMoney();

void unlimitedLoppingForPayment(FILE* fileOnly, float aPay);

float rewardDepentSystem(const unsigned long sixDigitRewardCode);

void randonSelectVoucherNum(FILE* fileOnly, int rewardPrice);

int rewardCountingSystem(const unsigned long rewardCodeMinusN);

float rewardVoucherPaymentSystem(FILE* fileOnly, float amountneedtoPay);

void motion_logo_main(FILE* stream);

void save_logo_main(FILE* stream);

void save_logo_6(FILE* stream);

void changecolour_and_display_MODE(const char *color, const int mode);

void montion_logo_D_M(FILE* stream, const int mode);

void motion_logo_6_M(FILE* stream, const int mode);

void changecolour_and_display_STATIC_MODE(const char* color, const int mode);

void changecolour_and_clear_screen(const char * backGcolour, const char * frontcolour);


#endif