// ==== Defining buttons and game values====

// buttons
int button1 = 12;
int button2 = 11;
int button3 = 10;
int button4 = 9;
int button5 = 8;

// while loop control variable
bool run = true;
	
// We set player's choice and Arduino´s to zero
	String playerChoice = "void";
	String Arduinochoice = "void";

// debugger settings
//#define DEBUGMODE


// ==== SETUP STAR() ====
void setup() {

// buttons input mode
pinMode(button1, INPUT);
pinMode(button2, INPUT);
pinMode(button3, INPUT);
pinMode(button4, INPUT);
pinMode(button5, INPUT);


//activating serial communication
Serial.begin(9600);
Serial.println("communication established successfully");


// DebugMode notice
#ifdef DEBUGMODE
Serial.print("DEBUGMODE Activated");
#endif


// welcome message
Serial.println("Greetings, human! It is time to play to -- rock paper scissors lizard Spock--");
Serial.println("Time to choose. press a button");
 
}


// ==== LOOP STARTS() ====
void loop (){

// control loop
while(run == true){

// === ARDUINO CHOICE ===

	// Arduino choice is a randomly picked number between 1 and 5
	int Randomchoice = random(1, 6);

// convert that number into the corresponding string
// continuously until the human player makes his choice.
	if(Randomchoice == 1){
		// Arduino chooses rock
		Arduinochoice = "rock";
	    
	}else if( eleccionRandom == 2 ){
		// Arduino chooses paper
		Arduinochoice = "paper";

	}else if( eleccionRandom == 3 ){
		// Arduino chooses scissors
		Arduinochoice = "scissors;

	}else if( eleccionRandom == 4 ){
		// Arduino chooses lizard
		Arduinochoice = "lizard";

	}else if( eleccionRandom == 5 ){
		// Arduino chooses Spock
		Arduinochoice = "spock";	
	    
	} else{
		// If the value is not in line with expected result.. we warn the user.
		Serial.print("Arduino is a cheat! fix its code");
	}
	// DebugMode
	#ifdef DEBUGMODE
		Serial.print("Arduino chooses: "+String(Arduinochoice));
	#endif


// === PLAYERS CHOICE AND GAME RESOLUTION ===

	// Here we wait till player has decided before evaluating results (IF NOT GO TO -> ELSE() {} -- line 239)
	if(playerChoice != "void"){
		// Resolution in case of a tie.
	    if(playerChoice == Arduinochoice){
	        Serial.print("Tie! "+String(playerChoice)+" does not beat  "+String(Arduinochoice)); 
	        delay(1000); 
	        run = false; // valid for the while loop and everything inside the loop().
		
		// If player is rock
		}else if( playerChoice == "rock") {
			
			// Rock beats scissors
			if (Arduinochoice == "scissors"){
				Serial.print("Player wins! ...rock crushes scissors");
				delay(1000);
	        	run = false;
			// Rock beats lizard.
			}else if( Arduinochoice == "lizard"){
				Serial.print("Player wins! ...rock crushes lizard");
				delay(1000);
	        	run = false;
			// rock loses to paper.
			}else if( Arduinochoice == "paper") {
				Serial.print("Player loses! ...paper covers rock");
				delay(1000);
	        	run = false;
			// rock loses to spock.
			}else if( Arduinochoice == "spock") {
				Serial.print("Player loses ....Spock vaporizes  rock");
				delay(1000);
	        	run = false;
			}



		// If player is paper	
		}else if( playerchoice == "paper" ){

			// paper beats rock.	
			if( Arduinochoice == "rock"){
				Serial.print("Player wins! ...paper covers rock");
				delay(1000);
	        	run = false;			
			// paper beats spock.	
			}else if(Arduinochoice == "spock"){
				Serial.print("Player wins! ...paper disproves Spock");
				delay(1000);
	        	run = false;
			// paper loses to scissors.
			}else if(Arduinochoice == "scissors"){
				Serial.print("Player loses! ...scissors cuts paper");
				delay(1000);
	        	run = false;
			// paper loses to lizard.
			}else if(Arduinochoice == "lizard"){
				Serial.print("Player loses! ...lizard eats paper");
				delay(1000);
	        	run = false;
			}



		// Si is scissors.
		}else if( playerchoice == "scissors"){
			// scissors beats paper.
			if(Arduinochoice == "paper"){
				Serial.print("Player wins! ...scissors cuts paper");
				delay(1000);
	        	run = false;
			// scissors beats lizard.
			}else if(Arduinochoice == "lizard"){
				Serial.print("Player wins! ...scissors decapitates lizard");
				delay(1000);
	        	run = false;
			// scissors loses to rock.
			}else if(Arduinochoice == "rock"){
				Serial.print("Player loses! ...rock crushes scissors");
				delay(1000);
	        	run = false;
			// scissors loses to spock.
			}else if(Arduinochoice == "spock"){
				Serial.print("Player loses! ...Spock smashes scissors");
				delay(1000);
	        	run = false;
			}
		



		// Si is lizard.
		}else if( playerchoice == "lizard"){
			// lizard beats spock.
			if(Arduinochoice == "spock"){
				Serial.print("Player wins! ...lizard poisons Spock");
				delay(1000);
	        	run = false;
			// lizard beats  paper.
			}else if( Arduinochoice == "paper"){
				Serial.print("Player wins! ...lizard eats paper");
				delay(1000);
	        	run = false;
			// lizard loses to  rock.
			}else if( Arduinochoice == "rock"){
				Serial.print("Player loses! ...rock crushes lizard");
				delay(1000);
	        	run = false;
			// lizard loses to scissors.
			}else if(Arduinochoice == "scissors"){
				Serial.print("Player loses! ...scissors decapitates lizard");
				delay(1000);
	        	run = false;
			}



		// If player is Spock.
		}else if( playerchoice == "spock"){

			// Spock beats scissors.
			if( Arduinochoice == "scissors"){
				Serial.print("Player wins! ...Spock smashes scissors");
				delay(1000);
	        	run = false;
			// Spock beats rock.
			}else if( Arduinochoice == "rock"){
				Serial.print("Player wins! ...Spock vaporizes la rock");
				delay(1000);
	        	run = false;
			// Spock loses to  paper.
			}else if(Arduinochoice == "paper"){
				Serial.print("Player loses! ...paper disproves Spock");
				delay(1000);
	        	run = false;
			// Spock loses to  lizard.
			}else if(Arduinochoice == "lizard"){
				Serial.print("Player loses! ...lizard poisons Spock");
				delay(1000);
	        	run = false;
			}
		
		} // closes playerchoice conditional

// ====  HERE WE DEFINE PLAYERS CHOICES  ====

	} else {
		delay(1000);
		// Player defines his choices throuhg  5 buttons
	    if(digitalRead(button1) == HIGH){
	    	playerchoice = "rock";
	    }else if(digitalRead(button2) == HIGH){
	    	playerchoice = "paper";
	    }else if(digitalRead(button3) == HIGH){
	    	playerchoice = "scissors";
	    }else if(digitalRead(button4) == HIGH){
	    	playerchoice = "lizard";
	    }else if(digitalRead(button5) == HIGH){
	    	playerchoice = "spock";
	    }
	    
	    // DebugMode
		#ifdef DEBUGMODE
			Serial.print("Human chooses: "+String(playerchoice));
		#endif

	} // End of conditional (playerchoice != "void")

} // While

} //Loop()

// End of code