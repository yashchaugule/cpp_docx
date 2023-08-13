//created by Yash Chaugule
#include <iostream>
#include <string>
#include <unistd.h>
#include <chrono>
#include <thread>
#include <fstream>
#include "functions.h"
#include "classes.h"

using namespace std;

bool infected = 0, blocked = 0, devMode = 0, powerful = 0;
int health = 100, mana = 100, maxHealthMana = 100;
int healingPotions = 0, manaPotions = 0, restorationPotions = 0;
int speed = 60;
int speedShow = 40;
int shieldDurability;
string shieldArmory[5] = {};
int mode = 2; //mode 0 = dev, mode 1 = easy, mode 2 = medium(default) mode 3 = hard
string easy = "\033[32mEasy Mode", normal = "\033[33mNormal Mode", hard = "\033[31mHard Mode", dev = "\033[31mD\033[33mE\033[32mV\033[36mE\033[34mL\033[35mO\033[31mP\033[33mE\033[32mR \033[36mM\033[34mO\033[35mD\033[31mE";
string difficulty = normal;

void heal(string typeOfHealing = "health", int healAmount = 100){
  if(typeOfHealing == "health"){
    infected = 0;
    healingPotions--;
    health += healAmount;
    if(health > maxHealthMana)
      health = maxHealthMana;
  }
  else if(typeOfHealing == "mana"){
    manaPotions--;
    mana += healAmount;
    if(mana > maxHealthMana)
      mana = maxHealthMana;
  }
  else if(typeOfHealing == "restore"){
    infected = 0;
    restorationPotions--;
    health += healAmount;
    mana += healAmount;
    if(mana > maxHealthMana)
      mana = maxHealthMana;
    if(health > maxHealthMana)
      health = maxHealthMana;
  }
}//end of heal()

int input(int userInput, string message = ""){
  bool repIn = false;
  while(repIn == false){
    cout << message;
    if(!(cin >> mode)){
      cin.clear();
      cin.ignore(10000, '\n');
      cout << "\033[31mTHAT IS NOT AN OPTION!" << endl;
      cont();
      system("clear");
    }
    else
      repIn = true;
  }
  return userInput;
}

void treasureBuff(string upOrDown){
  if(upOrDown == "+"){
    zombie.gold *= 1.5;
    worm.gold *= 2;
    demihuman.gold *= 1.5;
    goblin.gold *= 1.5;
    slime.gold *= 1.5;
    weakassassin.gold *= 1.5;
    wizard.gold *= 1.5;
    fGolem.gold *= 1.5;
    iGolem.gold *= 1.5;
    eGolem.gold *= 1.5;
    boss.gold *= 1.5;
  }//end of treasure up
  else if(upOrDown == "-"){
    zombie.gold /= 1.5;
    worm.gold /= 2;
    demihuman.gold /= 1.5;
    goblin.gold /= 1.5;
    slime.gold /= 1.5;
    weakassassin.gold /= 1.5;
    wizard.gold /= 1.5;
    fGolem.gold /= 1.5;
    iGolem.gold /= 1.5;
    eGolem.gold /= 1.5;
    boss.gold /= 1.5;
  }//end of treasure down
}//end of treasureBuff Function

void block(string &sheild){
  int blockChance;
  ran(blockChance, 100, 1);
  if(shieldDurability > 0){
    if (sheild == "\033[33mBronze Sheild"){
      if(blockChance <= 10){
        blocked = 1;
        bronzeS.durability--;
        shieldDurability--;
        cout << "\033[32mYou blocked the enemies attack with your " << sheild << "! Your sheild has " << shieldDurability << " durability left!" << endl;
        if(shieldDurability <= 0){
          cout << "\033[31mThe enemy has broken your sheild!\033[0m" << endl;
          shieldArmory[0] = "";
          sheild = "";
        }//end of sheild break
      }//end of bronze chance
    }//end of bronze sword if
    else if(sheild == "\033[37mSilver Sheild"){
      if (blockChance <= 20){
        blocked = 1;
        silverS.durability--;
        shieldDurability--;
        cout << "\033[32mYou blocked the enemies attack with your " << sheild << "! Your sheild has " << shieldDurability << " durability left!" << endl;
        if(shieldDurability <= 0){
          cout << "\033[31mThe enemy has broken your sheild!\033[0m" << endl;
          shieldArmory[1] = "";
          sheild = "";
        }//end of sheild break
      }//end of silver chance
    }//end of silver if
    else if(sheild == "\033[33mGold Sheild"){
      if(blockChance <= 70){
        blocked = 1;
        goldS.durability--;
        shieldDurability--;
        cout << "\033[32mYou blocked the enemies attack with your " << sheild << "! Your sheild has " << shieldDurability << " durability left!" << endl;
        if(shieldDurability <= 0){
          cout << "\033[31mThe enemy has broken your sheild!\033[0m" << endl;
          shieldArmory[2] = "";
          sheild = "";
        }//end of sheild break
      }//end of gold chance
    }//end of gold if
    else if(sheild == "\033[36mDiamond Sheild"){
      if(blockChance <= 50){
        blocked = 1;
        diamondS.durability--;
        shieldDurability--;
        cout << "\033[32mYou blocked the enemies attack with your " << sheild << "! Your sheild has " << shieldDurability << " durability left!" << endl;
        if(shieldDurability <= 0){
          cout << "\033[31mThe enemy has broken your sheild!\033[0m" << endl;
          shieldArmory[3] = "";
          sheild = "";
        }//end of sheild break
      }//end of diamond chance
    }//end of diamond if
    else if(sheild == "\033[33mCarrot Sheild"){
      blocked = 1;
      cout << "\033[32mYou blocked the enemies attack with your " << sheild << "!\nHow do you feel for using this item you filthy cheater." << endl;
    }//end of carrot sheild if
  }//end of sheild durability scan
}//end of block function

void difChange(string difChose){
  if(difChose == "easy"){
    if(difficulty == dev){
      devMode = 0;
      speed = 60;
      speedShow = 40;
      if(boss.kills == 0)
        powerful = 0;
    }
    difficulty = easy;
    mode = 1;
    worm.defaultHealth = 3;
    zombie.defaultHealth = 5;
    demihuman.defaultHealth = 12;
    weakassassin.defaultHealth = 13;
    slime.defaultHealth = 35;
    wizard.defaultHealth = 15;
    goblin.defaultHealth = 20;
    fGolem.defaultHealth = 45;
    iGolem.defaultHealth = 65;
    eGolem.defaultHealth = 85;
    boss.defaultHealth = 300;
    boss.damage = 45;
    fGolem.damage = 40;
    iGolem.damage = 25;
    eGolem.damage = 30;
    worm.damage = 1;
    zombie.damage = 2;
    demihuman.damage = 3;
    weakassassin.damage = 5;
    slime.damage = 6;
    wizard.damage = 9;
    goblin.damage = 4;
  }
  else if(difChose == "normal"){
    if(difficulty == dev){
      devMode = 0;
      speed = 60;
      speedShow = 40;
      if(boss.kills == 0)
        powerful = 0;
    }
    difficulty = normal;
    mode = 2;
    worm.defaultHealth = 5;
    worm.damage = 2;
    zombie.defaultHealth = 10;
    zombie.damage = 2;
    demihuman.defaultHealth = 17;
    demihuman.damage = 3;
    weakassassin.defaultHealth = 15;
    weakassassin.damage = 6;
    slime.defaultHealth = 50;
    slime.damage = 7;
    wizard.defaultHealth = 20;
    wizard.damage = 15;
    goblin.defaultHealth = 30;
    goblin.damage = 5;
    fGolem.defaultHealth = 80;
    fGolem.damage = 40;
    iGolem.defaultHealth = 115;
    iGolem.damage = 25;
    eGolem.defaultHealth = 150;
    eGolem.damage = 30;
    boss.defaultHealth = 350;
    boss.damage = 45;
  }
  else if(difChose == "hard"){
    if(difficulty == dev){
      devMode = 0;
      speed = 60;
      speedShow = 40;
      if(boss.kills == 0)
        powerful = 0;
    }
    difficulty = hard;
    mode = 3;
    worm.defaultHealth = 9;
    zombie.defaultHealth = 30;
    demihuman.defaultHealth = 50;
    weakassassin.defaultHealth = 45;
    slime.defaultHealth = 125;
    wizard.defaultHealth = 50;
    goblin.defaultHealth = 75;
    fGolem.defaultHealth = 140;
    iGolem.defaultHealth = 200;
    eGolem.defaultHealth = 270;
    boss.defaultHealth = 400;
    boss.damage = 45;
    fGolem.damage = 40;
    iGolem.damage = 25;
    eGolem.damage = 30;
    worm.damage = 3;
    zombie.damage = 4;
    demihuman.damage = 5;
    weakassassin.damage = 18;
    slime.damage = 10;
    wizard.damage = 22;
    goblin.damage = 10;
  }
  else if(difChose == "dev"){
    difficulty = dev;
    mode = 0;
    devMode = 1;
    speed = 0;
    speedShow = 100;
    powerful = 1;
    worm.defaultHealth = 1;
    zombie.defaultHealth = 1;
    demihuman.defaultHealth = 1;
    weakassassin.defaultHealth = 1;
    slime.defaultHealth = 1;
    wizard.defaultHealth = 1;
    goblin.defaultHealth = 1;
    fGolem.defaultHealth = 1;
    iGolem.defaultHealth = 1;
    eGolem.defaultHealth = 1;
    boss.defaultHealth = 1;
    worm.damage = 1;
    zombie.damage = 1;
    demihuman.damage = 1;
    weakassassin.damage = 1;
    slime.damage = 1;
    wizard.damage = 1;
    goblin.damage = 1;
    fGolem.damage = 1;
    iGolem.damage = 1;
    eGolem.damage = 1;
    boss.damage = 1;
  }//end of change to dev mode
}//end of difficulty change function

int main() {
  /*ITEMS*/
  const string bronzeSword = "\033[33mBronze Sword";     //bronze sword does 3 damage    | Starting wepon
  const string silverSword = "\033[37mSilver Sword";     //Silver sword does 5 damage    | Costs 50 gold
  const string goldSword = "\033[33mGold Sword";         //Gold sword does 7 damage      | Costs 100 gold
  const string diamondSword = "\033[36mDiamond Sword";   //Diamond sword does 10 damage  | Costs 250 gold
  const string bronzeSheild = "\033[33mBronze Sheild";   //Bronze has 10% block chance and 15 durability  | Costs 30 gold
  const string silverSheild = "\033[37mSilver Sheild";   //Silver has 20% block chance and 25 durability | Costs 45 gold
  const string goldSheild = "\033[33mGold Sheild";       //Golden has 70% block chance and 10 durability  | Costs 50 gold
  const string diamondSheild = "\033[36mDiamond Sheild"; //Diamond has 50% block chance and 35 durability| Costs 70 gold
  const string rebirth = "\033[32mTalisman of Rebirth";  //Revives player with 10 health
  const string treasure = "\033[33mTaliman of Treasure"; //Earn x1.5 gold
  const string destruction = "\033[31mTalisman of Destruction"; //do double damage
  const string emblem = "\033[35mAvengers Emblem";       //do double damage, get x1.5 gold, increase max health and mana to 200
  const string bronzeStaff = "\033[33mBronze Staff";     //does 12 damage  |  costs 50 fragments  |  Uses 5 mana
  const string silverStaff = "\033[37mSilver Staff";     //does 14 damage  |  costs 100 fragments |  Uses 10 mana
  const string goldStaff = "\033[33mGold Staff";         //does 16 damage  |  costs 150 fragments |  Uses 15 mana
  const string diamondStaff = "\033[36mDiamond Staff";   //does 20 damage  |  costs 200 fragments |  Uses 20 mana
  string swordArmory[5] = {bronzeSword}, manaWeponArmory[4];
  bool skullKey = 0, talismanOfRebirth = 0, talismanOfDestruction = 0, talismanOfTreasure = 0, avengerEmblem = 0;

  /*DEVELOPER ITEMS*/
  string carrotSmasher = "\033[33mCarrot Smasher";  //Carrot Smasher does 900 damage
  string carrotShield = "\033[33mCarrot Sheild";    //Carrot Sheild has 100% block chance and infinite durability

  /*PLAYER STATS*/
  int damage = 3;
  int manaDamage = 0;
  int manaUsage = 0;
  int manaFragments = 0;
  int gold = 0;
  string equippedSword = swordArmory[0];
  string equippedTalisman;
  string equippedManaWepon;
  string equippedShield;
  
  /*MOVEMENT/SWITCH VARIABLES*/
  int whereTo, shopChoice, equipChoice, armoryChoice, fightRun, settingsChoice, moveToBoss = 0, healOrGo;
  string moveToFight = "";

  /*OTHERS*/
  string cheatCode;
	int cheatNum;
  string userName;
  int randomEnemy = 0, randomTalisman = 0, randomFragments = 0;
  int missChance = 0;
  bool repIn = false;
  int tempSpeed = 35;
	int chestsOpened = 0, cratesOpened = 0;

  GAMEINTRO:
  system("clear");
  slow_print("\033[36mHello and welcome to \033[31mThe Dungeon Game!\n\n\033[34mWhat is your name?: ", speed);
  printf("\033[31m");
  getline(cin, userName, '\n');

  input(mode, "\033[36mWould you like to play in \033[31mHard Mode, \033[33mRegular Mode, \033[36mor \033[32mEasy Mode\n\033[0m[1] \033[32mEasy   \033[0m[2] \033[33mRegular   \033[0m[3] \033[31mHard\n\033[34m> \033[32m");
  if(mode == 1)
    difChange("easy");
  else if(mode == 2)
    difChange("normal");
  else if(mode == 3){
    difChange("hard");
    healingPotions = 1;
  }
  else if(mode == 0)
    difChange("dev");
  
  else{
    slow_print("\033[31mTHAT IS NOT AN OPTION!", speed);
    cont("\n");
    system("clear");
    goto GAMEINTRO;
  }
  slow_print("\033[36mWould you like to know how to play the game?\n\033[32m[1] Yes  \033[31m[2] No\n\033[31m> \033[32m", speed);
  cin >> whereTo;
  if(whereTo == 1){
    system("clear");
    slow_print("\033[36mOne of the most important things to note is that you can enter the number 0 to exit out of any area that you might find yourself stuck in besides fights. Remember that because its important.\n", tempSpeed);
    cont();
    slow_print("\033[36mAlthough there is no end goal to this game as of now, you can actually defeat a boss. In order to progress through the game you must first go to \033[37mThe Abandoned Town\033[36m. After killing enough enemies you will have recieved some gold. You can use this gold to buy things at \033[33mThe Shopkeepers Tavern\033[36m. In here you can buy better swords, shields, healing potions, and a special talisman. Any items you purchase will have to be equipped before you can use them in \033[31mThe Armory\033[36m. After you have gotten good enough gear, you can move on to \033[30mThe Dungeon\033[36m. In here, the enemies will be a lot stronger. If you open a chest in the \033[30mThe Dungeon\033[36m, you can get \033[37mThe Skull Key\033[36m. You use this to fight the boss. After you beat the boss, the difficulty will increase by 1 unless it is in hard mode. You can change things like gamespeed in the settings, and if you fork the repl, you can save your stats to a file(wont save progress).", tempSpeed);
    cont("\n");
  }
  GAMESTART:
  for(bool gameEnd = 0; gameEnd == 0;){
    system("clear");
    if(gold < 0)
      gold = 0;
    if(healingPotions < 0)
      healingPotions = 0;
    if(manaPotions < 0)
      manaPotions = 0;
    if(manaFragments < 0)
      manaFragments = 0;
    if(health <= 0){
      DEATH:
      system("clear");
      if(equippedTalisman == rebirth){
        slow_print("\033[32mYou feel your life draining from your body, but your Talisman of Rebirth heals you and returns you to 10 health!\n", speed);
        cont();
        health = 10;
        talismanOfRebirth = 0;
        equippedTalisman = "";
        goto GAMESTART;
      }
			else{
				printf("\033[31mYOU DIED!\033[0m");
				return 0;
			}
    }//end if die
    system("clear");
    if(equippedTalisman == destruction || equippedTalisman == emblem){
      manaDamage *= 1.5;
      damage *= 2;
    }
    RETRY:
    slow_print("\033[31mWelcome " + userName, speed);
    cout << "\n\033[31mDifficulty: " << difficulty << "\n\033[32mHealth: " << health << "\n\033[36mMana: " << mana << "\n\033[34mSword: " << equippedSword << "\n\033[33mSword's Damage: " << damage << "\n\033[34mMana Wepon: " << equippedManaWepon << "\n\033[33mMana Weapon's Damage: " << manaDamage << "\n\033[36mSheild: " << equippedShield << "\n\033[34mSheild Durability: "<< shieldDurability << "\n\033[33mTalisman: " << equippedTalisman << "\n\033[33mGold: " << gold << "\n\033[32mInfection Status: " << infected << "\n\033[35mWhere would you like to travel?\n\t\033[0m1)\033[33m The Shopkeepers Tavern\n\t\033[0m2)\033[30m The dungeons\n\t\033[0m3)\033[37m The Abandoned Town\n\t4)\033[31m The Armory\n\t\033[0m5) \033[33mThe forgery\n\t\033[0m6)\033[36m Statistics\n\t\033[0m7)\033[32m Use potion\n\t\033[0m8) \033[31mAdmin comands/cheat codes\n\t\033[0m9) \033[37mSettings" << endl;
    if(equippedTalisman == destruction || equippedTalisman == emblem){
      manaDamage /= 1.5;
      damage /= 2;
    }
    if(skullKey)
      cout << "\033[0m\t10) \033[31mValley Of Death" << endl;
    cout << "\033[0mPlease enter choice here: \033[33m";

    if(!(cin >> whereTo)){
      cin.clear();
      cin.ignore(10000, '\n');
      cout << "\033[31mTHAT IS NOT AN OPTION!" << endl;
      cont();
      system("clear");
      goto RETRY;
    }//end of input and check

    system("clear");
    switch(whereTo){
      case 1:
        SHOP:
        if(gold < 0)
          gold = 0;
        slow_print("\033[33mWelcome to the Shopkeepers Tavern!\n", speed);
        cout << "\033[33mYour Gold: " << gold << endl;
        cout << "\n\033[34mWhich Item would you like to buy?" << endl;
        cout << "\t\033[37m1) Silver sword\n\t\t\033[33mcost - 50 gold\n\t\t\033[31mdoes 5 damage\n\t\033[33m2) Gold Sword\n\t\t\033[33mcost - 100 gold\n\t\t\033[31mdoes 7 damage\n\t\033[34m3) Diamond Sword\n\t\t\033[33mcost - 250 gold\n\t\t\033[31mdoes 10 damage\n\t\033[32m4) Healing Potion\033[0m\n\t\t\033[33mcost - 40 gold\n\t\t\033[31mHeals health back to full\n\t\033[33m5) Bronze Sheild\n\t\tcost - 30 gold\n\t\t\033[31mBlock Chance: 10%\n\t\t\033[36mDurability: 15\n\t\033[37m6) Silver Sheild\n\t\t\033[33mcost - 45 gold\n\t\t\033[31mBlock Chance: 20%\n\t\t\033[36mDurability: 25\n\t\033[33m7) Gold Sheild\n\t\tcost - 50 gold\n\t\t\033[31mBlock Chance: 70%\n\t\t\033[36mDurability: 10\n\t8) Diamond Sheild\n\t\t\033[33mcost - 70\n\t\t\033[31mBlock Chance: 50%\n\t\t\033[36mDurability: 35\n\t\033[33m9) Talisman of Rebirth\n\t\t\033[33mcost - 200 gold\n\t\t\033[32mRevives you once after death\n\t\033[0m0) Return to Main Menu\nPlease enter choice here:  \033[34m";
        if(!(cin >> shopChoice)){
          cin.clear();
          cin.ignore(10000, '\n');
          cout << "\033[31mTHAT IS NOT AN OPTION!" << endl;
          cont();
          system("clear");
          goto SHOP;
        }
        cout << "\033[0m";

        switch(shopChoice){
          case 1:
            if((gold >= 50 && swordArmory[1] != silverSword) || devMode){
              cout << "\033[32m You have purchased the \033[37mSilver Sword!\033[0m" << endl;
              gold -= 50;
              swordArmory[1] = silverSword;
              cont();
              system("clear");
              goto SHOP;
            }//end of purchase silver sword
            else if(swordArmory[1] == silverSword){
              cout << "\033[31m You already own this weapon!\033[0m" << endl;
              cont();
              system("clear");
              goto SHOP;
            }//end of silver already owned
            else if (gold < 50 && !devMode){
              cout << "\033[31m You dont have enough gold to purchase this item!\033[0m" << endl;
              cont();
              system("clear");
              goto SHOP;
            }//end of not enough for silver
          break;
          case 2:
            if((gold >= 100 && swordArmory[2] != goldSword) || devMode){
              cout << "\033[32m You have purchased the Gold Sword!\033[0m" << endl;
              gold -= 100;
              swordArmory[2] = goldSword;
              cont();
              system("clear");
              goto SHOP;
            }//end of purchase gold sword
            else if(swordArmory[2] == goldSword){
              cout << "\033[31m You already own this weapon!\033[0m" << endl;
              cont();
              system("clear");
              goto SHOP;
            }//end of gold already owned
            else if(gold < 100 && !devMode){
              cout << "\033[31m You dont have enough gold to purchase this item!\033[0m" << endl;
              cont();
              system("clear");
              goto SHOP;
            }//end of not enough for gold
          break;
          case 3:
            if((gold >= 250 && swordArmory[3] != diamondSword) || devMode){
              cout << "\033[32m You have purchased the Diamond Sword!\033[0m" << endl;
              gold -= 250;
              swordArmory[3] = diamondSword;
              cont();
              system("clear");
              goto SHOP;
            }//end of purchase diamond sword
            else if (swordArmory[3] == diamondSword){
              cout << "\033[31m You already own this weapon!\033[0m" << endl;
              cont();
              system("clear");
              goto SHOP;
            }//end of diamond already owned
            else if(gold < 250 && !devMode){
              cout << "\033[31m You dont have enough gold to purchase this item!\033[0m" << endl;
              cont();
              system("clear");
              goto SHOP;
            }//end of not enough for diamond
          break;
          case 4:
            if((gold >= 40) || devMode){
              cout << "\033[32m You have purchased 1 healing potion!\033[32m" << endl;
              gold -= 40;
              healingPotions++;
              cont();
              system("clear");
              goto SHOP;
            }//end of healingPotions purchased
            else if(!devMode){
              cout << "\033[31m You dont have enough gold for this!" << endl;
              cont();
              system("clear");
              goto SHOP;
            }//end of not enough for potion
          break;
          case 5:
            if((gold >= bronzeS.cost && shieldArmory[0] != bronzeSheild) || devMode){
              cout << "\033[32m You have purchased the \033[33mBronze Sheild\033[32m!\033[0m" << endl;
              gold -= 30;
              shieldArmory[0] = bronzeSheild;
              bronzeS.durability = bronzeS.defaultDura;
              cont();
              system("clear");
              goto SHOP;
            }//end of purchase bronze sheild
            else if (shieldArmory[0] == bronzeSheild){
              cout << "\033[31m You already own this sheild!\033[0m" << endl;
              cont();
              system("clear");
              goto SHOP;
            }//end of bronze sheild already owned
            else if(gold < bronzeS.cost && !devMode){
              cout << "\033[31m You dont have enough gold to purchase this item!\033[0m" << endl;
              cont();
              system("clear");
              goto SHOP;
            }//end of not enough for bronze sheild
          case 6:
            if((gold >= silverS.cost && shieldArmory[1] != silverSheild) || devMode){
              cout << "\033[32m You have purchased the \033[37m Silver Sheild\033[32m!" << endl;
              gold -= silverS.cost;
              shieldArmory[1] = silverSheild;
              silverS.durability = silverS.defaultDura;
              cont();
              system("clear");
              goto SHOP;
            }//end of purchase silver sheild
            else if(shieldArmory[1] == silverSheild){
              cout << "\033[31m You already own this sheild!" << endl;
              cont();
              system("clear");
              goto SHOP;
            }//end of silver sheild already owned
            else if(gold < silverS.cost && !devMode){
              cout << "\033[31m You dont have enough gold to purchase this item!" << endl;
              cont();
              system("clear");
              goto SHOP;
            }//end of not enough for silver sheild
          break;
          case 7:
            if((gold >= goldS.cost && shieldArmory[2] != goldSheild) || devMode){
              cout << "\033[32m You have purchased the \033[33mgold sheild\033[32m!" << endl;
              gold -= goldS.cost;
              shieldArmory[2] = goldSheild;
              goldS.durability = goldS.defaultDura;
              cont();
              system("clear");
              goto SHOP;
            }//end of purchase gold sheild
            else if(shieldArmory[2] == goldSheild){
              cout << "\033[31m You already own this sheild!" << endl;
              cont();
              system("clear");
              goto SHOP;
            }//end of gold sheild already owned
            else if(gold < goldS.cost && !devMode){
              cout << "\033[31m You dont have enough gold for this item!" << endl;
              cont();
              system("clear");
              goto SHOP;
            }//end of not enough for gold sheild
          break;
          case 8:
            if((gold >= diamondS.cost && shieldArmory[3] != diamondSheild) || devMode){
              cout << "\033[32m You have purchased the \033[36mDiamond Sheild\033[32m!" << endl;
              gold -= diamondS.cost;
              shieldArmory[3] = diamondSheild;
              diamondS.durability = diamondS.defaultDura;
              cont();
              system("clear");
              goto SHOP;
            }//end of purchase diamond sheild
            else if(shieldArmory[3] == diamondSheild){
              cout << "\033[31m You already own this sheild!" << endl;
              cont();
              system("clear");
              goto SHOP;
            }//end of diamond sheild already owned
            else if(gold < diamondS.cost && !devMode){
              cout << "\033[31m You do not have enough gold to purchase this item!" << endl;
              cont();
              system("clear");
              goto SHOP;
            }//end of not enough for diamond sheild
          break;
          case 9:
            if((gold >= 200 && !talismanOfRebirth) || devMode){
              gold -= 200;
              talismanOfRebirth = 1;
              cout << "\033[32m You have purchased the " << rebirth << "\033[32m!" << endl;
              cont();
              system("clear");
              goto SHOP;
            }
            else if(talismanOfRebirth){
              cout << "\033[31m You already own this talisman!" << endl;
              cont();
              system("clear");
              goto SHOP;
            }
            else if(gold < 200 && !devMode){
              cout << "\033[31m You dont have enough gold for this item!" << endl;
              cont();
              system("clear");
              goto SHOP;
            }
          break;
        }//end of shop switch
      break;
      case 2:
      /**********DUNGEON**********/
        goblin.health = goblin.defaultHealth;
        wizard.health = wizard.defaultHealth;
        slime.health = slime.defaultHealth;
        weakassassin.health = weakassassin.defaultHealth;
        ran(randomEnemy, 10, 1);// 3 out of 10 times you will get goblin, 3 out of 10 times you will get wizard, 2 out of 10 times you will get a slime, 1 out of 10 times you will get assassin, 1 out of 10 times you will get chest

        if(randomEnemy == 8 || randomEnemy == 9){
          cout << "\033[36mYou have \033[32m" << health << " health" << endl;
          cout << "\033[36mYou have \033[34m" << mana << " mana" << endl;
          cout << "\033[31mEnemy health: " << slime.health << endl;
          slow_print("\033[36mYour walking down a hall when suddenly you see slime oozing from behind a door. The slime oozes out to fight you! It looks like it has a chest inside of it.", speed);
          system("clear");
          while(slime.health > 0){
            SFIGHT:
            cout << "\033[36mYou have \033[32m" << health << " health" << endl;
            cout << "\033[36mYou have \033[34m" << mana << " mana" << endl;
            cout << "\033[31mEnemy health: " << slime.health << endl;
            cout << "\033[36mYour walking down a hall when suddenly you see slime oozing from behind a door. The slime oozes out to fight you! It looks like it has a chest inside of it." << endl;
            cout << "Do you want to \033[31m[1] Melee Attack\033[0m or \033[34m[2]Mana attack\033[0m or \033[33m[3] Run\033[0m or \033[32m[4] Use Potion: ";
            if(!(cin >> fightRun)){
              cin.clear();
              cin.ignore(10000, '\n');
              cout << "\033[31mTHAT IS NOT AN OPTION!" << endl;
              cont();
              system("clear");
              goto SFIGHT;
            }

            if(fightRun == 4){
              system("clear");
              moveToFight = "slime";
              goto POTIONS;
            }//end of use healing potion slime
            
            else if(fightRun == 3){
              slow_print("\033[36mThe Slime jumps on you and makes you all \033[32mslimey\033[36m, dealing \033[31m10 damage! You can no longer run!\033[0m\n", speed);
              health -= 10;
              cont();
              if(health <= 0)
                goto DEATH;
              system("clear");
            }//end of run from slime

            else if(fightRun == 2){
              if(equippedManaWepon == ""){
                slow_print("\033[31mYou do not have a mana weapon equipped!", speed);
                cont("\n");
                system("clear");
              }//end of no mana wepon
              else{
                if(equippedTalisman == destruction || equippedTalisman == emblem)
                  manaDamage *= 1.5;
                if(infected)
                  slime.damage *= 2;
                block(equippedShield);
                if(!blocked){
                  health -= slime.damage;
                  cout << "\033[31mThe \033[32mSlime splashed you with its slime\033[31m, doing " << slime.damage << " damage, and leaving you at \033[32m" << health << " health!\033[0m\n" << endl;
                }//end of slime attack you
                if(mana >= manaUsage){
                  slime.health -= manaDamage;
                  mana -= manaUsage;
                  cout << "\033[32mYou shot the Slime with your " << equippedManaWepon << "\033[32m, dealing \033[31m" << manaDamage << " damage \033[32mand using \033[34m" << manaUsage << " mana\033[32m!" << endl;
                }
                else
                  slow_print("\033[31mYOU DONT HAVE ENOUGH MANA TO ATTACK\n", speed);
                if(equippedTalisman == destruction || equippedTalisman == emblem)
                  manaDamage /= 1.5;
                if(infected)
                  slime.damage /= 2;
                blocked = 0;
                cont();
                system("clear");
                if(health <= 0)
                  goto DEATH;
              }//end of have mana wepon
            }//end of mana attack used
            
            else if(fightRun == 1){
              if(equippedTalisman == destruction || equippedTalisman == emblem)
                damage *= 2;
              if(infected)
                slime.damage *= 2;
              slime.health -= damage;
              block(equippedShield);
              if(!blocked){
                health -= slime.damage;
                cout << "\033[31mThe \033[32mSlime splashed you with its slime\033[31m, doing " << slime.damage << " damage, and leaving you at \033[32m" << health << " health!\033[0m\n" << endl;
              }
              cout << "\033[32mYou did \033[31m" << damage << " damage \033[32mto the Slime, leaving it at " << slime.health << " health" << endl;
              blocked = 0;
              if(equippedTalisman == destruction || equippedTalisman == emblem)
                damage /= 2;
              if(infected)
                slime.damage /= 2;
              cont();
              system("clear");
              if(health <= 0)
                goto DEATH;
            }//end of fight slime
            else{
              cout << "\033[31mTHATS NOT AN OPTION!\033[0m" << endl;
              cont();
              system("clear");
              goto SFIGHT;
            }//end of wrong option
          }//end of slime fight loop
          slime.kills++;
          gold += slime.gold;
          cout << "\033[32mYou have defeated the slime!" << endl;
          cout << "You gained \033[33m" << slime.gold << " gold!\033[0m" << endl;
          cont();
        }//end of slime fight

        if(randomEnemy == 4){
          cout << "\033[36mYou have \033[32m" << health << " health" << endl;
          cout << "\033[36mYou have \033[34m" << mana << " mana" << endl;
          cout << "\033[31mEnemy health: " << weakassassin.health << endl;
          slow_print("\033[36mWhile walking you are surprised with a glowing portal which an assassin emerges from. The assassin motions you over for a fight!", speed);
          system("clear");
          while(weakassassin.health > 0){
            WAFIGHT:
            cout << "\033[36mYou have \033[32m" << health << " health" << endl;
            cout << "\033[36mYou have \033[34m" << mana << " mana" << endl;
            cout << "\033[31mEnemy health: " << weakassassin.health << endl;
            cout << "\033[36mWhile walking you are surprised with a glowing portal which an assassin emerges from. The assassin motions you over for a fight!" << endl;
            cout << "Do you want to \033[31m[1] Melee Attack\033[0m or \033[34m[2]Mana attack\033[0m or \033[33m[3] Run\033[0m or \033[32m[4] Use Potion: ";
            if(!(cin >> fightRun)){
              cin.clear();
              cin.ignore(10000, '\n');
              cout << "\033[31mTHAT IS NOT AN OPTION!" << endl;
              cont();
              system("clear");
              goto WAFIGHT;
            }

            if(fightRun == 4){
              system("clear");
              moveToFight = "assassin";
              goto POTIONS;
            }//end of use potion
                      
            else if(fightRun == 3){
              slow_print("\033[31mAs you try to run, the \033[37mWeak Assassin\033[31m does his final attack, SLICE AND DICE, dealing 12 damage!\n", speed);
              health -= 12;
              cont();
              if(health <= 0)
                goto DEATH;
              system("clear");
              goto GAMESTART;
            }//end of run

            else if(fightRun == 2){
              if(equippedManaWepon == ""){
                slow_print("\033[31mYou do not have a mana weapon equipped!", speed);
                cont("\n");
                system("clear");
              }//end of no mana wepon
              else{
                if(equippedTalisman == destruction || equippedTalisman == emblem)
                manaDamage *= 1.5;
                if(infected)
                  weakassassin.damage *= 2;
                block(equippedShield);
                if(!blocked){
                  health -= weakassassin.damage;
                  cout << "\n\033[31mThe Weak Assassin sliced you and did " << weakassassin.damage << " damage, leaving you at \033[32m" << health << " health!\033[0m" << endl;
                }//end of enemy attack you
                if(mana >= manaUsage){
                  weakassassin.health -= manaDamage;
                  mana -= manaUsage;
                  cout << "\033[32mYou shot the \033[37mWeak Assassin\033[32m with your " << equippedManaWepon << "\033[32m, dealing \033[31m" << manaDamage << " damage \033[32mand using \033[34m" << manaUsage << " mana\033[32m!" << endl;
                }//end of use mana wepon
                else
                  slow_print("\033[31mYOU DONT HAVE ENOUGH MANA TO ATTACK\n", speed);
                if(equippedTalisman == destruction || equippedTalisman == emblem)
                manaDamage /= 1.5;
                if(infected)
                  weakassassin.damage /= 2;
                blocked = 0;
                cont();
                system("clear");
                if(health <= 0)
                  goto DEATH;
              }//end of have mana wepon if
            }//end of use mana attack
                      
            else if(fightRun == 1){
              if(equippedTalisman == destruction || equippedTalisman == emblem)
                damage *= 2;
              if(infected)
                weakassassin.damage *= 2;
              weakassassin.health -= damage;
              block(equippedShield);
              if(!blocked){
                health -= weakassassin.damage;
                cout << "\033[37mThe Weak Assassin\033[31m attacked you and did " << weakassassin.damage << " damage, leaving you at " << health << "." << endl;
              }
              cout << "\033[32mYou did \033[31m" << damage << " damage \033[32mto the \033[37mWeak Assassin\033[32m, leaving it at " << weakassassin.health << " health" << endl;
              blocked = 0;
              if(equippedTalisman == destruction || equippedTalisman == emblem)
                damage /= 2;
              if(infected)
                weakassassin.damage /= 2;
              cont();
              system("clear");
              if(health <= 0)
                goto DEATH;
            }//end of fight with melee
            else{
              cout << "\033[31mTHATS NOT AN OPTION!\033[0m" << endl;
              cont();
              system("clear");
            }//end of wrong option
          }//end of weakassassin fight loop
          weakassassin.kills++;
          gold += weakassassin.gold;
          cout << "\033[32mYou have defeated the \033[37mWeak Assassin\033[32m!" << endl;
          cout << "You gained \033[33m" << weakassassin.gold << " gold!\033[0m" << endl;
          cont();
        }//end of weakassassin random enemy
        
        if(randomEnemy <= 3){
          cout << "\033[36mYou have \033[32m" << health << " health" << endl;
          cout << "\033[36mYou have \033[34m" << mana << " mana" << endl;
          cout << "\033[31mEnemy health: " << goblin.health << endl;
          slow_print("\033[36mYou wander through the dungeons when suddenly you spot a Goblin walking towards you!\033[0m", speed);
          system("clear");
          while(goblin.health > 0){
            GFIGHT:
            cout << "\033[36mYou have \033[32m" << health << " health" << endl;
            cout << "\033[36mYou have \033[34m" << mana << " mana" << endl;
            cout << "\033[31mEnemy health: " << goblin.health << endl;
            cout << "\033[36mYou wander through the dungeons when suddenly you spot a Goblin walking towards you!\033[0m" << endl;
            cout << "Do you want to \033[31m[1] Melee Attack\033[0m or \033[34m[2]Mana attack\033[0m or \033[33m[3] Run\033[0m or \033[32m[4] Use Potion: ";
            if(!(cin >> fightRun)){
              cin.clear();
              cin.ignore(10000, '\n');
              cout << "\033[31mTHAT IS NOT AN OPTION!" << endl;
              cont();
              system("clear");
              goto GFIGHT;
            }

            if(fightRun == 4){
              system("clear");
              moveToFight = "goblin";
              goto POTIONS;
            }//end of use potion
                      
            else if(fightRun == 3){
              slow_print("\033[31mYou stubbed your toe and the Goblin stole \033[33m7 gold \033[31mfrom you and did 10 damage!\033[0m", speed);
              health -= 10;
              gold -= 7;
              cont("\n");
              if(health <= 0)
                goto DEATH;
              system("clear");
              goto GAMESTART;
            }//end of run

            else if(fightRun == 2){
              if(equippedManaWepon == ""){
                slow_print("\033[31mYou do not have a mana weapon equipped!", speed);
                cont("\n");
                system("clear");
              }//end of no mana wepon
              else{
                if(equippedTalisman == destruction || equippedTalisman == emblem)
                manaDamage *= 1.5;
                if(infected)
                  goblin.damage *= 2;
                block(equippedShield);
                if(!blocked){
                  health -= goblin.damage;
                  cout << "\n\033[31mThe Goblin hit you and did " << goblin.damage << " damage, leaving you at \033[32m" << health << " health!\033[0m" << endl;
                }//end of goblin attack you
                if(mana >= manaUsage){
                  goblin.health -= manaDamage;
                  mana -= manaUsage;
                  cout << "\033[32mYou shot the Goblin with your " << equippedManaWepon << "\033[32m, dealing \033[31m" << manaDamage << " damage \033[32mand using \033[34m" << manaUsage << " mana\033[32m!" << endl;
                }//end of use mana wepon
                else
                  slow_print("\033[31mYOU DONT HAVE ENOUGH MANA TO ATTACK\n", speed);
                if(equippedTalisman == destruction || equippedTalisman == emblem)
                manaDamage /= 1.5;
                if(infected)
                  goblin.damage /= 2;
                blocked = 0;
                cont();
                system("clear");
                if(health <= 0)
                  goto DEATH;
              }//end of have mana wepon if
            }//end of use mana attack
                    
            else if(fightRun == 1){
              if(equippedTalisman == destruction || equippedTalisman == emblem)
                damage *= 2;
              if(infected)
                goblin.damage *= 2;
              goblin.health -= damage;
              block(equippedShield);
              if(!blocked){
                health -= goblin.damage;
                cout << "\n\033[31mThe Goblin hit you and did " << goblin.damage << " damage, leaving you at \033[32m" << health << " health!\033[0m" << endl;
              }
              cout << "\033[32mYou did \033[31m" << damage << " damage \033[32mto the Goblin, leaving it at " << goblin.health << " health" << endl;
              blocked = 0;
              if(equippedTalisman == destruction || equippedTalisman == emblem)
                damage /= 2;
              if(infected)
                goblin.damage /= 2;
              cont();
              system("clear");
              if(health <= 0)
                goto DEATH;
            }//end of fight with melee
            else{
              cout << "\033[31mTHATS NOT AN OPTION!\033[0m" << endl;
              cont();
              system("clear");
            }//end of wrong option
          }//end of goblin fight loop
          goblin.kills++;
          gold += goblin.gold;
          cout << "\033[32mYou have defeated the Goblin!" << endl;
          cout << "You gained \033[33m" << goblin.gold << " gold!\033[0m" << endl;
          cont();
        }//end of goblin random enemy

        if(randomEnemy >= 5 && randomEnemy <= 7){
          cout << "\033[36mYou have \033[32m" << health << " health" << endl;
          cout << "\033[36mYou have \033[34m" << mana << " mana" << endl;
          cout << "\033[31mEnemy health: " << wizard.health << endl;
          slow_print("\033[36mYou wander through the dungeons when suddenly you spot a wizard lying on the floor. You try to talk to him but he \033[31mattacks you!", speed);
          system("clear");
          while(wizard.health > 0){
            WFIGHT:
            cout << "\033[36mYou have \033[32m" << health << " health" << endl;
            cout << "\033[36mYou have \033[34m" << mana << " mana" << endl;
            cout << "\033[31mEnemy health: " << wizard.health << endl;
            cout << "\033[36mYou wander through the dungeons when suddenly you spot a wizard lying on the floor. You try to talk to him but he \033[31mattacks you!" << endl;
            cout << "Do you want to \033[31m[1] Melee Attack\033[0m or \033[34m[2]Mana attack\033[0m or \033[33m[3] Run\033[0m or \033[32m[4] Use Potion: ";
            if(!(cin >> fightRun)){
              cin.clear();
              cin.ignore(10000, '\n');
              cout << "\033[31mTHAT IS NOT AN OPTION!" << endl;
              cont();
              system("clear");
              goto WFIGHT;
            }

            if(fightRun == 4){
              system("clear");
              moveToFight = "wizard";
              goto POTIONS;
            }//end of use potion
                      
            else if(fightRun == 3){
              slow_print("\033[31mYou tried running but the Rogue Wizard \033[33m360 no-scoped\033[31m you with a spell and did \033[31m15 damage to you.\033[0m\n", speed);
              health -= 15;
              cont();
              if(health <= 0)
                goto DEATH;
              system("clear");
              goto GAMESTART;
            }//end of run

            else if(fightRun == 2){
              if(equippedManaWepon == ""){
                slow_print("\033[31mYou do not have a mana weapon equipped!", speed);
                cont("\n");
                system("clear");
              }//end of no mana wepon
              else{
                if(equippedTalisman == destruction || equippedTalisman == emblem)
                manaDamage *= 1.5;
                if(infected)
                  wizard.damage *= 2;
                block(equippedShield);
                if(!blocked){
                  health -= wizard.damage;
                  cout << "\033[31mThe Rogue Wizard hit you and did " << wizard.damage << " damage, leaving you at " << health << " health!\033[0m" << endl;
                }//end of enemy attack you
                if(mana >= manaUsage){
                  wizard.health -= manaDamage;
                  mana -= manaUsage;
                  cout << "\033[32mYou shot the Rouge Wizard with your " << equippedManaWepon << "\033[32m, dealing \033[31m" << manaDamage << " damage \033[32mand using \033[34m" << manaUsage << " mana\033[32m!" << endl;
                }//end of use mana wepon
                else
                  slow_print("\033[31mYOU DONT HAVE ENOUGH MANA TO ATTACK\n", speed);
                if(equippedTalisman == destruction || equippedTalisman == emblem)
                manaDamage /= 1.5;
                if(infected)
                  wizard.damage /= 2;
                blocked = 0;
                cont();
                system("clear");
                if(health <= 0)
                  goto DEATH;
              }//end of have mana wepon if
            }//end of use mana attack
                    
            else if(fightRun == 1){
              if(equippedTalisman == destruction || equippedTalisman == emblem)
                damage *= 2;
              if(infected)
                wizard.damage *= 2;
              wizard.health -= damage;
              block(equippedShield);
              if(!blocked){
                health -= wizard.damage;
                cout << "\033[31mThe wizard hit you and did " << wizard.damage << " damage, leaving you at " << health << " health!\033[0m" << endl;
              }
              cout << "\033[32mYou did \033[31m" << damage << " damage \033[32mto the Rogue Wizard, leaving it at " << wizard.health << " health" << endl;
              blocked = 0;
              if(equippedTalisman == destruction || equippedTalisman == emblem)
                damage /= 2;
              if(infected)
                wizard.damage /= 2;
              cont();
              system("clear");
              if(health <= 0)
                goto DEATH;
            }//end of fight with melee
            else{
              cout << "\033[31mTHATS NOT AN OPTION!\033[0m" << endl;
              cont();
              system("clear");
            }//end of wrong option
          }//end of Wizard fight loop
          wizard.kills++;
          healingPotions += wizard.healingPotions;
          gold += wizard.gold;
          cout << "\033[32mYou have defeated the Rogue Wizard!" << endl;
          cout << "You gained \033[33m" << wizard.gold << " gold\033[32m and \033[31m" << wizard.healingPotions << " healing potions!\033[0m" << endl;
          cont();
        }//end of wizard random enemy

        if(randomEnemy <= 10 && randomEnemy >= 8){
          system("clear");
          ran(woodChest.skullKey, 10, 1);
          ran(woodChest.gold, 30, 1);
          ran(woodChest.healthPotions, 3, 1);
          woodChest.healthPotions--;
          gold += woodChest.gold;
          healingPotions += woodChest.healthPotions;
					chestsOpened++;
          cout << "\033[32mYou found a chest! The chest had \033[33m" << woodChest.gold << " gold \033[32mand \033[31m" << woodChest.healthPotions << " healing potions!\033[0m" << endl;
          cont();
          if(woodChest.skullKey <= 3){
            skullKey = 1;
            slow_print("\033[36mWait, you also found a strange looking key in the chest!\n\033[37mSkull Key\033[36m obtained!\n", speed);
            cont();
          }//end of random key chance
        }//end of chest random enemy
      break;
      /*****ABANDONED TOWN*****/
      case 3:
      demihuman.health = demihuman.defaultHealth;
      zombie.health = zombie.defaultHealth;
      worm.health = worm.defaultHealth;
      ran(randomEnemy, 10, 1);//worm 4/10, zombie 3/10, demihuman 2/10, supply crate 1/10

      if(randomEnemy <= 4){
        cout << "\033[36mYou have \033[32m" << health << " health" << endl;
        cout << "\033[36mYou have \033[34m" << mana << " mana" << endl;
        cout << "\033[31mEnemy health: " << worm.health << endl;
        slow_print("\033[35mYou travel through the \033[37mAbandoned Town, \033[35mwhen suddenly a worm climbs out from the earth and \033[31mattacks you!\033[0m", speed);
        system("clear");
        while(worm.health > 0){
          WOFIGHT:
          cout << "\033[36mYou have \033[32m" << health << " health" << endl;
          cout << "\033[36mYou have \033[34m" << mana << " mana" << endl;
          cout << "\033[31mEnemy health: " << worm.health << endl;
          cout << "\033[35mYou travel through the \033[37mAbandoned Town, \033[35mwhen suddenly a worm climbs out from the earth and \033[31mattacks you!\033[0m" << endl;
          cout << "Do you want to \033[31m[1] Melee Attack\033[0m or \033[34m[2]Mana attack\033[0m or \033[33m[3] Run\033[0m or \033[32m[4] Use Potion: ";
          if(!(cin >> fightRun)){
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "\033[31mTHAT IS NOT AN OPTION!" << endl;
            cont();
            system("clear");
            goto WOFIGHT;
          }

          if(fightRun == 4){
            system("clear");
            moveToFight = "worm";
            goto POTIONS;
          }//end of use potion
                    
          else if(fightRun == 3){
            slow_print("\033[31mAs you run away, you slip on the worm and your drop all of your \033[33mgold!\033[32m\nYou got away safely.\033[0m\n", speed);
            gold -= gold;
            cont();
            if(health <= 0)
              goto DEATH;
            system("clear");
            goto GAMESTART;
          }//end of run

          else if(fightRun == 2){
            if(equippedManaWepon == ""){
              slow_print("\033[31mYou do not have a mana weapon equipped!", speed);
              cont("\n");
              system("clear");
            }//end of no mana wepon
            else{
              if(equippedTalisman == destruction || equippedTalisman == emblem)
              manaDamage *= 1.5;
              if(infected)
                worm.damage *= 2;
              block(equippedShield);
              ran(missChance, 3, 1);
              if(!blocked){
                health -= worm.damage;
                cout << "\033[31mThe worm constricts around your leg and does " << worm.damage << " damage, leaving you at \033[32m" << health << " health\033[0m" << endl;
              }//end of enemy attack you
              if(mana >= manaUsage){
                if(missChance == 2 || missChance == 1){
                  worm.health -= manaDamage;
                  mana -= manaUsage;
                  cout << "\033[32mYou shot the worm with your " << equippedManaWepon << "\033[32m, dealing \033[31m" << manaDamage << " damage \033[32mand using \033[34m" << manaUsage << " mana\033[32m!" << endl;
                }
                else if(missChance == 3)
                  slow_print("\033[31mYou tried to shoot the worm with your " + equippedManaWepon + "\033[31m, but you missed!\n", speed);
              }//end of use mana wepon
              else
                slow_print("\033[31mYOU DONT HAVE ENOUGH MANA TO ATTACK\n", speed);
              if(equippedTalisman == destruction || equippedTalisman == emblem)
              manaDamage /= 1.5;
              if(infected)
                worm.damage /= 2;
              blocked = 0;
              cont();
              system("clear");
              if(health <= 0)
                goto DEATH;
            }//end of have mana wepon if
          }//end of use mana attack
                  
          else if(fightRun == 1){
            if(equippedTalisman == destruction || equippedTalisman == emblem)
              damage *= 2;
            if(infected)
              worm.damage *= 2;
            block(equippedShield);
            ran(missChance, 3, 1);
            if(!blocked){
              health -= worm.damage;
              cout << "\033[31mThe worm constricts around your leg and does " << worm.damage << " damage, leaving you at \033[32m" << health << " health\033[0m" << endl;
            }
            if(missChance == 2){
              worm.health -= damage;
              cout << "\033[32mYou did \033[31m" << damage << " damage \033[32mto the Worm, leaving it at " << worm.health << " health" << endl;
            }
            else
              cout << "\033[31mYou attacked the Worm but you missed!" << endl;
            blocked = 0;
            if(equippedTalisman == destruction || equippedTalisman == emblem)
              damage /= 2;
            if(infected)
              worm.damage /= 2;
            cont();
            system("clear");
            if(health <= 0)
              goto DEATH;
          }//end of fight with melee
          else{
            cout << "\033[31mTHATS NOT AN OPTION!\033[0m" << endl;
            cont();
            system("clear");
          }//end of wrong option
        }//end of worm fight loop
        worm.kills++;
        gold += worm.gold;
        cout << "\033[32mYou have defeated the worm!" << endl;
        cout << "You gained \033[33m" << worm.gold << " gold!\033[0m" << endl;
        cont();
      }//end of worm random enemy

      if(randomEnemy >= 5 && randomEnemy <= 7){
        cout << "\033[36mYou have \033[32m" << health << " health" << endl;
        cout << "\033[36mYou have \033[34m" << mana << " mana" << endl;
        cout << "\033[31mEnemy health: " << zombie.health << endl;
        slow_print("\033[34mYou travel trough the city when suddenly a \033[32mzombie\033[34m crawls out from underneath a car and \033[31mattacks you!", speed);
        system("clear");
        while(zombie.health > 0){
          ZFIGHT:
          cout << "\033[36mYou have \033[32m" << health << " health" << endl;
          cout << "\033[36mYou have \033[34m" << mana << " mana" << endl;
          cout << "\033[31mEnemy health: " << zombie.health << endl;
          cout << "\033[34mYou travel trough the city when suddenly a \033[32mzombie\033[34m crawls out from underneath a car and \033[31mattacks you!" << endl;
          cout << "Do you want to \033[31m[1] Melee Attack\033[0m or \033[34m[2]Mana attack\033[0m or \033[33m[3] Run\033[0m or \033[32m[4] Use Potion: ";
          if(!(cin >> fightRun)){
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "\033[31mTHAT IS NOT AN OPTION!" << endl;
            cont();
            system("clear");
            goto ZFIGHT;
          }

          if(fightRun == 4){
            system("clear");
            moveToFight = "zombie";
            goto POTIONS;
          }//end of use potion
                    
          else if(fightRun == 3){
            slow_print("\033[31mWhile you tried to run away, the zombie scratched you and you become \033[32minfected\033[31m!\n", speed);
            infected = true;
            cont();
            if(health <= 0)
              goto DEATH;
            system("clear");
            goto GAMESTART;
          }//end of run

          else if(fightRun == 2){
            if(equippedManaWepon == ""){
              slow_print("\033[31mYou do not have a mana weapon equipped!", speed);
              cont("\n");
              system("clear");
            }//end of no mana wepon
            else{
              if(equippedTalisman == destruction || equippedTalisman == emblem)
              manaDamage *= 1.5;
              if(infected)
                zombie.damage *= 2;
              zombie.infChance = 10;
              block(equippedShield);
              if(!blocked){
                ran(zombie.infChance, 10, 1);
                health -= zombie.damage;
                cout << "\033[31mThe zombie did " << zombie.damage << " damage to you, leaving you at \033[32m" << health << " health!\033[0m" << endl;
              }//end of enemy attack you
              if(mana >= manaUsage){
                zombie.health -= manaDamage;
                mana -= manaUsage;
                cout << "\033[32mYou shot the Zombie with your " << equippedManaWepon << "\033[32m, dealing \033[31m" << manaDamage << " damage \033[32mand using \033[34m" << manaUsage << " mana\033[32m!" << endl;
              }//end of use mana wepon
              else
                slow_print("\033[31mYOU DONT HAVE ENOUGH MANA TO ATTACK\n", speed);
              if(equippedTalisman == destruction || equippedTalisman == emblem)
              manaDamage /= 1.5;
              if(infected)
                zombie.damage /= 2;
              blocked = 0;
              cont();
              if(zombie.infChance == 1){
                infected = true;
                slow_print("\033[31mThe wound the zombie gave you was deep enough to infect you with the zombie virus. You are now \033[32minfected!\033[0m\n", speed);
                cont();
              }
              system("clear");
              if(health <= 0)
                goto DEATH;
            }//end of have mana wepon if
          }//end of use mana attack
                  
          else if(fightRun == 1){
            if(equippedTalisman == destruction || equippedTalisman == emblem)
              damage *= 2;
            if(infected)
              zombie.damage *= 2;
            zombie.health -= damage;
            zombie.infChance = 10;
            block(equippedShield);
            if(!blocked){
              ran(zombie.infChance, 10, 1);
              health -= zombie.damage;
              cout << "\033[31mThe zombie did " << zombie.damage << " damage to you, leaving you at \033[32m" << health << " health!\033[0m" << endl;
            }
            cout << "\033[32mYou did \033[31m" << damage << " damage \033[32mto the Zombie, leaving it at " << zombie.health << " health" << endl;
            blocked = 0;
            if(equippedTalisman == destruction || equippedTalisman == emblem)
              damage /= 2;
            if(infected)
              zombie.damage /= 2;
            cont();
            if(zombie.infChance == 1){
              infected = true;
              slow_print("\033[31mThe wound the zombie gave you was deep enough to infect you with the zombie virus. You are now \033[32minfected!\033[0m\n", speed);
              cont();
            }
            system("clear");
            if(health <= 0)
              goto DEATH;
          }//end of fight with melee
          else{
            cout << "\033[31mTHATS NOT AN OPTION!\033[0m" << endl;
            cont();
            system("clear");
          }//end of wrong option
        }//end of zombie fight loop
        zombie.kills++;
        gold += zombie.gold;
        cout << "\033[32mYou have defeated the Zombie!" << endl;
        cout << "You gained \033[33m" << zombie.gold << " gold!\033[0m" << endl;
        cont();
      }//end of zombie random enemy

      if(randomEnemy == 8 || randomEnemy == 9){
        cout << "\033[36mYou have \033[32m" << health << " health" << endl;
        cout << "\033[36mYou have \033[34m" << mana << " mana" << endl;
        cout << "\033[31mEnemy health: " << demihuman.health << endl;
        slow_print("\033[36mYou break into a house and see some type of Demi-Human lying on the floor. It looks like it's protecting a crate. It jumps up and \033[31mattacks you!", speed);
        system("clear");
        while(demihuman.health > 0){
          DFIGHT:
          cout << "\033[36mYou have \033[32m" << health << " health" << endl;
          cout << "\033[36mYou have \033[34m" << mana << " mana" << endl;
          cout << "\033[31mEnemy health: " << demihuman.health << endl;
          cout << "\033[36mYou break into a house and see some type of Demi-Human lying on the floor. It looks like it's protecting a crate. It jumps up and \033[31mattacks you!" << endl;
          cout << "Do you want to \033[31m[1] Melee Attack\033[0m or \033[34m[2]Mana attack\033[0m or \033[33m[3] Run\033[0m or \033[32m[4] Use Potion: ";
          if(!(cin >> fightRun)){
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "\033[31mTHAT IS NOT AN OPTION!" << endl;
            cont();
            system("clear");
            goto DFIGHT;
          }

          if(fightRun == 4){
            system("clear");
            moveToFight = "demihuman";
            goto POTIONS;
          }//end of use potion
                    
          else if(fightRun == 3){
            slow_print("\033[31mYou turned around and start running, but the demihuman slammed you to the floor and did 10 damage!\n", speed);
            health -= 10;
            cont();
            if(health <= 0)
              goto DEATH;
            system("clear");
            goto GAMESTART;
          }//end of run

          else if(fightRun == 2){
            if(equippedManaWepon == ""){
              slow_print("\033[31mYou do not have a mana weapon equipped!", speed);
              cont("\n");
              system("clear");
            }//end of no mana wepon
            else{
              if(equippedTalisman == destruction || equippedTalisman == emblem)
              manaDamage *= 1.5;
              if(infected)
                demihuman.damage *= 2;
              block(equippedShield);
              if(!blocked){
                health -= demihuman.damage;
                cout << "\033[31mThe demi-human attacked you and did " << demihuman.damage << " damage, leaving you at \033[32m" << health << " health!" << endl;
              }//end of enemy attack you
              if(mana >= manaUsage){
                demihuman.health -= manaDamage;
                mana -= manaUsage;
                cout << "\033[32mYou shot the Demi-Human with your " << equippedManaWepon << "\033[32m, dealing \033[31m" << manaDamage << " damage \033[32mand using \033[34m" << manaUsage << " mana\033[32m!" << endl;
              }//end of use mana wepon
              else
                slow_print("\033[31mYOU DONT HAVE ENOUGH MANA TO ATTACK\n", speed);
              if(equippedTalisman == destruction || equippedTalisman == emblem)
              manaDamage /= 1.5;
              if(infected)
                demihuman.damage /= 2;
              blocked = 0;
              cont();
              system("clear");
              if(health <= 0)
                goto DEATH;
            }//end of have mana wepon if
          }//end of use mana attack
                  
          else if(fightRun == 1){
            if(equippedTalisman == destruction || equippedTalisman == emblem)
              damage *= 2;
            if(infected)
              demihuman.damage *= 2;
            demihuman.health -= damage;
            block(equippedShield);
            if(!blocked){
              health -= demihuman.damage;
              cout << "\033[31mThe demi-human attacked you and did " << demihuman.damage << " damage, leaving you at \033[32m" << health << " health!" << endl;
            }
            cout << "\033[32mYou did \033[31m" << damage << " damage \033[32mto the Demi-Human, leaving it at " << demihuman.health << " health" << endl;
            blocked = 0;
            if(equippedTalisman == destruction || equippedTalisman == emblem)
              damage /= 2;
            if(infected)
              demihuman.damage /= 2;
            cont();
            system("clear");
            if(health <= 0)
              goto DEATH;
          }//end of fight with melee
          else{
            cout << "\033[31mTHATS NOT AN OPTION!\033[0m" << endl;
            cont();
            system("clear");
          }//end of wrong option
        }//end of (enemy) fight loop
        demihuman.kills++;
        gold += demihuman.gold;
        cout << "\033[32mYou have defeated the Demi-Human!" << endl;
        cout << "You gained \033[33m" << demihuman.gold << " gold!\033[0m" << endl;
        cont();
      }//end of demihuman random enemy

      if(randomEnemy >= 8){
        system("clear");
        ran(crate.gold, 15, 1);
        ran(crate.healthPotions, 2, 1);
        crate.healthPotions--;
        gold += crate.gold;
        healingPotions += crate.healthPotions;
				cratesOpened++;
        slow_print("\033[36mYou traveled around the \033[37mAbandoned Town\033[36m and broke into a random house.\n", speed);
        usleep(1000);
        slow_print("\033[32mYou found a crate that had \033[33m", speed);
        usleep(1000);
        cout << crate.gold << " ";
        usleep(1000);
        slow_print("gold\033[32m and\033[32m ", speed);
        usleep(1000);
        cout << crate.healthPotions << " ";
        usleep(1000);
        slow_print(" healing potions!\n", speed);
        cont();
      }
      break;
      case 4:
        //**********ARMORY**********//
        ARMORY:
        slow_print("\033[32mWelcome to your \033[31marmory!\033[0m\n", speed);
        cout << "Where would you like to go?" << endl;
        cout << "\t1) \033[31mSword Armory\033[0m" << endl;
        cout << "\t2) \033[33mSheild Armory\033[0m" << endl;
        cout << "\t3) \033[37mTalismans\033[0m" << endl;
        cout << "\t4) \033[34mMagic Wepons\033[0m" << endl;
        cout << "\033[36mEnter choice here: \033[32m";
        if(!(cin >> armoryChoice)){
          cin.clear();
          cin.ignore(10000, '\n');
          cout << "\033[31mTHAT IS NOT AN OPTION!" << endl;
          cont();
          system("clear");
          goto ARMORY;
        }
        system("clear");
        switch(armoryChoice){
          case 0:
            system("clear");
            if(moveToBoss == 1){
              moveToBoss = 0;
              goto FGFIGHT;
            }//end of Go back to Fire Golem
            else if(moveToBoss == 2){
              moveToBoss = 0;
              goto IGFIGHT;
            }//end of go back to Ice Golem
            else if(moveToBoss == 3){
              moveToBoss = 0;
              goto EGFIGHT;
            }
            else if(moveToBoss == 4){
              moveToBoss = 0;
              goto BOSSFIGHT;
            }
          break;
          case 1:
          SWORDARMORY:
          cout << "\033[32mWelcome to the sword armory! These are swords you currently have: \033[0m" << endl;
          cout << "\033[0m1)" << swordArmory[0] << "\033[0m\n2)" << swordArmory[1] << "\033[0m\n3)" << swordArmory[2] << "\033[0m\n4)" << swordArmory[3] << "\033[0m\n5)" << swordArmory[4] << endl;
          cout << "Which one would you like to equip?: ";
          if(!(cin >> equipChoice)){
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "\033[31mTHAT IS NOT AN OPTION!" << endl;
            cont();
            system("clear");
            goto SWORDARMORY;
          }
          switch(equipChoice){
            case 0:
              system("clear");
              goto ARMORY;
            break;
            case 1:
              if(equippedSword != swordArmory[0] && swordArmory[0] == bronzeSword){
                equippedSword = swordArmory[0];
                damage = 3;
                cout << "\033[32mYou have equiped " << bronzeSword << "!\033[0m" << endl;
                cont();
                system("clear");
                goto SWORDARMORY;
              }//end of bronze equip
              else if(equippedSword == swordArmory[0]){
                cout << "\033[31m already have this sword equipped!\033[0m" << endl;
                cont();
                system("clear");
                goto SWORDARMORY;
              }//end of already equiped bronze
              else if(swordArmory[0] != bronzeSword){
                cout << "\033[31mYou do not own this sword!\033[0m" << endl;
                cont();
                system("clear");
                goto SWORDARMORY;
              }//end of dont have bronze
            break;
            case 2:
              if(equippedSword != swordArmory[1] && swordArmory[1] == silverSword){
                equippedSword = swordArmory[1];
                damage = 5;
                cout << "\033[32mYou have equiped " << silverSword << "!\033[0m" << endl;
                cont();
                system("clear");
                goto SWORDARMORY;
              }//end of silver equip
              else if(equippedSword == swordArmory[1]){
                cout << "\033[31m already have this sword equipped!\033[0m" << endl;
                cont();
                system("clear");
                goto SWORDARMORY;
              }//end of already equiped silver
              else if(swordArmory[1] != silverSword){
                cout << "\033[31mYou do not own this sword!\033[0m" << endl;
                cont();
                system("clear");
                goto SWORDARMORY;
              }//end of dont have silver
            break;
            case 3:
              if(equippedSword != swordArmory[2] && swordArmory[2] == goldSword){
                equippedSword = swordArmory[2];
                damage = 7;
                cout << "\033[32mYou have equiped " << goldSword << "\033[32m!\033[0m" << endl;
                cont();
                system("clear");
                goto SWORDARMORY;
              }//end of gold equip
              else if(equippedSword == swordArmory[2]){
                cout << "\033[31m already have this sword equipped!\033[0m" << endl;
                cont();
                system("clear");
                goto SWORDARMORY;
              }//end of already equiped gold
              else if(swordArmory[2] != goldSword){
                cout << "\033[31mYou do not own this sword!\033[0m" << endl;
                cont();
                system("clear");
                goto SWORDARMORY;
              }//end of dont have gold
            break;
            case 4:
              if(equippedSword != swordArmory[3] && swordArmory[3] == diamondSword){
                equippedSword = swordArmory[3];
                damage = 10;
                cout << "\033[32mYou have equiped " << diamondSword << "\033[32m!\033[0m" << endl;
                cont();
                system("clear");
                goto SWORDARMORY;
              }//end of diamond equip
              else if(equippedSword == swordArmory[3]){
                cout << "\033[31m already have this sword equipped!\033[0m" << endl;
                cont();
                system("clear");
                goto SWORDARMORY;
              }//end of already equipped diamond
              else if(swordArmory[3] != diamondSword){
                cout << "\033[31mYou do not own this sword!\033[0m" << endl;
                cont();
                system("clear");
                goto SWORDARMORY;
              }//end of dont have diamond
            break;
            case 5:
              if(equippedSword != swordArmory[4] && swordArmory[4] == carrotSmasher){
                equippedSword = swordArmory[4];
                damage = 900;
                cout << "\033[32mYou have equiped " << carrotSmasher << "\033[32m!\033[0m" << endl;
                cont();
                system("clear");
                goto SWORDARMORY;
              }//end of carrot equip
              else if(equippedSword == swordArmory[4]){
                cout << "\033[31mYou already have this sword equipped!\033[31m" << endl;
                cont();
                system("clear");
                goto SWORDARMORY;
              }//end of already equipped carrot
              else if(swordArmory[4] != carrotSmasher){
                cout << "\033[31mYou do not own this sword!\033[0m" << endl;
                cont();
                system("clear");
                goto SWORDARMORY;
              }//end of dont have carrot
            break;
            default:
              cout << "\033[31mThat is not a option!\033[0m" << endl;
              cont();
              system("clear");
              goto SWORDARMORY;
            break;
          }//end of sword armory
          break;
          case 2:
            SHIELDARMORY:
            cout << "\033[33mWelcome to the Sheild Armory! These are the sheilds you currently have: " << endl;
            cout << "\033[0m1) " << shieldArmory[0] << endl;
            if (shieldArmory[0] == bronzeSheild)
              cout << "\tBlock Chance: 10%\n\tDurability: " << bronzeS.durability << endl;
            cout << "\033[0m2) " << shieldArmory[1] << endl;
            if (shieldArmory[1] == silverSheild)
              cout << "\tBlock Chance: 20%\n\tDurability: " << silverS.durability << endl; 
            cout << "\033[0m3) " << shieldArmory[2] << endl;
            if (shieldArmory[2] == goldSheild)
              cout << "\tBlock Chance: 70%\n\tDurability: " << goldS.durability << endl;
            cout << "\033[0m4) " << shieldArmory[3] << endl;
            if (shieldArmory[3] == diamondSheild)
              cout << "\tBlock Chance: 50%\n\tDurability: " << diamondS.durability << endl;
            cout << "\033[0m5) " << shieldArmory[4] << endl;
            if (shieldArmory[4] == carrotShield)
              cout << "\tBlock Chance: 100%\n\tDurability: infinite" << endl;
            cout << "Which one would you like to equip?: ";
            if(!(cin >> equipChoice)){
              cin.clear();
              cin.ignore(10000, '\n');
              cout << "\033[31mTHAT IS NOT AN OPTION!" << endl;
              cont();
              system("clear");
              goto SHIELDARMORY;
            }
            switch(equipChoice){
              case 0:
                system("clear");
                goto ARMORY;
              break;
              case 1:
                if(equippedShield != bronzeSheild && shieldArmory[0] == bronzeSheild){
                  equippedShield = bronzeSheild;
                  shieldDurability = bronzeS.durability;
                  cout << "\033[32mYou have equipped the " << bronzeSheild << "\033[32m!" << endl;
                  cont();
                  system("clear");
                  goto SHIELDARMORY;
                }
                else if(shieldArmory[0] != bronzeSheild){
                  cout << "\033[31mYou dont own this sheild!" << endl;
                  cont();
                  system("clear");
                  goto SHIELDARMORY;
                }
                else if(equippedShield == bronzeSheild){
                  cout << "\033[31mThis sheild is already equipped!" << endl;
                  cont();
                  system("clear");
                  goto SHIELDARMORY;
                }
              break;
              case 2:
                if(equippedShield != silverSheild && shieldArmory[1] == silverSheild){
                  equippedShield = silverSheild;
                  shieldDurability = silverS.durability;
                  cout << "\033[32mYou have equipped the " << silverSheild << "\033[32m!" << endl;
                  cont();
                  system("clear");
                  goto SHIELDARMORY;
                }
                else if(shieldArmory[1] != silverSheild){
                  cout << "\033[31mYou dont own this sheild!" << endl;
                  cont();
                  system("clear");
                  goto SHIELDARMORY;
                }
                else if(equippedShield == silverSheild){
                  cout << "\033[31mThis sheild is already equipped!" << endl;
                  cont();
                  system("clear");
                  goto SHIELDARMORY;
                }
              break;
              case 3:
                if(equippedShield != goldSheild && shieldArmory[2] == goldSheild){
                  equippedShield = goldSheild;
                  shieldDurability = goldS.durability;
                  cout << "\033[32mYou have equipped the " << goldSheild << "\033[32m!" << endl;
                  cont();
                  system("clear");
                  goto SHIELDARMORY;
                }
                else if(shieldArmory[2] != goldSheild){
                  cout << "\033[31mYou dont own this sheild!" << endl;
                  cont();
                  system("clear");
                  goto SHIELDARMORY;
                }
                else if(equippedShield == goldSheild){
                  cout << "\033[31mThis sheild is already equipped!" << endl;
                  cont();
                  system("clear");
                  goto SHIELDARMORY;
                }
              break;
              case 4:
                if(equippedShield != diamondSheild && shieldArmory[3] == diamondSheild){
                  equippedShield = diamondSheild;
                  shieldDurability = diamondS.durability;
                  cout << "\033[32mYou have equipped the " << diamondSheild << "\033[32m!" << endl;
                  cont();
                  system("clear");
                  goto SHIELDARMORY;
                }
                else if(shieldArmory[3] != diamondSheild){
                  cout << "\033[31mYou dont own this sheild!" << endl;
                  cont();
                  system("clear");
                  goto SHIELDARMORY;
                }
                else if(equippedShield == diamondSheild){
                  cout << "\033[31mThis sheild is already equipped!" << endl;
                  cont();
                  system("clear");
                  goto SHIELDARMORY;
                }
              break;
              case 5:
                if(equippedShield != carrotShield && shieldArmory[4] == carrotShield){
                  equippedShield = carrotShield;
                  shieldDurability = 999999999;
                  cout << "\033[32mYou have equipped the " << carrotShield << "\033[32m!" << endl;
                  cont();
                  system("clear");
                  goto SHIELDARMORY;
                }
                else if(shieldArmory[4] != carrotShield){
                  cout << "\033[31mYou dont own this sheild!" << endl;
                  cont();
                  system("clear");
                  goto SHIELDARMORY;
                }
                else if(equippedShield == carrotShield){
                  cout << "\033[31mThis sheild is already equipped!" << endl;
                  cont();
                  system("clear");
                  goto SHIELDARMORY;
                }
              break;
              default:
                cout << "\033[31mTHATS NOT A CHOICE!" << endl;
                cont();
                system("clear");
                goto SHIELDARMORY;
              break;
            }//end of sheild equip select
          break;
          case 3:
            TALISMANARMORY:
            cout << "\033[36mWelcome to your \033[33mTalisman\033[36m armory" << endl;
            cout << "Currently Equipped: " << equippedTalisman << endl;
            cout << "\033[36mThese are the talismans you own: " << endl;
            cout << "\033[0m1) ";
            if(talismanOfRebirth)
              cout << rebirth;
            cout << "\n\033[0m2) ";
            if(talismanOfDestruction)
              cout << destruction;
            cout << "\n\033[0m3) ";
            if(talismanOfTreasure)
              cout << treasure;
            cout << "\n\033[0m4) ";
            if(avengerEmblem)
              cout << emblem;
            cout << "\n\033[34mPlease enter which one you would like to equip(0 to return): \033[32m";
            if(!(cin >> equipChoice)){
              cin.clear();
              cin.ignore(10000, '\n');
              cout << "\033[31mTHAT IS NOT AN OPTION!" << endl;
              cont();
              system("clear");
              goto TALISMANARMORY;
            }//end of input
            switch(equipChoice){
              case 0:
                system("clear");
                goto ARMORY;
              break;
              case 1:
                if(talismanOfRebirth && equippedTalisman != rebirth){
                  if(equippedTalisman == treasure || equippedTalisman == emblem)
                    treasureBuff("-");
                  if(equippedTalisman == emblem){
                    health /= 2;
                    mana /= 2;
                    maxHealthMana = 100;
                  }
                  equippedTalisman = rebirth;
                  slow_print("\033[32mYou have succesfully equipped the " + rebirth + "\033[32m!\n", speed);
                  cont();
                  system("clear");
                  goto TALISMANARMORY;
                }//rebirth equip
                else if(!talismanOfRebirth){
                  slow_print("\033[31mYou do not own this talisman!\n", speed);
                  cont();
                  system("clear");
                  goto TALISMANARMORY;
                }//end of dont own rebirth
                else if(equippedTalisman == rebirth){
                  slow_print("\033[31mYou already have this equipped!", speed);
                  cont();
                  system("clear");
                  goto TALISMANARMORY;
                }//end of rebirth already equipped
              break;
              case 2:
                if(equippedTalisman != destruction && talismanOfDestruction){
                  if(equippedTalisman == treasure || equippedTalisman == emblem)
                    treasureBuff("-");
                  if(equippedTalisman == emblem){
                    health /= 2;
                    mana /= 2;
                    maxHealthMana = 100;
                  }
                  equippedTalisman = destruction;
                  slow_print("\033[32mYou have succesfully equipped the " + destruction + "\033[31m!\n", speed);
                  cont();
                  system("clear");
                goto TALISMANARMORY;
                }//end of equip destruction
                else if(!talismanOfDestruction){
                  slow_print("\033[31mYou do not own this item!\n", speed);
                  cont();
                  system("clear");
                  goto TALISMANARMORY;
                }//end of dont own destruction
                else if(equippedTalisman == destruction){
                  slow_print("\033[31mYou already have this talisman equipped!\n", speed);
                  cont();
                  system("clear");
                  goto TALISMANARMORY;
                }//end of destruction already equipped
              break;
              case 3:
                if(talismanOfTreasure && equippedTalisman != treasure){
                  if(equippedTalisman != emblem)
                    treasureBuff("+");
                  if(equippedTalisman == emblem){
                    health /= 2;
                    mana /= 2;
                    maxHealthMana = 100;
                  }
                  equippedTalisman = treasure;
                  slow_print("\033[32mYou have equipped the " + treasure + "\033[32m!\n", speed);
                  cont();
                  system("clear");
                  goto TALISMANARMORY;
                }//end of treasure equip
                else if(!talismanOfTreasure){
                  slow_print("\033[31mYou do not own this item!\n", speed);
                  cont();
                  system("clear");
                  goto TALISMANARMORY;
                }//end of treasure not own
                else if(equippedTalisman == treasure){
                  slow_print("\033[31mYou already have this talisman equipped!\n", speed);
                  cont();
                  system("clear");
                  goto TALISMANARMORY;
                }//end of treasure already equipped
              break;
              case 4:
                if(equippedTalisman != emblem && avengerEmblem){
                  if(equippedTalisman != treasure)
                    treasureBuff("+");
                  health *= 2;
                  mana *= 2;
                  maxHealthMana = 200;
                  equippedTalisman = emblem;
                  slow_print("\033[32mYou have equipped the " + emblem + "\033[32m!", speed);
                  cont("\n");
                  system("clear");
                  goto TALISMANARMORY;
                }//end of equip emblem
                else if(equippedTalisman == emblem){
                  slow_print("\033[31mThis item is already equiped!", speed);
                  cont("\n");
                  system("clear");
                  goto TALISMANARMORY;
                }//end of already equipped
                else if(!avengerEmblem){
                  slow_print("\033[31mYou do NOT own this item!", speed);
                  cont("\n");
                  system("clear");
                  goto TALISMANARMORY;
                }//end of dont have emblem
              break;
              default:
                slow_print("\033[31mTHAT IS NOT AN OPTION!", speed);
                cont("\n");
                system("clear");
                goto TALISMANARMORY;
              break;
            }//end of talisman equip switch
          break;
          case 4:
            MANAARMORY:
            cout << "\033[36mWelcome to your Magic Wepon Armory!\n" << endl;
            cout << "\033[34mEquipped Item: " << equippedManaWepon << endl;
            cout << "\033[33mWhich item would you like to equip?\033[0m" << endl;
            cout << "\t1) " << manaWeponArmory[0] << "\n\t\033[0m2) " << manaWeponArmory[1] << "\n\t\033[0m3) " << manaWeponArmory[2] << "\n\t\033[0m4) " << manaWeponArmory[3] << endl;
            cout << "Enter choice here: ";
            if(!(cin >> equipChoice)){
              cin.clear();
              cin.ignore(10000, '\n');
              cout << "\033[31mTHAT IS NOT AN OPTION!" << endl;
              cont();
              system("clear");
              goto MANAARMORY;
            }//end of input
            switch(equipChoice){
              case 0:
                system("clear");
                goto ARMORY;
              break;
              case 1:
                if(equippedManaWepon != manaWeponArmory[0] && manaWeponArmory[0] == bronzeStaff){
                  equippedManaWepon = bronzeStaff;
                  manaDamage = 12;
                  manaUsage = 5;
                  slow_print("\033[32mYou have equipped the " + bronzeStaff + "\033[32m!", speed);
                  cont("\n");
                  system("clear");
                  goto MANAARMORY;
                }//end of equip bronze staff
                else if(manaWeponArmory[0] != bronzeStaff){
                  slow_print("\033[31mYou don't have this weapon!", speed);
                  cont("\n");
                  system("clear");
                  goto MANAARMORY;
                }//end of dont own bronze staff
                else if(equippedManaWepon == manaWeponArmory[0]){
                  slow_print("\033[31mYou already have this weapon equipped!", speed);
                  cont("\n");
                  system("clear");
                  goto MANAARMORY;
                }//end of bronze staff already equipped
              break;
              case 2:
                if(equippedManaWepon != manaWeponArmory[1] && manaWeponArmory[1] == silverStaff){
                  equippedManaWepon = manaWeponArmory[1];
                  manaDamage = 14;
                  manaUsage = 10;
                  slow_print("\033[32mYou have equipped the " + silverStaff + "\033[32m!", speed);
                  cont("\n");
                  system("clear");
                  goto MANAARMORY;
                }//end of equip silver staff
                else if(manaWeponArmory[1] != silverStaff){
                  slow_print("\033[31mYou don't have this weapon!", speed);
                  cont("\n");
                  system("clear");
                  goto MANAARMORY;
                }//end of equip silver staff
                else if(equippedManaWepon == manaWeponArmory[1]){
                  slow_print("\033[31mYou already have this weapon equipped!", speed);
                  cont("\n");
                  system("clear");
                  goto MANAARMORY;
                }//end of silver staff already equipped
              break;
              case 3:
                if(equippedManaWepon != manaWeponArmory[2] && manaWeponArmory[2] == goldStaff){
                  equippedManaWepon = manaWeponArmory[2];
                  manaDamage = 16;
                  manaUsage = 15;
                  slow_print("\033[32mYou have equipped the " + goldStaff + "\033[32m!", speed);
                  cont("\n");
                  system("clear");
                  goto MANAARMORY;
                }//end of equip gold staff
                else if(manaWeponArmory[2] != goldStaff){
                  slow_print("\033[31mYou don't have this weapon!", speed);
                  cont("\n");
                  system("clear");
                  goto MANAARMORY;
                }//end of equip gold staff
                else if(equippedManaWepon == manaWeponArmory[2]){
                  slow_print("\033[31mYou already have this weapon equipped!", speed);
                  cont("\n");
                  system("clear");
                  goto MANAARMORY;
                }//end of gold staff already equipped
              break;
              case 4:
                if(equippedManaWepon != manaWeponArmory[3] && manaWeponArmory[3] == diamondStaff){
                  equippedManaWepon = manaWeponArmory[3];
                  manaDamage = 20;
                  manaUsage = 20;
                  slow_print("\033[32mYou have equipped the " + diamondStaff + "\033[32m!", speed);
                  cont("\n");
                  system("clear");
                  goto MANAARMORY;
                }//end of equip diamond staff
                else if(manaWeponArmory[3] != diamondStaff){
                  slow_print("\033[31mYou don't have this weapon!", speed);
                  cont("\n");
                  system("clear");
                  goto MANAARMORY;
                }//end of equip diamond staff
                else if(equippedManaWepon == manaWeponArmory[3]){
                  slow_print("\033[31mYou already have this weapon equipped!", speed);
                  cont("\n");
                  system("clear");
                  goto MANAARMORY;
                }//end of diamond staff already equipped
              break;
              default:
                slow_print("\033[31mTHAT IS NOT AN OPTION!", speed);
                cont("\n");
                system("clear");
                goto MANAARMORY;
              break;
            }
          break;
          default:
            system("clear");
            slow_print("\033[31mTHAT IS NOT A CHOICE!", speed);
            cont("\n");
            system("clear");
            goto ARMORY;
          break;
        }//end of armory select switch
      break;
      case 5:
        //**********FORGERY**********//
        FORGERY:
        if(manaFragments < 0)
          manaFragments = 0;
        if(manaPotions < 0)
          manaPotions = 0;
        if(!powerful){
          cout << "\033[31mYou are not powerfull enough" << endl;
          cont();
        }
        else{
          slow_print("\033[33mWelcome to your Forgery!\n\n", speed);
          cout << "\033[36mMana Fragments: " << manaFragments << endl << endl;
          cout << "\033[33mWhich item would you like to forge?\n" << endl;
          cout << "\t\033[34m1) " + bronzeStaff << endl;
          cout << "\t\t\033[36m -costs 50 mana fragments and " << bronzeSword << endl;
          cout << "\t\t\033[31m -does 11 damage " << endl;
          cout << "\t\033[34m2) " + silverStaff << endl;
          cout << "\t\t\033[36m -costs 100 mana fragments and " << silverSword << endl;
          cout << "\t\t\033[31m -does 13 damage" << endl;
          cout << "\t\033[34m3) " + goldStaff << endl;
          cout << "\t\t\033[36m -costs 150 mana fragments and " << goldSword << endl;
          cout << "\t\t\033[31m -does 15 damage" << endl;
          cout << "\t\033[34m4) " + diamondStaff << endl;
          cout << "\t\t\033[36m -costs 200 mana fragments and " << diamondSword << endl;
          cout << "\t\t\033[31m -does 20 damage" << endl;
          cout << "\t\033[34m5) " + emblem << endl;
          cout << "\t\t\033[36m -costs 50 mana fragments and every \033[33mtalisman" << endl;
          cout << "\t\t\033[31m -Gives gold and damage effects, along with increasing max health and mana to 200" << endl;
          cout << "\t\033[34m6) Mana Potion" << endl;
          cout << "\t\t\033[36m -costs 3 mana fragments and 1 \033[32mhealing potion" << endl;
          cout << "\t\t\033[31m -Heals 100 Mana" << endl;
          cout << "\t\033[34m7) \033[35mRestoration Potion" << endl;
          cout << "\t\t\033[36m -costs 1 \033[32mhealing potion\033[36m, 1 \033[34mmana potion\033[36m, and 5 mana fragments" << endl;
          cout << "\t\t\033[31m -Heals 150 of both \033[36mmana \033[31mand \033[32mhealth" << endl;
          cout << "\033[36mEnter choice\n\033[31m>\033[32m";
          if(!(cin >> shopChoice)){
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "\033[31mTHAT IS NOT AN OPTION!" << endl;
            cont();
            system("clear");
            goto FORGERY;
          }//end of input
          switch(shopChoice){
            case 0:
              system("clear");
            break;
            case 1:
              if((manaFragments >= 50 && manaWeponArmory[0] != bronzeStaff && swordArmory[0] == bronzeSword) || devMode){
                manaFragments -= 50;
                manaWeponArmory[0] = bronzeStaff;
                swordArmory[0] = "";
                if(equippedSword == bronzeSword){
                  equippedSword = "";
                  damage = 0;
                }
                slow_print("\033[32mYou have created the " + bronzeStaff + "\033[32m!", speed);
                cont("\n");
                system("clear");
                goto FORGERY;
              }//end of create bronze staff
              else if(manaWeponArmory[0] == bronzeStaff){
                slow_print("\033[31mYou already own this staff!", speed);
                cont("\n");
                system("clear");
                goto FORGERY;
              }//end of already have staff
              else if(manaFragments < 50 || swordArmory[0] != bronzeSword){
                slow_print("\033[31mYou don't have enough supplies to make this item!", speed);
                cont("\n");
                system("clear");
                goto FORGERY;
              }//end of not enough fragments
            break;
            case 2:
              if((manaFragments >= 100 && manaWeponArmory[1] != silverStaff && swordArmory[1] == silverSword) || devMode){
                manaFragments -= 100;
                manaWeponArmory[1] = silverStaff;
                swordArmory[1] = "";
                if(equippedSword == silverSword){
                  equippedSword = "";
                  damage = 0;
                }
                slow_print("\033[32myou have created the " + silverStaff + "\033[32m!", speed);
                cont("\n");
                system("clear");
                goto FORGERY;
              }//end of create silver staff
              else if(manaWeponArmory[1] == silverStaff){
                slow_print("\033[31mYou already own this staff!", speed);
                cont("\n");
                system("clear");
                goto FORGERY;
              }//end of already have staff
              else if(manaFragments < 100 || swordArmory[1] != silverSword){
                slow_print("\033[31mYou don't have enough supplies to make this item!", speed);
                cont("\n");
                system("clear");
                goto FORGERY;
              }//end of not enough supplies
            break;
            case 3:
              if((manaFragments >= 150 && manaWeponArmory[2] != goldStaff && swordArmory[2] == goldSword) || devMode){
                manaFragments -= 150;
                manaWeponArmory[2] = goldStaff;
                swordArmory[2] = "";
                if(equippedSword == goldSword){
                  equippedSword = "";
                  damage = 0;
                }
                slow_print("\033[32mYou have created the " + goldStaff + "\033[32m!", speed);
                cont("\n");
                system("clear");
                goto FORGERY;
              }//end of create gold staff
              else if(manaWeponArmory[2] == goldStaff){
                slow_print("\033[31mYou already own this staff!", speed);
                cont("\n");
                system("clear");
                goto FORGERY;
              }//end of already have staff
              else if(manaFragments < 150 || swordArmory[2] != goldSword){
                slow_print("\033[31mYou don't have enough supplies to make this item!", speed);
                cont("\n");
                system("clear");
                goto FORGERY;
              }//end of not enough supplies
            break;
            case 4:
              if((manaFragments >= 200 && manaWeponArmory[3] != diamondStaff && swordArmory[3] == diamondSword) || devMode){
                manaFragments -= 200;
                manaWeponArmory[3] = diamondStaff;
                swordArmory[3] = "";
                if(equippedSword == diamondSword){
                  equippedSword = "";
                  damage = 0;
                }
                slow_print("\033[32mYou have created the " + diamondStaff + "\033[32m!", speed);
                cont("\n");
                system("clear");
                goto FORGERY;
              }//end of create diamond staff
              else if(manaWeponArmory[3] == diamondStaff){
                slow_print("\033[31mYou already own this staff!", speed);
                cont("\n");
                system("clear");
                goto FORGERY;
              }//end of already have staff
              if(manaFragments < 200 || swordArmory[3] != diamondSword){
                slow_print("\033[31mYou don't have enough supplies to make this item!", speed);
                cont("\n");
                system("clear");
                goto FORGERY;
              }
            break;
            case 5:
              if((manaFragments >= 50 && talismanOfDestruction && talismanOfRebirth && talismanOfTreasure) || devMode){
                manaFragments -= 50;
                talismanOfRebirth = 0;
                talismanOfTreasure = 0;
                talismanOfDestruction = 0;
                avengerEmblem = 1;
                if(equippedTalisman == treasure)
                  treasureBuff("-");
                equippedTalisman = "";
                slow_print("\033[32mYou have forged the " + emblem + "\033[32m!", speed);
                cont("\n");
                system("clear");
                goto FORGERY;
              }//end of make emblem
              else if(avengerEmblem){
                slow_print("\033[31mYou already own this item!", speed);
                cont("\n");
                system("clear");
                goto FORGERY;
              }//end of already have emblem
              else if(!talismanOfRebirth || !talismanOfTreasure || !talismanOfDestruction){
                slow_print("\033[31mYou are missing one or more of the talismans needed!", speed);
                cont("\n");
                system("clear");
                goto FORGERY;
              }//end of missing talisman
            break;
            case 6:
              if((manaFragments >= 3 && healingPotions > 0) || devMode){
                manaPotions++;
                manaFragments -= 3;
                healingPotions--;
                slow_print("\033[32mYou have created a \033[34mMana Potion\033[32m!", speed);
                cont("\n");
                system("clear");
                goto FORGERY;
              }//end of make mana potion
              else if(manaFragments < 3){
                slow_print("\033[31mYou dont have enough mana fragments for this item!\033[31m\033[31m Your very poor", speed);
                cont("\n");
                system("clear");
                goto FORGERY;
              }//end of not enough fragments
              else if(healingPotions <= 0){
                slow_print("\033[31mYou dont have enough healing potions!", speed);
                cont("\n");
                system("clear");
                goto FORGERY;
              }//end of not enough healing potions
            break;
            case 7:
              if((manaFragments >= 5 && healingPotions > 0 && manaPotions > 0) || devMode){
                manaFragments -= 5;
                healingPotions--;
                manaPotions--;
                restorationPotions++;
                slow_print("\033[32mYou have created a \033[35mrestoration potion\033[32m!", speed);
                cont("\n");
                system("clear");
                goto FORGERY;
              }//end of make restoration potion
              else if(manaFragments < 5){
                slow_print("\033[31mYou dont have enough fragments to make this!", speed);
                cont("\n");
                system("clear");
                goto FORGERY;
              }//end of not enough fragments
              else if(healingPotions <= 0 || manaPotions <= 0){
                slow_print("\033[31mYou dont have enough potions for this item!", speed);
                cont("\n");
                system("clear");
                goto FORGERY;
              }//end of not enough potions
            break;
            default:
              system("clear");
              cout << "\033[31mTHAT IS NOT AN OPTION!" << endl;
              cont();
              system("clear");
              goto FORGERY;
            break;
          }//end of forgery switch
        }//end of enter forgery else
        system("clear");
      break;
      case 6:
        //**********STATS**********//
        cout << "\033[32mWelcome to Statistics!" << endl;
        cout << "You have killed " << worm.kills << " worms\nYou have killed " << zombie.kills << " zombies\nYou have killed " << demihuman.kills << " Demi-Humans\nYou have killed " << goblin.kills << " goblins\nYou have killed " << wizard.kills << " Rouge Wizards\nYou have killed " << slime.kills << " Slimes\nYou have killed " << weakassassin.kills << " Weak Assassins\nYou have killed " << fGolem.kills << " Fire Golems\nYou have killed " << iGolem.kills << " Ice Golems\nYou have killed " << eGolem.kills << " Earth Golems\nYou have killed " << boss.kills << " Final Bosses\n\nYou have opened " << cratesOpened << " Crates in the Abandoned Town\nYou have opened " << chestsOpened << " Chests in the Dungeon" << endl;
        cont();
      break;
      case 7:
        //**********POTIONS**********//
        POTIONS:
        cout << "\033[32mHealth: " << health << endl;
        cout << "\033[34mMana: " << mana << endl;
        cout << "\033[31mWelcome to the potions section!" << endl;
        cout << "\033[0m[1]\033[32m Healing Potions: " << healingPotions << endl;
        cout << "\033[0m[2]\033[34m Mana Potions: " << manaPotions << endl;
        cout << "\033[0m[3]\033[35m Restoration Potions: " << restorationPotions << endl;
        cout << "\033[37mWhich one would you like to use: ";
        if(!(cin >> equipChoice)){
          cin.clear();
          cin.ignore(10000, '\n');
          cout << "\033[31mTHAT IS NOT AN OPTION!" << endl;
          cont();
          system("clear");
          goto POTIONS;
        }//end of input
        switch(equipChoice){
          case 0:
            system("clear");
            if(moveToFight == "demihuman"){
              system("clear");
              moveToFight = "";
              goto DFIGHT;
            }
            else if(moveToFight == "zombie"){
              system("clear");
              moveToFight = "";
              goto ZFIGHT;
            }
            else if(moveToFight == "worm"){
              system("clear");
              moveToFight = "";
              goto WOFIGHT;
            }
            else if(moveToFight == "goblin"){
              system("clear");
              moveToFight = "";
              goto GFIGHT;
            }
            else if(moveToFight == "wizard"){
              system("clear");
              moveToFight = "";
              goto WFIGHT;
            }
            else if(moveToFight == "slime"){
              system("clear");
              moveToFight = "";
              goto SFIGHT;
            }
            else if(moveToFight == "assassin"){
              system("clear");
              moveToFight = "";
              goto WAFIGHT;
            }
            else if(moveToFight == "firegolem"){
              system("clear");
              moveToFight = "";
              goto FGFIGHT;
            }
            else if(moveToFight == "icegolem"){
              system("clear");
              moveToFight = "";
              goto IGFIGHT;
            }
            else if(moveToFight == "earthgolem"){
              system("clear");
              moveToFight = "";
              goto EGFIGHT;
            }
            else if(moveToFight == "boss"){
              system("clear");
              moveToFight = "";
              goto BOSSFIGHT;
            }
            else if(moveToFight == "potion1"){
              system("clear");
              moveToFight = "";
              goto POTIONUSE1;
            }
            else if(moveToFight == "potion2"){
              system("clear");
              moveToFight = "";
              goto POTIONUSE2;
            }
            else if(moveToFight == "potion3"){
              system("clear");
              moveToFight = "";
              goto POTIONUSE3;
            }
          break;
          case 1:
            if(healingPotions > 0 && health < maxHealthMana){
              cout << "\033[32mYou used a healing potion and healed 100 health!\033[0m" << endl;
              heal("health");
              cont();
              system("clear");
              goto POTIONS;
            }//end of Healing Potion use
            else if(healingPotions == 0){
              cout << "\033[31mYou dont have any healing potions!\033[0m" << endl;
              cont();
              system("clear");
              goto POTIONS;
            }//end of dont have potions
            else if(health >= maxHealthMana){
              cout << "\033[31mYour already at full health!\033[0m" << endl;
              cont();
              system("clear");
              goto POTIONS;
            }//end of health full
          break;
          case 2:
            if(manaPotions > 0 && mana < maxHealthMana){
              cout << "\033[32mYou used a \033[34mmana potion\033[32m and healed 100 health!\033[0m" << endl;
              heal("mana");
              cont();
              system("clear");
              goto POTIONS;
            }//end of Mana Potion use
            else if(manaPotions == 0){
              cout << "\033[31mYou dont have any healing potions!\033[0m" << endl;
              cont();
              system("clear");
              goto POTIONS;
            }//end of dont have potions
            else if(mana >= maxHealthMana){
              cout << "\033[31mYour already at full \033[34mmana!\033[0m" << endl;
              cont();
              system("clear");
              goto POTIONS;
            }//end of mana full
          break;
          case 3:
            if(restorationPotions > 0 && (health < maxHealthMana || mana < maxHealthMana)){
              heal("restore", 150);
              cout << "\033[32mYou have used a \033[35mRestoration Potion\033[32m!" << endl;
              cont();
              system("clear");
              goto POTIONS;
            }//end of restoration potion use
            else if(restorationPotions <= 0){
              cout << "\033[31mYou do not have any \033[35mrestoration potions\033[31m!" << endl;
              cont();
              system("clear");
              goto POTIONS;
            }//end of dont have restoration potions
            else if(health >= maxHealthMana && mana >= maxHealthMana){
              cout << "\033[31mYou already have full \033[32mhealth \033[31mand \033[34mmana\033[31m!" << endl;
              cont();
              system("clear");
              goto POTIONS;
            }//end of full health/mana
          break;
          default:
            slow_print("\033[31mTHAT IS NOT AN OPTION!", speed);
            cont("\n");
            system("clear");
            goto POTIONS;
          break;
        }
      break;
      case 8:
        //**********CHEATS**********//
        slow_print("\033[32mWelcome to cheat codes! \033[0m\n\033[32mPlease enter a code here(or type 0 to go back to menu): ", speed);
        cin >> cheatCode;
        if (cheatCode == "gold"){
					RETRYGOLD:
					cout << "\033[32m\nHow much?: ";
					if(!(cin >> cheatNum)){
						cin.clear();
						cin.ignore(10000, '\n');
						cout << "\033[31mTHAT IS NOT AN OPTION!" << endl;
						cont();
						system("clear");
						goto RETRYGOLD;
					}//end of input
          gold += cheatNum;
          cheatCode = "";
        }//end of infinite gold
        else if(cheatCode == "manafragments"){
					RETRYFRAGS:
					cout << "\033[32m\nHow much?: ";
					if(!(cin >> cheatNum)){
						cin.clear();
						cin.ignore(10000, '\n');
						cout << "\033[31mTHAT IS NOT AN OPTION!" << endl;
						cont();
						system("clear");
						goto RETRYFRAGS;
					}//end of input
          manaFragments += cheatNum;
          cheatCode = "";
        }//end of magic
        else if(cheatCode == "skullkey"){
          skullKey = 1;
          cheatCode = "";
        }//end of boss arena key
        else if(cheatCode == "sethealth"){
					RETRYHEALTH:
					cout << "\033[32m\nHow much?: ";
					if(!(cin >> cheatNum)){
						cin.clear();
						cin.ignore(10000, '\n');
						cout << "\033[31mTHAT IS NOT AN OPTION!" << endl;
						cont();
						system("clear");
						goto RETRYHEALTH;
					}//end of input
          health = cheatNum;
          cheatCode = "";
        }//end of infinite health
        else if(cheatCode == "sheilds"){
          shieldArmory[0] = bronzeSheild;
          shieldArmory[1] = silverSheild;
          shieldArmory[2] = goldSheild;
          shieldArmory[3] = diamondSheild;
          shieldArmory[4] = carrotShield;
          bronzeS.durability = bronzeS.defaultDura;
          silverS.durability = silverS.defaultDura;
          goldS.durability = goldS.defaultDura;
          diamondS.durability = diamondS.defaultDura;
          equippedShield = "";
          shieldDurability = 0;
          cheatCode = "";
        }//end of all sheilds
        else if(cheatCode == "healingpotions"){
					RETRYPOTIONS:
					cout << "\033[32m\nHow much?: ";
					if(!(cin >> cheatNum)){
						cin.clear();
						cin.ignore(10000, '\n');
						cout << "\033[31mTHAT IS NOT AN OPTION!" << endl;
						cont();
						system("clear");
						goto RETRYPOTIONS;
					}//end of input
          healingPotions += cheatNum;
          cheatCode = "";
        }//end of full restock for healing potions
        else if(cheatCode == "carrotsmasher"){
          swordArmory[4] = carrotSmasher;
          cheatCode = "";
        }//end of carrot smasher sword
        else if(cheatCode == "swords"){
          swordArmory[0] = bronzeSword;
          swordArmory[1] = silverSword;
          swordArmory[2] = goldSword;
          swordArmory[3] = diamondSword;
          swordArmory[4] = carrotSmasher;
          cheatCode = "";
        }//end of all swords
        else if(cheatCode == "infect"){
          infected = 1;
          cheatCode = "";
        }//end of infect
        else if(cheatCode == "talismans"){
          equippedTalisman = "";
          talismanOfDestruction = 1;
          talismanOfRebirth = 1;
          talismanOfTreasure = 1;
          avengerEmblem = 1;
          cheatCode = "";
        }
        else
          cheatCode = "";
      break;
      /*****SETTINGS*****/
      case 9:
        SETTINGS:
        system("clear");
        cout << "\033[32mWelcome to settings!" << endl;
        cout << "\t1) Game Speed\n\t2) Difficulty Change\n\t3) Change Username\n\t4) Save Progress to Name" << endl;
        cout << "Where would you like to go (\033[0menter 0 to return to menu\033[32m): \033[0m";
        if(!(cin >> settingsChoice)){
          cin.clear();
          cin.ignore(10000, '\n');
          cout << "\033[31mTHAT IS NOT AN OPTION!" << endl;
          cont();
          system("clear");
          goto SETTINGS;
        }//end of input
        switch(settingsChoice){
          case 1:
            SPEED:
            system("clear");
            cout << "\033[34mGame Speed:" << endl;
            cout << "\033[36mCurrent speed: " << speedShow << endl;
            cout << "\033[30m***Default: 40***" << endl;
            cout << "\033[33mEnter a number between 0 and 100(The higher the faster it goes): ";
            if(!(cin >> speedShow)){
              cin.clear();
              cin.ignore(10000, '\n');
              cout << "\033[31mTHAT IS NOT AN OPTION!" << endl;
              cont();
              system("clear");
              goto SPEED;
            }//end of input
            if(speedShow > 100){
              cout << "\n\033[31mTHE SPEED ENTERED IS TOO HIGH!" << endl;
              cont();
              speedShow = 100 - speed;
              goto SPEED;
            }
            speed = 100 - speedShow;
            cout << "\033[32mThe speed is now set to " << speedShow << "%" << endl;
            cont();
            goto SETTINGS;
          break;
          case 2:
          DIFCHANGE:
            system("clear");
            cout << "\033[36mCurrent Difficulty: " << difficulty << endl;
            cout << "\033[32mWhich one would you like to select?\033[0m" << endl;
            cout << "\033[0m[1] \033[32mEasy\t\033[0m[2] \033[34mMedium\t\033[0m[3] \033[31mHard" << endl;
            if(!(cin >> equipChoice)){
              cin.clear();
              cin.ignore(10000, '\n');
              cout << "\033[31mTHAT IS NOT AN OPTION!" << endl;
              cont();
              system("clear");
              goto DIFCHANGE;
            }//end of input
            switch(equipChoice){
              case 0:
                difChange("dev");
                goto SETTINGS;
              break;
              case 1:
                difChange("easy");
                goto SETTINGS;
              break;
              case 2:
                difChange("normal");
                goto SETTINGS;
              break;
              case 3:
                difChange("hard");
                goto SETTINGS;
              break;
              default:
                cout << "\033[31mTHAT IS NOT AN OPTION!";
                cont();
                goto SETTINGS;
              break;
            }
            goto SETTINGS;
          break;
          case 3:
            system("clear");
            cout << "\033[36mCurrent Name: \033[33m" << userName << endl << endl;
            cout << "\033[36mWhat would you like your new name to be?: \033[32m";
            cin.ignore();
            getline(cin, userName, '\n');
            cout << "\033[36m\nYour new name is: \033[32m" << userName << endl;
            cont();
            goto SETTINGS;
          break;
          case 4:
            ofstream Save(userName + ".txt");

            Save << userName << "'s stats: \nEnemies Killed: \nWorms: " << to_string(worm.kills) << "\nZombies: " << to_string(zombie.kills) << "\nDemi-Humans: " << to_string(demihuman.kills) << "\nGoblins: " << to_string(goblin.kills) << "\nWeak Assassin: " << to_string(weakassassin.kills) << "\nRougue Wizard: " << to_string(wizard.kills) << "\nSlime: " << to_string(slime.kills) << "\nFire Golem: " << to_string(fGolem.kills) << "\nIce Golem: " << to_string(iGolem.kills) << "\nEarth Golem: " << to_string(eGolem.kills) << "\n???: " << to_string(boss.kills);

            Save.close();
          break;
        }//end of settings switch
      break;
      case 10:
        if(!skullKey){
          cout << "\n\033[31mTHAT IS NOT A CHOICE!\033[0m\n" << endl;
          cont();
        }//end of dont have boss key
        if(skullKey){
          fGolem.health = fGolem.defaultHealth;
          iGolem.health = iGolem.defaultHealth;
          eGolem.health = eGolem.defaultHealth;
          boss.health = boss.defaultHealth;
          usleep(999999);
          slow_print("\033[36mYou walk down the trail towards the \033[31mValley of Death\033[36m when suddenly you come across a door. \033[36m\033[36mYou use your \033[37mSkull Key\033[36m to open it!\n", speed);
          usleep(999999);
          system("clear");
          cout << "\033[32mYour health: " << health << endl;
          cout << "\033[34mYour mana: " << mana << endl;
          cout << "\033[31mEnemies health: " << fGolem.health << endl;
          slow_print("\033[36mYou walk foward and see your first enemy,\033[31m The Fire Golem!", speed);
          system("clear");
          while(fGolem.health > 0){
            FGFIGHT:
            cout << "\033[32mYour health: " << health << endl;
            cout << "\033[34mYour mana: " << mana << endl;
            cout << "\033[31mEnemies health: " << fGolem.health << endl;
            cout << "\033[36mYou walk foward and see your first enemy,\033[31m The Fire Golem!\033[0m" << endl;
            cout << "\033[0m[1] \033[31mMelee Attack  \033[0m[2] \033[34mMana Attack  \033[0m[3] \033[32mUse potion \033[0m[4] \033[33mGo to armory\033[0m" << endl;
            cout << "\033[36mEnter choice here: \033[33m";
            if(!(cin >> fightRun)){
              cin.clear();
              cin.ignore(10000, '\n');
              cout << "\033[31mTHAT IS NOT AN OPTION!" << endl;
              cont();
              system("clear");
              goto FGFIGHT;
            }//end of input

            switch(fightRun){
              case 1:
                if(equippedTalisman == destruction || equippedTalisman == emblem)
                  damage *= 2;
                fGolem.health -= damage;
                if(infected)
                  fGolem.damage *= 2;
                block(equippedShield);
                if(!blocked){
                  health -= fGolem.damage;
                  cout << "\033[31mThe Fire Golem attacked you and did " << fGolem.damage << " damage, leaving you at \033[32m" << health << " health!" << endl;
                }//end of not blocked
                cout << "\033[32mYou attacked the \033[31mFire Golem\033[32m with your " << equippedSword << "\033[32m and did " << damage << " damage, leaving it at " << fGolem.health << " health" << endl;
                blocked = 0;
                if(equippedTalisman == destruction || equippedTalisman == emblem)
                  damage /= 2;
                if(infected)
                  fGolem.damage /= 2;
                cont();
                system("clear");
                if(health <= 0)
                  goto DEATH;
              break;
              case 2:
                if(equippedTalisman == destruction || equippedTalisman == emblem)
                  manaDamage *= 1.5;
                if(infected)
                  fGolem.damage *= 2;
                block(equippedShield);
                if(!blocked){
                  health -= fGolem.damage;
                  cout << "\033[31mThe Fire Golem attacked you and did " << fGolem.damage << " damage, leaving you at " << health << " health!" << endl;
                }//end of not blocked
                if(mana >= manaUsage){
                  fGolem.health -= manaDamage;
                  mana -= manaUsage;
                  cout << "\033[32mYou shot the \033[31mFire Golem\033[32m with your magic staff and did " << manaDamage << " damage to it, leaving it at " << fGolem.health << " health" << endl;
                }
                else
                  slow_print("\033[31mYOU DONT HAVE ENOUGH MANA TO ATTACK\n", speed);
                if(equippedTalisman == destruction || equippedTalisman == emblem)
                  manaDamage /= 1.5;
                if(infected)
                  fGolem.damage /= 2;
                blocked = 0;
                cont();
                system("clear");
                if(health <= 0)
                  goto DEATH;
              break;
              case 3:
                moveToFight = "firegolem";
                system("clear");
                goto POTIONS;
              break;
              case 4:
                system("clear");
                moveToBoss = 1;
                goto ARMORY;
              break;
              default:
                cout << "\033[31mTHAT IS NOT AN OPTION!\033[0m" << endl;
                cont();
                system("clear");
                goto FGFIGHT;
              break;
            }//end of Fire golem switch
          }//end of fire golem loop
          gold += fGolem.gold;
          fGolem.kills++;
          ran(randomFragments, 30, 10);
          manaFragments += randomFragments;
          slow_print("\033[32mYou defeated the \033[31mFire Golem\033[32m and gained \033[33m", speed);
          cout << fGolem.gold;
          slow_print(" gold\033[32m and \033[36m", speed);
          cout << randomFragments;
          slow_print(" Mana Fragments!", speed);
          cont("\n");
          system("clear");
          usleep(999999);
          slow_print("\033[36mThe \033[31mFire Golem\033[36m falls to the ground after you defeat it. \033[36m\nYou see a door open behind it.\033[36m Would you like to use any potions before continuing?\n", speed);
          cout << "\033[0m[1] \033[32mYes  [2] \033[31mNo\n\033[0mPlease enter choice here: ";
          cin >> healOrGo;
          system("clear");
          if(healOrGo == 1){
            moveToFight = "potion1";
            goto POTIONS;
          }//end of use healing potion before continuing
          POTIONUSE1:
          system("clear");
          usleep(999999);
          slow_print("\033[36mYou walk through the door into some kind of \033[37mfrozen tundra\033[36m. There are ice spikes everywhere.", speed);
          usleep(999999);
          system("clear");
          slow_print("Suddenly the ice spikes start to come together to form the shape of a new golem!", speed);
          usleep(999999);
          system("clear");
          cout << "\033[32mYour health: " << health << endl;
          cout << "\033[34mYour mana: " << mana << endl;
          cout << "\033[31mEnemies health: " << iGolem.health << endl;
          slow_print("\033[36mYou find your next enemy, the \033[37mIce Golem!\n", speed);
          system("clear");
          while(iGolem.health > 0){
            IGFIGHT:
            cout << "\033[32mYour health: " << health << endl;
            cout << "\033[34mYour mana: " << mana << endl;
            cout << "\033[31mEnemies health: " << iGolem.health << endl;
            cout << "\033[36mYou find your next enemy, the \033[37mIce Golem!" << endl;
            cout << "\033[0m[1] \033[31mMelee Attack  \033[0m[2] \033[34mMana Attack  \033[0m[3] \033[32mUse potion \033[0m[4] \033[33mGo to armory\033[0m" << endl;
            cout << "\033[36mEnter choice here: \033[33m";
            if(!(cin >> fightRun)){
              cin.clear();
              cin.ignore(10000, '\n');
              cout << "\033[31mTHAT IS NOT AN OPTION!" << endl;
              cont();
              system("clear");
              goto IGFIGHT;
            }//end of input

            switch(fightRun){
              case 1:
                if(equippedTalisman == destruction || equippedTalisman == emblem)
                  damage *= 2;
                iGolem.health -= damage;
                if(infected)
                  iGolem.damage *= 2;
                block(equippedShield);
                if(!blocked){
                  health -= iGolem.damage;
                  cout << "\033[31mThe \033[37mIce Golem\033[31m attacked you and did " << iGolem.damage << " damage, leaving you at \033[32m" << health << " health!" << endl;
                }//end of blocked
                cout << "\033[32mYou attacked the \033[37mIce Golem\033[32m with your " << equippedSword << "\033[32m and did " << damage << " damage, leaving it at " << iGolem.health << " health" << endl;
                blocked = 0;
                if(equippedTalisman == destruction || equippedTalisman == emblem)
                  damage /= 2;
                if(infected)
                  iGolem.damage /= 2;
                cont();
                if(health <= 0)
                  goto DEATH;
                system("clear");
              break;
              case 2:
                if(equippedTalisman == destruction || equippedTalisman == emblem)
                  manaDamage *= 1.5;
                if(infected)
                  iGolem.damage *= 2;
                block(equippedShield);
                if(!blocked){
                  health -= iGolem.damage;
                  cout << "\033[31mThe \033[37mIce Golem\033[31m attacked you and did " << fGolem.damage << " damage, leaving you at " << health << " health!" << endl;
                }//end of not blocked
                if(mana >= manaUsage){
                  iGolem.health -= manaDamage;
                  mana -= manaUsage;
                  cout << "\033[32mYou shot the \033[37mIce Golem\033[32m with your magic staff and did " << manaDamage << " damage to it, leaving it at " << iGolem.health << " health" << endl;
                }
                else
                  slow_print("\033[31mYOU DONT HAVE ENOUGH MANA TO ATTACK\n", speed);
                blocked = 0;
                if(equippedTalisman == destruction || equippedTalisman == emblem)
                  manaDamage /= 1.5;
                if(infected)
                  iGolem.damage /= 2;
                cont();
                system("clear");
                if(health <= 0)
                  goto DEATH;
              break;
              case 3:
                moveToFight = "icegolem";
                system("clear");
                goto POTIONS;
              break;
              case 4:
                system("clear");
                moveToBoss = 2;
                goto ARMORY;
              break;
              default:
                cout << "\033[31mTHAT IS NOT AN OPTION!\033[0m" << endl;
                cont();
                system("clear");
                goto IGFIGHT;
              break;
            }//end of ice Golem switch
          }//end of ice golem fight loop
          system("clear"); 
          gold += iGolem.gold;
          iGolem.kills++;
          ran(randomFragments, 40, 10);
          manaFragments += randomFragments;
          slow_print("\033[32mYou defeated the \033[37mIce Golem\033[32m and gained \033[33m", speed);
          cout << eGolem.gold;
          slow_print(" gold\033[32m and \033[36m", speed);
          cout << randomFragments;
          slow_print(" Mana Fragments!", speed);
          cont("\n");
          system("clear");
          usleep(999999);
          slow_print("\033[36mThe \033[37mIce Golem\033[36m shattered into thousands of small pieces. You see another door behind where the \033[37mIce Golem\033[36m was. \nWould you like to use a potion before continuing?\n", speed);
          cout << "\033[0m[1] \033[32mYes  \033[0m[2] \033[31mNo\n\033[0mPlease enter choice here: ";
          cin >> healOrGo;
          system("clear");
          if(healOrGo == 1){
            moveToFight = "potion2";
            goto POTIONS;
          }//end of use healing potion before continuing
          POTIONUSE2:
          system("clear");
          usleep(999999);
          slow_print("\033[36mYou walk through the door into some kind of \033[32mmountainous jungle\033[36m area.", speed);
          usleep(999999);
          system("clear");
          usleep(666666);
          slow_print("\033[36mSuddenly, a nearby rock stand up and starts approaching you! Its the \033[33mEarth Golem!\033[36m", speed);
          usleep(999999);
          system("clear");
          cout << "\033[32mYour health: " << health << endl;
          cout << "\033[34mYour mana: " << mana << endl;
          cout << "\033[31mEnemies health: " << eGolem.health << endl;
          slow_print("\033[36mYou find your next enemy, the \033[33mEarth Golem!\n", speed);
          system("clear");
          while(eGolem.health > 0){
            EGFIGHT:
            cout << "\033[32mYour health: " << health << endl;
            cout << "\033[34mYour mana: " << mana << endl;
            cout << "\033[31mEnemies health: " << eGolem.health << endl;
            cout << "\033[36mYou find your next enemy, the \033[33mEarth Golem!" << endl;
            cout << "\033[0m[1] \033[31mMelee Attack  \033[0m[2] \033[34mMana Attack  \033[0m[3] \033[32mUse potion \033[0m[4] \033[33mGo to armory\033[0m" << endl;
            cout << "\033[36mEnter choice here: \033[33m";
            if(!(cin >> fightRun)){
              cin.clear();
              cin.ignore(10000, '\n');
              cout << "\033[31mTHAT IS NOT AN OPTION!" << endl;
              cont();
              system("clear");
              goto EGFIGHT;
            }//end of input

            switch(fightRun){
              case 1:
                if(equippedTalisman == destruction || equippedTalisman == emblem)
                  damage *= 2;
                eGolem.health -= damage;
                if(infected)
                  eGolem.damage *= 2;
                block(equippedShield);
                if(!blocked){
                  health -= eGolem.damage;
                  cout << "\033[31mThe \033[33mEarth Golem\033[31m attacked you and did " << eGolem.damage << " damage, leaving you at \033[32m" << health << " health!" << endl;
                }//end of blocked
                cout << "\033[32mYou attacked the \033[33mEarth Golem\033[32m with your " << equippedSword << "\033[32m and did " << damage << " damage, leaving it at " << eGolem.health << " health" << endl;
                blocked = 0;
                if(equippedTalisman == destruction || equippedTalisman == emblem)
                  damage /= 2;
                if(infected)
                  eGolem.damage /= 2;
                cont();
                if(health <= 0)
                  goto DEATH;
                system("clear");
              break;
              case 2:
                if(equippedTalisman == destruction || equippedTalisman == emblem)
                  manaDamage *= 1.5;
                if(infected)
                  eGolem.damage *= 2;
                block(equippedShield);
                if(!blocked){
                  health -= eGolem.damage;
                  cout << "\033[31mThe \033[33mEarth Golem\033[31m attacked you and did " << eGolem.damage << " damage, leaving you at " << health << " health!" << endl;
                }//end of not blocked
                if(mana >= manaUsage){
                  eGolem.health -= manaDamage;
                  mana -= manaUsage;
                  cout << "\033[32mYou shot the \033[33mEarth Golem\033[32m with your magic staff and did " << manaDamage << " damage to it, leaving it at " << eGolem.health << " health" << endl;
                }
                else
                  slow_print("\033[31mYOU DONT HAVE ENOUGH MANA TO ATTACK\n", speed);
                if(equippedTalisman == destruction || equippedTalisman == emblem)
                  manaDamage /= 1.5;
                if(infected)
                  eGolem.damage /= 2;
                blocked = 0;
                cont();
                system("clear");
                if(health <= 0)
                  goto DEATH;
              break;
              case 3:
                moveToFight = "earthgolem";
                system("clear");
                goto POTIONS;
              break;
              case 4:
                system("clear");
                moveToBoss = 3;
                goto ARMORY;
              break;
              default:
                cout << "\033[31mTHAT IS NOT AN OPTION!\033[0m" << endl;
                cont();
                system("clear");
                goto EGFIGHT;
              break;
            }//end of earth golem switch
          }//end of earth golem loop
          gold += eGolem.gold;
          eGolem.kills++;
          ran(randomFragments, 50, 10);
          manaFragments += randomFragments;
          slow_print("\033[32mYou defeated the \033[33mEarth Golem\033[32m and gained \033[33m", speed);
          cout << eGolem.gold;
          slow_print(" gold\033[32m and \033[36m", speed);
          cout << randomFragments;
          slow_print(" Mana Fragments!", speed);
          cont("\n");
          system("clear");
          usleep(999999);
          slow_print("\033[36mThe \033[33mEarth Golem\033[36m falls to the floor and breaks into many pieces.\nYou see another door behind where he was with some kind of \033[37mBright Light\033[36m coming from it!\nWould you like to use a potion before continuing?\n", speed);
          cout << "\033[0m[1] \033[32mYes  [2] \033[31mNo\n\033[0mPlease enter choice here: ";
          cin >> healOrGo;
          system("clear");
          if(healOrGo == 1){
              moveToFight = "potion3";
              goto POTIONS;
          }//end of use healing potion before continuing
          POTIONUSE3:
          system("clear");
          usleep(999999);
          slow_print("\033[36mYou walk through the door and see a mysterious man standing at the top of a staircase.\033[36m The building your in is white and everthing is very bright.", speed);
          usleep(999999);
          system("clear");
          slow_print("\033[37mCome here my child. \033[37m\033[37mCome here \033[31m\033[31m" + userName, speed);
          usleep(1200000);
          system("clear");
          slow_print("\033[36mYou walk towards this mysterious man.\033[36m Is he god?\033[36m Is he a devil?\033[36m To you, it doesn't matter what he is. \033[36mYou feel a sense of happiness as you approach him.\033[36m He holds out his arms, welcoming you to his...\033[36m", speed);
          usleep(999999);
          system("clear");
          slow_print("Wait...\033[36m\033[36m\033[31m\nNo", speed);
          usleep(999999);
          system("clear");
          slow_print("\033[36mThe brightness of the room starts to fade,\033[30m darkness starts spreading all around the room.\033[36m \nThe man turns around to face you and he is the most scary looking thing you've ever seen.\033[36m \nYou realize that this is going to be the final fight. \033[36mThe \033[31mall or nothing\033[36m\n", speed);
          usleep(777777);
          for(int count = 0; count <= 3; count++){
            system("clear");
            cout << "\033[0m \033[47m              \033[0m " << endl;
            cout << "\033[47m   \033[43m          \033[47m   \033[43m" << endl;
            cout << "    \033[47m \033[44m  \033[43m  \033[44m  \033[47m \033[43m    " << endl;
            cout << "                " << endl;
            cout << "  \033[41m  \033[43m        \033[41m  \033[43m  " << endl;
            cout << "   \033[41m          \033[43m   " << endl;
            cout << "\033[0m \033[43m              \033[0m " << endl;
            usleep(666666);
            system("clear");

            cout << "\033[0m \033[47m              \033[0m " << endl;
            cout << "\033[47m   \033[43m          \033[47m   \033[43m" << endl;
            cout << "    \033[47m \033[44m  \033[43m  \033[44m  \033[47m \033[43m    " << endl;
            cout << "                " << endl;
            cout << "  \033[41m            \033[43m  " << endl;
            cout << "   \033[41m          \033[43m   " << endl;
            cout << "\033[0m \033[43m              \033[0m " << endl;
            usleep(666666);
          }
          system("clear");
          cout << "\033[0m \033[47m              \033[0m " << endl;
          cout << "\033[47m   \033[43m          \033[47m   \033[43m" << endl;
          cout << "    \033[0m   \033[43m  \033[0m   \033[43m    " << endl;
          cout << "                " << endl;
          cout << "  \033[41m            \033[43m  " << endl;
          cout << "   \033[41m          \033[43m   " << endl;
          cout << "\033[0m \033[43m              \033[0m " << endl;
          usleep(999999);
          system("clear");
          usleep(999999);
          cout << "\033[32mYour health: " << health << endl;
          cout << "\033[34mYour mana: " << mana << endl;
          cout << "\033[31m\?\?\?'s Health: " << boss.health << endl;
          slow_print("\033mYou are fighting \?\?\?!\n", speed);
          while(boss.health > 0){
            BOSSFIGHT:
            system("clear");
            cout << "\033[32mYour health: " << health << endl;
            cout << "\033[34mYour mana: " << mana << endl;
            cout << "\033[31m\?\?\?'s Health: " << boss.health << endl;
            if(infected)
              cout << "\033[32mYOU ARE INFECTED!" << endl;
            cout << "\033mYou are fighting \?\?\?!" << endl;
            cout << "\033[0m[1] \033[31mMelee Attack  \033[0m[2] \033[34mMana Attack  \033[0m[3] \033[32mUse potion \033[0m[4] \033[33mGo to armory\033[0m" << endl;
            cout << "\033[36mEnter choice here: \033[33m";
            if(!(cin >> fightRun)){
              cin.clear();
              cin.ignore(10000, '\n');
              cout << "\033[31mTHAT IS NOT AN OPTION!" << endl;
              cont();
              system("clear");
              goto BOSSFIGHT;
            }//end of input

            switch(fightRun){
              case 1:
                ran(boss.infChance, 10, 1);
                ran(missChance, 10, 1);
                block(equippedShield);
                if(equippedTalisman == destruction || equippedTalisman == emblem)
                  damage *= 2;
                if(infected)
                  boss.damage *= 2;
                if(!blocked){
                  health -= boss.damage;
                  cout << "\033[31m??? did " << boss.damage << " damage to you, leaving you at " << health << " health!" << endl;     
                }//end of boss attack
                if(missChance <= 2){
                  cout << "\033[31mYou swung at ??? but missed! His \033[30mdemonic laughter echoed through out the room." << endl;
                }//end of miss boss
                else{
                  boss.health -= damage;
                  cout << "\033[32mYou attacked ??? and did \033[31m" << damage << " damage\033[32m, leaving it at " << boss.health << " health!" << endl;
                }//end of attack boss
                blocked = 0;
                if(equippedTalisman == destruction || equippedTalisman == emblem)
                  damage /= 2;
                if(infected)
                  boss.damage /= 2;
                if(!blocked){
                  if(boss.infChance == 1){
                    infected = 1;
                    cout << "\033[31mThe boss infected you with its \033[32mdeadly virus\033[31m! He now does 2 times the damage to you!" << endl;
                  }//end of infection chance
                }//end of check block for infection
                cont();
                if(health <= 0)
                  goto DEATH;
              break;
              case 2:
                ran(boss.infChance, 10, 1);
                ran(missChance, 10, 1);
                block(equippedShield);
                if(equippedTalisman == destruction || equippedTalisman == emblem)
                  manaDamage *= 1.5;
                if(infected)
                  boss.damage *= 2;
                if(!blocked){
                  health -= boss.damage;
                  cout << "\033[31m??? did " << boss.damage << " damage to you, leaving you at " << health << " health!" << endl;   
                }//end of boss attacks
                if(missChance <= 3)
                  cout << "\033[31mYou shot at ??? but missed! His \033[30mdemonic laughter echoed through out the room." << endl;
                else{
                  if(mana >= manaUsage){
                    boss.health -= manaDamage;
                    mana -= manaUsage;
                    cout << "\033[32mYou shot at \033[31m???\033[32m with your magic staff and did " << manaDamage << " damage to it, leaving it at " << boss.health << " health" << endl;
                  }//end of attack boss with mana
                else
                  slow_print("\033[31mYOU DONT HAVE ENOUGH MANA TO ATTACK\n", speed);
                }//end of attempt to attack boss with mana
                blocked = 0;
                if(equippedTalisman == destruction || equippedTalisman == emblem)
                  manaDamage /= 1.5;
                if(infected)
                  boss.damage /= 2;
                if(!blocked){
                  if(boss.infChance == 1){
                    infected = 1;
                    cout << "\033[31mThe boss infected you with its \033[32mdeadly virus\033[31m! He now does 2 times the damage to you!" << endl;
                  }//end of infection chance
                }//end of check block for infection
                cont();
                system("clear");
                if(health <= 0)
                  goto DEATH;
              break;
              case 3:
                system("clear");
                moveToFight = "boss";
                goto POTIONS;
              break;
              case 4:
                system("clear");
                moveToBoss = 4;
                goto ARMORY;
              break;
              default:
                cout << "\033[31mTHATS NOT A CHOICE!" << endl;
                cont();
                goto BOSSFIGHT;
              break;
            }//end of boss fight switch
          }//end of boss loop
          system("clear");
          boss.kills++;
          powerful = 1;
          gold += boss.gold;
          ran(randomTalisman, 3, 1);
          slow_print("\033[32mYou defeated \033[31m???\033[32m and gained \033[33m", speed);
          cout << boss.gold;
          slow_print(" gold!\n\033[32m??? also left a \033[33mTalisman\033[32m on the floor!\033[32m Its the ", speed);
          if(randomTalisman == 1){
            cout << rebirth << "\033[32m!" << endl;
            if(talismanOfRebirth){
              cout << "\033[33mYou already have this talisman so you sold it instead for 40 gold!" << endl;
              gold += 40;
            }//end of sell talisman
            else
              talismanOfRebirth = 1;
          }
          else if(randomTalisman == 2){
            cout << destruction << "\033[32m!" << endl;
            if(talismanOfDestruction){
              cout << "\033[33mYou already have this talisman so you sold it instead for 40 gold!" << endl;
              gold += 40;
            }
            else
              talismanOfDestruction = 1;
          }
          if(randomTalisman == 3){
            cout << treasure << "\033[32m!" << endl;
            if(talismanOfTreasure){
              cout << "\033[33mYou already have this talisman so you sold it instead for 40 gold!" << endl;
              gold += 40;
            }
            else
              talismanOfTreasure = 1;
          }
          cont();

          usleep(999999);
          system("clear");
          slow_print("\033[31m\"\033[30mBUT HOW COULD I BE DEFEATED\033[31m\"\n", speed);
          usleep(555555);
          slow_print("\033[31mThis isnt over", speed);
          usleep(999999);
          system("clear");
          cout << "\033[0m \033[47m              \033[0m " << endl;
          cout << "\033[47m   \033[43m          \033[47m   \033[43m" << endl;
          cout << "    \033[0m   \033[43m  \033[0m   \033[43m    " << endl;
          cout << "                " << endl;
          cout << "  \033[41m            \033[43m  " << endl;
          cout << "   \033[41m          \033[43m   " << endl;
          cout << "\033[0m \033[43m              \033[0m " << endl;
          usleep(666666);
          system("clear");
          //second stage
          cout << "\033[0m \033[47m              \033[0m " << endl;
          cout << "\033[47m   \033[43m          \033[47m   \033[43m" << endl;
          cout << "    \033[0m   \033[43m  \033[0m   \033[43m    " << endl;
          cout << "      \033[47m    \033[43m      " << endl;
          cout << "  \033[41m            \033[43m  " << endl;
          cout << "   \033[41m          \033[43m   " << endl;
          cout << "\033[0m \033[43m              \033[0m " << endl;
          usleep(666666);
          system("clear");
          //third stage
          cout << "\033[0m \033[47m              \033[0m " << endl;
          cout << "\033[47m   \033[43m          \033[47m   \033[43m" << endl;
          cout << "    \033[0m   \033[47m  \033[0m   \033[43m    " << endl;
          cout << "      \033[47m    \033[43m      " << endl;
          cout << "  \033[41m     \033[47m  \033[41m     \033[43m  " << endl;
          cout << "   \033[41m          \033[43m   " << endl;
          cout << "\033[0m \033[43m              \033[0m " << endl;
          usleep(666666);
          system("clear");
          //fourth stage
          cout << "\033[0m \033[47m              \033[0m " << endl;
          cout << "\033[47m   \033[43m   \033[47m \033[43m  \033[47m \033[43m   \033[47m   \033[43m" << endl;
          cout << "    \033[0m   \033[47m  \033[0m   \033[43m    " << endl;
          cout << "     \033[47m      \033[43m     " << endl;
          cout << "  \033[41m     \033[47m  \033[41m     \033[43m  " << endl;
          cout << "   \033[41m   \033[47m \033[41m  \033[47m \033[41m   \033[43m   " << endl;
          cout << "\033[0m \033[43m              \033[0m " << endl;
          usleep(666666);
          system("clear");
          //fifth stage
          cout << "\033[0m \033[47m              \033[0m " << endl;
          cout << "\033[47m   \033[43m   \033[47m \033[43m  \033[47m \033[43m   \033[47m   \033[43m" << endl;
          cout << "    \033[47m  \033[0m \033[47m  \033[0m \033[47m  \033[43m    " << endl;
          cout << "   \033[47m \033[43m \033[47m      \033[43m \033[47m \033[43m   " << endl;
          cout << "  \033[41m  \033[47m  \033[41m \033[47m  \033[41m \033[47m  \033[41m  \033[43m  " << endl;
          cout << "   \033[41m   \033[47m \033[41m  \033[47m \033[41m   \033[43m   " << endl;
          cout << "\033[0m \033[43m              \033[0m " << endl;
          usleep(666666);
          system("clear");
          //sixth stage
          cout << "\033[0m \033[47m              \033[0m " << endl;
          cout << "\033[47m    \033[43m  \033[47m    \033[43m  \033[47m    \033[43m" << endl;
          cout << "\033[47m   \033[43m \033[47m        \033[43m \033[47m   \033[43m" << endl;
          cout << "   \033[47m \033[43m \033[47m      \033[43m \033[47m \033[43m   " << endl;
          cout << "  \033[41m  \033[47m        \033[41m  \033[43m  " << endl;
          cout << "\033[47m \033[43m  \033[47m  \033[41m \033[47m \033[41m  \033[47m \033[41m \033[47m  \033[43m  \033[47m " << endl;
          cout << "\033[0m \033[47m     \033[43m \033[47m  \033[43m \033[47m     \033[0m " << endl;
          usleep(666666);
          system("clear");
          //seventh stage
          cout << "\033[0m \033[47m              \033[0m " << endl;
          cout << "\033[47m                \033[43m" << endl;
          cout << "\033[47m   \033[43m \033[47m        \033[43m \033[47m   \033[43m" << endl;
          cout << "\033[47m  \033[43m \033[47m         \033[47m \033[43m \033[47m  \033[43m" << endl;
          cout << " \033[47m  \033[41m \033[47m        \033[41m \033[47m  \033[43m " << endl;
          cout << "\033[47m \033[43m  \033[47m          \033[43m  \033[47m " << endl;
          cout << "\033[0m \033[47m     \033[43m \033[47m  \033[43m \033[47m     \033[0m " << endl;
          usleep(666666);
          system("clear");
          //final stage
          cout << "\033[0m \033[47m              \033[0m " << endl;
          cout << "\033[47m                " << endl;
          cout << "                " << endl;
          cout << "                " << endl;
          cout << "                " << endl;
          cout << "                " << endl;
          cout << "\033[0m \033[47m              \033[0m " << endl;
          usleep(666666);
          system("clear");
          for(int count; count <= 20000; count++)
            cout << "\033[47m ";
          usleep(999999 * 2);
          system("clear");
          slow_print("\033[34m" + userName + ",\033[34m wake up.\033[34m\033[34m Your journey is not over yet", speed);
          cout << "\033[0m";
          usleep(999999 * 2);
          cout << string(100, '\n');
          usleep(999999);
          skullKey = 0;
          /*****DIFFICULTY INCREASE*****/
          if(difficulty == easy)
            difChange("normal");
          else if(difficulty == normal)
          difChange("hard");
        }//end of have boss key
      break;
      default:
        cout << "\n\033[31mTHAT IS NOT A CHOICE!\033[0m\n" << endl;
        cont();
      break;
    }//end of switch
  }//end of loop
}//e
