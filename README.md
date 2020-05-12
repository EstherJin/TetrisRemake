# Demo and Design Document

## 1.0 Demo

Starting Screen:
![](Demo%20Images/starting_screen.png)


Gameplay (supports different levels and keeps score):
![](Demo%20Images/game_play.png)


More gameplay to show all blocks the game generates (please don't judge tetris skill):
![](Demo%20Images/game_play2.png)


## 2.0 UML
![](Tetris%20UML.png)

## 3.0 Overview				

This section will discuss the overall flow of the project starting from main:

#### Main.cc:
Function: Initializes Game and Interpreter and passes user input toInterpreter

#### Interpreter Class:
Function: Process user input 
Connection to other classes: N/A
Implementation details: Maps a command to a list of command aliases. 
processCommands(string, Game*,  Int*): Finds the command and calls the corresponding command to Game through a pointer that main.cc passes it.

#### Game Class:
Function: Manages the two boards
Connection to other classes: Holds two Boards and a textDisplay
Implementation details: Acts based on the command and turn that is passed by Interpreter. For the turn/left/right drop commands, it calls the corresponding command for the board. It receives information from these commands such as number of lines cleared and it acts accordingly by adding a Board Decorator etc. 

#### Board, BasicBoard, Decorator, Heavy, Blind, Force:
Function: Is the Board of a player
Connection to other classes: Owned by Game. Owns Block1 for current and next block, owns a vector of Block2’s for the activeblocks on the board. Owns a Level for the level.
BasicBoard and Decorator extend Board. Heavy, Blind, Force extend Decorator. Decorator HASA board.
Implementation details of BasicBoard:
Uses a decorator pattern (elaborated below)
move(int)/turn(int)/down(Int): Calls Block1’s movePos(int)/ TurnPos(int)/ DownPos(Int) to receive a vector of the coordinates. Checks grid to see if it is the new coordinates are valid. If it is, call’s Block1’s move(int)/turn(int)/down(int).
dropblock(): Moves the Block1 down until it is no longer valid. Creates a Block2 based on the Block1 and deletes the Block1. Checks each row to see if a line is cleared. If so, erases that row from the grid and adds a new row at the top and informs all rows that their row has changed. Based on lines cleared, updates score. Checks all active blocks to see if any have been deleted and updates score and removes them accordingly. Sets currentblock to nextblock and checks if it is a valid position 
Changelevel(int): Updates the Level accordingly

#### Block1:
Function: Represents a block that has yet to be dropped.
Connection to other classes: Extends Subject, Subclasses include T/J/L/I/O/S/Z/Dot. Owned by Board
Implementation details:
Block1 is pure virtual but it implements down and move
Each Subclass is responsible for its own rotate
Any move/turn/downPos() function returns a vector of coordinates. move/turn/down() actually moves the Block1 and notifies observers (textDisplay/graphics) of changed position

#### Block2:
Function: Represents a dropped block on the grid
Connection to other classes: Owned by Board. Extends Observer Observes Cells. 
Implementation details
Observes the cells that make up the block. If the cell gets cleared, it will notify Block2 which reduces it’s cellCount field.

#### Row:
Function: Represents a row on the board
Connection to other classes: Owns a vector of Cells. Is owned by Board
Implementation details
Links Board with Cells
checkFull() returns if the row is full so the Board knows to clear
changeRowNum(int) calls changeRow() for all it’s cells
changeCell(int, char) calls Cell at int position’s changeCell function

#### Cell:
Function: Represents one Cell of a Board
Connection to other classes: Owned by Row. Is a Subject (to TextDisplay/graphics)
Implementation details
changeCell(char) changes Cell to char and notifies observers.
changeRow(int) notifies observers that current position is being cleared. Notifies observers with its new position.

#### Level, NonRandom, Random, Level1/2/3/4:
Function: 
Level is an abstract class that stores an integer that represents the current level the play is on
NonRandom is responsible for parsing data from the sequence files and returning the next character in the file
Random is an abstract class and Level1/2/3/4 inherit fields from Random
All Level’s (except abstract ones) can return info about the next block as a char
Connection to other classes:
All Level classes are owned by Board
Level classes (non-abstract) return a char. Within Board’s method nextBlock(), the char returned by Level is stored and used to update the nextBlock field in Board
Implementation details
Level: In this abstract class, we defined an accessor method to get an integer that represents the current level and also a changeLevel method to mutate the lvl field
NonRandom: In this class, we store an extra string field file that is the name of the sequence file we use, and an extra string field sequence that stores the current sequence of future Blocks that are to appear on screen.
nextBlock(): While the next Block is undetermined, initialize an istringstream with sequence and see if we can pass a character into a temporary char called block. If successful, cut off sequence by 2 characters and exit the loop. If not, that means sequence is empty, and we will update the sequence string to what’s stored in the original file
Random: Pass in an extra unsigned int field called seed (constructor only)
Level1/2/3/4: 
nextBlock(): use srand(seed) and rand() to generate an integer (according to the specifications) and enter if-else-if blocks. If the integer falls in the range of a particular Block1 character, we return the char

### Output classes:

#### StringGenerator:
Function: generate a string to represent one Board
Connection to other classes: owned by Board, is an Observer and gets notified by Subjects
Implementation details: loop through info in Board’s grid and return a string representation

#### TextDisplay:
Function: combine two strings that represent the two players’ Boards
Connection to other classes: owned by Game
Implementation details: get passed two strings from Game and combines the two strings 

#### GraphicsDisplay:
Function: display all graphics of each Board
Connection to other classes: get notified by Subject classes, uses Xwindow for display, owned by Board, is an Observer
Implementation details: according to each display specification, call Xwindow functions to fill rectangles or draw elements

#### Xwindow:
Function: calls Xlib functions to display graphics
Connection to other classes: owned by GraphicsDisplay
Implementation details: (used the implementation provided by A4Q5 and made changes to colours)


## 4.0 Design

In this section, we will be discussing changes in our design and design patterns we used to solve major challenges.

### Changes to design:
Return value of Level changed from Block1 to char
The use of Level is to inform a Board about what the upcoming block that will show up as well as to successfully update its nextBlock field
Since Board includes all classes of Block1’s, it would be unnecessary and more dangerous for Level’s nextBlock() to return a Block1. Instead, nextBLock() always returns a character representing the next block and Board will update it’s field according to the character through using a few if-else blocks. 
Added Row to Grid to better manage the cells 
When we started implementing, we realized that Board was implementing a lot of code for one row. We decided to add a row class to have some more abstraction.
Transferred all fields from Board to BasicBoard 
We realized our original UML implemented the Decorator design pattern incorrectly. It does not make sense for Board to have fields such as grid as a Decorator should not have an additional grid.
In general, added more fields to structures as we overlooked some aspects

### Design Patterns:
Vector (template class) and Iterator - vectors were used in fields of classes such as in BasicBoard to store Block2’s, to store Rows in grid, Cells in the Row class, and chars in StringGenerator. Vector helped us avoid more errors by automatically resizing for us, providing safer access to elements by using at(), providing iterators, helping us easily add and remove elements, and automatically deleting the heap allocated array when going out of scope so we didn’t have to use delete, reducing the chance of memory leaks. 
Factory - was used to create different Levels. This makes use of inheritance and each concrete Level inherits the nextBlock method 
Subject/Observer - In our design Block1 and Cell are Subjects. 
Decorator - was used on Board, with concrete class BasicBoard and Decorator subclasses Force, Heavy, and Blind. Decorators were used for adding and removing special effects, with a has-a relationship to a Board. So, Decorator also had a removeDecorator method to return the Board it had in the form of a shared pointer, since it was a has-a relationship. removeDecorator removes the special effect, and multiple special effects can be layered on simultaneously with the use of the Decorator design pattern. During runtime, these special effects can be implemented by creating a Decorator, initialized with the current board. 

## 5.0 Resilience to Change

### Supports extensions:
Adding new special effects with the decorator pattern:
We facilitate the process of adding new special effects by implementing the decorator pattern for Board. If we need to add a new feature, we can just create a new class that inherits Decorator with all the new methods. Since the new concrete board is an Object, we will not need to edit BasicBoard to invoke the new methods due to polymorphism 
Adding new levels with the factory pattern:
Adding new levels with the factor pattern is very easy since concrete Level objects inherit an abstract Level class and when nextBlock() is invoked to return a char, the factory pattern ensures that for each concrete Level, the correct random number generator is used because nextBlock() method is overridden. To add a new concrete Level, we just need to create a new Level class that inherits Random or NonRandom and include the desired nextBlock code. This means in Board, we don’t need to use else-if blocks to check the type of Level and instead we could just create an instance of Level and directly call its methods. This thus exemplifies good support for extensions.

### Low coupling:
Distinct modules are not heavily dependent on each other: 
To achieve this, we made sure that each class has its unique responsibility. For example, Board’s goal is to move blocks around and update scores according to the rules of the game. Block1’s are only responsible for figuring out where it will be moved based on instructions given by Board. Block2’s are only observing cells to know whether it’s deleted or not. Rows and Cells only contain information about their locations (for Board to access or mutate). Levels can only determine the current level and return the next Block. The implementation of these classes, therefore, are not dependent on the implementation of others. If new rules need to be applied for how Block1’s should be moved around, then Board doesn’t need to know how it was done. We would just need to change implementation of Block1 and Board’s method calls to Block1 still work. If new rules are set for Levels’ nextBlock method, then we only need to make corresponding changes and call the methods from Board with getNext

### Pure virtual methods:
We used pure virtual methods on multiple modules including Level’s and Block1’s. Abstract classes are great for promoting loose coupling because we want our base class to provide a default implementation for a function, but still force any derived classes to provide their own implementation for any add-ons. If any changes need to be implemented for the derived classes, we just need to fix a small part of our code in the derived class instead of changing everything. This also prevents the use of if-else structures to execute the correct methods. Also, virtual methods in general allow us to determine the correct subclass method to use without needing to dynamic cast or store a type field. 

### High cohesion:
Modules work closely together to complete a single task:
Level and its subclasses follow the factory design pattern with its only goal being to generate new Block1 types.
Block1 and its subclasses focus on calculating the position of a Block when moved.
Block2’s sole use is to inform Board to update score when it is deleted.
Cell and Row focus on when it’s state is changed, and notifies its observers.
Board and its subclasses focuses on the activity of a single player, and is used by Game to carry out commands from the player during their turn. 

### MVC:
We decoupled the interface to prevent having to make changes to Game or Board when editing features that involve display. The view classes GraphicsDisplay, StringGenerator, and TextDisplay were created for this purpose. Instead of letting Game or Board print the display, we let Board call StringGenerator and let Game call TextDisplay to combine the views for two Board’s. This is to make sure that when we make changes to the formatting of the display, we don’t have to keep on changing things in Game and Board, which are supposed to have control over important information of the game. This follows the Single Responsibility Principle. The controller is main.cc and Interpreter which takes in commands and issues them to the model and view in order to manipulate the game, and the model is Game which stores the data and follows commands from the controller. 

## 6.0 Possible Extensions and Features We are Proud of

1. If you wanted to introduce a new level in the system, you would simply need to create a new subclass of RandomLevel with the corresponding probabilities in the nextBlock() method. Then you would just need to recompile LevelX.cc, LevelX.h, main.cc, and Board.cc (Board.h can just contain a forward declaration of the Level class, so it does not require recompilation). 

2. To introduce more effects: our Board class follows the Decorator design pattern. So if you wanted to add multiple effects, you would simply add the decorations you wanted to the board. This prevents the program from having multiple if else branches. If more effects were created, we would just add another decorator subclass.

3. To accomodate the addition of new commands: as the commands field in the Interpreter class is a map made up of a base command name as a key and a vector of substitute command names as values, you would simply need to lookup the command key and add the new command name to the corresponding vector. You would also need to add a new rename command, where you lookup the key and append the value to the vector.
If we wanted to support a macro language, we would add a macros field to our interpreter with a type of map<string, vector<string>>. If the Interpreter could not find a command in the commands field and found it in the macros field, it would iterate through the vector of commands and execute each command. We would also need to add an addMacro() command that the user can use in the command line.

4. We were able to use unique/shared pointers/vectors for the fields in our classes. Therefore, we were able to avoid the use of delete that comes with arrays/raw pointers. This greatly simplified our destructors. 

## 7.0 Final Thoughts
		 	 	 		
#### 1. What lessons did this project teach us about developing software in teams?

One lesson we learned was the importance of planning before starting to code. Because our UML was very detailed, it was much easier to allocate work, and everyone had a clear understanding of what they needed to do. Also, a detailed UML showed how each class interacted with another, making it easy for people to work separately, since they only needed certain methods from other classes without needing to understand the implementation. Also, because we planned our design and the use of design patterns beforehand, we were able to avoid the many pitfalls that would come with poor design. Thus, our coding process went much smoother. 
Another lesson we learned was how to allocate work, which resulted directly from our good planning. Because we planned well and met up often to discuss the project specs, we had a general idea of how much work needed to be done for each module so we split up our work very evenly.
 							
#### 2. What would we have done differently if we had the chance to start over? 

One thing we would do differently is to research more before actually coding. A large problem we faced was figuring out how smart pointers worked, and it took a lot of time and energy to debug. For example, we didn’t know that shared pointers work better with Decorators that have a “has-a” relationship with Board, and using unique pointers kept giving us errors. But after hours of debugging, a quick Google search showed us that shared pointers would solve this problem. Doing research before writing code would have helped us fully understand and plan out what to do, as well as avoid potential problems that would require us to rewrite most of our code. Research may take more time in the beginning, but it saves a lot more in the long run. 
 						
					 				
			
		

