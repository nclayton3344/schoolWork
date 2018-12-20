using System;

namespace HuntTheWumpus
{
    class Program
    {
        static int[,] adjacentRooms; // adjacentRooms rectangular array. See CreateCave() for initialization.
        static int numRooms, currentRoom, startingPosition, mapChoice; // currentRoom is an integer variable that stores the room the player is currently in (between 0-20)
        static int wumpusRoom, batRoom1, batRoom2, pitRoom1, pitRoom2; // Stores the room numbers of the respective 
        static int wumpusStart, bat1Start, bat2Start;
        static bool playerAlive, wumpusAlive; // Are the player and wumpus still alive? True or false.
        static Random random = new Random(); // Our random number generator
        static int numArrows, playerScore, moveCount; //store player score, arrow count, and total moves made 
        static int[] treasureRooms; //for holding location of treasure chests
        static string[] highScores; //for loading and displaying saved high scores
        static string playerName = ""; //player name initialized to blank string
        static string[] saveData;

        //////////////////////////////////////////////////////////////////////////////////////////////////
        // CAVE STRUCTURES
        //////////////////////////////////////////////////////////////////////////////////////////////////
        static void CreateToroidal(){
            adjacentRooms = new int[,]         
            {
               {5, 9, 15}, {5, 6, 16}, {6, 7, 17}, {7, 8, 18}, {8, 9, 19},
               {0, 1, 14}, {1, 2, 10}, {2, 3, 11}, {3, 4, 12}, {0, 4, 13},
               {6, 15, 19}, {7, 15, 16}, {8, 16, 17}, {9, 17, 18}, {5, 18, 19},
                {0, 10, 11}, {1, 11, 12}, {2, 12, 13}, {3, 13, 14}, {4, 10, 14}
            };

            // Save the total number of rooms in a more user-friendly variable name
            numRooms = adjacentRooms.GetLength(0);
        }

        static void CreateBeadString(){
            adjacentRooms = new int[,]         
            {
               {1, 2, 19},   {0, 2, 3},   {0, 1, 3},   {1, 2, 4},    {3, 5, 6},
               {4, 6, 7},  {4, 5, 7},    {5, 6, 8},   {7, 9, 10},   {8, 10, 11},
               {8, 9, 11}, {9, 10, 12}, {11, 13, 14},  {12, 14, 15},  {12, 13, 15},
               {13, 14, 16}, {15, 17, 18},  {16, 18, 19}, {16, 17, 19}, {0, 17, 18}
            };

            // Save the total number of rooms in a more user-friendly variable name
            numRooms = adjacentRooms.GetLength(0); 
        }

        static void CreateMobius(){
            adjacentRooms = new int[,]         
            {
               {1, 2, 19},   {0, 3, 18},   {0, 3, 4},   {1, 2, 5},    {2, 5, 6},
               {3, 4, 7},  {4, 7, 8},    {5, 6, 9},   {6, 9, 10},   {7, 8, 11},
               {8, 11, 12}, {9, 10, 13}, {10, 13, 14},  {11, 12, 15},  {12, 15, 16},
               {13, 14, 17}, {14, 17, 18},  {15, 16, 19}, {1, 16, 19}, {0, 17, 18}
            };

            // Save the total number of rooms in a more user-friendly variable name
            numRooms = adjacentRooms.GetLength(0); 
        }

        //this method creates the dodec cave pattern
        static void CreateDodec(){
            adjacentRooms = new int[,]         
            {
               {1, 4, 7},   {0, 2, 9},   {1, 3, 11},   {2, 4, 13},    {0, 3, 5},
               {4, 6, 14},  {5, 7, 16},    {0, 6, 8},   {7, 9, 17},   {1, 8, 10},
               {9, 11, 18}, {2, 10, 12}, {11, 13, 19},  {3, 12, 14},  {5, 13, 15},
               {14, 16, 19}, {6, 15, 17},  {8, 16, 18}, {10, 17, 19}, {12, 15, 18}
            };

            // Save the total number of rooms in a more user-friendly variable name
            numRooms = adjacentRooms.GetLength(0); 
        }

        // This method creates or builds the cave network, mainly initalizing the adjacentRooms array.
        // This is where you will add support for new types of caves.
        static void CreateCave()
        {
            bool validChoice = false;

            Console.ForegroundColor = ConsoleColor.Green;
            Console.WriteLine("Select a cave style.");
            Console.ForegroundColor = ConsoleColor.Gray;
            Console.WriteLine("1) Dodecahedron");
            Console.WriteLine("2) Mobius Strip");
            Console.WriteLine("3) String of Beads");
            Console.WriteLine("4) Toroidal Hex");
            Console.WriteLine("5) Suprise Me");
            Console.ForegroundColor = ConsoleColor.White;
            
            while(!validChoice){
                Console.Write("Please make a selection: ");
                    try
                    {
                        int choice = Convert.ToInt32(Console.ReadLine());
                        if(choice == 5)
                            choice = random.Next(1, 5);

                        switch (choice)
                        {
                            case 1: 
                                CreateDodec();
                                validChoice = true;
                                break;
                            case 2:
                                CreateMobius(); 
                                validChoice = true;
                                break;
                            case 3:
                                CreateBeadString(); 
                                validChoice = true;
                                break;
                            case 4: 
                                CreateToroidal();
                                validChoice = true;
                                break;
                            default:
                                Console.WriteLine("Invalid choice. Please try again.");
                                break;
                        }
                        mapChoice = choice;
                    }
                    catch (FormatException)
                    {
                        // This try...catch block catches the FormatException that Convert.ToInt32 will throw 
                        // if the user inputs text or something that cannot be converted to an integer.
                        validChoice = false;
                        Console.WriteLine("Invalid choice. Please try again.");
                    }
            }
        }

        //////////////////////////////////////////////////////////////////////////////////////////////////
        //  END OF CAVE STRUCTURES
        //////////////////////////////////////////////////////////////////////////////////////////////////

        //////////////////////////////////////////////////////////////////////////////////////////////////
        // INITIALIZE GAME OBJECTS
        //////////////////////////////////////////////////////////////////////////////////////////////////

        //this method adds treasures in 4 different rooms
        static void AddTreasures()
        {
            treasureRooms = new int[] {random.Next(1, 5), random.Next(5, 10), random.Next(10, 15), random.Next(15, numRooms)};
        }      

        static void PlaceBats()
        {
            bool validRoom = false;
            while(!validRoom){
                batRoom1 = random.Next(0, numRooms);
                if(batRoom1 != wumpusRoom)
                    validRoom = true;
            }

            validRoom = false;
            while(!validRoom){
                batRoom2 = random.Next(0, numRooms);
                if(batRoom2 != wumpusRoom && batRoom2 != batRoom1)
                    validRoom = true;
            }
            bat1Start = batRoom1;
            bat2Start = batRoom2;
            // Console.WriteLine("DEBUG: Bats detected in room {0}, {1}", batRoom1, batRoom2);
        }

        static void PlacePits()
        {
            pitRoom1 = random.Next(0, numRooms);
            pitRoom2 = random.Next(0, numRooms);
            // Console.WriteLine("DEBUG: Pits detected in room {0}, {1}", pitRoom1, pitRoom2);
        }
        static void PlaceWumpus()
        {
            int randomRoom = random.Next(0, numRooms);
            wumpusRoom = randomRoom;
            // Console.WriteLine("DEBUG: Wumpus detected in room {0}", wumpusRoom);
            wumpusStart = wumpusRoom;
        }

        static void PlacePlayer(){
            int randomRoom;
            do{
                randomRoom = random.Next(0, numRooms);
            }while(randomRoom == wumpusRoom || randomRoom == pitRoom1 || randomRoom == pitRoom2 || randomRoom == batRoom1 || randomRoom == batRoom2);
            startingPosition = randomRoom;            
            currentRoom = Move(randomRoom);
            //Console.WriteLine("DEBUG: Player detected in room {0}", currentRoom);
        }

        //////////////////////////////////////////////////////////////////////////////////////////////////
        // END OF GAME OBJECT INITIALIZATION
        //////////////////////////////////////////////////////////////////////////////////////////////////

        //////////////////////////////////////////////////////////////////////////////////////////////////
        // SCORING FEATURES
        //////////////////////////////////////////////////////////////////////////////////////////////////

        static void CalculateMoveBonus(){
            
            if(moveCount == 0){
                playerScore += 50000;                
            } else if(moveCount < 5){
                playerScore += 10000;
            } else if(moveCount < 10){
                playerScore += 5000;
            } else if (moveCount < 15){
                playerScore += 1000;
            } else {
                playerScore += 500;
            }            

        }

        static void LoadHighScores(){
            highScores = System.IO.File.ReadAllLines(@"WumpusHighScore.txt");
        }
        static void SaveHighScore(string name, int score){
            System.IO.File.AppendAllText(@"WumpusHighScore.txt", name + "\n");
            System.IO.File.AppendAllText(@"WumpusHighScore.txt", Convert.ToString(score) + "\n");
        }
        // ViewHighScores(). This method should read the high score file from disk and display its contents.
        static void ViewHighScores()
        {   
            LoadHighScores();
            int counter = 0;
            // TODO: Task 8
            Console.Clear();
            foreach(string line in highScores){
                if(counter % 2 == 0){
                    Console.ForegroundColor = ConsoleColor.Green;
                    Console.Write("{0}: ", line);
                } else {
                    Console.ForegroundColor = ConsoleColor.Gray;
                    Console.WriteLine("{0}", line); 
                }
                counter++;
            }
            Console.ForegroundColor = ConsoleColor.White;
            Console.WriteLine("Press ENTER to return to the main menu.");
            Console.ReadLine();
        }

        //////////////////////////////////////////////////////////////////////////////////////////////////
        // END OF SCORING FEATURES
        //////////////////////////////////////////////////////////////////////////////////////////////////

        //////////////////////////////////////////////////////////////////////////////////////////////////
        // GAME MECHANICS AND ACTIONS
        //////////////////////////////////////////////////////////////////////////////////////////////////

        // This method returns true if roomB is adjacent to roomA, otherwise returns false.
        // It is a helper method that loops through the adjacentRooms array to check. 
        // It will be used throughout the app to check if we are next to the wumpus, bats, or pits
        // as well as check if we can make a valid move.
        static bool IsRoomAdjacent(int roomA, int roomB)
        {
            for (int j = 0; j < adjacentRooms.GetLength(1); j++)
            {
                if (adjacentRooms[roomA, j] == roomB) return true;
            }
            return false;
        }

        // This is a  method that checks if the user inputted a valid room to move to or not.
        // The room number has to be between 0 and 20, but also must be adjacent to the current room.
        static bool IsValidMove(int roomID)
        {
            if (roomID < 0) return false;
            if (roomID > numRooms) return false;
            if (!IsRoomAdjacent(currentRoom, roomID)) return false;

            return true;     
        }

        // This method moves the player to a new room and returns the new room. It performs no checks on its own.
        static int Move(int newRoom)
        {
            return newRoom;
        }

        static void CheckForTreasure()
        {
            Console.ForegroundColor = ConsoleColor.Yellow;
            bool treasureFound = false;
            string name = "";
            for(int i = 0; i < treasureRooms.Length && !treasureFound; i++){
                if(currentRoom == treasureRooms[i]){
                    Console.WriteLine("You see a treasure chest. Press ENTER to open it.");
                    Console.ReadLine();
                    switch(random.Next(0,5)){
                        case 0:
                            name = "gold";
                            Console.WriteLine("The chest contains {0}!", name);
                            playerScore += 1000;
                            break;
                        case 1:
                            name = "silver";
                            Console.WriteLine("The chest contains {0}!", name);
                            playerScore += 750;
                            break;
                        case 2:
                            name = "arrows";
                            Console.WriteLine("The chest contains {0}!", name);
                            numArrows += 3;
                            playerScore += 300;
                            break;
                        case 3:
                            name = "nothing";
                            Console.WriteLine("The chest contains {0}!", name);
                            playerScore += 50;
                            break;
                        case 4:
                            name = "a map";
                            Console.WriteLine("The chest contains {0}!", name);
                            Console.WriteLine("The map indicates the bottomless pits are located in room {0} and {1}!", pitRoom1, pitRoom2);
                            playerScore += 500;
                            break;
                    }
                    treasureRooms[i] = -1;                    
                    treasureFound = true;
                }
            }
            Console.ForegroundColor = ConsoleColor.White;
        }

        // Inspects the current room. 
        // This method should check for Hazards such as being in the same room as the wumpus, bats, or pits
        // It must also check if you are adjacent to a hazard and handle those cases
        // Finally it will just print out the room description
        static void InspectCurrentRoom()
        {            
            if (currentRoom == wumpusRoom)
            {
                Console.ForegroundColor = ConsoleColor.DarkGray;
                Console.WriteLine("The Wumpus ate you!!!");
                Console.WriteLine("LOSER!!!");
                Console.ForegroundColor = ConsoleColor.White;
                PlayAgain();
            }
            else if (currentRoom == batRoom1 || currentRoom == batRoom2) 
            {
                int roomBatsLeft = currentRoom;
                bool validNewBatRoom = false;
                bool isBatRoom = false;
                Console.ForegroundColor = ConsoleColor.DarkMagenta;
                Console.WriteLine("Snatched by superbats!!");
                if(currentRoom == pitRoom1 || currentRoom == pitRoom2)
                    Console.WriteLine("Luckily, the bats saved you from the bottomless pit!!");                
                while(!isBatRoom){
                    currentRoom = Move(random.Next(0, numRooms));
                    if(currentRoom != batRoom1 && currentRoom != batRoom2)
                        isBatRoom = true;
                }
                Console.WriteLine("The bats moved you to room {0}.", currentRoom);
                Console.ForegroundColor = ConsoleColor.White;
                InspectCurrentRoom();

                if(roomBatsLeft == batRoom1){
                    while(!validNewBatRoom){
                        batRoom1 = random.Next(1, numRooms);
                        if(batRoom1 != wumpusRoom && batRoom1 != currentRoom)
                            validNewBatRoom = true;
                    }
                } else {
                    while(!validNewBatRoom){
                        batRoom2 = random.Next(1, numRooms);
                        if(batRoom2 != wumpusRoom && batRoom2 != currentRoom)
                            validNewBatRoom = true;
                    }
                }
            }
            else if(currentRoom == pitRoom1 || currentRoom == pitRoom2)
            {
                Console.ForegroundColor = ConsoleColor.DarkCyan;
                Console.WriteLine("YYYIIIIIEEEEE.... fell in a pit!!!");
                Console.WriteLine("GAME OVER LOSER!!!");
                Console.ForegroundColor = ConsoleColor.White;
                PlayAgain();
            }
            else
            {
                Console.WriteLine("{0}, you are in room {1}.", playerName, currentRoom);
                if (IsRoomAdjacent(currentRoom, wumpusRoom)){
                    Console.ForegroundColor = ConsoleColor.DarkGray;
                    Console.WriteLine("You smell a horrid stench...");
                    Console.ForegroundColor = ConsoleColor.White;
                } 
                if (IsRoomAdjacent(currentRoom, batRoom1) || IsRoomAdjacent(currentRoom, batRoom2)){
                    Console.ForegroundColor = ConsoleColor.DarkMagenta;
                    Console.WriteLine("Bats nearby...");
                    Console.ForegroundColor = ConsoleColor.White;
                } 
                if (IsRoomAdjacent(currentRoom, pitRoom1) || IsRoomAdjacent(currentRoom, pitRoom2)){
                    Console.ForegroundColor = ConsoleColor.DarkCyan;
                    Console.WriteLine("You feel a draft...");
                    Console.ForegroundColor = ConsoleColor.White;
                } 
                CheckForTreasure();
                Console.Write("Tunnels lead to rooms ");
                for (int j = 0; j < adjacentRooms.GetLength(1); j++)
                {
                    Console.Write("{0} ", adjacentRooms[currentRoom, j]);
                }
                Console.WriteLine();
            }
        }

        // Method accepts a text string which is the command the user inputted.
        // This method performs the action of the command or prints out an error.
        static void PerformAction(string cmd)
        {
            int newRoom;
            switch (cmd.ToLower().Trim())
            {
                case "save":
                    SaveGame();
                    Console.WriteLine("Game Data has saved successfully, press enter to return to the main menu.");
                    Console.ReadLine();
                    playerAlive = false;
                    break;
                case "move":
                    Console.Write("Which room? ");
                    try
                    {
                        newRoom = Convert.ToInt32(Console.ReadLine());
                        // Check if the user inputted a valid room id, then simply tell the player to move there.
                        if (IsValidMove(newRoom))
                        {
                            currentRoom = Move(newRoom);
                            playerScore += 100;
                            moveCount++;
                            InspectCurrentRoom();
                        }
                        else
                        {
                            Console.WriteLine("You cannot move there.");
                        }
                    }
                    catch (FormatException) // Try...Catch block will catch if the user inputs text instead of a number.
                    {
                        Console.WriteLine("You cannot move there.");
                    }
                    break;
                case "shoot":
                    if(numArrows > 0){
                        Console.Write("Which room? ");
                        try
                        {
                            newRoom = Convert.ToInt32(Console.ReadLine());
                            // Check if the user inputted a valid room id, then simply tell the player to move there.
                            if (IsValidMove(newRoom))
                            {   
                                numArrows--;
                                if(newRoom == wumpusRoom){
                                    playerScore += 1000;
                                    CalculateMoveBonus();
                                    Console.WriteLine("ARGH.. Splat!");
                                    Console.WriteLine("Congratulations, {0}. You killed the Wumpus! You Win.", playerName);
                                    Console.WriteLine("You scored {0} points!", playerScore);
                                    SaveHighScore(playerName, playerScore);
                                    Console.WriteLine("Press ENTER to return to the main menu.");
                                    Console.ReadLine();
                                    wumpusAlive = false;
                                } 
                                else 
                                {
                                    Console.WriteLine("Miss! But you startled the Wumpus");
                                    moveStartledWumpus(wumpusRoom);
                                    Console.WriteLine("Arrows Left: {0}", numArrows);
                                    playerScore -= 200;
                                    if(wumpusRoom == currentRoom){
                                        Console.WriteLine("The wumpus attacked you! You've been killed.");
                                        Console.WriteLine("Game Over!");
                                        PlayAgain();
                                    }
                                        
                                }                                                            
                            }
                            else
                            {
                                Console.WriteLine("You cannot shoot there.");
                            }
                        }
                        catch (FormatException) // Try...Catch block will catch if the user inputs text instead of a number.
                        {
                            Console.WriteLine("You cannot shoot there.");
                        }
                    } else
                    {
                        Console.WriteLine("You do not have any arrows!");
                    }
                    break;
                case "quit":
                    Console.WriteLine("Quitting the current game.");
                    playerAlive = false;
                    break;
                default:
                    Console.WriteLine("You cannot do that. You can move, shoot, save or quit.");
                    break;
            }
        }

        static void moveStartledWumpus(int roomNum){
            int rando = random.Next(0,3);
            if(rando != 3)
                wumpusRoom = adjacentRooms[roomNum, rando];
        }

        //////////////////////////////////////////////////////////////////////////////////////////////////
        //  END OF GAME MECHANICS AND ACTIONS
        //////////////////////////////////////////////////////////////////////////////////////////////////
        

        //////////////////////////////////////////////////////////////////////////////////////////////////
        // BUILDING THE GAME 
        //////////////////////////////////////////////////////////////////////////////////////////////////

        static void PlayAgain(){
            string reply;            
            Console.WriteLine("Would you like to replay the same map? Enter yes to play again.");
            reply = Console.ReadLine();
            reply.ToLower().Trim();
            if(reply == "yes"){
                currentRoom = startingPosition;
                wumpusRoom = wumpusStart;
                batRoom1 = bat1Start;
                batRoom2 = bat2Start;
                Console.Clear();
                Console.WriteLine("Try not to die this time. \n");
                InspectCurrentRoom();
            } else {
                playerAlive = false;
            }

        }

        // PlayGame() method starts up the game.
        // It houses the main game loop and when PlayGame() quits the game has ended.
        static void PlayGame(bool newGame)
        {
            // We are about to start the game. 
            string cmd;

            Console.WriteLine("Running the game...");
            
            if(newGame){
                //Get a name for the player
                playerName = "";
                do {
                    Console.WriteLine("\nBefore we begin, enter your name");
                    Console.Write(">>> ");
                    playerName = Console.ReadLine();
                }while(playerName == "");

                // Perform initialization tasks at the beginning of every game
                playerScore = 0;
                moveCount = 0;
                CreateCave();   // Create the cave network.
                AddTreasures();
                PlaceWumpus();  // Place the wumpus in a room
                PlaceBats();
                PlacePits();
                PlacePlayer();
                // Task 2, Task 3 Hint. Maybe we need PlaceBats() and PlacePits()?

                // Place the player in room 0 and inspect that room to get started.
                playerAlive = true;
                wumpusAlive = true;
                numArrows = 3;
            } else {
                LoadGameData();
            }

            //Inspects the initial room
            InspectCurrentRoom();

            // Main game loop.
            // 1) Prompt the user for some input
            // 2) Perform the action the user inputted
            // 3) Check if the game is over or not and keep looping.
            while (playerAlive && wumpusAlive)
            {
                Console.Write(">>> ");
                cmd = Console.ReadLine();
                PerformAction(cmd);
            }
        }

        static void SaveGame(){
            saveData = new string [] {
                Convert.ToString(mapChoice),
                Convert.ToString(startingPosition),
                Convert.ToString(currentRoom),
                Convert.ToString(wumpusRoom),
                Convert.ToString(wumpusStart),
                Convert.ToString(batRoom1),
                Convert.ToString(bat1Start),
                Convert.ToString(batRoom2),
                Convert.ToString(bat2Start),
                Convert.ToString(numArrows),
                Convert.ToString(moveCount),
                Convert.ToString(playerScore),
                Convert.ToString(treasureRooms[0]),
                Convert.ToString(treasureRooms[1]),
                Convert.ToString(treasureRooms[2]),
                Convert.ToString(treasureRooms[3]),
                Convert.ToString(pitRoom1),
                Convert.ToString(pitRoom2),
                playerName
            };
            System.IO.File.WriteAllLines(@"SaveData.txt", saveData);
        }

        static void LoadGameData(){
            saveData = System.IO.File.ReadAllLines(@"SaveData.txt");
            InitializeSaveData();
            // Console.WriteLine("DEBUG: Bats detected in room {0}, {1}", batRoom1, batRoom2);
            // Console.WriteLine("DEBUG: Wumpus detected in room {0}", wumpusRoom);
            // Console.WriteLine("DEBUG: Pits detected in room {0}, {1}", pitRoom1, pitRoom2);
        }

        static void InitializeSaveData(){
            switch(Convert.ToInt32(saveData[0])){
                case 1:
                    CreateDodec();
                    break;
                case 2:
                    CreateMobius();
                    break;
                case 3:
                    CreateBeadString();
                    break;
                case 4: 
                    CreateToroidal();
                    break;
            }
            playerAlive = true;
            wumpusAlive = true;
            startingPosition = Convert.ToInt32(saveData[1]);
            currentRoom = Convert.ToInt32(saveData[2]);
            wumpusRoom = Convert.ToInt32(saveData[3]);
            wumpusStart = Convert.ToInt32(saveData[4]);
            batRoom1 = Convert.ToInt32(saveData[5]);
            bat1Start = Convert.ToInt32(saveData[6]);
            batRoom2 = Convert.ToInt32(saveData[7]);
            bat2Start = Convert.ToInt32(saveData[8]);
            numArrows = Convert.ToInt32(saveData[9]);
            moveCount = Convert.ToInt32(saveData[10]);
            playerScore = Convert.ToInt32(saveData[11]);
            treasureRooms = new int[] {
                                Convert.ToInt32(saveData[12]),
                                Convert.ToInt32(saveData[13]),
                                Convert.ToInt32(saveData[14]),
                                Convert.ToInt32(saveData[14])
            };
            pitRoom1 = Convert.ToInt32(saveData[16]);
            pitRoom2 = Convert.ToInt32(saveData[17]);
            playerName = saveData[18];
        }

        //////////////////////////////////////////////////////////////////////////////////////////////////
        // END OF GAME BUILDING
        //////////////////////////////////////////////////////////////////////////////////////////////////

        //////////////////////////////////////////////////////////////////////////////////////////////////
        // MAIN!!!!!
        //////////////////////////////////////////////////////////////////////////////////////////////////       
        static void Main(string[] args)
        {
            int choice;
            bool validChoice;
            bool keepPlaying;
            wumpusStart = bat1Start = bat2Start = -1;

            Console.ForegroundColor = ConsoleColor.Green;

            // The purpose of the outer do...while loop is when the game ends, we will bring the user back
            // to the main menu, so they can start a new game, view scores, view instructions, or really quit.
            do
            {
                keepPlaying = true;
                Console.Clear();
                Console.ForegroundColor = ConsoleColor.Green;
                Console.WriteLine("Welcome to Hunt The Wumpus.");
                Console.ForegroundColor = ConsoleColor.Gray;
                Console.WriteLine("1) New Game");
                Console.WriteLine("2) Load Game Save");
                Console.WriteLine("3) Print Instructions");
                Console.WriteLine("4) View High Scores");
                Console.WriteLine("5) Quit");
                Console.ForegroundColor = ConsoleColor.White;

                do // inner do...while loop is to keep looping until the user picks a valid menu selection
                {
                    validChoice = true;
                    Console.Write("Please make a selection: ");
                    try
                    {
                        choice = Convert.ToInt32(Console.ReadLine());
                        switch (choice)
                        {
                            case 1: // User selected New Game
                                PlayGame(true);
                                break;
                            case 2: // User selected Load Game
                                PlayGame(false);
                                break;
                            case 3: // User selected Print Instructions
                                PrintInstructions();
                                break;
                            case 4: // User selected View High Score List
                                ViewHighScores();
                                break;
                            case 5: // User selected Quit
                                Console.WriteLine("Quitting.");
                                keepPlaying = false;
                                break;
                            default:
                                validChoice = false;
                                Console.WriteLine("Invalid choice. Please try again.");
                                break;
                        }
                    }
                    catch (FormatException)
                    {
                        // This try...catch block catches the FormatException that Convert.ToInt32 will throw 
                        // if the user inputs text or something that cannot be converted to an integer.
                        validChoice = false;
                        Console.WriteLine("Invalid choice. Please try again.");
                    }
                
                } while (validChoice == false); // Inner loop ends when validChoice is true
            } while (keepPlaying); // Outer loop ends when the user selects quit.
        }
        //////////////////////////////////////////////////////////////////////////////////////////////////
        // END OF MAIN
        //////////////////////////////////////////////////////////////////////////////////////////////////
        

        //////////////////////////////////////////////////////////////////////////////////////////////////
        // LONG STRING FOR INSTRUCTIONS
        //////////////////////////////////////////////////////////////////////////////////////////////////
        static void PrintInstructions()
        {
            // TODO: Display some instructions here.
            string instructs = @"    Welcome to 'Hunt the Wumpus'!                                                  
    The wumpus lives in a cave of 20 rooms. Each room has 3 tunnels leading to     
    other rooms. (Look at a dodecahedron to see how this works - if you don't know 
    what a dodecahedron is, ask someone).                                          
                                                                                
    Hazards                                                                        
    Bottomless pits - two rooms have bottomless pits in them. If you go there, you 
    fall into the pit (& lose!)                                                    
    Super bats - two other rooms have super bats.  If you go there, a bat grabs you
    and takes you to some other room at random. (Which may be troublesome). Once the
    bat has moved you, that bat moves to another random location on the map.        
                                                                                
    Wumpus                                                                         
    The wumpus is not bothered by hazards (he has sucker feet and is too big for a 
    bat to lift).  Usually he is asleep.  Two things wake him up: you shooting an  
    arrow or you entering his room. If the wumpus wakes he moves (p=.75) one room or 
    stays still (p=.25). After that, if he is where you are, he eats you up and you lose!

    Treasure
    You may find treasure chests throughout the caves that could contain something
    useful or nothing at all.                     
                                                                                
    You                                                                            
    Each turn you may move, save or shoot an arrow using the commands move, save, & shoot.
    Saving: you can save your current game data and load it later                               
    Moving: you can move one room (thru one tunnel).                               
    Arrows: you have 3 arrows. You lose when you run out. You aim by telling the 
    computer the rooms you want the arrow to go to.  If the arrow can't go that way 
    (if no tunnel), the arrow will not fire.                                                                          
                                                                                
    Warnings                                                                       
    When you are one room away from a wumpus or hazard, the computer says:         
                                                                                
    Wumpus: 'I smell a wumpus'                                                     
    Bat: 'Bats nearby'                                                             
    Pit: 'I feel a draft'";

            Console.Clear();
            Console.WriteLine("\n{0}", instructs);
            Console.WriteLine();
            Console.WriteLine("Press ENTER to return to the main menu.");
            Console.ReadLine();
        }
        //////////////////////////////////////////////////////////////////////////////////////////////////
        // END OF INSTRUCTION STRING
        //////////////////////////////////////////////////////////////////////////////////////////////////
    }
}
