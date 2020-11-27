#include<stdio.h>	
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<time.h>
#define NOT_INCLUDE_PCD1_ASSGINMENT
#include"c:\Users\ITSUKA KOTORI\source\repos\Tutorial Pcd2\Tutorial Pcd2\funtion_call_decale.h"
#include"c:\Users\ITSUKA KOTORI\source\repos\Project2\Project2\limlib.h"
#define INCLUDED_ASSGINMENT_GLOBAL_VARIABLE
#define _PRACTICAL_2_SEM2_PCD2
#define FUNCTION_H_FILE
#include"c:\Users\ITSUKA KOTORI\source\repos\Project2\Project2\shareVariable.h"
#include"c:\Users\ITSUKA KOTORI\source\repos\Tutorial Pcd2\Tutorial Pcd2\borrowStruct.h"
#include"c:\Users\ITSUKA KOTORI\source\repos\Tutorial Pcd2\Tutorial Pcd2\minelib.h"

// Golbal variable is define at shareVariable.h

// LimSaiKeat.h is put part of define and inside mainly 
// is store define data and for declaration function

// LimSaiKeat.c is for definition


#pragma warning(disable:4996)

void main()
{
	int    numOfCus = 0;
	float  total = 0.00;
	float  totalP = 0.00;
	float  pricesst = 0.00;
	float  totalreward = 0.00;
	char   conti;
	char   symbol;
	char   comboT;
	char   cancle;
	int    count = FALSE;

	practical3_Question2_main();

	const ComboI comboData[NUM_OF_COMBO] = {
		{ 'A',COMBOA },
	{ 'B',COMBOB },
	{ 'C',COMBOC },
	{ 'D',COMBOD },
	{ 'E',COMBOE },
	{ 'F',COMBOF }
	};

	Quantities_I userI[NUM_OF_COMBO] = {
		{ 0,0,comboData[0] },
	{ 0,0,comboData[1] },
	{ 0,0,comboData[2] },
	{ 0,0,comboData[3] },
	{ 0,0,comboData[4] },
	{ 0,0,comboData[5] },
	};

	const S_ComboData menuinfo[NUM_OF_COMBO] = {
		{ "Single Combo - A\nBerger x 1 , drink x 1\n",2,comboData[0] },
	{ "Copper Combo - B\nBerger x 2 , drink x 2\n",2,comboData[1] },
	{ "Single Combo - C\nBerger x 1 , drink x 1\nChess Drumstick x 1\n",3,comboData[2] },
	{ "Copper Combo - D\nBerger x 2 , drink x 2\nChess Drumstick x 2\n",3,comboData[3] },
	{ "Family Combo - E\nBerger x 3 , drink x 3\nChess Drumstick x 2\n",3,comboData[4] },
	{ "Super Family Combo - F\nBerger x 4 , drink x 1 Bottel(2L)\nChess Drumstick x 8\n",3,comboData[5] }
	};

	Standard_Employee empData_A_PCD1[10] = {
		{ { "Tan mei mei","EMP00001","JALAN MELUR","016-641-7375",0.00 },
	{ 11,4,2016 },{ "Xiao Tan","73218324",{ "Tan mei mei",'F',{ 21,10,1999 } } } },
	{ { "Ng fong lan","EMP00017","JALAN BUNGA KEMBOJA","108-772-1982",0.00 },
	{ 21,7,2018 },{ "Mei Li","LIMMINGJUN",{ "Ng Fong Lan",'F',{ 31,8,1987 } } } },
	{ { "Lee Wen Long","EMP01017","PANDAN INDAH","03-4296-0357",0.00 },
	{ 21,9,2017 },{ "Long Kun","ilovejapan",{ "Lee Wen Long",'M',{ 1,1,2000 } } } }
	};
	logo();

	do                                          //frist do while loop
	{
		nameMODE = TRUE;
		changeMoney();
		menuprice(menuinfo, HIGHER_COMBO_A, LOWER_COMBO_A);
		++numOfCus;
		printf("Customer No: %d \n", numOfCus);	//shown num of customer
		for (int i = 0; i < NUM_OF_COMBO; i++)
			userI[i].qtyC = 0;
		symbol = ' ';
		do {									//second while
			printf("enter the COMBO writen in menu (cancle = z)(other = exit): ");
			// auto mode tolower valid range a to z
			comboT = get_valid_char('a', 'z', "tl");
			for (int i = 0; i < NUM_OF_COMBO; i++)
			{
				if (comboData[i].combo == comboT)						//combo ...
				{
					if (count != FALSE)
						symbol = '+';
					userI[i].qtyC += quantities(symbol, cancle,
						userI[i].qtyC, comboData[i].comboPrice);
					count++;
				}
				else if (comboT == 'z')
				{
					symbol = '-';
					printf("Enter The COMBO Need To Cancel: ");         //Cancle ...
					cancle = get_any_char('a', 'z', "tl");
					for (int i = 0; i < NUM_OF_COMBO; i++)
						if (comboData[i].combo == cancle)
							userI[i].qtyC -= quantities(symbol, cancle,
								userI[i].qtyC, comboData[i].comboPrice);
				}
			}

		} while (ISCOM(comboT) == TRUE || comboT == 'z'); // second do while

		count = 0;
		total = 0.00;
		totalP = 0.00;
		// total += (combo[n] * quantities[n])
		for (int i = 0; i < NUM_OF_COMBO; i++)
			total += (userI[i].qtyC*comboData[i].combo);
		pricesst = total * SST;	//total=t1+t2+t3+t4 & self service task
		totalP = (total*SST) + total;	                 //total of customer pay

		printf("\n");
		printf("\tCombo Charge    =   \t\t\t\t\t%s %10.2f\n", moneytype, moneyratio*(total));
		printf("\tAdd 10%% SST     =   \t\t\t\t\t%s %10.2f\n", moneytype, moneyratio*(pricesst));
		printf("\tTOTAL TO PAY    =   \t\t\t\t\t%s %10.2f\n", moneytype, moneyratio*(totalP));
		totalP > 0 ? totalP : (totalP = 0);
		unlimitedLoppingForPayment(totalP);

		if (total > 200)
		{
			//ecah 200 ringgit got change to get 1 loop
			totalreward = totalreward + rewardlooping(total);
		}
		//count total quantities					
		for (int i = 0; i < NUM_OF_COMBO; i++)
			userI[i].totalQ += userI[i].qtyC;

		//print thank you and ask about next customer
		printf("THANK YOU, HAVE A NICE DAY!!\n\n");
		printf("Next customer (Y=yes?): ");
		conti = get_any_char('y', 'y', "tl");
		total = 0;
	} while (conti == 'y');	//frist do while and loop

							//Dairy summary and thank you message

	system("pause");

}