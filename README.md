# Text-Based Role Playing Game
This is a tutorial how to make a text-based rpg using c languange. Linked list is implemented in this code. This code is quite simple to make but it is not a short code.

## FLOWCHART

1. [RPG Flowchart](RPG.png)
2. [Adventure / Battle Flowchart](Adventure.png)
3. [Inventory Flowchart](Inventory.png)
4. [Shop Flowchart](Shop.png)


## TUTORIAL

Important steps to make text-based rpg

- Make two linked list for shop and inventory

  This step is important to make sure that items that in shop will not get mixed with item that in shop. Each linked list must    have the same struct.

- Insert item in shop first

  The next step is you need to insert the items in shop once. In this step you will need a marking to insert items to make sure the items will not inserted twice. After you insert items once, the marking will skip the insert code and right to shop display.

- Make buying function
  
  Buying function is used for player to buy the items if the player has enough money / gold. This function will contain two linked list where the shop linked list will delete the item and the inventory linked list will add the item.

- Random number generator
  
  Make a function to generate number with a minimum number and maximum number. This function will be used in the adventure / battle stage.

- Adventure
  
  Make a simple battle stage where you have turns and actions to defeat the enemy. The actions are attack, defend, inventory, and run. 
  Attack is for attacking enemy. Player's damage will be a random number added with the weapon damage 
  Defend is for blocking enemy damage. Player's block damage will be a random number between half player's defense an full player's defense
  Inventory is for open inventory and using potion.
  Run is for go back to lobby.
  Money / Gold loot will be random number.

- User Friendly

  Finishing step is make the program to be easily used by other people and if possible add some decoration (ASCII art).

