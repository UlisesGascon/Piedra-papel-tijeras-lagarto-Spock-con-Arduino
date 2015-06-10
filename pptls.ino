// ==== Definiendo los Botones y los valores del juego ====

// botones
int boton1 = 12;
int boton2 = 11;
int boton3 = 10;
int boton4 = 9;
int boton5 = 8;

// variable de control de loop while 
bool run = true;
	
// Definimos la eleccion del jugador y Arduino a cero.
	String eleccionJugador = "vacio";
	String eleccionArduino = "vacio";

// Parámetros del depurador
//#define DEBUGMODE


// ==== EMPIEZA EL SETUP() ====
void setup() {

// Modo Input en los pulsadores
pinMode(boton1, INPUT);
pinMode(boton2, INPUT);
pinMode(boton3, INPUT);
pinMode(boton4, INPUT);
pinMode(boton5, INPUT);


//Activando la comunicación Serial
Serial.begin(9600);
Serial.println("Comunicacion establecida con exito");


// Aviso del DebugMode
#ifdef DEBUGMODE
Serial.print("DEBUGMODE Activado");
#endif


// mensaje de bienvenida
Serial.println("Bienvenido Humano! Es hora de jugar a -- Piedra papel tijeras lagarto Spock --");
Serial.println("Tiempo de elegir. Presiona un boton");
 
}


// ==== EMPIEZA EL LOOP() ====
void loop (){

// Loop de control
while(run == true){

// === ELECCIÓN ARDUINO ===

	// la elección de Arduino es un numero al azar entre 1 y 5.
	int eleccionRandom = random(1, 6);

// convertir ese numero en la cadena de texto correpondiente 
// continuamente hasta que el jugador humano haga su elección.
	if(eleccionRandom == 1){
		// Arduino elige piedra
		eleccionArduino = "piedra";
	    
	}else if( eleccionRandom == 2 ){
		// Arduino elige papel
		eleccionArduino = "papel";

	}else if( eleccionRandom == 3 ){
		// Arduino elige tijeras
		eleccionArduino = "tijeras";

	}else if( eleccionRandom == 4 ){
		// Arduino elige lagarto
		eleccionArduino = "lagarto";

	}else if( eleccionRandom == 5 ){
		// Arduino elige Spock
		eleccionArduino = "spock";	
	    
	} else{
		// Si el valor se sale de lo esperado... avisamos al usuario.
		Serial.print("Arduino es un tramposo! Arregla su codigo");
	}
	// DebugMode
	#ifdef DEBUGMODE
		Serial.print("Arduino elige: "+String(eleccionArduino));
	#endif


// === ELECCIÓN DEL JUGADOR Y RESOLUCCIÓN DE LA PARTIDA ===

	// Aqui esperamos a que el jugador haya decidido antes de evaluar resultados. (SINO PASA AL -> ELSE() {} -- linea 239)
	if(eleccionJugador != "vacio"){
		// Resolución en caso de empate.
	    if(eleccionJugador == eleccionArduino){
	        Serial.print("Empate! "+String(eleccionJugador)+" no gana a "+String(eleccionArduino)); 
	        delay(1000); 
	        run = false; // Para el Loop While y con ello todo dentro de Loop().
		
		// Si el jugador es piedra
		}else if( eleccionJugador == "piedra") {
			
			// Piedra gana a tijeras.
			if (eleccionArduino == "tijeras"){
				Serial.print("Jugador Gana! ...piedra aplasta las tijeras");
				delay(1000);
	        	run = false;
			// Piedra gana a lagarto.
			}else if( eleccionArduino == "lagarto"){
				Serial.print("Jugador Gana! ...piedra aplasta al lagarto");
				delay(1000);
	        	run = false;
			// Piedra pierde con papel.
			}else if( eleccionArduino == "papel") {
				Serial.print("Jugador Pierde! ...papel cubre a la piedra");
				delay(1000);
	        	run = false;
			// Piedra pierde con spock.
			}else if( eleccionArduino == "spock") {
				Serial.print("Jugador Pierde! ....Spock vaporiza la piedra");
				delay(1000);
	        	run = false;
			}



		// Si el jugador es papel.	
		}else if( eleccionJugador == "papel" ){

			// Papel gana a piedra.	
			if( eleccionArduino == "piedra"){
				Serial.print("Jugador Gana! ...papel cubre a la piedra");
				delay(1000);
	        	run = false;			
			// Papel gana a spock.	
			}else if(eleccionArduino == "spock"){
				Serial.print("Jugador Gana! ...papel refuta a Spock");
				delay(1000);
	        	run = false;
			// Papel pierde con tijeras.
			}else if(eleccionArduino == "tijeras"){
				Serial.print("Jugador Pierde! ...tijeras cortan el papel");
				delay(1000);
	        	run = false;
			// Papel pierde con lagarto.
			}else if(eleccionArduino == "lagarto"){
				Serial.print("Jugador Pierde! ...lagarto se come el papel");
				delay(1000);
	        	run = false;
			}



		// Si el jugador es tijeras.
		}else if( eleccionJugador == "tijeras"){
			// tijeras gana a papel.
			if(eleccionArduino == "papel"){
				Serial.print("Jugador Gana! ...tijeras cortan el papel");
				delay(1000);
	        	run = false;
			// tijeras gana a lagarto.
			}else if(eleccionArduino == "lagarto"){
				Serial.print("Jugador Gana! ...tijeras decapitan al lagarto");
				delay(1000);
	        	run = false;
			// tijeras pierde con piedra.
			}else if(eleccionArduino == "piedra"){
				Serial.print("Jugador Pierde! ...piedra aplasta las tijeras");
				delay(1000);
	        	run = false;
			// tijeras pierde con spock.
			}else if(eleccionArduino == "spock"){
				Serial.print("Jugador Pierde! ...Spock destroza las tijeras");
				delay(1000);
	        	run = false;
			}
		



		// Si el jugador es lagarto.
		}else if( eleccionJugador == "lagarto"){
			// Lagarto gana a spock.
			if(eleccionArduino == "spock"){
				Serial.print("Jugador Gana! ...lagarto envenena a Spock");
				delay(1000);
	        	run = false;
			// Lagarto gana a papel.
			}else if( eleccionArduino == "papel"){
				Serial.print("Jugador Gana! ...lagarto se come el papel");
				delay(1000);
	        	run = false;
			// Lagarto pierde con piedra.
			}else if( eleccionArduino == "piedra"){
				Serial.print("Jugador Pierde! ...piedra aplasta al lagarto");
				delay(1000);
	        	run = false;
			// Lagarto pierde con tijeras.
			}else if(eleccionArduino == "tijeras"){
				Serial.print("Jugador Pierde! ...tijeras decapitan al lagarto");
				delay(1000);
	        	run = false;
			}



		// Si el jugador es Spock.
		}else if( eleccionJugador == "spock"){

			// Spock gana a tijeras.
			if( eleccionArduino == "tijeras"){
				Serial.print("Jugador Gana! ...Spock destroza las tijeras");
				delay(1000);
	        	run = false;
			// Spock gana a piedra.
			}else if( eleccionArduino == "piedra"){
				Serial.print("Jugador Gana! ...Spock vaporiza la piedra");
				delay(1000);
	        	run = false;
			// Spock pierde con papel.
			}else if(eleccionArduino == "papel"){
				Serial.print("Jugador Pierde! ...papel refuta a Spock");
				delay(1000);
	        	run = false;
			// Spock pierde con lagarto.
			}else if(eleccionArduino == "lagarto"){
				Serial.print("Jugador Pierde! ...lagarto envenena a Spock");
				delay(1000);
	        	run = false;
			}
		
		} // cierra condiccional de eleccionJugador

// ====  AQUI SE DEFINE LA ELECCIÓN DEL JUGADOR  ====

	} else {
		delay(1000);
		// El jugador define su elección a traves de los 5 botones.
	    if(digitalRead(boton1) == HIGH){
	    	eleccionJugador = "piedra";
	    }else if(digitalRead(boton2) == HIGH){
	    	eleccionJugador = "papel";
	    }else if(digitalRead(boton3) == HIGH){
	    	eleccionJugador = "tijeras";
	    }else if(digitalRead(boton4) == HIGH){
	    	eleccionJugador = "lagarto";
	    }else if(digitalRead(boton5) == HIGH){
	    	eleccionJugador = "spock";
	    }
	    
	    // DebugMode
		#ifdef DEBUGMODE
			Serial.print("Humano elige: "+String(eleccionJugador));
		#endif

	} // Fin del condiccional (eleccionJugador != "vacio")

} // While

} //Loop()

// Fín del código