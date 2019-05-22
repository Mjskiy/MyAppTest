// TEXTRPG.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <time.h>

using namespace std;


enum MAIN_MENU
{
	MM_NONE,
	MM_MAP,
	MM_STORE,
	MM_INVENTORY,
	MM_EXIT
};

enum MAP_TYPE
{
	MT_NONE,
	MT_EASY,
	MT_NORMAL,
	MT_HARD,
	MT_BACK
};

enum JOB
{
	JOB_NONE,
	JOB_KNIGHT,
	JOB_ARCHER,
	JOB_WIZARD,
	JOB_END
};

enum BATTLE
{
	BATTLE_NONE,
	BATTLE_ATTACK,
	BATTLE_BACK
};

#define NAME_SZIE 32

struct _tagInventory
{
	int iGold;
};

struct _tagPlayer
{
	char strName[NAME_SZIE];
	char strJobName[NAME_SZIE];
	JOB eJob;
	int iAttackMin;
	int iAttackMax;
	int iArmorMin;
	int iArmorMax;
	int iHP;
	int iHPMAX;
	int iMP;
	int iMPMAX;
	int iEXP;
	int iLevel;

	_tagInventory tInventory;
};

struct _tagMonster
{

	char strName[NAME_SZIE];
	int iAttackMin;
	int iAttackMax;
	int iArmorMin;
	int iArmorMax;
	int iHP;
	int iHPMAX;
	int iMP;
	int iMPMAX;
	int iEXP;
	int iLevel;
	int iGoldMin;
	int iGoldMax;
};


int main()
{

	srand((unsigned int)time(0));

	// 플레이어 정보의 설정
	_tagPlayer tPlayer = {};

	// 플레이어의 이름을 받는다
	cout << "이름 : ";
	cin.getline(tPlayer.strName, NAME_SZIE - 1);

	int iJob = JOB_NONE;
	while (true)
	{
		system("cls");
		cout << "1 기사" << endl;
		cout << "2. 궁수" << endl;
		cout << "3. 마법사" << endl;
		cout << "원하는 직업을 선택하세요 : ";
		cin >> iJob;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		else if (iJob<=JOB_NONE || iJob >= JOB_END)
		{
			iJob = JOB_NONE;
		}

		tPlayer.iLevel = 1;
		tPlayer.iEXP = 0;
		tPlayer.eJob =(JOB)iJob;
		tPlayer.tInventory.iGold = 10000;

		switch (tPlayer.eJob)
		{
		case JOB_KNIGHT:
			strcpy_s(tPlayer.strJobName, "기사");
			tPlayer.iAttackMin = 5;
			tPlayer.iAttackMax = 10;
			tPlayer.iArmorMin = 15;
			tPlayer.iArmorMax = 20;
			tPlayer.iHPMAX = 500;
			tPlayer.iHP = 500;
			tPlayer.iMP = 100;
			tPlayer.iMPMAX = 100;
			break;

		case JOB_ARCHER:
			strcpy_s(tPlayer.strJobName, "궁수");
			tPlayer.iAttackMin = 10;
			tPlayer.iAttackMax = 15;
			tPlayer.iArmorMin = 10;
			tPlayer.iArmorMax = 15;
			tPlayer.iHPMAX = 400;
			tPlayer.iHP = 400;
			tPlayer.iMP = 200;
			tPlayer.iMPMAX = 200;
			break;

		case JOB_WIZARD:
			strcpy_s(tPlayer.strJobName, "마법사");
			tPlayer.iAttackMin = 15;
			tPlayer.iAttackMax = 20;
			tPlayer.iArmorMin = 5;
			tPlayer.iArmorMax = 10;
			tPlayer.iHPMAX = 300;
			tPlayer.iHP = 300;
			tPlayer.iMP = 300;
			tPlayer.iMPMAX = 300;
			break;
		}
		break;
	}

	//몬스터를 생성한다. 
	_tagMonster tMonsterArr[MT_BACK - 1] = {};

	//고블린 생성 
	strcpy_s(tMonsterArr[0].strName, "고블린");
	tMonsterArr[0].iAttackMin = 20;
	tMonsterArr[0].iAttackMax = 30;	
	tMonsterArr[0].iArmorMin = 2;
	tMonsterArr[0].iArmorMax = 5;
	tMonsterArr[0].iHP = 100;
	tMonsterArr[0].iHPMAX = 100;
	tMonsterArr[0].iMP = 10;
	tMonsterArr[0].iMPMAX = 10;
	tMonsterArr[0].iLevel = 1;
	tMonsterArr[0].iEXP = 1000;
	tMonsterArr[0].iGoldMin = 500;
	tMonsterArr[0].iGoldMax = 1500;

	// 트롤생성
	strcpy_s(tMonsterArr[1].strName, "트롤");
	tMonsterArr[1].iAttackMin = 80;
	tMonsterArr[1].iAttackMax = 130;
	tMonsterArr[1].iArmorMin = 60;
	tMonsterArr[1].iArmorMax = 90;
	tMonsterArr[1].iHP = 2000;
	tMonsterArr[1].iHPMAX = 2000;
	tMonsterArr[1].iMP = 100;
	tMonsterArr[1].iMPMAX = 100;
	tMonsterArr[1].iLevel = 5;
	tMonsterArr[1].iEXP = 7000;
	tMonsterArr[1].iGoldMin = 6000;
	tMonsterArr[1].iGoldMax = 8000;

	// 드래곤 생성
	strcpy_s(tMonsterArr[2].strName, "드래곤");
	tMonsterArr[2].iAttackMin = 250;
	tMonsterArr[2].iAttackMax = 500;
	tMonsterArr[2].iArmorMin = 200;
	tMonsterArr[2].iArmorMax = 400;
	tMonsterArr[2].iHP = 30000;
	tMonsterArr[2].iHPMAX = 30000;
	tMonsterArr[2].iMP = 20000;
	tMonsterArr[2].iMPMAX = 20000;
	tMonsterArr[2].iLevel = 10;
	tMonsterArr[2].iEXP = 30000;
	tMonsterArr[2].iGoldMin = 20000;
	tMonsterArr[2].iGoldMax = 50000;

	//

	while (true)
	{
		system("cls");
		cout << "******************** 로비 ***********************" << endl;
		cout << "1. 맵" << endl;
		cout << "2. 상점" << endl;
		cout << "3. 가방" << endl;
		cout << "4. 종료" << endl;
		cout << "메뉴를 선택하세요 : ";
		int iMenu;
		cin >> iMenu;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}

		if (iMenu == MM_EXIT)
		{
			break;
		}


		switch (iMenu)
		{
		case MM_MAP:
			while (true)
			{
				system("cls");

				cout << "******************** 맵 ***********************" << endl;

				cout << "1 쉬움" << endl;
				cout << "2 보통" << endl;
				cout << "3 어려움" << endl;
				cout << "4 뒤로가기" << endl;
				cout << "맵을 선택하세요 : "  ;
				cin >> iMenu;

				if (cin.fail())
				{
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}

				if (iMenu == MT_BACK)
					break;

			//
				_tagMonster tMonster = tMonsterArr[iMenu-1];
				while (true)
				{
					system("cls");
					switch (iMenu)
					{
					case MT_EASY:
						cout << "******************** 쉬움 *****************************" << endl;
						break;
					case MT_NORMAL:
						cout << "******************** 보통 *****************************" << endl;

						break;
					case MT_HARD:
						cout << "******************** 어려움 *****************************" << endl;

						break;
					default:
						break;
					}

					// 플레이어의 정보를 출력
					cout << "================ Player ============================" << endl;
					cout << "이름 : " << tPlayer.strName << "\t 직업 : " << tPlayer.strJobName << endl;
					cout << "레별 : " << tPlayer.iLevel << "\t 경험치 : " << tPlayer.iEXP << endl;
					cout << "공격력 : " << tPlayer.iAttackMin <<" ~ "<< tPlayer.iAttackMax << "\t 방어력 : " << 
						tPlayer.iArmorMin <<" ~ " << tPlayer.iArmorMax << endl;
					cout << "체력 : " << tPlayer.iHP << " / " << tPlayer.iHPMAX  << "\t 마나 : " << 
						tPlayer.iMP << " / " << tPlayer.iMPMAX << endl;
					cout << "보유골드 : " << tPlayer.tInventory.iGold << " Gold " << endl << endl;

					// 몬스터 정보를 출력
					cout << "================ Monster ============================" << endl;
					cout << "이름 : " << tMonster.strName << "\t 레벨 : " << tMonster.iLevel << endl;
					
					cout << "공격력 : " << tMonster.iAttackMin << " ~ " << tMonster.iAttackMax << "\t 방어력 : " <<
						tMonster.iArmorMin << " ~ " << tMonster.iArmorMax << endl;
					cout << "체력 : " << tMonster.iHP << " / " << tMonster.iHPMAX << "\t 마나 : " <<
						tMonster.iMP << " / " << tMonster.iMPMAX << endl;
					cout << "획득 경험치 : " << tMonster.iEXP << " \t 획득골드 " << tMonster.iGoldMin << " - "
						<< tMonster.iGoldMax << endl << endl;

					// 
					cout << "1. 공격" << endl;
					cout << "2. 도망가기" << endl;
					cout << "메뉴를 선택하세요 : " ;
					cin >> iMenu;
				
					if (cin.fail())
					{
						cin.clear();
						cin.ignore(1024, '\n');
						continue;
					}

					else if (iMenu == BATTLE_BACK)
						break;

					switch (iMenu)
					{
					case BATTLE_ATTACK:
					{
						int iAttack = rand() % (tPlayer.iAttackMax - tPlayer.iAttackMin + 1) + tPlayer.iAttackMin;
						int iAmor = rand() % (tMonster.iArmorMax - tMonster.iArmorMin + 1) + tMonster.iArmorMin;
						int iDamage = iAttack - iAmor;
						iDamage = iDamage < 1 ? 1 : iDamage;

						// 몬스터의 HP를 감소시킨다. 
						tMonster.iHP -= iDamage;

						cout << tPlayer.strName << "가 " << tMonster.strName << "에게 " << iDamage << "를 입혔습니다. " << endl;

						// 몬스터가 죽었을 경우를 처리한다. 
						if (tMonster.iHP <= 0)
						{
							cout << tMonster.strName << " 사망하였습니다." << endl;
							tPlayer.iEXP += tMonster.iEXP;
							int iGold = rand() % (tMonster.iGoldMax - tMonster.iGoldMin + 1) + tMonster.iGoldMin;
							tPlayer.tInventory.iGold += iGold;
							cout << tMonster.iEXP << " 경험치를 획득하였습니다." << endl;
							cout << iGold << " 를 획득하였습니다." << endl;

							tMonster.iHP = tMonster.iHPMAX;
							tMonster.iMP = tMonster.iMPMAX;
							system("pause");
							break;
						}

						// 몬스터가 살아 있단면 플레이어를 공격한다. 

						iAttack = rand() % (tMonster.iAttackMax - tMonster.iAttackMin + 1) + tMonster.iAttackMin;
						iAmor = rand() % (tPlayer.iArmorMax - tPlayer.iArmorMin + 1) + tPlayer.iArmorMin;
						iDamage = iAttack - iAmor;
						iDamage = iDamage < 1 ? 1 : iDamage;

						// 플레이어의 HP를 감소시킨다.
						tPlayer.iHP -= iDamage;
						cout << tMonster.strName << "가 " << tPlayer.strName << "에게 " << iDamage << "를 입혔습니다. " << endl;

						//플레이어가 죽었을 경우를 처리한다. 
						if (tPlayer.iHP <= 0)
						{
							cout << tPlayer.strName << " 사망하였습니다." << endl;
							int iExp = tPlayer.iEXP * 0.1f;
							int iGold = tPlayer.tInventory.iGold * 0.1f;
							tPlayer.iEXP -= iExp;							
							tPlayer.tInventory.iGold = iGold;

							cout << iExp << " 경험치를 잃었습니다." << endl;
							cout << iGold << " 를 잃었습니다." << endl;

							// 플레이어의 HP와 MP를 회복한다.
							tPlayer.iHP = tPlayer.iHPMAX;
							tPlayer.iMP = tPlayer.iMPMAX;
						}
						system("pause");
					}
						break;
					}
				}
			}
			break;

		case MM_STORE:
			break;

		case MM_INVENTORY:
			break;

		case MM_EXIT:
			break;

		default:
			cout << "잘못 선택하였습니다" << endl;
			break;
		}


	}

    return 0;
}

