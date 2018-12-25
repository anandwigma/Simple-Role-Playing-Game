#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*created by
Anandwi Ghurran Muhajjalin Arreto (1706985911)
Farhan Prayuda Putra (1706042762)
*/

/* define struct for inventory */
struct inventory {
	char Code[5];
	char Name[100];
	char Type[10];
	int Damage;
	int Defense;
	int Health;
	int Price;
	char Desc[100];
	struct inventory  *nextPtr;
};

typedef struct inventory Inventory;
typedef Inventory *InventoryPtr;

/* define struct for shop */
struct itemList {
	char Code[5];
	char Name[100];
	char Type[10];
	int Damage;
	int Defense;
	int Health;
	int Price;
	char Desc[100];
	struct itemList  *nextPtr;
};

typedef struct itemList ItemList;
typedef ItemList *ItemListPtr;

/* Basic linked list function */
void insert(ItemListPtr *sPtr, char code[], char name[], char type[], int damage, int defense, int health, int price, char desc[]);
void insert2(InventoryPtr *sPtr, char code[], char name[], char type[], int damage, int defense, int health, int price, char desc[]);
int isEmpty(ItemListPtr sPtr);
void printList1(ItemListPtr currentPtr);
int checker(char item[], char check[]);

/* Shop function */
void DisplayWeapon(ItemListPtr currentPtr);
void DisplayGear(ItemListPtr currentPtr);
void DisplayItem(ItemListPtr currentPtr);
int search(ItemListPtr *sPtr, char code[]);
int buy(ItemListPtr *sPtr, InventoryPtr *aPtr, char code[], int *gold);

/* Inventory function */
void DisplayInventoryWeapon(InventoryPtr currentPtr);
void DisplayInventoryGear(InventoryPtr currentPtr);
void DisplayInventoryItem(InventoryPtr currentPtr);
int eqItem(InventoryPtr *sPtr, char code[]);
void deleteItem(InventoryPtr *sPtr, char code[]);

/* Battle arena function */
int battle(int CurrentFloor, int Offense, int Defense, int PlayerHealth, InventoryPtr sPtr, int *gold);
int random(int min, int max);
int useItem1(InventoryPtr *sPtr, char code[]);
int useItem2(InventoryPtr *sPtr, char code[]);
int useItem3(InventoryPtr *sPtr, char code[]);

/*story of the game*/
void story();
int instruction();



int main()
{
	story();
	ItemListPtr startPtr = NULL;
	InventoryPtr headPtr = NULL;
	int choice, mark = 0;
	int offense = 0, defense = 0, health = 100, helmet = 0, armor = 0, boot = 0;   /*player basic attribute variables declaration*/
	int floor, attribute, money = 0;	/*player adventure level and gold*/
	int *moneyPtr;		/*pointer for player gold*/
	moneyPtr = &money;
	char item[5];
	char Menu, Shop, Inv, Battle;
	insert2(&headPtr,"PS","Pulpen Sarasa","Offense",10,0,0,20,"Pulpen mahal betak punya orang");
	
	/*Game lobby*/
	Menu :
	printf("+-+-+-+-+-+-+-+-+ +-+-+-+-+-+-+-+-+-+ +-+-+-+ +-+-+-+ +-+-+-+-+ +-+-+-+-+-+-+ +-+-+-+-+-+  \n " );
	printf("|K|e|s|a|t|r|i|a| |M|a|h|a|s|i|s|w|a| |d|a|n| |B|O|P| |Y|a|n|g| |S|a|n|g|a|t| |M|a|h|a|l| \n");
	printf("+-+-+-+-+-+-+-+-+ +-+-+-+-+-+-+-+-+-+ +-+-+-+ +-+-+-+ +-+-+-+-+ +-+-+-+-+-+-+ +-+-+-+-+-+\n\n\n");
	printf(" Lobby\n");
	printf(" Health : %d\n",health);
	printf(" Gold   : %d\n\n",money);
	printf(" 1. Adventure\n 2. Inventory\n 3. Shop\n 4. Help\n 5. Exit Game\n\n");
	printf(" Choice : ");
	scanf(" %d", &choice);
	system("cls");

	switch(choice)
	{
		case 1 :
			/*The battle of the game*/
			Battle :
			printf(" Level Option :\n\n");
			for(choice = 1;choice<=10;choice++)
			{
				printf(" Level %d\n",choice);	
			}
			printf(" Choose level : ");
			scanf(" %d",&floor);
			system("cls");
			battle(floor,offense,defense,health,headPtr,moneyPtr);
			system("pause");
			system("cls");
			goto Menu;
			
		case 2 :
			/*Inventory menu*/
			Inv : 
			printf(" YOUR INVENTORY\n\n");
			printf(" 1. Weapon\n 2. Gear\n 3. Potion\n 4. Back\n\n");
			printf(" Select : ");
			scanf(" %d",&choice);
			system("cls");
			switch(choice)
			{
				case 1 :
					DisplayInventoryWeapon(headPtr);
					printf("\n\n 1. Equip weapon\n 2. Back\n Select : ");
					scanf(" %d",&choice);
					switch(choice)
					{
						case 1 :
							printf(" Weapon code : ");
							getchar();
							gets(item);
							offense = eqItem(&headPtr, item);
							printf(" Weapon equipped\n Damage = %d\n",offense);
							
						case 2 :
							system("pause");
							system("cls");
							goto Inv;
							
						default :
							printf(" Invalid choice.\n\n");
							system("pause");
							system("cls");
							goto Inv;
					}
					
				case 2 :
					DisplayInventoryGear(headPtr);
					printf("\n\n 1. Equip gear\n 2. Back\n Select : ");
					scanf(" %d",&choice);
					switch(choice)
					{
						case 1 :
							printf(" Gear code : ");
							getchar();
							gets(item);
							if(searchInventory(&headPtr, item, "Helmet") == 1)
							{
								helmet = eqItem(&headPtr, item);
								defense = helmet + armor + boot;
								printf(" Gear equipped\n Defense = %d\n",defense);
							}
							else if(searchInventory(&headPtr, item, "Armor") == 1)
							{
								armor = eqItem(&headPtr, item);
								defense = helmet + armor + boot;
								printf(" Gear equipped\n Defense = %d\n",defense);
							}
							else if(searchInventory(&headPtr, item, "Boot") == 1)
							{
								boot = eqItem(&headPtr, item);
								defense = helmet + armor + boot;
								printf(" Gear equipped\n Defense = %d\n",defense);
							}
							
							printf(" Helmet : %d\n Armor : %d\n Boot : %d\n\n",helmet,armor,boot);
							
							
						case 2 :
							system("pause");
							system("cls");
							goto Inv;
							
						default :
							printf(" Invalid choice.\n\n");
							system("pause");
							system("cls");
							goto Inv;
					}
				
				case 3 :
					DisplayInventoryItem(headPtr);
					printf("\n\n 1. Back\n Select : ");
					scanf(" %d",&choice);
					system("pause");
					system("cls");
					goto Inv;
					
				
				case 4 :
					system("cls");
					goto Menu;
					
				default :
					printf(" Invalid choice.\n\n");
					system("pause");
					system("cls");
					goto Inv;
			}
			
			
			
		case 3 :
			if(mark == 1)
			{
				goto Shop;
			}
			/*shop initialization*/
			insert(&startPtr,"WS","Wooden Sword","Offense",15,0,0,35,"Average sword for training");
			insert(&startPtr,"IS","Iron Sword","Offense",30,0,0,50,"Standard iron sword for knights");
			insert(&startPtr,"DS","Diamond Sword","Offense",45,0,0,70,"Rare sword given to those who slain the unworthy");
			insert(&startPtr,"WH","Wooden Helmet","Helmet",0,5,0,20,"Helmet made from the finest oak tree");
			insert(&startPtr,"IH","Iron Helmet","Helmet",0,10,0,35,"Battle-tested helmet for those who are worthy");
			insert(&startPtr,"DH","Dragonscaled Helmet","Helmet",0,15,0,50,"Legendary gear for the dragonslayer");
			insert(&startPtr,"WA","Wooden Armor","Armor",0,5,0,25,"Helmet made from the finest oak tree");
			insert(&startPtr,"IA","Iron Armor","Armor",0,10,0,40,"Battle-tested helmet for those who are worthy");
			insert(&startPtr,"DA","Dragonscaled Armor","Armor",0,15,0,55,"No sword can penetrate it");
			insert(&startPtr,"LB","Leather Boots","Boot",0,5,0,15,"Helmet made from the finest oak tree");
			insert(&startPtr,"IB","Iron Boots","Boot",0,10,0,25,"Battle-tested helmet for those who are worthy");
			insert(&startPtr,"AB","Achilles Boots","Boot",0,15,0,40,"Legendary boots worn by gods");
			insert(&startPtr,"SHP","Small Health Potion","Concoction",0,0,10,5,"Heals small portion of health");
			insert(&startPtr,"MHP","Medium Health Potion","Concoction",0,0,20,15,"Heals health signifiacntly");
			insert(&startPtr,"LHP","Large Health Potion","Concoction",0,0,35,20,"Gives you strength to continue the battle");		
			insert(&startPtr,"GB","Ghoul's Blood","Concoction",10,0,15,20,"Sharpen your battle instinct for 4 turns and heals you");
			insert(&startPtr,"MJ","Mandrake Juice","Concoction",0,15,15,25,"Strengten your defends for 4 turns and heals you");
			mark = 1;
			/*Shop menu*/
			Shop :
			printf(" ADVENTURER SHOP\n\n");
			printf(" 1. Weapon\n 2. Gear\n 3. Potion\n 4. Back\n\n ");
			scanf(" %d",&choice);
			system("cls");
			switch(choice)
			{
				case 1 :					
					if(!isEmpty(startPtr))
					{
						DisplayWeapon(startPtr);
						printf("Your Gold : %d\n\n",money);
						printf(" 1. Buy weapons\n 2. Back\n\n ");
						scanf(" %d",&choice);
						while(choice != 2){
							printf(" Item code : ");
							getchar();
							scanf(" %s",&item);
							choice = search(&startPtr,item);
							
											
							if(choice == 1)
							{
								choice = buy(&startPtr,&headPtr, item, moneyPtr);
								if(choice == 1)
								{
									printf(" Weapon added to inventory.\n\n");
									system("pause");
									system("cls");
								}
								else
								{
									printf(" Insufficient gold.\n\n");
									system("pause");
									system("cls");
								}
								
							}
							else
							{
								printf(" Weapon not found.\n\n", item);	
								system("pause");
								system("cls");
							}
							
							
							DisplayWeapon(startPtr);
							printf("Your Gold : %d\n\n",money);
							printf(" 1. Buy weapons\n 2. Back\n\n ");
							scanf(" %d",&choice);
						}
						system("cls");
						goto Shop;
							
					}
					else
					{
					printf(" Weapon is empty.\n\n");
					system("pause");
					system("cls");
					goto Shop;
					}
						
				case 2 :
					if(!isEmpty(startPtr))
					{
						DisplayGear(startPtr);
						printf("Your Gold : %d\n\n",money);
						printf(" 1. Buy gears\n 2. Back\n\n ");
						scanf(" %d",&choice);
						while(choice != 2){
							printf(" Gear code : ");
							getchar();
							scanf(" %s",&item);
							choice = search(&startPtr,item);
																		
							if(choice == 1)
							{
								choice = buy(&startPtr,&headPtr, item, moneyPtr);
								if(choice == 1)
								{
									printf(" Gear added to inventory.\n\n");
									system("pause");
									system("cls");
								}
								else
								{
									printf(" Insufficient gold.\n\n");
									system("pause");
									system("cls");
								}
							}
							else
							{
								printf(" Gear not found.\n\n", item);	
								system("pause");
								system("cls");
							}
							
							DisplayGear(startPtr);
							printf("Your Gold : %d\n\n",money);
							printf(" 1. Buy gears\n 2. Back\n\n ");
							scanf(" %d",&choice);
						}
						system("pause");
						system("cls");
						goto Shop;
							
					}
					else
					{
					printf(" Gear is empty.\n\n");
					system("pause");
					system("cls");
					goto Shop;
					}
					case 3 :
						if(!isEmpty(startPtr))
						{
							DisplayItem(startPtr);
							printf("Your Gold : %d\n\n",money);
							printf(" 1. Buy items\n 2. Back\n\n ");
							scanf(" %d",&choice);
							while(choice != 2){
								printf(" Item code : ");
								getchar();
								scanf(" %s",&item);
								choice = search(&startPtr,item);
								
												
								if(choice == 1)
								{
									choice = buy(&startPtr,&headPtr, item, moneyPtr);
									if(choice == 1)
									{
										printf(" Item added to inventory.\n\n");
										system("pause");
										system("cls");
									}
									
									else
									{
										printf(" Insufficient gold.\n\n");
										system("pause");
										system("cls");
									}
								}
								else
								{
									printf(" Item not found.\n\n", item);	
									system("pause");
									system("cls");
								}
								
								DisplayItem(startPtr);
								printf("Your Gold : %d\n\n",money);
								printf(" 1. Buy items\n 2. Back\n\n ");
									scanf(" %d",&choice);
							}
							system("pause");
							system("cls");
								goto Shop;
							
						}
						else
						{
						printf(" Potion is empty.\n\n");
						system("pause");
						system("cls");
						goto Shop;
						}
					
					case 4 :
						system("cls");
						goto Menu;	
						
					default :
						printf(" Invalid choice.\n\n");
						system("pause");
						system("cls");
						goto Shop;	
			}
		
		case 4 :
			/*help menu*/
			instruction();
			goto Menu;
			
		case 5 :
			/*exit from the game*/
			return 0;
			
		default :
			/*error message*/
			printf(" Invalid choice.\n\n");
			system("pause");
			system("cls");
			goto Menu;	
	}
		
		
}

/*insert item to shop*/
void  insert(ItemListPtr *sPtr, char code[], char name[], char type[], int damage, int defense, int health, int price, char desc[])
{
	ItemListPtr newPtr;
	ItemListPtr previousPtr;
	ItemListPtr currentPtr;
	
	newPtr = malloc(sizeof(ItemList));
	
	if(newPtr != NULL)
	{
		strcpy(newPtr->Code,code);
		strcpy(newPtr->Name,name);
		strcpy(newPtr->Type,type);
		strcpy(newPtr->Desc,desc);
		newPtr->Damage = damage;
		newPtr->Defense = defense;
		newPtr->Health = health;
		newPtr->Price = price;
		newPtr->nextPtr = NULL;
		
		previousPtr = NULL;
		currentPtr = *sPtr;
		
		while(currentPtr != NULL)
		{
			previousPtr = currentPtr;
			currentPtr = currentPtr->nextPtr;
		}
		
		if(previousPtr == NULL)
		{
			newPtr->nextPtr = *sPtr;
			*sPtr = newPtr;	
		}
		else
		{
			previousPtr->nextPtr = newPtr;
			newPtr->nextPtr = currentPtr;
		}	
	}
	
	else
	{
		printf("%s not inserted. No memory available\n",name);
	}
}

/*insert item to inventory from code source*/
void  insert2(InventoryPtr *sPtr, char code[], char name[], char type[], int damage, int defense, int health, int price, char desc[])
{
	InventoryPtr newPtr;
	InventoryPtr previousPtr;
	InventoryPtr currentPtr;
	
	newPtr = malloc(sizeof(ItemList));
	
	if(newPtr != NULL)
	{
		strcpy(newPtr->Code,code);
		strcpy(newPtr->Name,name);
		strcpy(newPtr->Type,type);
		strcpy(newPtr->Desc,desc);
		newPtr->Damage = damage;
		newPtr->Defense = defense;
		newPtr->Health = health;
		newPtr->Price = price;
		newPtr->nextPtr = NULL;
		
		previousPtr = NULL;
		currentPtr = *sPtr;
		
		while(currentPtr != NULL)
		{
			previousPtr = currentPtr;
			currentPtr = currentPtr->nextPtr;
		}
		
		if(previousPtr == NULL)
		{
			newPtr->nextPtr = *sPtr;
			*sPtr = newPtr;	
		}
		else
		{
			previousPtr->nextPtr = newPtr;
			newPtr->nextPtr = currentPtr;
		}	
	}
	
	else
	{
		printf("%s not inserted. No memory available\n",name);
	}
}

/*checking whether a pointer is NULL or not*/
int isEmpty(ItemListPtr sPtr)
{
	return sPtr == NULL;
}

/*remove item from inventory*/
void deleteItem(InventoryPtr *sPtr, char code[])
{
	InventoryPtr previousPtr;
	InventoryPtr currentPtr;
	InventoryPtr tempPtr;
	
	
	if(checker((*sPtr)->Code,code) == 1)
	{

			tempPtr = *sPtr;
			*sPtr = (*sPtr)->nextPtr;
			free(tempPtr);
	}
	
	else
	{
		previousPtr = *sPtr;
		currentPtr = (*sPtr)->nextPtr;
		
		while(currentPtr != NULL && checker(currentPtr->Code,code) != 1)
		{
			previousPtr = currentPtr;
			currentPtr = currentPtr->nextPtr;
		}
		
		if(currentPtr != NULL)
		{
				tempPtr = currentPtr;
				currentPtr = currentPtr->nextPtr;
				free(tempPtr);
		}
		else if(currentPtr->nextPtr == NULL)
		{
			free(currentPtr);
		}
		
	}
}


int checker(char item[], char check[])
{
	int i, result = 1;
	for (i=0;item[i] != '\0' || check[i] != '\0';i++)
	{
		if(item[i] != check[i])
		{
			result = 0;
			break;
		}
	}
	return result;
}

/*display weapons that available in the store*/
void DisplayWeapon(ItemListPtr currentPtr)
{
	if (currentPtr == NULL)
	{
		printf("No Weapon Available.\n\n");
	}
	else
	{
		while (currentPtr != NULL)
		{
			if(checker(currentPtr->Type,"Offense") == 1)
			{
				printf("Name    : %s(%s)\n",currentPtr->Name,currentPtr->Code);
				printf("Damage  : %d\n",currentPtr->Damage);
				printf("Price   : %d\n",currentPtr->Price);
				printf("About   : %s\n\n",currentPtr->Desc);
			}
			currentPtr = currentPtr->nextPtr;
		}
	}
}

/*display gears that available in the store*/
void DisplayGear(ItemListPtr currentPtr)
{
	if (currentPtr == NULL)
	{
		printf("No Gear Available.\n\n");
	}
	else
	{	
		while (currentPtr != NULL)
		{
			if(checker(currentPtr->Type,"Helmet") == 1 || checker(currentPtr->Type,"Armor") == 1 || checker(currentPtr->Type,"Boot") == 1)
			{
				printf("Name     : %s(%s)\n",currentPtr->Name,currentPtr->Code);
				printf("Defense  : %d\n",currentPtr->Defense);
				printf("Price    : %d\n",currentPtr->Price);
				printf("About    : %s\n\n",currentPtr->Desc);
			}
			currentPtr = currentPtr->nextPtr;
		}
	}
}

/*display potions that available in the store*/
void DisplayItem(ItemListPtr currentPtr)
{
	if (currentPtr == NULL)
	{
		printf("No Potion Available.\n\n");
	}
	else
	{
		while (currentPtr != NULL)
		{
			if(checker(currentPtr->Type,"Concoction") == 1)
			{
				printf("Name           : %s(%s)\n",currentPtr->Name,currentPtr->Code);
				printf("Damage Boost   : %d\n",currentPtr->Damage);
				printf("Defense Boost  : %d\n",currentPtr->Defense);
				printf("Restore Health : %d\n",currentPtr->Health);
				printf("Price          : %d\n",currentPtr->Price);
				printf("About          : %s\n\n",currentPtr->Desc);
			}
			currentPtr = currentPtr->nextPtr;
		}
	}
}

/*remove item from shop and add item to inventory*/
int buy(ItemListPtr *sPtr,InventoryPtr *aPtr, char code[], int *gold)
{
	ItemListPtr previousPtr;
	ItemListPtr currentPtr;
	ItemListPtr tempPtr;
	InventoryPtr addPtr;
	InventoryPtr beforePtr;
	InventoryPtr presentPtr;
	
	addPtr = malloc(sizeof(Inventory));
	
	if(checker((*sPtr)->Code,code) == 1)
	{
		if(*gold >= (*sPtr)->Price)
		{
		
			strcpy(addPtr->Code,(*sPtr)->Code);
			strcpy(addPtr->Name,(*sPtr)->Name);
			strcpy(addPtr->Type,(*sPtr)->Type);
			strcpy(addPtr->Desc,(*sPtr)->Desc);
			addPtr->Damage = (*sPtr)->Damage;
			addPtr->Defense = (*sPtr)->Defense;
			addPtr->Health = (*sPtr)->Health;
			addPtr->Price = (*sPtr)->Price;
		
		
			beforePtr = NULL;
			presentPtr = *aPtr;
		
			while(presentPtr != NULL)
			{
				beforePtr = presentPtr;
				presentPtr = presentPtr->nextPtr;
			}
			
			if(beforePtr == NULL)
			{
				addPtr->nextPtr = *aPtr;
				*aPtr = addPtr;	
			}
			else
			{
				beforePtr->nextPtr = addPtr;
				addPtr->nextPtr = presentPtr;
			}
			
			*gold -= (*sPtr)->Price;
			if(checker((*sPtr)->Type,"Offense") == 1 || checker((*sPtr)->Type,"Helmet") == 1 || checker((*sPtr)->Type,"Armor") == 1 || checker((*sPtr)->Type,"Boot") == 1)
			{
				tempPtr = *sPtr;
				*sPtr = (*sPtr)->nextPtr;
				free(tempPtr);
			}
			return 1;
		}
		else
		{
			return 0;
		}
	}
	
	else
	{
		previousPtr = *sPtr;
		currentPtr = (*sPtr)->nextPtr;
		

		while(currentPtr != NULL && checker(currentPtr->Code,code) != 1)
		{
			previousPtr = currentPtr;
			currentPtr = currentPtr->nextPtr;
		}
		
		if(*gold >= currentPtr->Price)
		{	
			if(currentPtr != NULL)
			{
				strcpy(addPtr->Code,currentPtr->Code);
				strcpy(addPtr->Name,currentPtr->Name);
				strcpy(addPtr->Type,currentPtr->Type);
				strcpy(addPtr->Desc,currentPtr->Desc);
				addPtr->Damage = currentPtr->Damage;
				addPtr->Defense = currentPtr->Defense;
				addPtr->Health = currentPtr->Health;
				addPtr->Price = currentPtr->Price;
			
			
				beforePtr = NULL;
				presentPtr = *aPtr;
				
				while(presentPtr != NULL)
				{
					beforePtr = presentPtr;
					presentPtr = presentPtr->nextPtr;
				}
				
				if(beforePtr == NULL)
				{
					addPtr->nextPtr = *aPtr;
						*aPtr = addPtr;	
				}
				else
				{
					beforePtr->nextPtr = addPtr;
					addPtr->nextPtr = presentPtr;
				}
				
				*gold -= currentPtr->Price;	
				if(checker(currentPtr->Type,"Offense") == 1 || checker(currentPtr->Type,"Helmet") == 1 || checker(currentPtr->Type,"Armor") == 1 || checker(currentPtr->Type,"Boot") == 1)
				{
					tempPtr = currentPtr;
					previousPtr->nextPtr = currentPtr->nextPtr;
					free(tempPtr);
				}
				return 1;
			}
		}
		else
		{
			return 0;
		}
	}
}

/*checking whether an item is in the shop or not*/
int search(ItemListPtr *sPtr, char code[])
{
	ItemListPtr previousPtr;
	ItemListPtr currentPtr;
	int result = 1;
	
	if(checker((*sPtr)->Code,code) == 1)
	{
		return result;
	}
	
	else
	{
		previousPtr = *sPtr;
		currentPtr = (*sPtr)->nextPtr;
		
		while(currentPtr != NULL && checker(currentPtr->Code,code) != 1)
		{
			previousPtr = currentPtr;
			currentPtr = currentPtr->nextPtr;
		}
		
		if(currentPtr != NULL)
		{
			return result;
		}
		
	}
	result = 0;
	return result;
}

/*checking whether an item is in the inventory or not*/
int searchInventory(InventoryPtr *sPtr, char code[], char type[])
{
	InventoryPtr previousPtr;
	InventoryPtr currentPtr;
	
	
	if(checker((*sPtr)->Code,code) == 1)
	{
		if(checker((*sPtr)->Type,type) == 1)
		{
			return 1;
		}
		
	}
	
	else
	{
		previousPtr = *sPtr;
		currentPtr = (*sPtr)->nextPtr;
		
		while(currentPtr != NULL && checker(currentPtr->Code,code) != 1)
		{
			previousPtr = currentPtr;
			currentPtr = currentPtr->nextPtr;
		}
		
		if(currentPtr != NULL)
		{
			if(checker(currentPtr->Type,type) == 1)
			{
				return 1;
			}
			else
			{
				return -1;
			}
		}
		
	}
}

/*display weapons that available in the inventory*/
void DisplayInventoryWeapon(InventoryPtr currentPtr)
{
	if (currentPtr == NULL)
	{
		printf(" No Weapon Available.\n\n");
	}
	else
	{
		while (currentPtr != NULL)
		{
			if(checker(currentPtr->Type,"Offense") == 1)
			{
				printf(" %s(%s)\n",currentPtr->Name,currentPtr->Code);
				printf(" Damage : %d\n",currentPtr->Damage);
				printf(" About  : %s\n\n",currentPtr->Desc);
			}
			currentPtr = currentPtr->nextPtr;
		}
	}
}

/*display gears that available in the inventory*/
void DisplayInventoryGear(InventoryPtr currentPtr)
{
	if (currentPtr == NULL)
	{
		printf(" No Gear Available.\n\n");
	}
	else
	{
		while (currentPtr != NULL)
		{
			if(checker(currentPtr->Type,"Helmet") == 1 || checker(currentPtr->Type,"Armor") == 1 || checker(currentPtr->Type,"Boot") == 1)
			{
				printf(" %s(%s)\n",currentPtr->Name,currentPtr->Code);
				printf(" Type    : %s\n",currentPtr->Type);
				printf(" Defense : %d\n",currentPtr->Defense);
				printf(" About   : %s\n\n",currentPtr->Desc);
			}
			currentPtr = currentPtr->nextPtr;
		}
	}
}

/*display potions that available in the inventory*/
void DisplayInventoryItem(InventoryPtr currentPtr)
{
	if (currentPtr == NULL)
	{
		printf(" No Item Available.\n\n");
	}
	else
	{
		while (currentPtr != NULL)
		{
			if(checker(currentPtr->Type,"Concoction") == 1)
			{
				printf(" %s(%s)\n",currentPtr->Name,currentPtr->Code);
				printf(" Damage Boost   : %d\n",currentPtr->Damage);
				printf(" Defense Boost  : %d\n",currentPtr->Defense);
				printf(" Restore Health : %d\n\n",currentPtr->Health);
			}
			currentPtr = currentPtr->nextPtr;
		}
		
	}
}

/*equipping weapon or gear to increase damage and defense*/
int eqItem(InventoryPtr *sPtr, char code[])
{
	InventoryPtr previousPtr;
	InventoryPtr currentPtr;
	
	
	if(checker((*sPtr)->Code,code) == 1)
	{
		if(checker((*sPtr)->Type,"Offense") == 1)
		{
			return (*sPtr)->Damage;
		}
		else if(checker((*sPtr)->Type,"Helmet") == 1 || checker((*sPtr)->Type,"Armor") == 1 || checker((*sPtr)->Type,"Boot") == 1)
		{
			return (*sPtr)->Defense;
		}
		
	}
	
	else
	{
		previousPtr = *sPtr;
		currentPtr = (*sPtr)->nextPtr;
		
		while(currentPtr != NULL && checker(currentPtr->Code,code) != 1)
		{
			previousPtr = currentPtr;
			currentPtr = currentPtr->nextPtr;
		}
		
		if(currentPtr != NULL)
		{
			if(checker(currentPtr->Type,"Offense") == 1)
			{
				return currentPtr->Damage;
			}
			else if(checker(currentPtr->Type,"Helmet") == 1 || checker(currentPtr->Type,"Armor") == 1 || checker(currentPtr->Type,"Boot") == 1)
			{
				return currentPtr->Defense;
			}
		}
		
	}
	return 0;
}

/*damage boost from using potion*/
int useItem1(InventoryPtr *sPtr, char code[])
{
	InventoryPtr previousPtr;
	InventoryPtr currentPtr;
	int attribute;
	
	if(checker((*sPtr)->Code,code) == 1)
	{

			attribute = (*sPtr)->Damage;
			return attribute;
	}
	
	else
	{
		previousPtr = *sPtr;
		currentPtr = (*sPtr)->nextPtr;
		
		while(currentPtr != NULL && checker(currentPtr->Code,code) != 1)
		{
			previousPtr = currentPtr;
			currentPtr = currentPtr->nextPtr;
		}
		
		if(currentPtr != NULL)
		{
				attribute = (currentPtr)->Damage;
				return attribute;
		}
		
	}
	return 0;
}

/*defense boost from using potion*/
int useItem2(InventoryPtr *sPtr, char code[])
{
	InventoryPtr previousPtr;
	InventoryPtr currentPtr;
	int attribute;
	
	if(checker((*sPtr)->Code,code) == 1)
	{

			attribute = (*sPtr)->Defense;
			return attribute;
	}
	
	else
	{
		previousPtr = *sPtr;
		currentPtr = (*sPtr)->nextPtr;
		
		while(currentPtr != NULL && checker(currentPtr->Code,code) != 1)
		{
			previousPtr = currentPtr;
			currentPtr = currentPtr->nextPtr;
		}
		
		if(currentPtr != NULL)
		{
				attribute = (currentPtr)->Defense;
				return attribute;
		}
		
	}
	return 0;
}

/*restore health from using potion*/
int useItem3(InventoryPtr *sPtr, char code[])
{
	InventoryPtr previousPtr;
	InventoryPtr currentPtr;
	int attribute;
	
	if(checker((*sPtr)->Code,code) == 1)
	{

			attribute = (*sPtr)->Health;
			return attribute;
	}
	
	else
	{
		previousPtr = *sPtr;
		currentPtr = (*sPtr)->nextPtr;
		
		while(currentPtr != NULL && checker(currentPtr->Code,code) != 1)
		{
			previousPtr = currentPtr;
			currentPtr = currentPtr->nextPtr;
		}
		
		if(currentPtr != NULL)
		{
				attribute = (currentPtr)->Health;
				return attribute;
		}
		
	}
	return 0;
}

/*random number generator*/
int random(int min, int max)
{
	int randnum,i;
	randnum = (rand() % (max-min))+ min;
	return randnum;
}

/*battle stage in the rpg*/
int battle(int CurrentFloor, int Offense, int Defense, int PlayerHealth, InventoryPtr sPtr, int *gold)
{
	int MonsterHealth, MinMonsterDamage, MaxMonsterDamage;
	int MinPlayerDamage = 0, MaxPlayerDamage = 5, MonsterDamage, PlayerDamage, BlockDamage, MinPlayerDefense = 0, MaxPlayerDefense = 5;
	int MinGold, MaxGold, Gold;
	int DamageBoost = 0, DefenseBoost = 0;
	int action;
	char item[5];
	char Battle, Inv;
	switch (CurrentFloor)
	{
		case 1 :
			MonsterHealth = 100;
			MinMonsterDamage = 5;
			MaxMonsterDamage = 17;
			MinGold = 5;
			MaxGold = 10;
			break;
		case 2 :
			MonsterHealth = 125;
			MinMonsterDamage = 7;
			MaxMonsterDamage = 18;
			MinGold = 15;
			MaxGold = 20;
			break;
		case 3 :
			MonsterHealth = 150;
			MinMonsterDamage = 8;
			MaxMonsterDamage = 20;
			MinGold = 20;
			MaxGold = 25;
			break;
		case 4 :
			MonsterHealth = 200;
			MinMonsterDamage = 5;
			MaxMonsterDamage = 17;
			MinGold = 30;
			MaxGold = 35;
			break;
		case 5 :
			MonsterHealth = 250;
			MinMonsterDamage = 20;
			MaxMonsterDamage = 28;
			MinGold = 35;
			MaxGold = 40;
			break;
		case 6 :
			MonsterHealth = 275;
			MinMonsterDamage = 21;
			MaxMonsterDamage = 35;
			MinGold = 45;
			MaxGold = 50;
			break;
		case 7 :
			MonsterHealth = 300;
			MinMonsterDamage = 28;
			MaxMonsterDamage = 38;
			MinGold = 50;
			MaxGold = 55;
			break;
		case 8 :
			MonsterHealth = 325;
			MinMonsterDamage = 24;
			MaxMonsterDamage = 40;
			MinGold = 60;
			MaxGold = 65;
			break;
		case 9 :
			MonsterHealth = 150;
			MinMonsterDamage = 38;
			MaxMonsterDamage = 60;
			MinGold = 65;
			MaxGold = 70;
			break;
		case 10 :
			MonsterHealth = 400;
			MinMonsterDamage = 35;
			MaxMonsterDamage = 50;
			MinGold = 75;
			MaxGold = 80;
			break;
	}
	
	
	srand(time (NULL));
	while(action != 4)
	{
		Battle :
		if(PlayerHealth <= 0)
		{
			printf(" YOU DIED\n\n");
			PlayerHealth = 100;
			return CurrentFloor;
		}
		if(MonsterHealth <= 0)
		{
			CurrentFloor += 1;
			if(CurrentFloor > 10)
			{
			 Gold = 10000000;
			 Gold = random(MinGold,MaxGold);
			*gold += Gold;
			 printf(" Selamat anda dapat melunaskan BOP untuk semester ini :)\n");
			 printf(" Semangat untuk BOP semester depannya.\n\n");	
			}
			
			else
			{
				Gold = random(MinGold,MaxGold);
				*gold += Gold;
				printf(" FLOOR CLEARED\n");
				printf(" You got %d gold.\n\n",Gold);
			}
			Offense -= DamageBoost;
			Defense -= DefenseBoost;
			return CurrentFloor;	
		}
		MonsterDamage = random(MinMonsterDamage, MaxMonsterDamage);
		if(action == 2)
		{
			MonsterDamage -= BlockDamage;
			if(MonsterDamage<0)
			{
				MonsterDamage = 0;
			}	
		}		
		printf(" Monster Health : %d\n Player Health : %d\n",MonsterHealth,PlayerHealth);
		printf(" Action\n");
		printf(" 1. Attack      2. Defend\n");
		printf(" 3. Inventory   4. Run\n");
		printf(" Action : ");
		scanf(" %d",&action);
		

		switch(action)
		{
			case 1 :
				PlayerDamage = random(MinPlayerDamage, MaxPlayerDamage) + Offense;
				MonsterHealth -= PlayerDamage;
				PlayerHealth -= MonsterDamage;
				if(PlayerHealth<0)
				{
					PlayerHealth = 0;
				}
				if(MonsterHealth<0)
				{
					MonsterHealth = 0;
				}
				printf(" You attack monster for %d damage.\n Monster health = %d\n",PlayerDamage,MonsterHealth);
				printf(" Monster attack you for %d damage.\n Your health = %d\n",MonsterDamage,PlayerHealth);
				system("pause");
				system("cls");
				goto Battle;
				
			case 2 :
				BlockDamage = random(MinPlayerDefense+(0.5)*Defense,MaxPlayerDefense+Defense);
				MonsterDamage -= BlockDamage;
				if(MonsterDamage<0)
				{
					MonsterDamage = 0;
				}
				PlayerHealth -= MonsterDamage;
				if(PlayerHealth<0)
				{
					PlayerHealth = 0;
				}
				if(MonsterHealth<0)
				{
					MonsterHealth = 0;
				}
				printf(" Monster attack you for %d damage.\n You block %d damage.\n Your health = %d\n",MonsterDamage,BlockDamage,PlayerHealth);
				system("pause");
				system("cls");
				goto Battle;
				
			case 3 :
				Inv :
					DisplayInventoryItem(sPtr);
					printf("\n\n 1. Use item\n 2. Back\n Select : ");
					scanf(" %d",&action);
					switch(action)
					{
						case 1 :
							printf(" Item code : ");
							getchar();
							gets(item);
							DamageBoost = useItem1(&sPtr,item);
							DefenseBoost = useItem2(&sPtr,item);
							Offense += DamageBoost;
							Defense += DefenseBoost;
							PlayerHealth += useItem3(&sPtr,item);
							if(PlayerHealth > 100)
							{
								PlayerHealth = 100;
							}
							printf(" You used item.\n");
							printf(" Increase damage for %d\n",useItem1(&sPtr,item));
							printf(" Increase defense for %d\n",useItem2(&sPtr,item));
							printf(" Restore health for %d points\n",useItem3(&sPtr,item));
							PlayerHealth -= MonsterDamage;
							printf(" Monster attack you for %d damage.\n Your health = %d\n",MonsterDamage,PlayerHealth);
							deleteItem(&sPtr,item);
																	
						case 2 :
							system("pause");
							system("cls");
							goto Battle;
							
						default :
							printf(" Invalid choice.\n\n");
							system("pause");
							system("cls");
							goto Inv;
					}
			
			case 4 :
				return CurrentFloor;
				
			default :
				printf(" Invalid action.\n\n");
				system("pause");
				system("cls");
				goto Battle;
		}
	}
	
}

/*intro for the rpg*/
void story()
{
	char intro[]="Di dunia dimana harga BOP kuliah semakin mahal,\nSeorang mahasiswa pergi dalam petualangan dalam mencari\nharta karun untuk membiayai kuliahnya\n";
	 int i;    
 for(i = 0; i < strlen(intro); i++)
 {
  printf("%c", intro[i]);
  Sleep(50);  
 }
 for (i=0; i<3; i++)
    {
     printf (".");
     Sleep (500);
    }
    printf("\n");
	system("pause");
	system("cls");
	char welcome[]="SELAMAT DATANG DI\n";
 for(i = 0; i < strlen(welcome); i++)
 {
  printf("%c", welcome[i]);
  Sleep(50);  
 }
 for (i=0; i<3; i++)
    {
     printf (".");
     Sleep (500);
    }
    printf("\n");
	system("pause");
	system("cls");
}

/*help menu*/
int instruction()
{
	int choice;
	printf("\n BANTUAN\n\n");
	printf(" 1. Inventory\n 2. Shop\n 3. Adventure(Battle)\n 4. Kembali ke Lobby\n\n ");
	scanf(" %d",&choice);
	switch(choice)
	{
		case 1 :
			printf(" Petunjuk Inventory\n\n");
			printf(" - Semua benda yang anda beli akan langsung dimasukkan ke dalam inventory sesuai dengan kategori barang\n");
			printf(" - Weapon dan gear dapat digunakan (equip) pada menu inventory\n");
			printf(" - Item (potion) hanya dapat digunakan pada saat adventure (battle)\n");
			printf(" - Anda diberikan senjata awalan\n\n");
			system("pause");
			system("cls");
			instruction();
			break;
		
		case 2 :
			printf(" Petunjuk Shop\n\n");
			printf(" - Anda dapat membeli senjata (weapon), gear (helmet,armor,boot), dan item (potion) pada shop bila gold anda mencukupi harga dari barang\n");
			printf(" - Senjata (weapon) dan gear (helmet,armor,boot) akan hilang dari shop bila sudah terbeli\n\n");
			system("pause");
			system("cls");
			instruction();
			break;
			
		case 3 :
			printf(" Petunjuk Adventure (Battle)\n\n");
			printf(" - Terdapat 4 pilihan aksi dalam adventure, yaitu Attack, Defend, Inventory, Run\n");
			printf(" - Attack    : menyerang monster dengan senjata yang ada gunakan\n");
			printf(" - Defend    : mengurangi damage yang anda terima dari monster selama 2 turn\n");
			printf(" - Inventory : membuka menu inventory (hanya bagian item saja)\n");
			printf(" - Run       : kembali menuju lobby\n");
			printf(" - Bila menang anda akan mendapatkan gold dan kembali ke lobby dan dapat melanjutkan ke level selanjutnya\n");
			printf(" - Bila kalah anda akan kembali ke lobby dan tetap mengulang level tersebut\n");
			printf(" - Damage Boost dan Defense Boost hanya bertahan selama 1 level\n\n");
			system("pause");
			system("cls");
			instruction();
			break;
			
		case 4 :
			system("pause");
			system("cls");
			return 0;
			
		default :
			printf(" Invalid choice.\n\n");
			system("pause");
			system("cls");
			instruction();		
	}


}

