// Written by Gianfranco Lacasella


/*
                FORMAT
Direction: char ---------------> Button on the Android App

Go forward: 'F' ---------------> Forward button
Go forward/right: 'I' ---------> Forward button + Right button
Go forward/left: 'G'-----------> Forward button + Left button
Go backward: 'B' --------------> Backward button
Go backward/right: 'J'---------> Backward button + Right button
Go backward/left: 'H' ---------> Backward button + Left button
Go right: 'R' -----------------> Right button
Go left: 'L' ------------------> Left button


                FORMAT
Speed at v  = value -----------> Slider value on the Android App

Speed at 0  = 0 ---------------> Slider at 0
Speed at 10 = 1 ---------------> Slider at 10
Speed at 20 = 2 ---------------> Slider at 20
Speed at 30 = 3 ---------------> Slider at 30
Speed at 40 = 4 ---------------> Slider at 40
Speed at 50 = 5 ---------------> Slider at 50
Speed at 60 = 6 ---------------> Slider at 60
Speed at 70 = 7 ---------------> Slider at 70
Speed at 80 = 8 ---------------> Slider at 80
Speed at 90 = 9 ---------------> Slider at 90
Speed at 100 = 'q' ------------> Slider at 100


                FORMAT
Sound type = char ---------------> Button on the Android App

Sound 2 = 'W' -------------------> Front lights on
Sound 3 = 'w' -------------------> Front lights off
Sound 1 = 'U' -------------------> Back lights on
Imperial March = 'u' ------------> Back lights off
Ooooh = 'V' ---------------------> Horn on
Double Ooohh = 'v' --------------> Horn off
*/


// Constants
const int motorIzquierdoA = 10; // Digital pin #2. MotorIzquierdoA (LeftEngineA) connection
const int motorIzquierdoB = 12; // Digital pin #4. MotorIzquierdoB (LeftEngineB) connection
const int motorIzquierdoHabilitador = 11; // PWM pin to handle left engine speed
const int motorDerechoA = 2; // Digital pin #10. MotorDerechoA (RightEngineA) connection
const int motorDerechoB = 4; // Digital pin #12. MotorDerechoB (RightEngineB) connection
const int motorDerechoHabilitador = 3; // PWM pin to handle right engine speed
int tiempo = 0; // Variable that handles the speed with which arduino checks if there is a new int in the buffer
int rapidez = 0; // Variable that stores the actual BB-8 speed

// Some notes, that can be used in the sound functions
//           Note    = Frequency
const float  nota_C0 = 16.35;  //C0
const float  nota_Db0 = 17.32;  //C#0/Db0
const float  nota_D0 = 18.35;  //D0
const float  nota_Eb0 = 19.45;  //D#0/Eb0
const float  nota_E0 = 20.6;  //E0
const float  nota_F0 = 21.83;  //F0
const float  nota_Gb0 = 23.12;  //F#0/Gb0
const float  nota_G0 = 24.5;  //G0
const float  nota_Ab0 = 25.96;  //G#0/Ab0
const float  nota_A0 = 27.5;  //A0
const float  nota_Bb0 = 29.14;  //A#0/Bb0
const float  nota_B0 = 30.87;  //B0
const float  nota_C1 = 32.7;  //C1
const float  nota_Db1 = 34.65;  //C#1/Db1
const float  nota_D1 = 36.71;  //D1
const float  nota_Eb1 = 38.89;  //D#1/Eb1
const float  nota_E1 = 41.2;  //E1
const float  nota_F1 = 43.65;  //F1
const float  nota_Gb1 = 46.25;  //F#1/Gb1
const float  nota_G1 = 49;  //G1
const float  nota_Ab1 = 51.91;  //G#1/Ab1
const float  nota_A1 = 55;  //A1
const float  nota_Bb1 = 58.27;  //A#1/Bb1
const float  nota_B1 = 61.74;  //B1
const float  nota_C2 = 65.41;  //C2 (Middle C)
const float  nota_Db2 = 69.3;  //C#2/Db2
const float  nota_D2 = 73.42;  //D2
const float  nota_Eb2 = 77.78;  //D#2/Eb2
const float  nota_E2 = 82.41;  //E2
const float  nota_F2 = 87.31;  //F2
const float  nota_Gb2 = 92.5;  //F#2/Gb2
const float  nota_G2 = 98;  //G2
const float  nota_Ab2 = 103.83;  //G#2/Ab2
const float  nota_A2 = 110;  //A2
const float  nota_Bb2 = 116.54;  //A#2/Bb2
const float  nota_B2 = 123.47;  //B2
const float  nota_C3 = 130.81;  //C3
const float  nota_Db3 = 138.59;  //C#3/Db3
const float  nota_D3 = 146.83;  //D3
const float  nota_Eb3 = 155.56;  //D#3/Eb3
const float  nota_E3 = 164.81;  //E3
const float  nota_F3 = 174.61;  //F3
const float  nota_Gb3 = 185;  //F#3/Gb3
const float  nota_G3 = 196;  //G3
const float  nota_Ab3 = 207.65;  //G#3/Ab3
const float  nota_A3 = 220;  //A3
const float  nota_Bb3 = 233.08;  //A#3/Bb3
const float  nota_B3 = 246.94;  //B3
const float  nota_C4 = 261.63;  //C4
const float  nota_Db4 = 277.18;  //C#4/Db4
const float  nota_D4 = 293.66;  //D4
const float  nota_Eb4 = 311.13;  //D#4/Eb4
const float  nota_E4 = 329.63;  //E4
const float  nota_F4 = 349.23;  //F4
const float  nota_Gb4 = 369.99;  //F#4/Gb4
const float  nota_G4 = 392;  //G4
const float  nota_Ab4 = 415.3;  //G#4/Ab4
const float  nota_A4 = 440;  //A4
const float  nota_Bb4 = 466.16;  //A#4/Bb4
const float  nota_B4 = 493.88;  //B4
const float  nota_C5 = 523.25;  //C5
const float  nota_Db5 = 554.37;  //C#5/Db5
const float  nota_D5 = 587.33;  //D5
const float  nota_Eb5 = 622.25;  //D#5/Eb5
const float  nota_E5 = 659.26;  //E5
const float  nota_F5 = 698.46;  //F5
const float  nota_Gb5 = 739.99;  //F#5/Gb5
const float  nota_G5 = 783.99;  //G5
const float  nota_Ab5 = 830.61;  //G#5/Ab5
const float  nota_A5 = 880;  //A5
const float  nota_Bb5 = 932.33;  //A#5/Bb5
const float  nota_B5 = 987.77;  //B5
const float  nota_C6 = 1046.5;  //C6
const float  nota_Db6 = 1108.73;  //C#6/Db6
const float  nota_D6 = 1174.66;  //D6
const float  nota_Eb6 = 1244.51;  //D#6/Eb6
const float  nota_E6 = 1318.51;  //E6
const float  nota_F6 = 1396.91;  //F6
const float  nota_Gb6 = 1479.98;  //F#6/Gb6
const float  nota_G6 = 1567.98;  //G6
const float  nota_Ab6 = 1661.22;  //G#6/Ab6
const float  nota_A6 = 1760;  //A6
const float  nota_Bb6 = 1864.66;  //A#6/Bb6
const float  nota_B6 = 1975.53;  //B6
const float  nota_C7 = 2093;  //C7
const float  nota_Db7 = 2217.46;  //C#7/Db7
const float  nota_D7 = 2349.32;  //D7
const float  nota_Eb7 = 2489.02;  //D#7/Eb7
const float  nota_E7 = 2637.02;  //E7
const float  nota_F7 = 2793.83;  //F7
const float  nota_Gb7 = 2959.96;  //F#7/Gb7
const float  nota_G7 = 3135.96;  //G7
const float  nota_Ab7 = 3322.44;  //G#7/Ab7
const float  nota_A7 = 3520;  //A7
const float  nota_Bb7 = 3729.31;  //A#7/Bb7
const float  nota_B7 = 3951.07;  //B7
const float  nota_C8 = 4186.01;  //C8
const float  nota_Db8 = 4434.92;  //C#8/Db8
const float  nota_D8 = 4698.64;  //D8
const float  nota_Eb8 = 4978.03;  //D#8/Eb8
const int pinAltavoz = 6; // Pin PWM al que estara conectado el buzzer
const int nota_pausa = 0;



// Setup function
void setup(void)
{
    // Define necessary pins as OUTPUT (direction control)
    pinMode(motorIzquierdoA, OUTPUT);
    pinMode(motorIzquierdoB, OUTPUT);
    pinMode(motorIzquierdoHabilitador, OUTPUT);
    pinMode(motorDerechoA, OUTPUT);
    pinMode(motorDerechoB, OUTPUT);
    pinMode(motorDerechoHabilitador, OUTPUT);
    // Define buzzer pin (sound)
    pinMode(pinAltavoz, OUTPUT);
    // Start comunication at 9600 baud by the serial port
    Serial.begin(9600);
    return;
}


// Function to interpolate all possible speeds into 0-255 scale
// For 'q' (max speed), use r = 10
int conversorDeVelocidad(int r){return (r * 255) / 10;}



// Function that recives the actual speed of the BB-8 and returns the speed of the slower wheel on
// right/left turns
int conversorDeVelocidadGiroNormal(int r){return r / 3;}



// Function that recives the actual speed of the BB-8 and returns the speed of the slower wheel on
// diagonal turns
int conversorDeVelocidadGiroDiagonal(int r){return (2 * r)/3;}



// Function that plays sounds. Parameters: buzzer pin, note frequency and duration
void sonido(int pinAltav, float notaFrecuencia, long notaDuracion) 
{
    // Frequency to microseconds
    float microsegundosPorOnda = 1000000 / notaFrecuencia;
    // Cycles per second
    float milisegundosPorCiclo = 1000 / (microsegundosPorOnda * 2);
    float tiempoDeLoop = notaDuracion * milisegundosPorCiclo;
    // Play the sound
    for (int x = 0; x < tiempoDeLoop; x++)
    {
        digitalWrite(pinAltav, HIGH);
        delayMicroseconds(microsegundosPorOnda);
        digitalWrite(pinAltav, LOW);
        delayMicroseconds(microsegundosPorOnda);
    }
    return;
}


// Go forward function, with speed parameter in 0-255 scale
void haciaAdelante(int velocidad) 
{
    // Set right engine direction
    digitalWrite(motorDerechoA, LOW);
    digitalWrite(motorDerechoB, HIGH);
    // Set right engine speed
    analogWrite(motorDerechoHabilitador, velocidad);
    // Set left engine direction
    digitalWrite(motorIzquierdoA, LOW);
    digitalWrite(motorIzquierdoB, HIGH);
    // Set left engine speed
    analogWrite(motorIzquierdoHabilitador, velocidad);
    return;
}


// Go backward function, with speed  parameter in 0-255 scale
void haciaAtras(int velocidad)
{
    // Set right engine direction
    digitalWrite(motorDerechoA, HIGH);
    digitalWrite(motorDerechoB, LOW);
    // Set right engine speed
    analogWrite(motorDerechoHabilitador, velocidad);
    // Set left engine direction
    digitalWrite(motorIzquierdoA, HIGH);
    digitalWrite(motorIzquierdoB, LOW);
    // Set left engine speed
    analogWrite(motorIzquierdoHabilitador, velocidad);
    return;
}


// Go right function, with speed  parameter in 0-255 scale
void haciaDerecha(int velocidad)
{
    // Right wheel has to be slower than left wheel
    // Store in ruedaMasLenta lower wheel speed
    int ruedaMasLenta = conversorDeVelocidadGiroNormal(velocidad);
    // Set right engine direction
    digitalWrite(motorDerechoA, LOW);
    digitalWrite(motorDerechoB, HIGH);
    // Set right engine speed
    analogWrite(motorDerechoHabilitador, ruedaMasLenta);
    // Set left engine direction
    digitalWrite(motorIzquierdoA, LOW);
    digitalWrite(motorIzquierdoB, HIGH);
    // Set left engine speed
    analogWrite(motorIzquierdoHabilitador, velocidad);
    return;
}


// Go left function, with speed  parameter in 0-255 scale
void haciaIzquierda(int velocidad)
{
    // Left wheel has to bee slower than right wheel
    // Store in ruedaMasLenta lower wheel speed
    int ruedaMasLenta = conversorDeVelocidadGiroNormal(velocidad);
    // Set right engine direction
    digitalWrite(motorDerechoA, LOW);
    digitalWrite(motorDerechoB, HIGH);
    // Set right engine speed
    analogWrite(motorDerechoHabilitador, velocidad);
    // Set left engine direction
    digitalWrite(motorIzquierdoA, LOW);
    digitalWrite(motorIzquierdoB, HIGH);
    // Set left engine speed
    analogWrite(motorIzquierdoHabilitador, ruedaMasLenta);
    return;
}


// Go forward/right function, with speed  parameter in 0-255 scale
void haciaAdelanteDerecha(int velocidad)
{
    // Right wheel has to bee slower than left wheel
    // Store in ruedaMasLenta lower wheel speed
    int ruedaMasLenta = conversorDeVelocidadGiroDiagonal(velocidad);
    // Set right engine direction
    digitalWrite(motorDerechoA, LOW);
    digitalWrite(motorDerechoB, HIGH);
    // Set right engine speed
    analogWrite(motorDerechoHabilitador, ruedaMasLenta);
    // Set left engine direction
    digitalWrite(motorIzquierdoA, LOW);
    digitalWrite(motorIzquierdoB, HIGH);
    // Set left engine speed
    analogWrite(motorIzquierdoHabilitador, velocidad);
    return;
}



// Go forward/left function, with speed  parameter in 0-255 scale
void haciaAdelanteIzquierda(int velocidad)
{
    // Left wheel has to bee slower than right wheel
    // Store in ruedaMasLenta lower wheel speed
    int ruedaMasLenta = conversorDeVelocidadGiroDiagonal(velocidad);
    // Set right engine direction
    digitalWrite(motorDerechoA, LOW);
    digitalWrite(motorDerechoB, HIGH);
    // Set right engine speed
    analogWrite(motorDerechoHabilitador, velocidad);
    // Set left engine direction
    digitalWrite(motorIzquierdoA, LOW);
    digitalWrite(motorIzquierdoB, HIGH);
    // Set left engine speed
    analogWrite(motorIzquierdoHabilitador, ruedaMasLenta);
    return;
}


// Go backward/right function, with speed  parameter in 0-255 scale
void haciaAtrasDerecha(int velocidad)
{
    // Right wheel has to bee slower than left wheel
    // Store in ruedaMasLenta lower wheel speed
    int ruedaMasLenta = conversorDeVelocidadGiroDiagonal(velocidad);
    // Set right engine direction
    digitalWrite(motorDerechoA, HIGH);
    digitalWrite(motorDerechoB, LOW);
    // Set right engine speed
    analogWrite(motorDerechoHabilitador, ruedaMasLenta);
    // Set left engine direction
    digitalWrite(motorIzquierdoA, HIGH);
    digitalWrite(motorIzquierdoB, LOW);
    // Set left engine speed
    analogWrite(motorIzquierdoHabilitador, velocidad);
    return;
}


// Go backward/left function, with speed  parameter in 0-255 scale
void haciaAtrasIzquierda(int velocidad)
{
    // Left wheel has to bee slower than right wheel
    // Store in ruedaMasLenta lower wheel speed
    int ruedaMasLenta = conversorDeVelocidadGiroDiagonal(velocidad);
    // Set right engine direction
    digitalWrite(motorDerechoA, HIGH);
    digitalWrite(motorDerechoB, LOW);
    // Set right engine speed
    analogWrite(motorDerechoHabilitador, velocidad);
    // Set left engine direction
    digitalWrite(motorIzquierdoA, HIGH);
    digitalWrite(motorIzquierdoB, LOW);
    // Set left engine speed
    analogWrite(motorIzquierdoHabilitador, ruedaMasLenta);
    return;
}


// Stop both engines function
void parar(void)
{
    // Set both speeds at 0
    analogWrite(motorDerechoHabilitador, 0);
    analogWrite(motorIzquierdoHabilitador, 0);
    // Reset direction values
    digitalWrite(motorDerechoA, LOW);
    digitalWrite(motorDerechoB, LOW);
    digitalWrite(motorIzquierdoA, LOW);
    digitalWrite(motorIzquierdoB, LOW);
    return;
}


// Function that plays sound 1
void sonido1(void)
{
    for (int i=100; i<5000; i*=1.45)
    {
        sonido(pinAltavoz,i,60);
    }
    delay(10);
    for (int i=100; i<6000; i*=1.5)
    {
        sonido(pinAltavoz,i,20);
    }
    return;
}


// Function that plays ohhh sound
void ohhh(void)
{
    for (int i=1000; i<2000; i*=1.02) {
        sonido(pinAltavoz,i,10);
    }
    for (int i=2000; i>1000; i*=.98) {
        sonido(pinAltavoz,i,10);
    }
    return;
}


// Function that plays double ohhh
void dobleOhhh(void)
{
    for (int i=1000; i<5000; i*=1.05)
    {
        sonido(pinAltavoz,i,10);
    }
    delay(300);
    for (int i=1000; i<3000; i*=1.03)
    {
        sonido(pinAltavoz,i,10);
    }
    for (int i=3000; i>1000; i*=.97)
    {
        sonido(pinAltavoz,i,10);
    }
    return;
}


// Function that plays sound 2
void sonido2(void)
{
    sonido(pinAltavoz, nota_A7,100);
    sonido(pinAltavoz, nota_G7,100);
    sonido(pinAltavoz, nota_E7,100);
    sonido(pinAltavoz, nota_C7,100);
    sonido(pinAltavoz, nota_D7,100);
    sonido(pinAltavoz, nota_B7,100);
    sonido(pinAltavoz, nota_F7,100);
    sonido(pinAltavoz, nota_C8,100);
    sonido(pinAltavoz, nota_A7,100);
    sonido(pinAltavoz, nota_G7,100);
    sonido(pinAltavoz, nota_E7,100);
    sonido(pinAltavoz, nota_C7,100);
    sonido(pinAltavoz, nota_D7,100);
    sonido(pinAltavoz, nota_B7,100);
    sonido(pinAltavoz, nota_F7,100);
    sonido(pinAltavoz, nota_C8,100);
    return;
}


// Function that plays sound 3
void sonido3(void)
{
    sonido(pinAltavoz, nota_C7,100);
    sonido(pinAltavoz, nota_B7,100);
    sonido(pinAltavoz, nota_A7,100);
    sonido(pinAltavoz, nota_F7,100);
    sonido(pinAltavoz, nota_D7,100);
    sonido(pinAltavoz, nota_C7,100);
    sonido(pinAltavoz, nota_D7,100);
    sonido(pinAltavoz, nota_Eb8,100);
    sonido(pinAltavoz, nota_C7,100);
    sonido(pinAltavoz, nota_G7,100);
    sonido(pinAltavoz, nota_E7,100);
    sonido(pinAltavoz, nota_F7,100);
    sonido(pinAltavoz, nota_E7,100);
    sonido(pinAltavoz, nota_G7,100);
    sonido(pinAltavoz, nota_F7,100);
    sonido(pinAltavoz, nota_C8,100);
    return;
}


// Funcion that plays the Imperial March
void marchaImperial(void)
{
    sonido(pinAltavoz, nota_A4, 600);
    delay(100);
    sonido(pinAltavoz, nota_A4, 600);
    delay(100);
    sonido(pinAltavoz, nota_A4, 600);
    delay(100);
    sonido(pinAltavoz, nota_F4, 600);
    delay(100);
    sonido(pinAltavoz, nota_C5, 300);
    delay(100);
    sonido(pinAltavoz, nota_A4, 600);
    delay(100);
    sonido(pinAltavoz, nota_F4, 600);
    delay(100);
    sonido(pinAltavoz, nota_C5, 300);
    delay(100);
    sonido(pinAltavoz, nota_A4, 600);
    delay(100);
    sonido(pinAltavoz, nota_E5, 600);
    delay(100);
    sonido(pinAltavoz, nota_E5, 600);
    delay(100);
    sonido(pinAltavoz, nota_E5, 600);
    delay(100);
    sonido(pinAltavoz, nota_F5, 600);
    delay(100);
    sonido(pinAltavoz, nota_C5, 300);
    delay(100);
    sonido(pinAltavoz, nota_G5, 600);
    delay(100);
    sonido(pinAltavoz, nota_F5, 600);
    delay(100);
    sonido(pinAltavoz, nota_C5, 300);
    delay(100);
    sonido(pinAltavoz, nota_A4, 600);
    delay(100);
    return;
}



// Main function for the Arduino
void loop()
{
    // For the switch case values understanding, check the beginning of the code
    // If there is an unread int in the serial port...
    if (Serial.available())
    {
        // Store in comando that int
        int comando = Serial.read();
        // If comando is a number (ASCII) or is 'q' (MAX SPEED), then the user wants to change the speed
        if ((comando > 47 and comando < 58) or comando == 113)
        {
            switch(comando)
            {
                case 48:
                    rapidez = 0;
                    break;
                case 49:
                    rapidez = 1;
                    break;
                case 50:
                    rapidez = 2;
                    break;
                case 51:
                    rapidez = 3;
                    break;
                case 52:
                    rapidez = 4;
                    break;
                case 53:
                    rapidez = 5;
                    break;
                case 54:
                    rapidez = 6;
                    break;
                case 55:
                    rapidez = 7;
                    break;
                case 56:
                    rapidez = 8;
                    break;
                case 57:
                    rapidez = 9;
                    break;
                case 113:
                    rapidez = 10;
                    break;
                default:
                    break;
            }
        }

        // If not, the user wants to move the BB-8, or play a sound
        else
        {
            switch(comando)
            {
                case 70:
                    haciaAdelante(conversorDeVelocidad(rapidez));
                    tiempo = 0;
                    break;
                case 66:
                    haciaAtras(conversorDeVelocidad(rapidez));
                    tiempo = 0;
                    break;
                case 82:
                    haciaDerecha(conversorDeVelocidad(rapidez));
                    tiempo = 0;
                    break;
                case 76:
                    haciaIzquierda(conversorDeVelocidad(rapidez));
                    tiempo = 0;
                    break;
                case 73:
                    haciaAdelanteDerecha(conversorDeVelocidad(rapidez));
                    tiempo = 0;
                    break;
                case 71:
                    haciaAdelanteIzquierda(conversorDeVelocidad(rapidez));
                    tiempo = 0;
                    break;
                case 74:
                    haciaAtrasDerecha(conversorDeVelocidad(rapidez));
                    tiempo = 0;
                    break;
                case 72:
                    haciaAtrasIzquierda(conversorDeVelocidad(rapidez));
                    tiempo = 0;
                    break;
                case 87:
                    sonido2();
                    break;
                case 119:
                    sonido3();
                    break;
                case 85:
                    sonido1();
                    break;
                case 117:
                    marchaImperial();
                    break;
                case 86:
                    ohhh();
                    break;
                case 118:
                    dobleOhhh();
                    break;
            }   
        }
    }
    // Else, the serial port is clean
    // Perform 200 cycles of 1 ms
    if(tiempo < 200)
    {
        tiempo += 1;
    }
    // 200 ms have passed, so we stop the BB8
    else
    {
        parar();
    }
    // 1 ms delay per cycle
    delay(1);
}
